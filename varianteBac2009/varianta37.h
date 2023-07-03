using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Scrieţi un program C/C++ care citeşte numerele naturale nenule n şi k (k≤n≤100) şi un 
tablou unidimensional cu n elemente numere întregi, fiecare având cel mult 4 cifre. 
Programul modifică tabloul, permutând circular, cu k poziţii spre stânga, elementele 
acestuia şi afişează pe ecran, separate prin câte un spaţiu, elementele tabloului obţinut. */


void citireVector(int v[], int& n, int& k) {

	ifstream f("tablouPermutare.txt");

	f >> n;
	f >> k;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


void permutare(int v[], int n, int k) {

	while (k) {
		int termen0 = v[0];
		for (int i = 0; i < n - 1; i++) {
			v[i] = v[i + 1];
		}
		v[n - 1] = termen0;
		k--;
	}

}


void afisareVector(int v[], int n) {

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}

}


void solutie3() {

	int v[100], n, k;
	
	citireVector(v, n, k);

	permutare(v, n, k);

	afisareVector(v, n);

}



//4
/*a) Scrieţi doar antetul subprogramului nrdiv, care primeşte prin intermediul parametrului x
un număr natural nenul cu cel mult 4 cifre, şi returnează numărul de divizori primi ai lui x.
(4p.)
b) Pe prima linie a fişierului bac.in se află un număr natural nenul n (n≤1000), iar pe a 
doua linie a fişierului se află un şir format din n numere naturale nenule, despărţite prin 
câte un spaţiu, fiecare număr fiind format din cel mult 4 cifre. Scrieţi un program C/C++
care citeşte numerele din fişier şi care afişează pe ecran, folosind apeluri utile ale 
subprogramului nrdiv, prima şi ultima valoare din şirul celor n numere citite, care au un 
număr par de divizori primi. Numerele afişate vor fi separate printr-un spaţiu.*/


int nrdiv(int x) {

	int ct = 0;

	for (int d = 2; d <= x; d++) {
		if (x % d == 0) {
			ct++;
			while (x % d == 0) {
				x /= d;
			}
		}
	}

	return ct;

}


void afisarePrimaUltimaValoare() {

	ifstream f("nrParDivizori.txt");

	int n, nr, val2 = -1;

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> nr;
		if (nrdiv(nr) % 2 == 0) {
			if (val2 == -1) {
				cout << nr << ' ';
			}
			val2 = nr;
		}
	}

	cout << val2;

}


void solutie4() {

	afisarePrimaUltimaValoare();

}