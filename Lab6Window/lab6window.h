#ifndef LAB6WINDOW_H
#define LAB6WINDOW_H


#include <iostream>

using namespace std;


#include <QWidget>
#include <QSpinBox>

namespace Ui {
class Lab6Window;
}

class Lab6Window : public QWidget
{
    Q_OBJECT

public:
    explicit Lab6Window(QWidget *parent = nullptr);
    ~Lab6Window();

signals:
    void rootWindow();

private slots:
    void on_pBtnMenue_clicked();

    int get_row_count();

    int get_column_count();

    void set_table_widget_size(int rows, int columns);

    void add_spinbox(int rows, int columns, bool write);

    void on_CBCountRows_activated(int index);

    void on_CBCountColumns_activated(int index);

    void collect_user_data(int arr[], int row, int column);

    int check_value_in_arr(int const arr[], int value, int start, int stop);

    void get_count_duplicate_elements(int arr[], int duplicate_arr[], int row, int column);

    void replace_string_in_arr(int arr[], int duplicate_arr[], int row, int column);

    void show_output_matrix_data(int arr[], int row, int col);

    void on_pBtnShow_clicked();

private:
    Ui::Lab6Window *ui;
    QWidget *widget;
    QSpinBox *spinbox;
};


#define WIDTH_SPINBOX   35

#define HEIGHT_SPINBOX  35


#endif // LAB6WINDOW_H
