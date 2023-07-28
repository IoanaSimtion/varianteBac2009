using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Fişierul text bac.txt conţine, pe prima sa linie, 100 de numere naturale de cel mult 4 cifre 
fiecare, numerele fiind ordonate crescător şi separate prin câte un spaţiu, iar pe a doua 
linie un singur număr natural x. Scrieţi un program C/C++ care citeşte toate numerele din 
fişier şi verifică dacă x se află în şirul celor 100 de numere aflate pe prima linie a fişierului. 
În caz afirmativ, se va afişa pe ecran mesajul DA, altfel se va afişa mesajul NU.*/


void citireNumere(int v[], int& n, int& x) {

	ifstream f("numereCautareBinara.txt");

	n = 0;

	while (!f.eof()) {
		f >> v[n];
		n++;
	}

	x = v[n - 1];
	n--;

}


bool cautareBinara(int v[], int n, int x) {

	int st = 0, dr = n - 1;

	while (st <= dr) {
		
		int mijloc = (st + dr) / 2;
		if (v[mijloc] == x) {
			return true;
		}
		else {
			if (v[mijloc] > x) {
				st = mijloc - 1;
			}
			else {
				dr = mijloc + 1;
			}
		}
	}

	return false;

}


void solutie3() {

	int v[100], n, x;

	citireNumere(v, n, x);

	cout << n << endl;

	if (cautareBinara(v, n, x) == true) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

}



//4
/*Se consideră subprogramul radical, care: 
– primeşte prin intermediul parametrului a, un număr natural nenul de cel mult 4 cifre; 
– furnizează prin intermediul parametrului x cel mai mare număr natural cu proprietatea 
că x2 este mai mic sau egal cu a; de exemplu, dacă a=20, subprogramul va furniza prin 
x valoarea 4. 
a) Scrieţi numai antetul subprogramului radical. (4p.)
b) Scrieţi declarările de date şi programul principal C/C++ care citeşte de la tastatură un 
număr natural nenul de cel mult 4 cifre, n, şi prin apeluri utile ale subprogramului radical, 
verifică dacă n este pătrat perfect. Programul va afişa pe ecran în caz afirmativ mesajul DA, 
iar în caz contrar mesajul NU. */


void radical(int a, int& x) {

	for (x = 1; x * x <= a; x++) {
		x++;
	}

	x--;

}


bool ePatratPerfect(int n) {

	int x;

	radical(n, x);

	if (x * x == n) {
		return true;
	}

	return false;

}


void solutie4() {

	int n;

	cout << "n=";
	cin >> n;

	if (ePatratPerfect(n) == true) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

}