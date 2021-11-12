#include "calculator.h"
#include "ui_calculator.h"

// one parameter constructor to instantiate the mainWindow and set it up
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    this->result = 0;

    ui->setupUi(this);
    ui->resultLabel->setText(QString::number(this->result));
    this->setFixedSize(350,391); // set fixed size
}

// destructor
Calculator::~Calculator()
{
    delete ui;
}

// Set Data members to empty state
void Calculator::setEmpty()
{
    this->result = 0;
    this->number = 0;
    this->operation = Operators::None;
    this->hasOperator = false;
    this->numberString = "";
    this->calculationString = "";
}

// function to calculate the result based on the operation selected
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

// display the result data member on the calculator screen
void Calculator::displayResult()
{
    ui->resultLabel->setText(QString::number(this->result));
}

// display the number data member on the calculator screen
void Calculator::displayNumber()
{
    ui->resultLabel->setText(QString::number(this->number));
}

// display the result of the calculation and then set all the data members to empty state
void Calculator::on_buttonEqual_clicked()
{
    displayResult();
    setEmpty(); // after calculating and displaying, reset data members
}

// handle the clear button "CE"
void Calculator::on_clearButton_clicked()
{
    this->setEmpty();
    ui->resultLabel->setText(QString::number(this->result));
}

// check if an operator was selected before calculating the result
// otherwise set the result to the value of the current number
void Calculator::setOrCalculateResult()
{
    if(this->hasOperator)
        this->calculateResult();
    else
        this->result = this->number;
}

// Check if a string has an operator as a last character
// returns true if the last character is an operator
// false otherwise
bool Calculator::checkLastCharacter(const std::string obj_string)
{
    bool found = false;
    switch(obj_string.back())
    {
    case '+':
        found = true;
        break;
    case '-':
        found = true;
        break;
    case 'x':
        found = true;
        break;
    case '/':
        found = true;
        break;
    }

    return found;
}

// handle the button 0
void Calculator::on_button0_clicked()
{
    this->number = 0;
    this->calculationString += "0";
    displayNumber();
    setOrCalculateResult();
}

// handle the button 1
void Calculator::on_button1_clicked()
{
    this->number = 1;
    this->calculationString += "1";
    displayNumber();
    setOrCalculateResult();
}

// handle the button 2
void Calculator::on_button2_clicked()
{
    this->number = 2;
    this->calculationString += "2";
    displayNumber();
    setOrCalculateResult();
}

// handle the button 3
void Calculator::on_button3_clicked()
{
    this->number = 3;
    this->calculationString += "3";
    displayNumber();
    setOrCalculateResult();
}

// handle the button 4
void Calculator::on_button4_clicked()
{
    this->number = 4;
    this->calculationString += "4";
    displayNumber();
    setOrCalculateResult();
}

// handle the button 5
void Calculator::on_button5_clicked()
{
    this->number = 5;
    this->calculationString += "5";
    displayNumber();
    setOrCalculateResult();
}

// handle the button 6
void Calculator::on_button6_clicked()
{
    this->number = 6;
    this->calculationString += "6";
    displayNumber();
    setOrCalculateResult();
}

// handle the button 7
void Calculator::on_button7_clicked()
{
    this->number = 7;
    this->calculationString += "7";
    displayNumber();
    setOrCalculateResult();
}

// handle the button 8
void Calculator::on_button8_clicked()
{
    this->number = 8;
    this->calculationString += "8";
    displayNumber();
    setOrCalculateResult();
}

// handle the button 9
void Calculator::on_button9_clicked()
{
    this->number = 9;
    this->calculationString += "9";
    displayNumber();
    setOrCalculateResult();
}

// handle the button "+"
void Calculator::on_buttonPlus_clicked()
{
    this->operation = Operators::Sum;
    this->hasOperator = true;
}

// handle the button "-"
void Calculator::on_buttonMinus_clicked()
{
    this->operation = Operators::Subtract;
    this->hasOperator = true;
}

// handle the button "*"
void Calculator::on_buttonMultiply_clicked()
{
    this->operation = Operators::Multiply;
    this->hasOperator = true;
}

// handle the button "/"
void Calculator::on_buttonDivide_clicked()
{
    this->operation = Operators::Divide;
    this->hasOperator = true;
}

