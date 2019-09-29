#include<iostream>
#include"verification.h"
#include<string>
using namespace std;
bool Input::verif1(string s)
{
    if ((s.size()=5)&&(s[1]=',')&&(s[3]=',')&&(s[0]<10)&&(s[2]<10)&&(s[4]<10)&&(s[0]>0)&&(s[2]>0)&&(s[4]>0))
        return (true);
    else
        return (false);
}
