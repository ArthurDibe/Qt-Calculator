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


void Calculator::displayNumber()
{
    ui->resultLabel->setText(QString::number(this->number));
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


void Calculator::on_button0_clicked()
{
    this->number = 0;
    displayNumber();
    setOrCalculateResult();
}


void Calculator::on_button1_clicked()
{
    this->number = 1;
    displayNumber();
    setOrCalculateResult();
}


void Calculator::on_button2_clicked()
{
    this->number = 2;
    displayNumber();
    setOrCalculateResult();
}


void Calculator::on_button3_clicked()
{
    this->number = 3;
    displayNumber();
    setOrCalculateResult();
}


void Calculator::on_button4_clicked()
{
    this->number = 4;
    displayNumber();
    setOrCalculateResult();
}


void Calculator::on_button5_clicked()
{
    this->number = 5;
    displayNumber();
    setOrCalculateResult();
}


void Calculator::on_button6_clicked()
{
    this->number = 6;
    displayNumber();
    setOrCalculateResult();
}


void Calculator::on_button7_clicked()
{
    this->number = 7;
    displayNumber();
    setOrCalculateResult();
}


void Calculator::on_button8_clicked()
{
    this->number = 8;
    displayNumber();
    setOrCalculateResult();
}


void Calculator::on_button9_clicked()
{
    this->number = 9;
    displayNumber();
    setOrCalculateResult();
}

void Calculator::on_buttonPlus_clicked()
{
    this->operation = Operators::Sum;
    this->hasOperator = true;
}


void Calculator::on_buttonMinus_clicked()
{
    this->operation = Operators::Subtract;
    this->hasOperator = true;
}


void Calculator::on_buttonMultiply_clicked()
{
    this->operation = Operators::Multiply;
    this->hasOperator = true;
}


void Calculator::on_buttonDivide_clicked()
{
    this->operation = Operators::Divide;
    this->hasOperator = true;
}

