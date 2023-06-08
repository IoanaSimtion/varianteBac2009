using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Un tablou bidimensional A cu m linii şi n coloane (1≤m≤100, 1≤n≤100) conţine pe prima linie 
numerele 1,2,...,n, iar pe prima coloană numerele 1,2,...,m. Celelalte elemente ale 
tabloului sunt date de relaţia: Ai,j=Ai-1,j+Ai,j-1. Scrieţi un program C/C++ care citeşte de la 
tastatură numerele m şi n şi afişează pe ecran ultima cifră a elementului de pe ultima linie şi 
ultima coloană a tabloului.*/


void generareMatrice(int a[100][100], int n, int m) {

	for (int j = 0; j < n; j++) {
		a[0][j] = j + 1;
	}
	for (int i = 0; i < m; i++) {
		a[i][0] = i + 1;
	}

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
	}

}


void afisareMatrice(int a[100][100], int n, int m) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

}


void sol5() {

	int a[100][100], n, m;

	cout << "m=";
	cin >> m;
	cout << "n=";
	cin >> n;

	generareMatrice(a, n, m);

	//afisareMatrice(a, n, m);

	cout << a[m - 1][n - 1] % 10;

}



//SUBIECTUL 3



//3
/*a) Scrieţi definiţia completă a subprogramului shift care primeşte prin intermediul 
parametrului n o valoare naturală nenulă (n≤100), iar prin intermediul parametrului x, un 
tablou unidimensional cu maximum 100 de componente. Fiecare componentă a acestui 
tablou este un număr întreg care are cel mult 4 cifre. Subprogramul permută circular cu o 
poziţie spre stânga primele n elemente ale tabloului x şi furnizează tabloul modificat tot prin 
parametrul x. 
b) Scrieţi un program C/C++ care citeşte de la tastatură o valoare naturală nenulă n
(n≤100), apoi cele n elemente ale unui tablou unidimensional x. Programul va inversa 
ordinea elementelor tabloului x folosind apeluri utile ale subprogramului shift şi va afişa 
pe ecran, separate prin câte un spaţiu, elementele tabloului rezultat în urma acestei 
prelucrări.*/


void citireVector(int x[], int& n) {

	ifstream f("permutare.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> x[i];
	}

}


void shift(int n, int x[100]) {

	int aux = x[0];

	for (int i = 1; i < n; i++) {
		x[i - 1] = x[i];
	}

	x[n - 1] = aux;

}


void afisareVector(int x[], int n) {

	for (int i = 0; i < n; i++) {
		cout << x[i] << ' ';
	}

}


void solutie3() {

	int n, x[100];

	citireVector(x, n);

	for (int i = 0; i < n; i++) {
		shift(n - i, x);
	}

	afisareVector(x, n);

}



//4
/*Fişierul text BAC.TXT conţine pe prima linie un număr natural nenul n (1≤n≤1000), iar pe 
fiecare dintre următoarele n linii, câte două numere întregi a şi b (1≤a≤b≤32000), fiecare 
pereche reprezentând un interval închis de forma [a,b]. Scrieţi un program C/C++ care 
determină intervalele care au proprietatea că intersecţia cu oricare dintre celelalte n-1
intervale este vidă şi afişează pe câte o linie a ecranului, separate printr-un spaţiu, 
numerele care reprezintă capetele intervalelor determinate.*/


void citireAfisarePerechi() {

	ifstream f("perechi.txt");
	int n, x[100], y[100];

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> x[i] >> y[i];
	}
	
	for (int i = 0; i < n; i++) {
		int ct = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (x[i] > y[j] || x[j] > y[i]) {
					ct++;
				}
			}
		}
		if (ct == n - 1) {
			cout << x[i] << ' ' << y[i] << endl;
		}
	}

}


void solutie4() {

	citireAfisarePerechi();

}