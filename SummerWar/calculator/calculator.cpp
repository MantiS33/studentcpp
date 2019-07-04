#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->button_0,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_1,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_2,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_3,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_4,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_5,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_6,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_7,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_8,SIGNAL(clicked()),this,SLOT(numbers()));
    connect(ui->button_9,SIGNAL(clicked()),this,SLOT(numbers()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::numbers()
{
    QPushButton *button = (QPushButton *)sender();
    double num,temp;
    temp=(ui->label->text()).toDouble();
    if(abs(temp) / 10 >= 0)
    {
        num=(temp * 10)+(button->text()).toDouble();
    }
    else
    {
        num=temp;
    }
    //num=(ui->label->text()+button->text()).toDouble();
    ui->label->setText(QString::number(num,'g',10));
}
