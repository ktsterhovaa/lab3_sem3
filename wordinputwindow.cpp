#include "WordInputWindow.h"

WordInputWindow::WordInputWindow(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Введите слово:"));
    wordEdit = new QLineEdit(this);
    layout->addWidget(wordEdit);

    QPushButton *okButton = new QPushButton("OK", this);
    connect(okButton, &QPushButton::clicked, this, &WordInputWindow::onAccept);
    layout->addWidget(okButton);

    setLayout(layout);
}

QString WordInputWindow::getWord() const {
    return wordEdit->text();
}

void WordInputWindow::onAccept() {
    accept();
}
