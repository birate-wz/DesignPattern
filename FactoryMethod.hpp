
#ifndef __FACTORYMETHOD__
#define __FACTORYMETHOD__

#include <string>
#include <iostream>

using namespace std;
/*
�����˼򵥹���ģʽ�в����ؿ��ţ����ԭ�򡣹�������ģʽ��ѡ����
���Ƶ��˿ͻ���ȥʵ�֣����������¹��ܾͲ����޸�ԭ�����ֱ࣬���޸Ŀͻ��˼���
*/
class LeiFeng{   //�൱��product
public:
    virtual void Sweep(){
        cout<<"�׷�ɨ��"<<endl;
    }
};

class Student:public LeiFeng{  //�൱��ConcreteProduct
public:
    virtual void Sweep(){
        cout<<"��ѧ��ɨ��"<<endl;
    }
};
class Volenter:public LeiFeng{
public:
    virtual void Sweep(){
        cout<<"־Ը��"<<endl;
    }

};
class LeiFengFactory{  //��������Create
public:
    virtual LeiFeng* CreateLeiFeng(){
        return new LeiFeng();
    }
};
//����������
class StudentFactory:public LeiFengFactory{
public:
    virtual LeiFeng* CreateLeiFeng(){
        return new Student();
    }
};

class VolenterFactory:public LeiFengFactory{

public:
    virtual LeiFeng* CreateLeiFeng(){
        return new Volenter();
    }
};

/*
int main(){
    LeiFengFactory *sf = new LeiFengFactory();
    LeiFeng *s = sf->CreateLeiFeng();

    s->Sweep();
    delete s;
    delete sf;
    return 0;
}
*/
#endif __FACTORYMETHOD__
