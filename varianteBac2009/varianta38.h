using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//4
/*Se consideră o matrice pătratică cu n linii şi n coloane (1≤n≤30), ce 
memorează numere întregi nenule de cel mult două cifre fiecare. 
Scrieţi un program C/C++ care citeşte de la tastatură valoarea n şi 
elementele matricei şi care afişează pe ecran, ultima cifră a produsului 
acelor elemente de pe diagonala secundară ce au proprietatea că sunt 
valori minime pe coloanele lor. Dacă nu există astfel de elemente în 
matrice, se va afişa mesajul NU EXISTA. */


void citireMatrice(int a[100][100], int& n) {

	ifstream f("matriceValoriMinime.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f >> a[i][j];
		}
	}

}


int valoareMinimaColoana(int a[100][100], int n, int coloana) {

	int minim = INT_MAX;

	for (int i = 0; i < n; i++) {
		if (a[i][coloana] < minim) {
			minim = a[i][coloana];
		}
	}

	return minim;

}


int prodMinDiagonalaSecundara(int a[100][100], int n) {

	int produs = 1;
	bool exista = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j == n - 1) {
				if (a[i][j] == valoareMinimaColoana(a, n, j)) {
					produs *= a[i][j];
					exista = true;
				}
			}
		}
	}

	if (exista) {
		return produs % 10;
	}
	else {
		return -1;
	}
}


void sol4() {

	int a[100][100], n;

	citireMatrice(a, n);

	if (prodMinDiagonalaSecundara(a, n) != -1) {
		cout << prodMinDiagonalaSecundara(a, n);
	}
	else {
		cout << "NU EXISTA";
	}

}



//SUBIECTUL 3



//3
/*Scrieţi în limbajul C/C++ definiţia completă a subprogramul Del care are doi parametri: x, 
un număr întreg de cel mult 9 cifre, şi y, un număr natural nenul de o cifră. Subprogramul 
determină eliminarea tuturor cifrelor lui x mai mari strict decât y şi furnizează numărul 
obţinut tot prin intermediul parametrului x. Dacă toate cifrele lui x sunt mai mari strict decât 
y, atunci x va primi valoarea -1*/


void Del(int& x, int y) {

	int copie = 0, p = 1;

	while (x) {
		if (x % 10 <= y) {
			copie = copie + (x % 10) * p;
			p *= 10;
		}
		x /= 10;
	}

	if (copie != 0) {
		x = copie;
	}
	else {
		x = -1;
	}
}


void solutie3() {

	int x, y;

	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;

	Del(x, y);

	cout << x;

}



//4
/*Se consideră subprogramul inter, cu doi parametri: x şi y (numere întregi formate din cel 
mult patru cifre fiecare); subprogramul interschimbă valorile a două variabile transmise prin 
intermediul parametrilor x şi y. 
a) Scrieţi în limbajul C/C++ definiţia completă a subprogramului inter. (4p.)
b) Pe prima linie a fişierului bac.in se află un număr natural nenul n≤1000, iar pe a doua 
linie a fişierului se află un şir de n numere naturale nenule, despărţite prin câte un spaţiu, 
fiecare număr fiind format din cel mult 4 cifre. Scrieţi un program C/C++ care afişează pe 
ecran, în ordine crescătoare, numerele aflate pe a doua linie a fişierului. Numerele vor fi 
afişate pe o singură linie, iar între două numere se va lăsa un spaţiu. Se vor folosi apeluri 
utile ale subprogramului inter.*/


void inter(int& x, int& y) {

	int aux = x;
	x = y;
	y = aux;

}


void citireVector(int v[], int& n) {

	ifstream f("vector.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


void ordonareVector(int v[], int n) {

	bool flag;

	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (v[i] > v[i + 1]) {
				inter(v[i], v[i + 1]);
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

	ordonareVector(v, n);

	afisareVector(v, n);

}