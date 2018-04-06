#include "Arete.h"

Arete::Arete(int _indice, int _s1, int _s2, float _poids){
 m_indice= _indice;
 m_s1= _s1;
 m_s2= _s2;
 m_poids= _poids;
}

Arete::~Arete(){
}

int Arete::GetIndice(){
    return m_indice;
}

int Arete::GetS1(){
    return m_s1;
}

int Arete::GetS2(){
    return m_s2;
}

float Arete::GetPoids(){
    return  m_poids;
}

float Arete::Decre_poids(){
     m_poids--;
     return m_poids;
}
