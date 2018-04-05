#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "allegro.h"
#include "Graph.h"
#include "grman/grman.h"
#include <iostream>


class Menu
{
public:
    // Image m�moire servant � m�moriser l'�cran
    BITMAP *page;
    BITMAP *menu;
    BITMAP *menucolli;
    int zone2;
    int red, green, blue;
    Graph g ;


    Menu();
    ~Menu();

    //M�thodes
    void AfficherMenu() ;
    void PreparationMenu();
    int ChoixMenu();

};


#endif // MENU_H_INCLUDED
