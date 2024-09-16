#ifndef PAINTAPP_COMMANDMANAGER_H
#define PAINTAPP_COMMANDMANAGER_H

#include <stack>
#include "Command.h"

class CommandManager {

public:
    void ExecuteCommand(Command* command);
    void unExecuteCommand();

private:
    std::stack<Command*> command_stack;


};


#endif //PAINTAPP_COMMANDMANAGER_H
