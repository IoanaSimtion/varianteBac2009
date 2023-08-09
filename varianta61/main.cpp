/**În fişierul text.in se află un text scris pe mai multe linii, pe fiecare linie fiind caractere
diverse: litere mici ale alfabetului englez, cifre, spaţii şi semne de punctuaţie. Găsiţi o metodă
eficientă din punctul de vedere al timpului de executare şi al gestionării memoriei ce permite
afişarea celor mai frecvente perechi de vocale alăturate din text. Menţionăm că vocalele
sunt: a, e, i, o şi u.
De exemplu, dacă text.in conţine textul:
Aleea ce strabate valea
e-o unduire de pietris scanteietor,
De-aceea nu stii daca zboara sau doar inoata in unde aurii
cele mai frecvente perechi de vocale întâlnite în acest text sunt: ea şi oa (ele apar de 3 ori,
spre deosebire de alte perechi de vocale alăturate care apar de mai puţine ori).
a) Descrieţi succint, în limbaj natural, metoda de rezolvare aleasă, explicând în ce constă
eficienţa ei (3 – 4 rânduri). (4p.)
b) Scrieţi programul C/C++ corespunzător metodei descrise la cerinţa a. */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    ifstream f("text.in");

    char vocale[6]="aeiou", litera1, litera2;
    int frecventaDiftong[5][5]{}, maxim=0;

    f>>litera1;

    while(f.get(litera2))
    {
        if(strchr(vocale,litera1) && strchr(vocale,litera2))
        {
            frecventaDiftong[strchr(vocale,litera1)-vocale][strchr(vocale,litera2)-vocale]++;
        }
        litera1=litera2;
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(frecventaDiftong[i][j]>maxim){
                maxim=frecventaDiftong[i][j];
            }
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(frecventaDiftong[i][j]==maxim){
                cout<<vocale[i]<<vocale[j]<<endl;
            }
        }
    }

    return 0;
}
