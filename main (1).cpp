#include <iostream>

using namespace std;

string matricula[4];
    double capacidadCarga[4];
    double consumoGasolina[4];
    double cargaActual[4];
    
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
                do
                    cin >> camiones[i].cargaActual;
                while(camiones[i].cargaActual>camiones[i].capacidadCarga);                cout << endl;
            }
            break;

        case 2:
            // Consultar los datos de un camiÃ³n por su matrÃ­cula
            {
                string matriculaBuscar;
                cout << "Ingrese la matricula del camion a buscar: ";
                cin >> matriculaBuscar;
                bool encontrado = false;
                
                // BÃºsqueda del camiÃ³n
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
                    cout << "No se encontrÃ³ ningÃºn camiÃ³n con la matrÃ­cula " << matriculaBuscar << "." << endl;
                }
            }
            break;

        case 3:
            
            // Cargar un camion
            
            string cargarMatricula;
            double pesoCarga;
            cout << "Ingrese la matricula del camion a cargar: ";
            cin >> cargarMatricula;
            cout << "Ingrese el peso de la carga en kg: ";
            cin >> pesoCarga;

            bool encontrado = false;
            for (int i = 0; i < 4; i++) {
                if (matricula[i] == cargarMatricula) 
                {
                    if (cargaActual[i] + pesoCarga <= capacidadCarga[i]) {
                        cargaActual[i] += pesoCarga;
                        cout << "Carga agregada exitosamente. Carga actual: " << cargaActual[i] << " kg" << endl;
                    } else {
                        cout << "Error: La carga excede la capacidad maxima del camion." << endl;
                    }
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Camion no encontrado." << endl;
            }
        } if (opcion == 3) {
            // Encontrar el mejor camion disponible para una carga
            double pesoCarga;
            cout << "Ingrese el peso de la carga en kg: ";
            cin >> pesoCarga;

            int mejorCamion = -1;
            for (int i = 0; i < 4; i++) {
                if (pesoCarga <= capacidadCarga[i] - cargaActual[i]) {
                    if (mejorCamion == -1 || consumoGasolina[i] < consumoGasolina[mejorCamion]) {
                        mejorCamion = i;
                    }
                }
            }

            if (mejorCamion != -1) {
                cout << "El mejor camion para transportar la carga es el de matricula: " << matricula[mejorCamion] << endl;
                cout << "Capacidad restante: " << capacidadCarga[mejorCamion] - cargaActual[mejorCamion] << " kg" << endl;
                cout << "Consumo de gasolina: " << consumoGasolina[mejorCamion] << " galones/km" << endl;
            } else {
                cout << "No hay ningun camion disponible con la capacidad suficiente para esta carga." << endl;
            }
        }
    } 

    
            
            
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
            cout << "OperaciÃ³n no vÃ¡lida." << endl;
            
            break;
    }
    
    return 0;
}