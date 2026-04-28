#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStandardPaths>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->noteEditor,&QTextEdit::textChanged,this, &MainWindow::on_saveBtn_clicked);
    QString path=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/my_note.txt";
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice:: Text )){
        QTextStream in(&file);
        QString savedText=in.readAll();
        ui->noteEditor->setPlainText(savedText);
        file.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveBtn_clicked()
{
    QString folderPath=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString filePath=folderPath+"/my_note.txt";
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out<<ui->noteEditor->toPlainText();
        file.close();
        ui->statusbar->showMessage("Сохранено в папку загрузки", 2000);

    }else{
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить файл!");
        qDebug() << "Не удалось открыть файл для записи!";
        }

}

