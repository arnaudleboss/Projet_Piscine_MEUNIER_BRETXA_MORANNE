#include "Sommet.h"

Sommet::Sommet(std::string _nom, float _population, float _x, float _y ){
    m_nom =_nom;
    m_population =_population;
    m_x=_x;
    m_y=_y;
}

Sommet::~Sommet(){
}

std::string Sommet::GetNom(){
    return m_nom;
}

float Sommet::GetPopulation(){
    return m_population;
}

float Sommet::GetX(){
return m_x;
}

float Sommet::GetY(){
return m_y;
}
