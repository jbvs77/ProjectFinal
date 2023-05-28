#pragma once
#include <mysql.h>     
#include <iostream>    
using namespace std;
class ConexionBD {
   
public:
	MYSQL* conectar;

	
	void abrir_conexion() {

		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "admin1", "db_empresa", 3306, NULL, NULL);
	}
	


	MYSQL* getConectar() {
		return  conectar;
	}
	
	void cerrar_conexion() {
		mysql_close(conectar);
	}
};