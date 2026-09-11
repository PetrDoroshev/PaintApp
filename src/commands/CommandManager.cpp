#include "CommandManager.h"

void CommandManager::ExecuteCommand(std::unique_ptr<Command> command) {

    if (!command) {
        return;
    }

    command->Execute();
    command_stack.push(std::move(command));
}

void CommandManager::unExecuteCommand() {

    if (command_stack.empty()) {
        return;
    }

    command_stack.top()->unExecute();
    command_stack.pop();
}
