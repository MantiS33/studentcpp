#include "calculator.h"
#include "ui_calculator.h"

double num_first;

Calculator::Calculator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator)
{
    ui->setupUi(this);
    buttons();
}


double fact(double number);


void Calculator::buttons()
{
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
  connect(ui->button_sqrt,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_n,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_nsqr,SIGNAL(clicked()),this,SLOT(math_operations()));
  connect(ui->button_e,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_ln,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_pi,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_log,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_nsqrt,SIGNAL(clicked()),this,SLOT(math_operations()));
  ui->button_nsqr->setCheckable(true);
  ui->button_nsqrt->setCheckable(true);
  ui->button_divide->setCheckable(true);
  ui->button_mult->setCheckable(true);
  ui->button_plus->setCheckable(true);
  ui->button_minus->setCheckable(true);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::keyPressEvent(QKeyEvent *event)
{
    int key=event->key();
    QString str=QString(QChar(key));
    if(key==Qt::Key_0)
        ui->button_0->clicked();
    else if(key==Qt::Key_1)
        ui->button_1->clicked();
    else if(key==Qt::Key_2)
        ui->button_2->clicked();
    else if(key==Qt::Key_3)
        ui->button_3->clicked();
    else if(key==Qt::Key_4)
        ui->button_4->clicked();
    else if(key==Qt::Key_5)
        ui->button_6->clicked();
    else if(key==Qt::Key_6)
        ui->button_6->clicked();
    else if(key==Qt::Key_7)
        ui->button_7->clicked();
    else if(key==Qt::Key_8)
        ui->button_8->clicked();
    else if(key==Qt::Key_9)
        ui->button_9->clicked();
    else if(key==Qt::Key_Delete)
        ui->button_clear->clicked();
    else if(key==Qt::Key_Plus)
        ui->button_plus->clicked();
    else if(key==Qt::Key_Minus)
        ui->button_minus->clicked();
    else if(key==Qt::Key_Enter)
        ui->button_result->clicked();
    else if(key==42)
        ui->button_mult->clicked();
    else if(key==47)
        ui->button_divide->clicked();
    else if(key==46)
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
    str=QString::number(num,'g',15);
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
    if(button==ui->button_PlusMinus)
    {
        num=(ui->label->text()).toDouble();
        num=num*(-1);
        str=QString::number(num,'g',15);
        ui->label->setText(str);
    }
    else if(button==ui->button_percent)
      {
          num=(ui->label->text()).toDouble();
          num=num*0.01;
          str=QString::number(num,'g',15);
          ui->label->setText(str);
      }
    if(button==ui->button_sin)
      {
        num=ui->label->text().toDouble();
        num=sin(num);
        str=QString::number(num,'g',15);
        ui->label->setText(str);
      }
    else if(button==ui->button_cos)
      {
        num=ui->label->text().toDouble();
        num=cos(num);
        str=QString::number(num,'g',15);
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
        str=QString::number(num,'g',15);
        ui->label->setText(str);
      }
    else if(button==ui->button_pi)
      {
        num=3.1415926535897932;
        str=QString::number(num,'g',18);
        ui->label->setText(str);
      }
    else if(button==ui->button_n)
      {
        num=ui->label->text().toDouble();
        num=fact(num);
        str=QString::number(num,'g',15);
        ui->label->setText(str);
      }
    else if(button==ui->button_sqrt)
      {
        num=ui->label->text().toDouble();
        if(num>=0)
          {
            num=sqrt(num);
            str=QString::number(num,'g',15);
            ui->label->setText(str);
          }
        else
          {
            ui->label->setText("ERROR");
          }
      }
    else if(button==ui->button_e)
      {
        num=2.7182818284590;
        str=QString::number(num,'g',18);
        ui->label->setText(str);
      }
    else if(button==ui->button_ln)
      {
        num=ui->label->text().toDouble();
        num=log(num);
        str=QString::number(num,'g',15);
        ui->label->setText(str);
      }
    else if(button==ui->button_log)
      {
        num=ui->label->text().toDouble();
        num=log10(num);
        str=QString::number(num,'g',15);
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
  else if(ui->button_nsqr->isChecked())
    {
      result=pow(num_first,num_second);
      str=QString::number(result,'g',15);
      ui->label->setText(str);
      ui->button_nsqr->setChecked(false);
    }
  else if(ui->button_nsqrt->isChecked())
    {
      if (static_cast<int>(num_second) == num_second)
        {
          if (!(static_cast<int>(num_second) & 1))
            {
              if (abs(num_first) == num_first)
                {
                  result= pow(num_first, 1 / num_second);
                  str=QString::number(result,'g',15);
                  ui->label->setText(str);
                }
              else
                {
                  str = "ERROR";
                  ui->label->setText(str);
                }
            }
          else
            {
              if (abs(num_first) == num_first)
                {
                  result=pow(num_first, 1 / num_second);
                  str=QString::number(result,'g',15);
                  ui->label->setText(str);
                }
              else
                {
                  result=pow(abs(num_first), 1 / num_second) * (-1);
                  str=QString::number(result,'g',15);
                  ui->label->setText(str);
                }
            }
        }
      else
        {
          if (abs(num_first) == num_first)
            {
              result=pow(num_first, 1 / num_second);
              str=QString::number(result,'g',15);
              ui->label->setText(str);
            }
          else
            {
              result=pow(abs(num_first), 1 / num_second) * (-1);
              str=QString::number(result,'g',15);
              ui->label->setText(str);
            }
        }
      ui->button_nsqrt->setChecked(false);
    }

}

double fact(double number)
{
  if(number<0)
    return 0;
  if(number==0.0)
    return 1;
  else
    return number*fact(number-1);
}
