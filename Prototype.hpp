
#ifndef __PROPTOTYPE__
#define __PROPTOTYPE__

/*
从一个对象再创建另外一个可定制的对象，而无需知道任何创建的细节。
并能提高创建的性能。 说白了就 COPY 技术，把一个对象完整的 COPY 出一份
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Prototype{  //抽象基类

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
        *p = *this; // 复制对象
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
    ConcretePrototype1 *test1 = new ConcretePrototype1("小王");
    ConcretePrototype2 *test2 = (ConcretePrototype2*)test->Clone();

    test1->show();
    test2->show();
    return 0;

}
*/
#endif // __PROPTOTYPE__


