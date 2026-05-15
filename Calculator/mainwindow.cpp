#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    num_first = 0;
    waitingForOperand = false;

    connect(ui->pushButton_0, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::digits_numbers);

    connect(ui->pushButton_posneg, &QPushButton::clicked, this, &MainWindow::operations);
    connect(ui->pushButton_percent, &QPushButton::clicked, this, &MainWindow::operations);

    connect(ui->pushButton_plus, &QPushButton::clicked, this, &MainWindow::math_operations);
    connect(ui->pushButton_minus, &QPushButton::clicked, this, &MainWindow::math_operations);
    connect(ui->pushButton_multiply, &QPushButton::clicked, this, &MainWindow::math_operations);
    connect(ui->pushButton_devide, &QPushButton::clicked, this, &MainWindow::math_operations);

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_devide->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton*)sender();

    if (waitingForOperand) {
        ui->Resshow->setText(button->text());
        waitingForOperand = false;
    } else {
        if (ui->Resshow->text() == "0") {
            ui->Resshow->setText(button->text());
        } else {
            ui->Resshow->setText(ui->Resshow->text() + button->text());
        }
    }
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (waitingForOperand) {
        ui->Resshow->setText("0.");
        waitingForOperand = false;
        return;
    }
    if (!(ui->Resshow->text().contains('.'))) {
        ui->Resshow->setText(ui->Resshow->text() + ".");
    }
}

void MainWindow::operations()
{
    double all_numbers = ui->Resshow->text().toDouble();
    QPushButton *button = (QPushButton*)sender();

    if (button->text() == "+/-") {
        all_numbers *= -1;
    } else if (button->text() == "%") {
        all_numbers *= 0.01;
    }
    ui->Resshow->setText(QString::number(all_numbers, 'g', 12));
}

void MainWindow::math_operations()
{
    QPushButton *clickedButton = (QPushButton*)sender();
    QString newOperation = clickedButton->text();

    double currentValue = ui->Resshow->text().toDouble();

    if (!pendingOperation.isEmpty() && !waitingForOperand) {

        if (pendingOperation == "+") {
            num_first += currentValue;
        }
        else if (pendingOperation == "-") {
            num_first -= currentValue;
        }
        else if (pendingOperation == "x") {
            num_first *= currentValue;
        }
        else if (pendingOperation == "/") {

            if (currentValue == 0) {
                ui->Resshow->setText("Ошибка");
                pendingOperation.clear();
                return;
            }

            num_first /= currentValue;
        }

        ui->Resshow->setText(QString::number(num_first, 'g', 12));
    }
    else {
        num_first = currentValue;
    }

    pendingOperation = newOperation;
    waitingForOperand = true;
}

void MainWindow::on_pushButton_equal_clicked()
{
    calculateResult();


    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_devide->setChecked(false);

    waitingForOperand = true;
}

void MainWindow::on_pushButton_ac_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_devide->setChecked(false);
    ui->Resshow->setText("0");
    num_first = 0;
    waitingForOperand = false;
    pendingOperation.clear();
}

void MainWindow::calculateResult()
{
    double num_second = ui->Resshow->text().toDouble();

    if (pendingOperation == "+") {
        num_first += num_second;
    }
    else if (pendingOperation == "-") {
        num_first -= num_second;
    }
    else if (pendingOperation == "x") {
        num_first *= num_second;
    }
    else if (pendingOperation == "/") {

        if (num_second == 0) {
            ui->Resshow->setText("Ошибка");
            pendingOperation.clear();
            return;
        }

        num_first /= num_second;
    }

    ui->Resshow->setText(QString::number(num_first, 'g', 12));

    pendingOperation.clear();
}