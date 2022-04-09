#ifndef LAB7WINDOW_H
#define LAB7WINDOW_H

#include <iostream>

using namespace std;


#include <QWidget>

namespace Ui {
class Lab7Window;
}

class Lab7Window : public QWidget
{
    Q_OBJECT

public:
    explicit Lab7Window(QWidget *parent = nullptr);
    ~Lab7Window();

signals:
    void rootWindow();

private slots:
    void on_pBtnMenu_clicked();

    void set_answer(QString text);

    void on_pBtnCheck_clicked();

private:
    Ui::Lab7Window *ui;
};

#endif // LAB7WINDOW_H
