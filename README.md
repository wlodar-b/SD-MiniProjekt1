# Projekt: Struktury Danych - Miniprojekt 1 

## 1. Zarządzanie strukturami
* **main.cpp**: Punkt wejściowy programu. Zawiera dwupoziomowe menu sterujące.
* **Menu.hpp / Menu.cpp**: Obsługa interfejsu użytkownika i nawigacja między strukturami.
* **FileManager.hpp / FileManager.cpp**: Wczytywanie danych z plików `*.txt` i ich parsowanie.

---

## 2. Implementacje Struktur Danych
*Wszystkie struktury zaimplementowane samodzielnie bez użycia biblioteki STL.*

### Tablica Dynamiczna (ArrayList)
* **DynamicArray.hpp**: Definicja klasy, pól `array`, `size`, `capacity`.
* **DynamicArray.cpp**: Implementacja logiki, w tym dwukrotne zwiększanie rozmiaru przy braku miejsca.

### Lista Jednokierunkowa (Singly Linked List)
* **SinglyLinkedList.hpp**: Definicja węzła (`Node`) oraz klasy z wskaźnikami `head` i `tail`.
* **SinglyLinkedList.cpp**: Logika operacji na wskaźnikach.

### Lista Dwukierunkowa (Doubly Linked List)
* **DoublyLinkedList.hpp**: Definicja węzła z wskaźnikami `next` i `prev` oraz klasy.
* **DoublyLinkedList.cpp**: Implementacja metod z optymalizacją dostępu (np. od końca listy).

---

## 3. Pomiary Czasu
* **TimeMeasurer.hpp / TimeMeasurer.cpp**: Klasa do przeprowadzania badań.
    * Pomiar czasu w **nanosekundach [ns]**
    * Badania na kopiach struktur, aby zachować stały rozmiar $n$ podczas operacji `add`/`remove`.
