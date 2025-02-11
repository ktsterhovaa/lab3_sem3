#include "alphabetindex.h"


Dictionary<std::string, std::vector<int>> buildAlphabeticalIndexFromFile(
    const std::string &inputFilePath,
    int pageSize,
    const std::string &outputFilePath, int rowSize) {

    Dictionary<std::string, std::vector<int>> index;

    // Чтение текста из входного файла
    std::ifstream inputFile(inputFilePath);
    if (!inputFile) {
        throw std::runtime_error("Не удалось открыть входной файл.");
    }

    std::ostringstream textBuffer;
    textBuffer << inputFile.rdbuf();
    inputFile.close();
    std::string inputText = textBuffer.str();

    // Замена табуляций и переносов строк на пробелы и приведение к нижнему регистру
    for (char &ch : inputText) {
        if (ch == '\n' || ch == '\t' || !(std::isalnum(static_cast<unsigned char>(ch)))) {
            ch = ' ';
        }
        else {
            ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        }
    }

    Vector<Row> rows = lexer(inputText, rowSize);
    Vector<Page> pages = PageMaker(rows, pageSize);
    Book item(pages);

    std::string bookOutputFilePath = "C:\\Users\\Katya\\CLionProjects\\lr3\\output_book.txt"; // Изменено имя файла
    std::ofstream bookOutputFile(bookOutputFilePath);
    if (!bookOutputFile) {
        throw std::runtime_error("Не удалось открыть файл для записи книги.");
    }

    bookOutputFile << "Book:\n";
    for (int i = 0; i < item.GetPageCount(); i++) {
        bookOutputFile << "Page " << i + 1 << ":\n";

        Page page = item.GetPage(i);

        for (int j = 0; j < page.getPageSize(); j++) {
            bookOutputFile << page.getRow(j).get() << '\n';
        }
        bookOutputFile << '\n';
    }

    bookOutputFile.close();

    // Индексирование слов
    for (int NumPage = 0; NumPage < item.GetPageCount(); NumPage++) {
        Page page = item.GetPage(NumPage);
        for (int NumRow = 0; NumRow < page.getPageSize(); NumRow++) {
            Row row = page.getRow(NumRow);
            std::istringstream rowStream(row.get());
            std::string word;
            while(rowStream >> word) {
                // Приводим слово к нижнему регистру и удаляем лишние символы
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
                               return !std::isalnum(static_cast<unsigned char>(c)); // Оставляем только буквы и цифры
                           }), word.end());

                // Логируем текущее слово и номер страницы
                std::cout << "Обрабатываем слово: " << word << " на странице: " << NumPage + 1 << std::endl;

                if (word.empty()) continue; // Пропускаем пустые слова

                // Проверяем, существует ли слово в индексе
                if(index.contains(word)) {
                    // Получаем ссылку на вектор страниц
                    std::vector<int> &pages = index.get(word);
                    // Проверяем, не добавлена ли уже эта страница
                    if (std::find(pages.begin(), pages.end(), NumPage + 1) == pages.end()) {
                        pages.push_back(NumPage + 1); // Добавляем номер страницы
                    }
                }
                else {
                    index.add(word, {NumPage + 1}); // Добавляем новое слово с номером страницы
                }
            }
        }
    }

    // Запись индекса в выходной файл
    std::ofstream outputFile(outputFilePath);
    if (!outputFile) {
        throw std::runtime_error("Не удалось открыть выходной файл.");
    }

    for (auto it = index.begin(); it != index.end(); ++it) {
        const std::pair<std::string, std::vector<int>> &entry = *it;
        outputFile << entry.first << ": ";
        for (size_t i = 0; i < entry.second.size(); ++i) {
            outputFile << entry.second[i];
            if (i < entry.second.size() - 1) {
                outputFile << ", ";
            }
        }
        outputFile << std::endl;
    }

    outputFile.close();
    return index;
}

void StartBuildingAlphabetIndex(std::string fileName, int pageSize, int rowSize)
{
    std::string RealFileName = "C:\\Users\\Katya\\CLionProjects\\lr3\\input.txt\\" + fileName; // Добавлен обратный слэш
    std::string outputFilePath = "C:\\Users\\Katya\\CLionProjects\\lr3\\output.txt";

    buildAlphabeticalIndexFromFile(RealFileName, pageSize, outputFilePath, rowSize);
}


