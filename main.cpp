/// Romain Dauby, programme finis le 18/03
#include <iostream>
#include <string>

#include "jeu.h"
using namespace std;

void afficherLesTours(Jeu *hanoi)
{
    stack<Plateau> pilePlateaux1;
    pilePlateaux1 = hanoi->getPremiereTour()->getPile();
    stack<Plateau> pilePlateaux2;
    pilePlateaux2 = hanoi->getDeuxiemeTour()->getPile();
    stack<Plateau> pilePlateaux3;
    pilePlateaux3 = hanoi->getTroisiemeTour()->getPile();

    for (int i=1 ; i<=hanoi->getNbPlateaux() ; i++)
    {
        if(pilePlateaux1.empty())
            cout<<"*";
        else
        {
            cout<<pilePlateaux1.top().getTaille();
            pilePlateaux1.pop();
        }
        cout<<"          ";
        if(pilePlateaux2.empty())
            cout<<"*";
        else
        {
            cout<<pilePlateaux2.top().getTaille();
            pilePlateaux2.pop();
        }
        cout<<"          ";
        if(pilePlateaux3.empty())
            cout<<"*";
        else
        {
            cout<<pilePlateaux3.top().getTaille();
            pilePlateaux3.pop();
        }
        cout<<endl;
    }
}

int main()
{
    int premier, second, number;
    Jeu *hanoi;
    cout<<"Bienvenue dans le jeu du Hanoi realise par Romain Dauby !"<<endl<<endl<<"Veuillez choisir le nombre de plateaux pour la partie :";
    cin >> number;
    hanoi = new Jeu(number);
    int curseur=0;

    while(!hanoi->gagne())
    {
        afficherLesTours(hanoi);
        cout<<endl<<"Choisissez la premiere tour :";
        cin>>premier;
        cout<<"Choisissez la seconde tour :";
        cin>>second;
        cout<<endl;
        hanoi->joue(premier, second);
        curseur++;
    }
    afficherLesTours(hanoi);
    cout<<endl<<endl<<"Finito en "<<curseur<<" coups avec "<<number<<" plateaux au depart !";

    return 0;
}
