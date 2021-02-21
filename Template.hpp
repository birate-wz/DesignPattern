

#ifndef __TEMPLATE__
#define __TEMPLATE__

/*
把不变的代码部分都转移到父类中，将可变的代码用 virtual 留到子类重
写
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AbstractClass{

public:
    void show(){
        cout<<"I am"<<GetName()<<endl;
    }
protected:
    virtual string GetName()=0;
};

class Naruto:public AbstractClass{

protected:
    virtual string GetName(){
        return "火影史上最帅的六代目­­­一鸣惊人 naruto";
    }
};

class OnePice: public AbstractClass{
protected:
    virtual string GetName(){
        return "我是无恶不做的大海贼­­­路飞";
    }

};
/*
int main(){
    Naruto *man = new Naruto();
    man->show();

    OnePice *man2 = new OnePice();
    man2->show();

}
*/
#endif // __TEMPLATE__
