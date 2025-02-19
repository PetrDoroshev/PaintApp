#ifndef PAINTAPP_MANIPULATORTOOL_H
#define PAINTAPP_MANIPULATORTOOL_H

#include "Tool.h"
#include "../shapes/Manipulator.h"
#include "../commands/MoveCommand.h"
#include "../commands/ResizeCommand.h"
#include "../shapes/ShapeGroup.h"

class ManipulatorTool: public Tool {
    
private:

    int prev_x = 0;
    int prev_y = 0;
    bool is_click = true;
    bool ctrl_pressed = false;

    std::shared_ptr<shape::Manipulator> manipulator = std::shared_ptr<shape::Manipulator>(new shape::Manipulator(nullptr));
    std::shared_ptr<shape::ShapeGroup> shape_group = std::shared_ptr<shape::ShapeGroup>(new shape::ShapeGroup());

public:

    explicit ManipulatorTool(Canvas* canvas, CommandManager* commandManager);

    void onMousePress(QMouseEvent *event) override;
    void onMouseMove(QMouseEvent *event) override;
    void onMouseRelease(QMouseEvent *event) override;
    void onKeyPress(QKeyEvent *event) override;
    void onKeyRelease(QKeyEvent *event) override;

    const shape::Manipulator* getManipulator() const { return manipulator.get(); } 
};


#endif //PAINTAPP_MANIPULATORTOOL_H
