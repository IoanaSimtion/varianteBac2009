using namespace std;
#include <iostream>
#include <fstream>
#pragma once



//SUBIECTUL 3



//3
/*Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n din intervalul 
[2,50] şi apoi n numere reale şi afişează pe ecran câte dintre cele n numere reale sunt 
egale cu media aritmetică a celorlalte n-1 numere reale. */


void citireNumere(int v[], int& n) {

	ifstream f("numereMedie.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> v[i];
	}

}


int sumaVector(int v[], int n) {

	int suma = 0;

	for (int i = 0; i < n; i++) {
		suma += v[i];
	}

	return suma;

}


int nrElemente(int v[], int n) {

	int ct = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] == (sumaVector(v, n) - v[i]) / (n - 1)) {
			ct++;
		}
	}

	return ct;
}


void solutie3() {

	int v[50], n;

	citireNumere(v, n);

	cout << nrElemente(v, n);

}



//4
/*a) Scrieţi definiţia completă a unui subprogram primul, care 
- primeşte prin singurul său parametru, a, o valoare naturală din intervalul [2,10000]
- returnează o valoare naturală reprezentând cel mai mic divizor al numărului a mai mare strict 
decât 1. (6p.)
b) Fişierul text NUMERE.IN conţine pe prima linie un număr natural nenul n(1≤n≤100) şi pe 
următoarea linie n numere naturale din intervalul [2,10000] separate prin câte un spaţiu. 
Un număr natural n se numeşte „aproape prim” dacă este egal cu produsul a două numere 
prime distincte. De exemplu, numărul 14 este „aproape prim” pentru că este egal cu produsul 
numerelor prime 2 şi 7. 
Scrieţi un program C/C++ care determină, folosind apeluri utile ale suprogramului primul, 
cel mai mare număr „aproape prim” de pe linia a doua a fişierului NUMERE.IN. În cazul în 
care există un astfel de număr se afişează pe ecran mesajul DA, urmat de numărul 
determinat, iar în caz contrar mesajul NU*/


int primul(int a) {

	for (int i = 2; i <= a; i++) {
		if (a % i == 0) {
			return i;
		}
	}

}


void aproapePrim() {

	ifstream f("aproapePrim.txt");
	
	int n, a, max = -1;

	f >> n;

	for (int i = 0; i < n; i++) {
		f >> a;
		int b = a / primul(a);
		if (primul(b) == b && a > max) {
			max = a;
		}
	}

	if (max == -1) {
		cout << "NU";
	}
	else {
		cout << "DA ";
		cout << max;
	}

}


void solutie4() {

	aproapePrim();

}