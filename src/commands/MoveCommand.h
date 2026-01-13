
#ifndef PAINTAPP_MOVECOMMAND_H
#define PAINTAPP_MOVECOMMAND_H

#include "Command.h"

class MoveCommand: public Command {

public:

    MoveCommand(shape::Shape* modified_shape, double prev_x, double prev_y);

    ~MoveCommand() override = default;
    void Execute() override;
    void unExecute() override;

private:

    shape::Shape* modified_shape = nullptr;
    double prev_x, prev_y;

};


#endif //PAINTAPP_MOVECOMMAND_H
