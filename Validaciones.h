/*#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include"Pacientes.h"
#include <stdio.h>

using namespace std;
/// Validar Pacientes
bool ValidarDni(int dni){
//El campo DNI debe ser un número entero positivo y único. Es decir, un valor que no puede

struct Pacientes reg;

FILE *p;
    p=fopen("C:\\Users\\erivnah\\Documents\\Utn Frgp ayg2\\Parcial1Ayg2\\Parcial1\\filepacientes","ar");

    if(p==NULL){

        cout<<"Fallo al abrirlo ";
        exit(1);
    }


    do{
        fread(&reg,sizeof(reg),1,p);
        if(dni==reg.dni){
            return true;
        }

    }while(!EOF(p));
        return false;
}



bool validarCadena(char xCaracteres[]){

    if(strncmp(xCaracteres)==0){

        return true;
    }
    else return false;
}


ValidarLetra(char l){

 if(l=='m'||l=='f'||l=='o'||l=='M'||l=='F'||l=='O'){
    return false;
 }
    return true;
}
bool ValidarOSocial(int oSocial){
//El campo obra social debe ser un número entre el 1 y el 50.

    if(oSocial>0 && oSocial<=50){
        return true;
    }
    return false;
}

/// Validar Medicos
ValidarMatricula()
{
//El campo NroMatricula debe ser un número entero positivo y único. Es decir, un valor que no puede repetirse en el archivo de médicos.
}
ValidarEspecialidad()
{
//El campo especialidad debe ser un número entero entre el 1 y el 20.
}
Validarsueldo()
{
//El campo sueldo debe ser un número real mayor a cero.
}

/// validar Fecha
ValidarFechas()
{
//El campo fecha de nacimiento debe ser una fecha válida.



#endif // VALIDACIONES_H_INCLUDED
*/
