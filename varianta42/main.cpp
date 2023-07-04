/**Scrieţi programul C/C++ care citeşte de la tastatură un şir de cel mult 40 de caractere,
format doar din litere mici ale alfabetului englez, şi care afişează pe ecran, pe o singură
linie, toate vocalele ce apar în şirul citit. Vocalele vor fi afişate în ordinea apariţiei lor în şir,
separate prin câte un spaţiu, ca în exemplu. Se consideră ca fiind vocale următoarele litere:
a, e, i, o, u. Dacă şirul citit nu conţine nicio vocală, se va afişa pe ecran mesajul fara
vocale.
Exemplu: dacă se citeşte şirul calculator atunci pe ecran se va afişa: a u a o*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char sir[41];
    bool exista=false;

    cin.getline(sir,41);

    for(int i=0; i<strlen(sir); i++){
        if(strchr("aeiou",sir[i])){
            cout<<sir[i]<<' ';
            exista=true;
        }
    }

    if(exista==false){
        cout<<"fara vocale";
    }

    return 0;
}
