#ifndef __ABSTRACTFACTORY__
#define __ABSTRACTFACTORY__

/*
定义了一个创建一系列相关或相互依赖的接口，而无需指定它们的具体
类。
用于交换产品系列，如 ACCESS­>SQL SERVER；
产品的具体类名被具体工厂的实现分离
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class IUser{  //用户抽象接口
public:
    virtual void Getuser() = 0;
    virtual void InsertUser() = 0;

};

class IDepartment{  //部门抽象接口
public:
    virtual void GetDepartment() = 0;
    virtual void InsertDepartment() = 0;
};
class CAccessUser:public IUser{  //Access用户
public:
    virtual void Getuser(){
        cout<<"Access GetUser"<<endl;
    }
    virtual void InsertUser(){
        cout<<"Access InsertUser"<<endl;
    }
};

class CAccessDepartment:public IDepartment{ //Access 部门
public:
    virtual void GetDepartment(){
        cout<<"Access GetDepartment"<<endl;
    }
    virtual void InsertDepartment(){
        cout<<"Access InsertDepartment"<<endl;
    }
};
class CSqlUser:public IUser{   //SQL 用户
public:
    virtual void Getuser(){
        cout<<"Sql User"<<endl;
    }
    virtual void InsertUser(){
        cout<<"Sql User"<<endl;
    }
};

class CSqlDepartment:public IDepartment{  //SQL部门类
    virtual void GetDepartment(){
        cout<<"Sql getDepartment"<<endl;
    }
    virtual void InsertDepartment(){
        cout<<"Sql InsertDepartment"<<endl;
    }
};

class IFactory{   //抽象工厂
public:
    virtual IUser*CreateUser() = 0;
    virtual IDepartment *CreateDepartment() = 0;
};
class AccesFactory:public IFactory{  //Access 工厂
public:
    virtual IUser* CreateUser(){
        return new CAccessUser();
    }
    virtual IDepartment *CreateDepartment(){
        return new CAccessDepartment();
    }
};

class SqlFactory:public IFactory{
public:
    virtual IUser* CreateUser(){
        return new CSqlUser();
    }
    virtual IDepartment *CreateDepartment(){
        return new CSqlDepartment();
    }
};
/*
int main(){
    IFactory *factory = new SqlFactory();
    IUser *user = factory->CreateUser();
    IDepartment *depart = factory->CreateDepartment();
    user->Getuser();
    depart->GetDepartment();
    return 0;

}
*/
#endif // __ABSTRACTFACTORY__

