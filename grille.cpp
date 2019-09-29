#include<iostream>
#include"grille.h"
#include<windows.h>
using namespace std;
Grille::Grille()
{
    grille=new Case*[9];
    for(int i=0;i<9;i++)
    {
        grille[i]=new Case[9];
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            setCase2(i,j,0,true);
        }
    }


}
bool Grille::pleine()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(this->getCase(i,j).getval()==0)
                return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& flux,Grille& g)
{


    system("CLS");

    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
          if (((j+1)%3)==0)
            flux<<g.grille[i][j].getval()<<" | ";
        else
            flux<<g.grille[i][j].getval();

        }
        flux<<"\n";
        if (!((i+1)%3))
            flux<<"-------------------\n";
    }
    flux<<"\n\n";
    return (flux);
}
Case Grille::getCase(int i,int j)
{
  return grille[i][j];
}
void Grille::setCase1(int i,int j,int v)
{
 grille[i][j].setval(v);

}
void Grille::setCase2(int i,int j,int v,bool m)
{
   grille[i][j].setval(v);
   grille[i][j].setmodif(m);

}
bool Grille::absentligne(int i,int j,int v)
{

    for (int s=0; s < 9; s++)
        if ((grille[i][s].getval() ==v )&&(s!=j))
            return false;
    return true;

}
bool Grille::absentcolonne(int i,int j,int v)
{

    for (int s=0; s < 9; s++)
        if ((grille[s][j].getval() ==v )&&(s!=i))
            return false;
    return true;

}
bool Grille::absentbloc(int i,int j,int v)
{ int l = i-(i%3), c = j-(j%3);

    for (int e=l; e < l+3; e++)
    {


        for (int f=c; f < c+3; f++)
        {


            if (((grille[e][f]).getval() == v)&&(e!=i)&&(f!=j))
                return false;
                }}
    return true;

}
bool Grille::valeurvalider(int i,int j,int v)
{
    if(absentligne(i,j,v)&&(absentcolonne(i,j,v))&&absentbloc(i,j,v))
       return true;
    else return false;
}




