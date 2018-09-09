#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;

int main() {
	int pos = 49;
	int contador=0;
	srand(time(NULL));
	for (int i = 0; i<100; i++) {
		system("cls");
		int r = rand() % 2;
		if (r == 0) {
			pos = pos - 1;
		}
		else {
			pos = pos + 1;
		}

		if (pos < 0) {
			pos = 99;
		}
		if (pos > 99) {
			pos = 0;
		}
		if (pos == 49) {
			contador = contador + 1;
			
		}
		
		for (int j = 0; j<100; j++) {
			if (j == pos) {
				cout << "A";
			}
			else {
				cout << "*";
			}
			
		}
		Sleep(50); 
		
	}
	cout << endl;
	cout <<"Paso por el punto inicial: " << contador << "veces.";
	system("pause>nul");
}