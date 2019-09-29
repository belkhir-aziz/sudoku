#ifndef MACHINE_H_INCLUDED
#define MACHINE_H_INCLUDED
#include<deque>
#include"joueur.h"
#include"grille.h"
class Machine : public joueur
{


public:
   std::pair<position,int> choisirCoup(Grille g);
  // deque<int>m[81];

public:
   virtual void remplir(Grille);
   virtual bool Resoudre(Grille g,int e);
   virtual bool resoudre(Grille){};
   Grille *solution;
   Grille miseajour(Grille);
   deque<int>m[81];



};


#endif // JOUEUR_H_INCLUDED
