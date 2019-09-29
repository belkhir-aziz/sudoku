#ifndef MACHINE4_H_INCLUDED
#define MACHINE4_H_INCLUDED
#include"machine.h"
#include<vector>
#include<iterator>
#include<iostream>
using namespace std;

class Machine4 :public Machine
{


public:
    bool resoudre(Grille g);

    int suivant(int );

    bool Resoudre2(Grille g,int);


};




#endif // MACHINE4_H_INCLUDED
