#include <iostream>
using namespace std;

const char *nombre_archivo="archivo.dat";

struct Estudiante{
	
	int codigo;
	char nombre[50];
	char apellidos[50];
	int telefono;	
};

void Crear();
void Leer();
void Actualizar();
void Borrar();


main(){
	Leer();
	Crear();
	Actualizar();
	Borrar();
	system("pause");
}
void Leer(){
	system("cls");
	FILE* archivo=fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo=fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id=0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"_________________________________________________"<<endl;
	cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"telefono"<<endl;
	do{
		
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombre<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id += 1;
	}while(feof(archivo)==0);
	fclose(archivo);
	
}
void Crear(){
	FILE* archivo=fopen(nombre_archivo,"a+b");
	char res;
	Estudiante  estudiante;
	do{
		fflush(stdin);
		cout<<"Ingrese codigo ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese nombre ";
		cin.getline(estudiante.nombre,50);
		cout<<"Ingrese apellido ";
		cin.getline(estudiante.apellidos,50);
		cout<<"Ingrese telefono ";
		cin>>estudiante.telefono;
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Desea ingresar otro estudiante ";
		cin>>res;
	}while(res=='s' || res=='S');
	Leer();
	fclose(archivo);
}

void Actualizar(){
	FILE* archivo=fopen(nombre_archivo,"r+b");
	Estudiante  estudiante;
	int id=0;
	cout<<"Ingrese la posicion del archivo que quiere actualizar "<<endl;
	cin>>id;
	id-1;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
		fflush(stdin);
		cout<<"Ingrese codigo ";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese nombre ";
		cin.getline(estudiante.nombre,50);
		cout<<"Ingrese apellido ";
		cin.getline(estudiante.apellidos,50);
		cout<<"Ingrese telefono ";
		cin>>estudiante.telefono;
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
	
	Leer();
	fclose(archivo);
	
}

void Borrar(){
const char *nombre_archivo_temp ="archivo2.dat";
FILE* archivo=fopen(nombre_archivo,"rb");
FILE* archivo_temp=fopen(nombre_archivo_temp,"w+b");
Estudiante estudiante;
int id=0,id_n=0;
cout<<"Ingrese el id a borrar "<<endl;
cin>>id;

while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
	if(id_n!=id){
		fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
	}
	id_n++;
}
fclose(archivo);
fclose(archivo_temp);
archivo=fopen(nombre_archivo,"rb");
archivo_temp=fopen(nombre_archivo_temp,"wb");
while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
}
fclose(archivo);
fclose(archivo_temp);
Leer();
}

