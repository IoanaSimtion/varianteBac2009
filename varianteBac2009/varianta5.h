using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 5



void generareMatrice(int a[11][11], int n, int m) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i > j) {
				a[i][j] = i;
			}
			else {
				a[i][j] = j;
			}
		}
	}

}


void afisareMatrice(int a[11][11], int n, int m) {

	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

}


void sol5() {

	int A[11][11], n, m;

	cout << "n=";
	cin >> n;

	cout << "m=";
	cin >> m;

	generareMatrice(A, n, m);

	afisareMatrice(A, n, m);


}



//SUBIECTUL 3



//3


void afisarePrefixe(int n) {

	while (n > 9) {
		cout << n / 10 << ' ';
		n /= 10;
	}

}


void solutie3() {

	int n;

	cout << "n=";
	cin >> n;

	cout << "Prefixele numarului " << n << " sunt: " << endl;
	cout << n << ' ';
	afisarePrefixe(n);

}



//4


int f(int a) {

	int d = 2;

	do {
		while (a % d == 0) {
			a /= d;
			return d;
		}
		d++;
	} while (a > 1);

}


void citireMemorare(int v[], int& n) {

	ifstream fin("citire.txt");
	
	n = 0;

	int dim, x;
	fin >> dim;

	for (int i = 0; i < dim; i++) {
		fin >> x;
		if (x == f(x)) {
			v[n] = x;
			n++;
		}

	}

}


void bubbleSort(int v[], int n) {

	bool flag = 0;

	do {
		flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (v[i] > v[i + 1]) {
				swap(v[i], v[i + 1]);
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

	int a, v[100], n;

	cout << "a=";
	cin >> a;

	cout << "a) Cel mai mic divizor prim al lui " << a << " este " << f(a) << endl;

	citireMemorare(v, n);
	bubbleSort(v, n);

	cout << "b) ";
	afisareVector(v, n);

}



