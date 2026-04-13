#include "dynamicArray.hpp"
#include <iostream>

// tworzy pusta tablice o pojemnosci 1
DynamicArray::DynamicArray() {
    size = 0;
    capacity = 1;
    array = new int[capacity];
}

// kopiuje wszystkie elementy z innej tablicy 
DynamicArray::DynamicArray(const DynamicArray& other) {
    size = other.size;
    capacity = other.capacity;
    array = new int[capacity];
    for (int i = 0; i < size; i++) {
        array[i] = other.array[i];
    }
}

// zwalnia pamiec tablicy
DynamicArray::~DynamicArray() {
    delete[] array;
}

// podwaja pojemnosc i kopiuje elementy do nowej tablicy
void DynamicArray::resize() {
    capacity *= 2;              // Zwiększamy pojemność dwukrotnie
    int* newArray = new int[capacity]; // Alokacja nowej, większej przestrzeni

    // Kopiowanie starych elementów do nowej tablicy
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    delete[] array;             // Zwolnienie starej pamięci
    array = newArray;           // Przypisanie wskaźnika do nowej tablicy
}

// Dodawanie na końcu
void DynamicArray::addEnd(int value) {
    if (size == capacity) {
        resize();               // Jeśli brak miejsca, zwiększamy tablicę
    }   
    array[size] = value;        // Wstawienie elementu na koniec
    size++;                    
}

// Dodawanie na początku
void DynamicArray::addStart(int value) {
    if (size == capacity) {
        resize();
    }
    // Przesunięcie elementów w prawo, aby zrobić miejsce na indeksie 0
    for (int i = size; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = value;           // Wstawienie na początek
    size++;
}

// dodaje element na podana pozycje, przesuwa reszte w prawo
void DynamicArray::addAt(int index, int value) {
    // Sprawdzenie czy indeks jest poprawny
    if (index < 0 || index > size) {
        std::cout << "Bledny indeks!" << std::endl;
        return;
    }
    if (size == capacity) {
        resize();
    }

    // Przesunięcie elementów w prawo od podanego indeksu
    for (int i = size; i > index; i--) {
        array[i] = array[i - 1];
    }

    array[index] = value; // Wstawienie nowej wartości
    size++; 
}

// usuwa pierwszy element, przesuwa reszte w lewo 
void DynamicArray::removeStart() {
    if (size > 0) {
        // Przesunięcie wszystkich elementów w lewo o jedną pozycję
        for (int i = 0; i < size; i++) {
            array[i] = array[i +1];
        }
        size--;
    }
}

// usuwa element z podanej pozycji, przesuwa reste w lewo
void DynamicArray::removeAt(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Bledny indeks!" << std::endl;
        return;
    }

    // Przesunięcie elementów w lewo, aby "zakryć" usuwany element
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
}

// usuwa wszystko i resetuje tablice do stanu poczatkowego
void DynamicArray::clear() {
    delete[] array;             // Zwolnienie pamięci
    size = 0;                   // Resetowanie liczników
    capacity = 1;               // Resetowanie pojemności
    array = new int[capacity];  // Alokacja nowej startowej tablicy
}

// usuwa ostatni element - O(1)
void DynamicArray::removeEnd() {
    if (size > 0) {
        size--;
    }
}

// szuka wartosci i zwraca jej indeks, lub -1 jesli nie znaleziono - O(n)
int DynamicArray::find(int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

// wypisuje wszystkie elementy tablicy
void DynamicArray::display() {
    if (size == 0) {
        std::cout << "Tablica jest pusta." << std::endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// zwraca liczbe elementow
int DynamicArray::getSize() {
    return size;
}
