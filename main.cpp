#include <iostream>
#include "FactoryMethod.hpp"
#include "Prototype.hpp"
#include "SimpleTactory.hpp"
#include "Template.hpp"
#include "Facade.hpp"
#include "Builder.hpp"
#include "observer.hpp"
#include "AbstractFactory.hpp"
#include "StateModel.hpp"
#include "Adapter.hpp"
#include "Memo.hpp"
#include "Composite.hpp"
#include "Singleton.hpp"
#include "bridge.hpp"
#include "Command.hpp"
#include "Request.hpp"
#include "Mediator.hpp"
#include "Interpreter.hpp"
#include "Visitor.hpp"
using namespace std;


int main(){
    ObjectStructure* os = new ObjectStructure();
    os->Add(new Man());
    os->Add(new Women());

    Success *success = new Success();
    os->Display(success);

    Failure *fl = new Failure();
    os->Display(fl);
    return 0;

}
