using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2


//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (2<n<20),
construieşte în memorie şi afişează pe ecran o matrice cu n linii şi n coloane, în care 
fiecare element de pe diagonala secundară are valoarea n, fiecare element aflat deasupra 
diagonalei secundare este mai mic cu o unitate decât vecinul aflat pe aceeaşi linie în 
dreapta lui şi fiecare element aflat sub diagonala secundară este mai mare cu o unitate 
decât vecinul aflat pe aceeaşi linie în stânga lui. 
5. 
Elementele matricei vor fi afişate pe ecran, câte o linie a matricei pe 
câte o linie a ecranului cu câte un spaţiu între elementele fiecărei linii. */


void generareMatrice(int a[100][100], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j == n - 1) {
				a[i][j] = n;
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


void sol5() {

	int a[100][100], n = 5;

	generareMatrice(a, n);

	afisareMatrice(a, n);

}



//SUBIECTUL 3



//3
/*Scrieţi definiţia completă a subprogramului interval care are doi parametri a şi n, prin 
care primeşte un tablou unidimensional cu maximum 100 de numere naturale mai mici 
decât 1000 şi respectiv numărul efectiv de elemente din tabloul unidimensional. 
Subprogramul returnează numărul de elemente din tabloul unidimensional care aparţin 
intervalului închis determinat de primul şi respectiv ultimul element al tabloului.*/


void citireVector(int a[], int& n) {

	ifstream f("tablouInterval.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> a[i];
	}

}


void afisareVector(int a[], int n) {

	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}

}


int interval(int a[], int n) {

	int ct = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] >= a[0] && a[i] <= a[n - 1]) {
			ct++;
		}
		if (a[i] <= a[0] && a[i] >= a[n - 1]) {
			ct++;
		}
	}

	return ct;

}


void solutie3() {

	int a[100], n;

	citireVector(a, n);

	//afisareVector(a, n);

	cout << interval(a, n);

}



//4
/*În fişierul numere.txt pe prima linie este memorat un număr natural n (n≤10000), iar pe 
linia următoare un şir de n numere naturale distincte două câte două, separate prin câte un 
spaţiu, cu maximum 4 cifre fiecare. Se cere afişarea pe ecran a poziţiei pe care s-ar găsi 
primul element din şirul aflat pe linia a doua a fişierului, în cazul în care şirul ar fi ordonat 
crescător. Numerotarea poziţiilor elementelor în cadrul şirului este de la 1 la n. Alegeţi un 
algoritm de rezolvare eficient din punct de vedere al memoriei utilizate şi al timpului de 
executare. */


void citireVect(int v[], int& n) {
	
	ifstream f("vectorOrdonare.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


int pozPrimulElement(int v[], int n) {

	int ct = 1;

	for (int i = 2; i <= n; i++) {
		if (v[i] < v[0]) {
			ct++;
		}
	}

	return ct;

}


void solutie4() {

	int v[10000], n;

	citireVect(v, n);

	cout << pozPrimulElement(v, n);

}