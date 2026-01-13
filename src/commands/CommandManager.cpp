#include "CommandManager.h"

void CommandManager::ExecuteCommand(Command* command) {

    command->Execute();
    command_stack.push(command);
}

void CommandManager::unExecuteCommand() {

    if (command_stack.empty()) {
        return;
    }

    auto command = command_stack.top();
    command->unExecute();
    command_stack.pop();

    delete command;
}
