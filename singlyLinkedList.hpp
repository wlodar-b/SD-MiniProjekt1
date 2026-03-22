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
        Node* head;     // Wskaźnik na pierwszy element listy
        Node* tail;     // Wskaźnik na ostatni elemnt listy
        int size;       // Liczba przechowywanych elementów

    public:
        // Konstruktor - inicjalizujący pustą listę
        SinglyLinkedList();

        // Destruktor - musi zwolnić pamięć wszystkich węzłów 
        ~SinglyLinkedList();

        // Operacje dodawania elementu
        void addStart(int value);   // Dodawanie na początek - O(1)
        void addEnd(int value);     // Dodawanie na koniec - O(1) dzięki wskaźnikowi
        void addAt(int index, int value); // Dodawanie miejscu w losowe miejsce - O(n)

        // Operacja usuwania elementu
        void removeStart();         // Usuwanie z początku - O(1)
        void removeEnd();           // Usuwanie z końca - O(n) (trzeba znaleźć przedostatni element)
        void removeAt(int index);   // Usuwanie z losowego miejsca - O(n)

        // Operacja wyszukiwania
        int find(int value);        // Zwraca indeks elementu lub -1)

        // Metody pomocnicze do menu i badań
        void display();             // Wyświetlenie zawartości listy
        void clear();               // Czyszczenie całej listy (usuwanie wszystkich węzłów)
        int getSize();              // Zwraca aktualny rozmiar n
};

#endif