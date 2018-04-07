#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <iostream>

class Sommet
{
    public:
    Sommet(int _indice, std::string _nom, float _population, float _x, float _y, int _delete);
    ~Sommet();
    std::string m_nom;
    float m_population,m_x, m_y;
    int suppr;
    int indice;
    std::string GetNom();
    int GetIndice();
    float GetPopulation();
    float GetX();
    float GetY();
    float Decre_pop ();
};

#endif // SOMMET_H_INCLUDED
