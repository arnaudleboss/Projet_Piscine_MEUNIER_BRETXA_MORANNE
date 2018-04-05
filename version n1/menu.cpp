#include "menu.h"
#include "graph.h"
#include "grman/grman.h"
#include <iostream>
//Constructeur
Menu::Menu()
    :page(NULL),menu(NULL),menucolli(NULL),zone2(0),red(0),green(0),blue(0)
{

}

//Destructeur
Menu::~Menu()
{

}


//Méthode d'affichage

void Menu::PreparationMenu()
{
    //Buffer
    page= create_bitmap(SCREEN_W,SCREEN_H);
    menucolli = load_bitmap("menucolli1.png",NULL);
    menu = load_bitmap("menu1.png",NULL);

}


void Menu::AfficherMenu()
{

///positionne la bitmap à l'écran

    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    rest(20); //PROBLEME ICI : si rest(20) clignote très vite

    blit(menucolli,page,0,0,0,0,menucolli->w,menucolli->h);
    blit(menu,page,0,0,0,0, menu->w,menu->h);

}

int Menu::ChoixMenu()
{
    int i =0;
    Graph g;

    if(mouse_b&1)
    {
        zone2=getpixel(menucolli,mouse_x,mouse_y);
        red = getr(zone2);
        green = getg(zone2);
        blue = getb(zone2);

    }

    //Si on clique sur Savane
    if(red ==237 && green ==28 && blue==36)
    {
        std::cout<< "Savane"<< std::endl;
        //g.make_example();
        i = 1 ;
        //std::cout<<i;
        return i;
    }


    //Si on clique sur Air
    if(red ==34 && green ==177 && blue==76)
    {
        std::cout<< "air"<<std::endl;
        i = 2 ;
        return i ;
    }

    //Si on clique sur Mer
    if(red ==0 && green ==162 && blue==232)
    {
        std::cout<< "Mer"<< std::endl;
        i=3 ;
       // string name = "mer";
        return i;
    }

    //Si on clique sur Quitter
    if(red ==255 && green ==242 && blue==0)
    {
        ///On quitte le jeu
        std::cout<<"Appuyez sur Echap"<<std::endl;
        i = 4;
        return i;
    }

    return 0;
}
