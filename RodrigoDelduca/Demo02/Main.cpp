
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.setMinimumSize(QSize(570, 570));
    window.show();
    return app.exec();
}
