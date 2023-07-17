/**Se consideră un şir s având maximum 52 de caractere, şir ce conţine numai litere mici ale
alfabetului englez şi cifre. Primul caracter al şirului este o literă mică, ultimul caracter al
şirului este o cifră şi fiecare literă mică din şir este urmată de o cifră nenulă. Scrieţi un
program C/C++ care citeşte de la tastatură şirul s, apoi construieşte şi afişează pe ecran un
nou şir de caractere, format numai din litere mici ale alfabetului englez, şir construit după
următoarea regulă: fiecare literă mică se va repeta de atâtea ori de câte ori o indică cifra
situată pe poziţia imediat următoare în şirul iniţial, ca în exemplu.
Exemplu: dacă se citeşte de la tastatură şirul a2b1f2 atunci şirul cerut este aabff*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[53], s2[256];
    int d=0;

    cin.get(s,53);

    for(int i=0;i<strlen(s);i++){
        if(isdigit(s[i])){
            int j=0;
            while(j<int(s[i]-'0')-1){
                s2[d]=s[i-1];
                d++;
                j++;
            }
        }
        else{
            s2[d]=s[i];
            d++;
        }
    }

    cout<<s2;

    return 0;
}
