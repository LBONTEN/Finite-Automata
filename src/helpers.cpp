
#include "helpers.h"

bool stringIsInVector(const vector<string>& comparison, const string& target)
{
    for (const string& i : comparison)
    {
        if(i == target)
        {
            return true;
        }
    }
    return false;
}

bool nodeIsinVector(Node*& nodeToCheck, vector<Node*>& targetVector)
{
    for (Node* i : targetVector)
    {
        if(i == nodeToCheck)
        {
            return true;
        }
    }
    return false;
}

vector<Node*> unPairVector(const vector<pair<Node*, Node*>>& pairs)
{
    vector<Node*> unpaired;

    for(pair<Node*, Node*> i : pairs)
    {
        if(!nodeIsinVector(i.first, unpaired))
        {
            unpaired.push_back(i.first);
        }
        if(!nodeIsinVector(i.second, unpaired))
        {
            unpaired.push_back(i.second);
        }
    }
    return unpaired;
}

bool pairIsInVector(pair<Node*, Node*>& pairToCheck, vector<pair<Node*, Node*>>& pairs)
{
    for(pair<Node*, Node*> i : pairs)
    {
        if(i == pairToCheck)
        {
            return true;
        }
    }
    return false;
}

void createHTML(const string& fileName, vector<pair<Node*, Node*>> markedCombos)
{
    vector<Node*> allStates = unPairVector(markedCombos);
    fstream stream;
    stream.open(fileName, fstream::out);

    stream << "<html>\n"
              "\n"
              "\t<head>\n"
              "\t\t<style>\n"
              "\n"
              "\t\t\theader\n"
              "\t\t\t{\n"
              "\t\t\t\tfont-size: 24;\n"
              "\t\t\t\tfont-weight: bold;\n"
              "\t\t\t}\n"
              "\n"
              "\t\t\ttable\n"
              "\t\t\t{\n"
              "\t\t\t\tborder-collapse: collapse;\n"
              "\t\t\t\ttable-layout: fixed;\n"
              "\t\t\t\twidth: 333px\n"
              "\t\t\t}\n"
              "\n"
              "\t\t\tth, thead\n"
              "\t\t\t{\n"
              "\t\t\t\tbackground-color: bbbbbb;\n"
              "\t\t\t\tborder: 3px solid black;\n"
              "\t\t\t}\n"
              "\n"
              "\t\t\ttd\n"
              "\t\t\t{\n"
              "\t\t\t\tborder: 1px solid black\n"
              "\t\t\t}\n"
              "\n"
              "\t\t\t.broad\n"
              "\t\t\t{\n"
              "\t\t\t\twidth:444px;\n"
              "\t\t\t}\n"
              "\n"
              "\t\t\t.tab\n"
              "\t\t\t{\n"
              "\t\t\t\tdisplay: inline-block;\n"
              "\t\t\t\tmargin-left: 40px\n"
              "\t\t\t}\n"
              "\n"
              "\t\t</style>\n"
              "\t</head>\n"
              "\n"
              "\t<body>\n"
              "\t\t<table>\n"
              "\n"
              "\t\t\t<thead>\n"
              "\t\t\t\t<td></td>\n";

    for(unsigned long index = allStates.size() - 1; index > 0; index--)
    {
        stream << "\t\t\t\t<td>" <<
                  allStates[index]->getLabel() <<
                  "</td>\n";
    }

    stream << "\t\t\t</thead>\n"
              "\n"
              "\t\t\t<tbody>\n"
              "\n";

    while(allStates.size() > 1)
    {
        stream << "\t\t\t\t<tr>\n"
                  "\t\t\t\t\t<th>" <<
                  allStates[0]->getLabel() <<
                  "</th>\n"
                  "\n";

        for(unsigned long index = allStates.size() - 1; index > 0; index--)
        {
            pair<Node*, Node*> newPair {allStates[0], allStates[index]};
            pair<Node*, Node*> newPairSwapped {allStates[index], allStates[0]};

            if(pairIsInVector(newPair, markedCombos)
            || pairIsInVector(newPairSwapped, markedCombos))
            {
                stream << "\t\t\t\t\t<td bgcolor=ff0000></td>\n";
            } else
            {
                stream << "\t\t\t\t\t<td bgcolor=000000></td>\n";
            }
        }
        stream << "\t\t\t\t</tr>\n"
                  "\n";

        allStates.erase(allStates.begin());
    }

    stream << "\t\t\t</tbody>\n"
              "\t\t</table>\n"
              "\t</body>\n"
              "</html>";
}
