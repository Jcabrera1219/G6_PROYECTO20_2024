#include <iostream>
#include <string>
using namespace std;

struct Camion {
    string matricula;
    double capacidadCarga;
    double consumoGasolina;
    double cargaActual;
};

int main() {
    Camion camiones[4];  // Array de estructuras para almacenar los datos de los camiones
    int pmenu;
    
    cout << "1. Registrar un camion con su matricula, capacidad de carga, consumo de gasolina y carga actual" << endl;
    cout << "2. Consultar los datos de un camion a partir de su matricula " << endl;
    cout << "3. Cargar un camion verificando que no se exceda su capacidad maxima " << endl;
    cout << "4. Descargar un camion reduciendo su carga actual" << endl;
    cout << "5. El camion con menor consumo de gasolina que tenga capacidad de carga suficiente para una carga dada" << endl;
    cout << "6. Informar cuando no haya un camion disponible para transportar una carga dada" << endl;
    
    cout << "Digite la opcion que desee saber: ";
    cin >> pmenu;

    switch (pmenu) {
        case 1:
            // Registro de camiones
            for (int i = 0; i < 4; i++) {
                cout << "Ingrese los datos del camion " << i + 1 << endl;
                
                cout << "Matricula: ";
                cin >> camiones[i].matricula;
                
                cout << "Capacidad de carga (kg): ";
                cin >> camiones[i].capacidadCarga;
                
                cout << "Consumo de gasolina (galones/km): ";
                cin >> camiones[i].consumoGasolina;
                
                cout << "Carga actual (kg): ";
                cin >> camiones[i].cargaActual;
                
                cout << endl;
            }
            break;

        case 2:
            // Consultar los datos de un camión por su matrícula
            {
                string matriculaBuscar;
                cout << "Ingrese la matricula del camion a buscar: ";
                cin >> matriculaBuscar;
                bool encontrado = false;
                
                // Búsqueda del camión
                for (int i = 0; i < 4; i++) {
                    if (camiones[i].matricula == matriculaBuscar) {
                        cout << "Datos del camion con matricula " << matriculaBuscar << ":" << endl;
                        cout << "Capacidad de carga: " << camiones[i].capacidadCarga << " kg" << endl;
                        cout << "Consumo de gasolina: " << camiones[i].consumoGasolina << " galones/km" << endl;
                        cout << "Carga actual: " << camiones[i].cargaActual << " kg" << endl;
                        encontrado = true;
                        break;
                    }
                }
                
                if (!encontrado) {
                    cout << "No se encontró ningún camión con la matrícula " << matriculaBuscar << "." << endl;
                }
            }
            break;

        case 3:
            cout << "Resultado: " << endl;
            break;

        case 4:
            cout << "Resultado: " << endl;
            break;

        case 5:
            cout << "Resultado: " << endl;
            break;

        case 6:
            cout << "Resultado: " << endl;
            break;

        default:
            cout << "Operación no válida." << endl;
            break;
    }
    
    return 0;
}
