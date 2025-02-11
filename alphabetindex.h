#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Dictionary.h"

class AlphabetIndex {
private:
    Dictionary<int, std::string> pages;
    Dictionary<std::string, std::vector<int>> index;

    void splitIntoPages(const std::string &text, size_t pageSize, bool isWordSize) {
        std::istringstream stream(text);
        std::string word;
        std::vector<std::string> words;

        while (stream >> word) {
            words.push_back(word);
        }

        size_t pageCount = 0;
        size_t currentSize = 0;
        std::string currentPage;

        for (const auto &w : words) {
            size_t wordSize = w.length();
            if (isWordSize) {

                if (currentSize < pageSize) {
                    if (currentSize > 0) {
                        currentPage += " ";
                    }
                    currentPage += w;
                    currentSize++;
                } else {
                    pages.add(pageCount++, currentPage);
                    currentPage = w;
                    currentSize = 1;
                }
            } else {

                if (currentSize + wordSize + (currentSize > 0 ? 1 : 0) <= pageSize) {
                    if (currentSize > 0) {
                        currentPage += " ";
                    }
                    currentPage += w;
                    currentSize += wordSize + (currentSize > 0 ? 1 : 0);
                } else {
                    pages.add(pageCount++, currentPage);
                    currentPage = w;
                    currentSize = wordSize;
                }
            }
        }


        if (!currentPage.empty()) {
            pages.add(pageCount, currentPage);
        }
    }

    void buildIndex() {
        for (size_t i = 0; i < pages.size(); ++i) {
            std::string pageContent = pages.get(i);
            std::istringstream stream(pageContent);
            std::string word;

            while (stream >> word) {

                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                if (!index.contains(word)) {
                    index.add(word, std::vector<int>());
                }

                std::vector<int>& pageNumbers = index.get(word);
                if (std::find(pageNumbers.begin(), pageNumbers.end(), i + 1) == pageNumbers.end()) {
                    pageNumbers.push_back(i + 1);
                }
            }
        }
    }

public:
    AlphabetIndex(const std::string &filename, size_t pageSize, bool isWordSize) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file");
        }

        std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        splitIntoPages(text, pageSize, isWordSize);
        buildIndex();
    }

    void printIndex() const {
        for (auto it = index.begin(); it != index.end(); ++it) {
            std::cout << (*it).first << ": ";
            for (const auto &page : (*it).second) {
                std::cout << page << " ";
            }
            std::cout << std::endl;
        }
    }

    std::map<std::string, std::vector<int>> getIndex() const {
        std::map<std::string, std::vector<int>> result;
        for (auto it = index.begin(); it != index.end(); ++it) {
            const auto& pair = *it;
            result[pair.first] = pair.second;
        }
        return result;
    }

    void saveIndexToFile(const std::string &outputFileName) const {
        std::ofstream outFile(outputFileName);
        if (!outFile.is_open()) {
            throw std::runtime_error("Could not open output file");
        }

        for (const auto &pair : index) {
            outFile << pair.first << ": ";
            for (int page : pair.second) {
                outFile << page << " ";
            }
            outFile << std::endl;
        }

        outFile.close();
    }

};
