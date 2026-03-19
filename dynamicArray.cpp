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

// Dodawanie w dowolnym miejscu (losowa pozycja): O(n) 
void DynamicArray::addAt(int index, int value) {
    // Sprawdzenie, czy indeks jest poprawny
    if (index < 0 || index > size) {
        std::cout << "Bledny indeks!" << std::endl;
        return;
    }

    // Jeśli tablica jest pełna, zwiększamy ją dwukrotnie
    if (size == capacity) {
        resize();
    }

    // Przesunięcie elementów w prawo od podanego indeksu
    for (int i = size; i > index; i--) {
        array[i] = array[i - 1];
    }

    array[index] = value; // Wstawienie nowej wartości
    size++;                      // Zwiększenie licznika elementów    
}

// Usuwanie z początku: O(n)
void DynamicArray::removeStart() {
    if (size > 0) {
        // Przesunięcie wszystkich elementów w lewo o jedną pozycję
        for (int i = 0; i < size; i++) {
            array[i] = array[i +1];
        }
        size--;                 // Zmniejszenie rozmiaru
    }
}

// Usuwanie z dowolnego miejsca (losowa pozycja): O(n)
void DynamicArray::removeAt(int index) {
    // Sprawdzenie poprawności indeksu
    if (index < 0 || index >= size) {
        std::cout << "Bledny indeks!" << std::endl;
        return;
    }

    // Przesunięcie elementów w lewo, aby "zakryć" usuwany element
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;                 // Zmniejszenie rozmiaru
}

// Metoda czyszcząca strukturę: wymagana przy opcji "zbuduj z pliku"
void DynamicArray::clear() {
    delete[] array;             // Zwolnienie pamięci
    size = 0;                   // Resetowanie liczników
    capacity = 1;               // Resetowanie pojemności
    array = new int[capacity];  // Alokacja nowej startowej tablicy
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