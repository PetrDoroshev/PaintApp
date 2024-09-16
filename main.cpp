#include <QApplication>
#include "paint_app.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    paint_app paintApp;
    paintApp.show();

    return QApplication::exec();
}
