#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

// wezel listy - przechowuje wartosc i wskaznik na nastepny wezel
struct Node {
    int value;      // Właściwa wartość 
    Node* next;     // Wskaźnik na następny element 

    Node(int val) : value(val), next(nullptr) {}
};

// Klasa reprezentująca listę jednokierunkową
class SinglyLinkedList {

    private:
        Node* head;     // pierwszy element listy
        Node* tail;     // ostatni element listy
        int size;       // Liczba przechowywanych elementów

public:
    SinglyLinkedList();                            // tworzy pusta liste
    SinglyLinkedList(const SinglyLinkedList& other); // kopiuje inna liste (deep copy)
    ~SinglyLinkedList();                           // zwalnia pamiec

    void addStart(int value);              // dodaje element na poczatek
    void addEnd(int value);                // dodaje element na koniec
    void addAt(int index, int value);      // dodaje element na podana pozycje

    void removeStart();                    // usuwa pierwszy element
    void removeEnd();                      // usuwa ostatni element
    void removeAt(int index);              // usuwa element z podanej pozycji

    int find(int value);                   // szuka wartosci, zwraca indeks lub -1
    void display();                        // wypisuje zawartosc listy
    void clear();                          // usuwa wszystkie elementy
    int getSize();                         // zwraca liczbe elementow
};

#endif
