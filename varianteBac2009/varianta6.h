using namespace std;
#include <iostream>
#include <fstream>
#pragma once


//SUBIECTUL 3



//3


void citireVector(int v[], int& n) {

	ifstream f("vector.txt");
	
	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


void afisareSuma(int v[], int n) {

	for (int i = n - 1; i >= 0; i--) {
		int s = 0;
		for (int j = i; j >= 0; j--) {
			s += v[j];
		}
		cout << s << endl;
	}

}


void solutie3() {

	int v[100], n;

	citireVector(v, n);

	afisareSuma(v, n);

}



//4


void frecventaCitire(int s[], int& n, int fr[]) {

	ifstream f("BAC.TXT");

	n = 0;

	while (!f.eof()) {
		f >> s[n];
		fr[s[n]]++;
		n++;
	}

}


void afisareElemFrecv(int s[], int n, int fr[]) {

	for (int i = 0; i < n; i++) {
		if (fr[s[i]] != 0) {
			cout << s[i] << ' ' << fr[s[i]] << ' ';
			fr[s[i]] = 0;
		}
	}

}


void solutie4() {

	int s[100], n;
	int fr[100]{};

	frecventaCitire(s, n, fr);

	afisareElemFrecv(s, n, fr);

}