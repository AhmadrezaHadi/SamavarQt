#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bbvbLoginButton_clicked();

    void on_wrLoginButton_clicked();

    void on_ppLoginButton_clicked();

    void on_teamLoginButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
