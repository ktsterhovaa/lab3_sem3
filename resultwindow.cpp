#include "ResultWindow.h"

ResultWindow::ResultWindow(const QString &result, QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *resultLabel = new QLabel(result, this);
    layout->addWidget(resultLabel);
    setWindowTitle("Results");
    resize(300, 200);
}
