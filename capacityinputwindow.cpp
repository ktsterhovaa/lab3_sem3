#include "CapacityInputWindow.h"
#include <QMessageBox>

CapacityInputWindow::CapacityInputWindow(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *capacityLabel = new QLabel("Enter capacity:");
    capacityInput = new QLineEdit(this);
    layout->addWidget(capacityLabel);
    layout->addWidget(capacityInput);

    QLabel *countLabel = new QLabel("Enater number of items:");
    countInput = new QLineEdit(this);
    layout->addWidget(countLabel);
    layout->addWidget(countInput);

    submitButton = new QPushButton("Submit", this);
    layout->addWidget(submitButton);

    connect(submitButton, &QPushButton::clicked, this, &CapacityInputWindow::onSubmit);
}

void CapacityInputWindow::onSubmit() {
    bool ok1, ok2;
    int capacity = capacityInput->text().toInt(&ok1);
    int count = countInput->text().toInt(&ok2);

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Ошибка ввода", "Пожалуйста, введите корректные значения.");
        return;
    }

    accept();
}

int CapacityInputWindow::getCapacity() const {
    return capacityInput->text().toInt();
}

int CapacityInputWindow::getItemCount() const {
    return countInput->text().toInt();
}
