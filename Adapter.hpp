#ifndef __ADAPTER__
#define __ADAPTER__

/*
˫�������ʺ��޸ĵ�ʱ�򣬿��Կ���ʹ��������ģʽ
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
