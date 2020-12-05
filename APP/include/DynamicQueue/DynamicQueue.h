#pragma once

class DynamicQueue {

public:
    class Node {
    public:
        int data;
        Node *next = nullptr;
        Node *previous = nullptr;

        Node(int item) {
            data = item;
        }
    };

    Node *head = nullptr;
    Node *last = nullptr;
    int size = 0;

    void enqueue(int item);

    int dequeue();

    int front();

    int rear();
};