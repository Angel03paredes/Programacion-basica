#include<iostream>
using namespace std;
int main() {
	int a = 0, b = 0, c=0;
	cout << "Base: " << endl;
	cin >> b;

	cout << "Altura: " << endl;
	cin >> a;

	int area = b * a;
	c = area - b;

	
	for (int i = 0; i < area; i++) {
		if (i % b == 0) {
			cout << endl;
			cout << "*";
			
		}
		else if (i<b || i > area - b  || (i + 1) % b == 0 ) {
					cout << "*";

			}
		else { cout << " "; }
	} 
	system("pause>nul");
}