#include <climits>
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

class Stack {
private:
    Node* top;
    int   height;

public:
    Stack(int value) {
        Node* newNode = new Node(value);
        top           = newNode;
        height        = 1;
    }

    void  printStack();
    Node* getTop() { return top; }
    int   getHeight() { return height; }
    void  push(int value);
    int   pop();

    friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
};

int Stack::pop() {
    if (height == 0) {
        return INT_MIN;
    }

    Node* temp        = top;
    int   poppedValue = temp->value;
    top               = top->next;
    delete temp;
    height--;
    return poppedValue;
}

void Stack::push(int value) {
    Node* newNode = new Node(value);

    newNode->next = top;
    top           = newNode;
    height++;
}

void Stack::printStack() {
    Node* temp = top;
    while (temp != nullptr) {
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
}

std::ostream& operator<<(std::ostream& os, const Stack& stack) {
    Node* temp = stack.top;
    while (temp != nullptr) {
        os << temp->value << std::endl;
        temp = temp->next;
    }
    return os;
}

int main() {
    Stack* myStack = new Stack(1);
    myStack->push(2);
    myStack->push(3);
    myStack->push(4);
    myStack->push(5);
    std::cout << *myStack;
    std::cout << "Popped value: " << myStack->pop() << std::endl;
    std::cout << *myStack;
    return 0;
}