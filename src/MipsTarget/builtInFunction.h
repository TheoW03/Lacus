#include <iostream>
#include <string>
#include <vector>

#include "../../src/CompilerFrontend/parser.h"
#include "../../src/CompilerFrontend/Lexxer.h"
#include "../../src/MipsTarget/UtilFunctions.h"
#include "../../src/MipsTarget/MipsTarget.h"
#include "../../src/MipsTarget/VaraibleScope.h"

using namespace std;

#ifndef BUILT_IN_H
#define BUILT_IN_H
class builtInFunction
{
public:
    funcCallNode *function;
    
    virtual void execute_code_integer(string &gen_string, 
		    RegisterAllocation register_context, string registers);
    
    virtual void execute_code_float(string &gen_string, 
		    RegisterAllocation register_context, string registers);

    virtual void execute_code_char(string &gen_string, 
		    RegisterAllocation register_context, string registers);
    virtual void setup_params(vector<unique_ptr<Node>> params, 
		    string &gen_string, Scope_Monitor &scope_monitor);
};

#endif

#ifndef PRINT_H
#define PRINT_H
class Print : public builtInFunction
{
public:
    Print();
    void execute_code_integer(string &gen_string, 
		    RegisterAllocation register_context, string registers);
    void execute_code_float(string &gen_string, 
		    RegisterAllocation register_context, string registers);
    void execute_code_char(string &gen_string, 
		    RegisterAllocation register_context, string registers);

    void setup_params(vector<unique_ptr<Node>> params, 
		    string &gen_string, Scope_Monitor &scope_monitor);
};
#endif

#ifndef Exit_H
#define Exit_H
class Exit : public builtInFunction
{
public:
    Exit();
    void execute_code_integer(string &gen_string, 
		    RegisterAllocation register_context, string registers);
    void execute_code_float(string &gen_string, 
		    RegisterAllocation register_context, string registers);
    void execute_code_char(string &gen_string, 
		    RegisterAllocation register_context, string registers);
    void setup_params(vector<unique_ptr<Node>> params, 
		    string &gen_string, Scope_Monitor &scope_monitor);
};
#endif
