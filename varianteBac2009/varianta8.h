using namespace std;
#include <iostream>
#include <fstream>
#pragma once


//SUBIECTUL 2


//5


void generareMatrice(int a[100][100], int n, int p) {

	int x = 1;

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


void citireVector(int v[], int& n) {

	ifstream f("BAC3.TXT");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


void afisareSumaPp(int v[], int n) {

	bool primul = 0;
	int suma = 0;

	for (int i = 0; i < n; i++) {
		if (int(sqrt(v[i])) == sqrt(v[i])) {
			if (primul != 0) {
				cout << '+' << v[i];
				suma += v[i];
			}
			else {
				cout << v[i];
				suma += v[i];
				primul = 1;
			}
		}
	}

	cout << '=' << suma;

}


void solutie3() {

	int v[50], n;

	citireVector(v, n);

	afisareSumaPp(v, n);

}



//4


void citireVectori(int a[], int b[], int& n, int& m) {

	ifstream f("vectori.txt");

	f >> n >> m;

	for (int i = 0; i < n; i++) {
		f >> a[i];
	}
	
	for (int i = 0; i < m; i++) {
		f >> b[i];
	}

}


void sub(int a[], int b[], int n, int m) {

	int i = 0, j = 0;
	int c[100], k = 0;

	while (i < n && j < m) {
		if (a[i] < b[j]) {
			c[k] = a[i];
			k++;
			i++;
		}
		else {
			c[k] = b[j];
			k++;
			j++;
		}
	}

	while (i < n) {
		c[k] = a[i];
		k++;
		i++;
	}

	while (j < m) {
		c[k] = b[j];
		k++;
		j++;
	}

	cout << c[0] << ' ';

	for (int i = 1; i < k; i++) {
		if (c[i] % 2 != c[i - 1] % 2) {
			cout << c[i] << ' ';
		}
	}

}


void solutie4() {

	int a[100], b[100], n, m;

	citireVectori(a, b, n, m);
	
	sub(a, b, n, m);

}