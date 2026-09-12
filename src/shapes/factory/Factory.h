#ifndef PAINTAPP_FACTORY_H
#define PAINTAPP_FACTORY_H

#include "../Shape.h"

namespace shape {

    class Factory {
    public:
        virtual Shape* Create() const = 0;
        virtual ~Factory(){};
    };
}

#endif //PAINTAPP_FACTORY_H
