using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Se consideră o matrice cu n linii şi m coloane (1≤n≤30, 1≤m≤30), 
ce memorează numere întregi de cel mult 4 cifre fiecare. Scrieţi un 
program C/C++ care citeşte de la tastatură valorile n, m şi 
elementele matricei şi care afişează pe ecran, separate prin câte 
un spaţiu, valorile minime de pe fiecare coloană, în ordine de la 
ultima la prima coloană.*/


void citireMatrice(int a[100][100], int& n) {

	ifstream f("matrice.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f >> a[i][j];
		}
	}

}


void afisareMinimColoane(int a[100][100], int n) {

	for (int j = n - 1; j >= 0; j--) {
		int minim = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (a[i][j] < minim) {
				minim = a[i][j];
			}
		}
		cout << minim << ' ';
	}

}

void sol5() {

	int a[100][100], n;

	citireMatrice(a, n);

	afisareMinimColoane(a, n);

}



//SUBIECTUL 4



//3
/*Subprogramul cifra primeşte prin intermediul parametrului a un număr natural cu cel mult 
4 cifre şi returnează ultima cifră pară a sa. Dacă numărul nu conţine cifre pare, 
subprogramul returnează valoarea -1. De exemplu, dacă a=8345, subprogramul va 
returna 4.
a) Să se scrie definiţia completă a subprogramului cifra. 
b) Pe prima linie a fişierului bac.in se află un număr natural nenul n (n≤15000), iar pe 
a doua linie a fişierului se află un şir de n numere naturale, despărţite prin câte un spaţiu, 
fiecare număr fiind format din cel mult 4 cifre. 
Scrieţi un program C/C++ care citeşte numerele din fişier şi afişează pe ecran, folosind 
apeluri utile ale subprogramului cifra, cel mai mare număr care se poate forma cu 
ultimele cifre pare ale fiecărui element, dacă acestea există. Alegeţi o metodă de rezolvare 
eficientă ca timp de executare. Dacă toate numerele de pe a doua linie a fişierului au 
numai cifre impare, programul va afişa mesajul NU EXISTA. */


int cifra(int a) {

	if (a < 9 && a % 2 == 0) {
		return a;
	}

	while (a) {
		if ((a % 10) % 2 == 0) {
			return a % 10;
		}
		a /= 10;
	}

	return -1;

}


void afisareNumarMaxim() {

	ifstream f("numarCifre.txt");

	int n, a, fr[5]{};
	bool exista = false;

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> a;
		if (cifra(a) != -1) {
			fr[cifra(a) / 2]++;
		}
	}

	for (int i = 4; i >= 0; i--) {
		while (fr[i]) {
			cout << i * 2;
			fr[i]--;
			exista = true;
		}
	}

	if (!exista) {
		cout << "NU EXISTA";
	}
}


void solutie3() {

	afisareNumarMaxim();

}