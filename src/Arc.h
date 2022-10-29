// Bontenakel Lenny, s0181558

#ifndef DFA_ARC_H
#define DFA_ARC_H

class Node; // forward declaration om Node objecten te kunnen gebruiken in deze klasse

/* Class Arc:
 *  Representeert een arc uit de DFA.
 *      - char arcLabel: char om Arcs te kunnen terugvinden
 *      - Node* end: pointer naar de staat waar de arc in toekomt
*/

class Arc {
    char arcLabel;
    Node* end;

    friend class Node;
public:
    Arc(char label, Node* end): arcLabel(std::move(label)), end(end){}
};

#endif //DFA_ARC_H
