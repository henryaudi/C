#include <iostream>

class Node {
   public:
    int   value;
    Node* next;
    Node* prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
    friend std::ostream& operator<<(std::ostream& os, const Node& node);
};

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << node.value;
    return os;
}

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
    void  append(int value);
    void  deleteLast();
    void  prepend(int value);
    void  deleteFirst();
    Node* get(int index);
    bool  set(int index, int value);
    bool  insert(int index, int value);
    void  deleteNode(int index);
};

void DoublyLinkedList::deleteNode(int index) {
    if (index < 0 || index >= length) {
        return;
    }

    if (index == 0) {
        deleteFirst();
        return;
    }

    if (index == length - 1) {
        deleteLast();
        return;
    }

    Node* temp       = get(index);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    length--;
}

bool DoublyLinkedList::insert(int index, int value) {
    if (index < 0 || index > length) {
        return false;
    }

    if (index == 0) {
        prepend(value);
        return true;
    }

    if (index == length) {
        append(value);
        return true;
    }

    Node* newNode = new Node(value);
    Node* before  = get(index - 1);
    Node* after   = before->next;

    before->next  = newNode;
    newNode->prev = before;
    newNode->next = after;
    after->prev   = newNode;
    length++;
    return true;
}

bool DoublyLinkedList::set(int index, int value) {
    Node* temp = get(index);
    if (temp != nullptr) {
        temp->value = value;
        return true;
    }
    return false;
}

Node* DoublyLinkedList::get(int index) {
    if (index < 0 || index >= length) {
        return nullptr;
    }

    Node* temp = head;
    if (index < length / 2) {
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
    } else {
        temp = tail;
        for (int i = length - 1; i > index; i--) {
            temp = temp->prev;
        }
    }
    return temp;
}

void DoublyLinkedList::deleteFirst() {
    if (length == 0) {
        return;
    }

    Node* temp = head;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head       = head->next;
        head->prev = nullptr;
    }

    delete temp;
    length--;
}

void DoublyLinkedList::prepend(int value) {
    Node* newNode = new Node(value);
    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev    = newNode;
        head          = newNode;
    }

    length++;
}

void DoublyLinkedList::deleteLast() {
    if (length == 0) {
        return;
    }

    Node* temp = tail;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail       = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
    length--;
}

void DoublyLinkedList::append(int value) {
    if (this->length == 0) {
        Node* newNode = new Node(value);
        head          = newNode;
        tail          = newNode;
    } else {
        Node* newNode = new Node(value);
        tail->next    = newNode;
        newNode->prev = tail;
        tail          = newNode;
    }

    length++;
}

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
    myList->append(20);
    myList->append(30);
    myList->printList();

    myList->prepend(5);
    myList->printList();

    myList->deleteFirst();
    myList->deleteFirst();
    myList->deleteFirst();
    myList->printList();

    myList->deleteFirst();
    myList->printList();

    return 0;
}
