/**Un cuvânt s, de cel mult 20 caractere, format doar din litere mici ale alfabetului englez,
conţine cel puţin o consoană şi cel puţin o vocală. Scrieţi programul C/C++ care citeşte de la
tastatură cuvântul s, construieşte în memorie şi afişează pe ecran cuvântul obţinut prin
eliminarea tuturor consoanelor din cuvântul s. Se consideră consoană oricare literă care nu
se află în mulţimea {a, e, i, o, u}.
Exemplu: dacă se citeşte cuvântul bacalaureat, pe ecran se afişează: aaauea*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[21];

    cin.get(s,21);

    for(int i=0;i<strlen(s);i++){
        if(strchr("aeiou",s[i])==NULL){
            for(int j=i;j<strlen(s);j++){
                s[j]=s[j+1];
            }
            i--;
        }
    }

    cout<<s;

    return 0;
}
