//
// Created by shalaga44 on 12/3/20.
//
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

#include "../../../APP/include/StaticStack/StaticStack.h"

const int testingDataSize = 6;
int testingData[testingDataSize] = {20, 30, 44, 50, 60, 40};

void push_pop();

void emptyPop();

void fullPush();

int main() {
    push_pop();
    emptyPop();
    fullPush();


}

void fullPush() {
    StaticStack stack(testingDataSize);

    stack.push(1);
    stack.push(2);
    stack.pop();
    for (int i = 0; i < testingDataSize - 1; ++i)
        stack.push(i);
    try {
        stack.push(20);
        assert(false);
    } catch (...) {}
}

void emptyPop() {
    StaticStack stack(testingDataSize);
    try { stack.pop(); } catch (...) {}
}

void push_pop() {
    StaticStack stack(testingDataSize);
    for (int i:testingData)
        stack.push(i);

    for (int i = testingDataSize - 1; i + 1 > 0; --i)
        assert(stack.pop() == testingData[i]);
}
