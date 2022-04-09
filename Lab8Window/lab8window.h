#ifndef LAB8WINDOW_H
#define LAB8WINDOW_H

#include <iostream>
#include <fstream>

using namespace std;


#include <QWidget>
#include <QFileDialog>
#include <QMenu>
#include <QStyle>

namespace Ui {
class Lab8Window;
}

class Lab8Window : public QWidget
{
    Q_OBJECT

public:
    explicit Lab8Window(QWidget *parent = nullptr);
    ~Lab8Window();

    QString file_path = "D:/text.txt";

    bool state_open =   false;
    bool state_close =  false;
    bool state_modifi = false;
    bool state_save =   false;

    QStringList options = {
        "Open",
        "Close",
        "Modify",
        "Save as"
    };

signals:
    void rootWindow();

private slots:
    void on_pBtnMenue_clicked();

    void add_options_in_menue();

    void set_file_path(QString path);

    void show_plain_text(QString text);

    void show_file_dialog(string oprion);

    QString read_file();

    QString concatenate_string(QString text, int start, int stop);

    QString modify_file();

    void on_tBtnFile_triggered(QAction *arg1);

private:
    Ui::Lab8Window *ui;
    QFileDialog *filedialog;
    QMenu *menu;
};


#endif // LAB8WINDOW_H
