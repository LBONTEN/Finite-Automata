#include <utility>

// Bontenakel Lenny, s0181558

#include "Node.h"

bool isInVector(const vector<Node*>& vector, const string& target)
{
    for (Node* i : vector)
    {
        if(i->getLabel() == target)
        {
            return true;
        }
    }
    return false;
}

const string& Node::getLabel()
{
    return label;
}

bool Node::checkIfStart()
{
    return isStart;
}

bool Node::checkIfFinal()
{
    return isFinal;
}

Node* Node::transition(char input)
{
    for (Arc* i : arcs) {
        if (i->arcLabel == input) { // Zoek de juiste Arc die gevolgd moet worden
            return i->end; // return de staat waarin de Arc toekomt
        }
    }
    return nullptr;
}

Node* Node::findTo(json states, map<string, Node*>& instantiatedNodes, const string& labelNext)
{
    if(labelNext == label)
    {
        return this;
    }

    if(instantiatedNodes.find(labelNext) != instantiatedNodes.end())
    {
        return instantiatedNodes[labelNext];
    }

    for(int i = 0; i < states.size(); i++)
    {
        if(states[i]["name"] == labelNext)
        {
            Node* newNode =  new Node(states[i]["name"],
                            states[i]["starting"].get<bool>(),
                            states[i]["accepting"].get<bool>());
            instantiatedNodes.insert(pair<string, Node*>(newNode->label, newNode));
            return newNode;
        }
    }
    return nullptr;
}

void Node::placeArcs(json states, json transitions, const vector<char>& alphabet, map<string, Node*>& instantiatedNodes, set<string>& visited)
{
    if(visited.find(label) != visited.end()) { // Eindig deze frame indien de node al eens bezocht is geweest
        return;
    } else {                                   // Voeg de node toe an de vector van bezochte nodes
        visited.insert(label);
    }

    for(const char& i : alphabet)
    {
        bool found= false;
        int index= 0;
        while(!found)
        {
            if(index == transitions.size())
            {
                cerr << "Undefined transition: ẟ(" << label << ", " << i << ")" << endl;
                return;
            }
            string given_input= transitions[index]["input"];
            if(transitions[index]["from"] == label && *given_input.c_str() == i)
            {
                Node* newNode = findTo(states, instantiatedNodes, transitions[index]["to"]);
                if(newNode != nullptr)
                {
                    arcs.push_back(new Arc(*given_input.c_str(), newNode));
                    found= true;
                } else {
                    cerr << "Transition not specified" << endl;
                    return;
                }
            } else {
                index++;
            }
        }
    }

    for(Arc* i : arcs) { // Herhaal voor volgende nodes
        if(i->end->label != label)
        {
            i->end->placeArcs(states, transitions, alphabet, instantiatedNodes, visited);
        }
    }
}

void Node::printStates(fstream& file, set<string>& visited)
{
    if(visited.find(label) != visited.end()) { // Eindig deze frame indien de node al eens bezocht is geweest
        return;
    } else {                                   // Voeg de node toe an de vector van bezochte nodes
        visited.insert(label);
    }

    file << "\n";

    if(isStart) { // Als de node de start staat van de DFA is, wordt deze zo aangeduidt in het outputbestand
        file << "\tstart -> " << label << " \n\tstart[peripheries=0]" << endl;
    }

    for(Arc* i : arcs) {// Teken alle uitgaande transities vanuit deze staat
        file << "\t" << label << " -> " << i->end->label << " [label=" << i->arcLabel << "]" << endl;
    }

    if(isFinal) { // Als deze staat een finale staat is krijgt deze een 2e omringende cirkel in het outputbestand
        file << "\t" << label << " [peripheries=2]" << endl;
    }

    for(Arc* i : arcs) { // Herhaal voor volgende nodes
        i->end->printStates(file, visited);
    }
}

void Node::collectState(const vector<char>& alphabet, vector<Node *>& visited)
{
    if(isInVector(visited, label))
    {
        return;
    }
    visited.push_back(this);

    for (const char& i : alphabet)
    {
        transition(i)->collectState(alphabet, visited);
    }
}

void Node::replaceArcs(vector<Arc *> inputArcs)
{
    arcs.clear();
    arcs.insert(arcs.end(), inputArcs.begin(), inputArcs.end());
}

void Node::setArcs(vector<Arc*> inputArcs)
{
    arcs.insert(arcs.end(), inputArcs.begin(), inputArcs.end());
}

void Node::clearArcs()
{
    arcs.clear();
}
