// Bontenakel Lenny, s0151558

#include "DFA.h"

const Node& DFA::getStartNode()
{
    return *startNode;
}

bool DFA::isInAlphabet(char input)
{ // Check of een gegeven character in het alfabet van de DFA zit
    for(char i : alphabet)
    {
        if (input == i)
        {
            return true;
        }
    }
    return false;
}

void DFA::readJSON(ifstream& file)
{
    json root = json::parse(file);

    if(root["type"] == "DFA")
    {
        makeDFA(root);
    } else {
        cerr << "Given type is currently not supported." << endl;
    }
}

void DFA::makeDFA(json jason)
{
    for(int index = 0; index < jason["alphabet"].size(); index++)
    {
        string given_alphabet = jason["alphabet"][index];
        alphabet.push_back(*given_alphabet.c_str());
    }

    map<string, Node*> instantiatedNodes;
    bool foundStart= false;
    int index = 0;
    while(!foundStart) {
        if (index == jason["states"].size()) {
            cerr << "No starting state specified." << endl;
            alphabet.clear();
            return;
        }

        if (jason["states"][index]["starting"].get<bool>()) {
            startNode = new Node(jason["states"][index]["name"],
                                 jason["states"][index]["starting"].get<bool>(),
                                 jason["states"][index]["accepting"].get<bool>());
            instantiatedNodes.insert(pair<string, Node*>(startNode->label, startNode));
            foundStart = true;
        } else {
            index++;
        }
    }
    set<string> visited={};
    startNode->placeArcs(jason["states"], jason["transitions"], alphabet, instantiatedNodes, visited);
}

bool DFA::run(string string) // verwerkt een gegeven string
{
    Node* currentNode = startNode;

    for(char i : string)
    {
        if(!isInAlphabet(i)) // als de string een symbool bevat dat niet in het alfabet zit, hoort de functie te stoppen
        {
            return false;
        }
        currentNode = currentNode->transition(i); // ga naar de correcte staat
    }
    if(currentNode->isFinal) // als de staat na het verwerken van de inputstring finaal is, is de inputstring geldig
    {
        return true;
    }
    return false;
}

void DFA::generateDFAPng(const string& fileName) // Initieert het process om de DFA uit te schrijven in een .dot- en .png-bestand
{
    fstream stream;
    stream.open(fileName, fstream::out); // opent een bestand voor output

    stream << "DiGraph {\n\trankdir=LR" << endl;

    set<string> visited= {}; // declareert een set visited om reeds gevisiteerde nodes in te bewaren
    startNode->printStates(stream, visited); // functie om alle staten in het outputbestand te schrijven, beginnende bij de startnode

    stream << "}" << endl;
    stream.close();

    size_t extension = fileName.find_last_of(".");
    string outputPNG = fileName.substr(0, extension);
    outputPNG = outputPNG + ".png";

    string command;
    command = "dot " + fileName + " -Tpng -o " + outputPNG;

    system(command.c_str()); // creëert een .png bestand uit het .dot bestand
}

vector<Node*> DFA::collectStates()
{
    vector<Node*> allStates;

    startNode->collectState(alphabet, allStates);

    return allStates;
}

bool checkIfMarked(const pair<Node*, Node*>& pairToCheck, const vector<pair<Node*, Node*>>& markedPairs)
{
    for(const pair<Node*, Node*>& i : markedPairs)
    {
        if(i == pairToCheck)
        {
            return true;
        }
    }
    return false;
}

map<string, Node*> mergeNodes(vector<pair<Node*, Node*>> nodesToMerge)
{
    vector<Node*> mergedNodes;
    map<string, Node*> substitutions;

    while(!nodesToMerge.empty())
    {
        vector<pair<Node*, Node*>> temp;
        temp.push_back(nodesToMerge[0]);
        nodesToMerge.erase(nodesToMerge.begin());

        for(pair<Node*, Node*>& i : temp)
        {
            int index = 0;
            while(index < nodesToMerge.size())
            {
                if(i.first == nodesToMerge[index].first || i.first == nodesToMerge[index].second ||
                i.second == nodesToMerge[index].first || i.second == nodesToMerge[index].second)
                {
                    temp.push_back(nodesToMerge[index]);
                    nodesToMerge.erase(nodesToMerge.begin() + index);
                }
                else
                {
                    index++;
                }
            }
        }

        bool startState = false;
        bool acceptingState = false;
        vector<string> labelUnion;

        for(pair<Node*, Node*> i : temp)
        {
            if(!stringIsInVector(labelUnion, i.first->getLabel()))
            {
                labelUnion.push_back(i.first->getLabel());
            }
            if(!stringIsInVector(labelUnion, i.second->getLabel()))
            {
                labelUnion.push_back(i.second->getLabel());
            }
            if(i.first->checkIfStart() || i.second->checkIfStart())
            {
                startState = true;
            }
            if(i.first->checkIfFinal() || i.second->checkIfFinal())
            {
                acceptingState = true;
            }
        }
        string newLabel;

        for(string i : labelUnion)
        {
            newLabel = newLabel + i;
        }
        Node* newNode = new Node(newLabel, startState, acceptingState);

        for(string i : labelUnion)
        {
            substitutions.insert(pair<string, Node*>{i, newNode});
        }
    }
    return substitutions;
}

void DFA::connectStates(map<string, Node*>& substitutions, Node* currentNode, vector<string>& visited)
{
    Node* equivalentState = substitutions[currentNode->getLabel()];
    if(stringIsInVector(visited, equivalentState->getLabel())) return;
    visited.push_back(equivalentState->getLabel());

    vector<Arc*> newArcs;
    for(char& i : alphabet)
    {
        if(substitutions.find(currentNode->transition(i)->getLabel()) == substitutions.end())
        {
            substitutions.insert(pair<string, Node *>{currentNode->transition(i)->getLabel(),
                                                      new Node(currentNode->transition(i)->getLabel(),
                                                               currentNode->transition(i)->isStart,
                                                               currentNode->transition(i)->isFinal)});
        }

        Node* newTransition = substitutions[currentNode->transition(i)->getLabel()];
        newArcs.push_back(new Arc(i, newTransition));
    }
    equivalentState->setArcs(newArcs);

    for(char& i : alphabet)
    {
        connectStates(substitutions, currentNode->transition(i), visited);
    }
}

DFA DFA::createNewDFA(map<string, Node*>& substitutions)
{
    Node* newStartNode;
    vector<string> visited =  {};

    if(substitutions.find(startNode->getLabel()) == substitutions.end())
    {
        substitutions.insert(pair<string, Node *>{startNode->getLabel(),
                                                  new Node(startNode->getLabel(),
                                                           startNode->isStart,
                                                           startNode->isFinal)});
    }
    newStartNode = substitutions[startNode->getLabel()];


    connectStates(substitutions, startNode, visited);

    return DFA(alphabet, newStartNode);
}

DFA DFA::tableFilling(const string& htmlFileName)
{
    vector<Node*> allStates = collectStates();

    vector<pair<Node*, Node*>> unmarkedCombos;
    vector<pair<Node*, Node*>> markedCombos;

    while(!allStates.empty())
    {
        if(allStates[0]->isFinal)
        {
            for(Node* i : allStates)
            {
                pair<Node*, Node*> newCombo = {allStates[0], i};
                if (i->isFinal && allStates[0] != i)
                {
                    unmarkedCombos.push_back(newCombo);
                }
                if (!i->isFinal && allStates[0] != i)
                {
                    markedCombos.push_back(newCombo);
                }
            }
        }
        else
        {
            for(Node* i : allStates)
            {
                pair<Node*, Node*> newCombo = {allStates[0], i};
                if (!i->isFinal && allStates[0] != i)
                {
                    unmarkedCombos.push_back(newCombo);
                }
                if (i->isFinal && allStates[0] != i)
                {
                    markedCombos.push_back(newCombo);
                }
            }
        }
        allStates.erase(allStates.begin());
    }

    int index = 0;
    while (index < unmarkedCombos.size())
    {
        for(char& i : alphabet)
        {
            pair<Node*, Node*> pairToCheck = {unmarkedCombos[index].first->transition(i),
                                               unmarkedCombos[index].second->transition(i)};
            pair<Node*, Node*> pairToCheckSwapped = {pairToCheck.second,
                                                     pairToCheck.first};

            if(checkIfMarked(pairToCheck, markedCombos) || checkIfMarked(pairToCheckSwapped, markedCombos))
            {
                markedCombos.push_back(unmarkedCombos[index]);
                unmarkedCombos.erase(unmarkedCombos.begin() + index);
                index = -1;
                break;
            }
        }
        index++;
    }

    if (unmarkedCombos.empty())
    {
        return *this;
    }

    createHTML(htmlFileName, markedCombos);
    map<string, Node*> substitutions = mergeNodes(unmarkedCombos);
    return createNewDFA(substitutions);
}
