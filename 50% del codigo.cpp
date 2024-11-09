#include <iostream>
using namespace std;

struct Camion {
    string matricula;
    double capacidadCarga;
    double consumoGasolina;
    double cargaActual;
};

int main() {
    Camion camiones[4];  
    int pmenu;

    cout << "1. Registrar un camion con su matricula, capacidad de carga, consumo de gasolina y carga actual" << endl;
    cout << "2. Consultar los datos de un camion a partir de su matricula" << endl;
    cout << "3. Cargar o descargar un camion verificando los límites de capacidad" << endl;
    cout << "4. Descargar un camion reduciendo su carga actual" << endl;
    cout << "5. El camion con menor consumo de gasolina que tenga capacidad de carga suficiente para una carga dada" << endl;
    cout << "6. Informar cuando no haya un camion disponible para transportar una carga dada" << endl;
    
    cout << "Digite la opcion que desee: ";
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
                do {
                    cin >> camiones[i].cargaActual;
                    if (camiones[i].cargaActual > camiones[i].capacidadCarga) {
                        cout << "Error: La carga actual no puede exceder la capacidad máxima del camión." << endl;
                    }
                } while (camiones[i].cargaActual > camiones[i].capacidadCarga);
                
                cout << endl;
            }
            break;

        case 2: {
            // Consultar los datos de un camión por su matrícula
            string matriculaBuscar;
            cout << "Ingrese la matricula del camion a buscar: ";
            cin >> matriculaBuscar;
            bool encontrado = false;
            
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
            break;
        }

        case 3: {
            // Cargar o descargar un camión
            string matriculaModificacion;
            double pesoCambio;
            char tipoOperacion;

            cout << "Ingrese la matricula del camion a modificar: ";
            cin >> matriculaModificacion;
            cout << "Ingrese 'C' para cargar o 'D' para descargar: ";
            cin >> tipoOperacion;
            cout << "Ingrese el peso de la carga en kg: ";
            cin >> pesoCambio;

            bool encontrado = false;
            for (int i = 0; i < 4; i++) {
                if (camiones[i].matricula == matriculaModificacion) {
                    if (tipoOperacion == 'C' || tipoOperacion == 'c') { // Cargar
                        if (camiones[i].cargaActual + pesoCambio <= camiones[i].capacidadCarga) {
                            camiones[i].cargaActual += pesoCambio;
                            cout << "Carga agregada exitosamente. Carga actual: " << camiones[i].cargaActual << " kg" << endl;
                        } else {
                            cout << "Error: La carga excede la capacidad máxima del camión." << endl;
                        }
                    } else if (tipoOperacion == 'D' || tipoOperacion == 'd') { // Descargar
                        if (camiones[i].cargaActual >= pesoCambio) {
                            camiones[i].cargaActual -= pesoCambio;
                            cout << "Descarga realizada exitosamente. Carga actual: " << camiones[i].cargaActual << " kg" << endl;
                        } else {
                            cout << "Error: La descarga excede la carga actual del camión." << endl;
                        }
                    } else {
                        cout << "Operación no válida. Use 'C' para cargar o 'D' para descargar." << endl;
                    }
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Camion no encontrado." << endl;
            }
            break;
        }

        default:
            cout << "Operacion no valida." << endl;
            break;
                    case 5:
            cout << "Resultado: " << endl;
            break;

        case 6:
            cout << "Resultado: " << endl;
            break;

        
    }
    
    

    return 0;
}
