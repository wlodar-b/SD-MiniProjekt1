  Zarządzanie strukturami (Klasy bazowe i Menu)
main.cpp: Punkt wejściowy programu. Tutaj zaimplementuj dwupoziomowe menu sterujące.
Menu.hpp / Menu.cpp: (Opcjonalnie, ale zalecane) Klasa obsługująca interfejs użytkownika, wczytywanie opcji i przekierowanie do konkretnych struktur.
FileManager.hpp / FileManager.cpp: Klasa odpowiedzialna za wczytywanie danych z plików *.txt i ich poprawne parsowanie do struktur.
  Implementacje Struktur Danych
Dla każdej struktury musisz stworzyć osobny zestaw plików (pamiętaj: zakaz używania STL ):
  Tablica Dynamiczna (ArrayList):
DynamicArray.hpp: Definicja klasy, pól array, size, capacity oraz metod.
DynamicArray.cpp: Logika zwiększania rozmiaru dwukrotnie przy braku miejsca.
  Lista Jednokierunkowa (Singly Linked List):
SinglyLinkedList.hpp: Definicja klasy oraz struktury węzła (Node) zawierającej value i next. Musi zawierać wskaźniki head i tail.
SinglyLinkedList.cpp: Logika operacji na wskaźnikach.
  Lista Dwukierunkowa (Doubly Linked List):
DoublyLinkedList.hpp: Definicja węzła z wskaźnikami next i prev oraz klasy z polami head i tail.
DoublyLinkedList.cpp: Implementacja metod (np. optymalizacja dostępu do elementów od końca listy).
  3. Pomiary Czasu
TimeMeasurer.hpp / TimeMeasurer.cpp: Klasa dedykowana do przeprowadzania badań. Musi mierzyć czas w nanosekundach [ns]. Pamiętaj, aby przy badaniu add/remove operować na kopiach struktur, by zachować stały rozmiar $n$ podczas pomiaru
