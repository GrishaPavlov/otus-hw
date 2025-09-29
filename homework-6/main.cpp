#include <iostream>
#include "SequentialContainer.h"
#include "LinkedContainer.h"

int main() {

    std::cout << std::endl;
    std::cout << "Sequential container:\n";
    std::cout << std::endl;

    auto container = SequentialContainer<int>();
    for (int i = 0; i < 10; i++) {
        container.push_back(i);
    }
    container.print();
    container.print_length();
    container.remove(2);
    container.remove(3);
    container.remove(4);
    container.print();
    container.insert(0, 10);
    container.print();
    container.insert(3, 20);
    container.print();
    container.push_back(30);
    container.print();

    std::cout << std::endl;
    std::cout << "Linked container:\n";
    std::cout << std::endl;

    LinkedContainer<int> list = LinkedContainer<int>();
    for (int i = 0; i < 10; i++) {
        list.add(i);
    }
    list.print();
    list.printLength();
    list.remove(2);
    list.remove(3);
    list.remove(4);
    list.print();
    list.add_at(0, 10);
    list.print();
    list.add_at(4, 20);
    list.print();
    list.add(30);
    list.print();
}
