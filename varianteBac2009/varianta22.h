using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2


//5
/*Scrieţi un program C/C++ care citeşte de la tastatură numerele naturale m şi n din intervalul 
[1,24], apoi construieşte în memorie şi afişează pe ecran un tablou bidimensional cu m
linii şi n coloane astfel încât prin parcurgerea acestuia linie cu linie de sus în jos şi fiecare 
linie de la stânga la dreapta, se obţin în ordine descrescătoare toate numerele naturale de 
la 1 la m*n, ca în exemplu.
5. 
Fiecare linie a tabloului este afişată pe câte o linie a ecranului, elementele 
aceleiaşi linii fiind separate prin câte un spaţiu.*/


void generareMatrice(int a[100][100], int n, int m) {

	int produs = m * n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = produs;
			produs--;
		}
	}

}


void afisareMatrice(int a[100][100], int n, int m) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

}


void sol5() {

	int a[100][100], n, m;

	cout << "m=";
	cin >> m;
	cout << "n=";
	cin >> n;

	generareMatrice(a, n, m);

	afisareMatrice(a, n, m);

}



//SUBIECTUL 3


//3
/*a) Scrieţi definiţia completă a unui subprogram, nz, cu un parametru întreg n (0<n≤32000), 
care returnează numărul zerourilor de la sfârşitul numărului n!. (6p.) 
b) Scrieţi programul C/C++ care citește de la tastatură un număr natural k (0<k≤3) și 
determină, folosind apeluri ale subprogramului nz, cel mai mic număr natural n pentru care 
n! are cel puţin k zerouri la sfârşit. Numărul determinat se afișează pe ecran*/


int nz(int n) {

	int p5 = 0;

	for (int i = 5; i <= n; i += 5) {
		int j = i;
		while (j % 5 == 0) {
			p5++;
			j /= 5;
		}
	}

	return p5;

}


void solutie3() {

	int n = 4, k;

	cout << "k=";
	cin >> k;

	do {
		n++;
	} while (nz(n) < k);

	cout << n;

}



//4
/*Scrieţi programul C/C++ care citeşte din fişierul text BAC.TXT numărul întreg n
(1≤n≤10000) şi un şir de n perechi de numere întregi a b (1≤a≤b≤32000), fiecare pereche 
fiind scrisă pe o linie nouă a fişierului, cu un spaţiu între cele două numere. Programul 
afişează pe ecran pentru fiecare pereche a,b cel mai mare număr natural din intervalul 
închis [a,b]care este o putere a lui 2 sau numărul 0 dacă nu există nicio putere a lui 2 în 
intervalul respectiv. Numerele afișate pe ecran se scriu în linie, separate prin câte un 
spașiu. Un număr p este putere a lui 2 dacă există un număr natural k astfel încât p=2k*/


int nrPuterea2(int n) {

	int p = 1;

	while (p <= n) {
		p *= 2;
	}

	return p / 2;

}


void citireAfisare() {

	ifstream f("puterea2.txt");
	int n, a, b;

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> a >> b;
		if (nrPuterea2(b) >= a) {
			cout << nrPuterea2(b) << ' ';
		}
		else {
			cout << 0 << ' ';
		}
	}

}


void solutie4() {

	citireAfisare();

}