#include "grman/grman.h"
#include <iostream>

#include "graph.h"

int main()
{
    grman::init();
    grman::set_pictures_path("pics");

    Graph g;

    //g.Construire_le_graphe("Ocean.txt");
     g.Construire_le_graphe("Air.txt");
    //g.Construire_le_graphe("Savane.txt");

    while ( !key[KEY_ESC] )
    {

        /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
        g.update();

        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


