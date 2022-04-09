#ifndef LAB5WINDOW_H
#define LAB5WINDOW_H


#include <iostream>
using namespace std;

#include <QWidget>
#include <QSpinBox>

namespace Ui {
class Lab5Window;
}

class Lab5Window : public QWidget
{
    Q_OBJECT

public:
    explicit Lab5Window(QWidget *parent = nullptr);
    ~Lab5Window();

signals:
    void rootWindow();

private slots:
    void on_pBtnMenue_clicked();

    void set_table_widget(int index);

    void add_spinbox(int index);

    void set_answer_value(int count_numbers, int sum_numbers);

    void on_CBLength_activated(int index);

    void collect_user_data(int arr[], int len);

    int count_negative_numbers(const int arr[], int len);

    int sum_abs_numbers_after_min_number(const int arr[], int len);

    void on_pBtnShow_clicked();

private:
    Ui::Lab5Window *ui;
    QSpinBox *spinbox;
    QWidget *widget;
};


#define WIDTH_SPINBOX   35

#define HEIGHT_SPINBOX  35


#endif // LAB5WINDOW_H
