#ifndef __COMMAND__
#define __COMMAND__
/*
����ģʽ:
һ������������У��������Խ����������־���������������һ����
�Ծܾ����ġ����һ���������಻Ӱ��������

����ģʽ������һ�������Ķ�����֪����ô����һ�������Ķ���ֿ�
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//����ʦ��
class Barbucer{
public:
    void MakeMutton(){
        cout<<"roast mutton"<<endl;
    }
    void MakeChickenWing(){
        cout<<"roast chickenwing"<<endl;
    }
};
//����������:
class Command{
protected:
    Barbucer* receiver;
public:
    Command(Barbucer* temp){
        receiver = temp;
    }
    virtual void ExecuteCmd()=0;
};
//����������
class BakeMuttonCmd:public Command{
public:
    BakeMuttonCmd(Barbucer* temp):Command(temp){}
    virtual void ExecuteCmd(){
        receiver->MakeMutton();
    }
};
//�����������
 class ChickenWingCmd:public Command{
 public:
     ChickenWingCmd(Barbucer*temp):Command(temp){}
     virtual void ExecuteCmd(){
        receiver->MakeChickenWing();
     }

 };

 //����Ա��
 class Waiter{
 protected:
     vector<Command*>m_commandList;
 public:
    void SetCmd(Command* temp){
        m_commandList.push_back(temp);
        cout<<"add order"<<endl;
    }
    void Notify(){
        auto p = m_commandList.begin();
        while(p!=m_commandList.end()){
            (*p)->ExecuteCmd();
            p++;
        }
    }
 };
/*
 int main(){
    Barbucer* barbucer = new Barbucer();
    Command* cmd = new BakeMuttonCmd(barbucer);
    Command* cmd2 = new ChickenWingCmd(barbucer);

    Waiter* girl = new Waiter();

    girl->SetCmd(cmd);
    girl->SetCmd(cmd1);

    girl->Notify();
    return 0;
 }
 */
#endif // __COMMAND__

