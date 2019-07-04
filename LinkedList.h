#pragma once

#include "Node.h"
#include "Iterator.h" 

template<class T>
class LinkedList
{
private:
	Node<T>* head;
	int tamano;
public:

	LinkedList();
	LinkedList(int t);
	~LinkedList();
	void insertElement(int position);
	void removeElement(int position);
	Node<T>* getElement(int position);
	Iterator<T>* iterador();
	int getTamano();
};

#include "LinkedList.h"
template<typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tamano = 0;
}
template<typename T>
LinkedList<T>::LinkedList(int t) {
	head = nullptr;
	tamano = 0;

	for (int i = 0; i < t; i++) {
		insertElement(i);
	}
}

template <typename T>
LinkedList<T>::~LinkedList() {
	Node<T>* prev = nullptr; Node<T>* tmpHead = head;
	while (tmpHead) {
		prev = tmpHead;
		tmpHead = tmpHead->next;
		delete prev;
	}
}

template<typename T>
void LinkedList<T>::insertElement(int position) {

	Node<T>* prev = nullptr; Node<T>* cur = head;
	Node<T>* newNode = new Node<T>;

	newNode->next = nullptr;

	if (position == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		int iterator = 0;

		while (iterator != position) {
			if (iterator == position - 1) {
				prev = cur;
			}
			cur = cur->next;
			iterator++;
		}
		if (position == tamano) {
			newNode->next = nullptr;
		}
		else {
			newNode->next = cur;
		}
		prev->next = newNode;

	}
	tamano++;
}

template<typename T>
Node<T>* LinkedList<T>::getElement(int element) {
	Node<T>* tmpHead = head;
	int contador = 0;
	while (contador != element)
	{
		tmpHead = tmpHead->next;
		contador++;
	}
	return tmpHead;
}
template<typename T>
void LinkedList<T>::removeElement(int position) {
	if (head == nullptr)
		return;
	Node<T>* temp = head;

	if (position == 0)
	{
		head = temp->next;
		delete temp;

		return;
	}

	for (int i = 0; temp != nullptr && i < position - 1; i++)
		temp = temp->next();

	if (temp == nullptr || temp->next == nullptr)
		return;

	Node<T>* next = (temp->next)->next;

	delete temp->next;

	temp->next = next;
	tamano--;
}
template<typename T>
int LinkedList<T>::getTamano() {
	return tamano;
}

template<typename T>
Iterator<T>* LinkedList<T>::iterador() {
	return new Iterator<T>(this);
}