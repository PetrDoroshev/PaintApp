#include "MoveCommand.h"

void MoveCommand::Execute() {

}

void MoveCommand::unExecute() {

    modified_shape->setPos(prev_x, prev_y);
}

MoveCommand::MoveCommand(shape::Shape* modified_shape, double prev_x, double prev_y) {

    this->modified_shape = modified_shape;
    this->prev_x = prev_x;
    this->prev_y = prev_y;
}