#ifndef __VISITOR__
#define __VISITOR__

/*
访问者模式:
适用于数据结构稳定的系统。它把数据结构和作用于数据结构上的操作
分离开，使得操作集合
优点：新增加操作很容易，因为增加新操作就相当于增加一个访问者，访问者模
式将有关的行为集中到一个访问者对象中
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Man;
class Women;
//行为

class Action{
public:
    virtual void GetManConclusion(Man* ConcreteElementA)=0;
    virtual void GetWomenConclusion(Women* ConcreteElementB)=0;
};
//成功
class Success:public Action{
public:
    virtual void GetManConclusion(Man* ConcreteElementA){
        cout<<"GetManConclusion success"<<endl;
    }
    virtual void GetWomenConclusion(Women* ConcreteElementB){
        cout<<"GetWomenConclusion success"<<endl;
    }
};
//失败
class Failure:public Action{
public:
    virtual void GetManConclusion(Man* ConcreteElementA){
        cout<<"GetManConclusion Failure"<<endl;
    }
    virtual void GetWomenConclusion(Women* ConcreteElementB){
        cout<<"GetWomenConclusion Failure"<<endl;
    }
};

//抽象人类
class Person1{
public:
    virtual void Accept(Action* visitor)=0;
};
//男人
class Man:public Person1{
public:
    virtual void Accept(Action* visitor){
        visitor->GetManConclusion(this);
    }
};
//女人
class Women:public Person1{
public:
    virtual void Accept(Action* visitor){
        visitor->GetWomenConclusion(this);
    }
};
//对象结构类
class ObjectStructure{
private:
    vector<Person1*> m_personList;
public:
    void Add(Person1* p){
        m_personList.push_back(p);
    }
    void Display(Action* a){
        auto p = m_personList.begin();
        while(p!=m_personList.end()){
            (*p)->Accept(a);
            p++;
        }
    }
};
/*
int main(){
    ObjectStructure* os = new ObjectStructure();
    os->Add(new Man());
    os->Add(new Women());

    Success *success = new Success();
    os->Display(success);

    Failure *fl = new Failure();
    os->Display(fl);
    return 0;

}
*/
#endif // __VISITOR__
