#include<iostream>
#include"homme.h"
#include<windows.h>
using namespace std;
std::pair<position,int> Homme::choisirCoup(Grille g)
{
     string s;
      position p;
      p.lig=-1;
      p.col=-1;
    int v=-1;


    do
    {
        cout<<g;
        cout<<"choisir -->ligne,colonne,valeur\n0,0,0 pour quitter";
        cin>>s;
       /* if(g.getCase(int(s[0])-48,int(s[2])-48).getmodif()==false)
        {
            cout<<"case non modifiable"<<endl;

                        continue;
        }*/

        if(s=="0,0,0")
        {

           // system("CLS");
             cout<<"changer le mode(1)\nQuitter(2)\nSauvegarder(3)\nResolution rapide(4)\n";

            return make_pair(p,v);
        }

        else
        {




            if ((s[1]==',')&&(s[3]==',')&&(s[0]-48<9)&&(s[2]-48<9)&&(s[4]-48<10)&&(s[0]-48>=0)&&(s[2]-48>=0)&&(s[4]-48>0))
            {

                               position p;
                               p.lig=s[0]-48;
                               p.col=s[2]-48;
                               int v=s[4]-48;
                               if(g.getCase(p.lig,p.col).getmodif()==false)
                               {
                                   cout<<"la case est non-modifiable"<<endl;
                                   system("pause");

                               }
                               else{
                               if(g.valeurvalider(p.lig,p.col,v))
                               {
                               // system("CLS");
                                   cout<<"votre choix est juste\neffectuer cette coup(0)\nchanger le mode(1)\nQuitter(2)\nSauvegarder(3)\nResolution rapide(4)\n";
                                  return make_pair(p, v);
                               }
                               else
                               {
                                   continue;
                               }



            }}
        }



    }while(!g.pleine());
    return make_pair(p,v);


}

