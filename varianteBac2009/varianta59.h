using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Fişierul text bac.txt conţine, pe o singură linie, cel puţin 3 şi cel mult 100 de numere 
naturale nenule distincte de cel mult 4 cifre fiecare, numerele fiind separate prin câte un 
spaţiu. Scrieţi un program C/C++ care citeşte numerele din fişier şi scrie pe ecran ultima 
cifră a produsului celor mai mari 3 numere citite*/


void citireNumere(int v[]) {

	ifstream f("maxime3.txt");

	int nr;

	while (!f.eof()) {
		f >> nr;
		if (nr > v[2]) {
			v[0] = v[1];
			v[1] = v[2];
			v[2] = nr;
		}
		else {
			if (nr > v[1]) {
				v[0] = v[1];
				v[1] = nr;
			}
			else {
				if (nr > v[0]) {
					v[0] = nr;
				}
			}
		}
	}

}


void solutie3() {

	int v[3]{};

	citireNumere(v);

	cout << (v[0] * v[1] * v[2]) % 10;

}



//4
/*Se consideră subprogramul divizor, care: 
– primeşte prin intermediul parametrului, a, un număr natural nenul de cel mult 4 cifre, 
strict mai mare ca 1; 
– furnizează prin intermediul parametrului d, cel mai mic divizor al lui a strict mai mare 
decât 1. 
a) Scrieţi numai antetul subprogramului divizor. (4p.)
b) Scrieţi declarările de date şi programul principal C/C++ care citeşte de la tastatură un 
număr natural x (x>1), şi, prin apeluri utile ale subprogramului divizor, verifică dacă x
este număr prim. Programul va afişa pe ecran, în caz afirmativ, mesajul DA, iar în caz 
contrar mesajul NU*/


void divizor(int a, int& d) {

	for (d = a - 1; d > 1; d--) {
		if (a % d == 0) {
			break;
		}
	}

	if (d == 1) {
		d = a;
	}

}


bool ePrim(int x) {

	int d;

	divizor(x, d);

	if (d == x) {
		return true;
	}
	return false;

}


void solutie4() {

	int x;

	cout << "x=";
	cin >> x;

	if (ePrim(x) == true) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

}