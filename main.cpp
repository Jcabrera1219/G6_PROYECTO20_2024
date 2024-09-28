#include <iostream>
using namespace std;

int main()
{
    string matricula[4];
    double capacidadCarga[4];
    double consumoGasolina[4];
    double cargaActual[4];
    int pmenu;
    cout << "1.Registrar un camion con su matricula, capacidad de carga, consumo de gasolina y carga actual" <<endl;
     cout << "2. consultar los datos de un camion a partir de su matricula " <<endl;
      cout << "3. cargar un camion verificando que no se exceda su capasidad maxima " <<endl;
       cout << "4. descargar un camion reduciendo su carga actual" <<endl;
        cout << "5. El camion con menor consumo de gasolina que tenga capacidad de carga suficiente para una carga dada" <<endl;
         cout << "6. Informar cuando no alla un camion disponible para trasportar una carga dada  " <<endl;

          cout<<"digite la opcion que desee saber ";
          cin>>pmenu;
            
    do
    {
     switch (pmenu) {
        case 1:
             
    for (int i = 0; i < 4; i++) {
        cout << "Ingrese los datos del camion " << i + 1 << endl;
        
        cout << "Matricula: ";
        cin >> matricula[i];

        cout << "Capacidad de carga (kg): ";
        cin >> capacidadCarga[i];

        cout << "Consumo de gasolina (galones/km): ";
        cin >> consumoGasolina[i];

        cout << "Carga actual (kg): ";
        cin >> cargaActual[i];

        cout << endl;
    }

    cout << "Informacion de los camiones:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Camion " << i + 1 << ": " << endl;
        cout << "Matricula: " << matricula[i] << endl;
        cout << "Capacidad de carga: " << capacidadCarga[i] << " kg" << endl;
        cout << "Consumo de gasolina: " << consumoGasolina[i] << " galones/km" << endl;
        cout << "Carga actual: " << cargaActual[i] << " kg" << endl;
        cout << endl;
    }
            break;
        case 2:
            cout << "Resultado: " << endl;
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
        case 7:
            cout << "Resultado: " << endl;
            break;    
        default:
            cout << "Operación no válida." << endl;
            break;
            
     }   
     return 1;
     
    }
    while(pmenu > 7);
    
   
}