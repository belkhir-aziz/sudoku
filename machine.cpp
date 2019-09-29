#include<iostream>
#include<string>
#include"machine.h"
#include"grille.h"
#include<deque>
#include<windows.h>

using namespace std;
 void Machine::remplir(Grille g)
    {
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
           if(g.getCase(i,j).getmodif()==true)
                {
          for(int a=1;a<10;a++)
          {
              if (g.valeurvalider(i,j,a))
              {
                  m[i*9+j].push_back(a);
              }
          }
        }
    }}
    for(int i=0;i<81;i++)
    {

        {m[i].push_back(m[i].size());
        m[i].push_front(i);

        }

    }}
    /***********************************************************************************************************************/
    bool Machine::Resoudre(Grille g,int e)
{
  if(e==81)
    {
    solution=new Grille;

      for(int i=0;i<9;i++)
      {
          for(int j=0;j<9;j++)
          {
            solution->setCase2(i,j,g.getCase(i,j).getval(),g.getCase(i,j).getmodif());

          }
      }
      cout<<*solution;
      system("pause");


    return true;}
    else{
    position p;
     p.lig=m[e].front()/9;
       p.col=m[e].front()%9;


    if(g.getCase(p.lig,p.col).getmodif()==false)
        return(Resoudre(g,e+1));

    deque<int>::iterator it;
    it=m[e].begin();
    while(it!=m[e].end())
    {
     ++it;
     if(g.valeurvalider(p.lig,p.col,*it))

     {
         g.setCase1(p.lig,p.col,*it);
        // cout<<g;

         if (Resoudre(g,e+1))
            return true;

     }

    }
   g.setCase1(p.lig,p.col,0);
   return false;

    }


}
Grille Machine::miseajour(Grille g)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(g.getCase(i,j).getmodif()==true)
            {
                g.setCase1(i,j,0);
            }
        }
    }
    return g;
}
std::pair<position,int> Machine::choisirCoup(Grille g)
 {  position p;
    int v=-1;
     cout<<g;
     if(solution==NULL)
     {
         resoudre(g);
         cout<<"tag";
         system("pause");
         g=miseajour(g);
     }
     cout<<g;
     for(int i=0;i<9;i++)
     {
         for(int j=0;j<9;j++){
     if((g.getCase(i,j).getmodif()==true)&&(g.getCase(i,j).getval()==0))
     {
        cout<<"la machine propose "<< solution->getCase(i,j).getval()<<"pour la Case ("<<i<<","<<j<<") "<<endl;
        cout<<"\neffectuer cette coup(0)\nchanger le mode(1)\nQuitter(2)\nSauvegarder(3)\n";
        position p;
        p.lig=i;
        p.col=j;
        return make_pair(p,solution->getCase(i,j).getval());

     }}}
     return make_pair(p,v);
 }
