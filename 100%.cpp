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
    bool salir = false;
    int camionesRegistrados = 0; // Llevar control de cuántos camiones se han registrado

    while (!salir) {  // Bucle para repetir el menú
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Registrar camiones" << endl;
        cout << "2. Consultar datos de un camión por matrícula" << endl;
        cout << "3. Cargar o descargar un camión" << endl;
        cout << "5. Camión con menor consumo y capacidad suficiente para una carga dada" << endl;
        cout << "6. Informar cuando no haya camión disponible para una carga dada" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> pmenu;

        // Declaración de variables para uso compartido en los `case`
        string matriculaBuscar;
        double cargaNecesaria;
        int mejorIndice = -1;

        switch (pmenu) {
            case 1: {
                // Registro de camiones
                if (camionesRegistrados >= 4) {
                    cout << "Ya se han registrado 4 camiones. No es posible agregar más." << endl;
                    break;
                }

                cout << "\nIngrese los datos del camión " << camionesRegistrados + 1 << ":" << endl;

                // Validación de matrícula única
                string nuevaMatricula;
                bool matriculaRepetida;
                do {
                    matriculaRepetida = false;
                    cout << "Matrícula: ";
                    cin >> nuevaMatricula;

                    for (int i = 0; i < camionesRegistrados; i++) {
                        if (camiones[i].matricula == nuevaMatricula) {
                            matriculaRepetida = true;
                            cout << "Error: Matrícula repetida. Intente con otra." << endl;
                            break;
                        }
                    }
                } while (matriculaRepetida);

                camiones[camionesRegistrados].matricula = nuevaMatricula;

                // Validación de la capacidad de carga
                do {
                    cout << "Capacidad de carga (kg): ";
                    cin >> camiones[camionesRegistrados].capacidadCarga;
                    if (camiones[camionesRegistrados].capacidadCarga <= 0) {
                        cout << "Error: La capacidad de carga debe ser un número positivo. Intente de nuevo." << endl;
                    }
                } while (camiones[camionesRegistrados].capacidadCarga <= 0);

                // Validación del consumo de gasolina
                do {
                    cout << "Consumo de gasolina (galones/km): ";
                    cin >> camiones[camionesRegistrados].consumoGasolina;
                    if (camiones[camionesRegistrados].consumoGasolina <= 0) {
                        cout << "Error: El consumo de gasolina debe ser un número positivo. Intente de nuevo." << endl;
                    }
                } while (camiones[camionesRegistrados].consumoGasolina <= 0);

                // Validación de la carga actual
                do {
                    cout << "Carga actual (kg): ";
                    cin >> camiones[camionesRegistrados].cargaActual;
                    if (camiones[camionesRegistrados].cargaActual < 0) {
                        cout << "Error: La carga actual no puede ser negativa. Intente de nuevo." << endl;
                    } else if (camiones[camionesRegistrados].cargaActual > camiones[camionesRegistrados].capacidadCarga) {
                        cout << "Error: La carga actual no puede exceder la capacidad máxima del camión. Intente de nuevo." << endl;
                    }
                } while (camiones[camionesRegistrados].cargaActual < 0 || camiones[camionesRegistrados].cargaActual > camiones[camionesRegistrados].capacidadCarga);

                cout << "Camión registrado exitosamente.\n" << endl;
                camionesRegistrados++;
                break;
            }

            case 2: {
                // Consultar datos de un camión por matrícula
                cout << "\nIngrese la matrícula del camión a buscar: ";
                cin >> matriculaBuscar;

                bool encontrado = false;
                for (int i = 0; i < camionesRegistrados; i++) {
                    if (camiones[i].matricula == matriculaBuscar) {
                        cout << "\nDatos del camión con matrícula " << matriculaBuscar << ":" << endl;
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

            case 5: {
                // Camión con menor consumo y capacidad suficiente para una carga dada
                if (camionesRegistrados == 0) {
                    cout << "No hay camiones registrados." << endl;
                    break;
                }

                cout << "\nIngrese la carga necesaria (kg): ";
                cin >> cargaNecesaria;

                if (cargaNecesaria <= 0) {
                    cout << "Error: La carga debe ser un número positivo." << endl;
                    break;
                }

                for (int i = 0; i < camionesRegistrados; i++) {
                    if (camiones[i].capacidadCarga - camiones[i].cargaActual >= cargaNecesaria) {
                        if (mejorIndice == -1 || camiones[i].consumoGasolina < camiones[mejorIndice].consumoGasolina) {
                            mejorIndice = i;
                        }
                    }
                }

                if (mejorIndice != -1) {
                    cout << "El camión con menor consumo adecuado para la carga de " << cargaNecesaria << " kg es:" << endl;
                    cout << "Matrícula: " << camiones[mejorIndice].matricula << endl;
                    cout << "Consumo: " << camiones[mejorIndice].consumoGasolina << " galones/km" << endl;
                } else {
                    cout << "No hay camiones con capacidad suficiente para la carga de " << cargaNecesaria << " kg." << endl;
                }
                break;
            }

            case 6: {
                // Informar cuando no haya camión disponible para una carga dada
                if (camionesRegistrados == 0) {
                    cout << "No hay camiones registrados." << endl;
                    break;
                }

                cout << "\nIngrese la carga necesaria (kg): ";
                cin >> cargaNecesaria;

                if (cargaNecesaria <= 0) {
                    cout << "Error: La carga debe ser un número positivo." << endl;
                    break;
                }

                bool hayCamionDisponible = false;
                for (int i = 0; i < camionesRegistrados; i++) {
                    if (camiones[i].capacidadCarga - camiones[i].cargaActual >= cargaNecesaria) {
                        hayCamionDisponible = true;
                        break;
                    }
                }

                if (!hayCamionDisponible) {
                    cout << "No hay camiones disponibles para transportar una carga de " << cargaNecesaria << " kg." << endl;
                } else {
                    cout << "Sí hay camiones disponibles para esta carga." << endl;
                }
                break;
            }

            case 0:
                // Salir del programa
                salir = true;
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    }

    return 0;
}
