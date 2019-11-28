//Biblioteca de empleado
#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std; 

struct esclavo{
	char Nombre[100],Direccion[100],Codigo[100];
	char CURP[20];
	float Salario,Comisiones;
	struct esclavo* ant;
	struct esclavo* sig;
}; 
typedef esclavo* obrero; 

class Persona{		
	public:
		char Nombre[100],Direccion[100],Codigo[100];
		int Edad;
	//	virtual void Registrar();
		void consulta();
		void consultar_Cod();
		void Modificar();
	//	void ListaClientes();
};

class Empleado:public Persona{
	private:
		char CURP[20];
		float Salario,Comisiones;
		Empleado *siguiente,*anterior;
		
	public:
		Empleado();
		void Registrar();
		void consulta(/*char *busco*/);
		void consultar_Cod(/*int x*/);
		void Lista_empleados(obrero &inicio,obrero &fin);
		float asignar_c(char *codigo,float adicion);
		//void SetCURP();
		//void SetSalario();
		//void SetComisiones();
		
};
Empleado esclavo; 
void Persona::consulta()
{
	cout<<endl<<"nombre: "<<Nombre;
	cout<<endl<<"direccion: "<<Direccion;
}
void Persona::consultar_Cod()
{
	cout<<endl<<"nombre: "<<Nombre;
	cout<<endl<<"direccion: "<<Direccion;
}
Empleado::Empleado()
{
	Salario=6000.00;
	Comisiones=0.0;
}
float Empleado::asignar_c(char *codigo,float adicion)
{
	int reg,i;
		ifstream salida;
		ofstream entrada;
		entrada.open("emigracion.dat",ios::out|ios::app|ios::binary);
		salida.open("Empleados.dat",ios::in|ios::binary);
		if(salida.fail()||entrada.fail())
		{
			cout<<endl<<"error al generar el archivo..."<<endl;
			getch();
			
		}
		else
		{
			salida.seekg(0,ios::end);
			reg=salida.tellg()/sizeof(Empleado);
			salida.seekg(0);
			for(i=0;i<reg;i++)
			{
				salida.read((char *)&esclavo,sizeof(Empleado));
				if(strcmp(codigo,esclavo.Codigo)==0)
				{
					Comisiones=0;
					Comisiones=(adicion*0.02);
					Salario=Salario+(Comisiones);
					cout<<endl<<"salario "<<Salario;
				}
				entrada.write((char *)&esclavo,sizeof(Empleado));
				
			}
			salida.close();
			entrada.close();
			remove("Empleados.dat");
			rename("emigracion.dat","Empleados.dat");
			cout<<endl<<"comision asignada ";
			getch();
		}
}

void Empleado::Registrar()
{
	Salario=6000.00;
	Comisiones=0.0;
	ofstream entrada;
	entrada.open("Empleados.dat",ios::out|ios::app|ios::binary);
	if(entrada.fail())
	{
		cout<<endl<<"error al generar archivo"<<endl;
		getch();
	}
	else
	{
		//Persona::Registrar();
		cout<<endl<<"introdusca el nombre "<<endl;
		fflush(stdin);
		gets(Nombre);
		cout<<endl<<"introduce el codigo de empleado "<<endl;
		fflush(stdin);
		cin>>Codigo;
		cout<<endl<<"Introduce el domicilio ";
		fflush(stdin);
		gets(Direccion);
		cout<<endl<<"Introduce la curp ";
		fflush(stdin);
		gets(CURP);
	
	
		entrada.write((char *)&esclavo,sizeof(Empleado));
		entrada.close();
	}
	
}
void Empleado::consultar_Cod()
{
	ifstream salida;
	//ofstream entrada;
	char busco[50];
	int reg,i;
	salida.open("Empleados.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error al generar el archivo "<<endl;
		getch();
	}
	else
	{
		cout<<endl<<"introdusca el codigo del empleado que busca  "<<endl;
		fflush(stdin);
		gets(busco);
		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Empleado);
		salida.seekg(0);
		cout<<endl<<reg<<endl;
		for(i=0;i<reg;i++)
			{
				salida.read((char *)&esclavo,sizeof(Empleado));
				if(strcmp(busco,esclavo.Codigo)==0)
				{
					cout<<endl<<"entraste "<<endl;
					//cout<<endl<<"nombre: "<<Nombre;
					Persona::consultar_Cod();
					cout<<endl<<"CURP: "<<CURP;
					
				}
	
			}
		salida.close();
	}
}
void Empleado::consulta(/*char *busco*/)
{
	ifstream salida;
	//ofstream entrada;
	char busco[50];
	int reg,i;
	salida.open("Empleados.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error al generar el archivo "<<endl;
		getch();
	}
	else
	{
		cout<<endl<<"Nombre de empleado a buscar  "<<endl;
		fflush(stdin);
		gets(busco);
		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Empleado);
		salida.seekg(0);
		cout<<endl<<reg<<endl;
		for(i=0;i<reg;i++)
			{
				salida.read((char *)&esclavo,sizeof(Empleado));
				if(strcmp(busco,esclavo.Nombre)==0)
				{
					cout<<endl<<"entraste "<<endl;
					//cout<<endl<<"nombre: "<<Nombre;
					Persona::consulta();
					cout<<endl<<"CURP: "<<CURP;
					
				}
	
			}
		salida.close();
	}
}


void Empleado::Lista_empleados(obrero &inicio,obrero &fin)
{
	int reg,i;
	ifstream salida;
	obrero q,t=NULL;
	salida.open("Empleados.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error "<<endl;
		getch();
	}
	else
	{

		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Empleado);
		salida.seekg(0);
		cout<<endl<<reg<<endl;
		for(i=0;i<reg/*botin->sig!=NULL*/;i++)
		{
			salida.read((char *)&esclavo,sizeof(Empleado));
			q=new(struct esclavo);
			//pirata copia;
		//	cout<<"nombre "<<Nombre<<endl;
			strcpy(q->Nombre,Nombre);
			strcpy(q->Direccion,Direccion);
			strcpy(q->CURP,CURP);
			strcpy(q->Codigo,Codigo);
		//	q->Codigo=Codigo;
			q->Salario=Salario;
			q->Comisiones=Comisiones;
			
			if(i==0)
			{
			//	jack barbaciega;
				t=q;
				q->ant=NULL;
				q->sig=inicio;
				inicio=q;
				fin=q;
			}
			else
			{
			//	jack barbaciega;
				q->ant=NULL;
				q->sig=inicio;
				t->ant=q;
				inicio=q;
			}
		}
		for(i=0;i<reg;i++)
		{
			cout<<endl<<"nombre: "<<q->Nombre;
			cout<<endl<<"CURP: "<<q->CURP;
			cout<<endl<<"direccion: "<<q->Direccion;
			cout<<endl<<"salario: "<<q->Salario;
			cout<<endl;
			q=q->sig;
			getch();
		}
		salida.close();
	}
}




