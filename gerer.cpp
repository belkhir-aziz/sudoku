#include<iostream>
#include<fstream>
#include"grille.h"
#include"gerer.h"
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

void GererPartie::sauvegarder(Grille g)
{
  string sh,ch;
  cout<<"choisir un chemin pour l'enregistrement"<<endl;
  cin>>sh;

 ofstream monFlux(sh.c_str());


if(monFlux)
{


         for(int i(0);i<9;i++)
         {
           for(int j(0);j<9;j++)
           {
            monFlux << i <<" ";
            monFlux << j <<" ";
            monFlux << g.getCase(i,j).getval()<<" ";
            monFlux << g.getCase(i,j).getmodif() <<endl;
           }
         }
}
else cout<<"probleme";
}
Grille GererPartie::Reprendre(string sh)
{
 Grille g;
 int a,b,c;
 bool d;
 ifstream monFlux(sh.c_str());





for(int i(0);i<9;i++)
         {
           for(int j(0);j<9;j++)
           {

    monFlux >> a;
    monFlux >> b;
    monFlux >> c;
    monFlux >> d;

    g.setCase2(a,b,c,d);

           }
         }


 return g;
 cout<<"fichier non-existant";

}
Grille GererPartie::nouveau(Grille g)
{
     for(int i=0;i<9;i++)
   {
       srand(time(NULL));
       g.getCase(0,i).setval(rand()%9+1);

   }
      for(int i=0;i<9;i++)
   {

        if(!g.valeurvalider(0,i,g.getCase(0,i).getval()))
        {


        for(int j=0;j<9;j++)
        {

            if(g.valeurvalider(0,i,j+1))
            {
             g.getCase(0,i).setval(j+1);
            }
         }
         }



   }
}

