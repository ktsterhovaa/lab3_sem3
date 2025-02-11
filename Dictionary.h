#ifndef LR3_DICTIONARY_H
#define LR3_DICTIONARY_H

#include "HashTable.h"
#include <stdexcept>
#include <utility>

template<typename KeyType, typename ValueType>
class Dictionary {
private:
    THashTable<KeyType, ValueType> hashTable;

public:
    Dictionary(size_t capacity = 16) : hashTable(capacity) {}

    void add(const KeyType &key, const ValueType &value) {
        if (hashTable.contains(key)) {
            throw std::runtime_error("Key already exists");
        }
        hashTable.insert(key, value);
    }

    void remove(const KeyType &key) {
        hashTable.remove(key);
    }

    ValueType &get(const KeyType &key) {
        return hashTable[key];
    }

    const ValueType &get(const KeyType &key) const {
        return hashTable[key];
    }

    ValueType &operator[](const KeyType &key) {
        return hashTable[key];
    }

    const ValueType &operator[](const KeyType &key) const {
        return hashTable[key];
    }

    bool contains(const KeyType &key) {
        return hashTable.contains(key);
    }

    size_t size() const {
        return hashTable.size();
    }

    void clear() {
        hashTable.clear();
    }

    class Iterator {
    private:
        typename THashTable<KeyType, ValueType>::Iterator it;
    public:
        Iterator(typename THashTable<KeyType, ValueType>::Iterator iterator) : it(iterator) {}

        std::pair<KeyType, ValueType> operator*() {
            return {(*it).key_, (*it).value_};
        }

        Iterator &operator++() {
            ++it;
            return *this;
        }

        bool operator!=(const Iterator &other) const {
            return it != other.it;
        }
    };

    class ConstIterator {
    private:
        typename THashTable<KeyType, ValueType>::ConstIterator it;
    public:
        ConstIterator(typename THashTable<KeyType, ValueType>::ConstIterator iterator) : it(iterator) {}

        std::pair<const KeyType, const ValueType> operator*() const {
            return {(*it).key_, (*it).value_};
        }

        ConstIterator &operator++() {
            ++it;
            return *this;
        }

        bool operator!=(const ConstIterator &other) const {
            return it != other.it;
        }
    };

    Iterator begin() {
        return Iterator(hashTable.begin());
    }

    Iterator end() {
        return Iterator(hashTable.end());
    }

    ConstIterator begin() const {
        return ConstIterator(hashTable.begin());
    }

    ConstIterator end() const {
        return ConstIterator(hashTable.end());
    }
};

#endif //LR3_DICTIONARY_H
