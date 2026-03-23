#include "menu.hpp"
#include <iostream>
#include <string>

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
            case 3: menuDoublyLisy(); break;
            case 0: std::cout << "Zamykanie programu..." << std::endl;
            default: std::cout << "Bledny wybor!" << std::endl;
        }
    }
}

// Podmenu dla Tablicy Dynamicznej
void Menu::menuArray() {
    int choice = -1;
    int value, index, subChoice;
    std::string fileName;

    while (choice != 0) {
        std::cout << "\n--- TABLICA DYNAMICZNA ---" << std::endl;
        std::cout << "1. Zbuduj z pliku" << std::endl; // Musi najpierw usunąć stare dane
        std::cout << "2. Usun (poczatek/koniec/losowe)" << std::endl;
        std::cout << "3. Dodaj (poczatek/koniec/losowe)" << std::endl;
        std::cout << "4. Znajdz" << std::endl;
        std::cout << "5. Wyswietl" << std::endl;
        std::cout << "0. Powrot" << std::endl;
        std::cout << "Wybor: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> fileName;
                array.clear();      // Obowiazkowe czysczenie przed wycztaniem
                // Tu wywołamy FileManager, gdy go napiszemy
                break;
            case 2:
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
            case 3:
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
            case 4:
                std::cout << "Szukana wartosc: "; 
                std::cin >> value;
                index = array.find(value);
                if (index != -1) std::cout << "Znaleziono na indeksie: " << index << std::endl;
                else std::cout << "Nie znaleziono!" << std::endl;
                break;
            case 5:
                int size;
                std::cout << "Podaj wielkosc struktury: "; 
                std::cin >> size; 
                array.clear();
                // Tutaj petla generujaca 'size' losowych elementow 4-bajtowych 
                break;
            case 6:
                array.display(); 
                break;

        }
    }
}

// Podmenu dla Listy Jednokierunkowej