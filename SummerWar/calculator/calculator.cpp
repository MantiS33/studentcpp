#include "calculator.h"
#include "ui_calculator.h"

double num_first;

Calculator::Calculator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator)
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
    connect(ui->button_PlusMinus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->button_percent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->button_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->button_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->button_devide,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->button_mult,SIGNAL(clicked()),this,SLOT(math_operations()));
    ui->button_devide->setCheckable(true);
    ui->button_mult->setCheckable(true);
    ui->button_plus->setCheckable(true);
    ui->button_minus->setCheckable(true);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::numbers()
{
    QPushButton *button=(QPushButton*)sender();
    double num;
    QString str;
    if(ui->label->text().contains(".") && button->text()=="0")
    {
        str=ui->label->text()+button->text();
    }
    else
    {
    num=(ui->label->text()+button->text()).toDouble();
    str=QString::number(num,'g',10);
    }
    ui->label->setText(str);
}

void Calculator::on_button_dot_clicked()
{
    if(!(ui->label->text().contains('.')))
    {
        ui->label->setText(ui->label->text()+".");
    }

}

void Calculator::operations()
{
    QPushButton *button=(QPushButton*)sender();
    double num;
    QString str;
    if(button->text()=="+/-")
    {
        num=(ui->label->text()).toDouble();
        num=num*(-1);
        str=QString::number(num,'g',10);
        ui->label->setText(str);
    }
    else if(button->text()=="%")
      {
          num=(ui->label->text()).toDouble();
          num=num*0.01;
          str=QString::number(num,'g',10);
          ui->label->setText(str);
      }
}

void Calculator::math_operations()
{
  QPushButton *button=(QPushButton*)sender();
  num_first=ui->label->text().toDouble();
  ui->label->setText("0");
  button->setChecked(true);

}

void Calculator::on_button_clear_clicked()
{
   ui->button_plus->setChecked(false);
   ui->button_minus->setChecked(false);
   ui->button_mult->setChecked(false);
   ui->button_devide->setChecked(false);
   ui->label->setText("0");
}

void Calculator::on_button_result_clicked()
{
  double result,num_second;
  QString str;
  num_second=ui->label->text().toDouble();
  if(ui->button_plus->isChecked())
    {
      result=num_first+num_second;
      str=QString::number(result,'g',10);
      ui->label->setText(str);
      ui->button_plus->setChecked(false);
    }
  else if(ui->button_minus->isChecked())
    {
      result=num_first-num_second;
      str=QString::number(result,'g',10);
      ui->label->setText(str);
      ui->button_minus->setChecked(false);
    }
  else if(ui->button_mult->isChecked())
    {
      result=num_first*num_second;
      str=QString::number(result,'g',10);
      ui->label->setText(str);
      ui->button_mult->setChecked(false);
    }
  else if(ui->button_devide->isChecked())
    {
      if(num_second==0.0)
        {
          ui->label->setText("ERROR");
        }
      else
        {
          result=num_first/num_second;
          str=QString::number(result,'g',10);
          ui->label->setText(str);
        }
      ui->button_devide->setChecked(false);
    }
}
