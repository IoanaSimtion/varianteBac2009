using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Scrieţi definiţia completă a subprogramului suma care primeşte ca parametru un tablou 
unidimensional x cu cel mult 100 de elemente, numere reale, un număr natural n ce 
reprezintă numărul efectiv de elemente ale tabloului x (n≤100), şi un număr natural m (n≥m). 
Subprogramul returnează suma obţinută din cele mai mici m elemente ale tabloului x.  */


void citireVector(int v[], int& n) {

	ifstream f("vectorOrdonare.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


int suma(int v[], int n, int m) {

	int s = 0;
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

	for (int i = 0; i < m; i++) {
		s += v[i];
	}

	return s;

}


void solutie3() {

	int v[100], n, m;

	cout << "m=";
	cin >> m;

	citireVector(v, n);

	cout << suma(v, n, m);

}



//4
/*În fişierul numere.txt se află memorate, pe prima linie un număr natural n (1≤n≤100), iar 
pe fiecare dintre următoarele n linii, câte două numere întregi x,y (-100≤x≤y≤100),
reprezentând capetele câte unui segment [x,y] desenat pe axa Ox de coordonate. 
a) Scrieţi în limbajul C/C++ un program eficient din punct de vedere al timpului de executare
şi al spaţiului de memorare, care citeşte din fişier datele existente, determină segmentul 
rezultat în urma intersecţiei tuturor celor n segmente date şi afişează pe ecran două numere 
despărţie printr-un spaţiu ce reprezintă capetele segmentului cerut. Dacă segmentele nu au 
nici un punct comun se va afişa pe ecran valoarea 0. */


void citireAfisareCoordonate() {

	ifstream f("coordonateSegmente.txt");

	int x, y, n, xMax, yMin;

	f >> n;
	f >> x >> y;
	xMax = x;
	yMin = y;

	for (int i = 0; i < n; i++) {
		f >> x >> y;
		if (x > xMax) {
			xMax = x;
		}
		if (y < yMin) {
			yMin = y;
		}
	}

	if (xMax < yMin) {
		cout << xMax << ' ' << yMin;
	}
	else {
		cout << 0;
	}

}


void solutie4() {

	citireAfisareCoordonate();

}