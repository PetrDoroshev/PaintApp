#ifndef PAINTAPP_SHAPEFACTORY_H
#define PAINTAPP_SHAPEFACTORY_H

#include "Factory.h"

namespace shape {

    template<class ShapeType>
    class ShapeFactory: public Factory {

    public:

        ShapeType* Create() const override {
            return new ShapeType;
        }
    };
} // shape

#endif //PAINTAPP_SHAPEFACTORY_H
