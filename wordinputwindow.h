#ifndef WORDINPUTWINDOW_H
#define WORDINPUTWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class WordInputWindow : public QDialog {
    Q_OBJECT

public:
    explicit WordInputWindow(QWidget *parent = nullptr);

    QString getWord() const;

private slots:
    void onAccept();

private:
    QLineEdit *wordEdit;
};

#endif // WORDINPUTWINDOW_H
