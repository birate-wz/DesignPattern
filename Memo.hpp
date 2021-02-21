#ifndef __MEMO__
#define __MEMO__

/*
�ڲ��ƻ���װ�Ե�ǰ���£�����һ��������ڲ�״̬�����ڸö���֮��
�������״̬�������Ϳ��Խ��Ժ�Ķ���״̬�ָ�����ǰ�����״̬��
�����ڹ��ܱȽϸ��ӵģ�����Ҫ��¼��ά��������ʷ���ࣻ������Ҫ���������ֻ����
�������е�һС����ʱ Originator ���Ը��ݱ���� Memo ��ԭ��ǰһ״̬��
*/

#include <iostream>
#include <string>

using namespace std;

class Memo;

class Originator{   //��������
public:
    string state;
    Memo *CreateMemo();
    void SetMemo(Memo* memo);
    void show(){
        cout<<"state:"<<state<<endl;
    }
};

class Memo{  //����¼��
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

class Caretaker{  //��������
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

