

#ifndef __SIMPLEFATCTORY__
#define __SIMPLEFATCTORY__

/*
    主要用于创建对象。新添加类时，不会影响以前的系统代码。核心思想是用一个工厂来
    根据输入的条件产生不同的类，然后根据不同类的 virtual 函数得到不同的结果。
    GOOD:适用于不同情况创建不同的类时
    BUG：客户端必须要知道基类和工厂类，耦合性差
*/
class Coperation{
public:
    int m_nFirst;
    int m_nSecond;
    virtual double GetResult(){
        double dResult = 0;
        return dResult;
    }
};

class AddOperator:public Coperation{
public:
    virtual double GetResult(){
        return m_nFirst + m_nSecond;

    }

};

class SubOperator:public Coperation{
public:
    virtual double GetResult(){
        return m_nFirst- m_nSecond;
    }
};

class CCalculatorFactory{
public:
    static Coperation *Create(char Coperator);
};

Coperation* CCalculatorFactory::Create(char Coperator){
    Coperation *oper;
    switch (Coperator){

        case '+':
            oper = new AddOperator();
            break;
        case '-':
            oper = new SubOperator();
            break;
        default:
            oper = new AddOperator();
            break;
    }
    return oper;

}

/*
int main(){

    int a,b;
    cin>>a>>b;
    Coperation *op = CCalculatorFactory::Create('-');
    op->m_nFirst = a;
    op->m_nSecond = b;
    op->GetResult();
    return 0;

}
*/
#endif // __SIMPLEFATCTORY__
