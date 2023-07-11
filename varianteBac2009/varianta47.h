using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură două numere naturale m şi n
(0<m≤10, 0<n≤10) şi elementele unui tablou bidimensional cu m linii şi n coloane care 
reţine numere naturale mai mici decât 100; programul va construi şi va afişa pe ecran un 
nou tablou bidimensional cu n linii şi m coloane, obţinut din primul prin rotirea acestuia în 
sens trigonometric cu 90o, ca în exemplu. */


void citireMatrice(int a[100][100], int& n, int& m) {

	ifstream f("matriceRotire90.txt");

	f >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			f >> a[i][j];
		}
	}

}


void rotireMatrice90(int a[100][100], int b[100][100], int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[n - j][i] = a[i][j];
		}
	}

}


void afisareMatrice(int b[100][100], int n, int m) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}

}


void sol5() {

	int a[100][100], b[100][100], n, m;

	citireMatrice(a, n, m);

	rotireMatrice90(a, b, n, m);

	afisareMatrice(b, n, m);

}



//SUBIECTUL 3



//3
/*Fişierul text bac.txt conţine pe prima linie un număr natural n (n<100), iar pe a doua 
linie, separate prin câte un spaţiu, n numere naturale de cel mult 8 cifre fiecare. 
Scrieţi un program C/C++ care citeşte de la tastatură un număr natural k (k<50) precum 
şi numerele din fişierul bac.txt şi afişează pe ecran, cu câte un spaţiu între ele, toate 
numerele de pe a doua linie a fişierului care sunt puteri ale lui k. Un număr natural x este 
putere a lui k dacă există un număr natural y astfel încât x=k
y. Dacă nu există un asemenea număr pe a doua linie a fişierului, se afişează pe ecran mesajul NU.*/


bool ePutere(int x, int k) {

	for (int i = 0; pow(k, i) <= x; i++) {
		if (x == pow(k, i)) {
			return true;
		}
	}

	return false;

}


void citireAfisareNumere() {

	ifstream f("nrPuteri.txt");

	int n, nr, k, exista = 0;

	f >> n;
	f >> k;

	for (int i = 0; i < n; i++) {
		f >> nr;
		if (ePutere(nr, k)) {
			cout << nr << ' ';
			exista = 1;
		}
	}

	if (!exista) {
		cout << "NU";
	}

}


void solutie3() {

	citireAfisareNumere();

}



//4
/*a) Scrieţi în limbajul C/C++ doar antetul unui subprogram cif, care primeşte prin 
intermediul primului parametru, nr, un număr natural cu cel mult 9 cifre şi furnizează prin 
intermediul celui de-al doilea parametru, s, suma cifrelor din scrierea lui nr. (4p.)
b) Scrieţi programul C/C++ care citeşte de la tastatură un număr natural n (0<n<25), apoi 
un şir de n numere naturale nenule cu cel mult 9 cifre fiecare şi care afişează pe ecran, 
separate prin câte un spaţiu, numerele din şir care au suma cifrelor maximă, folosind 
apeluri utile ale subprogramului cif. */


void cif(int nr, int& s) {

	s = 0;

	while (nr) {
		s += nr % 10;
		nr /= 10;
	}

}


void citireNumere(int v[], int& n, int& maxim) {

	ifstream f("vectorSumaCifreMax.txt");

	int suma;

	maxim = 0;

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
		cif(v[i], suma);
		if (suma > maxim) {
			maxim = suma;
		}
	}

}


void afisareElementeSumaMax(int v[], int n, int maxim) {

	int suma;

	for (int i = 0; i < n; i++) {
		cif(v[i], suma);
		if (suma == maxim) {
			cout << v[i] << ' ';
		}
	}

}


void solutie4() {

	int v[100], n, maxim;

	citireNumere(v, n, maxim);

	afisareElementeSumaMax(v, n, maxim);

}