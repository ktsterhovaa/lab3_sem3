#include "ItemInputWindow.h"
#include <QMessageBox>

ItemInputWindow::ItemInputWindow(int itemCount, int capacity, QWidget *parent)
    : QDialog(parent), itemCount(itemCount), capacity(capacity), currentItemCount(0)
{
    layout = new QVBoxLayout(this);

    weightInput = new QLineEdit(this);
    valueInput = new QLineEdit(this);
    layout->addWidget(new QLabel("Enter weight:"));
    layout->addWidget(weightInput);
    layout->addWidget(new QLabel("Enter value:"));
    layout->addWidget(valueInput);

    addButton = new QPushButton("Add item", this);

    layout->addWidget(addButton);


    itemCountLabel = new QLabel("Number of items entered: 0 of " + QString::number(itemCount), this);
    layout->addWidget(itemCountLabel);

    connect(addButton, &QPushButton::clicked, this, &ItemInputWindow::onAddItem);

}

void ItemInputWindow::onAddItem() {
    bool ok1, ok2;
    int weight = weightInput->text().toInt(&ok1);
    int value = valueInput->text().toInt(&ok2);

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Ошибка ввода", "Пожалуйста, введите корректные значения для веса и ценности.");
        return;
    }

    items.append(Item(weight, value));
    currentItemCount++;

    weightInput->clear();
    valueInput->clear();
    itemCountLabel->setText("Entered items: " + QString::number(currentItemCount) + " of " + QString::number(itemCount));
    if (currentItemCount >= itemCount) {
        accept();
    }
}


QVector<Item> ItemInputWindow::getItems() const {
    return items;
}
void ItemInputWindow::onSubmit() {

}
