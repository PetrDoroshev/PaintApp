#ifndef PAINTAPP_COMMANDMANAGER_H
#define PAINTAPP_COMMANDMANAGER_H

#include <stack>
#include<memory>
#include "Command.h"

class CommandManager {

public:
    void ExecuteCommand(std::unique_ptr<Command> command);
    void unExecuteCommand();
    void reExevuteCommand();

private:
    std::stack<std::unique_ptr<Command>> undo_stack;
    std::stack<std::unique_ptr<Command>> redo_stack;
};


#endif //PAINTAPP_COMMANDMANAGER_H
