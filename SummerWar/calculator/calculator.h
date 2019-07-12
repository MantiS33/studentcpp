#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QKeyEvent>
#include <Qt>
#include <QtMath>
#include <QPushButton>

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
    void error();
    double nsqrt(double operand,double exp);

private:
    Ui::Calculator *ui;
    double num_first;
    double temp_result;
    double Result;
    bool waitingForOperand;
    QPushButton *additiveOperator;
    QPushButton *multiplicativeOperator;
    /*QString additiveOperator;
    QString multiplicativeOperator;*/

protected:
    virtual void keyPressEvent(QKeyEvent *event);
private slots:
    void multiplicativeOperatorClicked();
    void additiveOperatorClicked();
    bool calculate(double right_operand,const QPushButton* button);
    void numbers();
    void on_button_dot_clicked();
    void operations();
    void on_button_clear_clicked();
    void on_button_result_clicked();
    void math_operations();
    void on_button_del_clicked();
};

#endif // CALCULATOR_H
