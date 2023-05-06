using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural nenul, cu maximum 
8 cifre, construieşte în memorie şi afişează apoi pe ecran o matrice pătratică, având 
numărul de linii şi de coloane egal cu numărul de cifre ale numărului dat, completată cu 
cifrele numărului citit.
Astfel, elementele de pe prima coloană a matricei vor fi toate egale cu 
cifra unităţilor numărului dat, elementele de pe a doua coloană a 
matricei vor fi toate egale cu cifra zecilor numărului dat, şi aşa mai 
departe, ca în exemplu.*/


int nrCifre(int n) {

	int ct = 0;

	while (n) {
		n /= 10;
		ct++;
	}

	return ct;
}


void generareMatrice(int a[100][100], int& d, int n) {

	d = nrCifre(n);

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			a[j][i] = n % 10;
		}
		n /= 10;
	}

}


void afisareMatrice(int a[100][100], int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

}


void sol5() {

	int n = 1359, a[100][100], d;

	generareMatrice(a, d, n);

	afisareMatrice(a, d);

}



//SUBIECTUL 3



//3
/*Se citeşte de la tastatură un număr natural n (n≤500) şi apoi n cifre separate prin spaţii. Se 
cere să se afişeze pe ecran cele n cifre citite, în ordine crescătoare, separate prin câte un 
spaţiu.*/


void citireAfisareNr() {

	ifstream f("numere3.txt");
	int n, nr, fr[10]{};

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> nr;
		fr[nr]++;
	}

	for (int i = 0; i < 10; i++) {
		while (fr[i]) {
			cout << i << ' ';
			fr[i]--;
		}
	}

}


void solutie3() {

	citireAfisareNr();

}



//4
/*Fişierul text BAC.TXT conţine mai multe numere naturale, cu cel mult 6 cifre fiecare, câte 
un număr pe fiecare linie a fişierului. 
Scrieţi un program C/C++ care citeşte toate numerele din fişierul BAC.TXT şi le 
afişează pe ecran, în aceeaşi ordine, câte cinci pe fiecare linie, separate prin câte 
un spaţiu, cu excepţia ultimei linii care poate conţine mai puţin de cinci numere. 
Programul va afişa apoi pe ecran, pe o linie separată, câte numere din fişier au 
suma cifrelor pară. */


int sumaCifrelor(int n) {

	int s = 0;

	while (n) {
		s += (n % 10);
		n /= 10;
	}

	return s;

}


void citireAfisare() {

	ifstream f("BAC4.TXT");
	int n, ct = 0, sumaPara=0;

	while (!f.eof()) {
		f >> n;
		if (sumaCifrelor(n) % 2 == 0) {
			sumaPara++;
		}
		cout << n << ' ';
		ct++;
		if (ct == 5) {
			cout << endl;
			ct = 0;
		}
	}

	cout << endl << sumaPara;
}


void solutie4() {

	citireAfisare();

}