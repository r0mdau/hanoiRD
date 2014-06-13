/// Romain Dauby, programme finis le 18/03
#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "tour.h"

class Jeu
{
    private:
        Tour *m_premiereTour;
        Tour *m_deuxiemeTour;
        Tour *m_troisiemeTour;
        int m_nbPlateaux;

        void hanoi(int p_n, Tour *p_depart, Tour *p_inter, Tour *p_arrivee);
        void afficher();
        void deplacerPlateau(Tour *p_depart, Tour *p_arrivee);

    public:
        Jeu(int p_nbPlateau);
        void jouer();
        bool gagne();
        Tour* getPremiereTour();
        Tour* getDeuxiemeTour();
        Tour* getTroisiemeTour();
        int getNbPlateaux();
        void joue(int debut, int fin);
};

#endif // JEU_H_INCLUDED
