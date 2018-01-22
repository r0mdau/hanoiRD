/// Romain Dauby, programme finis le 18/03
#ifndef TOUR_H_INCLUDED
#define TOUR_H_INCLUDED

#include <stack>
#include <string>
#include "plateau.h"

class Tour
{
    private:
        std::string m_nom;
        int m_nbPlateaux;
        std::stack<Plateau> pilePlateaux; //pile de plateaux

    public:
        Tour(std::string p_nom);
        Tour(std::string p_nom, int p_nbPlateau);
        void deplacerPlateau(Tour *p_tourArrivee);
        void afficher();
        int combienDePlateau();
        int getPileSize();
        std::stack<Plateau> getPile();
        void ajouterPlateau(Plateau papou);
};

#endif // TOUR_H_INCLUDED
