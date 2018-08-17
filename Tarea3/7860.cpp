#include<iostream>
using namespace std;
int main()
{
	int lados;
	int result;
	cout << "¿Cuantos lados tiene su poligono?" << endl;
	cin >> lados  ;
	result = lados * (lados - 3) / 2;
	cout << "Diagonales: " << result << endl;
	system("pause");
}