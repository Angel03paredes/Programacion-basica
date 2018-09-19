#include <iostream>
using namespace std;
void main();
void salir();


struct datos {
	char nombre[30];
	char apellido[30];
	char correo[30];
	int telefono;
	int matricula;
	int calificacion[3] = {};
	char direccion1[20];
	char direccion2[20];
};
datos valores[100];


void main()

{
	cout << " MENU \n1.- Alta de alumnos \n2.- Alta de calificaciones \n3.-Edicion de alumnos \n4.-Borrar alumno \n5.-Salir" << endl;
	int opcion;
	cin >> opcion;
	switch (opcion) {
	case 1: cout << "ALTA DE ALUMNOS \n"; char alta[30]; cout << "Nombre: " << endl; cin >> alta; cout << "guardado"; int regresa; cout << "1 para regresar"; cin >> regresa; if (regresa == 1) { main(); } break;
	case 2: cout << "ALTA DE CALIFICACIONES \n";  cout << "Nombre: " << endl; cin >> alta; for (int i = 0; i < 3; i = i + 1) {
		cout << "calificacion" << i << ": ";/* cin >> calificacion[i];*/
	}   cout << "1 para regresar"; cin >> regresa; if (regresa == 1) { main(); } break;
	case 3: cout << "EDICION DE ALUMNOS  \n";  cout << "Nombre: " << endl; cin >> alta; cout << "Editar: \n 1.-Nombre \n2.- Apellido \n3.-Correo \n4.-Telefono \n5.-Matricula \n6.- Direccion";
		int opcion3; cin >> opcion3;
		switch (opcion3) {
		case 1:;
		case 2:;
		case 3:;
		case 4:;
		case 5:;
		case 6:;
		}

		cout << "1 para regresar"; cin >> regresa; if (regresa == 1) { main(); }



		break;
	case 4: cout << "BORRAR ALUMNO  \n";  cout << "Nombre: " << endl; cin >> alta; cout << "borrado";  cout << "1 para regresar"; cin >> regresa; if (regresa == 1) { main(); } break;

	case 5: salir();


	}
	system("pause");
}
void salir() {

}