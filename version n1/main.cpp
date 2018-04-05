#include "grman/grman.h"
#include <iostream>
#include "menu.h"


int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");

    Menu M;
    M.PreparationMenu();

    int i=6;


    ///-----------Affichage du Menu et selection du niveau------------------------
    while ((i != 1) && (i!=2) && (i!=3)  && (i!=4))
    {
        M.AfficherMenu();
        i= M.ChoixMenu();
        //std::cout<< "on obtient un "<< i<<std::endl;
    }


    /// -----------Affichage en fonction du graphe choisi---------------------
   // Graph g;
bool sortie = false ;

while (sortie==false)
{
    i= M.ChoixMenu();
    Graph g;
    //std::cout<<"on entre dans le while"<< std::endl;
    ///Si on clique sur Savane
    if( i==1)
    {
        g.Construire_le_graphe("Savane.txt"); //--> Affichage du graphe Savane
        int j = 1;
        sortie = false ;

        while(j!=2 )
        {
            /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
            g.update();

            /// Mise à jour générale (clavier/souris/buffer etc...)
            grman::mettre_a_jour();

            if (key[KEY_RIGHT])
            {
                j= 2; //ON sort de la boucle
            }

        }

        ///ON affiche a nouveau le menu
        Menu M;
        M.PreparationMenu();

        int i=6;

        ///-----------Affichage du Menu et selection du niveau------------------------
        while ((i != 1) && (i!=2) && (i!=3) && (i!=4))
        {
            M.AfficherMenu();
            i= M.ChoixMenu();
           // std::cout<< "on obtient un "<< i<<std::endl;
        }



    }


///Si on a cliqué sur Air

    if( i==2)
    {
        g.Construire_le_graphe("Air.txt"); //--> Affichage du graphe
        int j =1;
        sortie = false;

        while(j!=2)
        {
            /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
            g.update();

            /// Mise à jour générale (clavier/souris/buffer etc...)
            grman::mettre_a_jour();

            if (key[KEY_RIGHT])
            {
                j= 2; //ON sort de la boucle
            }
        }

        ///ON affiche a nouveau le menu
        Menu M;
        M.PreparationMenu();

        int i=6;

        ///-----------Affichage du Menu et selection du niveau------------------------
        while ((i != 1) && (i!=2) && (i!=3)&& (i!=4))
        {
            M.AfficherMenu();
            i= M.ChoixMenu();
            //std::cout<< "on obtient un "<< i<<std::endl;
        }

    }



    ///SI on a cliqué sur la Mer

    if( i==3)
    {
        g.Construire_le_graphe("OCEAN.txt"); //--> Affichage du graphe
        int j = 1;
        sortie = false;

        while( j!= 2)
        {
            /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
            g.update();

            /// Mise à jour générale (clavier/souris/buffer etc...)
            grman::mettre_a_jour();


            if (key[KEY_RIGHT])
            {
                j= 2; //ON sort de la boucle
            }

        }

        ///ON affiche a nouveau le menu
        Menu M;
        M.PreparationMenu();

        int i=6;

        ///-----------Affichage du Menu et selection du niveau------------------------
        while ((i != 1) && (i!=2) && (i!=3) && (i!=4))
        {
            M.AfficherMenu();
            i= M.ChoixMenu();
           // std::cout<< "on obtient un "<< i<<std::endl;
        }


    }

    if(i==4)
    {
        //return 0;
        sortie = true;
    }



   // std::cout <<"sortie : " <<sortie << std::endl ;
    //std::cout <<"i " <<i<< std::endl ;



}
        return 0;
        grman::fermer_allegro();

}
END_OF_MAIN();


