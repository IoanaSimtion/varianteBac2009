using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr 
natural n (2<n<10) şi care construieşte în memorie şi afişează pe 
ecran un tablou bidimensional cu n linii şi n coloane astfel încât, 
parcurgându-l linie cu linie de sus în jos şi fiecare linie de la stânga 
la dreapta, se obţin primele n2 numere pare nenule, în ordine strict 
crescătoare, ca în exemplu*/


void generareMatrice(int a[100][100], int n) {

	int nr = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = nr * 2;
			nr++;
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
/*Se consideră subprogramul cmdiv care primeşte prin parametrii x şi y două valori întregi 
pozitive (0<x<100 şi 0<y<100) şi returnează cel mai mare divizor comun al lor.
a) Scrieţi definiţia completă a subprogramului cmdiv. (4p.)
b) Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (1≤n≤100) şi 
determină, utilizând apeluri ale subprogramului cmdiv, numărul fracţiilor ireductibile de 
forma x/n cu x număr natural (1≤x≤n). Numărul obţinut va fi afişat pe ecran. */


int cmdiv(int x, int y) {

	int r;

	do {
		r = x % y;
		x = y;
		y = r;
	} while (r);

	return x;

}


int numarFractiiIreductibile(int n) {

	int ct = 0;

	for (int x = 1; x <= n; x++) {
		if (cmdiv(x, n) == 1) {
			ct++;
		}
	}

	return ct;

}


void solutie3() {

	int n;

	cout << "n=";
	cin >> n;

	cout << numarFractiiIreductibile(n);

}



//4
/*Fişierul text bac.in conţine pe prima linie un număr natural n (0<n<5000), iar pe a doua 
linie, separate prin câte un spaţiu, n numere naturale, formate din cel mult 4 cifre fiecare. 
Scrieţi un program C/C++ care determină şi scrie în fişierul bac.out toate numerele de pe 
a doua linie a fişierului care apar o singură dată pe această linie. Numerele determinate se 
vor afişa în ordinea crescătoare a valorilor lor, separate prin câte un spaţiu*/


void citireVector(int v[], int& n) {

	ifstream f("vectorAparitie.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


void sortareVector(int v[], int n) {

	bool flag = false;

	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (v[i] > v[i + 1]) {
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				flag = false;
			}
		}
	} while (flag == false);

}


void afisareNumere1Aparitie(int v[], int n) {

	for (int i = 0; i < n - 1; i++) {
		if (v[i - 1] != v[i] && v[i] != v[i + 1]) {
			cout << v[i] << ' ';
		}
	}

}


void solutie4() {

	int v[100], n;

	citireVector(v, n);

	sortareVector(v, n);

	afisareNumere1Aparitie(v, n);

}