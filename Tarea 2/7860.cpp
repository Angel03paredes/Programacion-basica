#include<iostream>
using namespace std;
int main()
{
	char nom[20];
	cout << "Inserte su nombre:" <<endl;
	cin  >> nom;
	char apell[20];
	cout << "Apellido:" << endl;
	cin >> apell;
	int edad;
	cout << "Edad:" << endl;
	cin >> edad;
	char tel[15];
		cout << "Telefono:" << endl;
		cin >> tel;
		cout << "Nombre:  "<<nom << apell << endl <<"Edad:   "<< edad  << endl<< "Telefono:   "<< tel <<endl;
		system("pause");
	return 0;
} 