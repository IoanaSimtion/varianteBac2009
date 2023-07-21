/**Scrieţi un program C/C++ care citeşte de la tastatură un şir de caractere format din
maximum 10 caractere, reprezentând un număr real în care partea întreagă este separată
de partea zecimală prin caracterul punct. Programul afişează pe ecran valoarea obţinută
prin adunarea numărului corespunzător părţii întregi şi a numărului corespunzător părţii
zecimale ale datei citite.
Exemplu: dacă se citeşte de la tastatură şirul de caractere 120.456 atunci se va afişa
576, iar dacă se citeşte de la tastatură şirul de caractere 121.090 atunci se va afişa 130*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[11];
    int poz=0, n1=0, n2=0;

    cin.get(s,11);

    for(int i=0; i<strlen(s) && poz==0; i++){
        if(s[i]=='.'){
            poz=i;
        }
    }

    for(int j=0;j<strlen(s);j++){
        if(j!=poz){
            if(j<poz){
                n1=n1*10+int(s[j]-'0');
            }
            else{
                n2=n2*10+int(s[j]-'0');
            }
        }
    }

    cout<<n1+n2;

    return 0;
}
