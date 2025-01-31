#include "ManipulatorTool.h"
#include "../paint_surface.h"
#include <iostream>


ManipulatorTool::ManipulatorTool(PaintSurface *paintSurface, CommandManager* commandManager): Tool(paintSurface, commandManager) {}

void ManipulatorTool::onMousePress(QMouseEvent *event) {

    if (event->button() == Qt::MouseButton::LeftButton) {

        int x = event->pos().x();
        int y = event->pos().y();

        prev_x = x, prev_y = y;
        paintSurface->manipulator.Touch(x, y);

        shape::Shape* attached_shape;

        if ((attached_shape = paintSurface->manipulator.getAttachedShape()) != nullptr) {

            if (paintSurface->manipulator.getSelectedControl() == Centre) {

                commandManager->ExecuteCommand(new MoveCommand(attached_shape, attached_shape->getX(), attached_shape->getY()));
            }
            else if (paintSurface->manipulator.getSelectedControl() != None) {

                commandManager->ExecuteCommand(new ResizeCommand(attached_shape,
                                                                 attached_shape->getX(),
                                                                 attached_shape->getY(),
                                                                 attached_shape->getWidth(),
                                                                 attached_shape->getHeight()));
            }
        }

        is_click = true;
    }
}

void ManipulatorTool::onMouseMove(QMouseEvent *event) {

    if (event->buttons() == Qt::MouseButton::LeftButton) {

        paintSurface->manipulator.Drag(event->pos().x() - prev_x, event->pos().y() - prev_y);

        prev_x = event->pos().x();
        prev_y = event->pos().y();

        is_click = false;
    }
}

void ManipulatorTool::onMouseRelease(QMouseEvent *event) {

    if (!is_click) return;

    if (event->button() == Qt::MouseButton::LeftButton) {

        int x = event->pos().x();
        int y = event->pos().y();

        prev_x = x, prev_y = y;

        double min_area = paintSurface->width() * paintSurface->height();
        shape::Shape *min_area_shape = nullptr;

        for (auto shape: paintSurface->shapes) {

            if (shape->Touch(x, y)) {

                if (shape->getArea() < min_area) {
                    min_area = shape->getArea();
                    min_area_shape = shape;
                }
            }
        }
        if (min_area_shape != nullptr) {

            if (ctrl_pressed) {
                shape_group.Add(min_area_shape);
                paintSurface->manipulator.setAttachedShape(&shape_group);
            } 
            else {
                paintSurface->manipulator.setAttachedShape(min_area_shape);
            }
        } 
        else {
            shape_group.Clear();
        }
    }
}

void ManipulatorTool::onKeyPress(QKeyEvent *event) {

    if (event->key() == Qt::Key::Key_Control) {
        ctrl_pressed = true;
    }
}

void ManipulatorTool::onKeyRelease(QKeyEvent *event) {

    if (event->key() == Qt::Key::Key_Control) {
        ctrl_pressed = false;
    }
}

