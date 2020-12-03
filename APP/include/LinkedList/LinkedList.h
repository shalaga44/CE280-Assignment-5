//
// Created by shalaga44 on 12/3/20.
//
#pragma once

#include <algorithm>
#include <ostream>

class LinkedList {

public:

    int size = 0;


    class Node {
    public:
        int data;
        Node *next = nullptr;

        explicit Node(int item) {
            data = item;
            next = nullptr;
        }
    };

    Node *head = nullptr;
    Node *last = nullptr;

    LinkedList();

    int pop();

    void add(int item);

    bool isEmpty() const;

    void removeHead();

    void removeLast();

    int search(int item);

    void removeAt(int index);

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list);
};