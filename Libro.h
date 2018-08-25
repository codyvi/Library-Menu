#ifndef LIBRO_H_
#define LIBRO_H_

#include<iostream>

#include<string>

#include"Material.h"

using namespace std;

class Libro : public Material
{
	public:
		Libro(int, string, int, string);

		Libro();

		//Getters
		int getNumPag();

		string getAutor();

		//Setters
		void setNumPag(int);

		void setAutor(string);

		//Sobreescribiendo métodos
		void muestra();

		//Devuelve el valor
		int cantidadDeDiasDePrestamo();

	private:
		int iNumPag;

		string sAutor;

};

//Constructores
Libro :: Libro(int idMaterial, string sTitulo, int iNumPag, string sAutor) : Material(idMaterial, sTitulo)
{
	this->iNumPag = iNumPag;

	this->sAutor = sAutor;
}

Libro :: Libro() : Material()
{
	iNumPag = 0;

	sAutor = "";
}

//Getters
int Libro :: getNumPag()
{
	return iNumPag;
}

string Libro :: getAutor()
{
	return sAutor;
}

//Setters
void Libro :: setNumPag(int iNumPag)
{
	this->iNumPag = iNumPag;
}

void Libro :: setAutor(string sAutor)
{
	this->sAutor = sAutor;
}

//Sobreescribiendo métodos
void Libro :: muestra()
{
	//tipo
	cout << "Tipo: " << "Libro" << endl;
	//id
	cout << "ID: " << this->idMaterial << endl;

	//título
	cout << "Titulo: " << this-> sTitulo << endl;

	//numpag
	cout << "Numero de pagina: " << this->iNumPag << endl;

	//autor
	cout << "Autor: " << this->sAutor << endl;
}

int Libro :: cantidadDeDiasDePrestamo()
{
	int iDias = 10;

	return iDias;
}


#endif

