/**Se consideră un text format doar din spaţii şi litere mici ale alfabetului englez, care începe
cu o literă şi care conţine cel puţin o vocală din multimea {a,e,i,o,u}. Scrieţi programul
C/C++ care citeşte de la tastatură un şir cu cel mult 100 de caractere, ca cel descris mai
sus şi care determină transformarea acestuia prin înlocuirea fiecărei vocale din text cu litera
imediat următoare din alfabet (a se înlocuieşte cu b, e se înlocuieşte cu f ş.a.m.d.).
Programul va afişa pe ecran şirul obţinut.
Exemplu: dacă şirul citit este examen de bacalaureat, după modificare se afişează:
fxbmfn df bbcblbvrfbt */


#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char text[101];

    cin.getline(text,101);

    for(int i=0;i<strlen(text);i++){
        if(strchr("aeiou",text[i])){
            text[i]=text[i]+1;
        }
    }

    cout<<text;

    return 0;
}
