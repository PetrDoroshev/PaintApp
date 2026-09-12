#include "CommandManager.h"

void CommandManager::ExecuteCommand(std::unique_ptr<Command> command) {

    if (!command) {
        return;
    }

    command->Execute();
    undo_stack.push(std::move(command));
}

void CommandManager::unExecuteCommand() {

    if (undo_stack.empty()) {
        return;
    }

    undo_stack.top()->unExecute();
    undo_stack.pop();
}
