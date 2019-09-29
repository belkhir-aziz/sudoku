#ifndef HOMME_H_INCLUDED
#define HOMME_H_INCLUDED
#include"joueur.h"
class Homme :public joueur
{public:
std::pair<position,int> choisirCoup(Grille);

};
#endif // HOMME_H_INCLUDED
