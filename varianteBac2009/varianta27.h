using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural 
n (2<n<=10) şi construieşte în memorie o matrice A cu n linii şi n
coloane în care toate elementele de pe prima linie, prima şi ultima 
coloană au valoarea 1 şi oricare alt element Aij din matrice este egal cu 
suma a 3 elemente situate pe linia i-1: primul aflat pe coloana j-1, al 
doilea pe coloana j, iar al treilea pe coloana j+1, ca în exemplu. 
Matricea va fi afişată pe ecran, linie cu linie, numerele de pe aceeaşi 
linie fiind separate prin câte un spaţiu. */


void generareMatrice(int a[100][100], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0 || j == n - 1) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1];
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
/*Scrieţi definiţa completă a subprogramului nreal cu doi parametri x şi y, numere naturale 
din intervalul [1;1000] ce returnează un număr real cu proprietatea că partea sa întreagă
este egală cu x, iar numărul format din zecimalele sale, în aceeaşi ordine, este egal cu y.*/


float nreal(int x, int y) {

	float nr;

	if (y < 10) {
		nr = ((float)y) / 10;
	}
	else {
		if (y < 100) {
			nr = ((float)y) / 100;
		}
		else {
			if (y < 1000) {
				nr = ((float)y) / 1000;
			}
			else {
				nr = ((float)y) / 10000;
			}
		}
	}

	nr = nr + x;

	return nr;

}


void solutie3() {

	int x, y;

	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;

	cout << nreal(x, y);

}



//4
/*Fişierul text NUMERE.IN conţine pe prima linie un număr natural nenul n (2≤n≤100) şi pe 
următoarea linie n numere reale pozitive, în ordine strict crescătoare, separate prin câte un 
spaţiu. 
a) Scrieţi un program C/C++ care, utilizând un algoritm eficient din punct de vedere al 
memoriei utilizate, determină şi afişează pe ecran cel mai mare număr natural x cu 
proprietatea că în orice interval deschis având drept capete oricare două dintre cele n numere 
aflate pe linia a doua în fişierul NUMERE.IN se găsesc cel puţin x numere întregi.*/


void afisareNumar() {

	ifstream f("numereIntervale.txt");

	int n, x = -1;
	float a, b;

	f >> n;
	f >> a;

	while (f >> b) {
		if ((int)b - (int)a < x || x == -1) {
			x = (int)b - (int)a;
		}
		a = b;
	}
	
	cout << x;

}


void solutie4() {

	afisareNumar();

}
