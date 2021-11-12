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
    void on_buttonEqual_clicked();
    void on_clearButton_clicked();
    void setOrCalculateResult();
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();

private:
    Ui::Calculator *ui;
    double result;
    double number;
    bool hasOperator;
    Operators operation;

};
#endif // CALCULATOR_H
