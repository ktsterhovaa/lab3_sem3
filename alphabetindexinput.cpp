#include "alphabetindexinput.h"
#include "ui_alphabetindexinput.h"

AlphabetIndexInput::AlphabetIndexInput(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AlphabetIndexInput)
{
    ui->setupUi(this);
}

AlphabetIndexInput::~AlphabetIndexInput()
{
    delete ui;
}
