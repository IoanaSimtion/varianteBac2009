#include <iostream>

#include <string.h>

using namespace std;

int main()
{
    char s[40];

    cout<<"Introduceti un cuvant: ";
    cin >> s;

    char vocale[10] = "aeiou";
    for (int i = 0; i < strlen(s); i++){
        if (strchr(vocale, s[i]) != 0){
          char aux[40];
          strcpy(aux, s + i);
          strcpy(s + i + 1, aux);
          s[i + 1] = toupper(s[i + 1]);
        }
    }
    cout << s << endl;
    return 0;
}
