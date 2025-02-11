#include "MostFrequentWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <stdexcept>

MostFrequentWindow::MostFrequentWindow(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *sequenceLabel = new QLabel("Enter your sequence:", this);
    layout->addWidget(sequenceLabel);
    sequenceInput = new QLineEdit(this);
    layout->addWidget(sequenceInput);

    QLabel *minLengthLabel = new QLabel("Enter minimal length:", this);
    layout->addWidget(minLengthLabel);
    minLengthInput = new QLineEdit(this);
    layout->addWidget(minLengthInput);

    QLabel *maxLengthLabel = new QLabel("Enter maximum length:", this);
    layout->addWidget(maxLengthLabel);
    maxLengthInput = new QLineEdit(this);
    layout->addWidget(maxLengthInput);

    QPushButton *submitButton = new QPushButton("Submit", this);
    layout->addWidget(submitButton);

    connect(submitButton, &QPushButton::clicked, this, &MostFrequentWindow::onSubmit);
}

void MostFrequentWindow::onSubmit() {
    QString sequence = sequenceInput->text();
    int minLength = minLengthInput->text().toInt();
    int maxLength = maxLengthInput->text().toInt();

    findMostFrequentSubsequence(sequence.toStdString(), minLength, maxLength);
    close();
}

void MostFrequentWindow::findMostFrequentSubsequence(const std::string &sequence, int minLength, int maxLength) {
    Dictionary<std::string, int> result = theMostFrequentSubsequences(sequence, minLength, maxLength);
    QString outputFilePath = "C:\\Users\\Katya\\CLionProjects\\lr3\\outputSequences.txt";
    std::vector<std::pair<std::string, int>> subsequences;

    for (auto it = result.begin(); it != result.end(); ++it) {
        auto [key, value] = *it;
        subsequences.emplace_back(key, value);
    }

    std::sort(subsequences.begin(), subsequences.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });

    QFile file(outputFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const auto &pair : subsequences) {
            out << "Subsequence: " << QString::fromStdString(pair.first) << ", Frequency: " << pair.second << "\n";
        }
        file.close();
    } else {
        throw std::runtime_error("Не удалось открыть файл для записи.");
    }
}

Dictionary<std::string, int> MostFrequentWindow::theMostFrequentSubsequences(const std::string &input, int lmin, int lmax) {
    Dictionary<std::string, int> result;

    for (int i = 0; i < input.length(); i++) {
        for (int j = lmin; j <= lmax; j++) {
            if (i + j <= input.length()) {
                std::string word = input.substr(i, j);
                if (result.contains(word)) {
                    result.get(word) += 1;
                } else {
                    result.add(word, 1);
                }
            }
        }
    }

    return result;
}
