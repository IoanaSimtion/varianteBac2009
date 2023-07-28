/**Scrieţi un program C/C++ care citeşte de la tastatură un şir de cel mult 50 de caractere
(litere mici şi mari ale alfabetului englez, cifre şi spaţii) şi afişează pe ecran litera mică cel
mai des întâlnită în şirul citit. Dacă există mai multe litere mici cu număr maxim de apariţii,
programul o va afişa pe prima dintre ele în ordine alfabetică. Dacă şirul nu conţine litere
mici, atunci pe ecran se va afişa mesajul nu.
Exemplu: dacă se citeşte şirul:
mergem la munte
atunci se va afişa: e (pentru că literele e şi m apar de cele mai multe ori în şir, iar e este
prima dintre ele în ordine alfabetică).*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[51], litera;
    int f[130]{}, maxim=0;

    cin.getline(s,51);

    for(int i=0; i<strlen(s); i++){
        if(s[i]>='a' && s[i]<='z'){
            f[s[i]]++;
        }
    }

    for(int l='a'; l<='z'; l++){
        if(f[l]>maxim){
            maxim=f[l];
            litera=l;
        }
    }

    cout<<litera;

    return 0;
}
