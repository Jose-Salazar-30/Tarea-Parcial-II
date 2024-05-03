#include <iostream>
#include <string>

using namespace std;

// funcion para calcular la nota media
float calculoMedio(float grades[4]){
	float sum = 0;
	for (int i = 0; i < 4; i++){
		sum += grades[i];
	}
	
	return sum / 4;
}

//Funcion para verificar si los estudiantes aprobaron
string checkPass(float average){
	if (average > 60) {
		return "Aprobado con mas de 60 puntos";
	} else {
		return "No has aprobado con mas de 60";
	}
}

int main() {
	int numEstudiantes;
	cout << "Ingrese el numero de estudiantes: ";
	cin >> numEstudiantes;
	
	//Creamos un array para guardar los datos de los estudiantes
	int id[numEstudiantes];
	string nombres[numEstudiantes];
	string apellidos[numEstudiantes];
	float materias[numEstudiantes][4];
	
	//Obtenemos la información de los estudiantes
	for (int i = 0; i < numEstudiantes; i++) {
		cout << "Ingrese el ID del estudiante " << i + 1 << ": ";
		cin >> id[i];
		cout << "Ingrese los nombres del estudiante " << i + 1 << ": ";
		cin >> nombres[i];
		cout << "Ingese los apellidos del estudiante " << i + 1 << ": ";
		cin >> apellidos[i];
		for (int j = 0; j < 4; j++){
			cout << "Ingrese la nota de la materia " << j + 1 << " para el estudiante " << i + 1 << ": ";
			cin >> materias[i][j];
		} 
	}
	
	// Mostramos la información de los estudiantes y los resultados
	for (int i = 0; i < numEstudiantes; i++) {
		cout << "Estudiante " << i + 1 << ":\n";
		cout << "ID: " << id[i] << "\n";
		cout << "Nombres: " << nombres[i] << "\n";
		cout << "Apellidos: " << apellidos[i] << "\n";
		float average = calculoMedio(materias[i]);
		cout << "Media: " << average << "\n";
		string passFail = checkPass(average);
		cout << "Aprobado/No Aprobado: " << passFail << "\n\n";
	}
	
	return 0;
}


