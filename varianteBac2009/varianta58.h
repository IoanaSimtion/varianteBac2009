using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Fişierul text BAC.TXT conţine, pe o singură linie, cel puţin 3 şi cel mult 100 de numere 
naturale nenule distincte de cel mult 4 cifre fiecare, numerele fiind separate prin câte un 
spaţiu. Scrieţi un program C/C++ care citeşte toate numerele din fişierul BAC.TXT şi scrie 
pe ecran, în ordine descrescătoare, cele mai mici 3 numere citite.*/


void citireNumere(int v[]) {

	ifstream f("minime3.txt");

	int nr;

	while (!f.eof()) {
		f >> nr;
		if (nr < v[2]) {
			v[0] = v[1];
			v[1] = v[2];
			v[2] = nr;
		}
		else {
			if (nr < v[1]) {
				v[0] = v[1];
				v[1] = nr;
			}
			else {
				if (nr < v[0]) {
					v[0] = nr;
				}
			}
		}
	}

}


void afisareMinime3(int v[]) {

	for (int i = 0; i < 3; i++) {
		cout << v[i] << ' ';
	}

}


void solutie3() {

	int v[3]={1000,1000,1000};

	citireNumere(v);

	afisareMinime3(v);

}



//4
/*Se consideră subprogramul divizor, care: 
– primeşte prin intermediul parametrului a un număr natural strict mai mare decât 1, de cel 
mult 4 cifre; 
– furnizează prin intermediul parametrului d cel mai mare divizor al lui a strict mai mic decât 
a. 
a) Scrieţi numai antetul subprogramului divizor. (4p.)
b) Scrieţi declarările de date şi programul principal C/C++ care citeşte de la tastatură un 
număr natural nenul x, de cel mult 4 cifre şi, prin apeluri utile ale subprogramului divizor,
verifică dacă x este număr prim. Programul va afişa pe ecran în caz afirmativ mesajul DA, iar 
în caz contrar mesajul NU.*/


void divizor(int a, int& d) {

	for (d = a - 1; d > 0; d--) {
		if (a % d == 0) {
			break;
		}
	}

}


bool ePrim(int x) {

	int d;

	divizor(x, d);

	if (d == 1) {
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