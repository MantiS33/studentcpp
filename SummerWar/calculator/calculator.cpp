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
    connect(ui->button_divide,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->button_mult,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->button_sin,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->button_cos,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->button_tan,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->button_sqr,SIGNAL(clicked()),this,SLOT(operations()));
    ui->button_divide->setCheckable(true);
    ui->button_mult->setCheckable(true);
    ui->button_plus->setCheckable(true);
    ui->button_minus->setCheckable(true);
}

Calculator::~Calculator()
{
    delete ui;
}

/*void Calculator::input(QString str)
{
    //QString text=ui->label
}*/

void Calculator::keyPressEvent(QKeyEvent *event)
{
    int key=event->key();
    QString str=QString(QChar(key));
    if(key==Qt::Key_0)
        ui->button_0->clicked();
    if(key==Qt::Key_1)
        ui->button_1->clicked();
    if(key==Qt::Key_2)
        ui->button_2->clicked();
    if(key==Qt::Key_3)
        ui->button_3->clicked();
    if(key==Qt::Key_4)
        ui->button_4->clicked();
    if(key==Qt::Key_5)
        ui->button_6->clicked();
    if(key==Qt::Key_6)
        ui->button_6->clicked();
    if(key==Qt::Key_7)
        ui->button_7->clicked();
    if(key==Qt::Key_8)
        ui->button_8->clicked();
    if(key==Qt::Key_9)
        ui->button_9->clicked();
    if(key==Qt::Key_Delete)
        ui->button_clear->clicked();
    if(key==Qt::Key_Plus)
        ui->button_plus->clicked();
    if(key==Qt::Key_Minus)
        ui->button_minus->clicked();
    if(key==Qt::Key_Enter)
        ui->button_result->clicked();
    if(key==42)
        ui->button_mult->clicked();
    if(key==47)
        ui->button_divide->clicked();
    if(key==46)
        ui->button_dot->clicked();
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
    if(button==ui->button_sin)
      {
        num=ui->label->text().toDouble();
        num=sin(num);
        str=QString::number(num,'g',10);
        ui->label->setText(str);
      }
    else if(button==ui->button_cos)
      {
        num=ui->label->text().toDouble();
        num=cos(num);
        str=QString::number(num,'g',10);
        ui->label->setText(str);
      }
    else if(button==ui->button_tan)
      {
        num=ui->label->text().toDouble();
        num=tan(num);
        str=QString::number(num,'g',15);
        ui->label->setText(str);
      }
    else if(button==ui->button_sqr)
      {
        num=ui->label->text().toDouble();
        num=num*num;
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
   ui->button_divide->setChecked(false);
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
  else if(ui->button_divide->isChecked())
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
      ui->button_divide->setChecked(false);
    }
}
