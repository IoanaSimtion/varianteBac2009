using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr 
natural n (1≤n≤6) şi elementele unui tablou bidimensional A cu n linii 
şi n coloane, care memorează numere naturale nenule mai mici decât 
100, şi afişează pe ecran produsul numerelor “pivot” pentru matricea 
A dacă există astfel de numere, altfel va afişa mesajul NU EXISTA. 
Un număr natural x este “pivot” pentru matricea A dacă înmulţind 
fiecare element de pe prima coloană cu numărul x, se obţin, în 
aceeaşi ordine, elementele unei alte coloane din matrice*/


void citireMatrice(int a[100][100], int& n) {

	ifstream f("pivot.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f >> a[i][j];
		}
	}

}


void vectorProdus(int a[100][100], int n, int nr, int v[]) {

	int i = 0;

	for (int j = 0; j < n; j++) {
		v[i] = a[j][0] * nr;
		i++;
	}

}


bool ePivot(int a[100][100], int n, int nr) {

	int v[100]{}, indice = 0;
	bool este = true;

	vectorProdus(a, n, nr, v);

	/*for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
	cout << endl;*/

	for (int i = 0; i < n; i++) {
		este = true;
		indice = 0;
		for (int j = 0; j < n; j++) {
			if (a[j][i] != v[indice]) {
				este = false;
			}
			indice++;
		}
		if (este == true) {
			return true;
		}
	}

	return este;

}


int produsPivoti(int a[100][100], int n) {

	int produs = 1, pivoti[100], m = 0;
	bool exista = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ePivot(a, n, a[i][j])) {
				for (int k = 0; k < m && exista == false; k++) {
					if (a[i][j] == pivoti[k]) {
						exista = true;
					}					
				}
				if (exista == false) {
					pivoti[m] = a[i][j];
					m++;
					produs *= a[i][j];
				}
			}
		}
	}

	return produs;

}


void sol5() {

	int a[100][100], n;

	citireMatrice(a, n);

	cout << produsPivoti(a, n);

}



//SUBIECTUL 3



//3
/*Scrieţi definiţia completă a subprogramului multipli, cu trei parametri a,b,c (a≤b),
numere naturale din intervalul [1,10000] ce returnează numărul numărul multiplilor lui c 
din intervalul [a;b]. */


int multipli(int a, int b, int c) {

	int ct = 0;

	for (int i = a; i <= b; i++) {
		if (i % c == 0) {
			ct++;
		}
	}

	return ct;

}


void solutie3() {

	int a, b, c;

	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;

	cout << multipli(a, b, c);

}




//4
/*Se consideră două tablouri unidimensionale A şi B cu elemente numere naturale din 
intervalul [1,10000]. Spunem că tabloul A “se poate reduce” la tabloul B dacă există o 
împărţire a tabloului A în secvenţe disjuncte de elemente aflate pe poziţii consecutive în 
tabloul A astfel încât prin înlocuirea secvenţelor cu suma elementelor din secvenţă să se 
obţină, în ordine, elementele tabloului B
Fişierul text NUMERE.IN conţine pe prima linie două numere naturale nenule n şi m
(1≤m≤n≤100), pe linia a doua n numere naturale din intervalul [1;10000] şi pe linia a
treia alte m numere naturale din intervalul [1;10000]. Pe fiecare linie numerele sunt
separate prin câte un spaţiu.
a) Scrieţi un program C/C++ care citeşte toate numerele din fişierul NUMERE.IN şi verifică,
utilizând un algoritm eficient din punctul de vedere al timpului de executare, dacă tabloul
construit cu cele n numere aflate pe linia a doua în fişier se poate reduce la tabloul construit
cu cele m numere aflate pe linia a treia în fişier. Programul afişează pe ecran mesajul DA în
caz afirmativ şi mesajul NU în caz negativ. (6p.)
 b) Descrieţi în limbaj natural metoda utilizată şi explicaţi în ce constă eficienţa ei. */


void citireVectori(int a[], int b[], int& n, int& m) {

	ifstream f("NUMERE.IN");

	f >> n >> m;

	for (int i = 0; i < n; i++) {
		f >> a[i];
	}

	for (int j = 0; j < m; j++) {
		f >> b[j];
	}

}


bool sePoateReduce(int a[], int b[], int n, int m) {

	int suma = 0, indice = 0;

	for (int i = 0; i < n; i++) {
		suma += a[i];
		if (suma > b[indice]) {
			return false;
		}
		if (suma == b[indice]) {
			suma = 0;
			indice++;
		}
	}

	return true;

}


void solutie4() {

	int a[100], b[100], n, m;

	citireVectori(a, b, n, m);

	if (sePoateReduce(a, b, n, m)) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

}