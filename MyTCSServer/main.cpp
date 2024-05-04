#include "myserverwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyServerWidget w;
    w.show();
    return a.exec();
}
