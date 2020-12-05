
#include "LinkedList/LinkedList.h"
#include <iostream>
#include <string>
#include <cassert>


void add_pop();

void emptyPop();

void removeHead();

void removeLast();

void search();

void removeAt();

void removeErros();

using namespace std;
const int testingDataSize = 6;
int testingData[testingDataSize] = {20, 30, 44, 50, 60, 40};

int main() {
//    LinkedList list = LinkedList();
    add_pop();
    emptyPop();
    removeHead();
    removeLast();
    search();
    removeAt();
    removeErros();
}

void removeErros() {
    LinkedList list = LinkedList();
    for (int i:testingData)
        list.add(i);
    try {
        list.removeAt(-1);
        assert(false);
    } catch (...) {}
    try {
        list.removeAt(testingDataSize + 1);
        assert(false);
    } catch (...) {}
}

void removeAt() {
    LinkedList list = LinkedList();
    for (int i:testingData)
        list.add(i);

    const int numberIndex = testingDataSize - 3;
    int number = testingData[numberIndex];
    assert(list.search(number) != -1);
    list.removeAt(numberIndex);
    assert(list.search(number) == -1);

}

void search() {
    LinkedList list = LinkedList();
    for (int i:testingData)
        list.add(i);

    const int numberIndex = testingDataSize - 2;
    int number = testingData[numberIndex];
    assert(list.search(number) == numberIndex);
    assert(list.search(9999) == -1);

}

void removeLast() {
    LinkedList list = LinkedList();
    for (int i:testingData)
        list.add(i);
    list.removeLast();
    assert(list.last->data == testingData[testingDataSize - 2]);
}

void removeHead() {
    LinkedList list = LinkedList();

    for (int i: testingData)
        list.add(i);
    list.removeHead();
    assert(list.head->data == testingData[1]);
}

void emptyPop() {
    LinkedList list = LinkedList();
    try {
        list.pop();
    } catch (...) {

    }
}

void add_pop() {
    LinkedList list = LinkedList();

    for (int i: testingData)
        list.add(i);

    for (int i: testingData)
        assert(i == list.pop());

}
