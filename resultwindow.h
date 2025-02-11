#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>

class ResultWindow : public QWidget {
public:
    ResultWindow(const QString &result, QWidget *parent = nullptr);
};

#endif // RESULTWINDOW_H
