/**Scrieţi un program C/C++ care citeşte de la tastatură un text format din cel mult 200 de
litere ale alfabetului englez, în care cuvintele sunt separate printr-un singur spaţiu şi
afişează pe ecran numărul de cuvinte din textul citit, care au prima respectiv ultima literă
vocală. În cazul în care în text nu există un astfel de cuvânt, se va afişa pe ecran mesajul
NU EXISTA. Se consideră vocală orice literă din mulţimea {a,A,e,E,i,I,o,O,u,U}.
5.
Exemplu: dacă textul introdus este:
Eratostene a sugerat ca anii bisecti se repeta la fiecare patru ani
pe ecran se va afişa:
4*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int ct=0;
    char text[201], vocale[11]="AaEeIiOoUu";

    cin.getline(text,201);

    for(int i=0; i<strlen(text); i++){
        if(strchr(vocale,text[i]) && (i==0 || text[i-1]==' ')){
            while(text[i+1]!=' ' && text[i+1]!=NULL){
                i++;
            }
            if(strchr(vocale,text[i])){
                ct++;
            }
        }
    }

    if(ct){
        cout<<ct;
    }
    else{
        cout<<"NU EXISTA";
    }

    return 0;
}
