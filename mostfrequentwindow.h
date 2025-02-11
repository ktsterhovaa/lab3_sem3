#ifndef MOSTFREQUENTWINDOW_H
#define MOSTFREQUENTWINDOW_H
#include "MostFrequent.h"
#include <QWidget>
#include <QLineEdit>
#include "ResultWindow.h"

class MostFrequentWindow : public QWidget {
    Q_OBJECT

public:
    MostFrequentWindow(QWidget *parent = nullptr);

private slots:
    void onSubmit();

private:
    QLineEdit *sequenceInput;
    QLineEdit *minLengthInput;
    QLineEdit *maxLengthInput;

    void findMostFrequentSubsequence(const std::string &sequence, int minLength, int maxLength);
    Dictionary<std::string, int> theMostFrequentSubsequences(const std::string &input, int lmin, int lmax);
};

#endif // MOSTFREQUENTWINDOW_H
