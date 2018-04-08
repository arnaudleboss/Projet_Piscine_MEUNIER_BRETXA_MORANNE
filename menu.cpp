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
    //Chargement de l'image ainsi que de l'image de collision
    menucolli = load_bitmap("menucolli1.png",NULL);
    menu = load_bitmap("menu1.png",NULL);

}


void Menu::AfficherMenu()
{

/// On positionne la bitmap à l'écran

    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    rest(20);

    blit(menucolli,page,0,0,0,0,menucolli->w,menucolli->h);
    blit(menu,page,0,0,0,0, menu->w,menu->h);

}


int Menu::ChoixMenu()
{
    int i =0;
    Graph g;

    //Si on clique sur l'ecran alors on recupere les pixels rouges, verts et bleus de la zone cliquée
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

        //La variable i va prendre pour valeur 1, et on retourne cette variable
        i = 1 ;
        return i;
    }


    //Si on clique sur Air
    if(red ==34 && green ==177 && blue==76)
    {
        std::cout<< "air"<<std::endl;

        //La variable i va prendre pour valeur 2, et on retourne cette variable
        i = 2 ;
        return i ;
    }

    //Si on clique sur Mer
    if(red ==0 && green ==162 && blue==232)
    {

        //La variable i va prendre pour valeur 3, et on retourne cette variable
        std::cout<< "Mer"<< std::endl;
        i=3 ;
        return i;
    }

    //Si on clique sur Quitter
    if(red ==255 && green ==242 && blue==0)
    {
        ///On quitte le jeu
        std::cout<<"Appuyez sur Echap"<<std::endl;

        //La variable i va prendre pour valeur 1, et on retourne cette variable
        i = 4;
        return i;
    }

    return 0;
}
