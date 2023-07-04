using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*a) Pe prima linie a fişierului bac.in se află un număr natural nenul n (n≤1000), iar pe a 
doua linie a fişierului se află un şir format din n numere naturale, despărţite prin câte un 
spaţiu, fiecare număr fiind format din cel mult 4 cifre. Scrieţi un program C/C++ care 
citeşte numerele din fişier şi care afişează pe ecran mesajul DA dacă elementele pare în şir 
sunt în ordine crescătoare, iar cele impare sunt în ordine descrescătoare şi mesajul NU în 
caz contrar. Alegeţi un algoritm eficient ca timp de executare şi spaţiu de memorie utilizat.*/


bool ordineCrescatoareDescrescatoare() {

	ifstream f("sirNumereOrd.txt");

	int n, a, b = INT_MIN, c = INT_MAX;

	f >> n;
	f >> a;

	if (a % 2 == 0) {
		b = a;
	}
	else {
		c = a;
	}

	while (!f.eof()) {
		f >> a;
		if (a % 2 == 0) {
			if (a < b) {
				return false;
			}
			b = a;
		}
		else {
			if (a > c) {
				return false;
			}
			c = a;
		}
	}

	return true;

}


void solutie3() {

	if (ordineCrescatoareDescrescatoare() == true) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

}



//4
/*a) Scrieţi definiţia completă a subprogramului sdiv care primeşte prin intermediul 
parametrului y un număr natural cu cel mult 6 cifre şi returnează suma tuturor divizorilor 
numărului y. (5p.)
b) Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (n<10000) şi 
care, folosind apeluri ale subprogramului sdiv verifică dacă suma divizorilor lui n este un 
număr prim. În caz afirmativ, programul va afişa pe ecran mesajul Da şi în caz contrar va 
afişa mesajul NU.*/


int sdiv(int y) {

	int suma = 0;

	for (int d = 2; d < sqrt(y); d++) {
		if (y % d == 0) {
			suma += d + y / d;
		}
	}

	return suma;

}


bool prim(int nr) {

	if (sdiv(sdiv(nr)) == sdiv(nr) + 1) {
		return true;
	}
	return false;

}


void solutie4() {

	int n;

	cout << "n=";
	cin >> n;

	if (prim(n) == true) {
		cout << "Da";
	}
	else {
		cout << "NU";
	}

}