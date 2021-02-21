#ifndef __FACADE__
#define __FACADE__

/*
为子系统的一组接口提供一个一致的界面。使用户使用起来更加方便
*/

#include <iostream>
#include <string>

using namespace std;

class SubSysOne{
public:
    void MethodOne(){
        cout<<"First Method"<<endl;
    }

};

class SubSysTwo{
public:
    void MethodTwo(){
        cout<<"Second Method"<<endl;
    }
};

class SubSysThree{
public:
    void MethodThree(){
        cout<<"Second Method"<<endl;
    }
};

class Facade{
private:
    SubSysOne       *sub1;
    SubSysTwo       *sub2;
    SubSysThree     *sub3;
public:
    Facade(){
        sub1 = new SubSysOne();
        sub2 = new SubSysTwo();
        sub3 = new SubSysThree();
    }
    ~Facade(){
        delete sub1;
        delete sub2;
        delete sub3;
    }
    void FacadeMethod(){
        sub1->MethodOne();
        sub2->MethodTwo();
        sub3->MethodThree();
    }
};

/*
int main(){
    Facade *test = new Facade();
    test->FacadeMethod();
    return 0;
}
*/


#endif
