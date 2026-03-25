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
    DoublyLinkedList doublylist; // Do odkomentowania po zrobieniu struktury listy dwukierunkowej

    // Metody pomocnicze dla podmenu
    void menuArray();
    void menuSinglyList();
    void menuDoublyList();

public:
    void displayMainMenu(); // Główne menu wyboru struktury
};

#endif // MENU_HPP