#ifndef MENU_HPP
#define MENU_HPP

#include "dynamicArray.hpp"
#include "singlyLinkedList.hpp"
#include "doublyLinkedList.hpp"

class Menu {
private: 
    // Instancje struktury danych
    DynamicArray array;
    SinglyLinkedList singlyList;
    // DoublyLinkedList doubly list; // Do odkomentowania po zrobieniu struktury listy dwukierunkowej

    // Metody pomocnicze dla podmenu
    void menuArray();
    void menuSinglyList();
    void menuDoublyLisy();

public:
    void displayMainMenu(); // Główne menu wyboru struktury
};

#endif // MENU_HPP