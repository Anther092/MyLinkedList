//
// Created by Bogdan on 14/04/2021.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

using ValueType = int;

struct Node {
    Node *next;
    ValueType value;

    Node();
    Node(ValueType v);
    ~Node();
};


#endif //LINKEDLIST_NODE_H
