//
// Created by Bogdan on 14/04/2021.
//

#include "Node.h"

Node::Node() {
    value = 0;
    next = nullptr;
}

Node::Node(ValueType v) {
    value = v;
    next = nullptr;
}

Node::~Node() {
    value = 0;
    delete next;
}

