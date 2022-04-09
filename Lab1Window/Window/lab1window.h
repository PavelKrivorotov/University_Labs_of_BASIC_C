#ifndef LAB1WINDOW_H
#define LAB1WINDOW_H

#include <iostream>
#include "Lab1Window/MathModule/math_funcs.h"

using namespace std;


#include <QWidget>
#include <QString>

#define MAXIMUM_INPUT_SYMBOLS   100


namespace Ui {
class Lab1Window;
}

class Lab1Window : public QWidget
{
    Q_OBJECT

public:
    explicit Lab1Window(QWidget *parent = nullptr);
    ~Lab1Window();

    string input_arr[MAXIMUM_INPUT_SYMBOLS];
    int index = 0;

signals:
    void rootWindow();

private slots:
    void set_index(int new_index);

    void set_input_arr(string string_arr[], string value);

    void clear_input_arr(string string_arr[]);

    QString create_LInput_string(const string input_arr[]);

    void clear_LInput(string input_arr[]);

    void update_LInput(string input_arr[], string value);

    int get_count_of_elem_in_arr(const string arr[]);


    void on_pBtnMenue_clicked();

    void on_pBtnNumberOne_clicked();

    void on_pBtnManagerClear_clicked();

    void on_pBtnManagerDeleteLast_clicked();

    void on_pBtnManagerCalculate_clicked();

    void on_pBtnMathOperatorPlus_clicked();

    void on_pBtnMathOperatorMinus_clicked();

    void on_pBtnMathOperatorMultiply_clicked();

    void on_pBtnMathOperatorDivide_clicked();

    void on_pBtnMathOperatorPower_clicked();

    void on_pBtnMathFunctionsSin_clicked();

    void on_pBtnMathFunctionsCos_clicked();

    void on_pBtnMathFunctionsTan_clicked();

    void on_pBtnMathFunctionsCtg_clicked();

    void on_pBtnMathFunctionsExp_clicked();

    void on_pBtnMathFunctionsLog_clicked();

    void on_pBtnManagerOpenBracket_clicked();

    void on_pBtnManagerCloseBracket_clicked();

    void on_pBtnMathOperatorDecimalPoint_clicked();

    void on_pBtnNumberTwo_clicked();

    void on_pBtnNumberThree_clicked();

    void on_pBtnNumberFour_clicked();

    void on_pBtnNumberFive_clicked();

    void on_pBtnNumberSix_clicked();

    void on_pBtnNumberSeven_clicked();

    void on_pBtnNumberEight_clicked();

    void on_pBtnNumberNine_clicked();

    void on_pBtnNumberZero_clicked();

    void on_pBtnConstant_pi_clicked();

    void on_pBtConstant_e_clicked();

    void on_pBtnVariableX_clicked();

private:
    Ui::Lab1Window *ui;
};

#endif // LAB1WINDOW_H
