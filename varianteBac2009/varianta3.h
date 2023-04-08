using namespace std;
#include <iostream>
#include <fstream>
#pragma once


//SUBIECTUL 2


//3


struct Fractie {

	int x, y;

};



int cmmdc(int a, int b) {

	int r;

	do {
		r = a % b;
		a = b;
		b = r;
	} while (r);

	return a;

}


void sol3() {

	Fractie f, f1, f2;

	cout << "numarator 1: ";
	cin >> f1.x;
	cout << "numarator 1: ";
	cin >> f1.y;

	cout << "numarator 2: ";
	cin >> f2.x;
	cout << "numarator 2: ";
	cin >> f2.y;

	int cmmmc = (f1.y * f2.y) / cmmdc(f1.y, f2.y);

	f.x = f1.x * (cmmmc / f1.y) + f2.x * (cmmmc / f2.y);
	f.y = f1.y * (cmmmc / f1.y) + f2.y * (cmmmc / f2.y);

	cout << f1.x << '/' << f1.y << " + " << f2.x << '/' << f2.y << " = " << f.x << '/' << f.y;

}



//5



void generareMatrice(int a[100][100], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				a[i][j] = 0;
			}
			else {
				a[i][j] = n - j;
			}
		}
	}

}


void afisareMatrice(int a[100][100], int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
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

	afisareMatrice(a, n, n);

}



//SUBIECTUL 3



//3


int nrCifre(int n) {
	
	int ct = 0;

	while (n) {
		n /= 10;
		ct++;
	}

	return ct;
}



void citireMemorare(int v[], int& n) {

	ifstream f("NR2.TXT");
	int nr;

	while (!f.eof()) {
		f >> nr;
		if (nrCifre(nr)>2) {
			v[n] = nr;
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


void solutie3() {

	int v[100], n = 0;

	citireMemorare(v, n);

	if (n != 0) {
		bubbleSort(v, n);
		afisareVector(v, n);
	}
	else {
		cout << "NU EXISTA";
	}

}



//4


int cif(int a, int b) {

	int ap = 0;

	while (a) {
		if (a % 10 == b) {
			ap++;
		}
		a /= 10;
	}

	return ap;

}


void frecventaCifre(int fr[], int n) {

	for (int i = 0; i < 10; i++) {
		if (fr[i] == 0) {
			fr[i] = cif(n, i);
		}
	}

}


bool palindrom(int fr[]) {

	for (int i = 0; i < 10; i++) {
		if (fr[i] % 2 != 0) {
			return false;
		}
	}

	return true;
}


void palindormMax(int fr[], int n, int& a, int& b) {

	int p = 1;

	for (int i = 9; i >= 0; i--) {
		while (fr[i]) {
			a = a * 10 + i;
			b = i * p + b;
			fr[i]--;
			fr[i]--;
			p *= 10;
		}
	}

}


void solutie4() {

	int a, b, n, nr1 = 0, nr2 = 0;
	int fr[10]{};

	/*cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;

	cout << "a)" << cif(a, b) << endl;*/

	cout << "n=";
	cin >> n;

	frecventaCifre(fr, n);

	/*for (int i = 0; i < 10; i++) {
		cout << fr[i] << ' ';
	}*/

	if (palindrom(fr) == true) {
		palindormMax(fr, n, nr1, nr2);
		cout << "b) " << nr1 * pow(10, nrCifre(nr2)) + nr2;
	}
	else {
		cout << "b)" << 0;
	}

}