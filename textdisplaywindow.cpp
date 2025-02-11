#include "TextDisplayWindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

TextDisplayWindow::TextDisplayWindow(const std::vector<std::string>& pages, QWidget *parent)
    : QDialog(parent), pages(pages), currentPage(0) {

    totalPages = pages.size();

    QVBoxLayout *layout = new QVBoxLayout(this);
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    layout->addWidget(textEdit);

    pageLabel = new QLabel(this);
    layout->addWidget(pageLabel);

    prevButton = new QPushButton("Предыдущая страница", this);
    nextButton = new QPushButton("Следующая страница", this);
    layout->addWidget(prevButton);
    layout->addWidget(nextButton);

    connect(prevButton, &QPushButton::clicked, this, &TextDisplayWindow::previousPage);
    connect(nextButton, &QPushButton::clicked, this, &TextDisplayWindow::nextPage);

    showPage(currentPage);
}

void TextDisplayWindow::showPage(int page) {
    if (page < 0 || page >= totalPages) return;
    currentPage = page;
    textEdit->setPlainText(QString::fromStdString(pages[currentPage]));

    prevButton->setEnabled(currentPage > 0);
    nextButton->setEnabled(currentPage < totalPages - 1);

    pageLabel->setText(QString("Страница %1 из %2").arg(currentPage + 1).arg(totalPages));
}

void TextDisplayWindow::nextPage() {
    if (currentPage < totalPages - 1) {
        showPage(currentPage + 1);
    }
}

void TextDisplayWindow::previousPage() {
    if (currentPage > 0) {
        showPage(currentPage - 1);
    }
}
