#ifndef TEXTDISPLAYWINDOW_H
#define TEXTDISPLAYWINDOW_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <vector>
#include <string>

class TextDisplayWindow : public QDialog {
    Q_OBJECT

public:
    TextDisplayWindow(const std::vector<std::string>& pages, QWidget *parent = nullptr);

private:
    void showPage(int page);
    void nextPage();
    void previousPage();

    QTextEdit *textEdit;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QLabel *pageLabel;
    std::vector<std::string> pages;
    int currentPage;
    int totalPages;
};

#endif // TEXTDISPLAYWINDOW_H
