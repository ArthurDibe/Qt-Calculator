#include<iostream>
#include <climits> // UINT_MAX
#include "calculator.h"
#include "ui_calculator.h"

// one parameter constructor to instantiate the mainWindow and set it up
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    setEmpty();
    ui->setupUi(this);
    ui->resultLabel->setText(QString::number(m_result));
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
    m_result = 0;
    m_number = 0;
    m_operation = Operators::None;
    m_hasOperator = false;
    m_numberString = "";
    m_calculationString = "";
    m_isFirstTime = true;
}

// function to calculate the result based on the operation selected
void Calculator::calculateResult()
{
    switch(m_operation)
    {
    case Operators::Sum:
        if(m_isFirstTime) m_result = m_number;
        else    m_result += std::stod(m_numberString);
        break;

    case Operators::Subtract:
        if(m_isFirstTime) m_result = m_number;
        else    m_result -= std::stod(m_numberString);
        break;

    case Operators::Multiply:
        if(m_isFirstTime) m_result = m_number;
        else    m_result *= std::stod(m_numberString);
        break;

    case Operators::Divide:
        if(m_isFirstTime) m_result = m_number;
        else    m_result /= std::stod(m_numberString);
        break;

    case Operators::None:
        break;
    }

    m_isFirstTime = false;
}

// display the result data member on the calculator screen
void Calculator::displayResult()
{
    ui->resultLabel->setText(QString::number(m_result));
}

// display the number data member on the calculator screen
void Calculator::displayNumber()
{
    ui->resultLabel->setText(QString::fromStdString(m_numberString));
}

// display the result of the calculation and then set all the data members to empty state
void Calculator::on_buttonEqual_clicked()
{
    if(std::isdigit(m_calculationString.back())){
        m_calculationString += '=';
        displayResult();
        updateCalculationLabel();
        calculateResult();
        displayResult();
        setEmpty(); // after calculating and displaying, reset data members
    }
}

// handle the clear button "CE"
void Calculator::on_clearButton_clicked()
{
    setEmpty();
    displayResult();
    updateCalculationLabel();
}

// Check if a string has an operator as a last character
// returns true if the last character is an operator
// false otherwise
bool Calculator::checkLastForOperator(const std::string obj_string)
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

// Update the calculation label
void Calculator::updateCalculationLabel()
{
    ui->calculationLabel->setText(QString::fromStdString(m_calculationString));
}

// This function was created to check if we need to replace the zero character (in case it is the first one)
// returns true if the numberString is one length long and it has the character zero
// false otherwise
bool Calculator::hasOneAndZero()
{
    return (m_numberString.length() == 1) && (m_numberString.back() == '0');
}

void Calculator::addNumber(char numberChosen)
{
    bool isOk = true;

    if(numberChosen == '.')
    {
        if(m_numberString.find_first_of('.') == std::string::npos)
            m_numberString += numberChosen;
        else
            isOk = false;
    }
    else {
        if(hasOneAndZero())
            m_numberString.back() = numberChosen; // check if it is needed to replace the zero character
        else
            m_numberString += numberChosen;
    }

    if(isOk) {
        m_calculationString += numberChosen;
        updateCalculationLabel();
        displayNumber();
    }

}

void Calculator::addOperator(Operators opEnum, char opChar)
{
    m_operation = opEnum;
    m_hasOperator = true;

    if(checkLastForOperator(m_calculationString)){ // check if the operator should be replaced with another one or not
        m_calculationString.back() = opChar;
    }
    else{
        m_calculationString += opChar;
    }

    m_number = std::stod(m_numberString); // convert the numberSTring into double
    m_numberString = "";                  // restart numberString
    calculateResult();                    // update the result variable so far

    updateCalculationLabel();
}

// handle the button 0
void Calculator::on_button0_clicked(){ addNumber('0'); }

// handle the button 1
void Calculator::on_button1_clicked(){ addNumber('1'); }

// handle the button 2
void Calculator::on_button2_clicked(){ addNumber('2'); }

// handle the button 3
void Calculator::on_button3_clicked(){ addNumber('3'); }

// handle the button 4
void Calculator::on_button4_clicked(){ addNumber('4'); }

// handle the button 5
void Calculator::on_button5_clicked(){ addNumber('5'); }

// handle the button 6
void Calculator::on_button6_clicked(){ addNumber('6'); }

// handle the button 7
void Calculator::on_button7_clicked(){ addNumber('7'); }

// handle the button 8
void Calculator::on_button8_clicked(){ addNumber('8'); }

// handle the button 9
void Calculator::on_button9_clicked(){ addNumber('9'); }

// handle the button .
void Calculator::on_buttonDecimal_clicked(){ addNumber('.'); }

// handle the button "+"
void Calculator::on_buttonPlus_clicked(){ addOperator(Operators::Sum, '+'); }

// handle the button "-"
void Calculator::on_buttonMinus_clicked(){ addOperator(Operators::Subtract, '-'); }

// handle the button "*"
void Calculator::on_buttonMultiply_clicked(){ addOperator(Operators::Multiply, 'x'); }

// handle the button "/"
void Calculator::on_buttonDivide_clicked(){ addOperator(Operators::Divide, '/'); }



void Calculator::on_factorialButton_clicked()
{
    m_calculationString += '!';
    updateCalculationLabel();

    try{
        m_result = factorial(std::stoi(m_numberString));
        if(m_result <= 0) throw "ERROR";
        m_numberString = std::to_string((unsigned)m_result);
        m_calculationString = m_numberString;
    }
    catch(const char* msg){
        m_calculationString = msg;
        m_numberString = msg;
        updateCalculationLabel();
        m_result = 0;
        std::cout << msg << std::endl;
    }

    displayResult();
}

int Calculator::factorial(const int n){
    int result = 1;
    if(n > 1){
        result *= n * factorial(n-1);
    }
    return result;
}

