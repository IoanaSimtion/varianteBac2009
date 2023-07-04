/**Un şir cu maximum 255 de caractere conţine cuvinte separate prin câte un spaţiu. Cuvintele
sunt formate numai din litere mici ale alfabetului englez. Scrieţi un program C/C++ care
citeşte de la tastatură un astfel de şir şi îl afişează pe ecran modificat, inversând prin
oglindire doar cuvintele care încep cu vocală, ca în exemplu. Se consideră ca fiind vocale
următoarele litere: a, e, i, o, u.
Exemplu: pentru şirul: maine este proba la informatica se va afişa:
maine etse proba la acitamrofni*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char sir[256];

    cin.getline(sir,256);

    for(int i=0; i<strlen(sir); i++){
        if(strchr("aeiou", sir[i]) && (sir[i-1]==' ' || i==0)){
            int j=i;
            while(sir[j]!=' ' && sir[j]!=NULL){
                j++;
            }
            j--;
            while(i<j){
                char aux=sir[i];
                sir[i]=sir[j];
                sir[j]=aux;
                i++;
                j--;
            }
        }
    }

    cout<<sir;

    return 0;
}
