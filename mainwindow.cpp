#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_knapsackProblemButton_clicked()
{
    hide();
    CapacityInputWindow capacityDialog(this);

    if (capacityDialog.exec() == QDialog::Accepted) {
        int capacity = capacityDialog.getCapacity();
        int itemCount = capacityDialog.getItemCount();

        ItemInputWindow itemDialog(itemCount, capacity, this);
        if (itemDialog.exec() == QDialog::Accepted) {
            QVector<Item> items = itemDialog.getItems();
            std::vector<Item> stdItems(items.begin(), items.end());
            auto [maxValue, usedItems] = KnapsackProblemSolving(stdItems, capacity);

            QString usedItemsStr = "Used items: ";
            for (int index : usedItems) {
                usedItemsStr += QString("Item %1 (Weight: %2, Value: %3); ")
                .arg(index + 1)
                    .arg(items[index].weight)
                    .arg(items[index].value);
            }

            QMessageBox::information(this, "Result",
                                     "Max value: " + QString::number(maxValue) + "\n" + usedItemsStr);
        }
    }
}






void MainWindow::on_mostFrequentSubsequenceButton_clicked() {
    hide();
    MostFrequentWindow *window = new MostFrequentWindow();
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();
}





void MainWindow::on_alphabetIndexButton_clicked() {
    AlphabetIndexInputWindow *inputWindow = new AlphabetIndexInputWindow(this);


    if (inputWindow->exec() == QDialog::Accepted) {

        QString fileName = "C:\\Users\\Katya\\CLionProjects\\lr3\\input.txt";
        size_t pageSize = inputWindow->getPageSize();

        try {
            AlphabetIndex index(fileName.toStdString(), pageSize, true);

            std::ifstream file(fileName.toStdString());
            if (!file.is_open()) {
                throw std::runtime_error("Could not open file");
            }
            std::string originalText((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

            std::string outputFileName = "C:\\Users\\Katya\\CLionProjects\\lr3\\output.txt";
            index.saveIndexToFile(outputFileName);

            AlphabetIndexDisplayWindow *displayWindow = new AlphabetIndexDisplayWindow(index.getIndex(), originalText, this);
            displayWindow->exec();
        } catch (const std::exception &e) {

            QMessageBox::warning(this, "Ошибка", e.what());
        }
    }

    delete inputWindow;
}
