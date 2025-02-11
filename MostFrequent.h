#ifndef LR3_MOSTFREQUENT_H
#define LR3_MOSTFREQUENT_H
#include "Dictionary.h"
#include <fstream>

Dictionary<std::string, int> theMostFrequentSubsequences(const std::string &input, int lmin, int lmax);

void FindingTheMostFrequentSubsequence(const std::string &input, int lmin, int lmax);

#endif //LR3_MOSTFREQUENT_H
