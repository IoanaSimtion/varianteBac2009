using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Fişierul bac.txt conţine pe prima linie un număr natural n (n≤100), iar pe a doua linie, 
separate prin câte un spaţiu, n numere naturale nenule, cu cel mult 4 cifre fiecare. Scrieţi 
programul C/C++ care citeşte de la tastatură un număr natural k (k≤25), construieşte în 
memorie şi afişează pe ecran un tablou unidimensional ce conţine, în ordinea în care au 
fost citite, numerele de pe a doua linie a fişierului bac.txt care au cel puţin k divizori.*/


bool celPutinKDivizori(int n, int k) {

	int ct = 0;

	for (int d = 1; d < n; d++) {
		if (n % d == 0) {
			ct++;
		}
		if (ct == k) {
			return true;
		}
	}

	return false;

}


void generareVector(int v[], int& d) {

	ifstream f("kDivizori.txt");

	int n, nr, k;

	d = 0;

	f >> n;
	f >> k;

	for (int i = 0; i < n; i++) {
		f >> nr;
		if (celPutinKDivizori(nr, k)) {			
			v[d] = nr;
			d++;
		}
	}

}


void afisareVector(int v[], int d) {

	for (int i = 0; i < d; i++) {
		cout << v[i] << ' ';
	}

}


void solutie3() {

	int v[100], n;

	generareVector(v, n);

	afisareVector(v, n);

}



//4
/*a) Scrieţi în limbajul C/C++ doar antetul subprogramului cifre, care prin intermediul 
parametrului nr primeşte un număr natural de cel mult 9 cifre şi furnizează prin intermediul 
parametrilor nc şi sc numărul de cifre şi respectiv suma cifrelor din scrierea lui nr. (4p.)
b) Scrieţi programul C/C++ care citeşte de la tastatură un număr natural n (10≤n≤109) şi 
verifică, folosind apeluri utile ale subprogramului cifre, dacă în scrierea în baza 10 a lui n
se găseşte cel puţin o cifră care să fie media aritmetică a celorlalte cifre din componenţa lui 
n.Programul afişează pe ecran mesajul DA în caz afirmativ şi mesajul NU în caz contrar*/


void cifre(int n, int& sc, int& nc) {

	nc = 0, sc = 0;

	while (n) {
		sc += n % 10;
		nc++;
		n /= 10;
	}

}


bool cifraMedieAritm(int n) {

	int p = 1;

	while (n / p != 0) {
		int sc, dc;
		cifre(n, sc, dc);
		if ((n / p) % 10 == (sc - ((n / p) % 10)) / (dc - 1)) {
			return true;
		}
		p = p * 10;
	}

	return false;

}


void solutie4() {

	int n;

	cout << "n=";
	cin >> n;

	if (cifraMedieAritm(n)) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

}