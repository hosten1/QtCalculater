#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QLabel>
#include<QDebug>
#include<QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include<iostream>
#include "calculate.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

   /*
    resize(600,400);
    QMenuBar *bar = menuBar();
//    bar->setVisible(true);
//    bar->show();
    this->setMenuBar(bar);//创建一个导航栏，如果不设置菜单栏，这个就不会显示
    //创建菜单
    QMenu *menu1 = bar->addMenu("文件");
    menu1->addSeparator();//添加分割线
    QMenu *menu2 = bar->addMenu("编辑");
    QAction *newAction = menu1->addAction("新建");
    QAction *openAction = menu1->addAction("打开");
    QAction *new1Action = menu2->addAction("新建");
    QAction *open2Action = menu2->addAction("打开");

//工具栏
    QToolBar *toobar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toobar);//默认停靠位置
    toobar->setMovable(true);
    toobar->setFloatable(true);
    toobar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
    toobar->addAction(newAction);
    toobar->addAction(openAction);
    toobar->addSeparator();
    toobar->addAction(new1Action);
    toobar->addAction(open2Action);
    //状态栏

    QStatusBar *sBar = statusBar();
    setStatusBar(sBar);
    QLabel *lab = new  QLabel("显示");
    sBar->addWidget(lab);
*/
    connect(ui->actionnew,&QAction::triggered,this,[=](){

      QString filePath =  QFileDialog::getOpenFileName(this,"打开文件","/Users/vrv2/Desktop/06  qt","*.txt");
       qDebug()<<"ddddddddddddddddddddd"<<filePath;
    });
QGridLayout *gLayout = ui->gridLayout;
tEdit =  ui->textEdit;
tEdit->setFixedHeight(50);
tEdit->setPlainText("0");
ui->pushButton_16->setFixedHeight(60);
ui->pushButton_17->setFixedHeight(60);
gLayout->setRowStretch(0,120);
gLayout->setColumnStretch(60,0);
ui->pushButton->setFixedHeight(60);
ui->pushButton_1->setFixedHeight(60);
ui->pushButton_2->setFixedHeight(60);
ui->pushButton_3->setFixedHeight(60);
ui->pushButton_4->setFixedHeight(60);
ui->pushButton_5->setFixedHeight(60);
ui->pushButton_6->setFixedHeight(60);
ui->pushButton_7->setFixedHeight(60);
ui->pushButton_8->setFixedHeight(60);
ui->pushButton_9->setFixedHeight(60);
ui->pushButton_10->setFixedHeight(60);
ui->pushButton_11->setFixedHeight(60);
ui->pushButton_12->setFixedHeight(130);//等于号
ui->pushButton_12->setFixedWidth(155);//等于号
gLayout->addWidget(ui->pushButton_12,4,4,0,0);
ui->pushButton_13->setFixedHeight(60);
ui->pushButton_14->setFixedHeight(60);
ui->pushButton_15->setFixedHeight(60);
ui->pushButton_16->setFixedHeight(60);
ui->pushButton_17->setFixedHeight(60);
ui->pushButton_19->setFixedHeight(60);
ui->pushButton_20->setFixedHeight(60);
ui->pushButton_21->setFixedHeight(60);

ui->pushButton->setText("±");
    //资源文件使用方式
ui->actionnew->setIcon(QIcon("://a_j.png"));

connect(ui->actionnew,&QAction::triggered,this,[=](){
    qDebug()<<"对话框";
});



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_textChanged()
{
    QString str = ui->textEdit->toPlainText();
    qDebug()<<"on_textEdit_textChanged "<<str;
}

//void MainWindow::on_pushButton_1_toggled(bool checked)
//{
//    QString str = ui->pushButton_1->text();
//    if(isCalcluted){
//        b = str.toInt();
//    }else {
//        a = str.toInt();
//     }
//     qDebug()<<"on_pushButton_1_toggled "<<str<<"checked ="<<checked << " a = " << a << " b = " << b;
//}

void MainWindow::on_pushButton_1_clicked(bool checked)//1
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = ui->pushButton_1->text();
    }else {
        str_text = str_text + ui->pushButton_1->text();
    }
    tEdit->setPlainText(str_text);
    tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    QString str = ui->pushButton_1->text();
//    qDebug()<<"on_pushButton_1_toggled "<<str<<"checked ="<<checked;
//    tEdit->setPlainText(str_text+str);
//     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//     if(isCalcluted){
//         QString cacStr = tEdit->toPlainText();
//         QStringList list = cacStr.split(ch);

//         b = list.last().toInt();
//     }else {
//          a = tEdit->toPlainText().toInt();
//      }
}

void MainWindow::on_pushButton_2_clicked()//2
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = ui->pushButton_2->text();
    }else {
        str_text = str_text + ui->pushButton_2->text();
    }
    tEdit->setPlainText(str_text);
    tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    QString str_text = tEdit->toPlainText();
//    QString str = ui->pushButton_2->text();
//    qDebug()<<"on_pushButton_2_clicked "<<str;
//    ui->textEdit->setPlainText(str_text+str);
//     ui->textEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//     if(isCalcluted){
//         QString cacStr =  ui->textEdit->toPlainText();
//         QStringList list = cacStr.split(ch);

//         b = list.last().toInt();
//     }else {
//          a = ui->textEdit->toPlainText().toInt();
//      }
}


void MainWindow::on_pushButton_3_clicked()//3
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = ui->pushButton_3->text();
    }else {
        str_text = str_text + ui->pushButton_3->text();
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    QString str_text = ui->textEdit->toPlainText();
//    QString str = ui->pushButton_3->text();
//    qDebug()<<"on_pushButton_3_clicked "<<str;
//     ui->textEdit->setPlainText(str_text+str);
//     ui->textEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//     if(isCalcluted){
//         QString cacStr =  ui->textEdit->toPlainText();
//         QStringList list = cacStr.split(ch);

//         b = list.last().toInt();
//     }else {
//         a = ui->textEdit->toPlainText().toInt();
//      }
}



void MainWindow::on_pushButton_4_clicked()//4
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = "4";
    }else {
        str_text = str_text + "4";
    }
    tEdit->setPlainText(str_text);
    tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    QString str_text = ui->textEdit->toPlainText();
//    QString str = ui->pushButton_4->text();
//    qDebug()<<"on_pushButton_4_clicked "<<str;
//    ui->textEdit->setPlainText(str_text+str);
//     ui->textEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//     if(isCalcluted){
//         QString cacStr =  ui->textEdit->toPlainText();
//         QStringList list = cacStr.split(ch);

//         b = list.last().toInt();
//     }else {
//         a = ui->textEdit->toPlainText().toInt();
//      }
}

void MainWindow::on_pushButton_5_clicked()//5
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = "5";
    }else {
        str_text = str_text + "5";
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);

//    QString str_text = ui->textEdit->toPlainText();
//    QString str = ui->pushButton_5->text();
//    qDebug()<<"on_pushButton_5_clicked "<<str;
//    ui->textEdit->setPlainText(str_text+str);
//    ui->textEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    if(isCalcluted){
//        QString cacStr =  ui->textEdit->toPlainText();
//        QStringList list = cacStr.split(ch);

//        b = list.last().toInt();
//    }else {
//        a = ui->textEdit->toPlainText().toInt();
//     }
}

void MainWindow::on_pushButton_6_clicked()//6
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = "6";
    }else {
        str_text = str_text + "6";
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    QString str_text = ui->textEdit->toPlainText();
//    QString str = ui->pushButton_6->text();
//    qDebug()<<"on_pushButton_6_clicked "<<str;
//    ui->textEdit->setPlainText(str_text+str);
//     ui->textEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//     if(isCalcluted){
//         QString cacStr =  ui->textEdit->toPlainText();
//         QStringList list = cacStr.split(ch);

//         b = list.last().toInt();
//     }else {
//         a = ui->textEdit->toPlainText().toInt();
//      }
}


void MainWindow::on_pushButton_7_clicked()//7
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = "7";
    }else {
        str_text = str_text + "7";
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    QString str_text = ui->textEdit->toPlainText();
//    QString str = ui->pushButton_7->text();
//    qDebug()<<"on_pushButton_7_clicked "<<str;
//    ui->textEdit->setPlainText(str_text+str);
//     ui->textEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//     if(isCalcluted){
//         QString cacStr =  ui->textEdit->toPlainText();
//         QStringList list = cacStr.split(ch);

//         b = list.last().toInt();
//     }else {
//         a = ui->textEdit->toPlainText().toInt();
//      }
}
void MainWindow::on_pushButton_8_clicked()//8
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = "8";
    }else {
        str_text = str_text + "8";
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    QString str_text = ui->textEdit->toPlainText();
//    QString str = ui->pushButton_8->text();
//    qDebug()<<"on_pushButton_8_clicked "<<str;
//    ui->textEdit->setPlainText(str_text+str);
//    ui->textEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    if(isCalcluted){
//        QString cacStr =  ui->textEdit->toPlainText();
//        QStringList list = cacStr.split(ch);

//        b = list.last().toInt();
//    }else {
//        a = ui->textEdit->toPlainText().toInt();
//     }
}

void MainWindow::on_pushButton_9_clicked()//9
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = "9";
    }else {
        str_text = str_text + "9";
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    QString str_text = ui->textEdit->toPlainText();
//    QString str = ui->pushButton_9->text();
//    qDebug()<<"on_pushButton_9_clicked "<<str;
//    ui->textEdit->setPlainText(str_text+str);
//    ui->textEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    if(isCalcluted){
//        QString cacStr =  ui->textEdit->toPlainText();
//        QStringList list = cacStr.split(ch);

//        b = list.last().toInt();
//    }else {
//        a = ui->textEdit->toPlainText().toInt();
//     }

}


void MainWindow::on_pushButton_13_clicked()//0
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = "0";
    }else {
        str_text = str_text + "0";
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
}
void MainWindow::on_pushButton_10_clicked()//+
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = "+";
    }else {
        str_text = str_text + "+";
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    QString str_text = ui->textEdit->toPlainText();
//    QString str = ui->pushButton_10->text();
//    qDebug()<<"on_pushButton_10_clicked "<<str;
//    ui->textEdit->setPlainText(str_text+str);
//     ui->textEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//     if(!isCalcluted){
//         if(str == "+"){
//             ch = str;
//             isCalcluted = true;
//         }else{
//             isCalcluted = false;
//         }
//     }

}

void MainWindow::on_pushButton_11_clicked()//-
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = "-";
    }else {
        str_text = str_text + "-";
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//    QString str_text = ui->textEdit->toPlainText();
//    QString str = ui->pushButton_11->text();
//    qDebug()<<"on_pushButton_11_clicked "<<str;
//    ui->textEdit->setPlainText(str_text+str);
//     ui->textEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
//     if(!isCalcluted){
//         if(str == "-"){
//             ch = str;
//             isCalcluted = true;
//         }else{
//             isCalcluted = false;
//         }
//     }
}
void MainWindow::on_pushButton_12_clicked()//=
{
      std::string inputTemp = tEdit->toPlainText().toStdString();
      Calculate cal;
      double value = cal.stringCalculate(inputTemp);

      if(value != INT_MAX) {
         QString str = tEdit->toPlainText()+"="+QString::number(value);
         tEdit->setPlainText(str);
      }else{
         QString str = tEdit->toPlainText()+"="+"=syntax error";
         tEdit->setPlainText(str);
      }

//    QString str_text = ui->textEdit->toPlainText();
//    QString str = ui->pushButton_12->text();
//    qDebug()<<"on_pushButton_12_clicked "<<str;
//    ui->textEdit->setPlainText(str_text+str);
//    if(!isResulted){
//        if(str == "="){
//            int c = 0;
//            if(ch == "+"){
//                c = a+b;
//            }else if (ch == "-"){
//                c = a-b;
//            }
//            QString str_res = QString::number(a,10) +ch+QString::number(b,10)+"="+QString::number(c,10);
//            ui->textEdit->setPlainText(str_res);
//            qDebug()<<"on_pushButton_12_clicked "<<str_res;
//        }
//        isResulted = true;
//    }else {
//        isCalcluted = false;
//        isResulted = false;
//        a=0;
//        b=0;
//        ch="";
//        ui->textEdit->setPlainText("");
//    }

}

void MainWindow::on_pushButton_16_clicked()//AC
{
   tEdit->setPlainText("");
}

void MainWindow::on_pushButton_17_clicked()//CE
{
    QString str_text = tEdit->toPlainText();
    str_text = str_text.left(str_text.length() - 1);
    tEdit->setPlainText(str_text);
}

void MainWindow::on_pushButton_clicked()//±
{
//    QString str_text = tEdit->toPlainText();
//    if(str_text == "0"){
//        str_text = ui->pushButton->text();
//    }else {
//        str_text = str_text + ui->pushButton_3->text();
//    }
//    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
}

void MainWindow::on_pushButton_19_clicked()//X
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = "*";
    }else {
        str_text = str_text + "*";
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
}

void MainWindow::on_pushButton_20_clicked()//"/"
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = "/";
    }else {
        str_text = str_text + "/";
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
}

void MainWindow::on_pushButton_14_clicked()//.
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = ".";
    }else {
        str_text = str_text + ".";
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
}

void MainWindow::on_pushButton_15_clicked()//(
{  QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = "(";
    }else {
        str_text = str_text + "(";
    }
    tEdit->setPlainText(str_text);
     tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);

}

void MainWindow::on_pushButton_21_clicked()//)
{
    QString str_text = tEdit->toPlainText();
    if(str_text == "0"){
        str_text = ")";
    }else {
        str_text = str_text + ")";
    }
    tEdit->setPlainText(str_text);
    tEdit->moveCursor(QTextCursor::End,QTextCursor::MoveAnchor);
}
