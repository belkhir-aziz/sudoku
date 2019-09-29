#include<iostream>
#include"machine4.h"
#include"joueur.h"
#include<vector>
using namespace std;
bool Machine4::resoudre(Grille g)
    {
    remplir(g);

   return Resoudre2(g,0);


  cout<<g;
    };
int Machine4::suivant(int e)
{

   // if(e==80)return 81;
    if((e/9)%2==0)
    {
        if(e%9==8)
        {return e+9;}
        else return e+1;

    }
    else
        {
         if(e%9==0)
        {return e+9;}
        else return e-1;

        }



}





 bool Machine4::Resoudre2(Grille g,int e)
{
if(e>80)
    {solution=new Grille;
      for(int i=0;i<9;i++)
      {
          for(int j=0;j<9;j++)
          {
            solution->setCase2(i,j,g.getCase(i,j).getval(),g.getCase(i,j).getmodif());

          }
      }
        return true;}
        else
        {


    position p;
     p.lig=m[e].front()/9;
       p.col=m[e].front()%9;


    if(g.getCase(p.lig,p.col).getmodif()==false)

    {

    return Resoudre2(g,suivant(e));
    }

    deque<int>::iterator it;
    it=m[e].begin();
    while(it!=m[e].end())
    {
     ++it;
     if(g.valeurvalider(p.lig,p.col,*it))

     {
         g.setCase1(p.lig,p.col,*it);
       //  cout<<g;






         if (Resoudre2(g,suivant(e)))
         {


            return true;}

     }

    }
   g.setCase1(p.lig,p.col,0);
   return false;




}}

