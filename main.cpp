#include <QApplication>
#include "paint_app.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QtPaintApp paintApp;
    paintApp.show();

    return QApplication::exec();
}
