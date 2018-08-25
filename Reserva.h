#ifndef RESERVA_H_
#define RESERVA_H_

using namespace std;

#include"Fecha.h"
#include<iostream>
#include<string>

class Reserva
{
	public:
		Fecha calculaFechaFinReserva(int);

		//Setters
		void setMaterial(int);

		void setCliente(int);

		void setFechaReservacion(Fecha);


		//Getters
		int getMaterial();

		int getCliente();

		Fecha getFechaReservacion();

	private:
		int idMaterial;

		int idCliente;

		Fecha fechaReservacion;
};

Fecha Reserva :: calculaFechaFinReserva(int iDias)
{
	//Valor a regresar
	Fecha fFin;

	//Sumando todos los días
	int iDiaFin = fechaReservacion.getDia() + iDias;

	int iMesFin= fechaReservacion.getMes();

	int iYearFin = fechaReservacion.getYear();

	//Número de dias del mes actual
	int iNumDias;

	//Array para saber los días de un mes. Febrero puede ser modificado
	int iArrDias[12] = {31, 28, 31, 30, 31, 30,31,31,30,31,30,31};

	//Modificando si el año es bisiesto
	if(fechaReservacion.esBisiesto())
	{
		iArrDias[1]++;
	}

	//Obteniendo los dias del mes actual
	iNumDias = iArrDias[fechaReservacion.getMes() - 1];


	//Ejecutando cambios de mes si es necesario
	if(iDiaFin > iNumDias)
	{
		iDiaFin -= iNumDias;

		iMesFin++;

		//Ejecutando cambios de año si es necesario
		//13 es la única posibilidad de mayor a 12 en esta versión, debido a la
		//verificación en el main. De todas maneras se dejará "iMes > 12".
		if(iMesFin > 12)
		{
			iMesFin = 1;

			iYearFin++;
		}
	}

	//Modificando la fecha de fin
	fFin.setFecha(iDiaFin, iMesFin, iYearFin);

	//Devolviendo el objeto
	return fFin;
}

//Setters
void Reserva :: setCliente(int idCliente)
{
	this->idCliente = idCliente;
}

void Reserva :: setMaterial(int idMaterial)
{
	this->idMaterial = idMaterial;
}

void Reserva :: setFechaReservacion(Fecha fFecha)
{
	fechaReservacion = fFecha;
}

//Getters
int Reserva :: getCliente()
{
	return idCliente;
}

int Reserva :: getMaterial()
{
	return idMaterial;
}

Fecha Reserva :: getFechaReservacion()
{
	return fechaReservacion;
}
#endif
