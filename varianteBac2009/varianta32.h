using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Scrieţi definiţia completă a subprogramului nr_prim care are ca parametru un număr 
natural x şi returnează cel mai mic număr prim, strict mai mare decât x.*/


int nr_prim(int x) {

	for (int nr = x + 1; ; nr++) {
		bool prim = true;
		for (int d = 2; d <= nr / 2 && prim == true; d++) {
			if (nr % d == 0) {
				prim = false;
			}
		}
		if (prim == true) {
			return nr;
		}
	}

}


void solutie3() {

	int x;

	cout << "x=";
	cin >> x;

	cout << nr_prim(x);

}



//4
/*În fişierul numere.txt sunt memorate pe mai multe linii, numere întregi (cel mult 100), 
numerele de pe aceeaşi linie fiind despărţite prin câte un spaţiu, fiecare număr având cel 
mult 9 cifre. Să se determine cele mai mici două valori având exact două cifre fiecare, 
memorate în fişier şi să se afişeze pe ecran aceste valori, despărţite printr-un spaţiu. Dacă
în fişier nu se află două astfel de valori, pe ecran se va afişa valoarea 0. 
a) Descrieţi în limbaj natural o metodă de rezolvare eficientă din punct de vedere al 
gestionării memoriei şi al timpului de executare. (4p.)
b) Scrieţi programul C/C++ corespunzător metodei descrise la punctul a. */


void citireAfisareNr() {

	ifstream f("numere100.txt");
	int min1 = 100, min2 = 100, n;

	while (f >> n) {
		if ((n <= 99 && n >= 10) || (n >= -99 && n <= -10)) {
			if (n < min2) {
				min1 = min2;
				min2 = n;
			}
			else {
				if (n < min1) {
					min1 = n;
				}
			}
		}
	}

	if (min2 == -100) {
		cout << 0;
	}
	else {
		cout << min2 << ' ' << min1;
	}

}


void solutie4() {

	citireAfisareNr();

}