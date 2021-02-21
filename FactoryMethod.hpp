
#ifndef __FACTORYMETHOD__
#define __FACTORYMETHOD__

#include <string>
#include <iostream>

using namespace std;
/*
修正了简单工厂模式中不遵守开放－封闭原则。工厂方法模式把选择判
断移到了客户端去实现，如果想添加新功能就不用修改原来的类，直接修改客户端即可
*/
class LeiFeng{   //相当于product
public:
    virtual void Sweep(){
        cout<<"雷锋扫地"<<endl;
    }
};

class Student:public LeiFeng{  //相当于ConcreteProduct
public:
    virtual void Sweep(){
        cout<<"大学生扫地"<<endl;
    }
};
class Volenter:public LeiFeng{
public:
    virtual void Sweep(){
        cout<<"志愿者"<<endl;
    }

};
class LeiFengFactory{  //工厂基类Create
public:
    virtual LeiFeng* CreateLeiFeng(){
        return new LeiFeng();
    }
};
//工厂具体类
class StudentFactory:public LeiFengFactory{
public:
    virtual LeiFeng* CreateLeiFeng(){
        return new Student();
    }
};

class VolenterFactory:public LeiFengFactory{

public:
    virtual LeiFeng* CreateLeiFeng(){
        return new Volenter();
    }
};

/*
int main(){
    LeiFengFactory *sf = new LeiFengFactory();
    LeiFeng *s = sf->CreateLeiFeng();

    s->Sweep();
    delete s;
    delete sf;
    return 0;
}
*/
#endif __FACTORYMETHOD__
