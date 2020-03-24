/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DSALIB_H
#define DSA191_A1_DSALIB_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class DSAException {
    int     _error;
    string  _text;
public:

    DSAException() : _error(0), _text("Success") {}
    DSAException(int err) : _error(err), _text("Unknown Error") {}
    DSAException(int err, const char* text) : _error(err), _text(text) {}

    int getError() { return _error; }
    string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
    T data;
    L1Item<T> *pNext;
    L1Item() : pNext(NULL) {}
    L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
public:
    L1Item<T>   *_pHead;// The head pointer of linked list
    L1Item<T>   *_pTail;
    size_t      _size;// number of elements in this list

    L1List() : _pHead(NULL), _pTail(NULL), _size(0) {}
    ~L1List();

    L1Item<T>* getHead() {
        return _pHead;
    }
    L1Item<T>* getTail() {
        return _pTail;
    }
    void    clean();
    bool    isEmpty() {
        return _pHead == NULL;
    }
    size_t  getSize() {
        return _size;
    }

    T&      at(int i);// give the reference to the element i-th in the list
    T&      operator[](int i);// give the reference to the element i-th in the list

    bool    find(T& a, int& idx);// find an element similar to a in the list. Set the found index to idx, set idx to -1 if failed. Return true if success.
    int     insert(int i, T& a);// insert an element into the list at location i. Return 0 if success, -1 otherwise
    int     remove(int i);// remove an element at position i in the list. Return 0 if success, -1 otherwise.

    int     push_back(T& a);// insert to the end of the list
    int     insertHead(T& a);// insert to the beginning of the list

    int     removeHead();// remove the beginning element of the list
    int     removeLast();// remove the last element of the list

    void    reverse();

    void    traverse(void (*op)(T&)) {
        // TODO: Your code goes here
    }
    void    traverse(void (*op)(T&, void*), void* pParam) {
        // TODO: Your code goes here
    }
};

/// Insert item to the end of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::push_back(T &a) {
    // TODO: Your code goes here
    if (isEmpty()) {
        _pHead = new L1Item<T> (a);
        _pTail = _pHead;
    return 0;
    }
    _pTail->pNext = new L1Item<T> (a);
    _pTail = _pTail->pNext;
    _size++;
    return 0;
}

/// Insert item to the front of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insertHead(T &a) {
    // TODO: Your code goes here
    if (isEmpty()) {
        _pHead = new L1Item<T> (a);
        _pTail = _pHead;
        _size++;
        return 0;
    }
    L1Item<T> *p = new L1Item<T> (a);
    p->pNext = _pHead;
    _pHead = p;
    _size++;
    return 0;
}

/// Remove the first item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeHead() {
    // TODO: Your code goes here
    if (isEmpty()) return -1;
    L1Item<T> *temp = _pHead;
    _pHead = _pHead->pNext;
    delete temp;
    temp = NULL;
    _size--;
    return 0;
}

/// Remove the last item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeLast() {
    // TODO: Your code goes here
    if (isEmpty()) return -1;
    L1Item<T> *temp = _pHead;
    for (int i = 0; i < _size - 2; i++) temp = temp->pNext;
    delete _pTail;
    _pTail = temp;
    temp->pNext = NULL;
    _size--;
    return 0;
}

template <class T>
T& L1List<T>::at(int i) {
    if (L1List::isEmpty()) {
        throw "at: empty list";
    }
    if (i > L1List::_size) throw "index out of range";
    if (i == 0) return _pHead->data;
    L1Item<T> *temp = L1List::_pHead;
    for (int j = 0; j < i; j++) temp = temp->pNext;
    return temp->data;
}

template <class T>
T& L1List<T>::operator[](int i) {
    if (L1List::isEmpty()) {
        throw std::logic_error("Empty list");
    }
    if (i > _size) throw std::logic_error("Index out of range");
    L1Item<T> *temp = L1List::_pHead;
    for (int j = 0; j < i; j++) temp = temp->pNext;
    return temp->data;
}

template <class T>
bool L1List<T>::find(T& a, int& idx) {
    if (L1List::isEmpty()) {
        idx = -1;
        return false;
    }
    L1List<T> *temp = L1List::_pHead;
    int index = 0;
    while (temp->data != a) {
        temp = temp->pNext;
        index++;
        if (temp == NULL) break;
    }
    if (temp == NULL) {
        idx = -1;
        return false;
    }
    idx = index;
    return true;
}

template <class T>
int L1List<T>::insert(int i, T& a) {
    if (i == 0) return insertHead(a);
    L1Item<T> *temp = L1List::_pHead;
    for (int j = 0; j < i - 1; j++) {
        temp = temp->pNext;
        if (temp == NULL) return -1;
    }
    L1Item<T> *insertNode = new L1Item<T> (a);
    insertNode->pNext = temp->pNext;
    temp->pNext = insertNode;
    L1List::_size++;
    return 0;
}

template <class T>
int L1List<T>::remove(int i) {
    if (i == 0) {
        _pHead = _pHead->pNext;
        return 0;
    }
    L1Item<T> *temp = L1List::_pHead;
    for (int j = 0; j < i - 1; j++) {
        temp = temp->pNext;
        if (temp == NULL) return -1;
    }
    L1Item<T> *Next = temp->pNext;
    temp->pNext= Next->pNext;
    delete Next;
    Next = NULL;
    return 0;
}

template <class T>
L1List<T>::~L1List() {
    L1Item<T> *temp = L1List::_pHead;
    while (L1List::_pHead != NULL) {
        L1List::_pHead = L1List::_pHead->pNext;
        delete temp;
        temp = L1List::_pHead;
    }
    _size = 0;
}

#endif //DSA191_A1_DSALIB_H
