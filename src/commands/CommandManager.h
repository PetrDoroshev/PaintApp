#ifndef PAINTAPP_COMMANDMANAGER_H
#define PAINTAPP_COMMANDMANAGER_H

#include <stack>
#include<memory>
#include "Command.h"

class CommandManager {

public:
    void ExecuteCommand(std::unique_ptr<Command> command);
    void unExecuteCommand();

private:
    std::stack<std::unique_ptr<Command>> command_stack;


};


#endif //PAINTAPP_COMMANDMANAGER_H
