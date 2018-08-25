/*
    Proyecto 3
    Sistema de Biblioteca que muestra un menu con 7 opciones
    para ver reservaciones, materiales, fechas y demas
    David Alonso Cantu Mtz
    A00822455
    Version 1.0
*/

#include"Fecha.h"
#include"Reserva.h"
#include"Material.h"
#include"Disco.h"
#include"Libro.h"
#include"Software.h"

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//Cargar los materiales del txt al arreglo
void cargarMaterial(ifstream &fMaterial, Material *arrMaterial[], int &iContador, char arrCharTipo[])
{
	//Variables para guardar datos
	int iId;

	string sTitulo;

	char cTipo;

	string sContenedor;

	int iContenedor;

	//Cargando el ID del material
	while(fMaterial >> iId)
	{
		//Cargando el título del material
		fMaterial >> sTitulo;

		//Cargando el tipo del material
		fMaterial >> cTipo;

		//Guardando el tipo en el array
		arrCharTipo[iContador] = cTipo;

		//Si es un libro
		if(cTipo == 'L')
		{
			//Carga número de página
			fMaterial >> iContenedor;

			//Carga autor
			fMaterial >> sContenedor;

			//Mandar al arreglo de materiales
			arrMaterial[iContador] = new Libro(iId, sTitulo, iContenedor, sContenedor);
		}

		//Si es un disco
		else if(cTipo == 'D')
		{
			//Carga duración
			fMaterial >> iContenedor;

			//Mandar al objeto de materiales
			arrMaterial[iContador] = new Disco(iId, sTitulo, iContenedor);
		}

		//Si es un software
		else if(cTipo == 'S')
		{
			//Carga sistema operativo
			fMaterial >> sContenedor;

			//Mandar al objeto de materiales
			arrMaterial[iContador] = new Software(iId, sTitulo, sContenedor);
		}

		//Incrementando el contador
		iContador++;
	}

}

//Void para cargar las reservas del .txt a un arreglo de reservas
void cargarReserva(ifstream &fReserva, Reserva arrReserva[], int &iContador)
{
	//Creando el objeto de tipo reserva
	Reserva rReserva;

	//Creando objeto tipo fecha
	Fecha fFecha;

	//Variables para guardar datos del archivo
	int iDia;

	int iMes;

	int iYear;

	int iIdMaterial;

	int iIdCliente;

	//Obteniendo los datos
	while(fReserva >> iDia)
	{
		fReserva >> iMes >> iYear >> iIdMaterial >> iIdCliente;

		//Asignando los valores
		rReserva.setMaterial(iIdMaterial);

		rReserva.setCliente(iIdCliente);

		fFecha.setFecha(iDia, iMes, iYear);

		rReserva.setFechaReservacion(fFecha);


		//Agregando al array
		arrReserva[iContador] = rReserva;

		//Incrementando el contador
		iContador++;
	}
}

//void que muestra el menú al usuario
void desplegarMenu()
{
	cout << "Entre alguna de las siguientes opciones para realizar la actividad"<< endl;

	cout << "A. Consultar los materiales disponibles" << endl;

	cout << "B. Mostrar todas las reservaciones" << endl;

	cout << "C. Mostrar las reservaciones de un material" << endl;

	cout << "D. Mostrar materiales en reserva en una fecha dada" << endl;

	cout << "E. Hacer una reservacion" << endl;

	cout << "F. Presione F para terminar y guardar los datos" << endl;

	cout << "Seleccione una opcion: ";
}

/*
	Función que devuelve true si existe un material dado su ID, falso si no

	Parámetros:
		iContador		Contador de materiales
		iId			ID del material a buscar
		*arrMaterial[]		Arreglo de apuntadores de materiales

	Returns:
		true o false
*/
bool validarMaterial(int iContador, int iId, Material *arrMaterial[])
{
	//Variable a regresar
	bool bJudge = 0;

	//Checando cada material
	for(int i = 0; i < iContador; i++)
	{
		//Si se encuentra
		if(arrMaterial[i]->getId() == iId)
		{
			//Hacer true la booleana
			bJudge = !(bJudge);

			//detener el ciclio
			i = iContador;
		}
	}

	//Devolviendo la variable
	return bJudge;
}

/*
	Función que recibe una fecha e informa al usuario si es o no válida
	y el porqué

	Parámetros:
		fFecha		Fecha a validar

	Return
		bJudge		Dicta si la fecha es o no válida
*/
bool validarFecha(Fecha fFecha)
{
	//Variable a regresar
	bool bJudge = 1;

	//Array para saber los días de un mes. Febrero puede ser modificado
	int iArrDias[12] = {31, 28, 31, 30, 31, 30,31,31,30,31,30,31};

	//Modificando si el año es bisiesto
	if(fFecha.esBisiesto())
	{
		iArrDias[1]++;
	}

	//Si ingresó más de un 12 en el mes
	if(fFecha.getMes() > 12)
	{
		//Informa al usuario
		cout << "Ese mes es inexistente, ingrese la fecha de nuevo, porfavor: ";


		//Haciendo falsa la condición
		bJudge = 0;
	}

	//Si el mes no tiene tantos días
	else if(fFecha.getDia() > iArrDias[fFecha.getMes() - 1])
	{
		//Informa al usuario
		cout << "Ese mes solo tiene " << iArrDias[fFecha.getMes() - 1] << " dias, favor de ingresar una cantidad valida: ";

		//Haciendo falsa la condición
		bJudge = 0;
	}

	//Si ingresó algún número negativo o cero
	else if(fFecha.getDia() < 1 || fFecha.getMes() < 1 || fFecha.getYear() < 1 )
	{
		//Informa al usuario
		cout << "Porfavor ingrese numeros positivos: ";


		//Haciendo falsa la condición
		bJudge = 0;
	}

	//Regresando el valor
	return bJudge;

}

//Void para mostrar los atributos de todos los materiales
void mostrarMateriales(int iContador, char arrCharTipo[], Material *arrMaterial[])
{
	//Para cada material muestra sus datos
	for(int i = 0; i < iContador; i++)
	{
		arrMaterial[i]->muestra();

		cout << endl;
	}
}

//Función que recibe un ID y envía el index de dicho material en el arreglo de apuntador de materiales
int idPorIndex(int iId, int iCantMat, Material *arrMaterial[])
{
	//Variable a retornar
	int iIndex;

	//Recorriendo todos los materiales
	for(int i = 0; i < iCantMat; i++)
	{
		//Si en cuentras el index del ID dado
		if(iId == arrMaterial[i]->getId())
		{
			//Guárdalo
			iIndex = i;

			//Detén en ciclio
			i = iCantMat;
		}
	}

	//Regresando la variable
	return iIndex;
}

//Void para mostrar todas las reservas y sus datos
void mostrarReservas(int iContadorReserva, int iCantMat, Reserva arrReserva[], Material *arrMaterial[])
{
	//Index del objeto en cuestión
	int iIndex;

	//Para cada reserva
	for(int i = 0; i < iContadorReserva; i++)
	{
		iIndex = idPorIndex(arrReserva[i].getMaterial(), iCantMat, arrMaterial);

		//Muestra su fecha de entrada
		cout << "Reserva: " << arrReserva[i].getFechaReservacion() << endl;

		//Su fecha de salida
		cout << "Fin de Reserva: " << arrReserva[i].calculaFechaFinReserva(arrMaterial[iIndex]->cantidadDeDiasDePrestamo()) << endl;

		//El cliento que reservó
		cout << "ID del cliente: " << arrReserva[i].getCliente() << endl;

		//El nombre del material
		cout << "Nombre del material: " << arrMaterial[iIndex]->getTitulo() << endl << endl;
	}
}

//Void para mostrar las reservas de un material dado
void mostrarReservasPorMaterial(int iContadorReserva, int iCantMat, int iMaterialId, Reserva arrReserva[], Material *arrMaterial[])
{
	//Index del objeto en cuestión
	int iIndex;

	//Para saber si hay o no reservas
	bool bReservas = 0;

	//Para cada reserva
	for(int i = 0; i < iContadorReserva; i++)
	{
		iIndex = idPorIndex(arrReserva[i].getMaterial(), iCantMat, arrMaterial);

		//Si el id es el dado por el usario
		if(arrReserva[i].getMaterial() == iMaterialId)
		{
			//Muestra su fecha de entrada
			cout << "Reserva: " << arrReserva[i].getFechaReservacion() << endl;

			//Su fecha de salida
			cout << "Fin de Reserva " << arrReserva[i].calculaFechaFinReserva(arrMaterial[iIndex]->cantidadDeDiasDePrestamo()) << endl;

			//El cliento que reservó
			cout << "ID del cliente: " << arrReserva[i].getCliente() << endl;

			//El nombre del material
			cout << "Nombre del material: " << arrMaterial[iIndex]->getTitulo() << endl << endl;

			//Es más eficiente hacer esto que checar primero y luego cambiar el valor en caso de que no sea true
			bReservas = 1;
		}
	}

	//Si no hubo reservas
	if(!(bReservas))
	{
		//Informa al usuario
		cout << "El material " << iMaterialId << " no cuenta con ninguna reserva." << endl << endl;
	}

}

//Void para mostrar las reservas cuyo tiempo contiene a una fecha dada por el usuario
void mostrarReservasPorFecha(int iContadorReserva, int iCantMat, Fecha fContenedor, Reserva arrReserva[], Material *arrMaterial[])
{
	//Index del objeto en cuestión
	int iIndex;

	//Para saber si hay o no reservas
	bool bReservas = 0;

	//Explora cada reserva
	for(int i = 0; i < iContadorReserva; i++)
	{
		iIndex = idPorIndex(arrReserva[i].getMaterial(), iCantMat, arrMaterial);

		//Si la fecha dada está entre el inicio y fin de la reserva
		if(fContenedor >= arrReserva[i].getFechaReservacion() && fContenedor <=  arrReserva[i].calculaFechaFinReserva(arrMaterial[iIndex]->cantidadDeDiasDePrestamo())){

			//Muestra el nombre del material
			cout << "Nombre del material: " << arrMaterial[iIndex]->getTitulo() << endl;

			//Muestra el ID del cliente
			cout << "ID del cliente: " << arrReserva[i].getCliente() << endl << endl;

			bReservas = 1;
		}
	}

	//Si no hay reserva informa al usuario
	if(!(bReservas))
	{
		cout << "No hay ningun material reservado en esa fecha." << endl;
	}
}

//void para validar que la fecha no esté ocupada dado un material y una fecha
bool validarDisponibilidad(int iContadorReserva, int iCantMat, int iId, Fecha fFecha, Reserva arrReserva[],  Material *arrMaterial[])
{
	//Variable a regresar
	bool bJudge = 1;

	//Fecha de fin de la reservación
	Fecha fFin;

	//Variable para guardar el index del objeto
	int iIndex;

	//Recorre todas las reservaciones
	for(int i = 0; i < iContadorReserva; i ++)
	{
		//Si una tiene el ID solicitado
		if(arrReserva[i].getMaterial() == iId)
		{
			iIndex = idPorIndex(arrReserva[i].getMaterial(), iCantMat, arrMaterial);

			fFin = arrReserva[i].calculaFechaFinReserva(arrMaterial[iIndex]->cantidadDeDiasDePrestamo());

			//Si la fecha de la reserva interfiere con la nueva
			if(fFecha >= arrReserva[i].getFechaReservacion() && fFecha <= fFin)
			{
				//Hacer falsa la booleana
				bJudge = 0;
			}
		}
	}

	//Si no hay disponibilidad informarle al usuario
	if(!(bJudge))
	{
		cout << "La fecha esta ocupada." << endl << endl;
	}

	//Regresar la variable
	return bJudge;
}


//main donde variables importantes son declaradas y las funciones llamadas para poder correr el programa correctamente
int main()
{
	//Contador de materiales
	int iCantMat = 0;

	//Contador de reservas
	int iContadorReserva = 0;

	//Variable para almacenar cualquier valor integer que se ofrezca
	int iContenedor;

	int iContenedor2;

	//Objeto "contenedor"
	Fecha fContenedor;

	//Variable  para almacenar la opción dada por el usuario
	char cOpcion;

	//Array de chars para saber el tipo de cada elemento de material
	char arrCharTipo[20];

	//Arreglo de tipo material (20)
	Material *arrMaterial[20];

	//Arreglo de tipo reserva (50)
	Reserva arrReserva[50];

	//Abriendo el archivo de material
	ifstream fMaterial("Materiales.txt");

	//Cargando el archivo de material
	cargarMaterial(fMaterial, arrMaterial, iCantMat, arrCharTipo);

	//Cerrando el archivo de material
	fMaterial.close();

	//Abriendo el archivo de reserva
	ifstream fReserva("Reserva.txt");

	//Cargando el archivo de reserva
	cargarReserva(fReserva, arrReserva, iContadorReserva);

	//Cerrando el archivo de reserva
	fReserva.close();

	//Dando la bienvenida al usuario
	cout << "///////////////////////////////////" << endl;
	cout << "///   Sistema Biblioteca 1.0   ////" << endl;
	cout << "/// Reservaciones y Materiales ////" << endl;
	cout << "///////////////////////////////////" << endl << endl;

	//Mientras el usuario no quiera salir
	do
	{
		//Desplegando el menú
		desplegarMenu();

		//Recoger opción
		cin >> cOpcion;

		//Si el usuario selecciona la letra a
		if(cOpcion == 'a' || cOpcion == 'A')
		{
			//Mostrar los materiales
			cout << endl;
			cout << "Materiales: " << endl << endl;
			mostrarMateriales(iCantMat, arrCharTipo, arrMaterial);
		}

		//Si el usuario selecciona la letra b
		else if(cOpcion == 'b' || cOpcion == 'B')
		{
			//Mostrar lista de reservas
            cout << endl;
			cout << "Reservaciones: " << endl << endl;
			mostrarReservas(iContadorReserva, iCantMat, arrReserva, arrMaterial);
		}

		//Si el usuario selecciona la letra c
		else if(cOpcion == 'c' || cOpcion == 'C')
		{
			//Pidiendo el ID hasta que sea válido
			cout << "Ingrese el ID del material a revisar: ";

			cin >> iContenedor;


			while(!(validarMaterial(iCantMat, iContenedor, arrMaterial)))
			{
				cout << "Favor de ingresar un  ID valido: ";

				cin >> iContenedor;
			}
			cout << endl;

			cout << "Reservaciones: "<< endl << endl;

			//Mostrar reservas de un material específico
			mostrarReservasPorMaterial(iContadorReserva, iCantMat, iContenedor, arrReserva, arrMaterial);
		}

		//Si el usuario selecciona la letra d
		else if(cOpcion == 'd' || cOpcion == 'D')
		{
			//Pidiendo datos de la fecha
			cout << "Favor de ingresar la fecha en formato dando primero el dia, luego el mes y al final el anio: ";
			cin >> fContenedor;

			//Validando fecha
			while(!(validarFecha(fContenedor)))
			{
				cin >> fContenedor;
			}

			//Mostrar mat. reservados en una fecha
			cout << endl;
			cout << "Reservaciones:" << endl << endl;
			mostrarReservasPorFecha(iContadorReserva, iCantMat, fContenedor, arrReserva, arrMaterial);
		}

		//Si el usuario selecciona la letra e
		else if(cOpcion == 'e' || cOpcion == 'E')
		{
			//Hacer reservación

			//Pidiendo el ID del cliente
			cout << "Ingrese el ID del cliente: ";

			cin >> iContenedor;

			//Pidiendo el ID del material
			cout << "Ingrese el ID del material a reservar: ";

			cin >> iContenedor2;

			//Validando el ID del material
			while(!(validarMaterial(iCantMat, iContenedor2, arrMaterial)))
			{
				cout << "Favor de ingresar un ID valido: ";

				cin >> iContenedor2;
			}

			//Pidiendo la fecha
			cout << "Favor de ingresar la fecha en formato dando primero el dia, luego el mes y al final el anio: ";

			cin >> fContenedor;

			//Validando la fecha(que esté correcta)
			while(!(validarFecha(fContenedor)))
			{
				cin >> fContenedor;
			}

			//Validando la disponibilidad de la fecha
			while(!(validarDisponibilidad(iContadorReserva, iCantMat, iContenedor2, fContenedor, arrReserva, arrMaterial)))
			{
				cout << "Favor de elegir otra fecha para reservar el articulo: ";

				cin >> fContenedor;
			}

			//Agregando reserva en el array
			arrReserva[iContadorReserva].setCliente(iContenedor);

			arrReserva[iContadorReserva].setMaterial(iContenedor2);

			arrReserva[iContadorReserva].setFechaReservacion(fContenedor);

			iContadorReserva++;


		}
	}while(cOpcion >= 'a' && cOpcion <= 'e' || cOpcion >= 'A' && cOpcion <= 'E');

	//Abriendo ofstream para actualizar el txt
	ofstream archivoReservaActua;
	archivoReservaActua.open("Reserva.txt");
	if(cOpcion == 'F' || cOpcion == 'f')
    {
        for(int i=0; i < iContadorReserva; i++)
        {
            archivoReservaActua << arrReserva[i].getFechaReservacion().getDia();
            archivoReservaActua << " ";
            archivoReservaActua << arrReserva[i].getFechaReservacion().getMes();
            archivoReservaActua << " ";
            archivoReservaActua << arrReserva[i].getFechaReservacion().getYear();
            archivoReservaActua << " ";
            archivoReservaActua << arrReserva[i].getMaterial();
            archivoReservaActua << " ";
            archivoReservaActua << arrReserva[i].getCliente();
            if(i < iContadorReserva -1)
            {
               archivoReservaActua << endl;
            }
        }
    }

	//Finalizar
	return 0;
}
