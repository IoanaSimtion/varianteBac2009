using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Scrieţi definiţia completă a unui subprogram P, cu trei parametri, care primeşte prin 
intermediul primului parametru, a, un tablou unidimensional de cel mult 100 de numere 
întregi, cu cel mult 4 cifre fiecare, prin intermediul celui de-al doilea parametru, n, numărul 
efectiv de elemente ale tabloului, iar prin parametrul k, un număr natural (k<101) şi 
returnează cea mai mare sumă cu k termeni care se poate obţine adunând k elemente ale 
tabloului.*/


void citireVector(int v[], int& n) {

	ifstream f("vector.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


int P(int a[], int n, int k) {

	int suma = 0;
	bool flag = false;

	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] < a[i + 1]) {
				int aux = a[i];
				a[i] = a[i + 1];
				a[i + 1] = aux;
				flag = false;
			}

		}
	} while (flag == false);

	for (int i = 0; i < k;  i++) {
		suma += a[i];
	}

	return suma;

}


void solutie3() {

	int a[100], n, k;

	cout << "k=";
	cin >> k;

	citireVector(a, n);

	cout << P(a, n, k);

}



//4
/*Fişierul text numere.txt conţine pe prima linie un număr natural n (0<n<100000) iar pe 
doua linie, separate prin câte un spaţiu, n numere naturale formate din cel mult două cifre
fiecare. 
a) Scrieţi un program C/C++ care determină în mod eficient, din punct de vedere al timpului 
de executare, numerele ce apar o singură dată în a doua linie a fişierului. Aceste numere 
vor fi afişate pe ecran în ordine crescătoare, separate prin câte un spaţiu.*/


void citireNumere(int fr[]) {

	ifstream f("numereFrecventa.txt");
	int n, nr;

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> nr;
		fr[nr]++;
	}

}


void afisareNumere(int fr[]) {

	for (int i = 0; i < 100; i++) {
		if (fr[i] == 1) {
			cout << i << ' ';
		}
	}

}


void solutie4() {

	int fr[100]{};

	citireNumere(fr);

	afisareNumere(fr);

}