
#include <math.h>
#include "Lab1Window/MathModule/math_funcs.h"


string math_functions[11] = {
    "+", "-", "*", "/", "^",
    "sin", "cos", "tan",
    "ctg", "exp", "log"
};


string numbers[10] = {
    "0", "1", "2", "3",
    "4", "5", "6", "7",
    "8", "9"
};


string constants[3] = {
    "pi", "e", "x"
};


// ...

void set_math_tree(math_tree_knot math_tree[], int index_knot,
                   int operation, double value, int left, int right) {
    math_tree[index_knot].operation = operation;
    math_tree[index_knot].value = value;
    math_tree[index_knot].left = left;
    math_tree[index_knot].right = right;
}


int check_str_in_arr(string str, const string arr[],
                      int start_index, int stop_index) {
    for (int ind = start_index; ind < stop_index; ind++) {
        if (str == arr[ind]) {
            return ind;
        }
    }

    return -1;
}


bool check_breackets_in_string(const string math_string[],
                               int start_index, int stop_index) {
    int breackets = 0;

    for (int ind = start_index; ind < stop_index; ind++) {
        if ( math_string[ind] == "(" ) {
            breackets = breackets + 1;
        }

        else if ( math_string[ind] == ")" ) {
            breackets = breackets - 1;
        }

        if ( breackets < 0 ) {
            return false;
        }
    }

    return true;
}


void set_math_string(const string math_string[], string new_math_string[],
                     int start_index, int stop_index) {
    int ind = 0;

    while(start_index < stop_index) {
        new_math_string[ind] = math_string[start_index];

        ind = ind + 1;
        start_index = start_index + 1;
    }
}


int get_last_math_operation(string math_string[], int len) {
    int ind = 0, breackets = 0;
    int ind_operation = 0, weight_operation = 10000;

    while (ind < len) {
        int temp_weight = weight_operation + 1;

        if ( math_string[ind] ==  "(" ) {
            breackets = breackets + 1;
        }

        else if ( math_string[ind] == ")" ) {
            breackets = breackets - 1;
        }

        else if ( math_string[ind] == "^" ) {
            temp_weight = 3 + 10 * breackets;
        }

        else if ( math_string[ind] == "*" ) {
            temp_weight = 2 + 10 * breackets;
        }

        else if ( math_string[ind] == "/" ) {
            temp_weight = 2 + 10 * breackets;
        }

        else if ( math_string[ind] == "+" ) {
            temp_weight = 1 + 10 * breackets;
        }

        else if ( math_string[ind] == "-" ) {
            temp_weight = 1 + 10 * breackets;
        }

        else {
            ind = ind + 1;
            continue;
        }

        if (temp_weight <= weight_operation) {
            ind_operation = ind;
            weight_operation = temp_weight;
        }

        ind = ind + 1;
    }

    return ind_operation;
}


int create_tree(math_tree_knot math_tree[], const size_t len_1,
                string math_string[], size_t len_2, int index_knot) {
    if (len_2 == 1) {
        // Если длина строки равна единице, то мы дошли до конечного числа
        if (math_string[0] == "x") {
            set_math_tree(math_tree, index_knot, X__OPERATION_NUMBER, x_val, -1, -1);
            return index_knot;
        }

        else if (math_string[0] == "pi") {
            set_math_tree(math_tree, index_knot, PI__OPERATION_NUMBER, PI__NUMBER, -1, -1);
            return index_knot;
        }

        else if (math_string[0] == "e") {
            set_math_tree(math_tree, index_knot, E__OPERATION_NUMBER, E__NUMBER, -1, -1);
            return index_knot;
        }

        else {
            double value = ::atof(math_string->c_str());

            set_math_tree(math_tree, index_knot, NUMBER__OPERATION_NUMBER, value, -1, -1);
            return index_knot;
        }
    }

    else if (math_string[0] == "(" && math_string[len_2 - 1] == ")" &&
             check_breackets_in_string(math_string, 1, len_2 - 1)) {
        // Если выражение начинается с "(", а заканчивается ")" и внутри ВСЁ ОК, то
        // обрезаем эти скобки и вызываем функцию вновь
        string new_math_string[len_2 - 2];

        set_math_string(math_string, new_math_string, 1, len_2 - 1);

        int ind_left = create_tree(math_tree, len_1, new_math_string, len_2 - 2, index_knot + 1);

        set_math_tree(math_tree, index_knot, -1, -1, index_knot + 1, -1);

        return ind_left;
    }

    else if ( check_str_in_arr(math_string[0], math_functions, 0, 11) != -1 && math_string[1] == "(" &&
            math_string[len_2 - 1] == ")" && check_breackets_in_string(math_string, 2, len_2 - 1)) {
        // Если мы обнаружили строку -- математическую функцию (Например "cos(12 * 9 - 12)"), то
        // обрезаем строку (Отсекаем функцию и скобки -- обёртки).
        int new_len = len_2 - 3;
        string new_math_string[new_len];

        set_math_string(math_string, new_math_string, 2, len_2 - 1);

        int ind_left = create_tree(math_tree, len_1, new_math_string, len_2 - 3, index_knot + 1);

        int int_val_math_operator = check_str_in_arr(math_string[0], math_functions, 5, 11);

        set_math_tree(math_tree, index_knot, int_val_math_operator, -1, index_knot + 1, -1);

        return ind_left;
    }

    else {
        // Если все предыдущие шаги не сработали, то мы имеем такого вида выражение
        // (Например "12 * cos(12 - 9) + 122"), то мы находим самую последнюю
        // математическую операцию по ПРИОРИТЕТУ и делим строку на две. Разделителем
        // служит найденное (крайнее) действие.

        // Определяем самую последнюю операцию действия.
        int ind_operation = 0;
        ind_operation = get_last_math_operation(math_string, len_2);

        // Теперь следует разделить строку на две части (левая будет
        // равна всем значения до индекса_разбиения, а правая всем
        // значениям после индекса разбиения)
        int len_left_string = ind_operation;
        int len_right_string = len_2 - ind_operation - 1;

        string left_math_string[len_left_string];
        string right_math_string[len_right_string];

        set_math_string(math_string, left_math_string, 0, len_left_string);
        set_math_string(math_string, right_math_string, ind_operation + 1, len_2);

        // Теперь добавдяем новый узел соперацией
        int ind_left = create_tree(math_tree, len_1, left_math_string, len_left_string, index_knot + 1);
        int ind_right = create_tree(math_tree, len_1, right_math_string, len_right_string, ind_left + 1);

        int int_val_math_operator = check_str_in_arr(math_string[ind_operation], math_functions, 0, 5);

        set_math_tree(math_tree, index_knot, int_val_math_operator, -1, index_knot + 1, ind_left + 1);

        return ind_right;
    }
}



// ...

// 0
double get_plus(double left_val, double right_val) {
    return left_val + right_val;
}

// 1
double get_minus(double left_val, double right_val) {
    return left_val - right_val;
}

// 2
double get_multiply(double left_val, double right_val) {
    return left_val * right_val;
}

// 3
double get_divide(double left_val, double right_val) {
    return left_val / right_val;
}

// 4
double get_power(double left_val, double right_val) {
    return pow(left_val, right_val);
}

// 5
double get_sin(double val) {
    return sin(val);
}

// 6
double get_cos(double val) {
    return cos(val);
}

// 7
double get_tan(double val) {
    return tan(val);
}

// 8
double get_ctg(double val) {
    return 1 / tan(val);
}

// 9
double get_exp(double val) {
    return exp(val);
}

// 10
double get_log(double val) {
    return log(val);
}


double math_parser(const math_tree_knot math_tree[], const size_t len, int index) {
    if (math_tree[index].left == -1 && math_tree[index].right == -1) {
//        return ::atof(math_tree[index].value.c_str());
          return math_tree[index].value;
    }

    else {
        double answer;

        switch (math_tree[index].operation) {
            double left_val, right_val;

            case (VOID__OPERATION_NUMBER):
                answer = math_parser(math_tree, len, math_tree[index].left);
                break;

            case (PLUS__OPERATION_NUMBER):
                left_val = math_parser(math_tree, len, math_tree[index].left);
                right_val = math_parser(math_tree, len, math_tree[index].right);

                answer = get_plus(left_val, right_val);
                break;

            case (MINUS__OPERATION_NUMBER):
                left_val = math_parser(math_tree, len, math_tree[index].left);
                right_val = math_parser(math_tree, len, math_tree[index].right);

                answer = get_minus(left_val, right_val);
                break;

            case (MULTIPLY__OPERATION_NUMBER):
                left_val = math_parser(math_tree, len, math_tree[index].left);
                right_val = math_parser(math_tree, len, math_tree[index].right);

                answer = get_multiply(left_val, right_val);
                break;

            case (DIVIDE__OPERATION_NUMBER):
                left_val = math_parser(math_tree, len, math_tree[index].left);
                right_val = math_parser(math_tree, len, math_tree[index].right);

                answer = get_divide(left_val, right_val);
                break;

            case (POWER__OPERATION_NUMBER):
                left_val = math_parser(math_tree, len, math_tree[index].left);
                right_val = math_parser(math_tree, len, math_tree[index].right);

                answer = get_power(left_val, right_val);
                break;

            case (SIN__OPERATION_NUMBER):
                left_val = math_parser(math_tree, len, math_tree[index].left);

                answer = get_sin(left_val);
                break;

            case (COS__OPERATION_NUMBER):
               left_val = math_parser(math_tree, len, math_tree[index].left);

                answer = get_cos(left_val);
                break;

            case (TAN__OPERATION_NUMBER):
               left_val = math_parser(math_tree, len, math_tree[index].left);

                answer = get_tan(left_val);
                break;

            case (CTG__OPERATION_NUMBER):
               left_val = math_parser(math_tree, len, math_tree[index].left);

                answer = get_ctg(left_val);
                break;

            case (EXP_OPERATION_NUMBER):
               left_val = math_parser(math_tree, len, math_tree[index].left);

                answer = get_exp(left_val);
                break;

            case (LOG__OPERATION_NUMBER):
               left_val = math_parser(math_tree, len, math_tree[index].left);

                answer = get_log(left_val);
                break;
        }

        return answer;
    }
}



// ...

void change_input_arr(const string input_arr[], string change_arr[]) {
    int ind_1 = 0, ind_2 = 0;
    string value = "";

    while (input_arr[ind_1] != "!") {
        if (check_str_in_arr(input_arr[ind_1], numbers, 0, 10) != -1) {
            value = value + input_arr[ind_1];
        }

        else if (check_str_in_arr(input_arr[ind_1], math_functions, 0, 2) != -1 &&
                 ( (! ind_1) || (input_arr[ind_1 - 1] == "(")) &&
                 check_str_in_arr(input_arr[ind_1 + 1], numbers, 0, 10) != -1) {

            value = value + input_arr[ind_1];
        }

        else if (input_arr[ind_1] == "." &&
                 check_str_in_arr(input_arr[ind_1 - 1], numbers, 0, 10) != -1 &&
                 check_str_in_arr(input_arr[ind_1 + 1], numbers, 0, 10) != -1) {

            value = value + input_arr[ind_1];
        }

        else {
            if (value.length()) {
                change_arr[ind_2] = value;
                value = "";

                ind_2 = ind_2 + 1;
            }

            if (check_str_in_arr(input_arr[ind_1], math_functions, 0, 2) != -1 &&
               ( (! ind_1) || (input_arr[ind_1 - 1] == "(") ) &&
                check_str_in_arr(input_arr[ind_1 + 1], constants, 0, 3) != -1) {

                change_arr[ind_2] = "-1";
                change_arr[ind_2 + 1] = "*";
                change_arr[ind_2 + 2] = input_arr[ind_1 + 1];

                ind_1 = ind_1 + 1;
                ind_2 = ind_2 + 3;
            }

            else {
                change_arr[ind_2] = input_arr[ind_1];

                ind_2 = ind_2 + 1;
            }
        }

        ind_1 = ind_1 + 1;
    }

    if (value.length()) {
        change_arr[ind_2] = value;

        ind_2 = ind_2 + 1;
    }

    change_arr[ind_2] = "!";
}


