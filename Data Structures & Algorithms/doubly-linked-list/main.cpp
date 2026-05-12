#include <iostream>

class Node {
   public:
    int   value;
    Node* next;
    Node* prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
   private:
    Node* head;
    Node* tail;
    int   length;

   public:
    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        head          = newNode;
        tail          = newNode;
        length        = 1;
    }

    void  printList();
    Node* getHead();
    Node* getTail();
    int   getLength();
};

void DoublyLinkedList::printList() {
    Node* temp = head;

    while (temp != nullptr) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

Node* DoublyLinkedList::getHead() {
    return head;
}

Node* DoublyLinkedList::getTail() {
    return tail;
}

int DoublyLinkedList::getLength() {
    return length;
}

int main() {
    DoublyLinkedList* myList = new DoublyLinkedList(10);
    return 0;
}
