using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program în limbajul C/C++ care citeşte de la tastatură două valori naturale n şi m
(1≤n≤24, 1≤m≤24) şi construieşte în memorie un tablou bidimensional cu n linii şi m coloane
format din toate numerele naturale de la 1 la n*m, ca în exemplu. Programul va afişa pe 
ecran, pe n linii, tabloul obţinut, elementele fiecărei linii fiind separate prin câte un spaţiu.*/


void generareMatrice(int a[100][100], int n, int m) {

	int nr = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = nr;
			nr++;
		}
	}

}


void afisareMatrice(int a[100][100], int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

}


void sol5() {

	int a[100][100], n, m;

	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;

	generareMatrice(a, n, m);

	afisareMatrice(a, n, m);

}



//SUBIECTUL 3



//3
/*Subprogramul sfx primeşte prin singurul său parametru, x, un număr natural din intervalul
[100,2000000000] şi returnează valoarea 1 dacă ultimele trei cifre ale numărului sunt în 
ordine strict descrescătoare sau valoarea 0 în caz contrar. 
Exemplu: dacă x=24973 se va returna valoarea 1. 
a) Scrieţi definiţia completă a subprogramului sfx. (5p.)
b) Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n format din exact 
6 cifre şi verifică, utilizând apeluri ale subprogramului sfx, dacă acest număr are toate cifrele 
în ordine strict descrescătoare. Programul va afişa mesajul Da în caz afirmativ şi mesajul Nu
în caz contrar. */


int sfx(int x) {

	if ((x / 100) % 10 > (x / 10) % 10 && (x / 10) % 10 > x % 10) {
		return 1;
	}
	return 0;

}


void solutie3() {

	int n;

	cout << "n=";
	cin >> n;

	if (sfx(n) == sfx(n / 1000)) {
		cout << "Da";
	}
	else {
		cout << "Nu";
	}

}



//4
/*Pentru un şir de numere naturale, numim ”pol” al şirului un termen din şir care are doi vecini,
termenul precedent şi termenul următor din şir, şi valoarea termenului respectiv este strict 
mai mare decât valoarea fiecăruia dintre cei doi vecini ai săi. 
a) Fişierul text date.in conţine un şir de cel mult 10000 de numere naturale având 
maximum 6 cifre fiecare, numere separate prin câte un spaţiu. Scrieţi un program C/C++
care citeşte toate numerele din fişier şi afişează numărul de ”poli“ ai şirului citit, folosind un 
algoritm eficient din punctul de vedere al memoriei utilizate.*/


void citireNumereAfisarePoli() {

	ifstream f("poli.txt");

	int a = -1, b, c, poli = 0;

	f >> b;

	while (f >> c) {
		cout << b << ' ';
		if (b > (a + c) && a != -1) {
			poli++;
		}
		a = b;
		b = c;
	}

	cout << poli;

}


void solutie4() {

	citireNumereAfisarePoli();

}