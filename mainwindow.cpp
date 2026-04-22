#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIcon>
#include <QGridLayout>
#include <QPushButton>
#include <QResizeEvent>
#include <QMenu>
#include <QMessageBox>
#include <QProcess>
#include <QFile>
#include <QCoreApplication>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createTrayIcon();

    ui->calculator->setText("");
    ui->notes->setText("");
    ui->cows->setText("");
    ui->tic->setText("");

    ui->calculator->setIcon(QIcon(":/icons/cal.jpg"));
    ui->notes->setIcon(QIcon(":/icons/not.jpg"));
    ui->cows->setIcon(QIcon(":/icons/cow.jpg"));
    ui->tic->setIcon(QIcon(":/icons/tic.jpg"));

    QList<QPushButton*> buttons = {ui->calculator, ui->notes, ui->cows, ui->tic};
    for (QPushButton *btn : buttons) {
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        btn->setMinimumSize(100, 100);
        btn->setMaximumSize(QSize(16777215, 16777215));
        //btn->setIconSize(QSize(400, 400));
    }

    QWidget *central = centralWidget();
    QGridLayout *layout = qobject_cast<QGridLayout*>(central->layout());

    if (layout) {
        layout->setRowStretch(0, 1);
        layout->setRowStretch(1, 1);
        layout->setColumnStretch(0, 1);
        layout->setColumnStretch(1, 1);
        layout->setContentsMargins(20, 20, 20, 20);
        layout->setSpacing(20);
    } else {
        layout = new QGridLayout(central);
        layout->addWidget(ui->calculator, 0, 0);
        layout->addWidget(ui->notes, 0, 1);
        layout->addWidget(ui->cows, 1, 0);
        layout->addWidget(ui->tic, 1, 1);
        layout->setRowStretch(0, 1);
        layout->setRowStretch(1, 1);
        layout->setColumnStretch(0, 1);
        layout->setColumnStretch(1, 1);
        layout->setContentsMargins(20, 20, 20, 20);
        layout->setSpacing(20);
    }

    central->setMaximumSize(QSize(16777215, 16777215));
    setMaximumSize(QSize(16777215, 16777215));

    setWindowTitle("Лаунчер");
    setMinimumSize(400, 400);
    setStyleSheet("QMainWindow { background-color: #1a1a2e; }");

    connect(ui->calculator, &QPushButton::clicked, this, &MainWindow::launchCalculator);
    connect(ui->notes, &QPushButton::clicked, this, &MainWindow::launchNotes);
    connect(ui->cows, &QPushButton::clicked, this, &MainWindow::launchCows);
    connect(ui->tic, &QPushButton::clicked, this, &MainWindow::launchTic);

}
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    if (!ui->calculator) return;

    int btnWidth = ui->calculator->width();
    int btnHeight = ui->calculator->height();
    int iconSize = qMin(btnWidth, btnHeight);

    QList<QPushButton*> buttons = {ui->calculator, ui->notes, ui->cows, ui->tic};
    for (QPushButton *btn : buttons) {
        btn->setIconSize(QSize(iconSize, iconSize));
    }
}
void MainWindow::createTrayIcon()
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/icons/cal.jpg"));

    QMenu *trayMenu = new QMenu(this);
    QAction *showAction = trayMenu->addAction("Показать");
    QAction *quitAction = trayMenu->addAction("Выйти");

    trayIcon->setContextMenu(trayMenu);

    connect(showAction, &QAction::triggered, this, &QWidget::show);
    connect(quitAction, &QAction::triggered, this, &QWidget::close);

    trayIcon->show();
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible()) {
        hide();
        event->ignore();
        trayIcon->showMessage("Лаунчер", "Программа свернута в трей",
                              QSystemTrayIcon::Information, 2000);
    } else {
        event->accept();
    }
}
void MainWindow::launchProgram(const QString &programPath)
{
    QProcess *process = new QProcess(this);

    if (!QFile::exists(programPath)) {
        QMessageBox::warning(this, "Ошибка",
                             "Модуль не найден:\n" + programPath);
        delete process;
        return;
    }

    process->start(programPath);
    connect(process, &QProcess::finished, process, &QProcess::deleteLater);
}

void MainWindow::launchCalculator()
{
    QString appPath = QCoreApplication::applicationDirPath();
    launchProgram(appPath + "/modules/Calculator.exe");
}

void MainWindow::launchNotes()
{
    QString appPath = QCoreApplication::applicationDirPath();
    launchProgram(appPath + "/modules/Notes.exe");
}

void MainWindow::launchCows()
{
    QString appPath = QCoreApplication::applicationDirPath();
    launchProgram(appPath + "/modules/CowsGame.exe");
}

void MainWindow::launchTic()
{
    QString appPath = QCoreApplication::applicationDirPath();
    launchProgram(appPath + "/modules/TicTacToe.exe");
}

MainWindow::~MainWindow()
{
    delete ui;
}