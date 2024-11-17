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

    while (!salir) {  // Bucle para repetir el menú
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Registrar camiones" << endl;
        cout << "2. Consultar datos de un camión por matrícula" << endl;
        cout << "3. Cargar o descargar un camión" << endl;
        cout << "4. Descargar un camión reduciendo su carga actual" << endl;
        cout << "5. Camión con menor consumo y capacidad suficiente para una carga dada" << endl;
        cout << "6. Informar si no hay camión disponible para una carga dada" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> pmenu;

        string matriculaBuscar; 
        string matriculaModificacion;
        bool encontrado; 
        double pesoCambio;
        char tipoOperacion;

        switch (pmenu) {
            case 1:
                // Registro de camiones
                for (int i = 0; i < 4; i++) {
                    cout << "\nIngrese los datos del camión " << i + 1 << ":" << endl;

                    cout << "Matrícula: ";
                    cin >> camiones[i].matricula;

                    do {
                        cout << "Capacidad de carga (kg): ";
                        cin >> camiones[i].capacidadCarga;
                        if (camiones[i].capacidadCarga <= 0) {
                            cout << "Error: La capacidad de carga debe ser positiva. Intente de nuevo." << endl;
                        }
                    } while (camiones[i].capacidadCarga <= 0);

                    do {
                        cout << "Consumo de gasolina (galones/km): ";
                        cin >> camiones[i].consumoGasolina;
                        if (camiones[i].consumoGasolina <= 0) {
                            cout << "Error: El consumo de gasolina debe ser positivo. Intente de nuevo." << endl;
                        }
                    } while (camiones[i].consumoGasolina <= 0);

                    do {
                        cout << "Carga actual (kg): ";
                        cin >> camiones[i].cargaActual;
                        if (camiones[i].cargaActual < 0) {
                            cout << "Error: La carga actual no puede ser negativa. Intente de nuevo." << endl;
                        } else if (camiones[i].cargaActual > camiones[i].capacidadCarga) {
                            cout << "Error: La carga actual no puede exceder la capacidad máxima del camión. Intente de nuevo." << endl;
                        }
                    } while (camiones[i].cargaActual < 0 || camiones[i].cargaActual > camiones[i].capacidadCarga);

                    cout << "Camión registrado exitosamente.\n" << endl;
                }
                break;

            case 2:
                // Consultar datos de un camión por matrícula
                cout << "\nIngrese la matrícula del camión a buscar: ";
                cin >> matriculaBuscar;

                encontrado = false;
                for (int i = 0; i < 4; i++) {
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

            case 3:
                // Cargar o descargar un camión
                cout << "\nIngrese la matrícula del camión a modificar: ";
                cin >> matriculaModificacion;
                cout << "Ingrese 'C' para cargar o 'D' para descargar: ";
                cin >> tipoOperacion;
                cout << "Ingrese el peso de la carga en kg: ";

                do {
                    cin >> pesoCambio;
                    if (pesoCambio <= 0) {
                        cout << "Error: El peso debe ser positivo. Intente de nuevo: ";
                    }
                } while (pesoCambio <= 0);

                encontrado = false;
                for (int i = 0; i < 4; i++) {
                    if (camiones[i].matricula == matriculaModificacion) {
                        if (tipoOperacion == 'C' || tipoOperacion == 'c') {  
                            if (camiones[i].cargaActual + pesoCambio <= camiones[i].capacidadCarga) {
                                camiones[i].cargaActual += pesoCambio;
                                cout << "Carga agregada exitosamente. Carga actual: " << camiones[i].cargaActual << " kg" << endl;
                            } else {
                                cout << "Error: La carga excede la capacidad máxima." << endl;
                            }
                        } else if (tipoOperacion == 'D' || tipoOperacion == 'd') {  
                            if (camiones[i].cargaActual >= pesoCambio) {
                                camiones[i].cargaActual -= pesoCambio;
                                cout << "Descarga realizada exitosamente. Carga actual: " << camiones[i].cargaActual << " kg" << endl;
                            } else {
                                cout << "Error: La descarga excede la carga actual." << endl;
                            }
                        } else {
                            cout << "Operación no válida. Use 'C' o 'D'." << endl;
                        }
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Camión no encontrado." << endl;
                }
                break;

            case 4:
                // Descargar un camión reduciendo su carga actual a 0
                cout << "\nIngrese la matrícula del camión a descargar completamente: ";
                cin >> matriculaModificacion;

                encontrado = false;
                for (int i = 0; i < 4; i++) {
                    if (camiones[i].matricula == matriculaModificacion) {
                        camiones[i].cargaActual = 0;
                        cout << "La carga del camión con matrícula " << matriculaModificacion << " ha sido descargada completamente." << endl;
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "No se encontró ningún camión con la matrícula " << matriculaModificacion << "." << endl;
                }
                break;

            case 5:
                // Camión con menor consumo y capacidad suficiente para una carga dada
                double cargaRequerida;
                cout << "\nIngrese el peso de la carga a buscar (kg): ";
                cin >> cargaRequerida;

                Camion* mejorCamion = nullptr;
                for (int i = 0; i < 4; i++) {
                    if (camiones[i].capacidadCarga - camiones[i].cargaActual >= cargaRequerida) {
                        if (mejorCamion == nullptr || camiones[i].consumoGasolina < mejorCamion->consumoGasolina) {
                            mejorCamion = &camiones[i];
                        }
                    }
                }

                if (mejorCamion != nullptr) {
                    cout << "\nEl camión con menor consumo y capacidad suficiente es:" << endl;
                    cout << "Matrícula: " << mejorCamion->matricula << endl;
                    cout << "Capacidad de carga: " << mejorCamion->capacidadCarga << " kg" << endl;
                    cout << "Consumo de gasolina: " << mejorCamion->consumoGasolina << " galones/km" << endl;
                    cout << "Carga actual: " << mejorCamion->cargaActual << " kg" << endl;
                } else {
                    cout << "No hay ningún camión disponible con capacidad suficiente para esa carga." << endl;
                }
                break;
                
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
