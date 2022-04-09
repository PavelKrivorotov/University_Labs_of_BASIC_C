#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //...
    window1 = new Lab1Window();
    window2 = new Lab2Window();

    window4 = new Lab4Window();
    window5 = new Lab5Window();
    window6 = new Lab6Window();
    window7 = new Lab7Window();
    window8 = new Lab8Window();

    connect(window1, &Lab1Window::rootWindow, this, &MainWindow::show);
    connect(window2, &Lab2Window::rootWindow, this, &MainWindow::show);

    connect(window4, &Lab4Window::rootWindow, this, &MainWindow::show);
    connect(window5, &Lab5Window::rootWindow, this, &MainWindow::show);
    connect(window6, &Lab6Window::rootWindow, this, &MainWindow::show);
    connect(window7, &Lab7Window::rootWindow, this, &MainWindow::show);
    connect(window8, &Lab8Window::rootWindow, this, &MainWindow::show);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBtnContent_1_clicked()
{
    window1->show();
    this->close();
}


void MainWindow::on_pBtnContent_2_clicked()
{
    window2->show();
    this->close();
}


void MainWindow::on_pBtnContent_4_clicked()
{
    window4->show();
    this->close();
}


void MainWindow::on_pBtnContent_5_clicked()
{
    window5->show();
    this->close();
}


void MainWindow::on_pBtnContent_6_clicked()
{
    window6->show();
    this->close();
}


void MainWindow::on_pBtnContent_8_clicked()
{
    window8->show();
    this->close();
}


void MainWindow::on_pBtnContent_7_clicked()
{
    window7->show();
    this->close();
}

