#ifndef PAINTAPP_MANIPULATOR_H
#define PAINTAPP_MANIPULATOR_H

#include "Rectangle.h"
#include <unordered_map>

enum controlType { None, TopLeft, TopMid, TopRight, MidLeft, Centre, MidRight, BottomLeft, BottomMid, BottomRight };

namespace shape {

    class Manipulator: public Shape {

    private:

        int control_size = 5;
        Shape* attached_shape = nullptr;
        controlType selectedControl = None;
        std::unordered_map<controlType, Rectangle> controls;

        void update();
        void updateControls();


    public:

        explicit Manipulator(Shape *attachedShape);

        Shape *getAttachedShape() const;
        controlType getSelectedControl() const;
        void setAttachedShape(Shape *attachedShape);

        void drag(int dx, int dy);
        void touch(int x, int y);
        void Draw(Painter &painter) const override;


    };

} // shape

#endif //PAINTAPP_MANIPULATOR_H
