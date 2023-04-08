#include <iostream>

#include <string.h>

using namespace std;

int main()
{
    char s[100], c;
    int i,j;

    cout<<"Introduceti sirul de caractere: ";
    cin.getline(s,100);

    i=0;
    j=strlen(s)-1;

    while(i<j){

        c=s[i];
        s[i]=s[j];
        s[j]=c;
        i++;
        j--;
    }

    cout<<s;

    return 0;
}
