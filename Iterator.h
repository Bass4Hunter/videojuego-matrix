#pragma once
#include	"Node.h"

template<typename T>
class LinkedList;

template<typename T>
class Iterator
{
private:

	LinkedList<T>* _list;
	int	_posicion;
	Node<T>* _actual;

public:

	Iterator(LinkedList<T>* list);
	Iterator(Iterator<T>* newIterator);

	bool hasNext();
	Node<T>* next();
	Node<T>*& operator ++();
	Node<T>* operator ++(int);
	Node<T>* operator *();

};
template<typename T>
Iterator<T>::Iterator(LinkedList<T>* list) {
	_list = list;
	_posicion = 0;
	_actual = list->getElement(0);
}

template<typename T>
Iterator<T>::Iterator(Iterator<T>* newIterator) {

	_list = newIterator->_list;
	_posicion = newIterator->_posicion;
	_actual = newIterator->_actual;

	delete newIterator;
}


template<typename T>
bool Iterator<T>::hasNext() {
	if (_posicion < _list->getTamano())
		return true;
	else {
		return false;
	}
}

template<typename T>
Node<T>* Iterator<T>::next() {
	Node<T>* valor = _list->getElement(_posicion);
	_posicion++;
	return valor;
}
template<typename T>
Node<T>*& Iterator<T>::operator ++() {
	_actual = this->next();
	return _actual;
}

template<typename T>
Node<T>* Iterator<T>::operator ++(int) {
	_actual = operator++();
	return _actual;
}

template<typename T>
Node<T>* Iterator<T>::operator *() {
	return _actual;
}


