#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char s[256], t[256]="";
    cin.getline(s,256);
    bool gasit=0;
    for(int i=strlen(s)-1;i>=0 && !gasit; i--){
        if(strchr("aeiou",s[i])==NULL){
            strcpy(t,s+i+1);
            strcpy(s+i,t);
            gasit=1;
        }
    }
    cout<<s;
    return 0;
}
