#ifndef SOFTWARE_H_
#define SOFTWARE_H_

#include<iostream>

#include<string>

#include"Material.h"

using namespace std;

class Software : public Material
{
	public:
		//Constructores
		Software(int, string, string);

		Software();

		//Getter
		string getSistemaOper();

		//Setter
		void setSistemaOper(string);

		//Sobreescribiendo
		void muestra();

		int cantidadDeDiasDePrestamo();

	private:
	string sSistemaOper;
};

//Constructores
Software :: Software(int idMaterial, string sTitulo, string sSistemaOper) : Material(idMaterial, sTitulo)
{
	this->sSistemaOper = sSistemaOper;
}

Software :: Software() : Material()
{
	sSistemaOper = "";
}

//Getter
string Software :: getSistemaOper()
{
	return sSistemaOper;
}

//Setter
void Software :: setSistemaOper(string sSistemaOper)
{
	this->sSistemaOper = sSistemaOper;
}

//Sobreescribiendo
void Software :: muestra()
{
	//tipo
	cout << "Tipo: " << "Software" << endl;
	//id
	cout << "ID: " << this->idMaterial << endl;

	//título
	cout << "Titulo: " << this-> sTitulo << endl;

	//sistemaOper
	cout << "SistemaOper: " << this->sSistemaOper << endl;
}

int Software :: cantidadDeDiasDePrestamo()
{
	return 1;
}


#endif
