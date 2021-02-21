#ifndef __REQUEST__
#define __REQUEST__
/*
������ģʽ:
ʹ��������л��ᴦ�����󣬴Ӷ���������ķ����ߺͽ�����֮���
��Ϲ�ϵ���������������һ���������������������ݸ�����ֱ����һ��������Ϊֹ
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//����
class Request{
public:
    string m_strContent;
    int m_nNumber;
};

//������
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
//����
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
//�ܼ�
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

