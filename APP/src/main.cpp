#include "main.h"


void printCreateInfo();

void LinkedListLoop();

void queueLoop();

void StackLoop();

int main() {
    bool mainLoop = true;
    while (mainLoop) {
        printCreateInfo();
        char input;
        cin >> input;
        if (input == 'L')
            LinkedListLoop();
        else if (input == 'Q')
            queueLoop();
        else if (input == 'S')
            StackLoop();
        else
            mainLoop = false;
    }


    return 0;

}

void StackLoop() {
    StaticStack stack = StaticStack(100);
    cout << "INFO::CREATED::Stack::Size(100)" << endl;
    std::string input;
    cout << "Stack::Type \"Exit\" to Exit from stack" << endl;
    cout << "Stack::Type \"push\" to insert an item" << endl;
    cout << "Stack::Type \"pop\" to pop " << endl;
    cout << "Stack::Type \"print\" to list all the item" << endl;
    while (true) {
        if (input == "Exit") break;

        cout << "stack>>> ";
        cin >> input;
        if (input == "push") {
            cout << "\nstack::push>>> ";
            cin >> input;
            int item = stoi(input);
            stack.push(item);
            cout << endl;
        } else if (input == "pop") {
            cout << "\nstack::pop>>>  " << stack.pop() << endl;
        } else if (input == "print") {
            cout << "\nstack::print>>> ";
            cout << stack << endl;
        } else break;
    }
}

void queueLoop() {
    DynamicQueue queue;
    cout << "INFO::CREATED::DynamicQueue" << endl;
    std::string input;
    cout << "Queue::Type \"Exit\" to Exit from Queue" << endl;
    cout << "Queue::Type \"enqueue\" to insert an item" << endl;
    cout << "Queue::Type \"dequeue\" to dequeue " << endl;
    cout << "Queue::Type \"print\" to list all the item" << endl;
    while (true) {
        if (input == "Exit") break;
        cout << "Queue>>> ";
        cin >> input;
        cout << "input: " << input << endl;
        if (input == "enqueue") {
            cout << "\nQueue::enqueue>>> ";
            cin >> input;
            int item = stoi(input);
            queue.enqueue(item);
            cout << endl;
        } else if (input == "dequeue") {
            cout << "\nQueue::dequeue>>>  " << queue.dequeue() << endl;
        } else if (input == "print") {
            cout << "\nQueue::print>>> ";
            cout << queue << endl;
        } else break;
    }
}

void LinkedListLoop() {
    LinkedList list = LinkedList();
    cout << "INFO::CREATED::LinkedList" << endl;
    std::string input;
    cout << "LinkedList::Type \"Exit\" to Exit from LinkedList" << endl;
    cout << "LinkedList::Type \"add\" to insert an item" << endl;
    cout << "LinkedList::Type \"search\" to search for an item index" << endl;
    cout << "LinkedList::Type \"print\" to list all the item" << endl;
    cout << "LinkedList::Type \"remove\" to remove an item" << endl;
    cout << "LinkedList::Type \"removeAt\" to remove an item by index" << endl;
    while (true) {
        cout << "LinkedList>>> ";
        cin >> input;
        if (input == "Exit")break;
        else if (input == "add") {
            cout << "\nLinkedList::add>>> ";
            cin >> input;
            list.add(stoi(input));
            cout << endl;
        } else if (input == "search") {
            cout << "\nLinkedList::search>>> ";
            cin >> input;
            cout << list.search(stoi(input)) << endl;
        } else if (input == "print") {
            cout << "\nLinkedList::print>>> ";
            cout << list << endl;
        } else if (input == "size") {
            cout << "\nLinkedList::size>>> " << list.size << endl;
        } else if (input == "remove") {
            cout << "\nLinkedList::remove>>> ";
            cin >> input;

            int index = list.search(stoi(input));
            if (list.isEmpty())
                std::cerr << "List is empty" << endl;
            else if (index == -1)
                std::cerr << "Item not exist: " << stoi(input) << endl;
            else
                list.removeAt(index);
            cout << endl;
        } else if (input == "removeAt") {
            cout << "\nLinkedList::removeAt>>> ";
            cin >> input;

            if (list.isEmpty())
                std::cerr << "List is empty" << endl;

            else if (list.size < stoi(input))
                std::cerr << "no item at index: " << stoi(input) << endl;

            else
                list.removeAt(stoi(input));

            cout << endl;
        }

    }
}

void printCreateInfo() {
    cout << "Type L to create Stack" << endl;
    cout << "Type Q to create Queue" << endl;
    cout << "Type S to create Stack" << endl;
}
