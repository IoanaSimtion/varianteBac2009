using namespace std;
#include <iostream>
#include <fstream>
#pragma once


//SUBIECTUL 2


//5


void generareMatrice(int a[100][100], int n, int p) {

	int x = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			a[i][j] = x * x;
			x += 2;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

}


void sol5() {

	int a[100][100], n, p;

	cout << "n=";
	cin >> n;

	cout << "p=";
	cin >> p;

	generareMatrice(a, n, p);

}



//SUBIECTUL 3



//3


void sub(int& a, int& b, int n) {

	int nr;
	a = 0;
	b = 0;
	for (nr = n - 1; nr > 1; nr--) {
		bool prim = 1;
		for (int d = 2; d < nr / 2 && prim; d++) {
			if (nr % d == 0) {
				prim = 0;
			}
		}
		if (prim) {
			if (a == 0) {
				a = nr;
			}
			else {
				if (b == 0) {
					b = nr;
				}
				else {
					return;
				}
			}
		}
	}

}


void solutie3() {

	int a, b, n;

	cout << "n=";
	cin >> n;

	sub(a, b, n);

	cout << a << ' ' << b;

}



//4


void produse(int prod[]) {

	ifstream f("PRODUSE.TXT");
	int tip, cantitate, pret;

	while (!f.eof()) {
		f >> tip >> cantitate >> pret;
		prod[tip] += cantitate * pret;
	}

	for (int i = 0; i < 200000; i++) {
		if (prod[i]) {
			cout << i << ' ' << prod[i] << endl;
		}
	}
}


void solutie4() {

	int prod[200000]{};

	produse(prod);

}