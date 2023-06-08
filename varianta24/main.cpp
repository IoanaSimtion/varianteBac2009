/**Scrieţi un program C/C++ care citeşte de la tastatură două şiruri de caractere formate din
maximum 100 litere mici ale alfabetului englez şi afişează pe ecran cel mai lung sufix
comun al celor două şiruri de caractere. Dacă cele două şiruri nu au niciun sufix comun,
atunci programul va afişa pe ecran mesajul NU EXISTĂ.
Exemplu: pentru şirurile marina şi elena se va afişa na */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s1[101], s2[101];
    bool suf=0;

    cin.getline(s1,101);
    cin.getline(s2,101);

    for(int i=0; i<strlen(s1) && suf==0; i++){
        if(strstr(s2,s1+i)!=NULL){
            cout<<s1+i;
            suf=1;
        }
    }

    if(!suf){
        cout<<"Nu exista";
    }

    return 0;

}
