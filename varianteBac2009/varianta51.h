using namespace std;
#include <iostream>
#include <fstream>
#pragma once




//SUBIECTUL 3



//3
/*Se consideră subprogramul dist2, care primeşte prin intermediul parametrilor xa, ya şi 
respectiv xb, yb, coordonatele carteziene întregi (abscisă, ordonată) pentru două puncte 
din plan, A şi respectiv B. Subprogramul returnează pătratul distanţei dintre cele două
puncte. 
a) Scrieţi în limbajul C/C++ definiţia completă a subprogramului dist2. (4p.)
b) Scrieţi un program C/C++ care citeşte de la tastatură 8 valori întregi reprezentând 
coordonatele carteziene pentru patru puncte din plan şi afişează mesajul Da dacă cele 
patru puncte pot fi vârfurile unui pătrat, iar în caz contrar afişează mesajul Nu,folosind 
apeluri utile ale subprogramului dist2.*/


int dist2(int xa, int ya, int xb, int yb) {
	
	return pow((xa - xb), 2) * pow((ya - yb), 2);

}


struct Punct {
	int x, y;
};


void citireCoordonate(Punct v[]) {

	ifstream f("coordonatePatrat.txt");

	for (int i = 0; i < 4; i++) {
		f >> v[i].x >> v[i].y;
	}

}


bool ePatrat(Punct v[]) {

	int minDistanta = 0, lungimeLatura = -1;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i != j) {
				
				if (minDistanta == 0) {
					minDistanta = dist2(v[i].x, v[i].y, v[j].x, v[j].y);
				}
				else {
					if (minDistanta > dist2(v[i].x, v[i].y, v[j].x, v[j].y)) {
						minDistanta = dist2(v[i].x, v[i].y, v[j].x, v[j].y);
					}
				}
			}
		}
		if (lungimeLatura == -1) {
			if (minDistanta != 0) {
				lungimeLatura = minDistanta;
			}
		}
		else {
			if (lungimeLatura != minDistanta) {
				return false;
			}
		}
	}

	return true;

}


void solutie3() {

	Punct v[100];

	citireCoordonate(v);

	if (ePatrat(v)) {
		cout << "Da";
	}
	else {
		cout << "Nu";
	}

}



//4
/*Fişierul text date.in conţine pe prima linie un număr natural nenul n (n≤100), iar pe a 
doua linie n numere naturale nenule, separate prin câte un spaţiu, fiecare număr având 
maximum 4 cifre. Scrieţi un program C/C++ care citeşte toate numerele din fişierul text 
date.in, construieşte în memorie un tablou unidimensional a, cu cele n elemente din fişier 
şi afişează pe ecran perechile (ai, aj) , 1≤i<j≤n, cu proprietatea că elementele fiecăreia 
dintre aceste perechi au aceeaşi paritate. Fiecare pereche se va afişa pe câte o linie a 
ecranului, elementele perechii fiind separate prin câte un spaţiu. În cazul în care nu există
nicio pereche, se va afişa valoarea 0.*/


void citireVector(int v[], int& n) {

	ifstream f("vectorPerechi.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


void afisarePerechi(int v[], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] % 2 == 0 && v[j] % 2 == 0) {
				cout << v[i] << ' ' << v[j] << endl;
			}
			else {
				if (v[i] % 2 == 1 && v[j] % 2 == 1) {
					cout << v[i] << ' ' << v[j] << endl;
				}
			}
		}
	}

}


void solutie4() {

	int v[100], n;

	citireVector(v, n);

	afisarePerechi(v, n);

}