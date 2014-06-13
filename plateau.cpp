/// Romain Dauby, programme finis le 18/03
#include <iostream>
#include "plateau.h"

using namespace std;

Plateau::Plateau ()
{
}


Plateau::Plateau(int p_taille) : m_taille(p_taille)
{
}

int Plateau::getTaille()
{
    return m_taille;
}

void Plateau::afficher()
{
    cout << "Taille : "<<m_taille<<endl;
}

bool Plateau::puisJeEtreDeposerSurCePlateau(Plateau p_unPlateau)
{
    return (m_taille < p_unPlateau.getTaille());
}
