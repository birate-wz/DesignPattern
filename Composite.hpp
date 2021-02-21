#ifndef __COMPOSITE__
#define __COMPOSITE__

/**
整体和部分可以被一致对待（如 WORD 中复制一个文字、一段文字、
一篇文章都是一样的操作）
**/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Component{

public:
    string m_strName;
    Component(string strName){
        m_strName = strName;
    }
    virtual void Add(Component * com)=0;
    virtual void Display(int nDepth)=0;

};
class Leaf:public Component{
public:
    Leaf(string strName):Component(strName){}
    virtual void Add(Component* com){
        cout<<"leaf can't add"<<endl;
    }
    virtual void Display(int nDepth){
        string strtemp;
        for(int i=0;i<nDepth; ++i){
            strtemp+="-";
        }
        strtemp += m_strName;
        cout<<strtemp<<endl;
    }
};
class Composite:public Component{
private:
    vector<Component*> m_component;
public:
    Composite(string strName):Component(strName){}
    virtual void Add(Component* com){
        m_component.push_back(com);
    }
    virtual void Display(int nDepth){
        string strtemp;
        for(int i=0;i<nDepth; ++i){
            strtemp+="-";
        }
        strtemp+=m_strName;
        cout<<strtemp<<endl;
        auto p = m_component.begin();
        while(p!=m_component.end()){
            (*p)->Display(nDepth+2);
            p++;
        }
    }
};
/*
int main(){
    Composite *p = new Composite("xiao wang");
    p->Add(new Leaf("xiao li"));
    p->Add(new Leaf("xiao zhao"));

    Composite *p1 = new Composite("xiao xiao wu");
    p1->Add(new Leaf("da san"));

    p->Add(p1);
    p->Display(1);
    return 0;
}
*/
#endif // __COMPOSITE__
