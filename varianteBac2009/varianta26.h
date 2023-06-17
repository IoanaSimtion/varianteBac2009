using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural 
n (2<=n<=9) şi elementele unui tablou bidimensional A cu n linii şi n
coloane, care memorează numere naturale mai mici decât 10, şi 
afişează pe ecran (dacă există), separate prin câte un spaţiu, 
elementele din matrice care au proprietatea că sunt egale cu produsul 
celorlalte elemente aflate pe aceeaşi coloană. Dacă nu există astfel de 
elemente, programul va afişa pe ecran mesajul NU EXISTA.*/


void citireMatrice(int a[100][100], int& n) {

	ifstream f("matriceProdus.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f >> a[i][j];
		}
	}

}


int produsColoana(int a[100][100], int n, int coloana) {

	int produs = 1;

	for (int i = 0; i < n; i++) {
		produs *= a[i][coloana];
	}

	return produs;

}


void afisareElemente(int a[100][100], int n) {

	bool exista = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (produsColoana(a, n, j) == 0) {
				if (a[i][j] == 0) {
					cout << a[i][j] << ' ';
					exista = true;
				}
			}
			else {
				if (a[i][j] != 0 && (a[i][j] == (produsColoana(a, n, j) % a[i][j]))) {
					cout << a[i][j] << ' ';
					exista = true;
				}
			}
		}
	}

	if (exista == false) {
		cout << "NU EXISTA";
	}
}


void sol5() {

	int a[100][100], n;

	citireMatrice(a, n);

	/*for (int i = 0; i < n; i++) {
		cout << produsColoana(a, n, i) << ' ';
	}*/

	afisareElemente(a, n);

}



//SUBIECTUL 3



//3
/*Scrieţi programul C/C++ care citeşte de la tastatură două numere naturale nenule n şi k 
(n≤100, k≤100) şi afişează pe ecran, separaţi prin câte un spaţiu, în ordine 
descrescătoare, cei mai mici k multipli naturali nenuli ai numărului n.*/


void cmmmnK(int n, int k) {

	for (int i = k; i > 0; i--) {
		cout << n * i << ' ';
	}

}


void solutie3() {

	int n, k;

	cout << "n=";
	cin >> n;
	cout << "k=";
	cin >> k;

	cmmmnK(n, k);

}



//4
/*a) Scrieţi definiţia completă a subprogramului sterge, care primeşte prin cei 4 parametri
v,n,i,j: 
- v, un tablou unidimensional cu maximum 100 de elemente întregi din intervalul [-1000,1000]
- n, un număr natural reprezentând numărul de elemente din tabloul v
- i şi j două valori naturale cu 1≤i≤j≤n 
şi elimină din tabloul v elementele vi,vi+1,…,vj actualizând valoarea parametrului n. 
Tabloul modificat este furnizat tot prin parametrul v. (6p.)
b) Fişierul text NUMERE.IN conţine pe prima linie un număr natural nenul n (1≤n≤100) şi pe 
următoarea linie n numere întregi din intervalul [-1000;1000], separate prin câte un spaţiu. 
Scrieţi un program C/C++ care citeşte din fişierul NUMERE.IN numărul natural n, 
construieşte în memorie un tablou unidimensional v cu cele n numere întregi aflate pe linia a 
doua în fişier şi utilizează apeluri utile ale subprogramului sterge pentru a elimina din 
tablou un număr minim de elemente astfel încât să nu existe două elemente alăturate cu 
aceeaşi valoare. Elementele tabloului obţinut se afişează pe ecran, separate prin câte un
spaţiu.  */


void citireVector(int v[], int& n) {

	ifstream f("vectorStergere.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


void sterge(int v[100], int& n, int i, int j) {

	for (int k = i; k <= j; k++) {
		for (int l = i; l < n - 1; l++) {
			v[l] = v[l + 1];
		}
		n--;
	}

}


void eliminareElemente(int v[], int& n) {

	int i = 0, j;

	while (i < n) {
		j = i + 1;
		while (v[i] == v[j]) {
			j++;
		}
		sterge(v, n, i + 1, j - 1);
		i++;
	}

}


void afisareVector(int v[], int n) {

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}

}


void solutie4() {

	int v[100], n;

	citireVector(v, n);

	eliminareElemente(v, n);

	afisareVector(v, n);

}
