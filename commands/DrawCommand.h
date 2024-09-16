#ifndef PAINTAPP_DRAWCOMMAND_H
#define PAINTAPP_DRAWCOMMAND_H

#include "Command.h"
#include "../shapes/factory/Factory.h"

class DrawCommand: public Command {
public:

    DrawCommand(std::vector<shape::Shape *> &shapes, shape::Factory *shapeFactory);

    void Execute() override;
    void unExecute() override;

    ~DrawCommand() override;


private:
    std::vector<shape::Shape *>& shapes;
    shape::Shape* created_shape = nullptr;
    shape::Factory* shape_factory = nullptr;
};


#endif //PAINTAPP_DRAWCOMMAND_H
