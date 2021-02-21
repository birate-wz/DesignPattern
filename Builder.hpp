
#ifndef __BUILDER__
#define __BUILDER__

/*
�ڵ��������Ӷ�����㷨Ӧ�ö����ڸö������ɲ����Լ����ǵ�װ��
��ʽʱ���á�
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Person{
public:
    virtual void CreateHead() = 0;
    virtual void CreateHand() = 0;
    virtual void CreateBody() = 0;
    virtual void CreateFoot() = 0;

};
class ThinPerson:public Person{
public:
    virtual void CreateHead(){
        cout<<"thin head"<<endl;
    }
    virtual void CreateHand(){
        cout<<"thin hand"<<endl;
    }
    virtual void CreateBody(){
        cout<<"thin body"<<endl;
    }
    virtual void CreateFoot(){
        cout<<"thin foot"<<endl;
    }
};
class ThickPerson:public Person{
public:
    virtual void CreateHead(){
        cout<<"ThickPerson head"<<endl;
    }
    virtual void CreateHand(){
        cout<<"ThickPerson hand"<<endl;
    }
    virtual void CreateBody(){
        cout<<"ThickPerson body"<<endl;
    }
    virtual void CreateFoot(){
        cout<<"ThickPerson foot"<<endl;
    }
};
class Direct{
private:
    Person *p;
public:
    Direct(Person *temp) {p = temp;}
    void Create(){
        p->CreateHead();
        p->CreateHand();
        p->CreateBody();
        p->CreateFoot();
    }

};
/*
int main(){
    Person *p = new ThickPerson();
    Direct *d = new Direct(p);
    d->Create();
    delete p;
    delete d;
    return 0;

}
*/
/*
class Product{  //���ղ�Ʒlei
private:
    vector<string> m_product;
public:
    void Add(string strtemp){
        m_product.push_back(strtemp);
    }
    void show(){
        vector<string>::iterator p = m_product.begin();
        for(p = m_product.begin(); p!=m_product.end();p++)
            cout<<*p<<endl;
    }

};


class Builder{  //�����߻���
public:
    virtual void BuilderA() = 0;
    virtual void BuilderB() = 0;
    virtual Product* GetResult() = 0;
};

class ConcreteBuilder1:public Builder{  //��һ�ֽ�����
private:
    Product *m_product;
public:
    ConcreteBuilder1(){
        m_product = new Product();
    }
    virtual void BuilderA(){
        m_product->Add("one");
    }
    virtual void BuilderB(){
        m_product->Add("two");
    }
    virtual Product* GetResult(){
        m_product;
    }
};

class ConcreteBuilder2:public Builder{ //�ڶ��ֽ�����
private:
    Product *m_product;
public:
    ConcreteBuilder2(){
        m_product = new Product();
    }
    virtual void BuilderA(){
        m_product->Add("A");
    }
    virtual void BuilderB(){
        m_product->Add("B");
    }
    virtual Product* GetResult(){
        m_product;
    }
};

class Direct{  //ָ������
public:
    void Construct(Builder *temp){
        temp->BuilderA();
        temp->BuilderB();
    }
};*/
/*
int main(){
    Direct *p = new Direct();
    Builder *b1 = new ConcreteBuilder1();
    Builder *b2 = new ConcreteBuilder2();

    p->Construct(b1);   // ���õ�һ�ַ�ʽ
    Product *pb1 = b1->GetResult();
    pb1->show();

    p->Construct(b2);   // ���õ�һ�ַ�ʽ
    Product *pb2 = b2->GetResult();
    pb2->show();

}
*/
#endif // __BUILDER__

