#include "calculator.h"
#include "ui_calculator.h"


Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    this->result = 0;

    ui->setupUi(this);
    ui->resultLabel->setText(QString::number(this->result));
    this->setFixedSize(350,391); // set fixed size
}


Calculator::~Calculator()
{
    delete ui;
}


void Calculator::setEmpty()
{
    this->result = 0;
    this->number = 0;
    this->operation = Operators::None;
    this->hasOperator = false;
}


void Calculator::calculateResult()
{
    switch(this->operation)
    {
    case Operators::Sum:
        this->result += this->number;
        break;

    case Operators::Subtract:
        this->result -= this->number;
        break;

    case Operators::Multiply:
        this->result *= this->number;
        break;

    case Operators::Divide:
        this->result /= this->number;
        break;

    default:
        this->result = 0;
    }
}


void Calculator::displayResult()
{
    ui->resultLabel->setText(QString::number(this->result));
}


void Calculator::on_buttonEqual_clicked()
{
    displayResult();
    setEmpty(); // after calculating and displaying, reset data members
}


void Calculator::on_clearButton_clicked()
{
    this->setEmpty();
    ui->resultLabel->setText(QString::number(this->result));
}

void Calculator::setOrCalculateResult()
{
    if(!this->hasOperator)
        this->result = this->number;
    else
        this->calculateResult();
}


void Calculator::on_button1_clicked()
{
    this->number = 1;
    setOrCalculateResult();
}


void Calculator::on_button2_clicked()
{
    this->number = 2;
    setOrCalculateResult();
}


void Calculator::on_button3_clicked()
{
    this->number = 3;
    setOrCalculateResult();
}


void Calculator::on_button4_clicked()
{
    this->number = 4;
    setOrCalculateResult();
}

