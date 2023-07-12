using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Se consideră subprogramul divxy care primeşte prin parametrii x şi y două valori întregi 
pozitive (0<x<1000 şi 0<y<1000) şi returnează valoarea 1 dacă y este divizor al lui x sau x
este divizor al lui y şi returnează valoarea 0 în caz contrar. 
a) Scrieţi definiţia completă a subprogramului divxy. 
b) Scrieţi un program C/C++ care citeşte de la tastatură trei numere naturale nenule a, b şi
n, cu cel mult 3 cifre fiecare şi care afişează pe ecran toţi divizorii lui n din intervalul închis 
determinat de a şi b folosind apeluri utile ale subprogramului divxy. Intervalul închis 
determinat de a şi b este [a,b] dacă a<b sau [b,a] dacă b≤a. Numerele afişate sunt 
separate prin câte un spaţiu. Dacă nu există niciun astfel de număr se afişează mesajul NU EXISTA. */


int divxy(int x, int y) {

	if (x % y == 0 || y % x == 0) {
		return 1;
	}
	return 0;

}


void afisareDivixori(int a, int b, int n) {

	int exista = 0;

	if (a > b) {
		int aux = a;
		a = b;
		b = aux;
	}

	for (int i = a; i <= b && i <= n; i++) {
		if (divxy(n, i) == 1) {
			cout << i << ' ';
			exista = 1;
		}
	}

	if (!exista) {
		cout << "NU EXISTA";
	}
}


void solutie3() {

	int a = 85, b = 10, n = 40;

	/*cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "n=";
	cin >> n;*/

	afisareDivixori(a, b, n);

}



//4
/*Fişierul bac.in conţine pe prima linie un număr natural n (0<n<5000), iar pe a doua linie, 
separate prin câte un spaţiu, n numere naturale, formate din cel mult 4 cifre fiecare. 
Scrieţi un program C/C++ care determină şi scrie în fişierul bac.out, toate numerele, citite de 
pe a doua linie a fişierului bac.in, care apar de cel puţin două ori. Numerele determinate se 
vor scrie în ordine crescătoare, pe aceeaşi linie, separate prin câte un spaţiu*/


void citireVector(int v[], int& n) {

	ifstream f("vectorAparitie.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


void sortareVector(int v[], int n) {

	bool flag = false;

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


void afisareNumereAparitiiMultiple(int v[], int n) {

	for (int i = 0; i < n - 1; i++) {
		if (v[i] == v[i + 1]) {
			cout << v[i] << ' ';
			while (v[i] == v[i + 1] && i < n) {
				i++;
			}
		}
	}

}


void solutie4() {

	int v[100], n;

	citireVector(v, n);

	sortareVector(v, n);

	afisareNumereAparitiiMultiple (v, n);

}