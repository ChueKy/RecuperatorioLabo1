#ifndef MEDICOS_H_INCLUDED
#define MEDICOS_H_INCLUDED
struct Medicos
{

    int nroMatricula;
    char apellidos[50];
    char nombres[50];
    int especialidad;
    float sueldo;

};

int opc;

bool ValidarNroMedico(int  matricula){
///El campo nroMatricula debe ser un número entero positivo y único. Es decir, un valor que no puede

    struct Medicos reg;

    FILE *p;
    p=fopen("Medicos.dat","rb");

    if(p==NULL){

        //cout<<"Fallo al abrirlo ";
        return false;
    }


    do
    {
        fread(&reg,sizeof(reg),1,p);
        if(matricula==reg.nroMatricula)
        {
            fclose(p);
            return true;
        }

    }
    while(!feof(p));
    return false;

}

void CargarMedico()
{

    system ("color 0c");
    struct Medicos reg;
    int i=0,aux=1,vInicial=0,vFinal=20;
    reg.nroMatricula=1;
    bool validar= false;

    while(i!=1)
    {

        if (reg.nroMatricula>0)
        {
            do
            {

                validar=true;
                cout<<"Ingresar nroMatricula: ";
                cin >> reg.nroMatricula;
                if(reg.nroMatricula>0)
                {
                    validar=ValidarNroMedico(reg.nroMatricula);
                }
            }
            while(validar==true);
            cout<<"nroMatricula ingresado correctamente \n";


            do
            {
                cout<<"Ingresar Nombre: ";
                fflush(stdin);
                cin.getline(reg.nombres,30,'\n');
                fflush(stdin);
            }
            while(validarCadena(reg.nombres)==true);
            cout<<"Nombre Ingresado correctamente\n ";

            do
            {
                cout<<"Ingresar Apellido: ";
                fflush(stdin);
                cin.getline(reg.apellidos,30,'\n');
                fflush(stdin);
            }
            while(validarCadena(reg.apellidos)==true);
            cout<<"Apellido Ingresado Correctamente \n";

            do
            {
                cout<<"Ingresar Especialidad: ";
                cin>>reg.especialidad;
            }
            while(ValidarNumero(reg.especialidad,vInicial,vFinal)==true);
            cout<<"Especialidad Ingresada Correctamente \n";


            do
            {
                cout<<"Ingresar Sueldo: ";
                cin>>reg.sueldo;
            }
            while(reg.sueldo<0);
            cout<<"Sueldo Ingresado Correctamente\n ";

        }
        i++;

    }

    FILE *p;

    ///p=fopen("C:/Users/erivnah/Documents/Utn Frgp ayg2/Parcial1Ayg2/Parcial1/filepacientes","ab+");
    p=fopen("Medicos.dat","ab+");
    if(p==NULL)
    {
        cout<<"No Puedo Abrirlo \n";
        exit(1);
    }

    fwrite(&reg,sizeof(Medicos),1,p);
    fclose(p);
    system("pause");
}

 void GrabarMedicoModificado(int pos){
    struct Medicos p;
    FILE *PC;
    PC = fopen("Medicos.dat","rb+");
    if (PC==NULL){
        cout << "No existe el archivo.";
        return;
    }
    fseek(PC, sizeof (Medicos) * pos, 0);
    fread(&p, sizeof (Medicos), 1, PC);
    fseek(PC, sizeof (Medicos) * pos, 0);
    do{
    cout << "Ingrese Nuevo Sueldo: ";
    cin >> p.sueldo;
    }while(p.sueldo<=0);
    fwrite(&p, sizeof (Medicos), 1, PC);
    fclose(PC);
}


 int BuscarMedico(int nroMatricula){
    FILE *PC;
    struct Medicos p;
    int pos=0;
    PC = fopen("Medicos.dat","rb");
    if ( PC == NULL){
        return -1;
    }
    while (fread(&p, sizeof (Medicos), 1, PC))
    {
        if (nroMatricula==p.nroMatricula){
            fclose(PC);
            return pos;
        }
        pos++;
    }
    fclose(PC);
    return -1;
}
void ModificarMedico(){
    int nroMatricula, pos;
    cout << "INGRESE Nro de matricula PARA MODIFICAR El sueldo del medico: ";
    cin >> nroMatricula;
    pos = BuscarMedico(nroMatricula);
    if (pos==-1)    {
        cout << endl <<  "NO EXISTE EL Medico";
        return ;
    }
    else{
        GrabarMedicoModificado(pos);
    }
}

void MostrarMedicos(Medicos a){

system ("color 1e");
cout<<"-------------" <<endl;
cout<<"Nro Matricula: " <<a.nroMatricula <<endl;
cout<<"Nombre: " <<a.nombres<<endl;
cout<<"Apellido: " <<a.apellidos<<endl;
cout<<"Especialidad: " <<a.especialidad<<endl;
cout<<"Sueldo: " <<a.sueldo<<endl;

}

void ListarMedicos(){

struct Medicos reg;

FILE *p;

p=fopen("Medicos.dat","rb");

    if(p==NULL){
      cout<<"No Puedo Abrirlo \n";
      exit(1);
    }
while (fread(&reg,sizeof(Medicos),1,p)==1){
MostrarMedicos(reg);
}
fclose(p);
}

ListarMedicosPorNroMatricula(){
struct Medicos reg;
int nroMatricula, pos;
    do{
    cout << "Ingrese el Nro De matricula del medico que desea buscar:";
    cin >> nroMatricula;
    pos = BuscarMedico(nroMatricula);
    }while(pos==-1);

    FILE *p;
    p=fopen("Medicos.dat","rb");
    fseek(p, sizeof (Medicos) * pos, 0);
    fread(&reg,sizeof(Medicos),1,p);
    MostrarMedicos(reg);
    fclose(p);
}

int FuncionMenuMedicos(int opc){

while(true)
{
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t"<<"\t"<<"\t"<<"\t"<<"|------------------------------------------------|"<<endl;
    cout<<"\t"<<"\t"<<"\t"<<"\t"<<"| 1 = Nuevo Medico                               |"<<endl;
    cout<<"\t"<<"\t"<<"\t"<<"\t"<<"| 2 = Modificar Medico                           |"<<endl;
    cout<<"\t"<<"\t"<<"\t"<<"\t"<<"| 3 = Listar Todos los medicos                   |"<<endl;
    cout<<"\t"<<"\t"<<"\t"<<"\t"<<"| 4 = Listar Listar medico por Nro de Matricula  |"<<endl;
    cout<<"\t"<<"\t"<<"\t"<<"\t"<<"| 0 = VOLVER AL MENU PRINCIPAL                   |"<<endl;
    cout<<"\t"<<"\t"<<"\t"<<"\t"<<"|------------------------------------------------|"<<endl;
    cout<<"\t"<<"\t"<<"\t"<<"\t"<<"ingresar opcion: ";
    cin>>opc;

    system ("cls");

    switch(opc)
    {
    case 1:
        CargarMedico();
        system("pause");
        break;


    case 2:
        ModificarMedico();
        system("pause");
        break;


    case 3:
        ListarMedicos();
        system("pause");
        break;


    case 4:
        ListarMedicosPorNroMatricula();
        system("pause");
        break;

    case 0:
        ///Aca Va algo que me deje retornar al menu principal.
        return 0;
        break;


    default:
        cout<< " > ! Opcion Incorrecta ! " <<endl;
        system("pause");
        break;



    }
}

}

#endif // MEDICOS_H_INCLUDED
