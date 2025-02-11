#ifndef ITEMINPUTWINDOW_H
#define ITEMINPUTWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>
#include "KnapsackProblem.h"

class ItemInputWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ItemInputWindow(int itemCount, int capacity, QWidget *parent = nullptr);
    QVector<Item> getItems() const;

private slots:
    void onAddItem();
    void onSubmit();

private:
    QVBoxLayout *layout;
    QVector<Item> items;
    QLineEdit *weightInput;
    QLineEdit *valueInput;
    QPushButton *addButton;
    QLabel *itemCountLabel;
    int itemCount;
    int currentItemCount;
    int capacity;
};

#endif // ITEMINPUTWINDOW_H
