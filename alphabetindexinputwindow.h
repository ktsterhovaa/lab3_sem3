#ifndef ALPHABETINDEXINPUTWINDOW_H
#define ALPHABETINDEXINPUTWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include "alphabetindex.h"

class AlphabetIndexInputWindow : public QDialog {
    Q_OBJECT

public:

    explicit AlphabetIndexInputWindow(QWidget *parent = nullptr);


    QString getFileName() const;


    size_t getPageSize() const;

private slots:

    void onConfirm();

private:

    QLineEdit *fileNameInput;
    QLineEdit *pageSizeInput;
};

#endif // ALPHABETINDEXINPUTWINDOW_H
