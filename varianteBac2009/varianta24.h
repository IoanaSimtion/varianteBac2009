using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//4
/*Scrieţi o secvenţă de instrucţiuni C/C++ care să iniţializeze elementele unui tablou 
bidimensional A, cu n linii şi n coloane, 1<n≤100, cu numerele naturale 1,2,...,n, astfel 
încât pe fiecare linie sau coloană să existe toate numerele din mulţimea {1,2,...,n}. */


void initializareMatrice(int a[100][100], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j >= n) {
				a[i][j] = i + j - n + 1;
			}
			else {
				a[i][j] = i + j + 1;
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


void sol4() {

	int a[100][100], n;

	cout << "n=";
	cin >> n;

	initializareMatrice(a, n);

	afisareMatrice(a, n);

}



//SUBIECTUL 3



//3
/*a) Scrieţi definiţia completă a subprogramului p care primeşte prin intermediul parametrului 
n un număr natural nenul (n≤100), iar prin intermediul parametrului x un tablou 
unidimensional cu n componente întregi, de maximum patru cifre fiecare. Subprogramul 
furnizează prin intermediul parametrului mini valoarea minimă din tabloul x, prin 
intermediul parametrului maxi valoarea maximă din x, iar prin intermediul parametrului sum
suma elementelor din tabloul x. (6p.)
b) Scrieţi un program C/C++ care citeşte de la tastatură o valoare naturală nenulă n, 
(3≤n≤100), apoi cele n elemente distincte ale unui tablou unidimensional x. Fiecare dintre 
aceste elemente este un număr natural având cel mult patru cifre. Folosind apeluri utile ale 
subprogramului p, programul calculează şi afişează pe ecran media aritmetică a 
elementelor care ar rămâne în tabloul x dacă s-ar elimina valoarea minimă şi valoarea 
maximă din tablou. Valoarea afişată va avea cel mult 3 cifre după virgulă.*/


void citireVector(int x[], int& n) {

	ifstream f("medieAritm.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> x[i];
	}

}


void p(int n, int x[], int& mini, int& maxi, int& sum) {

	mini = INT_MAX;
	maxi = INT_MIN;
	sum = 0;

	for (int i = 0; i < n; i++) {
		if (x[i] < mini) {
			mini = x[i];
		}
		if (x[i] > maxi) {
			maxi = x[i];
		}
		sum += x[i];
	}

}


void solutie3() {

	int x[100], n, max, min, s;

	citireVector(x, n);

	p(n, x, min, max, s);

	cout << ("%.3f", ((float)(s - min - max)) / (n - 2));

}



//4
/*Fişierul text bac.txt conţine pe prima linie numărul natural n, 1≤n≤30000, pe următoarele 
n linii un şir de n numere întregi, ordonate crescător, iar pe ultima linie două numere întregi 
a şi b (a≤b) separate de un spaţiu. Fiecare dintre cele n numere, precum şi valorile a şi b, 
au cel mult patru cifre. 
a) Scrieţi un program C/C++, eficient din punct de vedere al timpului de executare, care 
afişează pe ecran cel mai mic număr întreg din intervalul închis [a,b] care se găseşte în 
şirul dat. Dacă nu există un astfel de număr, programul afişează textul NU*/


void citire(int v[], int& n, int& a, int& b) {

	ifstream f("interval.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

	f >> a >> b;

}


void cautare(int v[], int n, int a, int b) {

	int st = 0, dr = n - 1;
	bool gasit = 0;

	while (st <= dr && !gasit) {

		int mij = (st + dr) / 2;

		if (v[mij] < a) {
			st = mij + 1;
		}
		else {
			if (v[mij] > b) {
				dr = mij - 1;
			}
			else {
				cout << v[mij];
				gasit = 1;
			}
		}

	}

}


void solutie4() {

	int v[100], n, a, b;

	citire(v, n, a, b);

	cautare(v, n, a, b);

}