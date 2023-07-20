using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBEICTUL 2



//5
/*Se consideră o listă simplu înlănţuită alocată dinamic, în care fiecare nod memorează în 
câmpul info un număr întreg, iar în câmpul urm adresa elementului următor sau NULL 
dacă nu există un nod următor. 
Scrieţi un program C/C++ care citeşte de la tastatură 3 numere naturale nenule n, a şi r
(n≤20, a≤10, r≤10) şi construieşte în memorie o listă simplu înlănţuită astfel încât 
parcurgând lista de la primul nod până la ultimul nod şi afişând pe ecran, separate prin câte 
un spaţiu, numerele memorate în câmpul info al fiecărui nod, se obţin în ordine strict 
crescătoare toate elementele mulţimii M={a, a+r, a+2⋅r,...,a+(n-1)⋅r}. */


struct Nod {

	int info;
	Nod* urm;

};


void initializareLista(int n, int a, int r, Nod* nod) {

	for (int i = n - 1; i >= 0; i--) {
		Nod *nou = new Nod;
		nou->info = a + i * r;
		nou->urm = nod;
		nod = nou;
	}

}


void afisareLista(Nod *nod) {

	for (Nod* p = nod; p != NULL; p = p->urm) {
		cout << p->info << ' ';
	}

}


void sol5() {

	int n, a, r;
	Nod* nod = NULL;

	cout << "n=";
	cin >> n;
	cout << "a=";
	cin >> a;
	cout << "r=";
	cin >> r;

	initializareLista(n, a, r, nod);

	afisareLista(nod);

}



//SUBIECTUL 3



//3
/*Se consideră subprogramul cmmdc, care primeşte prin intermediul a doi parametri, a şi b, 
două numere naturale nenule, cu maximum 8 cifre fiecare, şi returnează cel mai mare 
divizor comun al valorilor parametrilor a şi b. 
a) Scrieţi definiţia completă a subprogramului cmmdc. (4p.)
b) Scrieţi un program Pascal care citeşte de la tastatură un număr natural n (n<300), şi, 
cu ajutorul subprogramului cmmdc, determină numărul perechilor de valori naturale (a,b), 
1<a<b<n, cu proprietatea că a şi b nu au niciun divizor comun în afară de 1. Numărul 
obţinut se va afişa pe ecran.*/


int cmmdc(int a, int b) {

	if (a == 0) {
		if (b == 0) {
			return -1;
		}
		else {
			return b;
		}
	}
	else {
		int r;
		do {
			r = a % b;
			a = b;
			b = r;
		} while (r != 0);
		return a;
	}
}


int contorPerechi(int n) {

	int ct = 0;

	for (int a = 2; a < n; a++) {
		for (int b = a + 1; b <= n; b++) {
			if (cmmdc(a, b) == 1) {
				ct++;
			}
		}
	}

	return ct;

}


void solutie3() {

	int n;

	cout << "n=";
	cin >> n;

	cout << contorPerechi(n);

}



//4
/*Fişierul text bac.txt are două linii: pe prima linie conţine un număr natural nenul n
(n<=100), iar pe linia a doua un şir format din n numere naturale de cel mult 4 cifre fiecare, 
despărţite prin spaţii. Scrieţi un program C/C++ care adaugă în fişier toate permutările 
circulare distincte ale şirului de pe linia a doua a fişierului. Astfel, se vor adăuga la sfârşitul 
fişierului încă n-1 linii, fiecare linie conţinând permutarea circulară cu o poziţie către 
stânga, a elementelor şirului aflat pe linia precedentă din fişier. Elementele fiecărei 
permutari vor fi separate prin câte un spaţiu*/


void citireVector(int v[], int& n) {

	ifstream f("permutari.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


void afisarePermutari(int v[], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cout << v[j] << ' ';
		}
		for (int k = 0; k < i; k++) {
			cout << v[k] << ' ';
		}
		cout << endl;
	}

}


void solutie4() {

	int v[100], n;

	citireVector(v, n);

	afisarePermutari(v, n);

}