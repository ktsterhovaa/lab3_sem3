#include "KnapsackProblem.h"

std::tuple<int, std::vector<int>> KnapsackProblemSolving(std::vector<Item> items, int capacity) {
    KnapsackSolver solver(capacity, items);
    return solver.solve();
}

