using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Scrieţi programul C/C++ care citeşte de la tastatură numărul natural n (0<n<100) şi un şir 
format din n numere reale. Aceste numere au atât partea întreagă cât şi partea fracţionară
formate din cel mult trei cifre. Programul determină şi afişează pe ecran toate numerele din 
şir care apar o singură dată în acesta.*/


void citireVector(float v[], int& n) {

	ifstream f("vectorFloat.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


void afisareNumere1Aparitie(float v[], int n) {

	for (int i = 0; i < n; i++) {
		int j;
		for (j = 0; j < n; j++) {
			if (v[i] == v[j] && i != j) {
				break;
			}
		}
		if (j == n) {
			cout << v[i] << ' ';
		}
	}

}


void solutie3() {

	float v[100];
	int n;

	citireVector(v, n);

	afisareNumere1Aparitie(v, n);

}



//4
/*Fişierul text numere.txt conţine pe prima linie un număr natural n (0<n<100000), iar pe a 
doua linie n numere naturale, formate din cel mult două cifre, separate prin câte un spaţiu. 
a) Scrieţi un program C/C++, eficient atât din punct de vedere al timpului de executare, care 
afişează pe ecran toate numerele situate pe a doua linie a fişierului, în ordinea crescătoare
a valorilor lor, separate prin câte un spaţiu.*/


void citireVector(int v[], int& n) {

	ifstream f("vectorOrdonare.txt");

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


void afisareVector(int v[], int n) {

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}

}


void solutie4() {

	int v[100], n;

	citireVector(v, n);

	sortareVector(v, n);

	afisareVector(v, n);

}
