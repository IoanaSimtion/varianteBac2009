/**Un şir cu maximum 255 de caractere conţine cuvinte separate prin unul sau mai multe spaţii.
Cuvintele sunt formate numai din litere mici ale alfabetului englez. Scrieţi un program C/C++
care citeşte un astfel de şir şi îl afişează modificat, prima şi ultima literă a fiecărui cuvânt fiind
afişată ca literă mare.
Exemplu: pentru şirul: maine este proba la informatica se va afişa:
MainE EstE ProbA LA InformaticA*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char sir[256];

    cin.getline(sir,256);

    if(sir[0]!=' '){
        sir[0]=toupper(sir[0]);
    }

    for(int i=0;i<strlen(sir);i++){
        if((sir[i-1]==' ' && sir[i]!=' ') || ( sir[i]!=' ' && (sir[i+1]==' ' || sir[i+1]==NULL))){
            sir[i]=toupper(sir[i]);
        }
    }

    cout<<sir;

    return 0;
}
