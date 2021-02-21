#ifndef __REQUEST__
#define __REQUEST__
/*
责任链模式:
使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的
耦合关系。将这个对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理为止
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//请求
class Request{
public:
    string m_strContent;
    int m_nNumber;
};

//管理者
class Manager{
protected:
    Manager* manager;
    string name;
public:
    Manager(string temp){
        name = temp;
    }
    void SetSuccessor(Manager* temp){
        manager = temp;
    }
    virtual void GetRequest(Request *request) = 0;
};
//经理
class CommonManager:public Manager{
public:
    CommonManager(string strTemp):Manager(strTemp){}
    virtual void GetRequest(Request *request){
        if(request->m_nNumber >=0 && request->m_nNumber <= 10){
            cout<<name<<"deal"<<request->m_nNumber<<"request"<<endl;
        }
        else{
            manager->GetRequest(request);
        }
    }
};
//总监
class MajorDemo:public Manager{
public:
    MajorDemo(string name):Manager(name){}
    virtual void GetRequest(Request* request){
        if(request->m_nNumber >= 10)
            cout<<name<<"deal"<<request->m_nNumber<<"request"<<endl;
    }
};
/*
int main(){
    Manager* common = new CommonManager("Zhang");
    Manager* major = new MajorDemo("Li");

    common->SetSuccessor(major);
    Request *req = new Request();
    req->m_nNumber = 33;
    common->GetRequest(req);

    req->m_nNumber=3;
    common->GetRequest(req);
    return 0;
}
*/
#endif // __REQUEST__

