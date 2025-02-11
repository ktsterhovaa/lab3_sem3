#ifndef ALPHABETINDEXINPUT_H
#define ALPHABETINDEXINPUT_H

#include <QDialog>

namespace Ui {
class AlphabetIndexInput;
}

class AlphabetIndexInput : public QDialog
{
    Q_OBJECT

public:
    explicit AlphabetIndexInput(QWidget *parent = nullptr);
    ~AlphabetIndexInput();

private:
    Ui::AlphabetIndexInput *ui;
};

#endif // ALPHABETINDEXINPUT_H
