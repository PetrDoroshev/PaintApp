#include "ResizeCommand.h"

ResizeCommand::ResizeCommand(shape::Shape *modifiedShape, double prevX, double prevY, double prevWidth, double prevHeight) : 
                             modified_shape(modifiedShape), 
                             prev_x(prevX), 
                             prev_y(prevY),
                             prev_width(prevWidth), 
                             prev_height(prevHeight) {}

void ResizeCommand::Execute() {

}

void ResizeCommand::unExecute() {

    modified_shape->setPos(prev_x, prev_y);
    modified_shape->setSize(prev_width, prev_height);

}

