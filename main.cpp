#include <iostream>
#include<cstdlib>
#include"grille.h"
#include"homme.h"
#include"joueur.h"
#include"gerer.h"
#include"machine.h"
#include"machine1.h"
#include"machine2.h"
#include"machine3.h"
#include"machine4.h"
#include"manuel.h"
#include "automatique.h"
#include"generateur.h"
#include<utility>
#include<string>
using namespace std;

int main()
{
int a;
int b,c;
int mode;
Grille h;
generateur*g;
GererPartie p;
joueur*j;
string chemin;


     do
     {

         cout<<"Nouveau jeu(1)\nReprendre(2)\nQuitter(3)\n";
         cin>>a;
         switch (a){



          case 1 :
             {

              do
              {
                  cout<<"Gerer manuellement(1)\nGerer automatiquement(2)\nQuitter(3)\n";
                  cin>>b;
                  switch (b){
              case 1:
                g=new manuel;
                break;
              case 2:
                g=new automatique;
                break;
              case 3:
                exit(0);
                break;
              default:
                break;

                }
            if((b==1)||(b==2))
            {

               h=g->generergrille(h);
            }
              }while((b!=1)&&(b!=2)&&(b!=3));

             break;}
          case 2  :
              {
                  cout<<"donner le chemin";
                  cin>>chemin;
                  h=p.Reprendre(chemin);
                  break;

              }


          case 3:
           exit(0);
          default :
            break;

  }   }while((a!=1)&&(a!=2)&&(a!=3));
 /************************************************************************************/
  Grille v;
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
     if(h.getCase(i,j).getval()==0)
     {
         v.setCase2(i,j,0,true);
     }
     else
     {
       v.setCase2(i,j,h.getCase(i,j).getval(),false);
     }
    }}

    /*****************************************************************************************/
  do
  {
      cout<<"mode Humain(1)\nMachine 1 (2)\n Machine 2 (3)\n Machine 3 (4) \n Machine 4 (5)\nSauvegarder(6)\nQuitter(7)\n";
      cin>>c;
      switch (c) {
  case 1 :
    j=new Homme;
    break;
  case 2 :
    j=new Machine1;
    break;
  case 3 :
    j=new Machine2;
    break ;
  case 4 :
    j=new Machine3;
    break ;
  case 5:
    j=new Machine4;
    break ;
  case 6:
      p.sauvegarder(v);
      break;
   case 7:
   exit(0);
   default :
    break;}






  }while((c!=1)&&(c!=2)&&(c!=3)&&(c!=4)&&(c!=5)&&(c!=6)&&(c!=7));

int coup;


if((c==1)||(c==2)||(c==3)||(c==4)||(c==5))
{
   std::pair <position,int> Pair;
   while(!h.pleine())
   {

       Pair=j->choisirCoup(h);
     do
        { cin>>coup;
       switch(coup){
   case 0 :
       {
           h.setCase1(Pair.first.lig,Pair.first.col,Pair.second);


           break;
       }
   case 1 :
    {


     do
  {
      cout<<"mode Humain(1)\nMachine 1 (2)\n Machine 2 (3)\n Machine 3 (4) \n Machine 4 (5)\n";
      cin>>mode;
      switch (mode) {
  case 1 :
    j=new Homme;
    break;
  case 2 :
    j=new Machine1;

    break;
  case 3 :
    j=new Machine2;
    break ;
  case 4 :
    j=new Machine3;
    break ;
  case 5:
    j=new Machine4;
    break ;


   default :
    break;}






  }while((mode!=1)&&(mode!=2)&&(mode!=3)&&(mode!=4)&&(mode!=5));





break;


    }

  case  2:
      {

       p.sauvegarder(h);
      break;}
   case 3:
   exit(0);
   case 4:
    {
        Machine2 m;
        m.resoudre(h);
        cout<<h;
    }
   default :
    break;}





       }while((coup!=0)&&(coup!=1)&&(coup!=2)&&(coup!=3));



   }

}


return 0;

}
