/// Romain Dauby, programme finis le 18/03/12
#include <iostream>
#include "jeu.h"

using namespace std;

Jeu::Jeu(int p_nbPlateau)
{
    m_premiereTour = new Tour("a", p_nbPlateau);
    m_deuxiemeTour = new Tour("b");
    m_troisiemeTour = new Tour("c");
    m_nbPlateaux=p_nbPlateau;
}

bool Jeu::gagne()
{
    return (m_nbPlateaux == m_troisiemeTour->combienDePlateau());
}

void Jeu::jouer()
{
    hanoi(m_premiereTour->combienDePlateau(), m_premiereTour, m_deuxiemeTour, m_troisiemeTour);
}

void Jeu::deplacerPlateau(Tour *p_depart, Tour *p_arrivee)
{
    p_depart->deplacerPlateau(p_arrivee);
}

void Jeu::afficher()
{
    m_premiereTour->afficher();
    m_deuxiemeTour->afficher();
    m_troisiemeTour->afficher();
}

void Jeu::hanoi(int p_n, Tour *p_depart, Tour *p_inter, Tour *p_arrivee)
{
    if(p_n==1)
        deplacerPlateau(p_depart, p_arrivee);
    else
    {
        hanoi(p_n-1, p_depart, p_arrivee, p_inter);
        deplacerPlateau(p_depart, p_arrivee);
        hanoi(p_n-1, p_inter, p_depart, p_arrivee);
    }
}

int Jeu::getNbPlateaux()
{
    return m_nbPlateaux;
}

Tour* Jeu::getPremiereTour()
{
    return m_premiereTour;
}

Tour* Jeu::getDeuxiemeTour()
{
    return m_deuxiemeTour;
}

Tour* Jeu::getTroisiemeTour()
{
    return m_troisiemeTour;
}

void Jeu::joue(int debut, int fin)
{
    if(debut==1 && fin==2)
    {
        deplacerPlateau(m_premiereTour, m_deuxiemeTour);
    }
    else if(debut==1 && fin==3)
    {
        deplacerPlateau(m_premiereTour, m_troisiemeTour);
    }
    else if(debut==2 && fin==1)
    {
        deplacerPlateau(m_deuxiemeTour, m_premiereTour);
    }
    else if(debut==2 && fin==3)
    {
        deplacerPlateau(m_deuxiemeTour, m_troisiemeTour);
    }
    else if(debut==3 && fin==1)
    {
        deplacerPlateau(m_troisiemeTour, m_premiereTour);
    }
    else if(debut==3 && fin==2)
    {
        deplacerPlateau(m_troisiemeTour, m_deuxiemeTour);
    }
    else if(debut==fin)
    {
        cout<<endl<<"Vous avez choisi deux fois la meme tour ..."<<endl;
    }
    else
        cout<<endl<<"Vous devez ecrire un chiffre allant de 1 a 3"<<endl;
}
