#pragma once
#include <iostream>

template<typename T>
class SequentialContainer {
public:
    SequentialContainer();
    explicit SequentialContainer(int len);
    ~SequentialContainer();
    void push_back(T value);
    void remove(int index);
    void insert(int index, T value);
    void print();
    void print_length();

private:
    int length_;
    T* data_;
};

template <typename T>
SequentialContainer<T>::SequentialContainer() {
    length_ = 0;
    data_ = nullptr;
}

template <typename T>
SequentialContainer<T>::SequentialContainer(int len) {
    length_ = len;
    data_ = new T[len]();
}

template <typename T>
SequentialContainer<T>::~SequentialContainer() {
    delete[] data_;
}

template <typename T>
void SequentialContainer<T>::push_back(T value) {
    T* newData = new T[length_ + 1];
    for (int i = 0; i < length_; i++) {
        newData[i] = data_[i];
    }
    newData[length_] = value;
    delete[] data_;
    data_ = newData;
    length_++;
}

template<typename T>
void SequentialContainer<T>::remove(int index) {
    if (index < 0 || index >= length_) {
        std::cout << "Index is out of bounds" << std::endl;
        return;
    }
    T* newData = new T[length_ - 1];
    int j = 0;
    for (int i = 0; i <= length_; i++) {
        if (i == index)
            i++;
        newData[j] = data_[i];
        j++;
    }
    delete[] data_;
    data_ = newData;
    length_--;
}

template<typename T>
void SequentialContainer<T>::insert(int index, T value) {
    T* newData = new T[length_ + 1];
    int j = 0;
    for (int i = 0; i < length_; i++) {
        if (i == index)
            j++;
        newData[j] = data_[i];
        if (j != length_)
            j++;
    }
    newData[index] = value;
    // 1 2 3   4 5 6 7
    // 1 2 3 1 4 5 6 7
    delete[] data_;
    data_ = newData;
    length_++;
}

template <typename T>
void SequentialContainer<T>::print() {
    for (int i = 0; i < length_-1; i++) {
        std::cout << data_[i] << ", ";//" " << i << std::endl;
    }
    std::cout << data_[length_-1];
    std::cout << std::endl;
}

template<typename T>
void SequentialContainer<T>::print_length() {
    std::cout << "Length: " << length_ << std::endl;
}
