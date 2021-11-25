#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

enum Operators {None, Sum, Subtract, Multiply, Divide};

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void setEmpty();
    void calculateResult();
    void displayResult();
    void displayNumber();
    void on_buttonEqual_clicked();
    void on_clearButton_clicked();

    bool checkLastForOperator(const std::string obj_string);
    void updateCalculationLabel();
    bool hasOneAndZero();
    void addNumber(char insertNumber);
    void addOperator(Operators opEnum, char opChar);

    void on_button0_clicked();
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_button9_clicked();
    void on_buttonDecimal_clicked();

    void on_buttonPlus_clicked();
    void on_buttonMinus_clicked();
    void on_buttonMultiply_clicked();
    void on_buttonDivide_clicked();
    void on_factorialButton_clicked();

    int factorial(const int n);
private:
    Ui::Calculator *ui;
    double m_result;
    double m_number;
    bool m_hasOperator;
    bool m_isFirstTime;
    Operators m_operation;
    std::string m_numberString;
    std::string m_calculationString;
};
#endif // CALCULATOR_H
