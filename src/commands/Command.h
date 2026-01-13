#ifndef PAINTAPP_COMMAND_H
#define PAINTAPP_COMMAND_H

#include <vector>
#include "../shapes/Shape.h"

class Command {

public:

    virtual ~Command() = default;

    virtual void Execute() = 0;
    virtual void unExecute() = 0;

};


#endif //PAINTAPP_COMMAND_H
