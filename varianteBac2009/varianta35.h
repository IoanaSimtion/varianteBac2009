using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi programul C/C++ care citeşte de la tastatură un număr natural n (n≤50) şi 
construieşte în memorie o matrice cu n linii şi n coloane, ale cărei elemente sunt 
numere întregi citite de la tastatură. Pentru fiecare coloană a matricei, în ordine, programul 
afişează pe ecran cel mai mic număr de pe respectiva coloană. Numerele afişate vor fi 
separate prin câte un spaţiu*/


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

	for (int j = 0; j < n; j++) {
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



//SUBIECTUL 3



//3
/*Fişierul text numere.in conţine pe prima linie un număr natural n (0<n<1000), iar pe a 
doua linie n numere naturale cu cel mult 9 cifre fiecare, despărţite prin câte un spaţiu. 
Scrieţi un program C/C++ care citeşte toate numerele din fişier şi afişează pe ecran, 
separate prin câte un spaţiu, numerele de pe a doua linie a fişierului, care încep şi se 
termină cu aceeaşi cifră.*/


bool primaUltimaCifra(int numar) {

	int ultimaCifra = numar % 10;

	while (numar > 9) {
		numar /= 10;
	}

	if (numar == ultimaCifra) {
		return true;
	}
	return false;

}


void citireAfisareNumere() {

	ifstream f("primaUltimaCifra.txt");

	int n, numar;

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> numar;
		if (primaUltimaCifra(numar)) {
			cout << numar << ' ';
		}
	}

}


void solutie3() {

	citireAfisareNumere();

}



//4
/*a) Scrieţi definiţia completă a unui subprogram sum care primeşte prin parametrul x un 
număr natural de cel mult 4 cifre şi returnează suma divizorilor numărului x, diferiţi de 1 şi 
de el însuşi. 
b) Scrieţi programul C/C++ care citeşte de la tastatură un număr natural n (0<n<100), apoi 
n numere naturale (cu cel mult 4 cifre fiecare). Programul determină, folosind apeluri utile 
ale subprogramului sum, pentru fiecare număr natural citit, suma divizorilor săi proprii şi 
afişează pe ecran sumele determinate, în ordinea crescătoare a valorilor lor, separate prin 
câte un spaţiu.*/


int sum(int x) {

	int suma = 0;

	for (int d = 2; d < x; d++) {
		if (x % d == 0) {
			suma += d;
		}
	}

	return suma;

}


void divizoriProprii(int div[], int& n) {

	ifstream f("numereDivProprii.txt");

	int nr;

	f >> n;
	f >> nr;

	div[0] = sum(nr);
	for (int i = 1; i < n; i++) {
		f >> nr;
		div[i] = sum(nr);
	}

}


void sortCrescator(int v[], int n) {

	bool flag;

	do {
		flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (v[i] > v[i + 1]) {
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				flag = 0;
			}
		}
	} while (flag == 0);

}


void afisareDivizoriProprii(int div[], int n) {

	for (int i = 0; i < n; i++) {
		cout << div[i] << ' ';
	}

}


void solutie4() {

	//cout << sum(10);

	int div[100], n;

	divizoriProprii(div, n);

	sortCrescator(div, n);

	afisareDivizoriProprii(div, n);

}