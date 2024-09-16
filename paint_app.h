#include <QMainWindow>
#include <QApplication>
#include <QMenu>
#include "paint_surface.h"
#include "tools/Tool.h"
#include "tools/DrawTool.h"
#include "tools/DrawTool.cpp"
#include "tools/ManipulatorTool.h"
#include "shapes/factory/Factory.h"
#include "shapes/factory/ShapeFactory.h"
#include "shapes/factory/PrototypeShapeFactory.h"
#include "commands/CommandManager.h"


class paint_app: public QMainWindow {

    Q_OBJECT;

public:
    explicit paint_app(QWidget* parent = nullptr);

private:

    int custom_shape_num = 0;

    PaintSurface* paintSurface;
    CommandManager* commandManager;
    std::unordered_map<std::string, Tool*> name_tool_map;

    QToolBar *toolbar;
    QMenu* shape_context_menu;
    QAction* checkedAction;
    QAction* add_custom_shape_act;

private slots:
    void setTool();
    void addCustomShape();

protected:
    void contextMenuEvent(QContextMenuEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

};