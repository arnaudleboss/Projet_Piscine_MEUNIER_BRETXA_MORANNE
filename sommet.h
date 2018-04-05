#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <iostream>

class Sommet
{
    public:
    Sommet(std::string _nom, float _population, float _x, float _y);
    ~Sommet();
    std::string m_nom;
    float m_population,m_x, m_y;

    std::string GetNom();
    float GetPopulation();
    float GetX();
    float GetY();
};

#endif // SOMMET_H_INCLUDED
