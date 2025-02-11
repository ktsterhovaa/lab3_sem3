#ifndef ALPHABETINDEXDISPLAYWINDOW_H
#define ALPHABETINDEXDISPLAYWINDOW_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <map>
#include <vector>
#include <string>

class AlphabetIndexDisplayWindow : public QDialog {
    Q_OBJECT

public:

    AlphabetIndexDisplayWindow(const std::map<std::string, std::vector<int>>& index, const std::string& text, QWidget *parent = nullptr);

private:
    QTextEdit *textEdit;
    QPushButton *showTextButton;
    QLineEdit *wordInput;
    std::map<std::string, std::vector<int>> index;
    std::string originalText;


    void showOriginalText();

    void searchWord(const std::string &word);
};

#endif // ALPHABETINDEXDISPLAYWINDOW_H
