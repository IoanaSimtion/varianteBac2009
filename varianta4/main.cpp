#include <iostream>

#include <string.h>

using namespace std;

int main()
{
    char s[256], t[256];

    cin>>s;

    int i=0;
    while(i<strlen(s)){
        if(islower(s[i])){
            strcpy(t , s + i + 1);
            strcpy(s + i , t);
            i--;
        }
        i++;
    }

    cout<<s;

    return 0;
}
