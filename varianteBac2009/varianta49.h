using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n ( 1≤n≤50) şi apoi 
un şir de n numere naturale cu cel mult 4 cifre fiecare şi care verifică dacă elementele şirului 
pot fi rearanjate astfel încât să respecte regula: al doilea element este cu 1 mai mare decât 
primul, al treilea cu 2 mai mare decât al doilea, ... , ultimul este cu n-1 mai mare decât 
penultimul. Programul afişează pe ecran mesajul DA în caz afirmativ şi mesajul NU în caz 
contrar.*/


void citireVector(int v[], int& n) {

	ifstream f("rearanjare.txt");

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


bool rearanjare(int v[], int n) {

	for (int i = 0; i < n - 1; i++) {
		if (v[i + 1] - v[i] != i + 1) {
			return false;
		}
	}

	return true;

}


void solutie3() {

	int v[100], n;

	citireVector(v, n);

	sortareVector(v, n);

	if (rearanjare(v, n) == true) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

}



//4
/*Se consideră subprogramul cmax care prin parametrul a primeşte un număr natural nenul 
mai mic decât 30000, iar prin parametrul b furnizează cifra maximă din numărul a. 
a) Scrieţi, folosind limbajul C/C++, doar antetul subprogramului cmax. (4p.)
b) Fişierul bac.txt conţine cel mult 1000 numere naturale nenule, mai mici decât 30000
fiecare, separate prin câte un spaţiu. Scrieţi programul C/C++ care citeşte din fişierul 
bac.txt toate numerele şi care determină cea mai mare cifră din scrierea lor şi cel mai mic 
dintre numerele care conţin această cifră, folosind apeluri utile ale subprogramului cmax. 
Cifra şi numărul determinate se vor afişa pe ecran, separate printr-un spaţiu.*/


void cmax(int a, int& b) {

	b = 0;

	while (a) {
		if (a % 10 > b) {
			b = a % 10;
		}
		a /= 10;
	}

}


void minimCiraMax(int& cifra, int& minim) {

	ifstream f("minCifrMax.txt");

	int nr, cifrMax = 0;

	cifra = 0, minim = INT_MAX;

	while (!f.eof()) {
		f >> nr;
		cmax(nr, cifrMax);
		if (cifrMax > cifra) {
			cifra = cifrMax;
			minim = nr;			
		}
		else {
			if (cifrMax == cifra) {
				if (nr < minim) {
					minim = nr;
				}
			}
		}
	}

}


void solutie4() {

	int cifra, numar;

	minimCiraMax(cifra, numar);

	cout << cifra << ' ' << numar;

}