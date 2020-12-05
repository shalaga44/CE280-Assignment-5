//
// Created by shalaga44 on 12/3/20.
//

#pragma once

#include <ostream>

class StaticStack {
public:
    int capacity;
    int size = 0;
    int *array;

    explicit StaticStack(int initialCapacity);

    int pop();

    int push(int item);
    bool isEmpty();

    friend std::ostream &operator<<(std::ostream &os, const StaticStack &stack);
};

