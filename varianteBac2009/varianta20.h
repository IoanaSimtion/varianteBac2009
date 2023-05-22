using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (2<n<20) şi 
construieşte în memorie o matrice cu n linii şi n coloane, numerotate de la 1 la n, în care 
fiecare element aflat pe chenarul exterior al matricei este egal cu suma dintre indicele liniei 
şi indicele coloanei pe care se află, iar fiecare dintre celelalte elemente este egal cu suma 
celor trei “vecini” situaţi în matrice pe linia anterioară. Două elemente din matrice se numesc 
vecine dacă se găsesc alături pe linie, coloană sau diagonală. Chenarul exterior al unei 
matrice este format din prima linie, ultima linie, prima coloană şi ultima coloană. 
5. 
Elementele matricei vor fi afişate pe ecran, câte o linie a matricei 
pe câte o linie a ecranului cu câte un spaţiu între elementele 
fiecărei linii.*/


void generareMatrice(int a[100][100], int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 || j == 1 || i == n || j == n) {
				a[i][j] = i + j;
			}
			else {
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1] + a[i - 1][j + 1];
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



//SUBIECTUL 3



//3
/*Subprogramul nule are doi parametri: a, prin care primeşte un tablou unidimensional cu 
maximum 100 de numere întregi, cu cel mult 4 cifre fiecare şi n, numărul de elemente din 
tablou. Subprogramul rearanjează elementele tabloului unidimensional astfel încât toate 
valorile nule să se afle la sfârşitul tabloului. Ordinea în cadrul secvenţei de elemente nenule 
poate fi oricare. Tabloul modificat este furnizat tot prin parametrul a*/


void citireVector(int a[], int& n) {

	ifstream f("vect.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> a[i];
	}

}


void nule(int a[], int n) {

	int i = 0, j = n - 1;

	while (i < j) {
		if (a[i] == 0 && a[j] != 0) {
			int aux = a[i];
			a[i] = a[j];
			a[j] = aux;
		}
		i++;
		j--;
	}

}


void afisareVector(int a[], int n) {

	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}

}


void solutie3() {

	int a[100], n;

	citireVector(a, n);

	nule(a, n);

	afisareVector(a, n);

}



//4
/*În fişierul nr1.txt este memorată pe prima linie o valoare naturală n de cel mult 8 cifre, 
iar pe linia următoare sunt memorate n numere naturale, cu maximum 4 cifre fiecare, 
ordonate strict crescător şi separate prin câte un spaţiu. În fişierul nr2.txt este memorată
pe prima linie o valoare naturală m de cel mult 8 cifre, iar pe linia următoare sunt memorate 
m numere naturale, cu maximum 4 cifre fiecare, ordonate strict crescător şi separate prin 
câte un spaţiu. Se cere afişarea pe ecran, separate prin câte un spaţiu, în ordine strict 
crescătoare, a tuturor numerelor aflate pe a doua linie atât în primul cât şi în al doilea fişier. 
Alegeţi un algoritm de rezolvare eficient din punct de vedere al memoriei utilizate şi al 
timpului de executare. */


void afisareNumere() {

	ifstream f1("numar1.txt");
	ifstream f2("numar2.txt");

	int a, b, n, m, i = 0, j = 0;

	f1 >> n;
	f2 >> m;

	f1 >> a;
	f2 >> b;

	while (i < n && j < m) {
		if (a < b) {
			f1 >> a;
			i++;
		}
		else {
			if (a > b) {
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



}


void solutie4() {

	afisareNumere();

}