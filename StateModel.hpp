#ifndef __STATEMODEL__
#define __STATEMODEL__

/*
��һ���������Ϊȡ��������״̬������������������ʱ�̸���״̬��
��������Ϊʱ���ɿ����õ�״̬ģʽ��
*/
#include <iostream>
using namespace std;

class Work;
class ForenoonState;
class NoonState;

class State{
public:
    virtual void WriteProgram(Work* w) = 0;

};

class Work{
private:
    State *current;
public:
    double hour;
    Work();
    void SetState(State * temp){
        current = temp;
    }
    void Writeprogram(){
        current->WriteProgram(this);
    }
};

class NoonState:public State{

public:
    virtual void WriteProgram(Work* w){
        cout<<"excute"<<endl;
        if(w->hour < 13)
            cout<<"not bad"<<endl;
        else
            cout<<"not, sleep"<<endl;
    }
};
class ForenoonSate:public State{
public:
    virtual void WriteProgram(Work* w){
        if(w->hour < 12)
            cout<<"spirit not bad"<<endl;
        else {
            w->SetState(new NoonState);
            w->Writeprogram();
        }

    }
};

Work::Work(){
    current = new ForenoonSate();
}
/*
int main(){
    Work *mywork = new Work();
    mywork->hour = 9;
    mywork->Writeprogram();
    mywork->hour = 14;
    mywork->Writeprogram();
    return 0;
}
*/
#endif // __STATEMODEL__
