#ifndef __ADAPTER__
#define __ADAPTER__

/*
双方都不适合修改的时候，可以考虑使用适配器模式
*/

#include<iostream>
using namespace std;

class Target{
public:
    virtual void Request(){
        cout<<"common request"<<endl;
    }
};

class Adaptee{
public:
    void SpecificalRequest(){
        cout<<"special request"<<endl;
    }
};

class Adapter:public Target{
private:
    Adaptee *ada;
public:
    virtual void Request(){
        ada->SpecificalRequest();
        Target::Request();
    }
    Adapter(){
        ada = new Adaptee();
    }
    ~Adapter(){
        delete ada;
    }
};
/*
int main(){
    Adapter *ada = new Adapter();
    ada->Request();
    delete ada;
    return;
}
*/
#endif
