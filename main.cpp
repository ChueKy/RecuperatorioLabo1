#include <iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;
#include"Pacientes.h"
#include"Medicos.h"
#include<stdio.h>
#include"Controles.h"
#include"configuracion.h"





int main(){
    int opc;


    while(true)
    {
        system("cls");
        system ("color 0a");
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t|---------MENU-PRINCIPAL----------|"<<endl;
        cout<<"\t\t\t\t\t| 1 = Pacientes                   |"<<endl;
        cout<<"\t\t\t\t\t| 2 = Medicos                     |"<<endl;
        cout<<"\t\t\t\t\t| 3 = Controles                   |"<<endl;
        cout<<"\t\t\t\t\t| 4 = Reportes                    |"<<endl;
        cout<<"\t\t\t\t\t| 5 = Configuracion               |"<<endl;
        cout<<"\t\t\t\t\t| 0 = Salir                       |"<<endl;
        cout<<"\t\t\t\t\t|---------------------------------|"<<endl;
        cout<<"\t\t\t\t\t\tingresar opcion: ";
        cin>>opc;

        system ("cls");
        switch(opc)
        {
        case 1:
            FuncionMenuPacientes(opc);
            system("pause");
            break;


        case 2:
            FuncionMenuMedicos(opc);
            system("pause");
            break;


        case 3:
            FuncionMenuControles(opc);
            system("pause");
            break;


        case 4:
            system("pause");
            break;


        case 5:

            system("pause");
            break;


        case 0:

            exit(0);
            break;


        case '0':
            return 0;
            break;


        default:
            cout<< " > ! Opcion Incorrecta ! " <<endl;
            system("pause");
            break;



        }
    }

    system("pause");
    return 0;
}
