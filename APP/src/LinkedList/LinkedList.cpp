//
// Created by shalaga44 on 12/3/20.
//

#include "LinkedList/LinkedList.h"
#include <exception>
#include <iostream>

void LinkedList::add(int item) {
    if (isEmpty()) {
        head = new Node(item);
        last = head;
    } else {
        Node *newNode = new Node(item);
        last->next = newNode;
        last = newNode;
    }
    size++;
}

int LinkedList::pop() {
    if (this->isEmpty())
        throw std::exception();
    int item = head->data;
    Node *newHead = head->next;
    delete head;
    size--;
    head = newHead;
    return item;
}

bool LinkedList::isEmpty() const {
    return size == 0;
}

void LinkedList::removeHead() {
    if (isEmpty())
        throw std::exception();
    Node *nextOfTheHead = head->next;
    delete head;
    head = nextOfTheHead;
    size--;
}

void LinkedList::removeLast() {
    Node *current = head;
    int i = 0;
    while (i < size - 2) {
        current = current->next;
        i++;
    }
    Node *lastOfTheLast = current;
    delete last;
    last = lastOfTheLast;
    last->next = nullptr;
    size--;
}


std::ostream &operator<<(std::ostream &os, const LinkedList &list) {
    if (list.isEmpty()) {
        os << "[]";
        return os;
    }
    if (list.size == 1) {
        os << "[" << list.head->data << "]";
        return os;
    }
    os << "[";
    LinkedList::Node *current = list.head;
    while (current != list.last) {
        os << current->data << ", ";
        current = current->next;
    }
    os << current->data << "]";
    return os;
}

int LinkedList::search(int item) const {
    Node *current = head;
    int counter = 0;
    while (current != last) {
        if (current->data == item) return counter;
        current = current->next;
        counter++;
    }
    if (last->data == item)
        return counter;
    return -1;
}

void LinkedList::removeAt(int index) {
    if (index == size - 1) {
        removeLast();
        return;
    }
    if (index == 0) {
        removeHead();
        return;
    }
    if (index < 0)
        throw std::exception();
    if (index > size - 1)
        throw std::exception();

    Node *lastOfCurrent = head;
    for (int i = 0; i < index - 1; ++i)
        lastOfCurrent = lastOfCurrent->next;

    Node *current = lastOfCurrent->next;
    lastOfCurrent->next = current->next;
    delete current;
    size--;
}


LinkedList::LinkedList() = default;


