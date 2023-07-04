using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Pe prima linie a fişierului bac.in se află un număr natural nenul n (n≤1000), iar pe a 
doua linie a fişierului se află un şir format din n numere naturale, despărţite prin câte un 
spaţiu, fiecare număr fiind format din cel mult 4 cifre. Scrieţi un program C/C++ care 
citeşte valorile din fişier şi care afişează pe ecran mesajul DA dacă toate elementele pare 
din şir sunt în ordine crescătoare şi mesajul NU în caz contrar*/


bool ordineCrescatoare() {

	ifstream f("sirNumereOrd.txt");

	int n, a, b;

	f >> n;
	f >> a;

	if (a % 2 == 0) {
		b = a;
	}

	while (!f.eof()) {
		f >> a;
		if (a % 2 == 0) {
			if (a < b) {
				return false;
			}
			b = a;
		}
	}

	return true;

}


void solutie3() {

	if (ordineCrescatoare() == true) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

}



//4
/*Se consideră subprogramul pr, care primeşte prin intermediul parametrului a un număr 
natural nenul cu cel mult 9 cifre şi returnează 1 dacă numărul este prim şi 0 în caz contrar. 
a) Scrieţi numai antetul subprogramului pr. (4p.) 
b) Considerăm un număr natural nenul n>99 cu cel mult 9 cifre. Din n se obţine un şir de 
valori prin eliminarea succesivă a ultimei cifre, apoi a ultimelor două cifre, apoi a ultimelor 
trei cifre etc., până ce se obţine un număr de două cifre, ca în exemplu. Să se realizeze un 
program C/C++ care citeşte de la tastatură numărul n şi care, folosind apeluri utile ale 
subprogramul pr, afişează pe ecran, separate prin câte un spaţiu, doar valorile prime din 
şirul numerelor obţinute din n, prin procedeul descris mai sus. */


int pr(int a) {

	for (int d = 2; d < sqrt(a); d++) {
		if (a % d == 0) {
			return 0;
		}
	}

	return 1;

}


void afisareNrPrime(int n) {

	while (n > 99) {
		n /= 10;
		if (pr(n) == 1) {
			cout << n << ' ';
		}
	}

}


void solutie4() {

	int n;

	cout << "n=";
	cin >> n;

	afisareNrPrime(n);

}
