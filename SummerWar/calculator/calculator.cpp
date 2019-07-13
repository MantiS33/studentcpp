#include "calculator.h"
#include "ui_calculator.h"


Calculator::Calculator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator)
{
    ui->setupUi(this);
    temp_result=0.0;
    Result=0.0;
    waitingForOperand=true;
    multiplicativeOperator=nullptr;
    additiveOperator=nullptr;
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
  connect(ui->button_plus,SIGNAL(clicked()),this,SLOT(additiveOperatorClicked()));
  connect(ui->button_minus,SIGNAL(clicked()),this,SLOT(additiveOperatorClicked()));
  connect(ui->button_divide,SIGNAL(clicked()),this,SLOT(multiplicativeOperatorClicked()));
  connect(ui->button_mult,SIGNAL(clicked()),this,SLOT(multiplicativeOperatorClicked()));
  connect(ui->button_sin,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_cos,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_tan,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_sqr,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_sqrt,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_n,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_nsqr,SIGNAL(clicked()),this,SLOT(multiplicativeOperatorClicked()));
  connect(ui->button_e,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_ln,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_pi,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_log,SIGNAL(clicked()),this,SLOT(operations()));
  connect(ui->button_nsqrt,SIGNAL(clicked()),this,SLOT(multiplicativeOperatorClicked()));
  ui->radioButton_Deg->setChecked(true);
  //ui->button_nsqr->setCheckable(true);
  //ui->button_nsqrt->setCheckable(true);
  //ui->button_divide->setCheckable(true);
  //ui->button_mult->setCheckable(true);
  //ui->button_plus->setCheckable(true);
  //ui->button_minus->setCheckable(true);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::additiveOperatorClicked()
{
  QPushButton *button=qobject_cast<QPushButton*>(sender());
  double num=ui->label->text().toDouble();

  if(multiplicativeOperator!=nullptr)
    {
      if(!calculate(num,multiplicativeOperator))
        {
          error();
          return;
        }
      ui->label->setText(QString::number(temp_result,'g',15));
      num=temp_result;
      temp_result=0.0;
      multiplicativeOperator=nullptr;
    }

  if(additiveOperator!=nullptr)
    {
      if(!calculate(num,additiveOperator))
        {
          error();
          return;
        }
      ui->label->setText(QString::number(Result,'g',15));
    }
  else
    {
      Result=num;
    }
  additiveOperator=button;

  waitingForOperand = true;
}

void Calculator::multiplicativeOperatorClicked()
{
  QPushButton *button=qobject_cast<QPushButton*>(sender());
  double num=ui->label->text().toDouble();

  if(multiplicativeOperator!=nullptr)
    {
      if(!calculate(num,multiplicativeOperator))
        {
          error();
          return;
        }
      ui->label->setText(QString::number(temp_result,'g',15));
    }
  else
    {
      temp_result = num;
    }
  multiplicativeOperator = button;
  waitingForOperand = true;
}


bool Calculator::calculate(double right_operand,const QPushButton *button)
{
  if(button == ui->button_plus)
    {
      Result = Result + right_operand;
    }
  else if(button == ui->button_minus)
    {
      Result = Result - right_operand;
    }
  else if(button == ui->button_mult)
    {
      temp_result = temp_result * right_operand;
    }
  else if(button == ui->button_divide)
    {
      if(right_operand == 0.0)
        return false;
      else
        {
          temp_result = temp_result / right_operand;
        }
    }
  else if(button == ui->button_nsqr)
    {
      temp_result = pow(temp_result,right_operand);
    }
  else if(button == ui->button_nsqrt)
    {
      temp_result = nsqrt(temp_result,right_operand);
    }
  return true;
}

void Calculator::error()
{
  on_button_clear_clicked();
  ui->label->setText("ERROR");
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
    else if(key==Qt::Key_Backspace)
      ui->button_del->clicked();
}

void Calculator::numbers()
{
    QPushButton *button=qobject_cast<QPushButton *>(sender());
    double num;
    QString str;
    if(waitingForOperand)
      {
        //ui->label->setText("0");
        ui->label->clear();
        waitingForOperand=false;
      }
    if(ui->label->text().contains(".") && button->text()=="0")
    {
        if(ui->label->text().length()<20)
          {
            str=ui->label->text()+button->text();
          }
        else
          {
            str=ui->label->text();
          }
    }
    else
    {
    num=(ui->label->text()+button->text()).toDouble();
    str=QString::number(num,'g',20);
    }
    ui->label->setText(str);
    //waitingForOperand=false;
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
    QPushButton *button=qobject_cast<QPushButton *>(sender());
    double num;
    QString str;
    num=ui->label->text().toDouble();
    if(button==ui->button_PlusMinus)
    {
        num=num*(-1);
    }
    else if(button==ui->button_percent)
      {
          num=num*0.01;
      }
    else if(button==ui->button_sin)
      {
        if(ui->radioButton_Deg->isChecked())
          {
            num=sin(num*3.14159265359 / 180.0);
          }
        else
          {
            num=sin(num);
          }
      }
    else if(button==ui->button_cos)
      {
        if(ui->radioButton_Deg->isChecked())
          {
            num=cos(num*3.14159265359 / 180);
          }
        else
          {
            num=cos(num);
          }
      }
    else if(button==ui->button_tan)
      {
        if(ui->radioButton_Deg->isChecked())
          {
            num=tan(num*3.14159265359 / 180.0);
          }
        else
          {
            num=tan(num);
          }
      }
    else if(button==ui->button_sqr)
      {
        num=num*num;
      }
    else if(button==ui->button_pi)
      {
        num=3.1415926535897932;
      }
    else if(button==ui->button_n)
      {
        num=fact(num);
      }
    else if(button==ui->button_sqrt)
      {
        if(num>=0)
          {
            num=sqrt(num);
          }
        else
          {
            error();
            return;
          }
      }
    else if(button==ui->button_e)
      {
        num=2.7182818284590;
      }
    else if(button==ui->button_ln)
      {
        num=log(num);
      }
    else if(button==ui->button_log)
      {
        num=log10(num);
      }
    waitingForOperand=false;
    str=QString::number(num,'g',20);
    ui->label->setText(str);
}

void Calculator::math_operations()
{
  QPushButton *button=qobject_cast<QPushButton *>(sender());
  QString buttonClicked=button->text();
  num_first=ui->label->text().toDouble();
  ui->label->setText("0");
  button->setChecked(true);
  waitingForOperand=true;
}

void Calculator::on_button_clear_clicked()
{
   Result=0.0;
   temp_result=0.0;
   waitingForOperand=true;
   multiplicativeOperator=nullptr;
   additiveOperator=nullptr;
   ui->button_plus->setChecked(false);
   ui->button_minus->setChecked(false);
   ui->button_mult->setChecked(false);
   ui->button_divide->setChecked(false);
   ui->label->setText("0");
}

void Calculator::on_button_result_clicked()
{
  /*double result,num_second;
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
  */
 double operand=ui->label->text().toDouble();

 if(multiplicativeOperator!=nullptr)
   {
     if(!calculate(operand,multiplicativeOperator))
       {
         error();
         return;
       }
     operand=temp_result;
     temp_result=0.0;
     multiplicativeOperator=nullptr;
   }
 if(additiveOperator!=nullptr)
   {
     if(!calculate(operand,additiveOperator))
       {
         error();
         return;
       }
     additiveOperator=nullptr;
   }
 else
   {
     Result=operand;
   }
 ui->label->setText(QString::number(Result,'g',15));
 Result=0.0;

  waitingForOperand=true;
}

void Calculator::on_button_del_clicked()
{
  QString str=ui->label->text();
  str.resize(str.size()-1);
  if(str.length()==0)
    {
      str="0";

    }
  ui->label->setText(str);
}

double Calculator::nsqrt(double operand,double exp)
{
  if (static_cast<int>(exp) == exp)
    {
      if (!(static_cast<int>(exp) & 1))
        {
          if (abs(operand) == operand)
            {
              operand = pow(operand, 1 / operand);
            }
          else
            {
              error();
              return 0.0;
            }
        }
      else
        {
          if (abs(operand) == operand)
            {
              operand=pow(operand, 1 / exp);
            }
          else
            {
              operand=pow(abs(operand), 1 / exp) * (-1);
            }
        }
    }
  else
    {
      if (abs(operand) == operand)
        {
          operand=pow(operand, 1 / exp);
        }
      else
        {
          operand=pow(abs(operand), 1 / exp) * (-1);
        }
    }
  return operand;
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

