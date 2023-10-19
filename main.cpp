
#include <iostream>
#include <string>
#include <vector>
#include "src/MipsTarget/MipsTarget.h"
#include "src/ARMTarget/ARMTarget.h"
#include "src/CompilerFrontend/Lexxer.h"
#include "src/CompilerFrontend/parser.h" // #define String string
#include <cmath>
#include <functional>
using namespace std;

#pragma endregion

void handle_cli(char *argv[], int argc)
{
    if (argc == 1)
    {
        return;
    }
    // for (int i = 0; i < argc; i++)
    // {
    //     if (strcmp(argv[i], "-d") == 0)
    //     {
    //         vector<Tokens> a = lex(readFile("test.lk"));
    //         cout << "lexxed" << endl;
    //         vector<FunctionNode *> c = functionParse(a);
    //         cout << "parsed" << endl;
    //         if (c.size() == 0)
    //         {
    //             cout << "nullptr out \n";
    //             return;
    //         }
    //         gen_mips_target(c);
    //         cout << "demo compiled \n";
    //         return;
    //     }
    // }
    char *file = argv[1];

    vector<Tokens> a = lex(readFile(file));
    cout << "lexxed sucessfully" << endl;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-token") == 0)
        {
            // cout << strcmp(argv[i], "-token") << endl;

            // cout << "print" << endl;
            printList(a);
        }
    }

    vector<FunctionNode *> c = functionParse(a);
    cout << "parsed successfully" << endl;
    string file1 = "";
    for (int i = 0; i < argc; i++)
    {

        if (strcmp(argv[i], "-o") == 0)
        {
            file1 = argv[i + 1];
        }
    }
    gen_mips_target(c, file1);

    cout << "compiled successfully" << endl;
}
int main(int argc, char *argv[])
{

    handle_cli(argv, argc);
    // vector<Tokens> a = lex(readFile("test.lk"));
    // Node *c = testExpressionParse(a);
    // rewrite_vars(c);
    // cout << "compiled" << endl;
    // printList(a);
    // vector<FunctionNode *> b = functionParse(a);
    // gen_mips_target(b);
    //     cout << "compiled sucessfully" << endl;

    // vector<FunctionNode *> c = functionParse(a);
    // cout << c.size() << endl;

    // Print the final result
    // std::cout << "Result: " << result.value << std::endl; // Output: Result: 12

    return 0;
}
