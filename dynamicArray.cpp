#include "dynamicArray.hpp"
#include <iostream>

// Konstruktor: inicjalizuje tablicę z początkowym rozmiarem (np. 1)
DynamicArray::DynamicArray() {
    size = 0;                   // Na początku struktura jest pusta
    capacity =1;                // Początkowa pojemność
    array = new int[capacity];  // Dynamiczna alokacja tablicy 
}

// Destruktor: zwalnia pamięć, aby uniknąć wycieków
DynamicArray::~DynamicArray() {
    delete[] array;             // Usunięcie tablicy z pamięci
}

// Prywatna metoda resize: kluczowa dla wydajności ArrayList
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

// Dodawanie na końcu: Operacja 0(1) amortyzowana
void DynamicArray::addEnd(int value) {
    if (size == capacity) {
        resize();               // Jeśli brak miejsca, zwiększamy tablicę
    }   
    array[size] = value;        // Wstawienie elementyu na koniec
    size++;                     // Inkrementacja licznika elementów
}

// Dodawanie na początku: Wymaga przesunięcia wszystkich elementów O(n)
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

// Usuwanie z końca: Operacja O(1)
void DynamicArray::removeEnd() {
    if (size > 0) {
        size--;                 // Po prostu zmniejszamy licznik (element fizycznie zostaje, ale jest niedostępny)
    }
}

// Wyszukiwanie: Generujemy liczbę i szukamy jej w strukturze
int DynamicArray::find(int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;           // Zwraca indeks znalezienia
        }
    }
    return -1;                  // Nie znaleziono
}

// Wyśwoetlanie: Na potrzeby menu i prezentacji
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

int DynamicArray::getSize() {
    return size;
}