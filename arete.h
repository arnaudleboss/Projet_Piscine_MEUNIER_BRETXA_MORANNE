#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED

class Arete
{
public:
    Arete(int _indice, int _s1, int _s2, float _poids);
    ~Arete();
    ///Création de variables
    int m_indice ;//l 'indice de l'arete l
    int  m_s1, m_s2; //le premier et le deuxième sommet auquel l'arete est reliée
    float m_poids;  //Poids de l'arete

    int GetIndice();
    int GetS1();
    int GetS2();
    float GetPoids();
    float Decre_poids();

};


#endif // ARETE_H_INCLUDED
