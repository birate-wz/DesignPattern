#ifndef __COMMAND__
#define __COMMAND__
/*
命令模式:
一、建立命令队列；二、可以将命令记入日志；三、接收请求的一方可
以拒绝；四、添加一个新命令类不影响其它类

命令模式把请求一个操作的对象与知道怎么操行一个操作的对象分开
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//烤肉师傅
class Barbucer{
public:
    void MakeMutton(){
        cout<<"roast mutton"<<endl;
    }
    void MakeChickenWing(){
        cout<<"roast chickenwing"<<endl;
    }
};
//抽象命令类:
class Command{
protected:
    Barbucer* receiver;
public:
    Command(Barbucer* temp){
        receiver = temp;
    }
    virtual void ExecuteCmd()=0;
};
//烤羊肉命令
class BakeMuttonCmd:public Command{
public:
    BakeMuttonCmd(Barbucer* temp):Command(temp){}
    virtual void ExecuteCmd(){
        receiver->MakeMutton();
    }
};
//烤鸡翅膀命令
 class ChickenWingCmd:public Command{
 public:
     ChickenWingCmd(Barbucer*temp):Command(temp){}
     virtual void ExecuteCmd(){
        receiver->MakeChickenWing();
     }

 };

 //服务员类
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

