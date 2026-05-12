#include <iostream>

class Node
{
public:
	int value;
	Node *next;
	Node(int value) : value(value), next(nullptr) {}
	friend std::ostream &operator<<(std::ostream &os, const Node &node);
};

std::ostream &operator<<(std::ostream &os, const Node &node)
{
	os << node.value;
	return os;
}

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
	void prepend(int value);
	void deleteFirst();
	Node *get(int index);
	bool set(int index, int value);
	bool insert(int index, int value);
	void deleteNode(int index);
	void reverse();
	~LinkedList();
};

void LinkedList::reverse()
{
	Node *temp = this->head;
	this->head = this->tail;
	this->tail = temp;

	Node *after = temp->next;
	Node *before = nullptr;

	for (int i = 0; i < this->length; i++)
	{
		after = temp->next;
		temp->next = before;
		before = temp;
		temp = after;
	}
}

void LinkedList::deleteNode(int index)
{
	if (index < 0 || index >= this->length)
	{
		return;
	}

	if (index == 0)
	{
		return this->deleteFirst();
	}
	if (index == this->length - 1)
	{
		return this->deleteLast();
	}

	Node *prev = this->get(index - 1);
	Node *temp = prev->next;
	prev->next = temp->next;
	delete temp;
	this->length--;
}

bool LinkedList::insert(int index, int value)
{
	if (index < 0 || index > this->length)
	{
		return false;
	}
	if (index == 0)
	{
		this->prepend(value);
		return true;
	}
	if (index == this->length)
	{
		this->append(value);
		return true;
	}

	Node *newNode = new Node(value);
	Node *temp = this->get(index - 1);
	newNode->next = temp->next;
	temp->next = newNode;
	this->length++;
	return true;
}

bool LinkedList::set(int index, int value)
{
	Node *temp = this->get(index);
	if (!temp)
		return false;
	temp->value = value;
	return true;
}

Node *LinkedList::get(int index)
{
	if (index < 0 || index >= this->length)
	{
		return nullptr;
	}

	Node *temp = this->head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	return temp;
}

void LinkedList::deleteFirst()
{
	if (length == 0)
		return;

	Node *temp = head;

	if (length == 1)
	{
		this->head = nullptr;
		this->tail = nullptr;
	}
	else
	{
		head = head->next;
	}
	delete temp;
	this->length--;
}

void LinkedList::prepend(int value)
{
	Node *newNode = new Node(value);
	if (this->length == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	this->length++;
}

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
	myLinkedList->append(5);
	myLinkedList->append(16);

	std::cout << "Node at index 1: " << *(myLinkedList->get(1)) << std::endl;

	myLinkedList->set(1, 6);
	std::cout << "Node at index 1 after set: " << *(myLinkedList->get(1)) << std::endl;

	delete myLinkedList;
	return 0;
}