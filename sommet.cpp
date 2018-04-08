#include "Sommet.h"

///Constructeur
Sommet::Sommet(int _indice, std::string _nom, float _population, float _x, float _y, int _delete )
{
    m_nom =_nom;
    m_population =_population;
    m_x=_x;
    m_y=_y;
    suppr=_delete;
    indice=_indice;
}

///Destructeur
Sommet::~Sommet()
{
}


///Getteurs
int Sommet::GetIndice()
{
    return indice;
}
std::string Sommet::GetNom()
{
    return m_nom;
}

float Sommet::GetPopulation()
{
    return m_population;
}

float Sommet::GetX()
{
    return m_x;
}

float Sommet::GetY()
{
    return m_y;
}

float Sommet::Decre_pop ()
{
    m_population--;
    if(m_population<0)
        m_population=0;
    return m_population;
}
