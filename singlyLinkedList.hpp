#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

// Struktura reprezentująca pojedynczy węzeł listy
struct Node {
    int value;      // Właściwa wartość (4-bajtowa liczba całkowita)
    Node* next;     // Wskaźnik na następny element (nullptr, jeśli to koniec)

    // Konstruktor węzła dla wygody alokacji
    Node(int val) : value(val), next(nullptr) {}
};

// Klasa reprezentująca listę jednokierunkową
class SinglyLinkedList {

    private:
        Node* head;     // pierwszy element listy
        Node* tail;     // ostatni elemnt listy
        int size;       // Liczba przechowywanych elementów

    public:
        SinglyLinkedList();
        SinglyLinkedList(const SinglyLinkedList& other);
        ~SinglyLinkedList();

        // Operacje dodawania elementu
        void addStart(int value);   // Dodawanie na początek
        void addEnd(int value);     // Dodawanie na koniec 
        void addAt(int index, int value); // Dodawanie miejscu w losowe miejsce 

        // Operacja usuwania elementu
        void removeStart();         // Usuwanie z początku 
        void removeEnd();           // Usuwanie z końca 
        void removeAt(int index);   // Usuwanie z losowego miejsca 

        // Operacja wyszukiwania
        int find(int value);        // Zwraca indeks elementu lub (-1)

        // Metody pomocnicze do menu i badań
        void display();             // Wyświetlenie zawartości listy
        void clear();               // Czyszczenie całej listy 
        int getSize();              // Zwraca aktualny rozmiar n
};

#endif