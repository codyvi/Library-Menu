#ifndef FECHA_H_
#define FECHA_H_

using namespace std;

#include<iostream>
#include<string>

class Fecha
{
	public:
		//Constructores
		Fecha(int, int, int);

		Fecha();

		//Getters
		int getDia();

		int getMes();

		int getYear();

		//Setters
		void setDia(int);

		void setMes(int);

		void setYear(int);

		//Métodos

		//Método para cambiar en orden, día, mes y año con un solo llamado
		void setFecha(int, int, int);


		//Regresa true si el año es bisiesto, si no lo es, false
		bool esBisiesto();

		//Regresa un string con el nombre del mes según el número
		string nombreMes();


		//Sobrecarga de operadores
		Fecha operator+(int);

		bool operator>=(Fecha);

		friend bool operator<=(Fecha, Fecha);

		bool operator>(Fecha);

		friend bool operator<(Fecha, Fecha);

		bool operator==(Fecha);

	   	 //cout <<
		friend ostream& operator<<(ostream &ost, Fecha fFecha);
		//cin >>
		friend istream& operator>>(istream &ist, Fecha &fFecha);


	private:
		int iDia;
		int iMes;
		int iYear;


};

Fecha :: Fecha(int iDia, int iMes, int iYear)
{
	this->iDia = iDia;

	this->iMes = iMes;

	this->iYear = iYear;
}

Fecha :: Fecha()
{
	//Inicializando valores
	iDia = 0;

	iMes = 0;

	iYear = 0;
}

//Getters
int Fecha :: getDia()
{
	return iDia;
}

int Fecha :: getMes()
{
	return iMes;
}

int Fecha :: getYear()
{
	return iYear;
}

//Setters
void Fecha :: setDia(int iDia)
{
	this->iDia = iDia;
}

void Fecha :: setMes(int iMes)
{
	this->iMes = iMes;
}

void Fecha :: setYear(int iYear)
{
	this->iYear = iYear;
}

//Métodos
void Fecha :: setFecha(int iDia, int iMes, int iYear)
{
	this->setDia(iDia);

	this->setMes(iMes);

	this->setYear(iYear);
}
string Fecha :: nombreMes()
{
	//string para almacenar el valor del retorno
	string sMes;

	//Buscando el resultado deseado
	if(iMes == 1)
	{
		sMes = "Ene";
	}

	else if(iMes == 2)
	{
		sMes = "Feb";
	}

	else if(iMes == 3)
	{
		sMes == "Mar";
	}

	else if(iMes == 4)
	{
		sMes == "Abr";
	}

	else if(iMes == 5)
	{
		sMes == "May";
	}

	else if(iMes == 6)
	{
		sMes = "Jun";
	}

	else if(iMes == 7)
	{
		sMes = "Jul";
	}

	else if(iMes == 8)
	{
		sMes = "Ago";
	}

	else if(iMes == 9)
	{
		sMes = "Sep";
	}

	else if(iMes == 10)
	{
		sMes = "Oct";
	}

	else if(iMes == 11)
	{
		sMes = "Nov";
	}

	else if(iMes == 12)
	{
		sMes = "Dic";
	}

	//Devolver el nombre del mes
	return sMes;
}

bool Fecha :: esBisiesto()
{
	//Variable a retornar
	bool bJudge;

	//Si es divisible entre 4
	if(iYear % 4 == 0)
	{
		//Es bisiesto
		bJudge = 1;
	}

	//Si no
	else
	{
		//No lo es
		bJudge = 0;
	}

	//Devolver el valor
	return bJudge;
}

//Sobrecarga de operadores
Fecha Fecha :: operator+(int iDia)
{
	Fecha fFecha(this->iDia + iDia, iMes, iYear);

	//Array para saber los días de un mes. Febrero puede ser modificado
	int iArrDias[12] = {31, 28, 31, 30, 31, 30,31,31,30,31,30,31};

	//Si es bisiesto, cambia el calendaro
	if(fFecha.esBisiesto())
	{
		iArrDias[1]++;
	}

	//Si sobrepasa los días permitidos
	if(iDia > iArrDias[iMes - 1])
	{
		//ajusta
		fFecha.iDia -= iArrDias[iMes - 1];

		fFecha.iMes++;

		//Si se pasa del último día del año
		if(iMes > 12)
		{
			//Empieza en el siguiente
			iMes = 1;

			iYear++;
		}


	}

	return fFecha;
}

bool Fecha :: operator>=(Fecha fFecha)
{
	//Valor a regresar
	bool bJudge;

	if(iYear > fFecha.iYear)
	{
		bJudge = 1;
	}

	else if(iYear == fFecha.iYear)
	{
		if(iMes > fFecha.iMes || fFecha.iMes == iMes && iDia >= fFecha.iDia)
		{
			bJudge = 1;
		}

		else
		{
			bJudge = 0;
		}
	}

	else
	{
		bJudge = 0;
	}

	//Regresando el valor
	return bJudge;
}

bool operator<=(Fecha fFecha1, Fecha fFecha2)
{
	//Valor a regresar
	bool bJudge;

	if(fFecha1.iYear < fFecha2.iYear)
	{
		bJudge = 1;
	}

	else if(fFecha1.iYear == fFecha2.iYear)
	{
		if(fFecha1.iMes < fFecha2.iMes || fFecha1.iMes == fFecha2.iMes && fFecha1.iDia <= fFecha2.iDia)
		{
			bJudge = 1;
		}

		else
		{
			bJudge = 0;
		}
	}

	else
	{
		bJudge = 0;
	}

	//Regresando el valor
	return bJudge;
}

bool Fecha :: operator>(Fecha fFecha)
{
	//Variable a regresar
	bool bJudge;

	if(iYear > fFecha.iYear)
	{
		bJudge = 1;
	}

	else if(iYear == fFecha.iYear)
	{
		if(iMes > fFecha.iMes || iMes == fFecha.iMes && iDia > fFecha.iYear)
		{
			bJudge = 1;
		}

		else
		{
			bJudge = 0;
		}
	}

	else
	{
		bJudge = 0;
	}

	//Regresando la variable
	return bJudge;
}

bool operator<(Fecha fFecha1, Fecha fFecha2)
{
	//Variable a regresar
	bool bJudge;

	if(fFecha1.iYear < fFecha2.iYear)
	{
		bJudge = 1;
	}

	else if(fFecha1.iYear == fFecha2.iYear)
	{
		if(fFecha1.iMes < fFecha2.iMes || fFecha1.iMes == fFecha2.iMes && fFecha1.iDia < fFecha2.iDia)
		{
			bJudge = 1;
		}

		else
		{
			bJudge = 0;
		}
	}

	else
	{
		bJudge = 0;
	}

	//Regresando variable
	return bJudge;
}

bool Fecha :: operator==(Fecha fFecha)
{
	//Variable a regresar
	bool bJudge;

	if(iDia == fFecha.iDia && iMes == fFecha.iMes && iYear == fFecha.iYear)
	{
		bJudge = 1;
	}

	else
	{
		bJudge = 0;
	}

	//Regresando la variable
	return bJudge;
}

	//Definición método cin >>
istream& operator>> (istream &ist, Fecha &fFecha)
{
	ist >> fFecha.iDia;

	ist >> fFecha.iMes;

	ist >> fFecha.iYear;

	return ist;
}

ostream& operator<<(ostream &ost, Fecha fFecha)
{
	ost << fFecha.iDia << "/" << fFecha.nombreMes() << "/" << fFecha.iYear;

	return ost;
}



#endif
