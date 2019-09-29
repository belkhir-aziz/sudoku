#include<iostream>
#include"machine3.h"
#include"joueur.h"
using namespace std;
/*****************************************************************************************************************************/

bool Machine3::resoudre(Grille g)
{
    remplir(g);
    return  Resoudre(g,0);
}
