//
// Created by Gregory on 9/26/2025.
//

#ifndef LINKEDCONTAINER_H
#define LINKEDCONTAINER_H
#include <iostream>

template<typename T>
struct Node {
    Node *next;
    Node *prev;
    T data;
};

template<typename T>
class LinkedContainer {
public:
    LinkedContainer();

    void add(T value);

    void add_at(int index, T value);

    void remove(int index);

    void print();

    void printLength() {
        std::cout << "Length: " << length << std::endl;
    }

    ~LinkedContainer();

private:
    Node<T> *firstNode;
    Node<T> *lastNode;
    int length;
};

template<typename T>
LinkedContainer<T>::LinkedContainer() {
    firstNode = nullptr;
    lastNode = nullptr;
    length = 0;
}


template<typename T>
void LinkedContainer<T>::add(T value) {
    auto *newNode = new Node<T>;
    newNode->data = value;
    if (length == 0) {
        firstNode = newNode;
        firstNode->prev = nullptr;
        lastNode = newNode;
        length = 1;
        return;
    }

    newNode->prev = lastNode;
    newNode->next = nullptr;
    lastNode->next = newNode;
    lastNode = newNode;
    length++;
}

template<typename T>
void LinkedContainer<T>::add_at(int index, T value) {
    auto *newNode = new Node<T>;
    newNode->data = value;
    Node<T> *current = firstNode;
    length++;
    for (int i = 0; i < length; i++) {
        if (index == 0) {
            newNode->prev = nullptr;
            newNode->next = current;
            current->prev = newNode;
            firstNode = newNode;
            return;
        }

        if (index == i) {
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
            return;
        }
        current = current->next;
    }
}

template<typename T>
void LinkedContainer<T>::remove(int index) {
    if (index < 0 || index >= length) {
        std::cout << "Index is out of bounds" << std::endl;
        return;
    }
    Node<T> *current = firstNode;
    for (int i = 0; i < length; i++) {
        if (index == 0) {
            current->next->prev = nullptr;
            firstNode = current->next;
            delete current;
            break;
        }

        if (i == index) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            break;
        }
        current = current->next;
    }
    length--;
}

template<typename T>
void LinkedContainer<T>::print() {
    Node<T> *current = firstNode;
    while (current->next != nullptr) {
        std::cout << current->data << ", ";
        current = current->next;
    }
    std::cout << lastNode->data << std::endl;
}

template<typename T>
LinkedContainer<T>::~LinkedContainer() {
    Node<T> *current = lastNode;
    Node<T> *previous = nullptr;
    while (current != nullptr) {
        previous = current->prev;
        delete current;
        current = previous;
    }
}


#endif //LINKEDCONTAINER_H
