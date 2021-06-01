//
// Created by Bogdan on 14/04/2021.
//

#include <iostream>
#include <cassert>
#include "LinkedList.h"
#include "Node.h"
using namespace std;


void LinkedList::pushBack(const ValueType &value) {
    ++size;

    Node *curLast = getLast();
    Node *last = new Node(value);

    if (head)
        curLast->next = last;
    else if (!head)
        head = last;
}

Node *LinkedList::getLast() {
    Node *cur = head;
    Node *prev = nullptr;
    while (cur) {
        prev = cur;
        cur = cur->next;
    }

    return prev;
}

LinkedList::LinkedList() {
    size = 0;
    head = nullptr;
}

LinkedList::~LinkedList() {
    size = 0;
    delete head;
}

void LinkedList::pushFront(const ValueType &value) {
    ++size;

    Node *newHead = new Node(value);
    newHead->next = head;
    head = newHead;
}

void LinkedList::insert(size_t idx, const ValueType &value) {
    assert(idx <= size);
    ++size;

    Node *cur = head;
    for (int i = 0; i < idx-1; ++i) {
        cur = cur->next;
    }

    Node *newNode = new Node(value);

    Node *buf = cur->next;
    cur->next = newNode;
    newNode->next = buf;
}

void LinkedList::map(int (*fn)(ValueType)) {
    Node *cur = head;
    while (cur) {
        fn(cur->value);
        cur = cur->next;
    }
}

void LinkedList::deleteCur(Node *prev, Node *cur) {
    --size;

    if (cur == head)
    {
        auto buf = head->next;
        head = nullptr;
        delete head;
        head = buf;
        return;
    }

    prev->next = cur->next;
    cur->next = nullptr;
    delete cur;
}

void LinkedList::filter(bool (*fn)(ValueType))
{
    Node *prev = nullptr;
    auto cur = head;


    while (cur)
    {
        if (fn(cur->value))
        {
            auto bufN = cur->next;
            deleteCur(prev, cur);
            cur = bufN;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
}

LinkedList::Iterator LinkedList::begin() {
    return Iterator(head);
}

LinkedList::Iterator LinkedList::end() {
    return Iterator(nullptr);
}

