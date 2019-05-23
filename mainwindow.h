#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_textEdit_textChanged();

//    void on_pushButton_1_toggled(bool checked);

    void on_pushButton_1_clicked(bool checked);
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_21_clicked();

private:
    Ui::MainWindow *ui;
    int a = 0;
    int b = 0;
    bool isCalcluted = false;
    bool isResulted = false;
    QString inputStr = "0";
    QTextEdit *tEdit;

};

#endif // MAINWINDOW_H
