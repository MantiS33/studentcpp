#include "calculator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.setWindowTitle("Калькулятор");
    w.resize(208,335);
    w.setFixedSize(208,335);
    w.show();

    return a.exec();
}
