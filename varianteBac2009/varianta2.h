using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//4


void functie(int a[100][100], int n) {

	int s = 0;
	
	for (int j = 0; j < n / 2; j++) {

	}

}



//SUBIECUL 3


//3



void citireMemorare(int v[], int& n) {

	ifstream f("NR.TXT");
	int nr;
	n = 0;

	while (!f.eof()) {
		f >> nr;
		if (nr > 0) {
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

	int v[100], n;

	citireMemorare(v, n);

	bubbleSort(v, n);

	afisareVector(v, n);

}


//4


int f(int a) {

	int s = 0, d = 2, p;

	do {
		p = 0;
		while (a % d == 0) {
			a /= d;
			p++;
		}
		if (p) {
			s += p;
		}
		d++;
	} while (a > 1);
	
	return s;
}


void solutie4() {

	int a = 90;
	cout << "Suma exponentilor din descompunerea in factori primi a numarului " << a << " este " << f(a);



}