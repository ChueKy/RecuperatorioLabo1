#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED
struct Fecha
{
    int dia,mes,anio;
};

struct Pacientes
{

    int dni;
    char apellidos[30];
    char nombres[30];
    char genero;
    struct Fecha nacimiento;
    int oSocial;
    bool estado;

};

bool Recuperar_Paciente ()
{
    struct Pacientes p;
    char tecla = NULL;
    int dni, pos, x=0, y=7;
    char opc;
    FILE *PC;
    PC = fopen("Pacientes.dat","rb+");
    if (PC==NULL)
    {
        cout << "ERROR! No existe el Archivo.";
        fclose(PC);
        return -1;
    }
    pos = Buscar_paciente(dni);
    if (pos == -1)
    {
        cout << "No existe el Paciente." << endl;
        system ("pause");
        return -1;
    }
    fseek(PC, pos*sizeof (Pacientes), 0);
    fread(&p, sizeof (Pacientes), 1, PC);
    if (p.estado==true)
    {
        cout << "El Paciente ya existe en nuestros registros." << endl;
        system ("cls");
    }
    else
    {
        cout << "El Paciente se ha dado de baja. ¿Recuperar?" << endl;
        cout << "S / N" << endl;
    }
    cin >> opc;
    if (opc == 'S' || opc == 's')
    {
        fseek(PC, pos*sizeof (Pacientes), 0);
        p.estado=true;
        fwrite(&p, sizeof (Pacientes), 1, PC);
        fclose(PC);
        cout << "Paciente Recuperado." << endl;
        return true;
    }
    else if (opc == 'N' || opc == 'n')
    {
        cout << "No surgieron cambios en el archivo." << endl;
        fclose(PC);
        return true;
    }
}

/// Validar Pacientes
bool  ValidarDni(int  dni){
//El campo DNI debe ser un número entero positivo y único. Es decir, un valor que no puede

    struct Pacientes reg;

    FILE *p;
    p=fopen("Pacientes.dat","rb");

    if(p==NULL)
    {

        //cout<<"Fallo al abrirlo ";
        return false;
    }


    do
    {
        fread(&reg,sizeof(reg),1,p);
        if(dni==reg.dni)
        {

            Recuperar_Paciente(dni);
            return true;

        }

    }
    while(!feof(p));

    fclose(p);
}



bool validarCadena(char xCaracteres[]){

    if(strlen(xCaracteres)==0)
    {

        return true;
    }
    else
        return false;
}


ValidarLetra(char l){

    if(l=='m'||l=='f'||l=='o'||l=='M'||l=='F'||l=='O')
    {
        return false;
    }
    return true;
}
bool ValidarNumero(int numero,int vInicial, int vFinal){
//El campo obra social debe ser un número entre el 1 y el 50.

    if(numero>vInicial && vFinal<=50)
    {
        return false;
    }
    return true;
}

bool ValidarFecha(int  d, int m, int a){

    //Array que almacenara los dias que tiene cada mes (si el ano es bisiesto, sumaremos +1 al febrero)
    int dias_mes[] = {31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};

    //Comprobar si el ano es bisiesto y anadir dia en febrero en caso afirmativo
    if((a%4 == 0 and a%100 != 0) or a%400 == 0)
        dias_mes[1]++;

    //Comprobar que el mes sea valido
    if(m < 1 or m > 12)
        return false;

    //Comprobar que el dia sea valido
    m = m-1;
    if(d <= 0 or d > dias_mes[m])
        return false;

    //Si ha pasado todas estas condiciones, la fecha es valida
    return true;


}

///Funcion Cargar 1 paciente.
void Cargar1Paciente(){
    system ("color 0c");
    Pacientes reg;
    int i=0,aux=1,vInicial=0,vFinal=50;
    reg.dni=1;
    int a,d,m;
    bool validar= false;

    while(i!=1)
    {

        if (reg.dni>0)
        {
            do{

                validar=true;
                cout<<"Ingresar Dni: ";
                cin >> reg.dni;
                if(reg.dni>0)
                {
                    validar=ValidarDni(reg.dni);
                }
            }
            while(validar==true);
            cout<<"Dni ingresado correctamente \n";

            if(Recuperar_Paciente==false)

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
                cout<<"Ingresar Apellido:";
                fflush(stdin);
                cin.getline(reg.apellidos,30,'\n');
            }
            while(validarCadena(reg.apellidos)==true);
            cout<<"Apellido Ingresado Correctamente \n";

            do{

                cout<<"Ingresar genero: ";
                cin>>reg.genero;
            }
            while(ValidarLetra(reg.genero)==true);
            cout<<"Genero Ingresado Correctamente \n";

            do{
                cout<<"Ingresar Fecha de nacimiento ";
                cin>>reg.nacimiento.dia;
                d=reg.nacimiento.dia;
                cin>>reg.nacimiento.mes;
                m=reg.nacimiento.mes;
                cin>>reg.nacimiento.anio;
                a=reg.nacimiento.anio;
                validar=ValidarFecha(d,m,a);
            }while(validar==false);


            do{
                cout<<"Ingresar Obra Social: ";
                cin>>reg.oSocial;
            }
            while(ValidarNumero(reg.oSocial,vInicial,vFinal)==true);
            cout<<"Obra Social Ingresado Correctamente\n ";
            reg.estado= true;
        }
        i++;

    }

     FILE *p;

            ///p=fopen("C:/Users/erivnah/Documents/Utn Frgp ayg2/Parcial1Ayg2/Parcial1/filepacientes","ab+");
            p=fopen("Pacientes.dat","ab+");
            if(p==NULL){
                cout<<"No Puedo Abrirlo \n";
                exit(1);
            }

            fwrite(&reg,sizeof(Pacientes),1,p);
            fclose(p);
            system("pause");

}
void MostrarPaciente(Pacientes a){


    if(a.estado==true){

    cout<<"-------------" <<endl;
    cout<<"DNI: " <<a.dni <<endl;
    cout<<"Apellido: " <<a.apellidos <<endl;
    cout<<"Nombre: " <<a.nombres <<endl;
    cout<<"Genero: " <<a.genero<<endl;
    cout<<"Fecha de Nacimiento :"<<a.nacimiento.dia<<"/"<<a.nacimiento.mes<<"/"<<a.nacimiento.anio<<endl;
    cout<<"Obra social:" <<a.oSocial<<endl;
    cout<<"Estado: " <<a.estado<<endl;

    }

    else{
    cout<<"El paciente esta dado de baja logica "<<endl;
    }

}


void ListarPacientes(){

struct Pacientes reg;

FILE *p;

p=fopen("Pacientes.dat","rb");

    if(p==NULL){
      cout<<"No Puedo Abrirlo \n";
      exit(1);
    }

while (fread(&reg,sizeof(Pacientes),1,p)==1){
MostrarPaciente(reg);

}

fclose(p);

}

 void grabar_Paciente_Modificado(int pos){
    struct Pacientes p;
    FILE *PC;
    PC = fopen("Pacientes.dat","rb+");
    if (PC==NULL)
    {
        cout << "No existe el archivo.";
        return;
    }
    fseek(PC, sizeof (Pacientes) * pos, 0);
    fread(&p, sizeof (Pacientes), 1, PC);
    fseek(PC, sizeof (Pacientes) * pos, 0);

    if (p.estado==true)
    {

        cout << "Ingrese obra social: ";
        cin >> p.oSocial;
        while (p.oSocial<1 || p.oSocial>50)
        {
            cout << "REINGRESE OBRA SOCIAL: ";
            cin >> p.oSocial;
        }
    }
    else
    {
        cout << "NO EXISTE EL PACIENTE ";
    }
    fwrite(&p, sizeof (Pacientes), 1, PC);
    fclose(PC);
}


 int Buscar_paciente(int dni){
    FILE *PC;
    Pacientes p;
    int pos=0;
    PC = fopen("Pacientes.dat","rb");
    if ( PC == NULL){
        return -1;
    }
    while (fread(&p, sizeof (Pacientes), 1, PC))
    {
        if (dni==p.dni){
            fclose(PC);
            return pos;
        }
        pos++;
    }
    fclose(PC);
    return -1;
}
void Modificar_Paciente (){
    int dni, pos;
    cout << "INGRESE DNI PARA MODIFICAR PACIENTE: ";
    cin >> dni;
    pos = Buscar_paciente(dni);
    if (pos==-1)    {
        cout << endl <<  "NO EXISTE EL PACIENTE";
        return ;
    }
    else{
        grabar_Paciente_Modificado(pos);
    }
}

ListarPacientesXDni(){
struct Pacientes reg;
int dni, pos;
    do{
    cout << "Ingrese el dni paciente que desea buscar:";
    cin >> dni;
    pos = Buscar_paciente(dni);
    }while(pos==-1);

    FILE *p;
    p=fopen("Pacientes.dat","rb");
    fseek(p, sizeof (Pacientes) * pos, 0);
    fread(&reg,sizeof(Pacientes),1,p);
    MostrarPaciente(reg);
    fclose(p);
}

void eliminar_paciente(){
struct Pacientes reg;
int dni;
char c;
FILE *p;
p = fopen("Pacientes.dat","rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVOS";
        system("pause");
        return;
    }
    cout<<"INGRESE EL DNI QUE DESEA DAR DE BAJA: ";
    cin>>dni;
        while(fread(&reg,sizeof reg,1,p)==1){
            if(dni==reg.dni){
                if(reg.estado==false){
                    cout<<"EL DNI INGRESADO ESTA DADO DE BAJA, DAR DE ALTA NUEVAMENTE? Y/N: ";
                    cin>>c;
                    c=toupper(c);
                    if(c =='Y'){
                        reg.estado=true;
                        fseek(p,- sizeof reg ,1);
                        fwrite(&reg,sizeof reg,1,p);
                        cout<<"EL USUARIO "<<dni<<" A SIDO DADO DE ALTA"<<endl;
                        fclose(p);
                        return;
                    }
                }
                reg.estado=false;
                fseek(p,- sizeof reg ,1);
                fwrite(&reg,sizeof reg,1,p);
                cout<<"EL USUARIO "<<dni<<" A SIDO ELIMINADO"<<endl;
                fclose(p);
                return;
            }
        }
cout<<"NO SE ENCONTRO EL USUARIO INGRESADO"<<endl;
fclose(p);
}

int FuncionMenuPacientes(int opc){

    struct Pacientes reg;
    struct Pacientes p1;
    while(true){

        system("cls");
        system ("color 0d");
        cout<<"\n \n \n \n \n \n \n \n \n \n";
        cout<<"\t\t\t\t\t|--------MENU-PACIENTES-----------|"<<endl;
        cout<<"\t\t\t\t\t| 1 = Nuevo Paciente              |"<<endl;
        cout<<"\t\t\t\t\t| 2 = Modificar Paciente          |"<<endl;
        cout<<"\t\t\t\t\t| 3 = Lister Paciente por Dni     |"<<endl;
        cout<<"\t\t\t\t\t| 4 = Listar todos los pacientes  |"<<endl;
        cout<<"\t\t\t\t\t| 5 = Eliminar paciente           |"<<endl;
        cout<<"\t\t\t\t\t| 0 = VOLVER AL MENU PRINCIPAL    |"<<endl;
        cout<<"\t\t\t\t\t|---------------------------------|"<<endl;
        cout<<"\t\t\t\t\t\tingresar opcion: ";
        cin>>opc;

        system ("cls");

        switch(opc)
        {
        case 1:
            Cargar1Paciente();
            system("pause");
            break;


        case 2:
            Modificar_Paciente ();
            system("pause");
            break;


        case 3:
            ListarPacientesXDni();
            system("pause");
            break;


        case 4:
            ListarPacientes();
            system("pause");
            break;


        case 5:
            eliminar_paciente();
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




#endif // PACIENTES_H_INCLUDED
