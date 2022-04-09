#include "lab6window.h"
#include "ui_lab6window.h"

Lab6Window::Lab6Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lab6Window)
{
    ui->setupUi(this);

    set_table_widget_size(1, 1);
    add_spinbox(1, 1, true);
    add_spinbox(1, 1, false);
}

Lab6Window::~Lab6Window()
{
    delete ui;
}


void Lab6Window::on_pBtnMenue_clicked()
{
    emit rootWindow();
    this->close();
}


// Collect InputMatrix size

int Lab6Window::get_row_count() {
    return ui->TWInputMatrix->rowCount();
}


int Lab6Window::get_column_count() {
    return ui->TWInputMatrix->columnCount();
}


void Lab6Window::set_table_widget_size(int rows, int columns) {
    // Clear data in Table Widget
    ui->TWInputMatrix->clear();
    ui->TWOutputMatrix->clear();

    // Set settings from InputMatrix
    ui->TWInputMatrix->setRowCount(rows);
    ui->TWInputMatrix->setColumnCount(columns);

    ui->TWInputMatrix->setMaximumWidth((WIDTH_SPINBOX + 3) * columns);
    ui->TWInputMatrix->setMaximumHeight((HEIGHT_SPINBOX + 3) * rows);

    ui->TWInputMatrix->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    // Set settings from OutputMatrix
    ui->TWOutputMatrix->setRowCount(rows);
    ui->TWOutputMatrix->setColumnCount(columns);

    ui->TWOutputMatrix->setMaximumWidth((WIDTH_SPINBOX + 3) * columns);
    ui->TWOutputMatrix->setMaximumHeight((HEIGHT_SPINBOX + 3) * rows);

    ui->TWOutputMatrix->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}


void Lab6Window::add_spinbox(int rows, int columns, bool write) {
    for (int ind_row = 0; ind_row < rows; ind_row++) {
        for (int ind_col = 0; ind_col < columns; ind_col++) {
            spinbox = new QSpinBox();

            spinbox->setMaximumWidth(WIDTH_SPINBOX);
            spinbox->setMaximumHeight(HEIGHT_SPINBOX);
            spinbox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

            spinbox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);

            spinbox->setValue(0);
            spinbox->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

            // Check flag "write" and add spinbox in needed TWMatrix
            if (write) {
                ui->TWInputMatrix->setCellWidget(ind_row, ind_col, spinbox);
            }

            else {
                spinbox->setReadOnly(true);

                ui->TWOutputMatrix->setCellWidget(ind_row, ind_col, spinbox);
            }
        }
    }
}


void Lab6Window::on_CBCountRows_activated(int index)
{
    // Show column Count now
    int col_count = get_column_count();

    // Set size of Table Widgets (InputMatrix and OutputMatrix)
    set_table_widget_size(index + 1, col_count);

    // Add spinbox in InputMatrix
    add_spinbox(index + 1, col_count, true);

    // Add spinbox in OutputMatrix
    add_spinbox(index + 1, col_count, false);
}


void Lab6Window::on_CBCountColumns_activated(int index)
{
    // Show row count now
    int row_count = get_row_count();

    // Set size of Table Widgets (InputMatrix and OutputMatrix)
    set_table_widget_size(row_count, index + 1);

    // Add spinbox in InputMatrix
    add_spinbox(row_count, index + 1, true);

    // Add spinbox in OutputMatrix
    add_spinbox(row_count, index + 1, false);
}


void Lab6Window::collect_user_data(int arr[], int row, int column) {
    for (int ind_row = 0; ind_row < row; ind_row++) {
        for (int ind_col = 0; ind_col < column; ind_col++) {
            widget = ui->TWInputMatrix->cellWidget(ind_row, ind_col);
            spinbox = new QSpinBox();

            spinbox = static_cast<QSpinBox*>(widget);

            int index = ind_row * column + ind_col;
            arr[index] = spinbox->value();
        }
    }
}


int Lab6Window::check_value_in_arr(int const arr[], int value, int start, int stop) {
    int count = 0;

    for (int ind = start; ind < stop; ind++) {
        if (arr[ind] == value) {
            count = count + 1;
        }
    }

    return count;
}


void Lab6Window::get_count_duplicate_elements(int arr[], int duplicate_arr[], int row, int column) {
    for (int ind_row = 0; ind_row < row; ind_row++) {
        int count = 0;

        for (int ind_col = 0; ind_col < column; ind_col++){
            int index = ind_row * column + ind_col;
            int temp_count = check_value_in_arr(arr, arr[index], ind_row * column, (ind_row + 1) * column);

            if (temp_count > count) {
                count = temp_count;
            }
        }

        duplicate_arr[ind_row] = count;
    }
}


void Lab6Window::replace_string_in_arr(int arr[], int duplicate_arr[], int row, int column) {
    for (int ind_1 = 0; ind_1 < row - 1; ind_1++) {
        for (int ind_2 = ind_1 + 1; ind_2 < row; ind_2++) {
            if (duplicate_arr[ind_2] > duplicate_arr[ind_1]) {
                //Replace value in duplicate_arr
                int temp = duplicate_arr[ind_1];
                duplicate_arr[ind_1] = duplicate_arr[ind_2];
                duplicate_arr[ind_2] = temp;

                // Replace string in arr
                for (int ind = 0; ind < column; ind++) {
                    int temp = arr[ind_1 * column + ind];
                    arr[ind_1 * column + ind] = arr[ind_2 * column + ind];
                    arr[ind_2 * column + ind] = temp;
                }
            }
        }
    }
}


void Lab6Window::show_output_matrix_data(int arr[], int row, int column) {
    for (int ind_row = 0; ind_row < row; ind_row++) {
        for (int ind_col = 0; ind_col < column; ind_col++) {
            widget = ui->TWOutputMatrix->cellWidget(ind_row, ind_col);
            spinbox = new QSpinBox();

            spinbox = static_cast<QSpinBox*>(widget);

            int index = ind_row * column + ind_col;
            spinbox->setValue(arr[index]);
        }
    }
}


void Lab6Window::on_pBtnShow_clicked()
{
    int col_count = get_column_count();
    int row_count = get_row_count();

    int arr[row_count * col_count];
    collect_user_data(arr, row_count, col_count);

    int duplicate_arr[row_count];
    get_count_duplicate_elements(arr, duplicate_arr, row_count, col_count);

    replace_string_in_arr(arr, duplicate_arr, row_count, col_count);

    show_output_matrix_data(arr, row_count, col_count);
}

