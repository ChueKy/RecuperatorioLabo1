#ifndef CONTROLES_H_INCLUDED
#define CONTROLES_H_INCLUDED

struct Controles {
    int iD;
    int dni;
    int  nroMatricula;
    float costo;
    Fecha fechas;
    int duracion;
    bool estado;
};

int verificar_control_id(){
int cant=0;
int total=0;
FILE *p;
p=fopen("Controles.dat","ab+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVOS";
        system("pause");
        return -1;
    }
fseek(p,0,2);
cant=ftell(p);
fclose(p);
total=cant/sizeof (Controles);
return total;
}

NuevoControl(){

 system ("color 0c");
    struct Controles reg;
    int i=0,aux=1,vInicial=0,vFinal=50,a,m,d,x;
    reg.dni=1;
    bool validar=false;
    FILE *p;


    cout<<"Usted esta cargando el control: "<<verificar_control_id()+1<<endl;
    reg.iD=verificar_control_id()+1;
    while(i!=1){

        if (reg.dni>0){
            do{

                validar=false;
                cout<<"Ingresar Dni: ";
                cin >> x;
                if(x>0){
                    reg.dni=x;

                    if(reg.dni>0){
                        validar=ValidarDni(reg.dni);
                    }
                }
            }
            while(validar==false);
            cout<<"Dni ingresado correctamente \n";


            do{
                validar=false;
                cout<<"Ingresar nroMatricula: ";
                cin >> reg.nroMatricula;
                if(reg.nroMatricula>0){
                    validar=ValidarNroMedico(reg.nroMatricula);
                }
            }
            while(validar==false);
            cout<<"nroMatricula ingresado correctamente \n";

            do{
                cout<<"Ingresar Costo:";
                cin>>reg.costo;
            }
            while(reg.costo<0);
            cout<<"Costo Ingresado Correctamente \n";

             do{
                cout<<"Ingresar Fecha ";
                cin>>reg.fechas.dia;
                d=reg.fechas.dia;
                cin>>reg.fechas.mes;
                m=reg.fechas.mes;
                cin>>reg.fechas.anio;
                a=reg.fechas.anio;
                validar=ValidarFecha(d,m,a);
            }while(validar==false);

            do{
                cout<<"Ingresar Duracion: ";
                cin>>reg.duracion;
            }
            while(reg.duracion<0);
            cout<<"Genero Ingresado Correctamente \n";

            cout<<"Estado Activo: ";
            reg.estado= true;
        }
        i++;

    }



            ///p=fopen("C:/Users/erivnah/Documents/Utn Frgp ayg2/Parcial1Ayg2/Parcial1/filepacientes","ab+");
            p=fopen("Controles.dat","ab+");
            if(p==NULL){
                cout<<"No Puedo Abrirlo \n";
                exit(1);
            }

            fwrite(&reg,sizeof(Controles),1,p);
            fclose(p);
            system("pause");

}

 void GrabarControlModificado(int pos){
    struct Controles p;
    FILE *PC;
    PC = fopen("Controles.dat","rb+");
    if (PC==NULL){
        cout << "No existe el archivo.";
        return;
    }
    fseek(PC, sizeof (Controles) * pos, 0);
    fread(&p, sizeof (Controles), 1, PC);
    fseek(PC, sizeof (Controles) * pos, 0);
    do{
    cout << "Ingrese Nueva duracion: ";
    cin >> p.duracion;
    }while(p.duracion<=0);
    fwrite(&p, sizeof (Controles), 1, PC);
    fclose(PC);
}

 int BuscarControl(int iD){
    FILE *PC;
    struct Controles p;
    int pos=0;
    PC = fopen("Controles.dat","rb");
    if ( PC == NULL){
        return -1;
    }
    while (fread(&p, sizeof (Controles), 1, PC))
    {
        if (iD==p.iD){
            fclose(PC);
            return pos;
        }
        pos++;
    }
    fclose(PC);
    return -1;
}

ModificarControl(){

    int iD, pos;
    cout << "INGRESE el Numero de Id Para modificar la duracion ";
    cin >> iD;
    pos = BuscarControl(iD);
    if (pos==-1)    {
        cout << endl <<  "NO EXISTE EL Control";
        return 0 ;
    }
    else{
        GrabarControlModificado(pos);
    }


}

void MostrarControles(Controles a){

system ("color 1e");
cout<<"-------------" <<endl;
cout<<"Nro iD: " <<a.iD <<endl;
cout<<"Nro dni: " <<a.dni <<endl;
cout<<"Nro Matricula: " <<a.iD <<endl;
cout<<"costo " <<a.costo<<endl;
cout<<"Fecha  :"<<a.fechas.dia<<"/"<<a.fechas.mes<<"/"<<a.fechas.anio<<endl;
cout<<"duracion: " <<a.duracion<<endl;
cout<<"estado: " <<a.estado<<endl;

}

void ListarControles(){

struct Controles reg;

FILE *p;

p=fopen("Controles.dat","rb");

    if(p==NULL){
      cout<<"No Puedo Abrirlo \n";
      exit(1);
    }
while (fread(&reg,sizeof(Controles),1,p)==1){
MostrarControles(reg);
}
fclose(p);
}

ListarControlXId(){

struct Controles reg;
int iD, pos;
    do{
        cout << "Ingrese el ID que desea visualizar :";
        cin >> iD;
        pos = BuscarControl(iD);
    }while(pos==-1);

    FILE *p;
    p=fopen("Controles.dat","rb");
    fseek(p, sizeof (Controles) * pos, 0);
    fread(&reg,sizeof(Controles),1,p);
    MostrarControles(reg);
    fclose(p);

}

int FuncionMenuControles(int opc){
while(true){

        system("cls");
        system ("color 0d");
        cout<<"\n \n \n \n \n \n \n \n \n \n";
        cout<<"\t\t\t\t\t|--------MENU-PACIENTES-----------|"<<endl;
        cout<<"\t\t\t\t\t| 1 = Nuevo Control               |"<<endl;
        cout<<"\t\t\t\t\t| 2 = Modificar Control           |"<<endl;
        cout<<"\t\t\t\t\t| 3 = Lister Control Por ID       |"<<endl;
        cout<<"\t\t\t\t\t| 4 = Listar todos los Controles  |"<<endl;
        cout<<"\t\t\t\t\t| 5 = Cancelar Control            |"<<endl;
        cout<<"\t\t\t\t\t| 0 = VOLVER AL MENU PRINCIPAL    |"<<endl;
        cout<<"\t\t\t\t\t|---------------------------------|"<<endl;
        cout<<"\t\t\t\t\t\tingresar opcion: ";
        cin>>opc;

        system ("cls");

        switch(opc){
        case 1:
            NuevoControl();
            system("pause");
            break;


        case 2:
            ModificarControl();
            system("pause");
            break;


        case 3:
            ListarControlXId();
            system("pause");
            break;


        case 4:
            ListarControles();
            system("pause");
            break;


        case 5:

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

#endif // CONTROLES_H_INCLUDED
