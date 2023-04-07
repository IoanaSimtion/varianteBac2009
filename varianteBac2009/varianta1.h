using namespace std;
#include <iostream>
#include <fstream>
#pragma once


//SUBIECTUL 2



//3


struct Punct {

	float x, y;

};


void sol3() {

	Punct A, B, C;

	cout << "xA=";
	cin >> A.x;

	cout << "yA=";
	cin >> A.y;

	cout << "xB=";
	cin >> B.x;

	cout << "yB=";
	cin >> B.y;

	C.x = (A.x + B.x) / 2;
	C.y= (A.y + B.y) / 2;

	cout << "Coordonatele mijlocului segmentului AB sunt: " << endl;
	cout << "xC=" << C.x << endl;
	cout << "yC=" << C.y << endl;

}



//5

void generareMatrice(int a[100][100], int n, int m) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i > j) {
				a[i][j] = j;
			}
			else {
				a[i][j] = i;
			}
		}
	}

}


void afisareMatrice(int a[100][100], int n, int m) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

}


void sol5() {

	int a[100][100], n, m;

	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;

	generareMatrice(a, n, m);

	afisareMatrice(a, n, m);

}



//SUBIECTUL 3



//3


void citireAfisareNumere(int n) {

	ifstream f("bac1.txt");
	int x;
	bool exista = 0;

	while (!f.eof()) {
		f >> x;
		if (x % n == 0) {
			cout << x << ' ';
			exista = 1;
		}
	}

	if (exista == 0) {
		cout << "Nu exista";
	}

}


void solutie3() {

	int n;

	cout << "n=";
	cin >> n;

	cout << "Numerele din fisier divizinile cu " << n << " sunt: " << endl;
	citireAfisareNumere(n);

}


//4


void citireVector(int v[], int n) {

	cout << "Introduceti elementele vectorului: ";

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

}


int sub(int v[], int n, int a) {

	int ct = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] < a) {
			ct++;
		}
	}

	return ct;
}


void solutie4() {

	int v[100], n, a;

	cout << "n=";
	cin >> n;

	citireVector(v, n);

	cout << "a=";
	cin >> a;

	cout << "In vector exista " << sub(v, n, a) << " elemente strict mai mici decat " << a << endl;

}