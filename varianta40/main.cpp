/**Un şir cu maximum 255 de caractere conţine cuvinte cuvinte formate numai din litere mici
ale alfabetului englez. Fiecare cuvânt este urmat de un caracter *. Scrieţi un program
C/C++ care citeşte un astfel de şir şi afişează pe ecran şirul obţinut prin eliminarea tuturor
apariţiilor primului cuvânt, ca în exemplu.
Exemplu: pentru şirul: bine*albine*foarte*bine* se va afişa:
*albine*foarte**
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char sir[256], cuv[256];

    cin.getline(sir,256);

    int i=0;
    while(sir[i]!='*'){
        cuv[i]=sir[i];
        i++;
    }

    while(strstr(sir,cuv)){
        strcpy(strstr(sir,cuv),strstr(sir,cuv)+strlen(cuv));
    }

    cout<<sir;

    return 0;
}
