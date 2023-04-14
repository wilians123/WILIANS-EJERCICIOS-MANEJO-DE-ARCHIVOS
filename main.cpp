#include <iostream>
#include <fstream>
#include <string>
#include "filesystem"
#include <windows.h>

using namespace std;

int main() {
  int n;
  string nombre;
  int edad;

  string direccion = "C:/Users/HUAWEI/Desktop";

  cout << "Cuantos archivos quieres crear" << endl;
  cin >> n;

  cout << "Cual es tu nombre" << endl;
  cin >> nombre;

  cout << "Cual es tu edad" << endl;
  cin >> edad;

  for (int i = 1; i <= n; i++) {
    string archivo = "Archivo" + to_string(i) + ".lsx";
    string ruta = direccion + "/" + archivo;
    ofstream salida(ruta);

    if (salida.is_open()) {
      salida << "Nombre: " << nombre << endl;
      salida << "Edad: " << edad << endl;
      salida.close(); // cerrar el archivo
      cout << "Se creo el archivo " << archivo << endl;
      ShellExecute(NULL, "open", ruta.c_str(), NULL, NULL, SW_SHOWNORMAL);
    }

    else {
      cout << "No se pudo crear el archivo " << archivo << endl;
    }
  }

  return 0;
}