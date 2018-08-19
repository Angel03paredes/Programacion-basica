#include<iostream>
using namespace std;
void main()
{
	float  r, angulo;
	cout << "Inserte  el radio r del triangulo: \n";
	cin >> r;
	cout << "Ahora su angulo: \n";
	cin >> angulo;
	angulo = angulo * 3.1416 / 180;

	float ejey = sin(angulo), ejex = cos(angulo);
	ejex = r * (ejex);
	ejey = r * (ejey);

	cout << "x= " << ejex << endl << "y= " << ejey << endl;

	
	system("pause");
}