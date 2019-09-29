#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED
#include<iostream>
using namespace std;
typedef struct position
{
public:
    int lig;
    int col;
}position;
class Case
{


int ligne;
int colonne;
int val;
bool modif;
public:
Case(int a,int b,int c,int d){ligne=a;colonne=b;val=c;modif=d;}
Case(int a,int b,int c){ligne=a;colonne=b;val=c;}
Case(){};
int getval(){return val;}
void setval(int a){val=a;}
bool getmodif(){return modif;}
void setmodif(bool b){modif=b;}
//int getligne(){return ligne;}
//void setligne(int a){ligne=a;}
//int getcolonne(){return colonne;}
//void setcolonne(int a){colonne=a;}


};
class Grille
{


  // Case **grille;
   public:
   Grille();
   Case getCase(int i,int j);
   void setCase1(int i,int j,int v);
   void setCase2(int i,int j,int v,bool m);
   friend ostream& operator<<(ostream&,Grille&);
   bool absentligne(int ,int,int);
   bool absentcolonne(int i,int j,int v);
   bool absentbloc(int i,int j,int v);
   bool valeurvalider(int i,int j,int v);
   bool pleine();
   Case **grille;

};
#endif // GRILLE_H_INCLUDED
