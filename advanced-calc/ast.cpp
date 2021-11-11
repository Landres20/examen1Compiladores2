#include "ast.h"
#include <map>
#include <iostream>

int NumExpression::evaluate(){
    return this->number;
}

bool NameDeclaration::check(){
    return this->identidad;
}

int AddExpression::evaluate(){
    float res = this->expr1->evaluate()+this->expr2->evaluate();
    printf("\nEl resultado de la suma fue: %f", res);
    return this->expr1->evaluate() + this->expr2->evaluate();
}
int SubExpression::evaluate(){
    float res = this->expr1->evaluate()-this->expr2->evaluate();
    printf("\nEl resultado de la resta fue: %f", res);
    return this->expr1->evaluate() - this->expr2->evaluate();
}
int MulExpression::evaluate(){
    float res = this->expr1->evaluate()*this->expr2->evaluate();
    printf("\nEl resultado de la multiplicacion fue: %f", res);
    return this->expr1->evaluate() * this->expr2->evaluate();
}
int DivExpression::evaluate(){
    float res = this->expr1->evaluate()/this->expr2->evaluate();
    printf("\nEl resultado de la division fue: %f", res);
    return this->expr1->evaluate() / this->expr2->evaluate();
}
int MayExpression::evaluate(){
    float res = this->expr1->evaluate()>this->expr2->evaluate();
    printf("\nEl resultado del mayor que fue: %f", res);
    return this->expr1->evaluate() > this->expr2->evaluate();
}
int MenExpression::evaluate(){
    float res = this->expr1->evaluate()<this->expr2->evaluate();
    printf("\nEl resultado del menor que fue: %f", res);
    return this->expr1->evaluate() < this->expr2->evaluate();
}
