using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2


//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (2<n<20),
construieşte în memorie şi afişează pe ecran o matrice cu n linii şi n coloane, numerotate 
de la 1 la n în care fiecare element din matrice aflat pe o linie impară va fi egal cu numărul 
liniei pe care se află şi fiecare element aflat pe o linie pară va fi egal cu numărul coloanei pe 
care se află. 
5. 
Elementele matricei vor fi afişate pe ecran, câte o linie a matricei pe 
câte o linie a ecranului cu câte un spaţiu între elementele fiecărei linii.*/


void generareMatrice(int a[100][100], int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i % 2 == 0) {
				a[i][j] = j;
			}
			else {
				a[i][j] = i;
			}
		}
	}

}


void afisareMatrice(int a[100][100], int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

}


void sol5() {

	int a[100][100], n = 5;

	generareMatrice(a, n);

	afisareMatrice(a, n);

}



//SUBIECTUL 3


//3
/*Scrieţi definiţia completă a subprogramului count care are doi parametri, a şi n, prin care 
primeşte un tablou unidimensional cu maximum 100 de numere reale şi respectiv numărul 
efectiv de elemente din tablou. Subprogramul returnează numărul de elemente din tabloul a
care sunt mai mari sau cel puţin egale cu media aritmetică a tuturor elementelor din tablou.*/


void citireVector(float a[], int& n) {

	ifstream f("tablou2.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> a[i];
	}

}


int count(float a[], int n) {

	int medie = 0, s = 0, ct = 0;

	for (int i = 0; i < n; i++) {
		s += a[i];
	}

	medie = s / n;

	for (int i = 0; i < n; i++) {
		if (a[i] >= medie) {
			ct++;
		}
	}

	return ct;

}


void solutie3() {

	float a[100];
	int n;

	citireVector(a, n);

	cout << count(a, n);

}



//4
/*În fişierul numere.txt este memorat un şir de maximum 10000 numere naturale, distincte 
două câte două, cu maximum 4 cifre fiecare, separate prin câte un spaţiu. Pentru un număr 
k citit de la tastatură, se cere afişarea pe ecran a poziţiei pe care se va găsi acesta în şirul 
de numere din fişier, dacă şirul ar fi ordonat descrescător, sau mesajul nu există, dacă
numărul k nu se află printre numerele din fişier. Alegeţi un algoritm eficient de rezolvare din 
punct de vedere al memoriei utilizate şi al timpului de executare. */


void pozitie(int k) {

	ifstream f("numereOrdonare.txt");

	int nr, poz = 0;
	bool exista = 0;

	while (!f.eof()) {
		f >> nr;
		if (nr > k) {
			poz++;
		}
		else {
			if (k == nr) {
				exista = 1;
			}
		}
	}

	if (exista) {
		cout << poz + 1;
	}
	else {
		cout << "nu exista";
	}

}


void solutie4() {

	int k;

	cout << "k=";
	cin >> k;

	pozitie(k);

}
