#include <iostream>
using namespace std;
void piedra();
void papel();
void tijera();
int puntos=0;
int puntosmaq=0;
int respuesta;
void cerrar();
bool bienvenida = true;
int main() {
	if (bienvenida == true) { cout << "Hola, gana 3 de 5 en piedra papel o tijeras" << endl; } bienvenida = false;
	if (puntos == 3) { cout << "ganaste"; }
	if (puntosmaq == 3) { cout << "perdiste"; }
	if (puntos < 3 && puntosmaq < 3) {
		cout << " Elige la opcion" << endl << "1.- Piedra.\n2.- Papel. \n3-. Tijeras.\n";
		int opcion;
		cin >> opcion;


		switch (opcion) {
		case 1:   piedra(); break;
		case 2:  papel(); break;
		case 3:  tijera(); break;
		}
	}
	else {
		cerrar();
	}
	
	
}
 
void piedra() {
	respuesta = rand() % 2;
	if (respuesta == 0) {
		cout << "Empate, intenta otra ves" << endl;
		cout << "puntos:" << puntos << "    pc: " << puntosmaq << endl;
		 main();
	}
	if (respuesta == 1) {
		cout << "Perdiste la ronda" << endl;
		puntosmaq = puntosmaq + 1;
		cout << "puntos:" << puntos << "    pc: " << puntosmaq << endl;
		 main();
	}
	if (respuesta == 2) {
		cout << "Ganaste la ronda" << endl;
		puntos = puntos + 1;
		cout << "puntos:" << puntos << "    pc: " << puntosmaq << endl;
		 main();
	}

}
void papel() {
	respuesta = rand() % 2;
	if (respuesta == 1) {
		cout << "Empate, intenta otra ves" << endl;
		cout << "puntos:" << puntos << "    pc: " << puntosmaq << endl;
		main();
	}
	if (respuesta == 2) {
		cout << "Perdiste la ronda" << endl;
		puntosmaq = puntosmaq + 1;
		cout << "puntos:" << puntos << "     pc: " << puntosmaq << endl;
		 main();
	}
	if (respuesta == 0) {
		cout << "Ganaste la ronda" << endl;
		puntos = puntos + 1;
		cout << "puntos:" << puntos << "   pc: " << puntosmaq << endl;
		 main();
	}

}
void tijera() {
	respuesta = rand() % 2;
	if (respuesta == 2) {
		cout << "Empate, intenta otra ves" << endl;
		cout << "puntos:" << puntos << "    pc: " << puntosmaq << endl;
		main();
	}
	if (respuesta == 0) {
		cout << "Perdiste la ronda" << endl;
		puntosmaq = puntosmaq + 1;
		cout << "puntos:" << puntos << "     pc: " << puntosmaq << endl;
		 main();
	}
	if (respuesta == 1) {
		cout << "Ganaste la ronda" << endl;
		puntos = puntos + 1;
		cout << "puntos:" << puntos << "    pc: " << puntosmaq << endl;
		 main();
	}
	
}
void cerrar()
{
	system("pause null");
}