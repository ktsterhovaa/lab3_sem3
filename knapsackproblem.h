#ifndef LR3_KNAPSACKPROBLEM_H
#define LR3_KNAPSACKPROBLEM_H

#include "RBTree.h"
#include <vector>
#include <algorithm>
#include <tuple>

struct Item {
    int weight;
    int value;
    Item(int weight_, int value_)
        : weight(weight_), value(value_) {}
    double valuePerWeight() const {
        return static_cast<double>(value) / weight;
    }
};

struct State {
    int currentWeight;
    int currentValue;
    std::vector<int> usedItems;

    bool operator<(const State& other) const {
        if (currentWeight != other.currentWeight)
            return currentWeight < other.currentWeight;
        return currentValue < other.currentValue;
    }

    bool operator==(const State& other) const {
        return currentWeight == other.currentWeight &&
               currentValue == other.currentValue &&
               usedItems == other.usedItems;
    }
};

class KnapsackSolver {
private:
    int capacity;
    std::vector<Item> items;
    RedBlackTree<State, int> stateTree;
    int maxValue;
    std::vector<int> bestUsedItems;

    void dfs(State state) {
        if (state.currentWeight > capacity) return;
        if (state.currentValue > maxValue) {
            maxValue = state.currentValue;
            bestUsedItems = state.usedItems;
        }

        //добавить уникальное состояние в дерево
        if (stateTree.find(state) != stateTree.getNil()) return;
        stateTree.insert(state, state.currentValue);

        //добавление каждого предмета
        for (int i = 0; i < items.size(); ++i) {
            if (std::find(state.usedItems.begin(), state.usedItems.end(), i) != state.usedItems.end())
                continue;

            State nextState = state;
            nextState.currentWeight += items[i].weight;
            nextState.currentValue += items[i].value;
            nextState.usedItems.push_back(i);
            dfs(nextState);
        }
    }

public:
    KnapsackSolver(int capacity, const std::vector<Item>& items)
        : capacity(capacity), items(items), maxValue(0) {
        //предметы по ценности на единицу веса
        std::sort(this->items.begin(), this->items.end(), [](const Item& a, const Item& b) {
            return a.valuePerWeight() > b.valuePerWeight();
        });
    }
    std::tuple<int, std::vector<int>> solve() {
        State initialState = {0, 0, {}};
        dfs(initialState);
        return {maxValue, bestUsedItems};
    }
};

std::tuple<int, std::vector<int>> KnapsackProblemSolving(std::vector<Item> items, int capacity);

#endif //LR3_KNAPSACKPROBLEM_H
