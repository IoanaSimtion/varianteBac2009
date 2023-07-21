using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Se consideră subprogramul cifre, care primeşte prin intermediul primului parametru, a, un 
număr natural cu maximum 8 cifre nenule şi returnează, prin intermediul celui de-al doilea 
parametrul b, cel mai mic număr care se poate forma cu toate cifrele distincte ale lui a. 
a) Scrieţi definiţia completă a subprogramului cifre. (4p.) 
b) Se consideră fişierul text date.in ce conţine pe prima linie un număr natural nenul n
(n≤100), iar pe a doua linie n numere naturale, separate prin câte un spaţiu, fiecare număr 
având maximum 8 cifre nenule. Scrieţi un program C/C++ care citeşte toate numerele din 
fişierul text date.in şi afişează pe ecran, despărţite prin câte un spaţiu, numerele situate 
pe a doua linie a fişierului, formate numai din cifre distincte ordonate strict crescător, 
folosind apeluri utile ale subprogramului cifre. În cazul în care nu există niciun astfel de 
număr se va afişa valoarea 0*/


void cifre(int a, int& b) {

	int fr[10]{};
	b = 0;

	while (a) {
		fr[a % 10]++;
		a /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (fr[i] == 1) {
			b = b * 10 + i;
		}
	}

}


void citireAfisareNumere() {

	ifstream f("cifreDistincte.txt");

	int n, nr, nr2;

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> nr;
		cifre(nr, nr2);
		if (nr == nr2) {
			cout << nr << ' ';
		}
	}

}


void solutie3() {

	citireAfisareNumere();

}



//4
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural nenul n (n≤100) 
şi 2*n numere naturale de maximum 3 cifre; primele n reprezintă elementele tabloului 
unidimensional a, iar următoarele n elementele tabloului unidimensional b; fiecare tablou 
are elementele numerotate începând de la 1. Programul construieste în memorie şi 
afişează pe ecran, cu spaţii între ele, cele n elemente ale unui tablou unidimensional c, în 
care orice element ci (1≤i≤n) se obţine conform definiţiei următoare: 
ci = ┌ ai concatenat cu bi, dacă ai<bi
└ bi concatenat cu ai, altfel*/


void citireVectori(int a[], int b[], int& n) {

	ifstream f("vectoriConcatenare.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> a[i];
	}
	for (int i = 0; i < n; i++) {
		f >> b[i];
	}

}


int nrCifre(int n) {

	int ct = 0;

	while (n) {
		ct++;
		n /= 10;
	}

	return ct;

}


void concatenare(int a[], int b[], int c[], int n) {

	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			c[i] = a[i] * pow(10, nrCifre(b[i])) + b[i];
		}
		else {
			c[i] = b[i] * pow(10, nrCifre(a[i])) + a[i];
		}
	}

}


void afisareVector(int c[], int n) {

	for (int i = 0; i < n; i++) {
		cout << c[i] << ' ';
	}

}


void solutie4() {

	int a[100], b[100], c[100], n;

	citireVectori(a, b, n);

	concatenare(a, b, c, n);

	afisareVector(c, n);

}