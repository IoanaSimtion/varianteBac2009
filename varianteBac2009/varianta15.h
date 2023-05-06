using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTULL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural cu exact 5 cifre şi 
construieşte în memorie o matrice cu 6 linii şi 6 coloane, numerotate de la 1 la 6, formată
astfel: 
- elementele aflate pe diagonala principală sunt toate nule; 
- elementele de pe linia 1, aflate deasupra diagonalei principale precum şi elementele de pe 
coloana 1, aflate sub diagonala principală au toate valoarea egală cu cifra unităţilor 
numărului citit; 
- elementele de pe linia 2, aflate deasupra diagonalei principale precum şi elementele de pe 
coloana 2, aflate sub diagonala principală au toate valoarea egală cu cifra zecilor numărului 
citit, şi aşa mai departe, ca în exemplu. 
5. 
Matricea astfel construită va fi afişată pe ecran, câte o linie a 
matricei pe câte o linie a ecranului, elementele de pe aceeaşi linie 
fiind separate prin câte un spaţiu*/


void generareMatrice(int a[100][100], int n) {

	for (int i = 1; i <= 6; i++) {
		for (int j = i + 1; j <= 6; j++) {
			a[j][i] = n % 10;
			a[i][j] = n % 10;
		}
		n /= 10;
	}

}


void afisareMatrice(int a[100][100]) {

	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

}


void sol5() {

	int a[100][100], n = 28731;

	generareMatrice(a, n);

	afisareMatrice(a);

}



//SUBIECTUL 3



//3
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (n≤32000) şi 
afişează pe ecran numărul natural din intervalul închis [1,n] care are cei mai mulţi divizori. 
Dacă există mai multe numere cu această proprietate se va afişa cel mai mic dintre ele.*/


int nrDivizori(int n) {

	int ct = 1;

	for (int d = 2; d < n / 2; d++) {
		if (n % d == 0) {
			ct++;
		}
	}

	return ct * 2;
}


int maximDivizori(int n) {

	int max = INT_MIN;

	for (int i = 1; i <= n; i++) {
		if (nrDivizori(i) > max) {
			max = i;
		}
	}

	return max;

}


void solutie3() {

	int n = 20;

	cout << maximDivizori(n);

}



//4
/*În fişierul text BAC.IN se găsesc, pe o singură linie, separate prin câte un spaţiu, mai multe 
numere naturale de cel mult 6 cifre fiecare. Se cere să se determine şi să se afişeze pe 
ecran, separate printr-un spaţiu, ultimele două numere impare (nu neapărat distincte) din 
fişierul BAC.IN. Dacă în fişier se găseşte un singur număr impar sau niciun număr impar se 
va scrie pe ecran mesajul Numere insuficiente. */


void afisareNrImpare2() {

	ifstream f("BAC2.IN");
	int a = 0, b = 0, n;

	while (!f.eof()) {
		f >> n;
		if (n % 2 == 1) {
			a = b;
			b = n;
		}
	}

	if (a && b) {
		cout << a << ' ' << b;
	}
	else {
		cout << "Numere insufieciente";
	}

}


void solutie4() {

	afisareNrImpare2();

}