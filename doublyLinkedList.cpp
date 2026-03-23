#include <iostream>
#include "doublyLinkedList.hpp"

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

void DoublyLinkedList::addStart(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    size++;
}

void DoublyLinkedList::addEnd(int value) {
    Node* newNode = new Node(value);
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    size++;
}

void DoublyLinkedList::addAt(int index, int value) {
    Node* newNode = new Node(value);
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    Node* a = current->prev;
    a->next = newNode;
    current->prev = newNode;
    newNode->next = current;
    newNode->prev = a;
    size++;
}

void DoublyLinkedList::removeStart() {
    Node* toDelete = head;
    Node* first = toDelete->next;
    first->prev = nullptr;
    head = first;
    delete toDelete;
    size--;
}

void DoublyLinkedList::removeEnd() {
    Node* toDelete = tail;
    Node* last = toDelete->prev;
    last->next = nullptr;
    tail = last;
    delete toDelete;
    size--;
}

void DoublyLinkedList::removeAt(int index) {
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    Node* a = current->prev;
    Node* b = current->next;
    a->next = b;
    b->prev = a;
    delete current;
    size--;
}
