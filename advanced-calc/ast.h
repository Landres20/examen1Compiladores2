#ifndef _AST_H_
#define _AST_H_

#include <list>
#include <string>

using namespace std;

class Expression{
    public:
    virtual int evaluate()=0;
};

class Declaration{
    public:
    virtual bool check()=0;
};

class BinaryExpression: public Expression {
    public:
        BinaryExpression(Expression * expr1, Expression * expr2){
            this->expr1 = expr1;
            this->expr2 = expr2;
        }
        Expression * expr1;
        Expression * expr2;
};

class NameDeclaration{
    public:
        NameDeclaration(Declaration * name){
            this->name = name;
        }
        Declaration * name;
};

class AddExpression: public BinaryExpression{
    public:
        AddExpression(Expression * expr1, Expression * expr2): BinaryExpression(expr1, expr2){}
        int evaluate();
};

class SubExpression: public BinaryExpression{
    public:
        SubExpression(Expression * expr1, Expression * expr2): BinaryExpression(expr1, expr2){}
        int evaluate();
};

class MulExpression: public BinaryExpression{
    public:
        MulExpression(Expression * expr1, Expression * expr2): BinaryExpression(expr1, expr2){}
        int evaluate();
};

class DivExpression: public BinaryExpression{
    public:
        DivExpression(Expression * expr1, Expression * expr2): BinaryExpression(expr1, expr2){}
        int evaluate();
};

class MayExpression: public BinaryExpression{
    public:
        MayExpression(Expression * expr1, Expression * expr2): BinaryExpression(expr1, expr2){}
        int evaluate();
};

class MenExpression: public BinaryExpression{
    public:
        MenExpression(Expression * expr1, Expression * expr2): BinaryExpression(expr1, expr2){}
        int evaluate();
};

class IDDeclaration: public NameDeclaration{
    public:
        IDDeclaration(Declaration * name): NameDeclaration(name){}
        bool check();
};

class NumExpression: public Expression{
    public:
        NumExpression(float number){
            this->number = number;
        }
        float number;
        int evaluate();
};

class NameDeclaration: public Declaration{
    public:
        NameDeclaration(string identidad){
            this->identidad=identidad;
        }
        string identidad;
        bool check();
};

#endif