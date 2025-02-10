#ifndef PAINTAPP_MANIPULATOR_H
#define PAINTAPP_MANIPULATOR_H

#include "Rectangle.h"
#include <unordered_map>

enum controlType { None, TopLeft, TopMid, TopRight, MidLeft, Centre, MidRight, BottomLeft, BottomMid, BottomRight };

namespace shape {

    class Manipulator: public Shape {

    private:

        int control_size = 5;
        std::shared_ptr<Shape> attached_shape = nullptr;
        controlType selected_control = None;
        std::unordered_map<controlType, Rectangle> controls;

        void Update();
        void updateControls();

    
    public:

        explicit Manipulator(std::shared_ptr<Shape> attachedShape);

        std::shared_ptr<Shape> getAttachedShape() const;
        controlType getSelectedControl() const;
        void setAttachedShape(std::shared_ptr<Shape> attachedShape);

        void Drag(int dx, int dy);
        void Touch(int x, int y);
        void Draw(Painter &painter) const override;


    };

} // shape

#endif //PAINTAPP_MANIPULATOR_H
