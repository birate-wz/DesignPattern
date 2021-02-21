#ifndef __BRIDGE__
#define __BRIDGE__

/*
桥接模式:
将抽象部分与实现部分分离，使它们可以独立变化。
这里说的意思不是让抽象基类与具体类分离，而是现实系统可能有多角度分类，
每一种分类都有可能变化，那么把这种多角度分离出来让它们独立变化，减少它们之间的耦
合性，即如果继承不能实现“开放－封闭原则”的话，就应该考虑用桥接模式。
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//手机软件
class HandsetSoft{
public:
    virtual void Run()=0;

};

//游戏软件
class HandsetGame:public HandsetSoft{
public:
    virtual void Run(){
        cout<<"run phone game"<<endl;
    }
};
//通讯录软件
class HandsetAddressList:public HandsetSoft{
public:
    virtual void Run(){
        cout<<"phone address list"<<endl;
    }
};

//手机品牌
class HandsetBrand{
protected:
    HandsetSoft *m_soft;
public:
    void SetHandsetSoft(HandsetSoft* temp){
        m_soft = temp;
    }
    virtual void Run()=0;
};
//M品牌
class HandsetBrandM:public HandsetBrand{
public:
    virtual void Run(){
        m_soft->Run();
    }
};

//N品牌
class HandsetBrandN:public HandsetBrand{
public:
    virtual void Run(){
        m_soft->Run();
    }
};
/*
int main(){
    HandsetBrand* brand = new HandsetBrandM();
    brand->SetHandsetSoft(new HandsetGame());
    brand->Run();
    brand->SetHandsetSoft(new HandsetAddressList());
    brand->Run();

    return 0;

}
*/

#endif
