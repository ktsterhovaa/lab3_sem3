#ifndef CAPACITYINPUTWINDOW_H
#define CAPACITYINPUTWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class CapacityInputWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CapacityInputWindow(QWidget *parent = nullptr);
    int getCapacity() const;
    int getItemCount() const;

private slots:
    void onSubmit();

private:
    QLineEdit *capacityInput;
    QLineEdit *countInput;
    QPushButton *submitButton;
};

#endif // CAPACITYINPUTWINDOW_H

