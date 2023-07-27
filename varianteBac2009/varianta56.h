using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2


//5
/*Scrieţi un program C/C++ care citeşte de la tastatură două numere naturale n şi k
(2<n<25, 0<k<n) şi construieşte în memorie o matrice cu n linii şi n coloane formată
numai din valori 1,2,3 şi 4 astfel încât: elementele aflate la intersecţia primelor k linii cu 
primele k coloane sunt egale cu 1, elementele aflate la intersecţia primelor k linii cu ultimele 
n-k coloane sunt egale cu 2, elementele aflate la intersecţia ultimelor n-k linii cu primele k
coloane sunt egale cu 3, elementele aflate la intersecţia ultimelor n-k linii cu ultimele n-k
coloane sunt egale cu 4 ca în exemplul de mai jos. 
5. 
Programul afişează pe ecran matricea construită, fiecare linie a 
matricei pe o linie a ecranului şi elementele de pe aceeaşi linie 
separate prin câte un singur spaţiu.*/


void generareMatrice(int a[100][100], int n, int k) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < k) {
				if (j < k) {
					a[i][j] = 1;
				}
				else {
					a[i][j] = 2;
				}
			}
			else {
				if (j < k) {
					a[i][j] = 3;
				}
				else {
					a[i][j] = 4;
				}
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

	int a[100][100], n, k;

	cout << "n=";
	cin >> n;
	cout << "k=";
	cin >> k;

	generareMatrice(a, n, k);

	afisareMatrice(a, n);

}



//SUBIECTUL 3



//3
/*Fişierul text numere.txt conţine, pe o singură linie, cel mult 1000 de numere naturale 
nenule cu cel mult 4 cifre fiecare, numerele fiind separate prin câte un spaţiu. Scrieţi un 
program C/C++ care citeşte toate numerele din fişier şi scrie pe ecran toate numerele pare 
citite, ordonate crescător. Dacă fişierul numere.txt nu conţine niciun număr par, atunci se 
va afişa pe ecran mesajul nu exista. */


void citireNumere(int v[], int& n) {

	ifstream f("numerePare.txt");

	int nr;

	n = 0;

	while (!f.eof()) {
		f >> nr;
		if (nr % 2 == 0) {
			v[n] = nr;
			n++;
		}
	}

}


void ordonareVector(int v[], int n) {

	bool flag;

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


void afisareVector(int v[], int n) {

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}

}


void solutie3() {

	int v[100], n;

	citireNumere(v, n);

	if (n == 0) {
		cout << "nu exista";
	}
	else {
		ordonareVector(v, n);
		afisareVector(v, n);
	}

}



//4
/*Se consideră subprogramele 
– prim, care primeşte prin intermediul unicului său parametrului x un număr natural nenul 
de cel mult 4 cifre şi returnează valoarea 1 dacă x este un număr prim şi 0 în caz contrar; 
– numar, care primeşte prin intermediul parametrului x un număr natural nenul de cel mult 
4 cifre şi furnizează prin intermediul parametrului nrp numărul de numere prime mai mici 
decât x. 
a) Scrieţi numai antetul subprogramului prim şi definiţia completă a subprogramului 
numar. (6p.)
b) Scrieţi un programul C/C++ în care se citesc de la tastatură două numere naturale 
nenule de cel mult 4 cifre, a şi b (a<b), şi, prin apeluri utile ale subprogramului numar, se 
verifică dacă intervalul închis [a,b] conţine cel puţin un număr prim. Programul va afişa pe 
ecran, în caz afirmativ, mesajul DA, iar în caz contrar, mesajul NU. */


int prim(int x) {

	for (int d = 2; d < sqrt(x); d++) {
		if (x % d == 0) {
			return 0;
		}
	}
	return 1;

}


void numar(int x, int& nrp) {

	nrp = 0;

	for (int nr = 0; nr < x; nr++) {
		if (prim(nr) == 1) {
			nrp++;
		}
	}

}


bool nrPrimeInterval(int a, int b) {

	int nrpA, nrpB;

	numar(b, nrpB);
	numar(a, nrpA);

	if (prim(a)) {
		nrpA++;
	}
	if (prim(b)) {
		nrpB++;
	}

	if (nrpB - nrpA > 0) {
		return true;
	}
	return false;

}


void solutie4() {

	int a, b;

	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;

	if (nrPrimeInterval(a, b) == true) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

}