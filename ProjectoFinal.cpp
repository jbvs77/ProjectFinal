/* Standard C++ includes */
#include <iostream>
#include <stdlib.h>     


/*C++ libraries from sample */
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

/*others*/
#include <mysql.h>
#include <Windows.h>
#include "cliente.h"        
#include "Deudor.h"
#include "ConexionBD.h"     
#include <stdlib.h>     




using namespace std;

int main()
{    

    
    
    void addD();
    void conexcionBD();
    void callRead();
    void addDeudor();
    void readDeudor();


    int opc = 0, exit, opc2 = 0; 
    
    do
    {        
        conexcionBD();           
        cout << "1. Clientes" << endl;
        cout << "2. Deudores" << endl;
        cout << "3. Existencias" << endl;
        cout << "4. Salir Programa" << endl;
        cout << "Opcion: " << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << "\nClientes -------\n" << endl;
            cout << "1. Ingreso" << endl;
            cout << "2. Consulta" << endl;
            cout << "3. Regresar" << endl;
            cout << "Opcion: " << endl;
            cin >> opc2;
            system("cls");
            do
            {
                switch (opc2)
                {
                case 1:
                    cout << "\nINGRESO CLIENTES --------------------------------------\n" << endl;
                    addD();
                    break;
                case 2:
                    cout << "\n CONSULTA CLIENTES --------------------------------------\n" << endl;                    
                    callRead();
                    system("pause");
                    break;
                case 3:                    
                    return main();
                    break;

                default:                    
                    cout << "__________________FUERA DE RANGO_________________" << endl;
                    break;
                }
            } while (opc2>=4 || opc2 <=0);
            break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 2:
            cout << "\n DEUDORES -------\n" << endl;
            cout << "1. Ingreso" << endl;
            cout << "2. Consulta" << endl;
            cout << "3. Regresar" << endl;
            cout << "Opcion: " << endl;
            cin >> opc2;
            system("cls");
            do
            {
                switch (opc2)
                {
                case 1:
                    cout << "\nINGRESO DEUDORES --------------------------------------\n" << endl;
                    addDeudor();
                    system("pause");
                    break;
                case 2:
                    cout << "\n CONSULTA DEUDORES --------------------------------------\n" << endl;
                    readDeudor();
                    system("pause");
                    break;
                case 3:
                    return main();
                    break;

                default:
                    cout << "Fuera de rango !!!! " << endl;
                    break;
                }
            } while (opc2 >=4 || opc2<=0);
            break;

        case 3: 
            break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 4:
            cout << "Seguro queres salir del programa...\n" << endl;
            cout << "1. Si" << endl;
            cout << "2. No" << endl;
            cin >> exit;
            if (exit == 1)
            {
                return 0;
            }
            else
            {
                system("cls");
                return main();
            }

            break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        default:
            cout << "__________________FUERA DE RANGO_________________" << endl;
            break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////
        }

    } while (opc>=4 || opc <=0);

    return 0;
}

void addD() {
    string nombre, montoCliente;    
   
    cout << "Ingrese Nombre: " << endl;
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese monto: " << endl;
    getline(cin, montoCliente);
    cin.ignore();
    
    cliente c = cliente(nombre, montoCliente);
    c.crear();
}

void conexcionBD() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "admin1", "db_empresa", 3306, NULL, 0);
    if (conectar)
    {
        system("color a");
    }
    else {
        system("color c");
    }
}


void callRead() {
    cliente c = cliente();
    c.readD();
}

void addDeudor() {
    string nombre, montoDeudor;

    cout << "Ingrese Nombre: " << endl;
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese monto: " << endl;
    getline(cin, montoDeudor);
    cin.ignore();
    debt i = debt(nombre, montoDeudor);
    i.crear();
}

void readDeudor() {
    debt i = debt();
    i.readD();
}







