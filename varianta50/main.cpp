/**Scrieţi programul C/C++ care citeşte de la tastatură un cuvânt s de cel mult 20 litere mici ale
alfabetului englez, construieşte în memorie şi afişează pe ecran cuvântul s după eliminarea
primei şi a ultimei vocale. Cuvântul s conţine cel puţin două vocale şi cel puţin o consoană. Se
consideră vocale literele: a, e, i, o, u.
Exemplu: dacă se citeşte cuvântul bacalaureat, pe ecran se afişează: bcalauret*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[21];
    int j;

    cin.get(s,21);

    j=0;
    while(strchr("aeiou",s[j])==NULL){
        j++;
    }
    for(int i=j;i<strlen(s);i++){
        s[i]=s[i+1];
    }

    j=strlen(s)-1;
    while(strchr("aeiou",s[j])==NULL){
        j--;
    }
    for(int i=j;i<strlen(s);i++){
        s[i]=s[i+1];
    }

    cout<<s;

    return 0;
}
