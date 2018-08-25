#ifndef DISCO_H_
#define DISCO_H_

#include<iostream>

#include<string>

#include "Material.h"

using namespace std;

class Disco : public Material
{
	public:
		//Constructores
		Disco(int, string, int);

		Disco();

		//Setter
		void setDuracion(int);

		//Getter
		int getDuracion();

		//Sobreescribiendo
		void muestra();

		int cantidadDeDiasDePrestamo();

	private:
		int iDuracion;
};

//constructores
Disco :: Disco(int idMaterial, string sTitulo, int iDuracion) : Material(idMaterial, sTitulo)
{
	this->iDuracion = iDuracion;
}

Disco :: Disco()
{
	iDuracion = 0;
}

//getter
int Disco :: getDuracion()
{
	return iDuracion;
}

//setter
void Disco :: setDuracion(int iDuracion)
{
	this->iDuracion = iDuracion;
}

//Sobreescribiendo
void Disco :: muestra()
{
	//tipo
	cout << "Tipo: " << "Disco" << endl;

	//id
	cout << "ID: " << this->idMaterial << endl;

	//título
	cout << "Titulo: " << this-> sTitulo << endl;

	//sistemaOper
	cout << "Duracion: " << this->iDuracion << endl;
}

int Disco :: cantidadDeDiasDePrestamo()
{
	return 3;
}

#endif
