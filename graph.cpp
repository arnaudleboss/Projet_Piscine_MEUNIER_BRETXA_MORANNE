#include "graph.h"
#include "sommet.h"
#include "arete.h"
#include <fstream>

/***************************************************
                    VERTEX
****************************************************/

/// Le constructeur met en place les éléments de l'interface
VertexInterface::VertexInterface(int idx, int x, int y, std::string pic_name, int pic_idx)
{
    // La boite englobante
    m_top_box.set_pos(x, y);
    m_top_box.set_dim(130, 100);
    m_top_box.set_moveable();

    // Le slider de réglage de valeur
    m_top_box.add_child( m_slider_value );
    m_slider_value.set_range(0.0 , 100.0); // Valeurs arbitraires, à adapter...
    m_slider_value.set_dim(20,80);
    m_slider_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);

    // Label de visualisation de valeur
    m_top_box.add_child( m_label_value );
    m_label_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Down);

    // Une illustration...
    if (pic_name!="")
    {
        m_top_box.add_child( m_img );
        m_img.set_pic_name(pic_name);
        m_img.set_pic_idx(pic_idx);
        m_img.set_gravity_x(grman::GravityX::Right);
    }

    // Label de visualisation d'index du sommet dans une boite
    m_top_box.add_child( m_box_label_idx );
    m_box_label_idx.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);
    m_box_label_idx.set_dim(20,12);
    m_box_label_idx.set_bg_color(BLANC);

    m_box_label_idx.add_child( m_label_idx );
    m_label_idx.set_message( std::to_string(idx) );
}


/// Gestion du Vertex avant l'appel à l'interface
void Vertex::pre_update()
{
    if (!m_interface)
        return;

    /// Copier la valeur locale de la donnée m_value vers le slider associé
    m_interface->m_slider_value.set_value(m_value);

    /// Copier la valeur locale de la donnée m_value vers le label sous le slider
    m_interface->m_label_value.set_message( std::to_string( (int)m_value) );
}


/// Gestion du Vertex après l'appel à l'interface
void Vertex::post_update()
{
    if (!m_interface)
        return;

    /// Reprendre la valeur du slider dans la donnée m_value locale
    m_value = m_interface->m_slider_value.get_value();
}



/***************************************************
                    EDGE
****************************************************/

/// Le constructeur met en place les éléments de l'interface
EdgeInterface::EdgeInterface(Vertex& from, Vertex& to)
{
    // Le WidgetEdge de l'interface de l'arc
    if ( !(from.m_interface && to.m_interface) )
    {
        std::cerr << "Error creating EdgeInterface between vertices having no interface" << std::endl;
        throw "Bad EdgeInterface instanciation";
    }
    m_top_edge.attach_from(from.m_interface->m_top_box);
    m_top_edge.attach_to(to.m_interface->m_top_box);
    m_top_edge.reset_arrow_with_bullet();

    // Une boite pour englober les widgets de réglage associés
    m_top_edge.add_child(m_box_edge);
    m_box_edge.set_dim(24,60);
    m_box_edge.set_bg_color(BLANCBLEU);

    // Le slider de réglage de valeur
    m_box_edge.add_child( m_slider_weight );
    m_slider_weight.set_range(0.0 , 100.0); // Valeurs arbitraires, à adapter...
    m_slider_weight.set_dim(16,40);
    m_slider_weight.set_gravity_y(grman::GravityY::Up);

    // Label de visualisation de valeur
    m_box_edge.add_child( m_label_weight );
    m_label_weight.set_gravity_y(grman::GravityY::Down);

}


/// Gestion du Edge avant l'appel à l'interface
void Edge::pre_update()
{
    if (!m_interface)
        return;

    /// Copier la valeur locale de la donnée m_weight vers le slider associé
    m_interface->m_slider_weight.set_value(m_weight);

    /// Copier la valeur locale de la donnée m_weight vers le label sous le slider
    m_interface->m_label_weight.set_message( std::to_string( (int)m_weight ) );
}

/// Gestion du Edge après l'appel à l'interface
void Edge::post_update()
{
    if (!m_interface)
        return;

    /// Reprendre la valeur du slider dans la donnée m_weight locale
    m_weight = m_interface->m_slider_weight.get_value();
}



/***************************************************
                    GRAPH
****************************************************/

/// Ici le constructeur se contente de préparer un cadre d'accueil des
/// éléments qui seront ensuite ajoutés lors de la mise ne place du Graphe
GraphInterface::GraphInterface(int x, int y, int w, int h)
{
    m_top_box.set_dim(1000,740);
    m_top_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);

    m_top_box.add_child(m_tool_box);
    m_tool_box.set_dim(80,720);
    m_tool_box.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);
    m_tool_box.set_bg_color(BLANCBLEU);

    m_top_box.add_child(m_main_box);
    m_main_box.set_dim(908,720);
    m_main_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);
    m_main_box.set_bg_color(BLANCJAUNE);

     /// On ajoute en haut à droite la boite à boutons
    m_tool_box.add_child( m_boite_boutons );
    m_boite_boutons.set_dim(74,80);
    m_boite_boutons.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up );
    m_boite_boutons.set_bg_color(BLANC);
    m_boite_boutons.set_moveable();

    /// Puis un 1er bouton avec un texte
    m_boite_boutons.add_child( m_bouton1 );
    m_bouton1.set_frame(0,0,77,26);
    m_bouton1.set_bg_color(GRISCLAIR);
    m_bouton1.add_child(m_bouton1_label);
    m_bouton1_label.set_message("ADD");

    /// Puis un 2eme bouton avec un texte
    m_boite_boutons.add_child( m_bouton2 );
    m_bouton2.set_frame(0,27,77,26);
    m_bouton2.set_bg_color(GRISCLAIR);
    m_bouton2.add_child(m_bouton2_label);
    m_bouton2_label.set_message("SAVE");

    /// Puis un 3eme bouton avec une texte

    m_boite_boutons.add_child( m_bouton3 );
    m_bouton3.set_frame(0,54,77,26);
    m_bouton3.set_bg_color(ROUGE);
    m_bouton3.add_child(m_bouton3_label);
    m_bouton3_label.set_message("DELETE");
}


/// Méthode spéciale qui construit un graphe

void Graph::Construire_le_graphe(std::string fichier)
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);

    /// Les sommets doivent être définis avant les arcs
    // Ajouter le sommet d'indice 0 de valeur 30 en x=200 et y=100 avec l'image clown1.jpg etc...
    //std::vector <Sommet*> m_sommet;
    //std::vector <Arete*> m_arete;

    std::ifstream load(fichier, std::ios::in);
    unsigned int ordre, nombre_arete, indice, s1, s2,x,y;
    float b,poids;
    std::string a;
       if(load){
            load>>ordre;
            load>>nombre_arete;
            for (unsigned int i=0;i<ordre;i++) {
            load>>a, load>>b, load>>x, load>>y;
            m_sommet.push_back(new Sommet(a,b,x,y));
            }

           for (unsigned int i=0;i<nombre_arete;i++) {
            load>>indice, load>>s1, load>>s2, load>>poids;
            //add_interfaced_edge(indice, s1, s2, poids);
            m_arete.push_back(new Arete(indice,s1,s2,poids));
            }


       }
         load.close();

       // Afficher les sommets et les arretes

        for (unsigned int i=0;i<ordre;i++) {
         add_interfaced_vertex(i, m_sommet[i]->GetPopulation(), m_sommet[i]->GetX(), m_sommet[i]->GetY(), m_sommet[i]->GetNom() + ".bmp");
        }

          /*for (unsigned int i=0; i<nombre_arete;i++){
            add_interfaced_edge(m_arete[i]->GetIndice(), m_arete[i]->GetS1(), m_arete[i]->GetS2(), m_arete[i]->GetPoids());
        }*/

        //m_areteAff.push_back(m_arete[1]);
        //for (unsigned int i=0; i<m_areteAff.size();i++){
          //  add_interfaced_edge(i, m_areteAff[i]->GetS1(), m_areteAff[i]->GetS2(), m_areteAff[i]->GetPoids());
       // }



        std::ofstream save(fichier, std::ios::out);  // ouverture en écriture avec effacement du fichier ouvert
        if(save){
            save<<m_sommet.size() << std::endl << m_arete.size()<< std::endl;
            for (unsigned int i=0; i<m_sommet.size(); i++){
            save<<m_sommet[i]->GetNom()<< " " << m_sommet[i]->GetPopulation()<< " " <<m_sommet[i]->GetX()<< " " <<m_sommet[i]->GetY()<<std::endl;
                        }
            for (unsigned int i=0; i<m_arete.size(); i++){
            save<<m_arete[i]->GetIndice()<< " "<< m_arete[i]->GetS1() << " "<< m_arete[i]->GetS2() << " " << m_arete[i]->GetPoids()<<std::endl;
                        }
        save.close();
        }

}


/// La méthode update à appeler dans la boucle de jeu pour les graphes avec interface
void Graph::update()
{
    if (!m_interface)
        return;

    for (auto &elt : m_vertices)
        elt.second.pre_update();

    for (auto &elt : m_edges)
        elt.second.pre_update();

    m_interface->m_top_box.update();

    for (auto &elt : m_vertices)
        elt.second.post_update();

    for (auto &elt : m_edges)
        elt.second.post_update();

         if (m_interface->m_bouton1.clicked())
        etat_bouton = 1;
    if(m_interface->m_bouton2.clicked())
        etat_bouton = 2;
    if(m_interface->m_bouton3.clicked())
        etat_bouton = 3;

    if(etat_bouton == 1)
    {
        std::cout<<"quelle arrete voulez vous creer ?" << std::endl;
        std::cout<<"premier sommet : " <<std::endl;
        std::cin >> s1;
        std::cout<<"deuxieme sommet : "<<std::endl;
        std::cin >> s2;

        for(unsigned int i = 0; i< m_arete.size();i++)
        {
            if(s1 == m_arete[i]->GetS1() && s2 == m_arete[i]->GetS2())
            {
            m_areteAff.push_back(m_arete[i]);
//            add_interfaced_edge(m_areteAff[i]->GetIndice(), m_areteAff[i]->GetS1, m_areteAff[i]->GetS2, m_areteAff[i]->GetPoids());
            trouve = 1;

            }
            else if((trouve != 1) && (i == m_arete.size()-1))
                std::cout << "pas d'arrete correspondante" << std::endl;

        }

        trouve = 0;


        for(unsigned int i=0;i<m_areteAff.size();i++)
        {
            std::cout << m_areteAff[i]->m_s1 << std::endl << m_areteAff[i]->m_s2 << std::endl << m_areteAff[i]->m_indice << std::endl << m_areteAff[i]->m_poids << std::endl;
        }

        etat_bouton = 0;
    }

    if(etat_bouton == 3)
    {
        std::cout << "quel sommet voulez vous supprimer ?" << std::endl;
        std::cin >> sommet;
        for(unsigned int i = 0; i< m_arete.size();i++)
        {
            if(sommet == m_arete[i]->GetS1())
            {
                std::cout << "trouve !" << m_arete[i]->GetS1() << std::endl;

            }
        }
        etat_bouton = 0;

    }

}

/// Aide à l'ajout de sommets interfacés
void Graph::add_interfaced_vertex(int idx, double value, int x, int y, std::string pic_name, int pic_idx )
{
    if ( m_vertices.find(idx)!=m_vertices.end() )
    {
        std::cerr << "Error adding vertex at idx=" << idx << " already used..." << std::endl;
        throw "Error adding vertex";
    }
    // Création d'une interface de sommet
    VertexInterface *vi = new VertexInterface(idx, x, y, pic_name, pic_idx);
    // Ajout de la top box de l'interface de sommet
    m_interface->m_main_box.add_child(vi->m_top_box);
    // On peut ajouter directement des vertices dans la map avec la notation crochet :
    m_vertices[idx] = Vertex(value, vi);
}

/// Aide à l'ajout d'arcs interfacés
void Graph::add_interfaced_edge(int idx, int id_vert1, int id_vert2, double weight)
{
    if ( m_edges.find(idx)!=m_edges.end() )
    {
        std::cerr << "Error adding edge at idx=" << idx << " already used..." << std::endl;
        throw "Error adding edge";
    }

    if ( m_vertices.find(id_vert1)==m_vertices.end() || m_vertices.find(id_vert2)==m_vertices.end() )
    {
        std::cerr << "Error adding edge idx=" << idx << " between vertices " << id_vert1 << " and " << id_vert2 << " not in m_vertices" << std::endl;
        throw "Error adding edge";
    }

    EdgeInterface *ei = new EdgeInterface(m_vertices[id_vert1], m_vertices[id_vert2]);
    m_interface->m_main_box.add_child(ei->m_top_edge);
    m_edges[idx] = Edge(weight, ei);
}

