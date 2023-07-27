/**Scrieţi un program C/C++ care citeşte de la tastatură un şir de cel mult 50 de caractere
(litere mici şi mari ale alfabetului englez, cifre, puncte, virgule şi spaţii) şi afişează pe ecran
cifra care apare de cele mai multe ori în şirul citit. Dacă şirul conţine mai multe cifre cu
număr maxim de apariţii, atunci se va afişa cea mai mică dintre acestea. Dacă şirul nu
conţine cifre, se va afişa pe ecran mesajul NU.
Exemplu: dacă se citeşte şirul:
Voi lua 9,5 la matematica 10 la informatica si 10 la romana
atunci se va afişa cifra 0 (pentru că cifrele 0 şi 1 apar de cele mai multe ori în şir, iar 0 este
cea mai mică dintre ele)*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char sir[51], cifre[11]="0123456789";
    int fr[100]{}, frMax=0;

    cin.getline(sir,51);

    for(int i=0;i<strlen(sir); i++){
        if(strchr(cifre,sir[i])){
            fr[sir[i]-'0']++;
            if(fr[sir[i]-'0'] > frMax){
                frMax=fr[sir[i]-'0'];
            }
        }
    }

    for(int i=0; i<10; i++){
        if(fr[i]==frMax){
            cout<<i;
            break;
        }
    }

    return 0;
}
