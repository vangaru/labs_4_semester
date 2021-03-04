#include <iostream>
#include <cmath>

using namespace std;

float getFloatSolution(float a, float b);
double getDoubleSolution(double a, double b);

void task2(int n, int m);

int main() {
	float f_a = 100.0;
	float f_b = 0.001;

	cout << getFloatSolution(f_a, f_b) << endl;

	double d_a = 100.0;
	double d_b = 0.001;
	
	cout << getDoubleSolution(d_a, d_b);

	cout << endl << "Enter n >> ";
	int n;
	cin >> n;
	cout << "Enter m >> ";
	int m;
	cin >> m;
	task2(n, m);

	return 0;
}

float getFloatSolution(float a, float b) {
	return ((pow(a - b, 4) - (pow(a, 4) - (4 * pow(a, 3) * b)) )) /
		(pow(b, 4) - 4 * a * pow(b, 3));
}

double getDoubleSolution(double a, double b) {
	return ((pow(a - b, 4) - (pow(a, 4) - (4 * pow(a, 3) * b)) )) /
		(pow(b, 4) - 4 * a * pow(b, 3));
}

void task2(int n, int m) {
	cout << "n---m: " << (n-- - m) << endl;
	cout << "m--<n: " << (m-- < n) << endl;
	cout << "n++>m: " << (n++ > m) << endl;
}



