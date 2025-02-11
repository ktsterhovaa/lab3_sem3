 #include "MostFrequent.h"
#include <stdexcept>
#include <fstream>

Dictionary<std::string, int> theMostFrequentSubsequences(const std::string &input, int lmin, int lmax) {
    Dictionary<std::string, int> result;
    for (int i = 0; i < input.length(); i++) {
        for (int j = lmin; j <= lmax; j++) {
            if (i + j <= input.length()) {
                std::string word = input.substr(i, j);
                if (result.contains(word)) {
                    result.get(word) += 1;
                } else {
                    result.add(word, 1);
                }
            }
        }
    }

    return result;
}

void FindingTheMostFrequentSubsequence(const std::string &input, int lmin, int lmax) {
    Dictionary<std::string, int> result = theMostFrequentSubsequences(input, lmin, lmax);
    std::string outputFilePath = "C:\\Users\\Katya\\CLionProjects\\lr3\\outputSequences.txt";

    std::ofstream outputFile(outputFilePath);
    if (!outputFile) {
        throw std::runtime_error("Не удалось открыть файл для записи.");
    }

    for (auto it = result.begin(); it != result.end(); ++it) {
        auto [key, value] = *it;
        outputFile << "Subsequence: " << key << ", Frequency: " << value << std::endl;
    }

    outputFile.close();
}
