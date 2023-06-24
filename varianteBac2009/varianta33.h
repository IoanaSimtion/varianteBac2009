using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Subprogramul sum3 primeşte prin parametrul x un tablou unidimensional, cu cel mult 100
de elemente, numere întregi cu cel mult 4 cifre fiecare, iar prin parametrul n un număr 
natural ce reprezintă numărul efectiv de elemente ale tabloului x (n≤100). Scrieţi definiţia 
completă a subprogramului sum3 care returnează suma elementelor tabloului care sunt 
divizibile cu 3. Dacă tabloul nu conţine nicio valoare divizibilă cu 3, subprogramul va returna 
0.*/


void citireVector(int x[], int& n) {

	ifstream f("sum.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> x[i];
	}

}


int sum3(int x[100], int n) {

	int suma = 0;

	for (int i = 0; i < n; i++) {
		if (x[i] % 3 == 0) {
			suma += x[i];
		}
	}

	return suma;

}


void solutie3() {

	int x[100], n;

	citireVector(x, n);

	cout << sum3(x,n);

}



//4
/*Pe prima linie a fişierului numere.txt se află un număr natural n (n≤100), iar pe 
următoarele n linii, câte n numere naturale despărţite prin câte un spaţiu, fiecare având cel 
mult 9 cifre. Printre aceste numere se află cel puţin unul cu 3 cifre şi cel puţin unul cu 4 cifre.
a) Scrieţi în limbajul C/C++, un algoritm eficient din punct de vedere al gestionării memoriei 
care citeşte din fişier datele existente şi determină şi afişează pe ecran, separate printr-un 
spaţiu, două numere din fişier, x şi y, unde x este cel mai mare număr de trei cifre, iar y
este acel număr pentru care |x-y| are valoare minimă. Dacă sunt mai multe valori pentru y
care respectă condiţia impusă se va afişa numai una dintre ele. */


void citireAfisare() {

	ifstream f("numereXY.txt");

	int x = 0, y, z = 9999, n;
	double k;

	f >> n;

	for (int i = 0; i < n * n; i++) {
		f >> k;
		if (k <= 999) {
			if (k > x) {
				y = x;
				x = k;
			}
			else {
				if (k > y) {
					y = k;
				}
			}
		}
		else {
			if (k >= 1000 && k <= 9999) {
				if (k < z) {
					z = k;
				}
			}
		}
	}

	if (x - y < z - x) {
		cout << x << ' ' << y;
	}
	else {
		cout << x << ' ' << z;
	}


}


void solutie4() {

	citireAfisare();

}
