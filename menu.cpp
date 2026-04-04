#include "menu.hpp"
#include "timeMeasurer.hpp"
#include <iostream>

// Metoda wyświetlająca główne menu wyboru struktury
void Menu::displayMainMenu() {
    int choice = -1;
    while (choice != 0) {
        std::cout << "\n=== MENU GLOWNE - PROJEKT SD ===" << std::endl;
        std::cout << "1. Tablica Dynamiczna (ArrayList)" << std::endl;
        std::cout << "2. Lista Jednokierunkowa" << std::endl;
        std::cout << "3. Lista Dwukierunkowa" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybor: ";
        std::cin >> choice;

        switch (choice) {
            case 1: menuArray(); break;
            case 2: menuSinglyList(); break;
            case 3: menuDoublyLinkedList(); break;
            case 0: std::cout << "Zamykanie programu..." << std::endl; break;
            default: std::cout << "Bledny wybor!" << std::endl;
        }
    }
}

// Podmenu dla Tablicy Dynamicznej
void Menu::menuArray() {
    int choice = -1;
    int value, index, subChoice;

    while (choice != 0) {
        std::cout << "\n--- TABLICA DYNAMICZNA ---" << std::endl;
        std::cout << "1. Usun (poczatek/koniec/losowe)" << std::endl;
        std::cout << "2. Dodaj (poczatek/koniec/losowe)" << std::endl;
        std::cout << "3. Znajdz" << std::endl;
        std::cout << "4. Utworz losowo" << std::endl;
        std::cout << "5. Wyswietl" << std::endl;
        std::cout << "6. Pomiar czasu" << std::endl;
        std::cout << "0. Powrot" << std::endl;
        std::cout << "Wybor: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "1.Poczatek, 2.Koniec, 3.Losowe miejsce: ";
                std::cin >> subChoice;
                if (subChoice == 1) array.removeStart();
                else if (subChoice == 2) array.removeEnd();
                else { 
                    std::cout << "Podaj indeks: "; 
                    std::cin >> index;
                    array.removeAt(index);
                }
                break;
            case 2:
                std::cout << "Wartosc: "; std::cin >> value;
                std::cout << "1.Poczatek, 2.Koniec, 3.Losowe miejsce: ";
                std::cin >> subChoice;
                if (subChoice == 1) array.addStart(value);
                else if (subChoice == 2) array.addEnd(value);
                else {
                    std::cout << "Podaj indeks: ";
                    std::cin >> index;
                    array.addAt(index, value);
                }
                break;
            case 3:
                std::cout << "Szukana wartosc: "; 
                std::cin >> value;
                index = array.find(value);
                if (index != -1) std::cout << "Znaleziono na indeksie: " << index << std::endl;
                else std::cout << "Nie znaleziono!" << std::endl;
                break;
            case 4: {
                int size;
                std::cout << "Podaj wielkosc struktury: "; 
                std::cin >> size; 
                array.clear();
                rng.reset();
                for (int i = 0; i < size; i++) {
                    array.addEnd(rng.generate());
                }
                break;
            }
            case 5:
                array.display(); 
                break;
            case 6: {
                if (array.getSize() == 0) {
                    std::cout << "Najpierw utworz strukture!" << std::endl;
                    break;
                }
                int iloscPomiarow;
                std::cout << "Podaj liczbe pomiarow: ";
                std::cin >> iloscPomiarow;
                int polowa = array.getSize() / 2;
                TimeMeasurer<DynamicArray> timer(array, iloscPomiarow);

                std::cout << "addStart:         " << timer.measure([&](DynamicArray& k) { k.addStart(rng.generate()); }) << " ns" << std::endl;
                std::cout << "addEnd:           " << timer.measure([&](DynamicArray& k) { k.addEnd(rng.generate()); }) << " ns" << std::endl;
                std::cout << "addAt(srodek):    " << timer.measure([&](DynamicArray& k) { k.addAt(polowa, rng.generate()); }) << " ns" << std::endl;
                std::cout << "removeStart:      " << timer.measure([&](DynamicArray& k) { k.removeStart(); }) << " ns" << std::endl;
                std::cout << "removeEnd:        " << timer.measure([&](DynamicArray& k) { k.removeEnd(); }) << " ns" << std::endl;
                std::cout << "removeAt(srodek): " << timer.measure([&](DynamicArray& k) { k.removeAt(polowa); }) << " ns" << std::endl;
                std::cout << "find:             " << timer.measure([&](DynamicArray& k) { k.find(rng.generate()); }) << " ns" << std::endl;
                break;
            }
        }
    }
}

// Podmenu dla Listy Jednokierunkowej
void Menu::menuSinglyList() {
    int choice = -1;
    int value, index, subChoice;

    while (choice != 0) {
        std::cout << "\n--- LISTA JEDNOKIERUNKOWA ---" << std::endl;
        std::cout << "1. Usun element" << std::endl;
        std::cout << "2. Dodaj element" << std::endl;
        std::cout << "3. Znajdz element" << std::endl;
        std::cout << "4. Utwórz losowo" << std::endl;
        std::cout << "5. Wyswietl" << std::endl;
        std::cout << "6. Pomiar czasu" << std::endl;
        std::cout << "0. Powrot" << std::endl;
        std::cout << "Wybor: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "1.Poczatek, 2.Koniec, 3.Losowe miejsce: ";
                std::cin >> subChoice;
                if (subChoice == 1) singlyList.removeStart();
                else if (subChoice == 2) singlyList.removeEnd();
                else { 
                    std::cout << "Podaj indeks: "; 
                    std::cin >> index;
                    singlyList.removeAt(index);
                }
                break;
            case 2:
                std::cout << "Wartosc: "; std::cin >> value;
                std::cout << "1.Poczatek, 2.Koniec, 3.Losowe miejsce: ";
                std::cin >> subChoice;
                if (subChoice == 1) singlyList.addStart(value);
                else if (subChoice == 2) singlyList.addEnd(value);
                else {
                    std::cout << "Podaj indeks: ";
                    std::cin >> index;
                    singlyList.addAt(index, value);
                }
                break;
            case 3:
                std::cout << "Szukana wartosc: "; 
                std::cin >> value;
                index = singlyList.find(value);
                if (index != -1) std::cout << "Znaleziono na indeksie: " << index << std::endl;
                else std::cout << "Nie znaleziono!" << std::endl;
                break;        
            case 4: {
                int size;
                std::cout << "Podaj wielkosc struktury: "; std::cin >> size;
                singlyList.clear();
                rng.reset();
                for (int i = 0; i < size; i++) {
                    singlyList.addEnd(rng.generate());
                }
                break;
            }
            case 5:
                singlyList.display();
                break;
            case 6: {
                if (singlyList.getSize() == 0) {
                    std::cout << "Najpierw utworz strukture!" << std::endl;
                    break;
                }
                int iloscPomiarow;
                std::cout << "Podaj liczbe pomiarow: ";
                std::cin >> iloscPomiarow;
                int polowa = singlyList.getSize() / 2;
                TimeMeasurer<SinglyLinkedList> timer(singlyList, iloscPomiarow);

                std::cout << "addStart:         " << timer.measure([&](SinglyLinkedList& k) { k.addStart(rng.generate()); }) << " ns" << std::endl;
                std::cout << "addEnd:           " << timer.measure([&](SinglyLinkedList& k) { k.addEnd(rng.generate()); }) << " ns" << std::endl;
                std::cout << "addAt(srodek):    " << timer.measure([&](SinglyLinkedList& k) { k.addAt(polowa, rng.generate()); }) << " ns" << std::endl;
                std::cout << "removeStart:      " << timer.measure([&](SinglyLinkedList& k) { k.removeStart(); }) << " ns" << std::endl;
                std::cout << "removeEnd:        " << timer.measure([&](SinglyLinkedList& k) { k.removeEnd(); }) << " ns" << std::endl;
                std::cout << "removeAt(srodek): " << timer.measure([&](SinglyLinkedList& k) { k.removeAt(polowa); }) << " ns" << std::endl;
                std::cout << "find:             " << timer.measure([&](SinglyLinkedList& k) { k.find(rng.generate()); }) << " ns" << std::endl;
                break;
            }
        }
    }
}

// Podmenu dla Listy Dwukierunkowej 
void Menu::menuDoublyLinkedList() {
    int choice = -1;
    int value, index, subChoice;

    while (choice != 0) {
        std::cout << "\n--- LISTA DWUKIERUNKOWA ---" << std::endl;
        std::cout << "1. Usun element" << std::endl;
        std::cout << "2. Dodaj element" << std::endl;
        std::cout << "3. Znajdz element" << std::endl;
        std::cout << "4. Utwórz losowo" << std::endl;
        std::cout << "5. Wyswietl" << std::endl;
        std::cout << "6. Pomiar czasu" << std::endl;
        std::cout << "0. Powrot" << std::endl;
        std::cout << "Wybor: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "1.Poczatek, 2.Koniec, 3.Losowe miejsce: ";
                std::cin >> subChoice;
                if (subChoice == 1) doublyLinkedList.removeStart();
                else if (subChoice == 2) doublyLinkedList.removeEnd();
                else { 
                    std::cout << "Podaj indeks: "; 
                    std::cin >> index;
                    doublyLinkedList.removeAt(index);
                }
                break;
            case 2:
                std::cout << "Wartosc: "; std::cin >> value;
                std::cout << "1.Poczatek, 2.Koniec, 3.Losowe miejsce: ";
                std::cin >> subChoice;
                if (subChoice == 1) doublyLinkedList.addStart(value);
                else if (subChoice == 2) doublyLinkedList.addEnd(value);
                else {
                    std::cout << "Podaj indeks: ";
                    std::cin >> index;
                    doublyLinkedList.addAt(index, value);
                }
                break;
            case 3:
                std::cout << "Szukana wartosc: "; 
                std::cin >> value;
                index = doublyLinkedList.find(value);
                if (index != -1) std::cout << "Znaleziono na indeksie: " << index << std::endl;
                else std::cout << "Nie znaleziono!" << std::endl;
                break;        
            case 4: {
                int size;
                std::cout << "Podaj wielkosc struktury: "; 
                std::cin >> size;
                doublyLinkedList.clear();
                rng.reset();
                for (int i = 0; i < size; i++) {
                    doublyLinkedList.addEnd(rng.generate());
                }
                break;
            }
            case 5:
                doublyLinkedList.display();
                break;
            case 6: {
                if (doublyLinkedList.getSize() == 0) {
                    std::cout << "Najpierw utworz strukture!" << std::endl;
                    break;
                }
                int iloscPomiarow;
                std::cout << "Podaj liczbe pomiarow: ";
                std::cin >> iloscPomiarow;
                int polowa = doublyLinkedList.getSize() / 2;
                TimeMeasurer<DoublyLinkedList> timer(doublyLinkedList, iloscPomiarow);

                std::cout << "addStart:         " << timer.measure([&](DoublyLinkedList& k) { k.addStart(rng.generate()); }) << " ns" << std::endl;
                std::cout << "addEnd:           " << timer.measure([&](DoublyLinkedList& k) { k.addEnd(rng.generate()); }) << " ns" << std::endl;
                std::cout << "addAt(srodek):    " << timer.measure([&](DoublyLinkedList& k) { k.addAt(polowa, rng.generate()); }) << " ns" << std::endl;
                std::cout << "removeStart:      " << timer.measure([&](DoublyLinkedList& k) { k.removeStart(); }) << " ns" << std::endl;
                std::cout << "removeEnd:        " << timer.measure([&](DoublyLinkedList& k) { k.removeEnd(); }) << " ns" << std::endl;
                std::cout << "removeAt(srodek): " << timer.measure([&](DoublyLinkedList& k) { k.removeAt(polowa); }) << " ns" << std::endl;
                std::cout << "find:             " << timer.measure([&](DoublyLinkedList& k) { k.find(rng.generate()); }) << " ns" << std::endl;
                break;
            }
        }
    }
}
