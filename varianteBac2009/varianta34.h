using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi programul C/C++ care citeşte de la tastatură un număr natural n (n≤20), 
construieşte în memorie şi afişează pe ecran, matricea cu n linii şi n coloane, în care se vor 
memora în ordinea crescătoare a valorii, pe linii şi coloane, primele n2
 numere naturale 
nenule, pare, care nu sunt divizibile cu 3. 
Fiecare linie a matricei se va afişa pe câte o linie a ecranului, cu 
elementele de pe aceeaşi linie separate prin câte un spaţiu.*/


void generareMatrice(int a[100][100], int n) {

	int nr = 2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nr % 3 != 0) {
				a[i][j] = nr;
			}
			else {
				while (nr % 3 == 0) {
					nr += 2;
				}
				a[i][j] = nr;
			}
			nr += 2;
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

	int a[100][100], n;

	cout << "n=";
	cin >> n;

	generareMatrice(a, n);

	afisareMatrice(a, n);

}



//SUBIECTUL 3


//3
/*a) Subprogramul max primeşte ca parametru un tablou unidimensional x cu cel mult 100 de 
elemente numere întregi, care sunt, în ordine, termenii unei progresii aritmetice şi un număr 
natural n, care reprezintă dimensiunea tabloului. Scrieţi definiţia completă a subprogramului 
max care returnează cel mai mare termen al progresiei aritmetice. Alegeţi un algoritm de 
rezolvare eficient din punct de vedere al timpului de executare. (6p.)
b) Explicaţi în limbaj natural metoda utilizată justificând eficienţa acesteia. (4p.) 
c) Pe prima linie a fişierului numere.txt se află un număr natural n (n≤100), iar pe 
următoarele n linii, câte n numere întregi cu cel mult 4 cifre fiecare. Scrieţi programul C/C++
care citeşte din fişier datele existente, determină liniile din fişier pe care s-au memorat în 
ordine termenii unei progresii aritmetice şi afişează pe ecran, folosind apeluri ale 
subprogramului max cel mai mare număr (diferit de cel situat pe prima linie) din fişier, care în 
plus este termenul unei progresii aritmetice. */


void citireVector(int x[], int& n) {

	ifstream f("progresie.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> x[i];
	}

}


int max(int x[100], int n) {

	if (x[0] - x[1] < 0) {
		return x[n - 1];
	}
	else {
		return x[0];
	}

}


bool eProgresieAritmetica(int x[], int n) {

	int dif = x[0] - x[1];

	for (int i = 1; i < n - 1; i++) {
		if (x[i] - x[i + 1] != dif) {
			return false;
		}
	}

	return true;

}


int maximTermeni() {
	
	ifstream f("progresiiAritmetice.txt");

	int x[100], n, maxim = INT_MIN;

	f >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f >> x[j];
		}
		if (eProgresieAritmetica(x, n)) {
			if (max(x, n) > maxim) {
				maxim = max(x, n);
			}
		}
	}

	return maxim;

}


void solutie3() {

	/*int x[100], n;

	citireVector(x, n);

	cout << max(x, n);*/

	cout << maximTermeni();

}