#include<iostream>
#include<deque>
#include<iterator>
#include"machine1.h"
#include"grille.h"
#include<utility>

using namespace std;



/*******************************************************************************************************************/






 void Machine1::tri2()
 {

 int i, j;
   for (i = 0; i < 81; ++i) {
       deque<int> elem(m[i].begin(),m[i].end());
     // elem=assign(m[i].begin(),m[i].end());
       for (j = i; j > 0 && m[j-1].back() > elem.back(); j--)
           m[j].assign(m[j-1].begin(),m[j-1].end());
       m[j].assign(elem.begin(),elem.end());
   }



  }


 /**************************************************************************************************************************/

bool Machine1::resoudre(Grille g)
{

    remplir(g);
    tri2();
   Resoudre(g,0);

   return true;
}
/**************************************************************************************************************************/

