#ifndef PAINTAPP_PROTOTYPESHAPEFACTORY_H
#define PAINTAPP_PROTOTYPESHAPEFACTORY_H

#include "ShapeFactory.h"
#include "Factory.h"

template<class ShapeType>
class PrototypeShapeFactory: public shape::Factory {
public:
    explicit PrototypeShapeFactory(ShapeType shapePrototype) : shape_prototype(shapePrototype) {}

    ShapeType *Create() const override {

        return new ShapeType(shape_prototype);
    }

private:
    ShapeType shape_prototype;

};



#endif //PAINTAPP_PROTOTYPESHAPEFACTORY_H
