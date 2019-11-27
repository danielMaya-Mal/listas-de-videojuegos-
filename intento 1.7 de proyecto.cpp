#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<string.h>
#include"videojuego.h"
using namespace std;
 
 
//Videojuego juego;
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
		//virtual void Registrar();
		void Consultar_Nom();
		void Consultar_Cod();
		void Modificar();
		void ListaClientes();
};

class Empleado:public Persona{
	private:
		char CURP[20];
		float Salario,Comisiones;
		Empleado *siguiente,*anterior;
		
	public:
		Empleado();
		void Registrar();
		void consulta(char *busco);
		void consulta(int x);
		void Lista_empleados(obrero &inicio,obrero &fin);
		//void SetCURP();
		//void SetSalario();
		//void SetComisiones();
		
};

class Cliente:public Persona{
	
	private:
		int tel;
		char Correo[100];
		Cliente *siguiente,*anterior;
		
	public:
		
};


//void Mostrar(Juego &video,jack &inicio,jack &fin,jack &sparrow);
//void Construccion(Juego &video,Juego &inicio,Juego &fin,int veces);
Empleado esclavo;
//void Consulta(Juego inicio);
void Renta_Venta();
//Videojuego video;
main()
{
	//Juego video=NULL,ini=NULL,final=NULL;
	disco inicio=NULL,fin=NULL,lista;
	obrero ini=NULL,final=NULL;
//	Empleado *esclavo=NULL;
	Cliente *bato=NULL;
	int I=0;
	char opc,opc_e,opc_c,opc_v,contrasenia[50],entrada[50]="contrasenia",busco[100];
	for(;;)
	{
		cout<<endl<<"introduce la contrasenia para entrar al sistema"<<endl;
		fflush(stdin);
		gets(contrasenia);
		system("CLS");
		if((strcmp(contrasenia,entrada)==0))
		{
			system("CLS");
			break;
		}
	}
	do
	{
		cout<<endl<<"1)clientes  ";
		cout<<endl<<"2)videojuegos ";
		cout<<endl<<"3)empleados ";
		cout<<endl<<"4)realizar venta/renta ";
		cout<<endl<<"5)salir del sistema ";
		fflush(stdin);
		cin>>opc;
		system("CLS");
		switch(opc)
		{
			case '1':
				cout<<endl<<"1)registrar ";
				cout<<endl<<"2)consultar por nombre ";
				cout<<endl<<"3)consultar por codigo de cliente ";
				cout<<endl<<"4)modificar ";
				cout<<endl<<"5)consultar lista de clientes ";
				fflush(stdin);
				cin>>opc_c;
				switch(opc_c)
				{
					case'1':
						break;
					case'2':
						break;
					case'3':
						break;
					case'4':
						break;
					case'5':
						break;
					default: 
					cout<<endl<<"fuera de rango "<<endl;
					getch();
					break;
				}
				break;
			case'2':
				cout<<endl<<"1)Registrar ";
				cout<<endl<<"2)consultar por nombres ";
				cout<<endl<<"3)modificar ";
				cout<<endl<<"4)reporte de videojuegos rentados ";
				cout<<endl<<"5)reporte de vidojuegos vendidos ";
				cout<<endl<<"6)reporte de videojuegos disponibles ";
				fflush(stdin);
				cin>>opc_v;
				switch(opc_v)
				{
					case'1':
						video.Registrar();
						break;
					case'2':
						video.Mostrar(inicio,fin,lista);
						break;
					case'3':
						video.modificar();
						break;
					case'4':
						video.Reporte_r(inicio,fin,lista);
						break;
					case'5':
						video.Reporte_v();
						break;
					case'6':
						video.Reporte_d(inicio,fin,lista);
						break;
					default:
						cout<<endl<<"valor fuera de rango ";
						getch();
						break;		
				}
				system("CLS");
				break;
			case'3':
				cout<<endl<<"1)registrar ";
				cout<<endl<<"2)consulta por nombre";
				cout<<endl<<"3)consultar por codigo de empleado ";
				cout<<endl<<"4)lista de empleados ";
				fflush(stdin);
				cin>>opc_e;
				switch(opc_e)
				{
					case'1':
						esclavo.Registrar();
						break;
					case'2':
						cout<<endl<<"Nombre de empleado a buscar  "<<endl;
						fflush(stdin);
						gets(busco);
						esclavo.consulta(busco);
						break;
					case'3':
						esclavo.consulta(I);
						break;
					case'4':
						esclavo.Lista_empleados(ini,final);
						break;
					default:
						cout<<endl<<"fuera de rango";
						getch();
						break;
				}
				getch();
				system("CLS");
				break;
			case'4':
				Renta_Venta();
				break;
			case'5':
				break;
			default: 
				cout<<endl<<"valor fuera de rango"<<endl;
				break;
		}
	}
	while(opc!='5');
}

void Renta_Venta()
{
	char desicion,busco_v[100],busco_r[100];
	float costo;
	cout<<endl<<"has entrado "<<endl;
	getch();
	cout<<endl<<"usted quiere comprar o rentar? \nV)compra\nR)renta"<<endl;
	fflush(stdin);
	cin>>desicion;
	switch(desicion)
	{
		case'V':
			cout<<endl<<"introdusca el codigo de cliente"<<endl;
			getch();
			cout<<endl<<"introdusca el codigo de empleado"<<endl;
			getch();
			costo=video.Ventas_Rentas();
			cout<<endl<<"costo acumulado: "<<costo;
			break;
		case'R':
			cout<<endl<<"introdusca el codigo de cliente"<<endl;
			getch();
			cout<<endl<<"introdusca el codigo de empleado"<<endl;
			getch();
			cout<<endl<<"introdusca el codigo del videojuego"<<endl;
			fflush(stdin);
			gets(busco_r);
			costo=video.Ventas_Rentas(busco_r);
		//	cout<<endl<<"costo acumulado: "<<costo;
			break;
		default:
			cout<<endl<<"valor fuera de rango"<<endl;
			break;
	}
	
}


Empleado::Empleado()
{
	Salario=6000.00;
	Comisiones=0.0;
}

void Empleado::Registrar()
{
	ofstream entrada;
	entrada.open("Empleados.dat",ios::out|ios::app|ios::binary);
	if(entrada.fail())
	{
		cout<<endl<<"error al generar archivo"<<endl;
		getch();
	}
	else
	{
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
void Empleado::consulta(char *busco)
{
	ifstream salida;
	//ofstream entrada;
	//char busco[50];
	int reg,i;
	salida.open("Empleados.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error al generar el archivo "<<endl;
		getch();
	}
	else
	{
		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Empleado);
		salida.seekg(0);
		cout<<endl<<reg<<endl;
		for(i=0;i<reg;i++)
			{
				salida.read((char *)&esclavo,sizeof(Empleado));
				if(strcmp(busco,esclavo.Nombre)==0)
				{
					cout<<endl<<"nombre: "<<Nombre;
					cout<<endl<<"CURP: "<<CURP;
					cout<<endl<<"direccion: "<<Direccion;
				}
	
			}
		salida.close();
	}
}

void Empleado::consulta(int x)
{
	ifstream salida;
	//ofstream entrada;
	char busco[50];
	int reg,i;
	cout<<endl<<"introdusca el codigo del empleado a buscar  "<<endl;
	fflush(stdin);
	gets(busco);
	salida.open("Empleados.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error al generar el archivo "<<endl;
		getch();
	}
	else
	{
		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Empleado);
		salida.seekg(0);
		cout<<endl<<reg<<endl;
		for(i=0;i<reg;i++)
			{
				salida.read((char *)&esclavo,sizeof(Empleado));
				if(strcmp(busco,esclavo.Codigo)==0)
				{
					cout<<endl<<"nombre: "<<Nombre;
					cout<<endl<<"CURP: "<<CURP;
					cout<<endl<<"direccion: "<<Direccion;
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
			salida.read((char *)&video,sizeof(Empleado));
			q=new(struct esclavo);
			//pirata copia;
			cout<<"nombre "<<Nombre<<endl;
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
			cout<<endl<<"comision: "<<q->Comisiones;
			cout<<endl;
			q=q->sig;
			getch();
		}
		salida.close();
	}
}




