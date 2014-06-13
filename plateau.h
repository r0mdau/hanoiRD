/// Romain Dauby, programme finis le 18/03
#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

class Plateau
{
    private:
        int m_taille; //taille du plateau

    public:
        Plateau ();
        Plateau (int p_taille);
        int getTaille();
        bool puisJeEtreDeposerSurCePlateau(Plateau p_unPlateau);
        void afficher();
};

#endif // PLATEAU_H_INCLUDED
