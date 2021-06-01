#include <iostream>
#include <algorithm>
#include <vector>
#include "LinkedList.h"

using namespace std;

using ValueType = int;

int print(ValueType data) {
    cout << data << " ";
}

bool isOdd(ValueType data) {
    return (data % 2) == 1;
}

int main() {

    LinkedList l;
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);
    l.pushFront(4);
    l.insert(2, 5);

    for(int v : l)
        std::cout << v << " ";

    return 0;
}
