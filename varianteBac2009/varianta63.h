using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program în limbajul C/C++ care citeşte de la tastatură două valori naturale n şi m
(1≤n≤24, 1≤m≤24) şi construieşte în memorie un tablou bidimensional cu n linii şi m coloane
format din toate numerele naturale de la 1 la n*m, ca în exemplu. Programul va afişa pe 
ecran, pe n linii, tabloul obţinut, elementele fiecărei linii fiind separate prin câte un spaţiu. */


void generareMatrice(int a[100][100], int n, int m) {

	int nr = 1;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[j][i] = nr;
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
/*Subprogramul verif primeşte prin singurul său parametru, x, un număr natural nenul cu
cel mult 9 cifre şi returnează valoarea 1 dacă numărul conţine cel puţin o secvenţă de 3
cifre impare alăturate şi 0 în caz contrar.
Exemplu: dacă x=7325972 se va returna valoarea 1.
a) Scrieţi definiţia completă a subprogramului verif. (6p.)
b) Scrieţi un program C/C++ care citeşte de la tastatură un număr natural nenul n cu exact
6 cifre şi, folosind apeluri utile ale subprogramului verif, verifică dacă n are primele trei
cifre impare. Programul afişează pe ecran mesajul Da în caz afirmativ şi mesajul Nu în caz contrar.*/


int verif(int x) {

	int ct = 0;

	while (x) {
		if ((x % 10) % 2 == 1) {
			ct++;
		}
		else {
			ct = 0;
		}
		if (ct == 3) {
			return 1;
		}
		x /= 10;
	}

	return 0;

}


void solutie3() {

	int n;

	cout << "n=";
	cin >> n;

	if (verif(n / 1000)) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

}



//4
/*Pentru un şir de numere naturale, numim ”nod” al şirului un termen din şir care are doi 
vecini, termenul precedent şi termenul următor din şir, şi valoarea termenului respectiv este 
strict mai mică decât suma valorilor celor doi vecini ai săi. 
a) Fişierul text date.in conţine un şir de cel puţin două şi cel mult 10000 de numere 
naturale având maximum 6 cifre fiecare, numere separate prin câte un spaţiu. Scrieţi un 
program C/C++ care citeşte toate numerele din fişier şi afişează numărul de ”noduri“ ale 
şirului citit, folosind un algoritm eficient din punctul de vedere al memoriei utilizate.*/


void citireNumereAfisareNoduri() {

	ifstream f("nod.txt");

	int a = - 1, b, c, noduri = 0;

	f >> b;

	while (f >> c) {
		if (b < (a + c) && a != -1) {
			noduri++;
		}
		a = b;
		b = c;
	}

	cout << noduri;

}


void solutie4() {

	citireNumereAfisareNoduri();

}