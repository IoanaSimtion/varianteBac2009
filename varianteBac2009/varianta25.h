using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Se consideră un tablou bidimensional cu m linii şi n coloane (1≤m≤100, 1≤n≤100), ale cărui 
elemente aparţin mulţimii {0,1,2}. Scrieţi un program C/C++ citeşte de la tastatură valorile m, 
n şi elementele tabloului şi care afişează pe ecran numerele de ordine ale coloanelor pentru 
care produsul elementelor situate pe ele, este maxim. Liniile şi coloanele tabloului se 
numerotează de la 1 la m, respectiv de la 1 la n. Numerele se vor afişa separate prin câte 
un spaţiu. */


void citireMatrice(int a[100][100], int& n, int& m) {

	ifstream f("matrice2.txt");

	f >> n >> m;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			f >> a[i][j];
		}
	}

}


int produsColoana(int a[100][100], int m, int coloana) {

	int prod = 1;

	for (int i = 1; i <= m; i++) {
		prod += a[i][coloana];
	}

	return prod;

}


int produsMax(int a[100][100], int n, int m) {

	int maxim = 0;

	for (int j = 0; j < n; j++) {
		if (produsColoana(a, m, j) > maxim) {
			maxim = produsColoana(a, m, j);
		}
	}

	return maxim;

}


void indiciProdusMaxim(int a[100][100], int n, int m, int indici[], int& d) {

	d = 0;

	for (int j = 0; j < n; j++) {
		if (produsColoana(a, m, j) == produsMax(a, n, m)) {
			indici[d] = j;
			d++;
		}
	}
	
}


void sol5() {

	int a[100][100], n, m, indici[100], d;

	citireMatrice(a, n, m);

	indiciProdusMaxim(a, n, m, indici, d);

	for (int i = 0; i < d; i++) {
		cout << indici[i] << ' ';
	}

}



//SUBIECTUL 3


//3
/*Subprogramul f primeşte prin intermediul parametrului n un număr natural nenul (1≤n≤9), 
iar prin intermediul parametrului a, un tablou unidimensional care conţine n valori naturale, 
fiecare dintre acestea reprezentând câte o cifră a unui număr. Astfel, a0 reprezintă cifra 
unităţilor numărului, a1 cifra zecilor etc. 
Subprogramul furnizează prin parametrul k o valoare naturală egală cu numărul obţinut din 
cifrele pare reţinute în tabloul a sau valoarea -1 dacă în tablou nu există nicio cifră pară. 
Scrieţi definiţia completă a subprogramului f. */


void f(int n, int a[], int& k) {

	k = 0;
	int ct = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] % 2 == 0) {
			k = k * 10 + a[i];
			ct++;
		}
	}

	if (ct == 0) {
		k = -1;
	}

}


void citireVector(int a[], int& n) {

	ifstream f("cifre.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> a[i];
	}

}


void solutie3() {

	int a[100], n, k;

	citireVector(a, n);

	f(n, a, k);

	cout << k;
}



//4
/*Fişierul text NUMAR.TXT conţine pe prima linie un număr real pozitiv x care are cel mult 
două cifre la partea întreagă şi cel mult şapte cifre după punctul zecimal.. 
a) Scrieţi un program C/C++ care, utilizând un algoritm eficient din punct de vedere al 
timpului de executare şi al memoriei utilizate, afişează pe ecran, separate printr-un spaţiu, 
două numere naturale al căror raport este egal cu x şi a căror diferenţă absolută este 
minimă.*/


void afisareValori(float x) {

	//CONDITII
	// --> daca x < 1 => a < b
	// --> daca x > 1 => a > b
	// --> daca x = 1 => a = b


	int a, b = 1;
	
	while (x * b != int(x * b)) {
		b++;
	}

	a = x * b;

	cout << a << ' ' << b;

}


void solutie4() {

	ifstream f("numar.txt");

	float x;

	f >> x;

	afisareValori(x);

}