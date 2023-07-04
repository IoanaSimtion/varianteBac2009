using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (0<n≤23) şi apoi 
construieşte în memorie o matrice cu n linii şi n coloane astfel încât elementele situate pe 
diagonala principală să fie egale cu 2, cele situate deasupra diagonalei principale să fie 
egale cu 1, iar cele situate sub diagonala principală să fie egale 3.
5. 
Programul va afişa matricea pe ecran, câte o linie a matricei pe o linie a 
ecranului, cu câte un spaţiu între elementele fiecărei linii*/


void generareMatrice(int a[100][100], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				a[i][j] = 1;
			}
			else {
				if (i > j) {
					a[i][j] = 3;
				}
				else {
					a[i][j] = 2;
				}
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
/*Scrieţi definiţia completă a unui subprogram P cu doi parametri, care primeşte prin 
intermediul primului parametru, n, un număr natural nenul (1≤n≤100) şi prin intermediul 
celui de-al doilea parametru, a, un tablou unidimensional cu elementele numerotate de la 1
la n, numere întregi de cel mult 4 cifre fiecare. Subprogramul returnează suma tuturor 
numerelor impare aflate pe poziţii pare din tablou*/


void citireVector(int v[], int& n) {

	ifstream f("vector.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


int P(int a[], int n) {

	int suma = 0;

	for (int i = 0; i < n; i+=2) {
		if (a[i] % 2 == 1) {
			suma += a[i];
		}
	}

	return suma;

}


void solutie3() {

	int a[100], n;

	citireVector(a, n);

	cout << P(a, n);

}



//4
/*Fişierul text numere.txt conţine pe prima linie un număr natural n (0<n<100000) iar pe a 
a doua linie n cifre, separate prin câte un spaţiu. 
a) Scrieţi un program C/C++ care determină în mod eficient, din punct de vedere al timpului 
de executare, cel mai mare număr ce se poate forma cu toate cifrele conţinute de a doua 
linie a fişierului numere.txt. Numărul determinat se va afişa pe ecran*/


void citireNumere(int fr[]) {

	ifstream f("cifreFrecventa.txt");
	int n, nr;

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> nr;
		fr[nr]++;
	}

}


int numarMaximCifre(int fr[]) {

	int nr = 0;

	for (int i = 9; i >= 0; i--) {
		while (fr[i] != 0) {
			nr = nr * 10 + i;
			fr[i]--;
		}
	}

	return nr;

}


void solutie4() {

	int fr[10]{};

	citireNumere(fr);

	cout << numarMaximCifre(fr);

}