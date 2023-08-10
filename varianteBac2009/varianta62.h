using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Scrieţi definiţia completă a unui subprogram fibo cu doi parametri, n şi v, care primeşte 
prin intermediul parametrului n un număr natural (1<n<30) şi returnează prin intermediul 
parametrului v un tablou unidimensional care conţine primii n termeni impari ai şirului lui 
Fibonacci (amintim că şirul lui Fibonacci este: 1,1,2,3,5,8,13,21,…).*/


void fibo(int n, int v[100]) {

	int a = 1, b = 1, c, ct = 2;

	v[0] = 1, v[1] = 1;

	while (ct < n) {
		c = a + b;
		if (c % 2 == 1) {
			v[ct] = c;
			ct++;
		}
		a = b;
		b = c;
	}

}


void afisareVector(int v[], int n) {

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}

}


void solutie3() {

	int v[100], n;

	cout << "n=";
	cin >> n;

	fibo(n, v);

	afisareVector(v, n);

}



//4
/*a) Fişierul date.in conţine un şir de cel mult 10000 numere naturale (printre care cel 
puţin un număr par şi cel puţin un număr impar), cu cel mult 2 cifre fiecare, separate prin 
câte un spaţiu. Scrieţi un program C/C++ care citeşte numerele din fişierul date.in şi 
scrie în fişierul text date.out valorile distincte citite, separate prin câte un spaţiu, 
respectându-se regula: pe prima linie vor fi scrise numerele impare în ordine crescătoare, 
iar pe linia a doua numerele pare, în ordine descrescătoare. Alegeţi o metodă eficientă din 
punctul de vedere al timpului de executare. */


void citireNumere(int fr[]) {

	ifstream f("date.in");

	int n;

	while (!f.eof()) {
		f >> n;
		fr[n]++;
	}

}


void afisare(int fr[]) {
	
	for (int i = 1; i < 100; i+=2) {
		if (fr[i]) {
			cout << i << ' ';
		}
	}

	cout << endl;

	for (int i = 0; i < 100; i += 2) {
		if (fr[i]) {
			cout << i << ' ';
		}
	}	

}


void solutie4() {

	int fr[100]{};
	
	citireNumere(fr);

	afisare(fr);

}