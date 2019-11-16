// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ACT10

#include<iostream>
#include<math.h>

using namespace std;

int Factorial(int f) {
	if (f == 0) {
		f = 1;
	}
	else {
		f = f * Factorial(f - 1);
	}
	return f;
}

int main() {
	int x;
	int kf;
	int n;
	double sum;

	cout << "Valor de la variable x: ";
	cin >> x;
	cout << "Desea que la sumatoria se realice desde que k=0 hasta que k sea: ";
	cin >> n;
	for (int k = 0; k <= n; k++) {
		kf = Factorial(k);
		sum = sum + (pow(x, k) / kf);
	}

	cout << "e^x = " << sum;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file