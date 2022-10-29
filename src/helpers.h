#include <string>
#include <vector>
#include "Node.h"

using namespace std;

#ifndef DFA_HELPERS_H
#define DFA_HELPERS_H

bool stringIsInVector(const vector<string>& comparison, const string& target);
bool nodeIsinVector(Node*& nodeToCheck, vector<Node*>& targetVector);

void createHTML(const string& fileName, vector<pair<Node*, Node*>>);
bool pairIsInVector(pair<Node*, Node*>& pairToCheck, vector<pair<Node*, Node*>>& pairs);
vector<Node*> unPairVector(const vector<pair<Node*, Node*>>& pairs);

#endif //DFA_HELPERS_H
