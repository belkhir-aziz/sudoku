#include<iostream>
#include"machine.h"
#include"grille.h"
#include"machine2.h"


using namespace std;
bool Machine2::resoudre(Grille g)
{
    return Resoudre(g,0);

}
bool Machine2::Resoudre(Grille g, int e)
{

    if (e == 81)
{
   solution=new Grille;
       for(int i=0;i<9;i++)
      {
          for(int j=0;j<9;j++)
          {
            solution->setCase2(i,j,g.getCase(i,j).getval(),g.getCase(i,j).getmodif());

          }
      }

        return true;
}
else{
        int i = e/9;
        int j = e%9;
    if (g.getCase(i,j).getmodif()==false)
        return(Resoudre(g,e+1));

    for (int k=1; k <= 9; k++)
    {
        if (g.valeurvalider(i,j,k))
        {
            g.setCase1(i,j,k);
            cout<<g;



            if ( Resoudre(g,e+1) )
                return true;
        }
    }
    g.setCase1(i,j,0);

    return false;}
}


