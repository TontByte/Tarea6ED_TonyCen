#pragma once
#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class LinkedList : public List<E> {
private:
	Node<E>* head;
	Node<E>* current; //apunta al que esta por atras
	Node<E>* tail;
	int size;

public:
	LinkedList() {
		head = current = tail = new Node<E>();
		size = 0;
	}
	~LinkedList() {
		clear();
		delete head;
	}

	void insert(E element) {
		current->next = new Node<E>(element, current->next);
		if (current == tail) {
			tail = current->next;
		}
		size++;
	}

	void append(E element) {
		tail = tail->next = new Node<E>(element, tail->next);
		size++;
	}

	E remove() {
		if (size == 0) {
			throw runtime_error("List is empty.");
		}
		if (current == tail) {
			throw runtime_error("No current element.");
		}
		E res = current->next->element;
		Node<E>* temp = current->next;
		current->next = temp->next;
		if (temp == tail) {
			tail = current;
		}
		delete temp;
		size--;
		return res;
	}

	void setElement(E element) {
		if (size == 0) {
			throw runtime_error("List is empty.");
		}
		if (current == tail) {
			throw runtime_error("No current element.");
		}
		current->next->element = element;
	}

	E getElement() {
		if (size == 0) {
			throw runtime_error("List is empty.");
		}
		if (current == tail) {
			throw runtime_error("No current element");
		}
		return current->next->element;
	}

	void clear() {
		current = head->next;
		while (head->next != nullptr) {
			head->next = current->next;
			delete current;
			current = head->next;
		}
		size = 0;
		current = tail = head;
	}

	/*
	tambien se puede
	for (current=head->next ; head->next != nullptr ; current = head->next) {
		head->next = current->next;
		delete current;
	}
	size = 0;
	current = tail = head;
	*/

	void goToStart() {
		current = head;
	}

	void goToEnd() {
		current = tail;
	}

	void goToPos(int pos) {
		if (pos > size || pos < 0) {
			throw runtime_error("Invalid index.");
		}
		current = head;
		for (int i = 0; i < pos; i++) {
			current = current->next;
		}
	}

	void next() {
		if (current != tail) {
			current = current->next;
		}
	}

	void previous() {
		if (current != head) {
			Node<E>* temp = head;
			while (temp->next != current) {
				temp = temp->next;
			}
			current = temp;
		}
	}

	bool atStart() {
		return (current == head);
	}

	bool atEnd() {
		return (current == tail);
	}

	int getPos() {
		Node<E>* temp = head;
		int res = 0;
		while (temp != current) {
			temp = temp->next;
			res++;
		}
		return res;
	}

	int getSize() {
		return size;
	}

	void print() {
		cout << "[";
		Node<E>* temp = head->next;
		for (int i = 0; i < size; i++) {
			cout << temp->element;
			if (temp != tail) {
				cout << ", ";
			}
			temp = temp->next;
		}
		cout << "]" << endl;
	}
};

