#include<iostream>
#include"manuel.h"
using namespace std;
Grille manuel::generergrille(Grille g)

 {
     string s;



    do
    {

        cout<<"choisir -->ligne,colonne,valeur\n0,0,0 pour quitter";
        cin>>s;
        if(g.getCase(int(s[0])-48,int(s[2])-48).getmodif()==false)
        {
            cout<<"case non modifiable"<<endl;

                        continue;}


        else
        {




            if ((s[1]=',')&&(s[3]=',')&&(s[0]-48<9)&&(s[2]-48<9)&&(s[4]-48<10)&&(s[0]-48>=0)&&(s[2]-48>=0)&&(s[4]-48>0)&&(s.size()==5))
            {


                                g.setCase1(s[0]-48,s[2]-48,s[4]-48);
                                cout<<g;





            }
        }



    }while(s!="0,0,0");
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(g.getCase(i,j).getval()!=0)
                g.getCase(i,j).setmodif(false);
        }
    }
    return g;



}



