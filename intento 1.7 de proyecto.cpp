#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;
 
 struct pirata{
	char Nombre[100],Genero[100],Estatus[20];
	int Codigo,copias=5;
	float Renta,Venta;
	typedef pirata* sig,ant;
	//Juego sig,ant;
	//typedef pirata* jack;
};
typedef pirata* jack;

class Videojuego{
	private:
	//	struct videojuego{
			char Nombre[100],Genero[100],Estatus[20];
			int Codigo,copias=5;
			float Renta,Venta;
			typedef class Videojuego* Juego;
			
	//	};
	public:
		Juego siguiente,anterior;
		//Videojuego();
		void Registrar(Juego &video);
		void Mostrar(Juego &video,jack &inicio,jack &fin,jack &sparrow);
		void modificar();
		void Reporte_r();
		void Reporte_v();
		void Reporte_d();
		
};
typedef class Videojuego* Juego;
//Videojuego juego;

class Persona{
	private:
		char Nombre[100],Direccion[100],Codigo[100];
		int Edad;
	public:
		void Registrar();
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
		void SetCURP();
		void SetSalario();
		void SetComisiones();
		
};

class Cliente:public Persona{
	
	private:
		char Correo[100];
		Cliente *siguiente,*anterior;
		
	public:
		
};


//void Mostrar(Juego &video,jack &inicio,jack &fin,jack &sparrow);
//void Construccion(Juego &video,Juego &inicio,Juego &fin,int veces);
//void Consulta(Juego inicio);

main()
{
	Juego video=NULL/*,inicio=NULL,fin=NULL*/;
	jack inicio=NULL,fin=NULL,destripador;
	Empleado *esclavo=NULL;
	Cliente *bato=NULL;
	int I=0;
	char opc,opc_e,opc_c,opc_v,contrasenia[50],entrada[50]="contrasenia";
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
						{
							Juego q=NULL;
							q=new Videojuego;
							q->Registrar(video);
						//	Construccion(video,inicio,fin,I);
						}
						break;
					case'2':
						Juego q;
						q->Mostrar(video,inicio,fin,destripador);
					//	Consulta(inicio);
						break;
					case'3':
						break;
					case'4':
						break;
					case'5':
						break;
					case'6':
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
				cout<<endl<<"3)consultar por codigo de cliente ";
				cout<<endl<<"4)lista de empleados ";
				fflush(stdin);
				cin>>opc_e;
				switch(opc_e)
				{
					case'1':
						break;
					case'2':
						break;
					case'3':
						break;
					case'4':
						break;
					default:
						cout<<endl<<"fuera de rango";
						getch();
						break;
				}
				break;
			case'4':
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
/*void Construccion(Juego &video,Juego &inicio,Juego &fin,int veces)
{
	Juego act=NULL,q=NULL;//sig=NULL,ant=NULL;//inicio=NULL,fin=NULL;
//	pos t;
	//q=NULL;
	//q->Registrar(video);
//	if(veces==0)
	if((inicio==NULL))
	{
		cout<<endl<<"no hay nada aun.."<<endl;
		q=new Videojuego;
		//video=q;
		act=q;
		q->Registrar(video);
		q->anterior=NULL;
		q->siguiente=NULL;
		act->anterior=inicio;
		act->siguiente=fin;
		inicio=act;
		fin=act;
		
	}
	else 
	{
		cout<<endl<<"generando..."<<endl;
		act=new Videojuego;
	//	act=q;
		act->Registrar(video);
		act->anterior=NULL;
		act->siguiente=q;
		inicio=act;
		fin=q;
		
	}
}
*/
/*void Consulta(Juego inicio)
{
	
	char busqueda[50];
	int i=0;
//	pos t;
	Juego q;
	q=inicio;
	cout<<endl<<"cual titulo buscas? "<<endl;
	fflush(stdin);
	gets(busqueda);
	for(i=0;q->siguiente==NULL;i++)
	{
		cout<<i<<endl;
		q->Mostrar(busqueda);
		//t=t->sig;
		q=q->siguiente;
	}
}
*/
void Videojuego::Registrar(Juego &video)
{
	int i,j,reg;
	//Juego q;
	//q=video;
	//q->anterior=NULL;
	ofstream entrada;
	entrada.open("videojuegos.dat",ios::out|ios::app|ios::binary);
	if(entrada.fail())
	{
		cout<<endl<<"error al generar arcivo"<<endl;
		getch();
	}
	else
	{
		cout<<endl<<"introdusca el nombre"<<endl;
		fflush(stdin);
		gets(Nombre);
		cout<<endl<<"introdusca el genero"<<endl;
		fflush(stdin);
		gets(Genero);
		cout<<endl<<"estatus \nV)vendido\nD)disponible\nR)rentado\n"<<endl;
		fflush(stdin);
		cin>>Estatus;
		cout<<endl<<"introduce el codigo"<<endl;
		fflush(stdin);
		cin>>Codigo;
		cout<<endl<<"introduce el valor de renta"<<endl;
		cin>>Renta;
		cout<<endl<<"introduce el valor de venta"<<endl;
		cin>>Venta;
		//q->siguiente=video
		entrada.write((char *)&video,sizeof(Videojuego));
		
	}
}

void Videojuego::Mostrar(Juego &video,jack &inicio,jack &fin,jack &sparrow)
{
	int reg,i;
	//cout<<endl<<"huevos...dante...";
	ifstream salida;
	jack botin,barbaciega=NULL;
	salida.open("videojuego.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error "<<endl;
		getch();
	}
	else
	{
		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Videojuego);
		salida.seekg(0);
		for(i=0;i<reg;i++)
		{
			salida.read((char *)&video,sizeof(Videojuego));
			botin=new(struct pirata);
			strcpy(botin->Nombre,video->Nombre);
			strcpy(botin->Genero,video->Genero);
			strcpy(botin->Estatus,video->Estatus);
			botin->Codigo=video->Codigo;
			botin->Venta=video->Venta;
			botin->Renta=video->Renta;
			botin->copias=video->copias;
			if(i==0)
			{
				
			//	jack barbaciega;
				barbaciega=botin;
				botin->ant=NULL;
				botin->sig=inicio;
				inicio=botin;
				fin=botin;
			}
			else
			{
			//	jack barbaciega;
				botin->ant=NULL;
				botin->sig=inicio;
				barbaciega->ant=botin;
				inicio=botin;
			}
		}
		for(i=0;i<reg;i++)
		{
			cout<<endl<<"nombre del juego: "<<botin->Nombre;
			cout<<endl<<"genero: "<<botin->Genero;
			cout<<endl<<"codigo: "<<botin->Codigo;
			cout<<endl<<"costo de renta: "<<botin->Renta;
			cout<<endl<<"costo de venta: "<<botin->Venta;
			cout<<endl;
		}
/*	if((strcmp(Nombre,busco))==0)
	{
	cout<<endl<<"nombre del juego: "<<Nombre;
	cout<<endl<<"genero: "<<Genero;
	cout<<endl<<"codigo: "<<Codigo;
	cout<<endl<<"costo de renta: "<<Renta;
	cout<<endl<<"costo de venta: "<<Venta;
	cout<<endl;
	}*/
	}
}
	
