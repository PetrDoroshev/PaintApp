#include "Manipulator.h"
#include <iostream>

namespace shape {

    Manipulator::Manipulator(std::shared_ptr<Shape> attachedShape) : attached_shape(attachedShape) {

        for (int i = TopLeft; i <= BottomRight; i++) {
            controls[static_cast<controlType>(i)] = Rectangle();
            controls[static_cast<controlType>(i)].setOutlineColor(Color(0, 0, 0, 255));
            controls[static_cast<controlType>(i)].setFillColor(Color(255, 255, 255, 255));
        }
    }

    std::shared_ptr<Shape> Manipulator::getAttachedShape() const {
        return attached_shape;
    }

    void Manipulator::setAttachedShape(std::shared_ptr<Shape> attachedShape) {
        attached_shape = attachedShape;
        Update();
    }

    void Manipulator::Draw(Painter& painter) const {

        if (!attached_shape) return;
        
        painter.DrawRect(Rectangle(x, y, width, height, Color(0, 0, 0, 255), Color(255, 255, 255, 0)));

        for (auto& control: controls) {

            if (control.first != Centre) {
                painter.DrawRect(control.second);
            }
        }

    }

    void Manipulator::Update() {

        if (!attached_shape) return;
        
        this->setPos(attached_shape->getX() , attached_shape->getY());
        this->setSize(attached_shape->getWidth(), attached_shape->getHeight());

        updateControls();
    }

    void Manipulator::updateControls() {

        int i = TopLeft;
        for (int _y = y; _y <= y + height; _y += height / 2) {
            for (int _x = x; _x <= x + width; _x += width / 2) {

                auto ct = static_cast<controlType>(i);

                if (ct == Centre) {
                    controls[ct] = Rectangle(x, y, width, height);

                }
                else {
                    controls[ct].setPos(_x - control_size / 2, _y - control_size / 2);
                    controls[ct].setWidth(control_size);
                    controls[ct].setHeight(control_size);
                }
                i++;
            }
        }
    }

    void Manipulator::Drag(int dx, int dy) {

        if (!attached_shape) return;

        int dw, dh;

        switch (selected_control) {

            case(TopLeft):
                dw = -dx; dh = -dy;
                break;

            case(TopMid):
                dw = 0; dh = -dy;
                dx = 0;
                break;

            case(TopRight):
                dw = dx; dh = -dy;
                dx = 0;
                break;

            case(MidLeft):
                dw = -dx; dh = 0;
                dy = 0;
                break;

            case(MidRight):
                dw = dx; dh = 0;
                dx = 0; dy = 0;
                break;

            case(BottomLeft):
                dw = -dx; dh = dy;
                dy = 0;
                break;

            case(BottomMid):
                dw = 0; dh = dy;
                dx = 0; dy = 0;
                break;

            case (BottomRight):
                dw = dx; dh = dy;
                dx = 0; dy = 0;
                break;

            case (Centre):
                dw = 0; dh = 0;
                break;

            case(None):
                return;
        }

        double new_width = attached_shape->getWidth() + dw;
        double new_height = attached_shape->getHeight() + dh;

        double new_x = attached_shape->getX() + dx;
        double new_y = attached_shape->getY() + dy;

       
        attached_shape->setPos(std::fmin(attached_shape->getX() + attached_shape->getWidth() - 10, new_x), 
                               std::fmin(attached_shape->getY() + attached_shape->getHeight() - 10, new_y));

        attached_shape->setSize(std::fmax(10, new_width), std::fmax(10, new_height));
        

        Update();
    }

    void Manipulator::Touch(int x, int y) {

        selected_control = None;
        for (auto& control: controls) {

            if (control.second.Touch(x, y)) {
                selected_control = control.first;
            }
        }

        if (selected_control == None) {
            attached_shape = nullptr;
        }
    }

    controlType Manipulator::getSelectedControl() const {
        return selected_control;
    }
} // shape