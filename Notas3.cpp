#include <fstream>
#include <iostream>
#include <string>


using namespace std;

//Definimos una estructura de Estudiante
struct Estudiante {
	int id;
	string nombre;
	string apellido;
	float notas[4];
	float average;
	string resultado;
};

// Funcion para calcular la media de las notas
float calcularMedia(float notas[4]){
	float sum = 0;
	for(int i = 0; i < 4; i++) {
		sum += notas[i];
	}
	return sum / 4;
}

// Funcion para verificar si el estudiante aprobo
string checkPass(float average){
	if (average > 60) {
		return "Has Aprobado con mas de 60";
	} else {
		return "No has Aprobado con mas de 60";
	}
}

//Funcion para crear un nuevo estudiante
void crearEstudiante(Estudiante* estudiante) {
	cout << "Ingrese el ID para el estudiante: ";
	cin >> estudiante->id;
	cout << "Ingrese el Nombre del estudiante :";
	cin >> estudiante->nombre;
	cout << "Ingrese el apellido del estudiante: ";
	cin >> estudiante->apellido;
	for (int i = 0; i < 4; i++) {
		cout << "Ingrese la nota " << i + 1 << " para el estudiante: ";
		cin >> estudiante->notas[i];
	}
	estudiante->average = calcularMedia(estudiante->notas);
	estudiante->resultado = checkPass(estudiante->average);
}

//Funcion para leer los estudiantes del archivo
void leerEstudiantes(Estudiante* estudiante, int numEstudiantes){
	ifstream file("Notas.dat", ios::binary);
	if (!file) {
		cout << "Error al abrir el archivo" << endl;
		return;
	}
	for (int i = 0; i < numEstudiantes; i++) {
		file.read((char*)&estudiante[i], sizeof(Estudiante));
	}
	file.close();
}

//Funcion para escribir un estudiante al archivo
void escribirEstudiante(Estudiante* estudiantes, int numEstudiantes) {
	ofstream  file("Notas.dat", ios::binary);
	if (!file) {
		cout << "Error al abrir el archivo" << endl;
		return;
	}
	for (int i = 0; i < numEstudiantes; i++) {
		file.write((char*)&estudiantes[i], sizeof(Estudiante));
	}
	file.close();
}

//Funcion para actualizar un estudiante
void actualizarEstudiante(Estudiante* estudiante) {
	cout << "Ingres el nuevo ID para el estudiante: ";
	cin >> estudiante->id;
	cout << "Ingrese el nuevo nombre para el estudiante: ";
	cin >> estudiante->nombre;
	cout << "Ingrese el nuevo apellido para el estudiante: ";
	cin >> estudiante->apellido;
	for (int i = 0; i < 4; i++) {
		cout << "Ingrese la nueva nota " << i + 1 << " para el estudiante: ";
		cin >> estudiante->notas[i];
	}
	estudiante->average = calcularMedia(estudiante->notas);
	estudiante->resultado = checkPass(estudiante->average);
}

//Funcion para eliminar un estudiante
void eliminarEstudiante(Estudiante* estudiantes, int numeroEstudiantes, int id) {
	for (int i = 0; i < numeroEstudiantes; i++) {
		if (estudiantes[i].id == id) {
			for (int j = i; j < numeroEstudiantes - 1; j++) {
				estudiantes[j] = estudiantes[j + 1];
			}
			numeroEstudiantes--;
			return;
		}
	}
	cout << "Estudiante no encontrado." << endl;
}

int main() {
	int numeroEstudiantes;
	cout << "Ingrese el numero de Estudiantes: ";
	cin >> numeroEstudiantes;

	//Creamos un array de la estructura de Estudiante
	Estudiante* estudiantes = new Estudiante[numeroEstudiantes];

	//Creamos estudiantes
	for (int i = 0; i < numeroEstudiantes; i++) {
		crearEstudiante(&estudiantes[i]);
	}

	//Escribimos el estudiante al archivo
	escribirEstudiante(estudiantes, numeroEstudiantes);

	//Leemos los estudiantes del archivi
	leerEstudiantes(estudiantes, numeroEstudiantes);

	//Mostramos los estudiantes
	for (int i = 0; i < numeroEstudiantes; i++) {
		cout << "Estudiante " << i + 1 << ".\n";
		cout << "ID: " << estudiantes[i].id << "\n";
		cout << "Nombres: " << estudiantes[i].nombre << ".\n";
		cout << "Apellidos: " << estudiantes[i].apellido << ".\n";
		cout << "Media: " << estudiantes[i].average << ".\n";
		cout << "Resultado: " << estudiantes[i].resultado << "\n\n";
	}

	// Actualizar Estudiante
	int id;
	cout << "Ingrese el ID del estudiante para actualizar: ";
	cin >> id;
	for (int i = 0; i < numeroEstudiantes; i++) {
		if (estudiantes[i].id == id) {
			actualizarEstudiante(&estudiantes[i]);
			break;
		}
	}

	//Escribimos los estudiantes al archivo
	escribirEstudiante(estudiantes, numeroEstudiantes);

	//Mostramos los estudiantes
	cout << "Estudiantes antes de actualizar:\n";
	for (int i = 0; i < numeroEstudiantes; i++) {
		cout << "Estudiante " << i + 1 << ":\n";
		cout << "ID: " << estudiantes[i].id << ":\n";
		cout << "Nombres: " << estudiantes[i].nombre << "\n";
		cout << "Apellidos: " << estudiantes[i].apellido << "\n";
		cout << "Media: " << estudiantes[i].average << "\n";
		cout << "Resultado: " << estudiantes[i].resultado << "\n";
	}

	//Eliminar un estudiante
	cout << "Ingrese el ID del estudiante a eliminar: ";
	cin >> id;
	eliminarEstudiante(estudiantes, numeroEstudiantes, id);

	//Escribimos los estudiantes al archivo
	escribirEstudiante(estudiantes, numeroEstudiantes);

	//Mostramos los estudiantes;
	cout << "Estudiantes antes de eleiminar:\n";
	for (int i = 0; i < numeroEstudiantes; i++) {
		cout << "Estudiante " << i + 1 << ".\n";
		cout << "ID: " << estudiantes[i].id << "\n";
		cout << "Nombres: " << estudiantes[i].nombre << "\n";
		cout << "Apellidos: " << estudiantes[i].apellido << "\n";
		cout << "Media: " << estudiantes[i].average << "\n";
		cout << "Resultado: " << estudiantes[i].resultado << "\n";
	}

	//Borramos la memoria
	delete[] estudiantes;

	return 0;
}
