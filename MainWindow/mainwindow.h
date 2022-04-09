#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Lab1Window/Window/lab1window.h>
#include <Lab2Window/lab2window.h>

#include <Lab4Window/lab4window.h>
#include <Lab5Window/lab5window.h>
#include <Lab6Window/lab6window.h>

#include <Lab8Window/lab8window.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pBtnContent_1_clicked();

    void on_pBtnContent_2_clicked();

    void on_pBtnContent_4_clicked();

    void on_pBtnContent_5_clicked();

    void on_pBtnContent_6_clicked();

    void on_pBtnContent_8_clicked();

private:
    Ui::MainWindow *ui;
    Lab1Window *window1;
    Lab2Window *window2;
    Lab4Window *window4;
    Lab5Window *window5;
    Lab6Window *window6;

    Lab8Window *window8;
};
#endif // MAINWINDOW_H
