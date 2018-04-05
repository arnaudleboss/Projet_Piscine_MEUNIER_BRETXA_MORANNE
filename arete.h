#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED

class Arete
{
    public:
        Arete(int _indice, int _s1, int _s2, float _poids);
        ~Arete();
    int m_indice, m_s1, m_s2;
    float m_poids;

   int GetIndice();
   int GetS1();
   int GetS2();
   float GetPoids();

};


#endif // ARETE_H_INCLUDED
