#include <iostream>
#include <QToolBar>
#include <QVBoxLayout>
#include <QDockWidget>
#include "paint_app.h"
#include "shapes/factory/ShapeFactory.h"
#include "shapes/Rectangle.h"
#include "shapes/Triangle.h"
#include "shapes/Ellipse.h"

using namespace shape;

paint_app::paint_app(QWidget *parent): QMainWindow(parent) {

    setGeometry(100, 100, 640, 480);
    //setFocusPolicy(Qt::FocusPolicy::StrongFocus);

    paintSurface = new PaintSurface;
    commandManager = new CommandManager;

    name_tool_map = {{"Rect", new DrawTool<Rectangle>(&paintSurface->canvas, commandManager)},
                     {"Triangle", new DrawTool<Triangle>(&paintSurface->canvas, commandManager)},
                     {"Ellipse", new DrawTool<Ellipse>(&paintSurface->canvas, commandManager)},
                     {"Pointer",  new ManipulatorTool(&paintSurface->canvas, commandManager)}};

    toolbar = addToolBar("main toolbar");

    auto* rectSelect = new QAction("Rect", this);
    auto* triangleSelect = new QAction("Triangle", this);
    auto* ellipseSelect = new QAction("Ellipse", this);
    auto* pointerSelect = new QAction("Pointer", this);

    rectSelect->setCheckable(true);
    triangleSelect->setCheckable(true);
    ellipseSelect->setCheckable(true);
    pointerSelect->setCheckable(true);

    checkedAction = rectSelect;
    rectSelect->setChecked(true);

    paintSurface->current_tool = name_tool_map["Rect"];

    toolbar->addAction(rectSelect);
    toolbar->addAction(triangleSelect);
    toolbar->addAction(ellipseSelect);
    toolbar->addAction(pointerSelect);

    setCentralWidget(paintSurface);

    shape_context_menu = new QMenu(this);
    add_custom_shape_act = new QAction("add_custom_shape_act", this);
    shape_context_menu->addAction(add_custom_shape_act);

    connect(rectSelect, &QAction::triggered, this, &paint_app::setTool);
    connect(triangleSelect, &QAction::triggered, this, &paint_app::setTool);
    connect(ellipseSelect, &QAction::triggered, this, &paint_app::setTool);
    connect(pointerSelect, &QAction::triggered, this, &paint_app::setTool);
    connect(add_custom_shape_act, &QAction::triggered, this, &paint_app::addCustomShape);

}

void paint_app::setTool() {

    auto* action = qobject_cast<QAction*>(sender());
    paintSurface->current_tool = name_tool_map[action->text().toStdString()];


    checkedAction->setChecked(false);
    checkedAction = action;
    action->setChecked(true);

}

void paint_app::addCustomShape() {

    auto manipulator_tool = dynamic_cast<ManipulatorTool*> (paintSurface->current_tool);

    if (manipulator_tool) {

        auto attached_shape = dynamic_cast<const shape::ShapeGroup*>(manipulator_tool->getManipulator());

        if (attached_shape) {

            custom_shape_num++;

            QString label = QString("CustomShape%1").arg(custom_shape_num);
            auto* customShapeSelect = new QAction(label, this);
            customShapeSelect->setCheckable(true);
            toolbar->addAction(customShapeSelect);

            name_tool_map[label.toStdString()] = new DrawTool<ShapeGroup>(&paintSurface->canvas, commandManager, *attached_shape);

            connect(customShapeSelect, &QAction::triggered, this, &paint_app::setTool);
        }
    }
}

void paint_app::contextMenuEvent(QContextMenuEvent *event) {

    if (paintSurface->underMouse()) {
        shape_context_menu->exec(event->globalPos());
    }
}

void paint_app::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key::Key_Z && event->modifiers() == Qt::Modifier::CTRL) {
        commandManager->unExecuteCommand();
        paintSurface->Update();
    }


}

