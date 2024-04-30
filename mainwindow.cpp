#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPushButton>
#include <QWidget>
#include <fstream> // Include for ifstream
#include <QString>
using namespace std;
std::string filename;
ifstream file;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
           "Open File", "", "All Files (*)");

   filename = fileName.toStdString();


}


void MainWindow::on_pushButton_2_clicked()
{

    QColor white(255, 255, 255);
    ui->textEdit->setTextColor(white);



    file.open(filename);
    string temp,content="";
    QString plaintext;
    while(getline(file,temp))
    {
        content+=temp;
    }
     plaintext = QString::fromStdString(content);
    ui->textEdit->setPlainText(plaintext);
    ui->label->setText("mistakes log");
}

