/**Scrieţi programul C/C++ care citeşte de la tastatură un şir de cel mult 40 de caractere,
format doar din litere ale alfabetului englez, şi care afişează pe ecran toate şirurile obţinute
prin eliminarea succesivă a câte unei singure litere din şirul citit, ca în exemplu. Şirurile se
vor afişa câte unul pe câte o linie a ecranului.
Exemplu: dacă se citeşte şirul abbc atunci pe ecran se va afişa:
bbc
abc
abc
abb*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char sir[41];

    cin.get(sir,41);

    for(int i=0; i<strlen(sir); i++){
        for(int j=0; j<strlen(sir); j++){
            if(i!=j){
                cout<<sir[j];
            }
        }
        cout<<endl;
    }

    return 0;
}
