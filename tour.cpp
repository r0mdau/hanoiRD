/// Romain Dauby, programme finis le 18/03
#include <iostream>
#include "tour.h"

using namespace std;

Tour::Tour(std::string p_nom) : m_nom(p_nom)
{
}

Tour::Tour(std::string p_nom, int p_nbPlateau): m_nom(p_nom), m_nbPlateaux(p_nbPlateau)
{
    //on prend le num�ro du nombre de plateaux comme le num�ro du plus gros plateau
    //(+le num�ro du plateau est gros, + il est gros)
    int t_plateau = p_nbPlateau;
    for(int i=1; i <= p_nbPlateau; i++)
    {
        Plateau new_plateau(t_plateau);
        pilePlateaux.push(new_plateau);
        t_plateau--;
    }
}

void Tour::deplacerPlateau(Tour *p_tourArrivee)
{
    if(pilePlateaux.empty())
    {
        cout<<endl<<"La premiere pile selectionnee est vide ..."<<endl<<endl;
    }
    else if(p_tourArrivee->getPile().empty() || pilePlateaux.top().puisJeEtreDeposerSurCePlateau(p_tourArrivee->getPile().top()))
    {
        //p_tourArrivee->getPile().push(pilePlateaux.top());
        p_tourArrivee->ajouterPlateau(pilePlateaux.top()); //on ajoute le plateau sur la nouvelle pile
        pilePlateaux.pop(); //on enleve le plateau que l'on vient de d�placer
    }else
        cout <<endl<<"Vous essayez de deplacer un gros plateau sur un plus petit ..."<<endl<<endl;
}

void Tour::ajouterPlateau(Plateau papou)
{
    pilePlateaux.push(papou);
}

void Tour::afficher()
{
    cout << "Nombre de plateaux : "<<m_nbPlateaux<<endl;
}

int Tour::combienDePlateau()
{
    int tot=0;
    std::stack<Plateau> papou = pilePlateaux;
    while(!papou.empty())
    {
        tot++;
        papou.pop();
    }
    return tot;
}

int Tour::getPileSize()
{
    return pilePlateaux.size();
}

std::stack<Plateau> Tour::getPile()
{
    return pilePlateaux;
}
