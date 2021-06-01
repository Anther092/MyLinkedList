//
// Created by Bogdan on 14/04/2021.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>
#include <cstddef>
#include "Node.h"

using ValueType = int;


class LinkedList {
private:
    Node *head;
    size_t size;

    Node* getLast();
    void deleteCur(Node *prev, Node *cur);
public:

    struct Iterator {
    private:
        Node *ptr;

    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Node;
        using pointer           = Node*;
        using reference         = Node&;

        explicit Iterator(Node *ptr);

        ValueType& operator*() const;
        Node* operator->();
        Iterator& operator++();
        Iterator operator++(int);
        bool operator!=(Iterator& o) ;
        bool operator==(Iterator& o);
    };

    Iterator begin();
    Iterator end();

    LinkedList();
    ~LinkedList();
    void pushBack(const ValueType &value);
    void pushFront(const ValueType &value);
    void insert(size_t idx, const ValueType &value);
    void map(int (*fn)(ValueType));
    void filter(bool (*fn)(ValueType));
    void revers();
};


#endif //LINKEDLIST_LINKEDLIST_H
