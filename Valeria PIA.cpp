//Valeria Paola Reyna Martinez PIA

#include <iostream>
#include<string>
#include<fstream>

using namespace std;
void alta();
void modificacion();
void listas();
void eliminar();
void archivos();

struct infoprecio
{
    int cant;
    float precio;
    float total;
    float totalIVA;
};

struct infocita
{
    string nombre;
    int numcita = 0;
    string tratamiento;
    string descripcion;
    string hora;
};

infocita altacita[3];
infoprecio preciototal[3];
int opcion, i, j, Alta;
float iva;
int main()
{
    cout << "\t CITAS DENTISTA \n";
    cout << "1.- Alta cita \n";
    cout << "2.- Modificacacion cita \n";
    cout << "3.- lista de citas \n";
    cout << "4.- Eliminar cita \n";
    cout << "5.- limpiar pantalla \n";
    cout << "6.- Salir \n";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        alta();
        return main();
        break;

    case 2:
        modificacion();
        return main();
        break;

    case 3:
        listas();
        return main();
        break;

    case 4:
        eliminar();
        return main();
        break;

    case 5:
        system("cls");
        return main();
        break;

    case 6:
        archivos();
        printf("gracias \n");
        break;
    }

}

void alta()
{

    for (i = 0; i < 3; i++)
    {
        cin.ignore();
        cout << "Escriba el nombre del paciente: \n";
        getline(cin, altacita[i].nombre);
        cout << "que tratamiento se hara? \n";
        cin >> altacita[i].tratamiento;
        cout << "Precio unitario: \n";
        cin >> preciototal[i].precio;
        cout << "Cantidad del tratamiento\n";
        cin >> preciototal[i].cant;
        cin.ignore();
        cout << "Describa el tratamiento: \n";
        getline(cin, altacita[i].descripcion);
        cout << "Hora \n";
        cin >> altacita[i].hora;

        preciototal[i].total = preciototal[i].precio * preciototal[i].cant;
        iva = preciototal[i].total * 0.16;
        preciototal[i].totalIVA = preciototal[i].total + iva;
    }
}

void modificacion()
{
    cout << "ingrese el num de cita \n";
    cin >> j;
    j = j - 1;
    for (i = j; i == j; i++)
    {
        cout << "tratamiento \n";
        cin >> altacita[i].tratamiento;
        cout << "Precio unitario \n";
        cin >> preciototal[i].precio;
        cout << "Cantidad del tratamiento \n";
        cin >> preciototal[i].cant;
        cout << "Hora \n";
        cin >> altacita[i].hora;

        preciototal[i].total = preciototal[i].precio * preciototal[i].cant;
        iva = preciototal[i].total * 0.16;
        preciototal[i].totalIVA = preciototal[i].total + iva;
    }
}

void listas()
{
    for (i = 0; i < 3; i++)
    {
        altacita[i].numcita = i + 1;
        cout << "Su cita es:" << altacita[i].numcita << endl;
        cout << altacita[i].nombre << endl;
        cout << altacita[i].tratamiento << endl;
        cout << altacita[i].hora << endl;
        cout << "El precio sin iva es: " << preciototal[i].total << endl;
        cout << "Precio con IVA: " << preciototal[i].totalIVA << endl;
    }
}

void eliminar()
{
    int j;
    cout << "ingrese la cita que desea eliminar";
    cin >> j;
    j = j - 1;
    for (int i = j; i == j; i++)
    {
        cout << "Eliminando registro" << j + 1 << endl;

        altacita[i].descripcion = " ";
        altacita[i].nombre = " ";
        altacita[i].hora = " ";
        altacita[i].tratamiento = " ";
        preciototal[i].cant = 0;
        preciototal[i].precio = 0;
        preciototal[i].total = 0;
        preciototal[i].totalIVA = 0;
    }
}

void archivos()
{
    ofstream archivo;
    string nombrearchivo;
    int texto;
    string texto2;

    nombrearchivo = "altacitas";

    archivo.open(nombrearchivo.c_str(), ios::out);

    if (archivo.fail())
    {
        cout << "ERROR No se guardo el archivo";
        exit(1);
    }

    for (int i = 0; i < 3; i++)
    {
        archivo << "LISTA DE CITAS";
        archivo << altacita[i].nombre << "\n";
        archivo << altacita[i].tratamiento << "\n";
        archivo << preciototal[i].cant << "\n";
        archivo << altacita[i].descripcion << "\n";
        archivo << preciototal[i].total << "\n";
        archivo << preciototal[i].totalIVA << "\n";
    }
    archivo.close();

    //Las citas se gurdan al salir del programa . en C:,en los proyectos de visual , En el nombre del proyecto :3 y se gurardan las 3 citas 
}
