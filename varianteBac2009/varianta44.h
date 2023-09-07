using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (0<n≤23) şi apoi 
construieşte în memorie o matrice cu n linii şi n coloane, formată din numere naturale
nenule, mai mici sau egale cu n, astfel încât să nu existe două linii cu aceeaşi sumă a 
elementelor şi nici două coloane cu aceeaşi sumă a elementelor. 
Programul va afişa matricea pe ecran, câte o linie a matricei pe o linie a ecranului, cu un 
spaţiu între elementele fiecărei linii*/


void generareMatrice(int a[100][100], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j < n) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
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
/*Scrieţi definiţia completă a unui subprogram P, cu doi parametri, a şi b, numere naturale cu 
cel mult 4 cifre fiecare, care afişează pe ecran, separate prin câte un spaţiu, numerele aflate 
în intervalul închis determinat de valorile a şi b, care sunt pătratele unor numere prime.*/


void P(int a, int b) {

	if (a > b) {
		swap(a, b);
	}

	for (int i = a; i <= b; i++) {
		if (sqrt(i) == (int)sqrt(i) && i != 1) {
			bool prim = true;
			for (int d = 2; d < sqrt(i); d++) {
				if (i % d == 0) {
					prim = false;
					break;
				}
			}
			if (prim == true) {
				cout << i << ' ';
			}
		}
	}

}


void solutie3() {

	int a, b;

	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;

	P(a, b);

}



//4
/*Fişierul text numere.txt conţine pe prima linie un număr natural n (0<n<100000), iar pe a 
doua linie n numere naturale, formate din cel mult 4 cifre, separate prin câte un spaţiu. 
a) Scrieţi un program C/C++ care determină în mod eficient, din punct de vedere al timpului 
de executare, cifrele ce apar în scrierea numerelor situate pe a doua linie a fişierului.
Programul va afişa pe ecran aceste cifre in ordine crescătoare, separate prin câte un spaţiu*/


void citireNumere(int fr[]) {

	ifstream f("cifreNr.txt");
	int n, nr;

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> nr;
		while (nr) {
			fr[nr % 10]++;
			nr /= 10;
		}
	}

}


void afisareCifre(int fr[]) {

	for (int i = 0; i < 10; i++) {
		if (fr[i] > 0) {
			cout << i << ' ';
		}
	}

}


void solutie4() {

	int fr[100]{};

	citireNumere(fr);

	afisareCifre(fr);

}