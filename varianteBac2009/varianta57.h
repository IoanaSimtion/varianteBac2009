using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură trei numere naturale n, a şi b
(2<n<25, 0<a<n, 0<b<n) şi construieşte în memorie o matrice cu n linii şi n coloane
numerotate de la 1 la n, formată numai din valori 0,1,2,3 şi 4 astfel încât: elementele 
aflate pe linia a sau coloana b sunt egale cu 0, cele aflate deasupra liniei a şi la stânga 
coloanei b sunt egale cu 1, cele aflate deasupra liniei a şi la dreapta coloanei b sunt egale
cu 2, cele aflate sub linia a şi la stânga coloanei b sunt egale cu 3, iar elementele aflate 
sub linia a şi la dreapta coloanei b sunt egale cu 4 ca în exemplul de mai jos. 
Programul afişează pe ecran matricea construită, fiecare linie a 
matricei pe o linie a ecranului şi elementele de pe aceeaşi linie 
separate prin câte un singur spaţiu. */


void generareMatrice(int m[100][100], int n, int a, int b) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < a - 1) {
				if (j < b - 1) {
					m[i][j] = 1;
				}
				else {
					if (j == b - 1) {
						m[i][j] = 0;
					}
					else {
						m[i][j] = 2;
					}
				}
			}
			else {
				if (i == a - 1) {
					m[i][j] = 0;
				}
				else {
					if (j < b - 1) {
						m[i][j] = 3;
					}
					else {
						if (j == b - 1) {
							m[i][j] = 0;
						}
						else {
							m[i][j] = 4;
						}
					}
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

	int m[100][100], n, a, b;

	cout << "n=";
	cin >> n;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;

	generareMatrice(m, n, a, b);

	afisareMatrice(m, n);

}



//SUBIECTUL 3



//3
/*Fişierul text INTRARE.TXT conţine, pe o singură linie, cel mult 100 de numere naturale 
nenule de cel mult patru cifre fiecare, numerele fiind separate prin câte un spaţiu. Scrieţi un 
program C/C++ care citeşte numerele din fişier şi scrie în fişierul text IESIRE.TXT, în 
ordine crescătoare, toate valorile distincte obţinute ca sumă de două elemente distincte 
aflate pe linia a doua a fişierului.*/


void citireNumere(int v[], int& n) {

	ifstream f("numereSuma.txt");

	n = 0;

	while (!f.eof()) {
		f >> v[n];
		n++;
	}

}


void vectorSuma(int v[], int n, int s[], int& m) {

	m = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				s[m] = v[i] + v[j];
				m++;
			}
		}
	}

}


void ordonareVector(int v[], int n) {

	bool flag;

	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (v[i] > v[i + 1]) {
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				flag = false;
			}
		}
	} while (flag == false);

}


void afisareSume(int s[], int m) {

	for (int i = 0; i < m; i++) {
		if (s[i] != s[i + 1]) {
			cout << s[i] << ' ';
		}
	}

}


void solutie3() {

	int v[100], s[200], n, m;

	citireNumere(v, n);

	vectorSuma(v, n, s, m);

	ordonareVector(s, m);

	afisareSume(s, m);

}



//4
/*Se consideră subprogramul multiplu, cu doi parametri, care: 
– primeşte prin intermediul parametrilor a şi k două numere întregi de cel mult 4 cifre; 
– returnează cel mai mic multiplu al lui k mai mare sau egal cu a. 
a) Scrieţi numai antetul subprogramului multiplu. (4p.)
b) Scrieţi declarările de date şi programul principal C/C++ care citeşte de la tastatură trei 
numere naturale nenule x, y, z, de cel mult 4 cifre fiecare, (x≤y), şi care, prin apeluri utile 
ale subprogramului multiplu, verifică dacă intervalul [x,y] conţine cel puţin un multiplu 
al lui z. Programul va afişa pe ecran, în caz afirmativ, mesajul DA, iar în caz contrar 
mesajul NU.*/


int multiplu(int a, int k) {

	int i = 2;

	while (k * i <= a) {
		i++;
	}

	return k * (i - 1);

}


bool multipluInterval(int x, int y, int z) {

	if (multiplu(y, z) < x) {
		return false;
	}
	return true;

}


void solutie4() {

	int x, y, z;

	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	cout << "z=";
	cin >> z;

	if (multipluInterval(x, y, z) == true) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}


}