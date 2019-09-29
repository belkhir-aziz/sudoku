#include<iostream>
#include<fstream>
#include"grille.h"
#include"gerer.h"
#include<string>
#include<ctime>
#include<cstdlib>
#include "automatique.h"
#include "machine4.h"

Grille automatique::masquer(Grille g)

{
int h=0 ;
    do
    {

    int i=rand()%9;

    int j=rand()%9;



       if(g.getCase(i,j).getval()!=0)
       {


        g.setCase2(i,j,0,true);
        ++h;

        }
    }while(h<10);
   return g;


}



Grille automatique::nouveau(Grille g)
{   Machine4 m;
     srand(time(0));
    int p=0 ;
    int x;
    for(int i=0;i<3 ;i++)
    {
         x=rand()%9+1;
        g.setCase1(0,i,x);
    }
    for(int i=0;i<3;i++)
    {
        if(g.valeurvalider(0,i,g.getCase(0,i).getval()))
        {
            g.getCase(0,i).setmodif(false);
        }
        else
            g.getCase(0,i).setval(0);
    }




 m.resoudre(g);




return g;

}
Grille automatique::generergrille(Grille g)
{

    g=nouveau(g);
    g=masquer(g);
    cout<<g;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(g.getCase(i,j).getval()==0)
                g.setCase2(i,j,0,true);
            else
                g.setCase2(i,j,g.getCase(i,j).getval(),false);
        }
    }

    return g;
}

