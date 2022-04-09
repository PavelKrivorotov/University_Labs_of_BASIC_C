#include "lab1window.h"
#include "ui_lab1window.h"

//#include "Lab1Window/MathModule/math_funcs.h"


// Create array of math input

//static int index = 0;
//string input_arr[MAXIMUM_INPUT_SYMBOLS];

double x_val = 0;

Lab1Window::Lab1Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lab1Window)
{
    ui->setupUi(this);
}

Lab1Window::~Lab1Window()
{
    delete ui;
}


// Functions of Root Window

void Lab1Window::on_pBtnMenue_clicked()
{
    emit rootWindow();
    this->close();
}


// ...

//void Lab1Window::set_index(int &index, int count) {
//    index = index + count;
void Lab1Window::set_index(int new_index) {
    index = new_index;
}


//void Lab1Window::set_input_arr(string string_arr[], int index, string value) {
void Lab1Window::set_input_arr(string string_arr[], string value) {
    string_arr[index] = value;
}


// ...

void Lab1Window::clear_input_arr(string string_arr[]) {
    int ind = 0;

//    while (string_arr[ind] != "!" && ind < MAXIMUM_INPUT_SYMBOLS) {
    while (ind < MAXIMUM_INPUT_SYMBOLS) {
        string_arr[ind] = "";

        ind++;
    }
}


// ...

QString Lab1Window::create_LInput_string(const string input_arr[]) {
    QString str = "";

    for (int ind = 0; ind < MAXIMUM_INPUT_SYMBOLS; ind++) {
        str = str + QString::fromStdString(input_arr[ind]);
    }

    return str;
}


//void Lab1Window::clear_LInput(string input_arr[], int &index) {
//    set_index(index, -index);
void Lab1Window::clear_LInput(string input_arr[]) {
    set_index(0);
    clear_input_arr(input_arr);

    ui->LInput->setText("Enter math expression...");
}


//void Lab1Window::update_LInput(string input_arr[], int &index, string value) {
//    set_input_arr(input_arr, index, value);
//    set_index(index, 1);
void Lab1Window::update_LInput(string input_arr[], string value) {
    set_input_arr(input_arr, value);
    set_index(index + 1);

    QString qvalue = create_LInput_string(input_arr);

    ui->LInput->setText(qvalue);
}


int Lab1Window::get_count_of_elem_in_arr(const string arr[]) {
    for (int ind = 0; ind < MAXIMUM_INPUT_SYMBOLS; ind++) {
        if (arr[ind] == "!") {
            return ind;
        }
    }

    return -1;
}


// Functions of Manager buttons

void Lab1Window::on_pBtnManagerClear_clicked()
{
    if (index > 0) {
//        clear_LInput(input_arr, index);
        clear_LInput(input_arr);
    }
}


void Lab1Window::on_pBtnManagerDeleteLast_clicked()
{
    if (index > 0) {
//        set_index(index, -1);
//        set_input_arr(input_arr, index, "");
        set_index(index - 1);
        set_input_arr(input_arr, "");
    }

    if (! index) {
        ui->LInput->setText("Enter math expression...");
    }

    else {
        QString qstr = create_LInput_string(input_arr);

        ui->LInput->setText(qstr);
    }
}


void Lab1Window::on_pBtnManagerCalculate_clicked()
{   
    if (index > 0) {
//        set_input_arr(input_arr, index, "!");
//        set_index(index, 1);
        set_input_arr(input_arr, "!");
        set_index(index + 1);

        string change_arr[MAXIMUM_INPUT_SYMBOLS * 2];
        change_input_arr(input_arr, change_arr);

        int count_elem = get_count_of_elem_in_arr(change_arr);

        string new_arr[count_elem];
        set_math_string(change_arr, new_arr, 0, count_elem);

        math_tree_knot math_tree[count_elem];
        create_tree(math_tree, count_elem, new_arr, count_elem, 0);

        double answer = math_parser(math_tree, count_elem, 0);

        ui->LOutput->setText(QString::number(answer));

//        clear_LInput(input_arr, index);
        clear_LInput(input_arr);
    }
}


void Lab1Window::on_pBtnManagerOpenBracket_clicked()
{
//    update_LInput(input_arr, index, "(");
    update_LInput(input_arr, "(");
}


void Lab1Window::on_pBtnManagerCloseBracket_clicked()
{
//    update_LInput(input_arr, index, ")");
    update_LInput(input_arr, ")");
}



// Functions of Math Operators buttons

void Lab1Window::on_pBtnMathOperatorPlus_clicked()
{
//    update_LInput(input_arr, index, "+");
    update_LInput(input_arr, "+");
}


void Lab1Window::on_pBtnMathOperatorMinus_clicked()
{
//    update_LInput(input_arr, index, "-");
    update_LInput(input_arr, "-");
}


void Lab1Window::on_pBtnMathOperatorMultiply_clicked()
{
//    update_LInput(input_arr, index, "*");
    update_LInput(input_arr, "*");
}


void Lab1Window::on_pBtnMathOperatorDivide_clicked()
{
//    update_LInput(input_arr, index, "/");
    update_LInput(input_arr, "/");
}


void Lab1Window::on_pBtnMathOperatorPower_clicked()
{
//    update_LInput(input_arr, index, "^");
    update_LInput(input_arr, "^");
}


void Lab1Window::on_pBtnMathOperatorDecimalPoint_clicked()
{
//    update_LInput(input_arr, index, ".");
    update_LInput(input_arr, ".");
}



// Functions of Math Functions buttons


void Lab1Window::on_pBtnMathFunctionsSin_clicked()
{
//    update_LInput(input_arr, index, "sin");
//    update_LInput(input_arr, index, "(");
    update_LInput(input_arr, "sin");
    update_LInput(input_arr, "(");
}


void Lab1Window::on_pBtnMathFunctionsCos_clicked()
{
//    update_LInput(input_arr, index, "cos");
//    update_LInput(input_arr, index, "(");
    update_LInput(input_arr, "cos");
    update_LInput(input_arr, "(");
}


void Lab1Window::on_pBtnMathFunctionsTan_clicked()
{
//    update_LInput(input_arr, index, "tan");
//    update_LInput(input_arr, index, "(");
    update_LInput(input_arr, "tan");
    update_LInput(input_arr, "(");
}


void Lab1Window::on_pBtnMathFunctionsCtg_clicked()
{
//    update_LInput(input_arr, index, "ctg");
//    update_LInput(input_arr, index, "(");
    update_LInput(input_arr, "ctg");
    update_LInput(input_arr, "(");
}


void Lab1Window::on_pBtnMathFunctionsExp_clicked()
{
//    update_LInput(input_arr, index, "exp");
//    update_LInput(input_arr, index, "(");
    update_LInput(input_arr, "exp");
    update_LInput(input_arr, "(");
}


void Lab1Window::on_pBtnMathFunctionsLog_clicked()
{
//    update_LInput(input_arr, index, "log");
//    update_LInput(input_arr, index, "(");
    update_LInput(input_arr, "log");
    update_LInput(input_arr, "(");
}


// Functions of Numbers buttons

void Lab1Window::on_pBtnNumberZero_clicked()
{
//    update_LInput(input_arr, index, "0");
    update_LInput(input_arr, "0");
}


void Lab1Window::on_pBtnNumberOne_clicked()
{
//    update_LInput(input_arr, index, "1");
    update_LInput(input_arr, "1");
}


void Lab1Window::on_pBtnNumberTwo_clicked()
{
//    update_LInput(input_arr, index, "2");
    update_LInput(input_arr, "2");
}


void Lab1Window::on_pBtnNumberThree_clicked()
{
//    update_LInput(input_arr, index, "3");
    update_LInput(input_arr, "3");
}


void Lab1Window::on_pBtnNumberFour_clicked()
{
//    update_LInput(input_arr, index, "4");
    update_LInput(input_arr, "4");
}


void Lab1Window::on_pBtnNumberFive_clicked()
{
//    update_LInput(input_arr, index, "5");
    update_LInput(input_arr, "5");
}


void Lab1Window::on_pBtnNumberSix_clicked()
{
//    update_LInput(input_arr, index, "6");
    update_LInput(input_arr, "6");
}


void Lab1Window::on_pBtnNumberSeven_clicked()
{
//    update_LInput(input_arr, index, "7");
    update_LInput(input_arr, "7");
}


void Lab1Window::on_pBtnNumberEight_clicked()
{
//    update_LInput(input_arr, index, "8");
    update_LInput(input_arr, "8");
}


void Lab1Window::on_pBtnNumberNine_clicked()
{
//    update_LInput(input_arr, index, "9");
    update_LInput(input_arr, "9");
}



// Functions of Math Constants buttons

void Lab1Window::on_pBtnConstant_pi_clicked()
{
//    update_LInput(input_arr, index, "pi");
    update_LInput(input_arr, "pi");
}


void Lab1Window::on_pBtConstant_e_clicked()
{
//    update_LInput(input_arr, index, "e");
    update_LInput(input_arr, "e");
}



// Functions of Variables

void Lab1Window::on_pBtnVariableX_clicked()
{
//    update_LInput(input_arr, index, "x");
    update_LInput(input_arr, "x");
}

