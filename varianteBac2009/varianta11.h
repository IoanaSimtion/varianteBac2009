using namespace std;
#include <iostream>
#include <fstream>
#pragma once


//SUBIECTUL 2


//5
/*Scrieţi un program C/C++ care citeşte de la tastatură două valori naturale nenule m şi n
(m≤10, n≤10) şi apoi m*n numere naturale nenule cu cel mult 4 cifre fiecare, reprezentând 
elementele unei matrice cu m linii şi n coloane. Programul determină apoi valorile minime de 
pe fiecare linie a matricei şi afişează pe ecran cea mai mare valoare dintre aceste minime.*/


void citireMatrice(int a[11][11], int& m, int& n) {

	ifstream f("citireMatrice.txt");

	f >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			f >> a[i][j];
		}
	}

}


void valoriMinime(int a[11][11], int m, int n, int v[]) {
	
	int indice = 0;

	for (int i = 0; i < m; i++) {
		v[indice] = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (a[i][j] < v[indice]) {
				v[indice] = a[i][j];
			}
		}
		indice++;
	}

}


void afisareVector(int v[], int n) {

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}

}


int valoareaMaxima(int v[], int n) {

	int max = INT_MIN;

	for (int i = 0; i < n; i++) {
		if (v[i] > max) {
			max = v[i];
		}
	}

	return max;

}


void sol5() {
	
	int a[11][11], m, n, v[11]{};
	
	citireMatrice(a, m, n);

	valoriMinime(a, m, n, v);

	//afisareVector(v, m);

	cout << valoareaMaxima(v, m);

}



//SUBIECTUL 3



//3
/*Fişierul text numere.txt conţine pe prima linie un număr natural n (n<30000), iar pe a 
doua linie n numere întregi având maximum 4 cifre fiecare. Se cere să se afişeze pe ecran 
un şir de n numere întregi, cu proprietatea că valoarea termenului de pe poziţia i
(i=1,2,…,n) din acest şir este egală cu cea mai mare dintre primele i valori de pe a doua 
linie a fişierului numere.txt*/


void citireAfisareNumere() {

	ifstream f("numere.txt");
	int max = INT_MIN, n, nr;

	f >> n;

	while (!f.eof()) {
		f >> nr;
		if (nr > max) {
			max = nr;
		}
		cout << max << ' ';
	}

}


void solutie3() {

	citireAfisareNumere();

}



//4
/*a) Scrieţi doar antetul funcţiei sum care primeşte ca parametru un număr natural nenul x cu 
maximum 9 cifre şi returnează suma divizorilor numărului x. 
Exemplu: sum(6) are valoarea 12 (=1+2+3+6). (3p.)
b) Să se scrie un program C/C++ care citeşte de la tastatură un număr natural n (0<n<25) şi 
apoi n numere naturale nenule cu maximum 9 cifre fiecare. Programul calculează, folosind 
apeluri ale funcţiei sum, şi afişează pe ecran câte numere prime conţine şirul citit. */


int sum(int x) {

	int s = 0;

	for (int i = 1; i <= sqrt(x); i++) {
		if (x % i == 0) {
			s += i + (x / i);
		}
	}

	return s;
}


int numerePrime() {

	ifstream f("sum.txt");

	int ctNumerePrime = 0, n, nr;

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> nr;
		if (sum(nr) == nr + 1 && nr != 1) {
			//cout << nr << ' ';
			ctNumerePrime++;
		}
	}

	return ctNumerePrime;
}


void solutie4() {

	cout << numerePrime();

}