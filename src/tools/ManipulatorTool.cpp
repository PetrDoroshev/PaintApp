#include "ManipulatorTool.h"
#include "../paint_surface.h"
#include <iostream>


ManipulatorTool::ManipulatorTool(Canvas *canvas, CommandManager* commandManager): Tool(canvas, commandManager) {}

void ManipulatorTool::onMousePress(QMouseEvent *event) {

    if (event->button() == Qt::MouseButton::LeftButton) {

        int x = event->pos().x();
        int y = event->pos().y();

        prev_x = x, prev_y = y;
        manipulator->Touch(x, y);

        shape::Shape* attached_shape;

        if ((attached_shape = manipulator->getAttachedShape().lock().get()) != nullptr) {

            if (manipulator->getSelectedControl() == Centre) {

                commandManager->ExecuteCommand(new MoveCommand(attached_shape, attached_shape->getX(), attached_shape->getY()));
            }
            else if (manipulator->getSelectedControl() != None) {

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

        manipulator->Drag(event->pos().x() - prev_x, event->pos().y() - prev_y);

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

            auto min_area_shape = canvas->getShape(x, y);

        if (min_area_shape.has_value()) {

            if (ctrl_pressed) {
                shape_group->Add(min_area_shape.value());
                manipulator->setAttachedShape(shape_group);
            } 
            else {
                manipulator->setAttachedShape(min_area_shape.value());
               
            }
            canvas->deleteShape(manipulator);
            canvas->Add(manipulator);
        } 
        else {
            shape_group->Clear();
            canvas->deleteShape(manipulator);
        }
    }
    std::cout << canvas->getShapesNumber() << std::endl;
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

