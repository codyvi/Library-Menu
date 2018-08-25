#ifndef MATERIAL_H_
#define MATERIAL_H_

#include<string>

#include<iostream>

#include"Fecha.h"

#include"Material.h"

using namespace std;

class Material
{
	public:
		//Constructores
		Material();

		Material(int, string);

		//Getters
		int getId();

		string getTitulo();

		//Setters
		void setId(int);

		void setTitulo(string);

		//Métodos virtuales
		virtual void muestra() = 0;

		virtual int cantidadDeDiasDePrestamo() = 0;

	protected:
		int idMaterial;

		string sTitulo;
};

//Constructores
Material :: Material()
{
	sTitulo = "";

	idMaterial = 0;
}

Material :: Material(int idMaterial, string sTitulo)
{
	this->idMaterial = idMaterial;

	this->sTitulo = sTitulo;
}

//Getters
int Material :: getId()
{
	return idMaterial;
}

string Material :: getTitulo()
{
	return sTitulo;
}

//Setters
void Material :: setId(int idMaterial)
{
	this->idMaterial = idMaterial;
}

void Material :: setTitulo(string sTitulo)
{
	this->sTitulo = sTitulo;
}

#endif
