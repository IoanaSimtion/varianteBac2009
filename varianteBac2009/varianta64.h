using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Subprogramul diviz primeşte prin intermediul parametrului n un număr natural nenul 
(2≤n≤200), iar prin intermediul parametrului a, un tablou unidimensional care conţine n
valori naturale nenule, fiecare dintre acestea având cel mult patru cifre. Elementele tabloului 
sunt numerotate de la 1 la n. 
Subprogramul returnează o valoare egală cu numărul de perechi (ai,aj), 1≤i<j≤n, în 
care ai este divizor al lui aj , sau aj este divizor al lui ai. 
Scrieţi definiţia completă a subprogramului diviz, în limbajul C/C++. */


void citireVector(int a[], int& n) {

	ifstream f("vectorDiviz.txt");

	f >> n;

	for (int i = 1; i <= n; i++) {
		f >> a[i];
	}

}


int diviz(int n, int a[]) {

	int ct = 0;

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] % a[j] == 0 || a[j] % a[i] == 0) {
				ct++;
			}
		}
	}

	return ct;

}


void solutie3() {

	int a[100], n;

	citireVector(a, n);

	cout << diviz(n, a);

}



//4
/*Fişierul text date.in conţine pe prima linie , separate prin câte un spaţiu, cel mult 1000 de 
numere naturale, fiecare dintre ele având maximum 9 cifre. 
a) Scrieţi un program C/C++ care citeşte numerele din fişierul date.txt şi determină cea 
mai lungă secvenţă ordonată strict descrescător, formată din valori citite consecutiv din 
fişier. Numerele din secvenţa găsită vor fi afişate pe ecran, pe o linie, separate prin câte un
spaţiu. Dacă sunt mai multe secvenţe care respectă condiţia impusă, se va afişa doar prima 
dintre acestea. Alegeţi o metodă de rezolvare eficientă din punctul de vedere al timpului de 
executare.*/


void citireNumere() {

	ifstream f("secventeDescresc.txt");

	

}


void solutie4() {



}