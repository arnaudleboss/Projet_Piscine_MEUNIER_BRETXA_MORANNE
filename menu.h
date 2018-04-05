#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "allegro.h"
#include "Graph.h"
#include "grman/grman.h"
#include <iostream>


class Menu
{
public:
    // Image mémoire servant à mémoriser l'écran
    BITMAP *page;
    BITMAP *menu;
    BITMAP *menucolli;
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
