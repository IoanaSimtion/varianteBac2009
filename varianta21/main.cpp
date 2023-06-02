/**Se consideră un text alcătuit din cel mult 250 de caractere, în care cuvintele sunt formate doar
din litere mici ale alfabetului englez şi sunt separate prin unul sau mai multe caractere *.
Scrieţi un program C/C++ care citeşte de la tastatură textul şi afişează pe ecran, pe câte o
linie, toate secvenţele formate din câte două litere identice, ca în exemplu.*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char text[256]="copiii*sunt*la***zoo";
    for(int i=0;i<strlen(text)-1;i++){
        if(text[i]==text[i+1] && text[i]!='*'){
            cout<<text[i]<<text[i+1]<<endl;
        }
    }
    return 0;
}
