using namespace std;
#include <iostream>
#include <fstream>
#pragma once

//SUBIECTUL 2

//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (2<n<16),
construieşte în memorie şi afişează pe ecran o matrice cu n linii şi n coloane în care 
elementele de pe cele două diagonale sunt egale cu 0, elementele care se află deasupra 
ambelor diagonale sunt egale cu 1, elementele care se află sub ambele diagonale sunt 
egale cu 2, iar restul elementelor sunt egale cu 3. 
5. 
Elementele matricei vor fi afişate pe ecran, câte o linie a matricei pe 
câte o linie a ecranului cu câte un spaţiu între elementele fiecărei linii.*/

void generareMatrice(int a[100][100], int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || i + j == n + 1) {
				a[i][j] = 0;
			}
			else {
				if (i < j && i + j < n + 1) {
					a[i][j] = 1;
				}
				else {
					if (i + j > n + 1 && i > j) {
						a[i][j] = 2;
					}
					else {
						a[i][j] = 3;
					}
				}
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

	int a[100][100], n;

	cout << "n=";
	cin >> n;

	generareMatrice(a, n);

	afisareMatrice(a, n);
}



//SUBIECTUL 3



//3
/*Scrieţi definiţia completă a subprogramului multiplu care are 3 parametri: a, prin care 
primeşte un tablou unidimensional cu maximum 100 de numere naturale mai mici decât 
1000, n, numărul efectiv de elemente ale tabloului şi k, un număr natural (k≤9). 
Subprogramul returnează numărul de elemente din tablou care sunt multipli ai numărului k
şi au ultima cifră egală cu k*/


int multiplu(int a[1000], int n, int k) {

	int ct = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] % k == 0 && a[i] % 10 == k) {
			ct++;
		}
	}

	return ct;

}


void citireFisier(int a[], int& n, int& k) {

	ifstream f("tablou.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> a[i];
	}

	f >> k;

}


void solutie3() {

	int a[1000], k, n;

	citireFisier(a, n, k);

	cout << multiplu(a, n, k);

}



//4
/*În fişierul numere.txt sunt memorate maximum 10000 de numere naturale cu cel mult 9
cifre fiecare. Fiecare linie a fişierului conţine câte un număr. Se cere afişarea pe ecran, în 
ordine descrescătoare, a tuturor cifrelor care apar în numerele din fişier. Alegeţi un algoritm 
de rezolvare eficient din punct de vedere al timpului de executare. 
Exemplu: dacă fişierul numere.txt conţine:
267 
39628 
79 
se va tipări 9987766322.*/


void citireFrecventa(int fr[]) {

	ifstream f("numereFr.txt");

	while (!f.eof()) {
		int x;
		f >> x;
		while (x) {
			fr[x % 10]++;
			x /= 10;
		}
	}

}


void afisareFr(int fr[]) {

	for (int i = 9; i >= 0; i--) {
		while (fr[i]) {
			cout << i;
			fr[i]--;
		}
	}

}


void solutie4() {

	int fr[10]{};

	citireFrecventa(fr);

	afisareFr(fr);

}