#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

// Klasa reprezentująca tablicę dynamiczną 
class DynamicArray {
    int* array;      // Wskaźniki na tablicę utworzoną dynamicznie
    int size;        // Liczba aktualnie przechowywanych elementów
    int capacity;    // Całkowity zarezerwowany rozmiar tablicy 
    
    // Prywatna metoda pomocnicza do zmiany rozmiaru tablicy (dwuktrotne zwiększanie)
    void resize();

public:
    // Konstruktor - inicjalizuje tablicę z zadanym rozmiarem początkowym
    DynamicArray();

    // Destruktor - zwalnia pamięć zaalokowaną dynamicznie
    ~DynamicArray();

    // Operacje usuwania elementy na różnych pozycjach 
    void removeStart();         // Usuwanie z początku
    void removeEnd();           // Usuwanie z końca
    void removeAt(int index);   // Usuwanie z losowego miejsca

    // Operacje dodawania elementy na różnych pozycjach 
    void addStart(int value);            // Dodawanie na początku
    void addEnd(int value);              // Dodawanie na końca
    void addAt(int index);      // Dodawanie w losowym miejscu

    // Operacja wyszukiwania wartości w strukturze
    int find(int value);        // Zwraca indeks znalezionego elementu -1 

    // Metody pomocnicze wymagane przez wytyczne menu
    void display();             // Wyświetla zawartość tablicy
    void clear();               // Czyści strukture przed wczytaniem nowych danych

    // Gettery potrzebne do badań i sprawozdania
    int getSize();              // Zwraca aktualną ilość elementów
};

#endif // DYNAMICARRAY_HPP