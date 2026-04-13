#include "singlyLinkedList.hpp"
#include <iostream>

// tworzy pusta liste
SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// kopiuje wszystkie elementy z innej listy 
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other) {
    head = nullptr;
    tail = nullptr;
    size = 0;
    Node* current = other.head;
    while (current != nullptr) {
        addEnd(current->value);
        current = current->next;
    }
}

// zwalnia pamiec wszystkich wezlow
SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

// dodaje element na poczatek - O(1)
void SinglyLinkedList::addStart(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

// dodaje element na koniec - O(1) dzieki wskaznikowi tail
void SinglyLinkedList::addEnd(int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

// usuwa pierwszy element - O(1)
void SinglyLinkedList::removeStart() {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;
    delete temp;
    size--;

    if (head == nullptr) tail = nullptr;
}

// usuwa ostatni element - O(n), bo trzeba znalezc przedostatni wezel
void SinglyLinkedList::removeEnd() {
    if (head == nullptr) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    size--;
}

// szuka wartosci i zwraca jej indeks, lub -1 jesli nie znaleziono - O(n)
int SinglyLinkedList::find(int value) {
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->value == value) return index;
        current = current->next;
        index++;
    }
    return -1;
}

// usuwa wszystkie elementy i zwalnia pamiec
void SinglyLinkedList::clear() {
    while (head != nullptr) {
        removeStart();
    }
}

// wypisuje zawartosc listy
void SinglyLinkedList::display() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// zwraca liczbe elementow
int SinglyLinkedList::getSize() {
    return size;
}

// dodaje element na podana pozycje - O(n)
void SinglyLinkedList::addAt(int index, int value) {
    if (index < 0 || index > size) {
        std::cout << "Bledny indeks!" << std::endl;
        return;
    }

    if (index == 0) {
        addStart(value);
    } else if (index == size) {
        addEnd(value);
    } else {
        Node* newNode = new Node(value);
        Node* current = head;
        // dochodzimy do wezla przed pozycja wstawienia
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
}

// usuwa element z podanej pozycji - O(n)
void SinglyLinkedList::removeAt(int index) {
    // Sprawdzenie poprawności indeksu
    if (index < 0 || index >= size) {
        std::cout << "Bledny indeks!" << std::endl;
        return;
    }

    if (index == 0) {
        removeStart();
    } else if (index == size - 1) {
        removeEnd();
    } else {
        Node* current = head;
        // dochodzimy do wezla przed usuwanym
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete; // Zwolnienie pamięci
        size--;
    }
}
