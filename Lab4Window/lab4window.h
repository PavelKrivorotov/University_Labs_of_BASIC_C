#ifndef LAB4WINDOW_H
#define LAB4WINDOW_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class Lab4Window;
}

class Lab4Window : public QWidget
{
    Q_OBJECT

public:
    explicit Lab4Window(QWidget *parent = nullptr);
    ~Lab4Window();

signals:
    void rootWindow();

private slots:
    void on_pBtnMenue_clicked();

    void clear_window();

    void get_input_value(double &x1, double &x2, double &dx, double &a, double &b, double &c);

    double calculate_function(double x, double a, double b, double c);

    void on_pBtnShow_clicked();

private:
    Ui::Lab4Window *ui;
    QStandardItemModel *model;
    QStandardItem *item_x;
    QStandardItem *item_fx;
};

#endif // LAB4WINDOW_H
