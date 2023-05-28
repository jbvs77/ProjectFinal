#pragma once
#include <iostream>		


using namespace std;

class persona		
{

protected: 
	
	string nombre, compra;  
		 
		 

protected:	
	persona(){
	}

	
	persona(string nom, string com) {

		nombre = nom;
		compra = com;
	}
};