#ifndef AUTOMATIQUE_H_INCLUDED
#define AUTOMATIQUE_H_INCLUDED
#include"generateur.h"
class automatique :public generateur
{

    private:
    Grille masquer(Grille g);

    Grille nouveau(Grille g);
    public:
    Grille generergrille(Grille g);
};


#endif // AUTOMATIQUE_H_INCLUDED
