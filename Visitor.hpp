#ifndef __VISITOR__
#define __VISITOR__

/*
������ģʽ:
���������ݽṹ�ȶ���ϵͳ���������ݽṹ�����������ݽṹ�ϵĲ���
���뿪��ʹ�ò�������
�ŵ㣺�����Ӳ��������ף���Ϊ�����²������൱������һ�������ߣ�������ģ
ʽ���йص���Ϊ���е�һ�������߶�����
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Man;
class Women;
//��Ϊ

class Action{
public:
    virtual void GetManConclusion(Man* ConcreteElementA)=0;
    virtual void GetWomenConclusion(Women* ConcreteElementB)=0;
};
//�ɹ�
class Success:public Action{
public:
    virtual void GetManConclusion(Man* ConcreteElementA){
        cout<<"GetManConclusion success"<<endl;
    }
    virtual void GetWomenConclusion(Women* ConcreteElementB){
        cout<<"GetWomenConclusion success"<<endl;
    }
};
//ʧ��
class Failure:public Action{
public:
    virtual void GetManConclusion(Man* ConcreteElementA){
        cout<<"GetManConclusion Failure"<<endl;
    }
    virtual void GetWomenConclusion(Women* ConcreteElementB){
        cout<<"GetWomenConclusion Failure"<<endl;
    }
};

//��������
class Person1{
public:
    virtual void Accept(Action* visitor)=0;
};
//����
class Man:public Person1{
public:
    virtual void Accept(Action* visitor){
        visitor->GetManConclusion(this);
    }
};
//Ů��
class Women:public Person1{
public:
    virtual void Accept(Action* visitor){
        visitor->GetWomenConclusion(this);
    }
};
//����ṹ��
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
