

#ifndef __SIMPLEFATCTORY__
#define __SIMPLEFATCTORY__

/*
    ��Ҫ���ڴ��������������ʱ������Ӱ����ǰ��ϵͳ���롣����˼������һ��������
    �������������������ͬ���࣬Ȼ����ݲ�ͬ��� virtual �����õ���ͬ�Ľ����
    GOOD:�����ڲ�ͬ���������ͬ����ʱ
    BUG���ͻ��˱���Ҫ֪������͹����࣬����Բ�
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
