//
// Created by shalaga44 on 12/3/20.
//

#include "StaticStack/StaticStack.h"
#include <exception>

StaticStack::StaticStack(int initialCapacity) {

    capacity = initialCapacity;
    array = new int[sizeof(int) * capacity];
}

int StaticStack::push(int item) {
    if (size == capacity)
        throw std::exception();
    array[size++] = item;
    return 0;
}

int StaticStack::pop() {
    if (isEmpty())
        throw std::exception();
    return array[--size];
}

bool StaticStack::isEmpty() const {
    return size == 0;
}

std::ostream &operator<<(std::ostream &os, const StaticStack &stack) {
    if (stack.size == 0) {
        os << "[]";
        return os;
    }
    os << "[";
    for (int i = 0; i < stack.size - 1; ++i)
        os << stack.array[i] << ", ";


    os << stack.array[stack.size - 1] << "]";
    return os;

}

