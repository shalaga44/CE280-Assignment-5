#include "../../../APP/include/DynamicQueue/DynamicQueue.h"
#include <cassert>
#include <iostream>

using namespace std;
const int testingDataSize = 6;
int testingData[testingDataSize] = {20, 30, 44, 50, 60, 40};


void enqueue_dequeue();

void emptyDequeue();

void size();

int main() {
    enqueue_dequeue();
    emptyDequeue();
    size();


    return 0;
}

void size() {
    DynamicQueue queue;
    for (int i: testingData)
        queue.enqueue(i);
    assert(queue.size == testingDataSize);
    queue.dequeue();
    assert(queue.size == testingDataSize - 1);
}

void emptyDequeue() {
    DynamicQueue queue;
    try {
        queue.dequeue();
        assert(false);
    } catch (...) {}
    queue.enqueue(10);
    assert(queue.dequeue() == 10);

    queue.enqueue(0);
    queue.enqueue(2);
    assert(queue.dequeue() == 0);
    assert(queue.dequeue() == 2);
}

void enqueue_dequeue() {
    DynamicQueue queue;
    for (int i: testingData)
        queue.enqueue(i);


    for (int i: testingData) {

        int item = queue.dequeue();
        cout << item << endl;
        assert(item == i);
    }
}
