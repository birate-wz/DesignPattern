#ifndef __SINGLETON__
#define __SINGLETON__

/*
��֤һ�������һ��ʵ�������ṩһ����������ȫ�ַ��ʵ�
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Singleton{
private:
    Singleton(){}
    static Singleton* single;
public:
    static Singleton *GetInstance(){
        if(single = NULL)
            single = new Singleton();
        return single;
    }
};

Singleton * Singleton::single = NULL;

/*
int main(){
    Singleton* s1 = Singleton::GetInstance();
    Singleton* s2 = Singleton::GetInstance();
    if(s1 == s2)
        cout<<"ok"<<endl;
    else
        cout<<"no"<<endl;
}
*/
#endif // __SINGLETON__
