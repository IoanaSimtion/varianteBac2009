using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n
(1≤n≤23) şi apoi construieşte în memorie o matrice cu n linii şi n coloane,
numerotate de la 1 la n, astfel încât fiecare element situat pe o linie i
(1≤i≤n) şi pe o coloană j (1≤j≤n) va fi egal cu suma dintre i şi j.
Programul va afişa matricea pe ecran, câte o linie a matricei pe o linie a
ecranului, elementele de pe aceeaşi linie fiind separate prin câte un spaţiu*/


void generareMatrice(int a[100][100], int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = i + j;
		}
	}

}



void afisareMatrice(int a[100][100], int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
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
/*Scrieţi un subprogram DIST, cu doi parametri, care primeşte prin intermediul parametrului a
un tablou unidimensional cu cel mult 100 de elemente, numere naturale de cel mult 4 cifre
fiecare, şi prin intermediul parametrului n un număr natural nenul, n<100, ce reprezintă
numărul de elemente din tablou. Subprogramul returnează valoarea 1 dacă toate
elementele tabloului a sunt distincte şi dacă diferenţa absolută a oricăror două elemente
vecine din tablou este diferită de 1, altfel returnând valoarea 0.*/


void citireVector(int v[], int& n) {

	ifstream f("vector.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


int DIST(int v[100], int n) {

	for (int i = 0; i < n - 1; i++) {
		if (abs(v[i] - v[i + 1]) == 1 || v[i] == v[i + 1]) {
			cout << abs(v[i] - v[i + 1]) << endl;
			return 0;
		}
	}

	return 1;

}


void solutie3() {

	int v[100], n;

	citireVector(v, n);

	cout << DIST(v, n);

}



//4
/*Fişierul text numere.txt conţine pe prima linie un număr natural n (0<n<100000), iar pe a 
doua linie un şir format din n cifre, separate prin câte un spaţiu. 
a) Scrieţi un program C/C++ care determină în mod eficient din punct de vedere al 
timpului de executare, cea mai mare cifră dintre cele situate pe a doua linie a fişierului, 
precum şi numărul de apariţii ale acesteia. Cele două numere vor fi afişate pe o singură
linie a ecranului, separate printr-un spaţiu.*/


void frecventaCifre(int v[], int n, int fr[]) {

	for (int i = 0; i < n; i++) {
		fr[v[i]]++;
	}

}


void afisareCifrMax(int v[], int n) {

	int fr[10]{};

	frecventaCifre(v, n, fr);

	for (int i = 9; i >= 0; i--) {
		if (fr[i] > 0) {
			cout << i << ' ' << fr[i];
			break;
		}
	}

}


void solutie4() {

	int v[100], n;

	citireVector(v, n);

	afisareCifrMax(v, n);

}