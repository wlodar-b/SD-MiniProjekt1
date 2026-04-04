#include "singlyLinkedList.hpp"
#include <iostream>

// Inicjalizacja pustej listy
SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

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

SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

// Dodawanie na początek: O(1)
void SinglyLinkedList::addStart(int value) {
    Node* newNode = new Node(value);    // Dynamiczna alokacja węzła
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

// Dodawanie na koniec: O(1) dzięki wskaźnikowi tail
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

// Usuwanie z początku: O(1) 
void SinglyLinkedList::removeStart() {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;
    delete temp;    // Zwolnienie pamięci
    size--;

    if (head == nullptr) tail = nullptr;    // Lista stała się pusta
}

// Usuwanie z końca: O(n) - musimy znaleźć przedostatni element
void SinglyLinkedList::removeEnd() {
    if (head == nullptr) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) { // Przejście do przedostatniego elementu 
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    size--;
}

// Wyszukiwanie wartości: O(n)
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

// Czyszczenie struktury - wymagane przed nowym wczytaniem
void SinglyLinkedList::clear() {
    while (head != nullptr) {
        removeStart();
    }
}

void SinglyLinkedList::display() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int SinglyLinkedList::getSize() {
    return size;
}

// Dodawanie w losowym miejscu (po indeksie): O(n)
void SinglyLinkedList::addAt(int index, int value) {
    // Sprawdzenie poprawności indeksu
    if (index < 0 || index > size) {
        std::cout << "Bledny indeks!" << std::endl;
        return;
    }

    // Wykorzystanie istniejących metod dla skrajnych przypadków
    if (index == 0) {
        addStart(value);
    } else if (index == size) {
        addEnd(value);
    } else {
        Node* newNode = new Node(value);
        Node* current = head;

        // Dotarcie do elementu poprzedzającego miejsce wstawienia
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        // Przepięcie wskaźników
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
}

// Usuwanie z losowego miejsca (po indeksie); O(n)
void SinglyLinkedList::removeAt(int index) {
    // Sprowadzenie poprawności indeksu
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

        // Znalezienie elementu przed tym, który usuwamy
        for (int i = 0; i < index -1; i++) {
            current = current->next;
        }

        Node* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete; // Zwolnienie pamięci
        size--;
    }
}
