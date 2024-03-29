#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

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
        cout << "El Paciente se ha dado de baja. ┐Recuperar?" << endl;
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

void Backup_Pacientes ()
{
    struct Pacientes p;
    struct Pacientes bkp;
    FILE *F;
    F = fopen ("Pacientes.dat", "rb");
    if (F==NULL)
    {
        exit (1);
        fclose(F);
    }
    FILE *F2;
    F2 = fopen ("Pacientes.bkp", "wb");
    if (F2==NULL)
    {
        exit (1);
        fclose(F2);
    }
    while(fread(&p, sizeof (Pacientes), 1, F)==1)
    {
        bkp.dni=p.dni;
        strcpy(bkp.apellidos, p.apellidos);
        strcpy(bkp.nombres, p.nombres);
        bkp.genero=p.genero;
        bkp.nacimiento=p.nacimiento;
        bkp.oSocial=p.oSocial;
        bkp.estado=p.estado;
        fwrite(&bkp, sizeof (Pacientes), 1, F2);
    }
    fclose(F2);
    fclose(F);
}


void Backup_Medicos ()
{
    struct Medicos m;
    struct Medicos bkp;
    FILE *F;
    F = fopen ("Medicos.dat", "rb");
    if (F==NULL)
    {
        exit (1);
        fclose(F);
    }
    FILE *F2;
    F2 = fopen ("Medicos.bkp", "wb");
    if (F2==NULL)
    {
        exit (1);
        fclose(F2);
    }
    while(fread(&m, sizeof (Medicos), 1, F)==1)
    {
        bkp.nroMatricula=m.nroMatricula;
        strcpy(bkp.apellidos, m.apellidos);
        strcpy(bkp.nombres, m.nombres);
        bkp.especialidad=m.especialidad;
        bkp.sueldo=m.sueldo;
        fwrite(&bkp, sizeof (Medicos), 1, F2);
    }
    fclose(F2);
    fclose(F);
}


/*Backup_Controles ()
{

    struct Controles c;

    FILE *F;
    F = fopen ("Controles.dat", "rb");
    if (F==NULL)
    {
        exit (1);
        fclose(F);
    }
    FILE *F2;
    F2 = fopen ("Controles.bkp", "wb");
    if (F2==NULL)
    {
        exit (1);
        fclose(F2);
    }
    while(fread(&c, sizeof (Controles), 1, F)==1)
    {
        bkp.iD=c.iD;
        bkp.dni=c.dni;
        bkp.matricula=c.matricula;
        bkp.costo=c.costo;
        bkp.fechas=c.fechas;
        bkp.duracion=c.duracion;
        bkp.estado=c.estado;
        fwrite(&bkp, sizeof (Controles), 1, F2);
    }
    fclose(F2);
    fclose(F);
}


void Realizar_Backup ()
{
    Backup_Pacientes();
    Backup_Medicos();
    Backup_Controles();
}


void Restaurar_Pacientes ()
{
    Paciente bkp;
    Paciente p;
    FILE *F2;
    F2 = fopen ("Pacientes.bkp", "rb+");
    if (F2==NULL)
    {
        exit (1);
    }
    FILE *F;
    F = fopen ("Pacientes.dat", "wb");
    if (F==NULL)
    {
        exit (1);
    }
    while(fread(&bkp, sizeof (Paciente), 1, F2)==1)
    {
        p.dni=bkp.dni;
        strcpy(p.apellidos, bkp.apellidos);
        strcpy(p.nombres, bkp.nombres);
        p.genero=bkp.genero;
        p.nacimiento=bkp.nacimiento;
        p.obra=bkp.obra;
        p.estado=bkp.estado;
        fwrite(&p, sizeof (Paciente), 1, F);
    }
    fclose(F);
    fclose(F2);
}


void Restaurar_Medicos ()
{
    Medico bkp;
    Medico m;
    FILE *F2;
    F2 = fopen ("Medicos.bkp", "rb+");
    if (F2==NULL)
    {
        exit (1);
    }
    FILE *F;
    F = fopen ("Medicos.dat", "wb");
    if (F==NULL)
    {
        exit (1);
    }
    while(fread(&bkp, sizeof (Medico), 1, F2)==1)
    {
        m.matricula=bkp.matricula;
        strcpy(m.apellidos, bkp.apellidos);
        strcpy(m.nombres, bkp.nombres);
        m.especialidad=bkp.especialidad;
        m.sueldo=bkp.sueldo;
        fwrite(&m, sizeof (Medico), 1, F);
    }
    fclose(F);
    fclose(F2);
}


void Restaurar_Controles ()
{
    Controles bkp;
    Controles c;
    FILE *F2;
    F2 = fopen ("Controles.bkp", "rb+");
    if (F2==NULL)
    {
        exit (1);
    }
    FILE *F;
    F = fopen ("Controles.dat", "wb");
    if (F==NULL)
    {
        exit (1);
    }
    while(fread(&bkp, sizeof (Controles), 1, F2)==1)
    {
        c.id=bkp.id;
        c.dni=bkp.dni;
        c.matricula=bkp.matricula;
        c.costo=bkp.costo;
        c.fcontrol=bkp.fcontrol;
        c.duracion=bkp.duracion;
        c.estado=bkp.estado;
        fwrite(&c, sizeof (Controles), 1, F);
    }
    fclose(F);
    fclose(F2);
}


void Restaurar_Backup()
{
    Restaurar_Pacientes();
    Restaurar_Medicos();
    Restaurar_Controles();
}
*/
int main_Configuraciones(){
int opc;
while(true){

        system("cls");
        system ("color 0d");
        cout<<"\n \n \n \n \n \n \n \n \n \n";
        cout<<"\t\t\t\t\t|--------MENU-PACIENTES-----------|"<<endl;
        cout<<"\t\t\t\t\t| 1 = Realizar Backup             |"<<endl;
        cout<<"\t\t\t\t\t| 2 = Restaurar Bakuo             |"<<endl;
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


#endif // CONFIGURACION_H_INCLUDED

