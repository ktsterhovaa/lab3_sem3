#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTextEdit>
#include <QMainWindow>
#include "CapacityInputWindow.h"
#include "ItemInputWindow.h"
#include "alphabetindexinputwindow.h"
#include "mostfrequentwindow.h"
#include "alphabetindexdisplaywindow.h"

#include "Dictionary.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_knapsackProblemButton_clicked();


    void on_mostFrequentSubsequenceButton_clicked();


    void on_alphabetIndexButton_clicked();

private:
    Ui::MainWindow *ui;

    QTextEdit *outputTextEdit;


};
#endif // MAINWINDOW_H
