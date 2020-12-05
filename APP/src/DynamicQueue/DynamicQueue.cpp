#include "../../include/DynamicQueue/DynamicQueue.h"
#include <exception>

void DynamicQueue::enqueue(int item) {
    if (head == nullptr) {
        head = new Node(item);
    } else if (last == nullptr) {
        last = new Node(item);
        last->previous = head;
        head->next = last;

    } else {
        Node *newNode = new Node(item);
        newNode->previous = last;
        last->next = newNode;
        last = newNode;
    }
    size++;
}

int DynamicQueue::dequeue() {
    if (size == 0)
        throw std::exception();
    int item = head->data;
    Node *newHead = head->next;
    delete head;
    head = newHead;
    size--;
    return item;

}

int DynamicQueue::front() {

    return head->data;

}

int DynamicQueue::rear() {
    return last->data;

}

std::ostream &operator<<(std::ostream &os, const DynamicQueue &queue) {
    if (queue.size == 0) {
        os << "[]";
        return os;
    }
    os << "[";
    DynamicQueue::Node *current = queue.head;
    while (current != queue.last) {
        os << current->data << ", ";
        current = current->next;
    }
    os << current->data << "]";
    return os;
}
