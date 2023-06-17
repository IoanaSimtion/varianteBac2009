/**Şirul de caractere s2 este “clona” şirului de caractere s1 dacă se poate obţine din s1 prin
eliminarea tuturor apariţiilor unei singure vocale. Se consideră vocală orice literă din
mulţimea {a,e,i,o,u}.
Scrieţi programul C/C++ care citeşte de la tastatură un cuvânt format din cel mult 20 litere
mici ale alfabetului englez şi afişează pe ecran (dacă există), toate “clonele” acestui cuvânt,
fiecare pe câte o linie a ecranului. */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[101]="", s2[101], voc[20]="aeiou", afisare=0;
    cin.getline(s,101);

    for(int i=0;i<5;i++){
        afisare=0;
        int k=0;
        for(int j=0;j<strlen(s);j++){
            if(s[j]!=voc[i]){
                afisare=1;
                s2[k]=s[j];
                k++;
            }
        }
        s2[k]=NULL;
        if(afisare && strcmp(s,s2)!=0){
            cout<<s2<<endl;
            strcpy(s2,"");
        }
    }

    return 0;
}
