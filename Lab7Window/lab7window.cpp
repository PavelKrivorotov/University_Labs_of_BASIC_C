#include "lab7window.h"
#include "ui_lab7window.h"

Lab7Window::Lab7Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lab7Window)
{
    ui->setupUi(this);
}

Lab7Window::~Lab7Window()
{
    delete ui;
}

void Lab7Window::on_pBtnMenu_clicked()
{
    ui->TEMainString->setPlainText("");
    ui->TESubString->setPlainText("");

    set_answer("");

    emit rootWindow();
    this->close();
}


void Lab7Window::set_answer(QString text) {
    ui->LResult->setText(text);
}


void Lab7Window::on_pBtnCheck_clicked()
{
    QString mainstr, substr;
    bool flag = false;

    mainstr = ui->TEMainString->toPlainText();
    substr = ui->TESubString->toPlainText();

    for (int ind_1 = 0; ind_1 < mainstr.size(); ind_1++) {
        for (int ind_2 = 0; ind_2 < substr.size(); ind_2++) {
            if (mainstr[ind_1] == substr[ind_2]) {
                set_answer(QString::fromStdString("MainString contain word in SubString --> ")
                           + QString::fromStdString("Letter ") +QString::fromStdString("'")
                           + substr[ind_2] + QString::fromStdString("'"));
                flag = true;
                break;
            }
        }
    }

    if (!flag) {
        set_answer("MainString not contain word in SubString");
    }
}

