/**Scrieţi un program C/C++ care citeşte de la tastatură un şir de cel mult 50 de caractere
(cifre, litere ale alfabetului englez şi spaţii; şirul conţine cel puţin o literă), apoi construieşte
în memorie şi afişează pe ecran şirul de caractere obţinut din şirul citit prin eliminarea tuturor
caracterelor care nu sunt litere.
Exemplu: dacă se citeşte şirul: Voi lua 10 la informatica atunci se va afişa:
Voilualainformatica */


#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char sir[51], sir2[51], caractere[12]="0123456789 ";
    int j=0;

    cin.getline(sir,51);

    for(int i=0; i<strlen(sir); i++){
        if(!strchr(caractere,sir[i])){
            sir2[j]=sir[i];
            j++;
        }
    }

    cout<<sir2;

    return 0;
}
