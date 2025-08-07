#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QpushButton>
#include<QTextStream>
#include<QMessageBox>
#include<QByteArray>
#include<QProcess>
#include<QAction>
#include<QString>
#include<QFile>
#include<QDir>

//c std lib
#include<cstdlib>

//#include<>//c++ std lib

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void combochanged(int);
    void entry(bool);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
