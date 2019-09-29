#ifndef GENERATEUR_H_INCLUDED
#define GENERATEUR_H_INCLUDED
#include"grille.h"
class generateur
{
  public:
  Grille virtual generergrille(Grille g)=0;
Grille grillevide()
{
    Grille g;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            g.setCase2(i,j,0,true);
        }
    }
    return g;
}
};


#endif // GENERATEUR_H_INCLUDED
