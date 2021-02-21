
#ifndef __PROPTOTYPE__
#define __PROPTOTYPE__

/*
��һ�������ٴ�������һ���ɶ��ƵĶ��󣬶�����֪���κδ�����ϸ�ڡ�
������ߴ��������ܡ� ˵���˾� COPY ��������һ������������ COPY ��һ��
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Prototype{  //�������

private:
    string m_strName;
public:
    Prototype(string strName) {m_strName = strName;}
    Prototype(){m_strName = "";}
    void show(){
        cout<<m_strName<<endl;
    }
    virtual Prototype*clone()=0;
};

class ConcretePrototype1:public Prototype{

public:
    ConcretePrototype1(string strName):Prototype(strName){}
    ConcretePrototype1(){}

    virtual Prototype* clone(){
        ConcretePrototype1 *p = new ConcretePrototype1();
        *p = *this; // ���ƶ���
        return p;
    }
};

class ConcretePrototype2:public Prototype{
public:
    ConcretePrototype2(string strName):Prototype(strName){}
    ConcretePrototype2(){}

    virtual Prototype *clone(){
        ConcretePrototype2 *p = new ConcretePrototype2();
        *p = *this;
        return p;
    }

};

/*
int main(){
    ConcretePrototype1 *test1 = new ConcretePrototype1("С��");
    ConcretePrototype2 *test2 = (ConcretePrototype2*)test->Clone();

    test1->show();
    test2->show();
    return 0;

}
*/
#endif // __PROPTOTYPE__


