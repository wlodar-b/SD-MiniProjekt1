#include <iostream>
#include "doublyLinkedList.hpp"

// wezel listy - przechowuje wartosc i wskazniki na sasiadow
class Node {
public:
    int value;    // wartosc przechowywana w wezle
    Node* next;   // wskaznik na nastepny wezel
    Node* prev;   // wskaznik na poprzedni wezel

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

// Konstruktor domyslny - tworzy pusta liste 
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Konstruktor kopiujacy - tworzy nowa liste bedaca kopia innej listy
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
    : head(nullptr), tail(nullptr), size(0)
{
    Node* current = other.head;
    while (current != nullptr) {
        addEnd(current->value);
        current = current->next;
    }
}

// Destruktor - zwalnia pamiec wszystkich wezlow 
DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

// zwraca liczbe elementow
int DoublyLinkedList::getSize() {
    return size;
}

// Dodaje nowy element na poczatek listy
void DoublyLinkedList::addStart(int value) {
    Node* newNode = new Node(value);  // tworzymy nowy wezel
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

// dodaje element na koniec 
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

// dodaje element na podana pozycje 
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
        // wstawiamy nowy wezel miedzy current->prev a current
        Node* a = current->prev;
        a->next = newNode;
        newNode->prev = a;
        newNode->next = current;
        current->prev = newNode;
        size++;
    }
}

// usuwa pierwszy element - O(1)
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

// usuwa ostatni element - O(1)
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

// usuwa element z podanej pozycji - O(n)
void DoublyLinkedList::removeAt(int index) {
    if (index < 0 || index >= size) return;
    if (index == size - 1) removeEnd();
    else if (index == 0) removeStart();
    else {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        // laczmy sasiadow ze soba, pomijajac usuwany wezel
        Node* a = current->prev;
        Node* b = current->next;
        a->next = b;
        b->prev = a;
        delete current;
        size--;
    }
}

// usuwa wszystkie elementy i zwalnia pamiec
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

// wypisuje zawartosc listy
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

// szuka wartosci i zwraca jej indeks, lub -1 jesli nie znaleziono - O(n)
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
