using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Subprogramul mult, cu doi parametri, primeşte prin intermediul primului parametru, n, un 
număr natural nenul cu maximum trei cifre şi prin intermediul celui de-al doilea parametru, 
a, un tablou unidimensional având n componente numere naturale cu cel mult 8 cifre 
fiecare. Subprogramul returnează valoarea true dacă cele n componente ale lui a pot 
forma o mulţime şi returnează false în caz contrar. 
a) Scrieţi definiţia completă a subprogramului mult. (6p.)
b) Fişierul text date.in conţine cel mult 400 de numere naturale având maximum 8 cifre 
fiecare. Scrieţi un program C/C++ care, folosind apeluri utile ale subprogramului mult, 
afişează pe ecran valoarea maximă k, astfel încât primele k numere succesive din fişier să
poată forma o mulţime. */


bool mult(int n, int a[]) {

	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				return false;
			}
		}
	}
	return true;
}


int indice() {


	ifstream f("kMaxim.txt");

	int k = 0, a[100];

	while (!f.eof()) {
		f >> a[k];
		k++;
		if (mult(k, a) == false) {
			k--;
			return k;
		}
	}

}


void solutie3() {

	cout << indice();

}



//4
/*Scrieţi un program C/C++ care citeşte de la tastatură două numere naturale nenule n şi k
(k<n≤10000) şi afişează pe ecran un şir format din k numere naturale consecutive care au 
suma n. Numerele se vor afişa pe ecran, în ordine crescătoare, despărţite între ele prin 
câte un spaţiu. În cazul în care nu există un astfel de şir, se va afişa mesajul Nu există.*/


void afisareKNumereSumaN2(int n, int k) {

	int suma = 0, start = 0, j = 0;
	bool exista = false;


	for (int i = start; i < n && exista == false; i++) {
		//todo:

		int v[100];

		int poz = 0;

		int k = i + 1;

		bool flag = false;
		while (suma <= n &&  flag==false) {
			suma += k;
			v[poz] = k;
			k++;

		}

	}

}

void afisareKNumereSumaN1(int n, int k, int v[]) {

	int suma = 0, start = 0, ct = 0;
	bool exista = false;


	for (int i = start; i < n && exista == false; i++) {
		
		suma += i;
		v[ct] = i;
		ct++;

		if (suma > n) {
			suma = 0;
			start++;
			i = start - 1;
			ct = 0;	
		}

		if (suma == n && ct == k) {
			exista = true;
		}
	}

	if (exista == false) {
		cout << "Nu exista";
	}
	else {
		for (int i = 0; i < ct; i++) {
			cout << v[i] << ' ';
		}
	}

}


void solutie4() {

	int n, k, v[100];

	cout << "n=";
	cin >> n;
	cout << "k=";
	cin >> k;

	afisareKNumereSumaN1(n, k, v);

}