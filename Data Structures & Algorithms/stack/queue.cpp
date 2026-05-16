#include <limits.h>

#include <iostream>

class Node {
public:
    int   value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
    friend std::ostream& operator<<(std::ostream& os, const Node& node);
};

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << node.value;
    return os;
}

class Queue {
private:
    Node* first;
    Node* last;
    int   length;

public:
    Queue(int value) {
        Node* newNode = new Node(value);
        first         = newNode;
        last          = newNode;
        length        = 1;
    }

    void  printQueue();
    Node* getFirst();
    Node* getLast();
    int   getLength();
    void  enqueue(int value);
    int   dequeue();
};

int Queue::dequeue() {
    if (length == 0) {
        return INT_MIN;
    }

    Node* temp          = first;
    int   dequeuedValue = temp->value;
    if (length == 1) {
        first = nullptr;
        last  = nullptr;
    } else {
        first = first->next;
    }
    delete temp;
    length--;
    return dequeuedValue;
}

void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (length == 0) {
        first = newNode;
        last  = newNode;
    } else {
        last->next = newNode;
        last       = newNode;
    }
    length++;
}

void Queue::printQueue() {
    Node* temp = first;
    while (temp != nullptr) {
        std::cout << *temp << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

Node* Queue::getFirst() {
    return first;
}

Node* Queue::getLast() {
    return last;
}

int Queue::getLength() {
    return length;
}

int main() {
    Queue* myQueue = new Queue(1);
    myQueue->printQueue();
}