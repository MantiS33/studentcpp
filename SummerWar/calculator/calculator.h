#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QKeyEvent>
#include <Qt>
#include <QtMath>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();
    void buttons();

private:
    Ui::Calculator *ui;
protected:
    virtual void keyPressEvent(QKeyEvent *event);
private slots:
    void numbers();
    void on_button_dot_clicked();
    void operations();
    void on_button_clear_clicked();
    void on_button_result_clicked();
    void math_operations();
};

#endif // CALCULATOR_H
