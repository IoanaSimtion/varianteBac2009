using namespace std;
#include <iostream>
#include <fstream>
#pragma once


//SUBIECTUL 2



//5


void citireMatrice(int a[100][100], int& n) {

	ifstream f("matrice.txt");

	f >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f >> a[i][j];
		}
	}
	
}


void afisarePatratConcentric(int a[100][100], int n) {

	for (int i = 0; i < n; i++)
		cout << a[0][i] << " ";
	for (int i = 1; i < n; i++)
		cout << a[i][n - 1] << " ";
	for (int i = n - 2; i >= 0; i--)
		cout << a[n - 1][i] << " ";
	for (int i = n - 2; i >= 1; i--)
		cout << a[i][0] << " ";

}


void sol5() {

	int a[100][100], n;

	citireMatrice(a, n);

	afisarePatratConcentric(a, n);

}



//SUBIECTUL 3



//3


void afisareDivizori(int n, int k) {

	while (n) {
		cout << k * n << ' ';
		n--;
	}

}


void solutie3() {

	int n, k;

	cout << "n=";
	cin >> n;

	cout << "k=";
	cin >> k;

	afisareDivizori(n, k);

}



//4


void solutie4() {

	//?

}