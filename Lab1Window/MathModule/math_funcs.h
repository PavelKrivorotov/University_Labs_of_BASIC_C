#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H


#include <iostream>
#include <string>

using namespace std;


// ...

struct math_tree_knot {
    int         operation;
    double      value;
    int         left;
    int         right;
};


// ...

extern string math_functions[11];

extern string numbers[10];

extern string constants[3];

extern double x_val;


// Числовые константы

#define PI__NUMBER      3.141592653


#define E__NUMBER       2.718281828


// Целочисленные идентификаторы математических операций

#define VOID__OPERATION_NUMBER      -1


#define PLUS__OPERATION_NUMBER      0


#define MINUS__OPERATION_NUMBER     1


#define MULTIPLY__OPERATION_NUMBER  2


#define DIVIDE__OPERATION_NUMBER    3


#define POWER__OPERATION_NUMBER     4


#define SIN__OPERATION_NUMBER       5


#define COS__OPERATION_NUMBER       6


#define TAN__OPERATION_NUMBER       7


#define CTG__OPERATION_NUMBER       8


#define EXP_OPERATION_NUMBER        9


#define LOG__OPERATION_NUMBER       10


// Целочисленные идентификаторы константных выражений

#define NUMBER__OPERATION_NUMBER    100


#define PI__OPERATION_NUMBER        101


#define E__OPERATION_NUMBER         102


#define X__OPERATION_NUMBER         103


// ...

void set_math_tree(math_tree_knot, int, string, string, int, int);


int check_str_in_arr(string, const string[], int, int);


bool check_breackets_in_string(const string[],int, int);


void set_math_string(const string[], string[], int, int);


int get_last_math_operation(string[], int);


int create_tree(math_tree_knot[], const size_t, string[], size_t, int);



// ...

double get_plus(double, double);


double get_minus(double, double);


double get_multiply(double, double);


double get_divide(double, double);


double get_power(double, double);


double get_sin(double);


double get_cos(double);


double get_tan(double);


double get_ctg(double);


double get_exp(double);


double get_log(double);


double math_parser(const math_tree_knot[], const size_t, int);



// ...

void change_input_arr(const string[], string[]);


#endif // MATH_FUNCTIONS_H

