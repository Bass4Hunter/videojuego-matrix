#pragma once
template <typename T>
class Node
{
public:
	T* _data;
	Node<T>* next;

	Node();
	~Node();
	Node(Node<T>*&);
};

template <typename T>
Node<T>::Node() {
	next = nullptr;
	_data = new T;
}

template<typename T>
Node<T>::~Node() {
	delete _data;
}

template <typename T>
Node<T>::Node(Node<T>*& newNode) {
	next = newNode->next;
	_data = newNode->next;
}