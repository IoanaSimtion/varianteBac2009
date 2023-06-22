/**Scrieţi un program C/C++ care citeşte de la tastatură două caractere c1 şi c2 (litere
distincte ale alfabetului englez), şi un text având cel mult 250 caractere (doar spaţii şi litere
ale alfabetului englez), pe care îl modifică înlocuind toate apariţiile caracterului memorat în
c1 cu cel memorat în c2 şi toate apariţiile caracterului memorat în c2 cu cel memorat în c1.
Programul afişează pe linii separate ale ecranului atât textul iniţial cât şi textul obţinut după
efectuarea înlocuirilor.*/


#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char c1, c2, text[251];

    cin.getline(text,251);
    cin>>c1;
    cin>>c2;

    cout<<text<<endl;

    for(int i=0;i<strlen(text);i++){
        if(text[i]==c1){
            text[i]=c2;
        }
        else{
            if(text[i]==c2){
                text[i]=c1;
            }
        }
    }

    cout<<text;

    return 0;
}
