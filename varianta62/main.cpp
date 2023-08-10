/**Scrieţi un program C/C++ care citeşte de la tastatură un text de cel mult 255 de caractere,
dintre care cel puţin unul este o literă mică a alfabetului englez, şi afişează pe ecran, pe o
singură linie, despărţite prin câte un spaţiu, toate literele mici ale alfabetului englez care
apar în text. Fiecare literă va fi afişată o singură dată, în ordinea primei ei apariţii în text. */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char text[256];
    int fr[300]{};

    cin.getline(text,256);

    for(int i=0; i<strlen(text); i++){
        if(islower(text[i]) && fr[text[i]]==0){
            cout<<text[i]<<' ';
            fr[text[i]]++;
        }
    }

    return 0;
}
