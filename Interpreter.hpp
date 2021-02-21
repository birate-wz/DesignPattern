#ifndef __INTERPRETER__
#define __INTERPRETER__
/*
解释器模式:
通常当一个语言需要解释执行，并且你可以将该语言中的句子表示成为
一个抽象的语法树时，可以使用解释器模式。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Context;
class AbstractExpression{
public:
    virtual void Interpret(Context* context) = 0;
};

class Expression:public AbstractExpression{
public:
    virtual void Interpret(Context* context){
        cout<<"Interpreter"<<endl;
    }

};
class NonterminalExpression:public AbstractExpression{
public:
    virtual void Interpret(Context* context){
        cout<<"NonterminalExpression"<<endl;
    }

};
class Context{
public:
    string input;
    string output;
};
/*
int main(){
    Context * context = new Context();
    vector<AbstractExpression*> expression;
    expression.push_back(new Expression());
    expression.push_back(new NonterminalExpression());
    expression.push_back(new NonterminalExpression());

    auto p = expression.begin();
    while(p!=expression.end()){

        (*p)->Interpret(context);
        p++;
    }
    return 0;

}
*/
#endif // __INTERPRETER__
