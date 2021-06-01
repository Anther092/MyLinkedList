//
// Created by Bogdan on 21/04/2021.
//

#include "Node.h"
#include "LinkedList.h"

LinkedList::Iterator::Iterator(Node *ptr) : ptr(ptr) {}

ValueType &LinkedList::Iterator::operator*() const {
    return ptr->value;
}

Node *LinkedList::Iterator::operator->() {
    return ptr;
}

LinkedList::Iterator &LinkedList::Iterator::operator++() {
    ptr = ptr->next;
    return *this;
}

LinkedList::Iterator LinkedList::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

bool LinkedList::Iterator::operator!=(LinkedList::Iterator &o) {
    return ptr != o.ptr;
}

bool LinkedList::Iterator::operator==(LinkedList::Iterator &o) {
    return !(*this != o);
}



