using namespace std;
#include <iostream>
#include <fstream>
#pragma once


//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (2<n<25) şi apoi 
construieşte în memorie o matrice cu n linii şi n coloane, numerotate de la 1 la n, ale cărei 
elemente primesc valori după cum urmează: elementul din linia i şi coloana j primeşte ca 
valoare ultima cifră a produsului i*j (1≤i≤n şi 1≤j≤n).
Programul va afişa matricea astfel construită pe ecran, câte o linie a matricei 
pe o linie a ecranului, elementele fiecărei linii fiind separate prin câte un 
spaţiu.*/


void generareMatrice(int a[100][100], int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = (i * j) % 10;
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

	int a[100][100], n;

	cout << "n=";
	cin >> n;

	generareMatrice(a, n);

	afisareMatrice(a, n);

}



//SUBIECTUL 3



//3
/*Fişierele text NR1.TXT şi NR2.TXT conţin, separate prin câte un spaţiu, mai multe numere 
întregi de cel mult 9 cifre fiecare. Fiecare dintre fişiere conţine cel mult 100 de valori şi 
numerele din fiecare fişier sunt ordonate strict crescător. Se cere să se afişeze pe ecran, în 
ordine crescătoare, numerele divizibile cu 5 care se găsesc doar în unul din cele două
fişiere.*/


void citireAfisareNr() {

	ifstream f1("numere1.txt");
	ifstream f2("numere2.txt");
	
	int nr1, nr2;

	f1 >> nr1;
	f2 >> nr2;

	while (!f1.eof() && !f2.eof()) {
		if (nr1 < nr2) {
			if (nr1 % 5 == 0) {
				cout << nr1 << ' ';
			}
			f1 >> nr1;
		}
		else {
			if (nr2 < nr1) {
				if (nr2 % 5 == 0) {
					cout << nr2 << ' ';
				}
				f2 >> nr2;
			}
			else {
				f1 >> nr1;
				f2 >> nr2;
			}
		}
	}

	while (!f1.eof()) {
		if (nr1 % 5 == 0) {
			cout << nr1 << ' ';
		}
		f1 >> nr1;
	}

	while (!f2.eof()) {
		if (nr2 % 5 == 0) {
			cout << nr2 << ' ';
		}
		f2 >> nr2;
	}

}


void solutie3() {

	citireAfisareNr();

}



//4
/*Scrieţi un program C/C++ care citeşte de la tastatură o valoare naturală nenulă n (n≤20), 
apoi un şir de n numere naturale, având fiecare exact 5 cifre. Dintre cele n numere citite, 
programul determină pe acelea care au toate cifrele egale şi le afişează pe ecran, în ordine 
crescătoare, separate prin câte un spaţiu.*/


bool cifreEgale(int n) {

	while (n>9) {
		if (n % 10 != (n / 10) % 10) {
			return false;
		}
		n /= 10;
	}

	return true;
}


void citireMemorareNr(int v[], int& d) {

	ifstream f("sirNumere.txt");

	int nr, n;
	d = 0;

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> nr;
		if (cifreEgale(nr)) {
			v[d] = nr;
			d++;
		}
	}

}


void sortCrescartor(int v[], int n) {

	bool flag = 1;

	do {
		
		flag = 1;

		for (int i = 0; i < n - 1; i++) {
			if (v[i] > v[i + 1]) {
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				flag = 0;
			}
		}
	} while (flag == 0);
}


void afisareVector(int v[], int n) {

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}

}


void solutie4() {

	int v[100], n;

	citireMemorareNr(v, n);

	sortCrescartor(v, n);

	afisareVector(v, n);

}