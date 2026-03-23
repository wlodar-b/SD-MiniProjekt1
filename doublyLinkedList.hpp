#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

class Node;

class DoublyLinkedList {
    Node* head;
    Node* tail;
    int size;

public:
    void addStart(int value);
    void addEnd(int value);
    void addAt(int index, int value);
    void removeStart();
    void removeEnd();
    void removeAt(int index);
};

#endif
