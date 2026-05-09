#include <iostream>

class Node
{
public:
	int value;
	Node *next;
	Node(int value) : value(value), next(nullptr) {}
};

class LinkedList
{
private:
	Node *head;
	Node *tail;
	int length;

public:
	LinkedList(int value) : head(new Node(value)), tail(head), length(1) {}

	void printList();

	Node *getHead() { return this->head; }
	Node *getTail() { return this->tail; }
	int getLength() { return this->length; }
	void append(int value);
	void deleteLast();

	~LinkedList();
};

void LinkedList::deleteLast()
{
	if (this->length == 0)
	{
		return;
	}

	Node *temp = head;
	if (this->length == 1)
	{
		this->head = nullptr;
		this->tail = nullptr;
	}
	else
	{
		Node *pre = head;
		while (temp->next)
		{
			pre = temp;
			temp = temp->next;
		}
		this->tail = pre;
		this->tail->next = nullptr;
	}
	this->length--;
	delete temp;
}

void LinkedList::printList()
{
	Node *temp = this->head;
	while (temp != nullptr)
	{
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}
}

void LinkedList::append(int value)
{
	Node *newNode = new Node(value);

	if (this->length == 0)
	{
		this->head = newNode;
		this->tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	this->length++;
}

LinkedList::~LinkedList()
{
	Node *current = this->head;
	while (current != nullptr)
	{
		Node *next = current->next;
		delete current;
		current = next;
	}
}

int main(int argc, char const *argv[])
{
	LinkedList *myLinkedList = new LinkedList(10);
	myLinkedList->printList();
	std::cout << "Head: " << myLinkedList->getHead()->value << std::endl;
	std::cout << "Tail: " << myLinkedList->getTail()->value << std::endl;
	std::cout << "Length: " << myLinkedList->getLength() << std::endl;

	delete myLinkedList;
	return 0;
}