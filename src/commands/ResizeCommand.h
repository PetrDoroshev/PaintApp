#ifndef PAINTAPP_RESIZECOMMAND_H
#define PAINTAPP_RESIZECOMMAND_H

#include "Command.h"

class ResizeCommand: public Command{
public:
    ResizeCommand(shape::Shape *modifiedShape, double prevX, double prevY, double prevWidth, double prevHeight);

    ~ResizeCommand() override = default;

    void Execute() override;

    void unExecute() override;


private:

    shape::Shape* modified_shape;
    double prev_x, prev_y;
    double prev_width, prev_height;

};


#endif //PAINTAPP_RESIZECOMMAND_H
