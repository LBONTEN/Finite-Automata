/* Bontenakel Lenny, s0181558

Dit project heeft als doel het simuleren van een DFA.
We gebruiken volgend voorbeeld als test.

            0      1
         |------|------|
  ->Q0   |  Q0  |  Q1  |
         |------|------|
   *Q1   |  Q1  |  Q0  |
         |------|------|

 */
#include "DFA.h"
#include "Arc.h"

int main(int argc, char** argv) {

    if(argc < 3)
    {
        cout << "invalid arguments" << endl;
    }

    if(argv[0] == "tfa")
    {
        ifstream file(argv[1]);
        DFA dfa(file);

        string outputfile2 = argv[3];

        dfa = dfa.tableFilling(argv[3]);
        dfa.generateDFAPng(argv[2]);
    }
    else
    {
        cout << "command " << argv[0] << " is currently not supported";
    }

}
