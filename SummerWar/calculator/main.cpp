#include "calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.setWindowTitle("Калькулятор");
    w.resize(410,405);
    w.setFixedSize(410,385);
    w.show();

    return a.exec();
}
