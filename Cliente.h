#pragma once
#include <mysql.h>		
#include <iostream>		
#include <string>		
#include "ConexionBD.h"	
#include "persona.h"	
#include <mysql_driver.h>

using namespace std;



class cliente : persona {
				   
public:	
			
	cliente() {

	}	
	cliente(string nom, string com) : persona(nom, com) {
		
	}

	void setNombres(string nom) { nombre = nom; }
	void setCompra(string com) { compra = com; }	

	string getNombre() { return nombre; }
	string getCompra() { return compra; }

	void crear() {
		int result;
		ConexionBD cn = ConexionBD();
				
		cn.abrir_conexion();		

		if (cn.getConectar()) {		
			string vQuery = "INSERT INTO clientes(nombreCliente,montoCliente)VALUES('" + nombre + "','" + compra + "');";
			
			const char* a1 = vQuery.c_str();

			result = mysql_query(cn.getConectar(), a1);
			
			if (!result) {

				cout << "Added successfully" << endl;
			}
			else
			{
				cout << "Not able to add cause: " << mysql_error(cn.conectar)<< endl;
			}
		}
		else {
			cout << "Conection issues" << endl;

		}
		cn.cerrar_conexion();		
	}

	void readD()
	{
		int dbConfirm;
		ConexionBD cn = ConexionBD();
		
		MYSQL_ROW row;
		MYSQL_RES* result;

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string ask = "select * from clientes";
			const char* a = ask.c_str();
			dbConfirm = mysql_query(cn.getConectar(), a);

			if (!dbConfirm)
			{
				result = mysql_store_result(cn.getConectar());
				//mostrar datos en pantalla por medio de la consulta				
				cout << "ID                      Nombre                                            Compra Realizada" << endl;
				while (row = mysql_fetch_row(result))
				{
					cout << row[0] << "                              " << row[1] << "                                                " << row[2] << endl;
				}
			}
			else
			{
				cout << "Not able to fetch cause: " << mysql_error(cn.conectar) << endl;
			}

			//aca el codigo
		}
		else {
			cout << "Conection issues" << endl;
		}

		cn.cerrar_conexion();
	}
};