#ifndef __OBSERVER__
#define __OBSERVER__

/*
定义了一种一对多的关系，让多个观察对象（公司员工）同时监听一个主题对象（秘书），主题对象状态发生变化时，会通知所有的观察者，使它们能够更新自己。
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Secretary;

class StockOberver{  //观察对象 观察者
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

class Secretary{  //秘书类(主题对象，通知类)
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
    Secretary *p = new Secretary(); //创建通知者

    StockOberver *s1 = new StockOberver("xiao li",p);
    StockOberver *s2 = new StockOberver("xiao zhao",p);

    p->Add(s1);
    p->Add(s2);

    p->action="老板来了";
    p->Notify();
    return 0;

}
*/
#endif // __OBSERVER__

