//
// Created by shalaga44 on 12/3/20.
//

#include "../../include/StaticStack/StaticStack.h"
#include <exception>

StaticStack::StaticStack(int initialCapacity) {

    capacity = initialCapacity;
    array = new int[sizeof(int) * capacity];
}

int StaticStack::push(int item) {
    if (size==capacity)
        throw std::exception();
    array[size++] = item;
    return 0;
}

int StaticStack::pop() {
    if (isEmpty())
        throw std::exception();
    return array[--size];
}

bool StaticStack::isEmpty() {
    return size == 0;
}

