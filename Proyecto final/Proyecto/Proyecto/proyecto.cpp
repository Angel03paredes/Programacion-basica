#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>

#define ARRIBA 72
#define ABAJO 80
#define ENTER 13


using namespace std;


void menu();
void altalumnos();
void altacalificaciones();
void editar();
void borrar();
void salir();
void lista();
void guardar();

void menueditar(bool encontrado);

char tecla;
int p = 0;
int c;
int opc;
int buscar;



struct datos {
	string nombre;
	string apellido;
	string correo;
	string telefono;
	int matricula;
	double calificacion[3] = {};
	string direccion1;
	string direccion2;
};
datos valores[100];
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void ocultar() {

	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 50;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hcon, &cci);


}


int main() {

	ocultar();
	system("color 1f");
	system("mode con: cols=70 lines=30");
	ifstream archivo("datos.data", ios::binary);


	archivo.read((char*)&valores, sizeof(valores));

	archivo.close();
	for (int i = 0; i < 100; i++)
	{
		if (valores[i].matricula != 0) {
			p++;
		}
	}



	menu();
}
void menu()

{


	int opcionseleccionada = 1;
	char tecla;
	bool  repite = true;
	do {

		system("cls");

		if (opcionseleccionada == 1) {
			cout << "                            MENU \n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "    Alta de alumnos        \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); cout << "    Alta de calificaciones \n    Edicion de alumnos     \n    Borrar alumno          \n    Lista de alumnos    \n    Salir                     " << endl;
		}
		if (opcionseleccionada == 2) {
			cout << "                            MENU \n\n    Alta de alumnos        \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "    Alta de calificaciones \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); cout << "    Edicion de alumnos     \n    Borrar alumno          \n    Lista de alumnos    \n    Salir" << endl;
		}
		if (opcionseleccionada == 3) {
			cout << "                            MENU \n\n    Alta de alumnos        \n    Alta de calificaciones \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "    Edicion de alumnos     \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); cout << "    Borrar alumno           \n    Lista de alumnos    \n    Salir " << endl;
		}
		if (opcionseleccionada == 4) {
			cout << "                            MENU \n\n    Alta de alumnos        \n    Alta de calificaciones \n    Edicion de alumnos     \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "    Borrar alumno          \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); cout << "    Lista de alumnos    \n    Salir                  " << endl;
		}
		if (opcionseleccionada == 5) {
			cout << "                            MENU \n\n    Alta de alumnos        \n    Alta de calificaciones \n    Edicion de alumnos     \n    Borrar alumno\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "    Lista de alumnos       \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); cout << "    Salir                  " << endl;
		}
		if (opcionseleccionada == 6) {
			cout << "                            MENU \n\n    Alta de alumnos        \n    Alta de calificaciones \n    Edicion de alumnos     \n    Borrar alumno          \n    Lista de alumnos";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "\n    Salir                  " << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
		}
		gotoxy(2, 1 + opcionseleccionada);  cout << "-";

		if (_kbhit())
		{

			do {
				tecla = _getch();
			} while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

			switch (tecla) {
			case ARRIBA: opcionseleccionada--;
				if (opcionseleccionada == 0) {
					opcionseleccionada = 6;
				}
				break;
			case ABAJO: opcionseleccionada++;
				if (opcionseleccionada == 7) {
					opcionseleccionada = 1;
				}
				break;
			case ENTER: repite = false;
				break;
			}
		}


		Sleep(150);

	} while (repite);

	switch (opcionseleccionada) {
	case 1: altalumnos();

		break;
	case 2: altacalificaciones();
		break;
	case 3: editar();
		break;
	case 4: borrar();
		break;
	case 5: lista();
		break;
	case 6:salir();
		break;
	default:
		system("cls");

		menu();


	}

}
void altalumnos() {
	system("cls");
	cout << " Alta alumnos" << endl << endl;

	cout << "Nombre del alumno: " << endl;
	getline(cin, valores[p].nombre);

	cout << "Apellidos: " << endl;
	getline(cin, valores[p].apellido);

	cout << "Correo: " << endl;
	getline(cin, valores[p].correo);

	cout << "Telefono: " << endl;
	getline(cin, valores[p].telefono);

	cout << "Matricula: " << endl;
	cin >> valores[p].matricula;
	cin.ignore();
	cout << "Calle: " << endl;
	getline(cin, valores[p].direccion1);

	cout << "Colonia: " << endl;
	getline(cin, valores[p].direccion2);

	guardar();

	p++;
	system("cls");
	string opc;
	cout << endl << "Otro registro? \n1.- Si. \n2.- Regresar\n";
	getline(cin, opc);
	while (opc != "1" && opc != "2") {
		system("cls");
		cout << endl << "Otro registro? \n1.- Si. \n2.- Regresar\n";
		getline(cin, opc);
	}
	if (opc == "1") {
		altalumnos();
	}
	else {
		menu();
	}

}
void altacalificaciones() {

	system("cls");
	cout << "       ALTA DE CALIFICACIONES" << endl << endl;
	cout << "Inserte la matricula a buscar " << endl;
	cin >> buscar;

	bool encontrado = false;
	for (int i = 0; i < p; i++)
	{
		if (valores[i].matricula == buscar) {
			cout << "Se encontro " << buscar << endl;
			for (int j = 0; j < 3; j++) {
				cout << "Calificacion " << j + 1 << " :" << endl;

				cin >> valores[i].calificacion[j];

			}
			encontrado = true;
			cout << "Guardado";
			guardar();
			break;
		}
	}

	if (!encontrado) {
		cout << "No se encontro." << endl;
	}

	char tecla;
	cout << endl << "Enter para regresar al menu";
	if (_kbhit()) {
		do {
			tecla = _getch();
		} while (tecla != ENTER);
	}
	menu();




}
void editar() {
	system("cls");
	cout << "       EDITAR" << endl << endl;
	cout << "Inserte la matricula a editar" << endl;
	cin >> buscar;

	bool encontrado = false;
	for (int i = 0; i < p; i++)
	{
		if (valores[i].matricula == buscar) {
			cout << "Se encontro " << buscar << endl;
			encontrado = true;
			c = i;
			break;
		}
	}
	if (encontrado) {
		menueditar(encontrado);
	}

	if (!encontrado) {
		cout << "No se encontro. Enter para regresar" << endl;
		if (_kbhit()) {
			do {
				tecla = _getch();
			} while (tecla != ENTER);
		}
		encontrado = true;
		menu();
	}

}

void menueditar(bool encontrado) {




	int opcionseleccionada = 1;

	bool  repite = true;
	do {
		system("cls");
		cout << "Elija lo que desee editar\n\n\n";


		if (opcionseleccionada == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "    Nombre              \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); cout << "    Correo \n    Telefono    \n    Matricula        \n    Direccion        \n    Calificaciones              \n    Regresar                        " << endl;
		}
		if (opcionseleccionada == 2) {
			cout << "    Nombre        \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "    Correo              \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); cout << "    Telefono    \n    Matricula          \n    Direccion       \n    Calificaciones      \n    Regresar                         " << endl;
		}
		if (opcionseleccionada == 3) {
			cout << "    Nombre        \n    Correo \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "    Telefono            \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); cout << "    Matricula           \n    Direccion       \n    Calificaciones              \n    Regresar                                        " << endl;
		}
		if (opcionseleccionada == 4) {
			cout << "    Nombre        \n    Correo \n    Telefono     \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "    Matricula           \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); cout << "    Direccion       \n    Calificaciones              \n    Regresar                                        " << endl;
		}
		if (opcionseleccionada == 5) {
			cout << "    Nombre        \n    Correo \n    Telefono    \n    Matricula         \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "    Direccion           " << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); cout << "    Calificaciones              \n    Regresar                                        " << endl;
		}
		if (opcionseleccionada == 6) {
			cout << "    Nombre        \n    Correo \n    Telefono    \n    Matricula         \n    Direccion               ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "\n    Calificaciones      " << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); cout << "    Regresar                                        " << endl;
		}
		if (opcionseleccionada == 7) {
			cout << "    Nombre        \n    Correo \n    Telefono    \n    Matricula         \n    Direccion               \n    Calificaciones              \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY); cout << "    Regresar            " << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
		}
		gotoxy(2, 2 + opcionseleccionada);  cout << "-";

		if (_kbhit())
		{

			do {
				tecla = _getch();
			} while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

			switch (tecla) {
			case ARRIBA: opcionseleccionada--;
				if (opcionseleccionada == 0) {
					opcionseleccionada = 7;
				}
				break;
			case ABAJO: opcionseleccionada++;
				if (opcionseleccionada == 8) {
					opcionseleccionada = 1;
				}
				break;
			case ENTER: repite = false;
				break;
			}
		}


		Sleep(200);

	} while (repite);

	switch (opcionseleccionada) {
	case 1: system("cls");

		cin.ignore();
		cout << "Nombre del alumno: " << endl;
		getline(cin, valores[c].nombre);

		cout << "Apellidos: " << endl;
		getline(cin, valores[c].apellido);
		char tecla;
		cout << endl << "Enter para regresar ";
		if (_kbhit()) {
			do {
				tecla = _getch();
			} while (tecla != ENTER);
		}

		break;
	case 2: system("cls");
		cout << "Correo: " << endl;
		cin.ignore();

		getline(cin, valores[c].correo);
		cout << "Enter para regresar";
		if (_kbhit()) {
			do {
				tecla = _getch();
			} while (tecla != ENTER);
		}


		break;
	case 3:
		system("cls");
		editar(); cout << "Telefono: " << endl;
		getline(cin, valores[c].telefono);
		if (_kbhit()) {
			do {
				tecla = _getch();
			} while (tecla != ENTER);
		}

		break;
	case 4:
		system("cls");
		cout << "Matricula: " << endl;
		cin >> valores[c].matricula;

		if (_kbhit()) {
			do {
				tecla = _getch();
			} while (tecla != ENTER);
		}
		break;
	case 5:
		system("cls");
		cout << "Calle: " << endl;
		getline(cin, valores[c].direccion1);

		cout << "Colonia: " << endl;
		getline(cin, valores[c].direccion2);
		if (_kbhit()) {
			do {
				tecla = _getch();
			} while (tecla != ENTER);
		}
		break;
	case 6:
		system("cls");
		for (int i = 0; i < 3; i++) {
			cout << "Calificacion " << i + 1 << " :" << endl;

			cin >> valores[c].calificacion[i];

		}
		if (_kbhit()) {
			do {
				tecla = _getch();
			} while (tecla != ENTER);
		}
		break;
	case 7: menu();

		system("cls");




	}
	guardar();
	menu();



}

void borrar()
{
	int o;
	bool encontrado = false;
	system("cls");
	cout << "               Borrar" << endl << endl;
	cout << "Inserte la matricula del alumno" << endl;
	cin >> buscar;

	int i = 0;
	while (i < p) {
		if (valores[i].matricula == buscar) {
			cout << "Encontre a: " << endl;
			cout << valores[i].matricula;

			cout << "Eliminar a " << valores[i].nombre << "?" << endl;
			cout << "1. Si \n2. No" << endl;
			cin >> o;
			encontrado = true;
			if (o == 1 && p != 0) {
				for (int j = i; j < p; j++)
				{
					valores[j] = valores[j + 1];
				}
				p--;
			}
			break;
		}
		
		i++;
	}
	if (!encontrado) {
		cout << "No se encontro nada" << endl;


		
	}
	cout << "Enter para regresar.";
		if (_kbhit()) {
			do {
				tecla = _getch();
			} while (tecla != ENTER);
		}
		guardar();
	menu();
}


void lista() {
	system("cls");
	int puntos;
	cout << "        LISTA DE ALUMNOS\n";
	if (p > 0) {
		for (int i = 0; i < p; i++) {
			cout << valores[i].matricula;
			double prom = valores[i].calificacion[0] * 0.3 + valores[i].calificacion[1] * 0.45 + valores[i].calificacion[2] * 0.25;
			puntos = 60 - 7 - sizeof(prom) / 4;


			for (int j = 0; j < puntos; j++) {
				cout << ".";
			}
			cout << prom << endl;
		}
		system("pause");

	}
	if (p <= 0) {
		cout <<endl << "No hay ningun registro";
		cout << endl;
		system("pause");

	}
	menu();
}

void salir() {



}

void guardar() {
	ofstream archivo;


	archivo.open("datos.data", ios::binary);

	archivo.write((char*)&valores, sizeof(valores));


	archivo.close();
}


