#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
protected:
    void resizeEvent(QResizeEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
private slots:
    void launchCalculator();
    void launchNotes();
    void launchCows();
    void launchTic();
    void launchProgram(const QString &programPath);
private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
    void createTrayIcon();
};
#endif // MAINWINDOW_H
