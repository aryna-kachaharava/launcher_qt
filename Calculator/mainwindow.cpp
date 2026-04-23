#include "mainwindow.h"
#include "./ui_mainwindow.h"
double num_first;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_posneg, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_devide, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()),this,SLOT(math_operations()));
    ui->pushButton_devide->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digits_numbers(){
    QPushButton*button=(QPushButton*)sender();
    double all_numbers;
    QString new_label;
    if (ui->Resshow->text().contains(".")&&button->text()=="0"){
        new_label=ui->Resshow->text()+button->text();
    }else{
    all_numbers=(ui->Resshow->text()+button->text()).toDouble();
        new_label=QString::number(all_numbers,'g',12);}
    ui->Resshow->setText(new_label);
}
void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->Resshow->text().contains('.')))
    ui->Resshow->setText(ui->Resshow->text()+".");

}

void MainWindow::operations(){
    QPushButton*button=(QPushButton*)sender();
    double all_numbers;
    QString new_label;
    if (button->text()=="+/-"){
        all_numbers=(ui->Resshow->text()).toDouble();
        all_numbers=all_numbers * -1;
        new_label=QString::number(all_numbers,'g',12);
        ui->Resshow->setText(new_label);
    }else if (button->text()=="%"){
        all_numbers=(ui->Resshow->text()).toDouble();
        all_numbers=all_numbers * 0.01;
        new_label=QString::number(all_numbers,'g',12);
        ui->Resshow->setText(new_label);}

}
void MainWindow::math_operations()
{
    QPushButton*button=(QPushButton*)sender();

    num_first=ui->Resshow->text().toDouble();
    ui->Resshow->setText("");
    button->setChecked(true);
}
void MainWindow::on_pushButton_ac_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_devide->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->Resshow->setText("0");
}


void MainWindow::on_pushButton_equal_clicked()
{
    double labelNumber,num_second;
    QString new_label;
    num_second=ui->Resshow->text().toDouble();
    if(ui->pushButton_plus->isChecked()){
        labelNumber=num_first+num_second;
        new_label=QString::number(labelNumber,'g',12);
        ui->Resshow->setText(new_label);
        ui->pushButton_plus->setChecked(false);

    } else     if(ui->pushButton_minus->isChecked()){
        labelNumber=num_first-num_second;
        new_label=QString::number(labelNumber,'g',12);
        ui->Resshow->setText(new_label);
        ui->pushButton_plus->setChecked(false);

    } else     if(ui->pushButton_multiply->isChecked()){
        labelNumber=num_first*num_second;
        new_label=QString::number(labelNumber,'g',12);
        ui->Resshow->setText(new_label);
        ui->pushButton_plus->setChecked(false);

    } else     if(ui->pushButton_devide->isChecked()){
        if (num_second==0){
            ui->Resshow->setText("нельзя делить");
        } else{
        labelNumber=num_first/num_second;
        new_label=QString::number(labelNumber,'g',12);
        ui->Resshow->setText(new_label);}
        ui->pushButton_plus->setChecked(false);

    }
}

