#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char sir[256];
    cin.getline(sir,256);
    sir[0]=toupper(sir[0]);
    for(int i=1;i<strlen(sir);i++){
        if(sir[i]!=' ' && sir[i-1]==' '){
            sir[i]=toupper(sir[i]);
        }
    }
    cout<<sir;
    return 0;
}
