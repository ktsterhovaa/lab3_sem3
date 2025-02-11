#include "AlphabetIndexInputWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDialog>

AlphabetIndexInputWindow::AlphabetIndexInputWindow(QWidget *parent) : QDialog(parent) {

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Введите имя файла и размер страницы:", this);
    layout->addWidget(label);

    fileNameInput = new QLineEdit(this);
    fileNameInput->setPlaceholderText("Имя файла");
    layout->addWidget(fileNameInput);

    pageSizeInput = new QLineEdit(this);
    pageSizeInput->setPlaceholderText("Размер страницы");
    layout->addWidget(pageSizeInput);

    QPushButton *confirmButton = new QPushButton("Подтвердить", this);
    layout->addWidget(confirmButton);

    connect(confirmButton, &QPushButton::clicked, this, &AlphabetIndexInputWindow::onConfirm);
}

QString AlphabetIndexInputWindow::getFileName() const {
    return fileNameInput->text();
}

size_t AlphabetIndexInputWindow::getPageSize() const {
    return pageSizeInput->text().toULong();
}

void AlphabetIndexInputWindow::onConfirm() {
    accept();
}
