#ifndef __BRIDGE__
#define __BRIDGE__

/*
�Ž�ģʽ:
�����󲿷���ʵ�ֲ��ַ��룬ʹ���ǿ��Զ����仯��
����˵����˼�����ó���������������룬������ʵϵͳ�����ж�Ƕȷ��࣬
ÿһ�ַ��඼�п��ܱ仯����ô�����ֶ�Ƕȷ�����������Ƕ����仯����������֮�����
���ԣ�������̳в���ʵ�֡����ţ����ԭ�򡱵Ļ�����Ӧ�ÿ������Ž�ģʽ��
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ֻ����
class HandsetSoft{
public:
    virtual void Run()=0;

};

//��Ϸ���
class HandsetGame:public HandsetSoft{
public:
    virtual void Run(){
        cout<<"run phone game"<<endl;
    }
};
//ͨѶ¼���
class HandsetAddressList:public HandsetSoft{
public:
    virtual void Run(){
        cout<<"phone address list"<<endl;
    }
};

//�ֻ�Ʒ��
class HandsetBrand{
protected:
    HandsetSoft *m_soft;
public:
    void SetHandsetSoft(HandsetSoft* temp){
        m_soft = temp;
    }
    virtual void Run()=0;
};
//MƷ��
class HandsetBrandM:public HandsetBrand{
public:
    virtual void Run(){
        m_soft->Run();
    }
};

//NƷ��
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
