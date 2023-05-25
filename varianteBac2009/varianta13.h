using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 2



//5
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (2<n<25) şi apoi
construieşte în memorie o matrice cu n linii şi n coloane, numerotate de la 1 la n, ale cărei 
elemente primesc valori după cum urmează: 
- elementele aflate pe diagonala secundară sunt toate nule; 
- elementele de pe coloana i (1≤i≤n), aflate deasupra diagonalei secundare, au valoarea 
egală cu i; 
- elementele de pe linia n-i+1 (1≤i≤n), aflate sub diagonala secundară, au valoarea egală
cu i. 
5. 
Programul afişează pe ecran matricea construită, câte o linie a matricei pe 
câte o linie a ecranului, elementele fiecărei linii fiind separate prin câte un 
spaţiu. */


void generareMatrice(int a[100][100], int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
if (i + j == n + 1) {
	a[i][j] = 0;
}
else {
	if (i + j < n + 1) {
		a[i][j] = j;
	}
	else {
		a[i][j] = n - i + 1;
	}
}
		}
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

	int a[100][100], n;

	cout << "n=";
	cin >> n;

	generareMatrice(a, n);

	afisareMatrice(a, n);

}



//SUBIECTUL 3



//3
/*Se consideră şirul 1, 2,1, 3,2,1, 4,3,2,1, ...
construit astfel: prima grupă este formată din numărul 1, a doua grupă este formată din
numerele 2 şi 1, iar grupa a k-a, este formată din numerele k, k-1,..., 1.
Se cere să se citescă de la tastatură un număr natural n (n≤1000) şi să se afişeze pe ecran
cel de al n-lea termen al şirului dat. */


int termenulN(int n) {

	int ct = 0;

	for (int i = 1; i < n; i++) {
		for (int j = i; j >= 1; j--) {
			ct++;
			if (ct == n) {
				return j;
			}
		}		
	}

}


void solutie3() {

	int n;

	cout << "n=";
	cin >> n;
	
	cout << termenulN(n);

}



//4
/*Se consideră subprogramul P care are doi parametri:
– n, prin intermediul căruia primeşte un număr natural de cel mult 9 cifre
– c, prin intermediul căruia primeşte o cifră.
Subprogramul va furniza tot prin intermediul parametrului n numărul obţinut din n prin
eliminarea tuturor apriţiilor cifrei c. Dacă, după eliminare, numărul nu mai conţine nicio cifră
sau conţine doar cifre 0, rezultatul returnat va fi 0.
a) Scrieţi doar antetul subprogramului P. (2p.)
b) Pe prima linie a fişierului text BAC.IN se găsesc, separate prin câte un spaţiu, mai multe
numere naturale de cel mult 9 cifre fiecare. Scrieţi programul C/C++ care citeşte numerele
din acest fişier, utilizând apeluri ale subprogramului P elimină toate cifrele impare din fiecare
dintre aceste numere şi apoi scrie în fişierul text BAC.OUT numerele astfel obţinute,
separate prin câte un spaţiu. Dacă un număr din fişierul BAC.IN nu conţine nicio cifră pară
nenulă, acesta nu va mai apărea deloc în fişierul de ieşire.*/


void P(int& n, int c) {

	int m = 0, p = 1;

	while (n) {
		if (n % 10 != c) {
			m += (n % 10) * p;
			p *= 10;
		}
		n /= 10;
	}

	n = m;

}


void citireAfisare() {

	ifstream f("BAC.IN");
	int n;

	while (!f.eof()) {
		f >> n;
		for (int i = 1; i <= 9; i += 2) {
			P(n, i);
		}
		if (n) {
			cout << n << ' ';
		}
	}

}


void solutie4() {

	citireAfisare();

}
