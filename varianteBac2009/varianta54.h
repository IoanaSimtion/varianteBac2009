using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural par, n (4≤n≤10), şi 
un număr natural x, cu exact 3 cifre, şi care construieşte în memorie un tablou 
bidimensional cu n linii şi n coloane, ce are elementele de pe diagonala principală egale cu 
prima cifră a numărului x, elementele de pe diagonala secundară egale cu ultima cifră a 
numărului x, iar restul elementelor egale cu cifra din mijloc a numărului x. 
5. 
Tabloul bidimensional se va afişa pe ecran, câte o linie a tabloului pe câte o 
linie a ecranului, elementele fiecărei linii fiind separate prin câte un spaţiu*/


void generareMatrice(int c1, int c2, int c3, int a[100][100], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				a[i][j] = c3;
			}
			else {
				if (i + j == n - 1) {
					a[i][j] = c1;
				}
				else {
					a[i][j] = c2;
				}
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

	int a[100][100], n, x;

	cout << "n=";
	cin >> n;
	cout << "x=";
	cin >> x;

	generareMatrice(x % 10, (x / 10) % 10, (x / 100) % 10, a, n);

	afisareMatrice(a, n);

}



//SUBIECTUL 3



//3
/*Se consideră subprogramul inv, care primeşte prin intermediul primului parametru a un 
număr natural, cu minimum două cifre şi maximum 8 cifre, şi furnizează prin intermediul 
celui de-al doilea parametru, b, valoarea numărului natural format cu aceleaşi cifre ca şi a, 
considerate în ordine inversă. De exemplu, pentru a=3805, după apel b va avea valoarea 
5083., iar dacă a=3800, după apel b va avea valoarea 83. 
a) Scrieţi definitia completă a subprogramului inv. (4p.)
b) Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n de minimum 
două şi maximum 8 cifre şi afişează pe ecran un număr palindrom cu valoarea cea mai 
apropiată de valoarea lui n citită. În cazul în care există două astfel de numere, se va afişa 
cel mai mic dintre ele. Se vor folosi apeluri utile ale subprogramului inv. 
Spunem că un număr natural x este palindrom dacă numărul format din cifrele lui x
considerate de la stânga către dreapta este acelaşi cu numărul format din cifrele lui x
considerate de la dreapta către stânga. */


void inv(int a, int& b) {

	b = 0;

	while (a) {
		b = b * 10 + a % 10;
		a /= 10;
	}

}


int palindromApropiat(int n) {

	int dist1 = 0, dist2 = 0, pal1, pal2;

	int invers;
	inv(n, invers);
	if (n == invers) {
		return n;
	}

	for (int i = n; i >= 11 && dist1 == 0; i--) {
		int invers;
		inv(i, invers);
		if (i == invers) {
			dist1 = n - i;
			pal1 = i;
		}
	}

	int i = n + 1;
	while (dist2 == 0) {
		int invers;
		inv(i, invers);
		if (i == invers) {
			dist2 = i - n;
			pal2 = i;
		}
		i++;
	}

	if (dist1 < dist2) {
		return pal1;
	}
	else {
		return pal2;
	}

}


void solutie3() {

	int n;

	cout << "n=";
	cin >> n;

	cout << palindromApropiat(n);

}



//4
/*Fişierul text date.in conţine pe prima linie un număr natural nenul n (n≤100), iar pe a 
doua linie un şir de n numere naturale nenule distincte, separate prin câte un spaţiu, 
fiecare număr având maximum 8 cifre. 
a) Scrieţi un program C/C++ care citeşte numerele din fişier şi determină câte dintre 
comopnentele şirului citit pot fi scrise ca sumă a altor două numere din acelaşi şir. 
Rezultatul obţinut se va afişa pe ecran. În cazul în care nu există niciun astfel de element, 
se va afişa valoarea 0.*/


void citireVector(int v[], int& n) {

	ifstream f("suma.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


int contorNumere(int v[], int n) {

	int ct = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (v[j] + v[k] == v[i]) {
					ct++;
				}
			}
		}
	}

	return ct;

}


void solutie4() {

	int v[100], n;

	citireVector(v, n);

	cout << contorNumere(v, n);

}