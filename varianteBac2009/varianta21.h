using namespace std;
#include <iostream>
#include <fstream>
#include <math.h>
#pragma once


//SUBIECTUL 3


//3
/*Scrieţi definiţia completă a unui subprogram i_prim care primeşte prin singurul său 
parametru, n, un număr natural din intervalul [2,30000] şi returnează diferenţa minimă
p2-p1 în care p1 şi p2 sunt numere prime şi p1≤n≤p2. */


int i_prim(int n) {

	int p1 = 0, p2 = 0;

	for (int i = n; i >= 0 && p1 == 0; i--) {
		bool prim = 1;
		for (int j = 2; j < sqrt(n) && prim; j++) {
			if (i % j == 0) {
				prim = 0;
			}
		}
		if (prim) {
			p1 = i;
		}
	}
	
	for (int i = n; i <= 200000 && p2 == 0; i++) {
		bool prim = 1;
		for (int j = 2; j < sqrt(n) && prim; j++) {
			if (i % j == 0) {
				prim = 0;
			}
		}
		if (prim) {
			p2 = i;
		}
	}

	return p2 - p1;
}


void solutie3() {

	int n;

	cout << "n=";
	cin >> n;

	cout << i_prim(n);

}



//4
/*Fişierul text BAC.TXT conţine pe prima linie două numere naturale n şi k separate de un 
spaţiu (3≤n≤10000, 2≤k≤n/2), iar pe a doua linie un şir de n numere naturale x1, x2, ..., 
xn separate prin câte un spaţiu, fiecare număr din acest şir având cel mult patru cifre. 
a) Scrieţi un program C/C++ care citeşte numerele din fişier şi determină, utilizând o 
metodă eficientă din punct de vedere al timpului de executare, cel mai mic indice i (1≤i≤nk+1) 
pentru care media aritmetică a numerelor xi, xi+1, ..., xi+k-1 este maximă. 
Programul afişează valoarea lui i pe ecran.*/


void citireVector(int x[], int& n, int& k, int& suma) {

	ifstream f("BAC5.TXT");

	f >> n >> k;

	for (int i = 1; i <= n; i++) {
		f >> x[i];
		suma += x[i];
	}

}


int indice(int x[], int suma, int n, int k) {

	int imax = 1, sumaMax = suma, i = 1;

	for (int j = k + 1; j <= n; j++) {
		suma = suma - x[i] + x[j];
		i++;
		if (suma > sumaMax) {
			sumaMax = suma;
			imax = i;
		}
	}
	
	return imax;

}


void solutie4() {

	int x[10000], n, k, suma = 0;

	citireVector(x, n, k, suma);

	cout << indice(x, suma, n, k);

}