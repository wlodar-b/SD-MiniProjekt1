# Projekt: Struktury Danych - Miniprojekt 1 

## 1. Zarządzanie strukturami
* **main.cpp**: Punkt wejściowy programu. Zawiera dwupoziomowe menu sterujące.
* **menu.hpp / menu.cpp**: Obsługa interfejsu użytkownika i nawigacja między strukturami.
* **fileManager.hpp / fileManager.cpp**: Wczytywanie danych z plików `*.txt` i ich parsowanie.

---

## 2. Implementacje Struktur Danych
*Wszystkie struktury zaimplementowane samodzielnie bez użycia biblioteki STL.*

### Tablica Dynamiczna (ArrayList)
* **dynamicArray.hpp**: Definicja klasy, pól `array`, `size`, `capacity`.
* **dynamicArray.cpp**: Implementacja logiki, w tym dwukrotne zwiększanie rozmiaru przy braku miejsca.

### Lista Jednokierunkowa (Singly Linked List)
* **singlyLinkedList.hpp**: Definicja węzła (`Node`) oraz klasy z wskaźnikami `head` i `tail`.
* **singlyLinkedList.cpp**: Logika operacji na wskaźnikach.

### Lista Dwukierunkowa (Doubly Linked List)
* **doublyLinkedList.hpp**: Definicja węzła z wskaźnikami `next` i `prev` oraz klasy.
* **doublyLinkedList.cpp**: Implementacja metod z optymalizacją dostępu (np. od końca listy).

---

## 3. Pomiary Czasu
* **timeMeasurer.hpp / timeMeasurer.cpp**: Klasa do przeprowadzania badań.
    * Pomiar czasu w **nanosekundach [ns]**
    * Badania na kopiach struktur, aby zachować stały rozmiar $n$ podczas operacji `add`/`remove`.
