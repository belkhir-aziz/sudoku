#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include"grille.h"
class joueur
{public:
virtual std::pair<position,int>choisirCoup(Grille g)=0;

};


#endif // JOUEUR_H_INCLUDED
