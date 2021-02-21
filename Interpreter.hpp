#ifndef __INTERPRETER__
#define __INTERPRETER__
/*
������ģʽ:
ͨ����һ��������Ҫ����ִ�У���������Խ��������еľ��ӱ�ʾ��Ϊ
һ��������﷨��ʱ������ʹ�ý�����ģʽ��
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
