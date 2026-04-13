#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

class DynamicArray {
    int* array;      // wskaznik na tablice w pamieci
    int size;        // ile elementow aktualnie przechowujemy
    int capacity;    // ile elementow moze pomiescic tablica bez rozszerzania

    void resize();   // podwaja pojemnosc tablicy (prywatna)

public:
    DynamicArray();                          // tworzy pusta tablice
    DynamicArray(const DynamicArray& other); // kopiuje inna tablice (deep copy)
    ~DynamicArray();                         // zwalnia pamiec

    void addStart(int value);                // dodaje element na poczatek
    void addEnd(int value);                  // dodaje element na koniec
    void addAt(int index, int value);        // dodaje element na podana pozycje

    void removeStart();                      // usuwa pierwszy element
    void removeEnd();                        // usuwa ostatni element
    void removeAt(int index);                // usuwa element z podanej pozycji

    int find(int value);                     // szuka wartosci, zwraca indeks lub -1
    void display();                          // wypisuje zawartosc tablicy
    void clear();                            // usuwa wszystko i resetuje tablice
    int getSize();                           // zwraca liczbe elementow
};

#endif
