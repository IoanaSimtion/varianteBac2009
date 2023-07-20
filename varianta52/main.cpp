/**Scrieţi un program C/C++ care citeşte de la tastatură un număr natural nenul n (n≤100),
apoi n şiruri de caractere, fiecare şir având maximum 30 de caractere, doar litere mici ale
alfabetului englez, şi afişează pe ecran câte dintre cele n şiruri de caractere sunt formate
numai din vocale. Se consideră vocale literele a, e, i, o, u.*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, da;
    char siruri[100][100];

    cout<<"n=";
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++){
        cin.getline(siruri[i],100);
    }

    for(int i=0;i<n;i++){
        da=1;
        for(int j=0;j<strlen(siruri[i]) && da==1;j++){
            if(strchr("aeiou",siruri[i][j])==NULL){
                da=0;
            }
        }
        if(da==1){
            cout<<siruri[i]<<endl;
        }
    }

    return 0;
}
