#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <memory>
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/IR/Constants.h"
#include "llvm/Support/raw_ostream.h"
#include "../../src/CompilerFrontend/Lexxer.h"
using namespace std;
#define OFFSET 65536

#ifndef NODE_H
#define NODE_H

struct Node
{
    unique_ptr<Node> right;
    unique_ptr<Node> left; // int s;
    virtual llvm::Value *Codegen(llvm::IRBuilder<> &builder);

    virtual ~Node();
};
#endif

#ifndef VAR_REF_H
#define VAR_REF_H
struct VaraibleReference : public Node
{
    unique_ptr<Node> expression;
    Tokens varaible;
};
#endif

#ifndef VAR_DEC_H
#define VAR_DEC_H
struct VaraibleDeclaration : public Node
{
    unique_ptr<Node> expression;
    Tokens varaible;
    Tokens typeOfVar;
    int size;
    int constant;
};
#endif

#ifndef BOOL_EXPR_NODE_H
#define BOOL_EXPR_NODE_H
struct BoolExpressionNode : public Node
{

    optional<Tokens> op;
    int next_is_or;
};
#endif

#ifndef BOOL_LITERAL_NODE_H
#define BOOL_LITERAL_NODE_H
struct BooleanLiteralNode : public Node
{
    Tokens value;
};
#endif

#ifndef LOOP_NODE_H
#define LOOP_NODE_H
struct LoopNode : public Node
{
    unique_ptr<BoolExpressionNode> condition;
    vector<shared_ptr<Node>> statements;
};
#endif

#ifndef ELSE_NODE_H
#define ELSE_NODE_H
struct ElseNode : public Node
{

    vector<shared_ptr<Node>> statements;
};
#endif

#ifndef CHAR_NODE_H
#define CHAR_NODE_H
struct CharNode : public Node
{
    string character;
};
#endif

#ifndef IF_STATEMENT_NODE_H
#define IF_STATEMENT_NODE_H
struct IfSatementNode : public Node
{

    unique_ptr<BoolExpressionNode> condition;
    vector<shared_ptr<Node>> statements;
    unique_ptr<ElseNode> Else;
};
#endif

#ifndef FUNC_CALL_NODE_H
#define FUNC_CALL_NODE_H
struct funcCallNode : public Node
{
    Tokens funcCall;
    vector<unique_ptr<Node>> params;
};
#endif

#ifndef FLOAT_NODE_H
#define FLOAT_NODE_H
struct FloatNode : public Node
{
    string num;
};
#endif

#ifndef INT_NODE_H
#define INT_NODE_H
struct IntegerNode : public Node
{
    string num;
    virtual llvm::Value *Codegen(llvm::IRBuilder<> &builder);
};
#endif

#ifndef STRING_NODE_H
#define STRING_NODE_H
struct StringNode : public Node
{
    string stringBuffer;
};
#endif

#ifndef OP_NODE_H
#define OP_NODE_H
struct OperatorNode : public Node
{
    struct Tokens token;
    virtual llvm::Value *Codegen(llvm::IRBuilder<> &builder);
};
#endif

#ifndef RETURN_STATEMENT_H
#define RETURN_STATEMENT_H
struct ReturnStatment : public Node
{
    unique_ptr<Node> expression;
};
#endif

#ifndef FUNCTION_NODE_H
#define FUNCTION_NODE_H
struct FunctionNode : public Node
{
    Tokens nameOfFunction;
    vector<shared_ptr<VaraibleDeclaration>> params;
    vector<shared_ptr<Node>> statements;
    string hashed_functionName; // the name that is asm
    optional<Tokens> returnType;
    virtual llvm::Value *Codegen(llvm::IRBuilder<> &builder);
};
#endif
#ifndef FOR_LOOP_NODE_H
#define FOR_LOOP_NODE_H
struct ForLoopNode : public Node
{
    unique_ptr<Node> incrimentorVar;
    unique_ptr<BoolExpressionNode> condition;
    vector<shared_ptr<Node>> statements;
};
#endif

#ifndef ARRAY_DEC_H
#define ARRAY_DEC_H

struct ArrayDeclaration : public Node
{
    unique_ptr<Node> size;
    Tokens varaible;
    Tokens typeOfVar;
    vector<unique_ptr<Node>> array_dimensions;
    int dimensions;
};
#endif

#ifndef ARRAY_REF_H
#define ARRAY_REF_H
struct ArrayRef : public Node
{
    Tokens name;
    unique_ptr<Node> RefedLocation;
    unique_ptr<Node> value;
    int referencedDimensions;
};
#endif

#ifndef CAST_NODE_H
#define CAST_NODE_H
struct CastNode : public Node
{
    Tokens type;
    unique_ptr<Node> expression;
};
#endif
vector<unique_ptr<FunctionNode>> parse(vector<Tokens> &tokens);

Node *term(vector<Tokens> &tokens);
Node *factor(vector<Tokens> &tokens);

Node *expression(vector<Tokens> &tokens);

Tokens *matchAndRemove(vector<Tokens> &tokens, type type, string caller);
bool isNull(Node *n);
Node *handleFunctions(vector<Tokens> &tokens);
void printParams(vector<Tokens *> a);
Node *testParse(vector<Tokens> &tokens);

vector<unique_ptr<FunctionNode>> functionParse(vector<Tokens> &tokens);
Node *parseVar(vector<Tokens> &tokens, Tokens *name);
Node *handleCalls(vector<Tokens> &tokens, Tokens *checkIfFunct);
Node *handleSatements(vector<Tokens> &tokens);
unique_ptr<Node> testExpressionParse(vector<Tokens> &tokens);
// unique_ptr<Node> sunique_ptr<Node> test(vector<Tokens> &tokens){afe_parse(vector<Tokens> &tokens);

unique_ptr<Node> test(vector<Tokens> &tokens);
