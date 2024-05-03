#include <iostream>
#include <string>

using namespace std;

// Se define una estructura de Estudiantes
struct Estudiante {
	int id;
	string nombres;
	string apellidos;
	float* notas;
};


// Funcion para calcular el promedio de clases
float calcularPromedio(float* notas) {
	float sum = 0;
	for (int i = 0; i < 4; i++){
		sum += notas[i];
	}
	return sum / 4;
}


// Funcion para verificar si el estudiante aprobo o no aprobo
string checkPass(float average) {
	if (average > 60) {
		return "Aprobado";
	} else {
		return "Reprobado";
	}
}


int main() {
	int numEstudiantes;
	cout << "Ingrese el numero de Estudiantes: ";
	cin >> numEstudiantes;
	
	//Creamos un array del puntero de la estructura de Estudiantes
	Estudiante* estudiantes = new Estudiante[numEstudiantes];
	
	//Obtenemos la información de los estudiantes
	for (int i = 0; i < numEstudiantes; i++) {
		cout << "Ingrese el Id del Estudiante " << i + 1 << ": ";
		cin >> estudiantes[i].id;
		cout << "Ingrese los nombres del Estudiante: " << i + 1 << ": ";
		cin >> estudiantes[i].nombres;
		cout << "Ingese los apellidos del Estudiante: " << i + 1 << ": ";
		cin >> estudiantes[i].apellidos;
		estudiantes[i].notas = new float[4];
		for (int j = 0; j < 4; j++) {
			cout << "Ingrese la nota " << j + 1 << " para el estudiante " << i + 1 << ": ";
			cin >> estudiantes[i].notas[j];
		}
	}
	
	// Mostramos la información de los estudiantes y los resultados
	for (int i = 0; i < numEstudiantes; i++) {
		cout << "Estudiante: " << i + 1 << ":\n";
		cout << "ID: " << estudiantes[i].id << "\n";
		cout << "Nombres: " << estudiantes[i].nombres << "\n";
		cout << "Apellidos: " << estudiantes[i].apellidos << "\n";
		float average = calcularPromedio(estudiantes[i].notas);
		cout << "Promedio: " << average << "\n";
		string passFail = checkPass(average);
		cout << "Aprobado/No Aprobado: " << passFail << "\n\n";	 
	}
	
	//Borramos la memoria asignada dinamicamente
	for (int i = 0; i < numEstudiantes; i++){
		delete[] estudiantes[i].notas;
	}
	
	delete[] estudiantes;
	
	return 0;
}
