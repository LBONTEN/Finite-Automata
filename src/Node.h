// Bontenakel Lenny, s0181558

#ifndef DFA_NODE_H
#define DFA_NODE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "nlohmann/json.hpp"
#include "Arc.h"
#include "helpers.h"
using namespace std;
using json = nlohmann::json;

class DFA; // forward declaration om DFA objecten te kunnen gebruiken in deze klasse

/* Class Node:
 *  Representeert een staat uit de DFA.
 *      - string label: string om staten te kunnen vinden en herkennen
 *      - vector<Arc*> arcs: Houdt alle uitgaande arcs van de staat bij
 *      - bool isStart: Boolean om de startstaat te kunnen aanduiden
 *      - bool isFinal: Boolean om finale staten te kunnen aanduiden
 */

class Node {
public:
    Node(string label, const bool isStart= false, const bool isFinal= false):
            label(label), isStart(isStart), isFinal(isFinal) {}

    ~Node()= default;

    void replaceArcs(vector<Arc*> inputArcs);
    void setArcs(vector<Arc*> inputArcs);

    const string& getLabel();
    bool checkIfStart();
    bool checkIfFinal();

private:
    string label;
    vector<Arc*> arcs={};
    const bool isStart;
    const bool isFinal;

    void collectState(const vector<char>& alphabet, vector<Node*>& visited);
    Node* transition(char);
    Node* findTo(json, map<string, Node*>&, const string&);
    void printStates(fstream& file, set<string>& visited);
    void placeArcs(json, json, const vector<char>&, map<string, Node*>&, set<string>&);
    void clearArcs();

    friend class DFA;
    friend class Arc;

};

#endif //DFA_NODE_H
