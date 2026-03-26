#include <iostream>
#include "doublyLinkedList.hpp"

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

int DoublyLinkedList::getSize() {
    return size;
}

void DoublyLinkedList::addStart(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void DoublyLinkedList::addEnd(int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void DoublyLinkedList::addAt(int index, int value) {
    if (index < 0 || index > size) return;

    if (index == 0) {
        addStart(value);
    } else if (index == size) {
        addEnd(value);
    } else {
        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        Node* a = current->prev;
        a->next = newNode;
        newNode->prev = a;
        newNode->next = current;
        current->prev = newNode;
        size++;
    }
}

void DoublyLinkedList::removeStart() {
    if (head == nullptr) return;

    Node* toDelete = head;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        Node* first = toDelete->next;
        first->prev = nullptr;
        head = first;
    }
    delete toDelete;
    size--;
}

void DoublyLinkedList::removeEnd() {
    if (tail == nullptr) return;

    Node* toDelete = tail;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        Node* last = toDelete->prev;
        last->next = nullptr;
        tail = last;
    }
    delete toDelete;
    size--;
}

void DoublyLinkedList::removeAt(int index) {
    if (index < 0 || index >= size) return;
    if (index == size - 1) removeEnd();
    else if (index == 0) removeStart();
    else {
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
}
void DoublyLinkedList::clear() {
    if (size == 0) return;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void DoublyLinkedList::display() {
    Node* current = head;
    std::cout << "[ ";
    while (current != nullptr) {
        std::cout << current->value << ", ";
        current = current->next;
    }
    std::cout << "]";
    std::cout << std::endl;
}
int DoublyLinkedList::find(int value) {
    if (size == 0) return -1;
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->value == value) return index;
        current = current->next;
        index++;
    }
    return -1;
}