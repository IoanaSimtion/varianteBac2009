using namespace std;
#include <iostream>
#include <fstream>
#pragma once


//SUBIECTUL 3


//3


void citireVector(int v[], int& d, int& n) {

	ifstream f("BAC2.TXT");

	d = 0;

	f >> n;

	while (!f.eof()) {
		f >> v[d];
		d++;
	}

}


int pozNrPar(int v[], int n) {

	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 0) {
			return i;
		}
	}

	return -1;

}


int pozNrImpar(int v[], int n, int d) {

	for (int i = d - 1; i >= d - 3; i--) {
		if (v[i] % 2 == 1) {
			return i;
		}
	}

	return -1;

}


void afisareVector(int v[], int d) {
	
	for (int i = 0; i < d; i++) {
		cout << v[i] << ' ';
	}

}


void solutie3() {

	int v[100], n, d;

	citireVector(v, d, n);

	if (pozNrImpar(v, n, d) != -1 && pozNrPar(v, n) != -1) {
		swap(v[pozNrImpar(v, n, d)], v[pozNrPar(v, n)]);
	}

	afisareVector(v, d);

}



//4


int sub(int n) {

	if (n <= 5) {
		return n;
	}
	else {
		int m = 5;
		while (n > m) {
			m *= 2;
		}
		m /= 2;
	}

}


void solutie4() {

	int s;

	cin >> s;

	while (s) {
		int n = sub(s);
		cout << n << ' ';
		s -= n;
	}

}