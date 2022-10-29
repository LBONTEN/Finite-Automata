// Bontenakel Lenny, s0181558

#ifndef DFA_DFA_H
#define DFA_DFA_H

#include "Node.h"
#include "helpers.h"
using namespace std;


/* Class DFA:
 *  De te simuleren DFA:
 *      - vector<char> alphabet: Houdt het te gebruiken alfabet van de DFA bij
 *      - Node* startNode: Duidt de startstaat aan
 */

class DFA {
public:
    DFA(ifstream& file) { readJSON(file); }
    DFA(vector<char> alphabet, Node* startNode) : alphabet(std::move(alphabet)), startNode(startNode){}
    ~DFA() = default;

    DFA tableFilling(const string& htmlFileName);

    const Node& getStartNode();
    bool isInAlphabet(char);
    void readJSON(ifstream&);
    bool run(string);
    void generateDFAPng(const string& fileName);
    DFA createNewDFA(map<string, Node*>& substitutions);

private:
    void connectStates(map<string, Node*>& substitutions, Node* currentNode, vector<string>& visited);
    vector<Node*> collectStates();
    vector<char> alphabet;
    Node* startNode;

    void makeDFA(json);

};

#endif //DFA_DFA_H
