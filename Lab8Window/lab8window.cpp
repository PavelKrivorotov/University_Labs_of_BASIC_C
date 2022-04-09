#include "lab8window.h"
#include "ui_lab8window.h"

Lab8Window::Lab8Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lab8Window)
{
    ui->setupUi(this);

    menu = new QMenu();
    add_options_in_menue();

    ui->PTextEdit->setPlainText(QString("Hello World\nMy name is Pavel Krivorotov"));
}

Lab8Window::~Lab8Window()
{
    delete ui;
}

void Lab8Window::on_pBtnMenue_clicked()
{
    emit rootWindow();
    this->close();
}


void Lab8Window::add_options_in_menue() {
    for (int ind = 0; ind < options.size(); ind++) {
        menu->addAction(options[ind]);
    }

    ui->tBtnFile->setMenu(menu);
}


void Lab8Window::set_file_path(QString path) {
    file_path = path;
}


void Lab8Window::show_plain_text(QString text) {
    ui->PTextEdit->setPlainText(text);
}


void Lab8Window::show_file_dialog(string option) {
    filedialog = new QFileDialog();
    QString path;

    if (option == "read") {
        path = filedialog->getOpenFileName(this, "Open file", "D:/", "Text files (*.txt)");
    }

    else if (option == "write") {
        QString text;
        text = ui->PTextEdit->toPlainText();

        filedialog->saveFileContent(text.toUtf8(), file_path);
    }

    else {
        path = "D:/text.txt";
    }


    if (path.size()) {
        file_path = path;
    }
}


QString Lab8Window::read_file() {
    if (file_path.size()) {
        ifstream op_file(file_path.toStdString());
        string file, line;

        while (getline(op_file, line)) {
            file = file + line + "\n";
        }

        op_file.close();

        return QString::fromStdString(file);
    }

    else {
        return "";
    }
}


QString Lab8Window::concatenate_string(QString text, int start, int stop) {
    QString qstr;

    for (int ind = start; ind < stop; ind++) {
        qstr = qstr + text[ind];
    }

    return qstr;
}


QString Lab8Window::modify_file() {
     QString first_part, second_part, other;
     QString text;

     text = ui->PTextEdit->toPlainText();
     text.replace("\n", "");

     int start_ind = 0, stop_ind = 0;

     while (stop_ind < text.size()) {
         if (text[stop_ind] == QString::fromStdString(".")) {
             other = other + concatenate_string(text, start_ind, stop_ind + 1);

             start_ind = stop_ind + 1;
         }

         else if (text[stop_ind] == QString::fromStdString("!")) {
             first_part = first_part + concatenate_string(text, start_ind, stop_ind + 1);

             start_ind = stop_ind + 1;
         }

         else if (text[stop_ind] == QString::fromStdString("?")) {
             second_part = second_part + concatenate_string(text, start_ind, stop_ind + 1);

             start_ind = stop_ind + 1;
         }

         stop_ind = stop_ind + 1;
     }

     if (start_ind < stop_ind) {
         other = other + concatenate_string(text,start_ind, stop_ind);
     }

     return first_part + second_part + other;
}


void Lab8Window::on_tBtnFile_triggered(QAction *arg1)
{
//    cout << arg1->iconText().toStdString() << endl;

    if (arg1->iconText() == "Open") {
        show_file_dialog("read");

        QString text = read_file();
        show_plain_text(text);
    }

    else if (arg1->iconText() == "Close") {
        set_file_path("D:/");
        show_plain_text("");
    }

    else if (arg1->iconText() == "Modify") {
        QString modify_text = modify_file();
        show_plain_text(modify_text);
    }

    else if (arg1->iconText() == "Save as") {
        show_file_dialog("write");
    }
}

