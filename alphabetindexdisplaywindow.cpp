#include "AlphabetIndexDisplayWindow.h"
#include "TextDisplayWindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <sstream>

AlphabetIndexDisplayWindow::AlphabetIndexDisplayWindow(const std::map<std::string, std::vector<int>>& index, const std::string& text, QWidget *parent)
    : QDialog(parent), index(index), originalText(text) {

    QVBoxLayout *layout = new QVBoxLayout(this);
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);

    QString displayText;
    for (const auto& pair : index) {
        displayText += QString::fromStdString(pair.first) + ": ";
        for (int page : pair.second) {
            displayText += QString::number(page) + " ";
        }
        displayText += "\n";
    }

    textEdit->setPlainText(displayText);
    layout->addWidget(textEdit);

    QLineEdit *wordInput = new QLineEdit(this);
    wordInput->setPlaceholderText("Введите слово для поиска");
    layout->addWidget(wordInput);

    QPushButton *searchButton = new QPushButton("Найти страницу", this);
    layout->addWidget(searchButton);

    connect(searchButton, &QPushButton::clicked, [this, wordInput]() {
        std::string word = wordInput->text().toStdString();
        searchWord(word);
    });

    showTextButton = new QPushButton("Показать исходный текст", this);
    layout->addWidget(showTextButton);

    connect(showTextButton, &QPushButton::clicked, this, &AlphabetIndexDisplayWindow::showOriginalText);

    QPushButton *closeButton = new QPushButton("Закрыть", this);
    layout->addWidget(closeButton);
    connect(closeButton, &QPushButton::clicked, this, &AlphabetIndexDisplayWindow::accept);
}

void AlphabetIndexDisplayWindow::showOriginalText() {
    std::istringstream stream(originalText);
    std::string word;
    std::vector<std::string> pages;
    std::string currentPageText;
    size_t wordCount = 0;

    const size_t wordsPerPage = 100;

    while (stream >> word) {
        if (wordCount < wordsPerPage) {
            if (!currentPageText.empty()) {
                currentPageText += " ";
            }
            currentPageText += word;
            wordCount++;
        } else {
            pages.push_back(currentPageText);
            currentPageText = word;
            wordCount = 1;
        }
    }

    if (!currentPageText.empty()) {
        pages.push_back(currentPageText);
    }

    TextDisplayWindow *textDisplayWindow = new TextDisplayWindow(pages, this);
    textDisplayWindow->exec();
}

void AlphabetIndexDisplayWindow::searchWord(const std::string &word) {
    std::string lowerWord = word;
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

    auto it = index.find(lowerWord);
    if (it != index.end()) {
        const std::vector<int>& pages = it->second;
        if (!pages.empty()) {

            QString pageNumbers;
            for (int page : pages) {
                pageNumbers += QString::number(page) + " ";
            }

            QMessageBox::information(this, "Найдено", QString("Слово \"%1\" встречается на страницах: %2").arg(QString::fromStdString(lowerWord)).arg(pageNumbers));
        } else {
            QMessageBox::information(this, "Не найдено", QString("Слово \"%1\" не найдено.").arg(QString::fromStdString(lowerWord)));
        }
    } else {
        QMessageBox::warning(this, "Не найдено", QString("Слово \"%1\" не найдено в индексе.").arg(QString::fromStdString(lowerWord)));
    }
}
