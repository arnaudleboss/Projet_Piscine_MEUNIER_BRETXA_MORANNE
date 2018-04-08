#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "allegro.h"
#include "Graph.h"
#include "grman/grman.h"
#include <iostream>


class Menu
{
public:

    BITMAP *page;   //Buffer
    BITMAP *menu;   //Image pour le menu
    BITMAP *menucolli;  //Image de collision du menu
    int zone2;
    int red, green, blue;
    Graph g ;


    Menu();
    ~Menu();

    //Méthodes
    void AfficherMenu() ;
    void PreparationMenu();
    int ChoixMenu();

};


#endif // MENU_H_INCLUDED
