using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C / C++ care citeşte de la tastatură un număr natural n(2<n<20),
construieşte în memorie şi afişează pe ecran o matrice cu n linii şi n coloane, numerotate
de la 1 la n, în care fiecare element aflat pe o linie impară este egal cu suma dintre indicii
liniei şi coloanei pe care se află şi fiecare element aflat pe o linie pară este egal cu cel mai
mic dintre elementele aflate pe linia anterioară şi pe aceeaşi coloană cu el sau pe linia
anterioară şi pe una dintre coloanele vecine cu cea pe care se află el.
5.
Elementele matricei vor fi afişate pe ecran, câte o linie a matricei pe
câte o linie a ecranului cu câte un spaţiu între elementele fiecărei linii.*/


void generareMatrice(int a[100][100], int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i % 2 == 1) {
				a[i][j] = i + j;
			}
			else {
				if (j == 1) {
					a[i][j] = a[i - 1][j];
				}
				else {
					a[i][j] = a[i - 1][j - 1];
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

	int a[100][100], n = 5;

	generareMatrice(a, n);

	afisareMatrice(a, n);

}



//SUBIECTULL 3



//3
/*Subprogramul aranjare are doi parametri : a prin care primeşte un tablou unidimensional
cu maximum 100 de numere reale nenule şi n, numărul de elemente din tablou.
Subprogramul rearanjează elementele tabloului unidimensional astfel încât toate valorile 
negative să se afle pe primele poziţii, iar valorile pozitive în continuarea celor negative. 
Ordinea în cadrul secvenţei de elemente pozitive, respectiv în cadrul secvenţei de elemente 
negative, poate fi oricare. Tabloul modificat va fi furnizat tot prin intermediul parametrului a.*/


void citireVector(float a[], int& n) {

	ifstream f("separareNumere.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> a[i];
	}

}


void aranjare(float a[], int n) {

	int i = 0, j = n - 1;

	while (i < j) {

		if (a[i] < 0 && a[j] >= 0) {
			int aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			i++;
			j--;
		}
		else {
			i++;
		}
	}

}


void afisareVector(float a[], int n) {

	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}

}


void solutie3() {

	float a[100];
	int n;

	citireVector(a, n);

	aranjare(a, n);

	afisareVector(a, n);

}



//4
/*În fişierul nr1.txt este memorată pe prima linie o valoare naturală n de cel mult 8 cifre, 
iar pe linia următoare sunt memorate n numere naturale, cu maximum 4 cifre fiecare, 
ordonate strict crescător şi separate prin câte un spaţiu. În fişierul nr2.txt este memorată
pe prima linie o valoare naturală m de cel mult 8 cifre, iar pe linia următoare sunt memorate 
m numere naturale, cu maximum 4 cifre fiecare, ordonate strict crescător şi separate prin 
câte un spaţiu. Se cere afişarea pe ecran, separate prin câte un spaţiu, în ordine strict
crescătoare, a tuturor numerelor aflate pe a doua linie în cel puţin unul dintre cele două
fişiere. În cazul în care un număr apare în ambele fişiere, el va fi afişat o singură dată. 
Alegeţi un algoritm de rezolvare eficient din punct de vedere al memoriei utilizate şi al 
timpului de executare*/


void afisareInterclasata() {

	ifstream f1("nr1.txt");
	ifstream f2("nr02.txt");

	int n, m, a, b, i = 0, j = 0;

	f1 >> n;
	f2 >> m;

	f1 >> a;
	f2 >> b;

	while (i < n && j < m) {
		if (a < b) {
			cout << a << ' ';
			f1 >> a;
			i++;
		}
		else {
			if (b < a) {
				cout << b << ' ';
				f2 >> b;
				j++;
			}
			else {
				cout << a << ' ';
				f1 >> a;
				f2 >> b;
				i++;
				j++;
			}
		}
	}

	while (i < n) {
		cout << a << ' ';
		f1 >> a;
		i++;
	}

	while (j < m) {
		cout << b << ' ';
		f2 >> b;
		j++;
	}



}


void solutie4() {

	afisareInterclasata();

}
