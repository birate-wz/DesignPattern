#ifndef __MEDIATOR__
#define __MEDIATOR__
/*
中介者模式:
用一个中介对象来封装一系列的对象交互，中介者使各对象不需要显示
的相互引用，从而降低耦合；而且可以独立地改变它们之间的交互
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Colleague;

class Mediator{
public:
    virtual void Send(string message, Colleague* col) = 0;

};

//抽象同事类
class Colleague{
protected:
    Mediator* mediator;
public:
    Colleague(Mediator* temp){
        mediator = temp;
    }

};
//同事1
class Colleague1:public Colleague{
public:
    Colleague1(Mediator* media):Colleague(media){}

    void Send(string strMessage){
        mediator->Send(strMessage, this);
    }
    void Notify(string strMessage){
        cout<<"colleague 1 get message"<<endl;
    }
};
//同事2
class Colleague2:public Colleague{
public:
    Colleague2(Mediator* media):Colleague(media){}

    void Send(string strMessage){
        mediator->Send(strMessage, this);
    }
    void Notify(string strMessage){
        cout<<"colleague 2 get message"<<endl;
    }
};

//具体中介者类
class ConcreteMediator:public Mediator{
public:
    Colleague1 *col1;
    Colleague2 *col2;
    virtual void Send(string message, Colleague* col){
        if(col == col1)
            col2->Notify(message);
        else
            col1->Notify(message);
    }

};
/*
int main(){
    ConcreteMediator* m = new ConcreteMediator();

    //让同事认识中介
    Colleague1* col1 = new Colleague1(m);
    Colleague2* col2 = new Colleague2(m);

    m->col1 = col1;
    m->col2 = col2;

    col1->Send("Have you had meals?")
    col2->Send("Not yet");
    return 0;
}
*/
#endif // __MEDIATOR__
