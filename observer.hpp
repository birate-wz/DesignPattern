#ifndef __OBSERVER__
#define __OBSERVER__

/*
������һ��һ�Զ�Ĺ�ϵ���ö���۲���󣨹�˾Ա����ͬʱ����һ������������飩���������״̬�����仯ʱ����֪ͨ���еĹ۲��ߣ�ʹ�����ܹ������Լ���
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Secretary;

class StockOberver{  //�۲���� �۲���
private:
    string name;
    Secretary* sub;
public:
    StockOberver(string strname, Secretary* strsub){
        name = strname;
        sub = strsub;
    }
    void Update();

};

class Secretary{  //������(�������֪ͨ��)
private:
    vector<StockOberver> observer;
public:
    string action;
    void Add(StockOberver ob){
        observer.push_back(ob);
    }
    void Notify(){
        vector<StockOberver>::iterator p = observer.begin();
        while(p!=observer.end()){
            (*p).Update();
            p++;
        }
    }

};
void StockOberver::Update(){

    cout<<name<<":"<<sub->action<<",staring to work!"<<endl;
}
/*
int main(){
    Secretary *p = new Secretary(); //����֪ͨ��

    StockOberver *s1 = new StockOberver("xiao li",p);
    StockOberver *s2 = new StockOberver("xiao zhao",p);

    p->Add(s1);
    p->Add(s2);

    p->action="�ϰ�����";
    p->Notify();
    return 0;

}
*/
#endif // __OBSERVER__

