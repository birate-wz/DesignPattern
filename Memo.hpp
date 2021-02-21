#ifndef __MEMO__
#define __MEMO__

/*
在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外
保存这个状态，这样就可以将以后的对象状态恢复到先前保存的状态。
适用于功能比较复杂的，但需要记录或维护属性历史的类；或者需要保存的属性只是众
多属性中的一小部分时 Originator 可以根据保存的 Memo 还原到前一状态。
*/

#include <iostream>
#include <string>

using namespace std;

class Memo;

class Originator{   //发起人类
public:
    string state;
    Memo *CreateMemo();
    void SetMemo(Memo* memo);
    void show(){
        cout<<"state:"<<state<<endl;
    }
};

class Memo{  //备忘录类
public:
    string state;
    Memo(string strState){
        state = strState;
    }
};

Memo *Originator::CreateMemo(){
 return new Memo(state);
}

void Originator::SetMemo(Memo* memo){
    state = memo->state;
}

class Caretaker{  //管理者类
public:
    Memo * memo;

};
/*
int main(){
    Originator *on = new Originator();
    on->state = "on";
    on->show();

    Caretaker *c = new Caretaker();
    c->memo = on->CreateMemo();

    on->state="off";
    on->show();

    on->SetMemo(c->memo);
    on->show();
    return 0;
}
*/
#endif // __MEMO__

