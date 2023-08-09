using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (2<n≤15) şi 
construieşte în memorie o matrice pătrată cu n linii şi n coloane în care ultima linie conţine, 
în ordine, numerele 1,2,3,..,n, elementele situate deasupra diagonalei principale sunt 
nule şi oricare alt element este obţinut prin însumarea elementelor vecine cu el, aflate pe 
linia imediat următoare, pe aceeaşi coloană cu el sau pe una din coloanele alăturate.
Programul va afişa pe ecran matricea obţinută pe n linii, elementele fiecărei linii fiind 
separate prin câte un spaţiu.*/


void generareMatrice(int a[100][100], int n) {

	for (int j = 0; j < n; j++) {
		a[n - 1][j] = j + 1;
	}

	for (int i = n - 2; i >= 0; i--) {
		a[i][0] = a[i + 1][0] + a[i + 1][1];
		for (int j = 1; j < n; j++) {
			if (i < j) {
				a[i][j] = 0;
			}
			else {
				a[i][j] = a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
			}
		}
	}

}


void afisareMatrice(int a[100][100], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

}


void sol5() {

	int a[100][100], n;

	cout << "n=";
	cin >> n;

	generareMatrice(a, n);

	afisareMatrice(a, n);

}



//SUBIECTUL 3



//3
/*Subprogramul cifra primeşte prin parametrul x un număr real nenul pozitiv şi furnizează
prin parametrul y valoarea cifrei unităţilor părţii întregi a lui x. 
Exemplu: dacă x=34.567, după apel y=4. 
a) Scrieţi definiţia completă a subprogramului cifra. (6p.) 
b) Scrieţi un program C/C++ care citeşte de la tastatură două numere reale cu cel mult două
zecimale, numere reprezentând mediile semestriale obţinute de un elev. Programul stabileşte, 
folosind apeluri utile ale subprogramului cifra, dacă cele două medii citite se află în aceeaşi 
categorie de medii sau nu. Precizăm că orice medie, în funcţie de intervalul în care se 
încadrează, face parte din una dintre categoriile: [3,3.99], [4,4.99], [5,5.99],
[6,6.99], [7,7.99], [8,8.99] sau [9,10]. În cazul în care ambele medii fac parte din 
aceeaşi categorie, programul va afişa mesajul Da, altfel va afişa mesajul Nu.*/


void cifra(float x, int& y) {

	y = (int)x % 10;

}


void solutie3() {

	float medie1, medie2;
	int cifr1, cifr2;

	cin >> medie1 >> medie2;

	cifra(medie1, cifr1);
	cifra(medie2, cifr2);

	if (cifr1 == cifr2 || cifr1 + cifr2 == 9 && cifr1 * cifr2 == 0) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

}