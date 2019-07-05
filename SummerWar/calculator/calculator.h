#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
private slots:
    void numbers();
    void on_button_dot_clicked();
    void operations();
    void on_button_clear_clicked();
    void on_button_result_clicked();
    void math_operations();
};

#endif // CALCULATOR_H
