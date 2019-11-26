#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;
 
 struct nodo{
	char Nombre[100],Genero[100],Estatus[20];
	int Codigo,copias=5,prestado=0,vendido=0;
	float Renta,Venta;
	struct nodo* sig;
	struct nodo* ant;
	//Juego sig,ant;
	//typedef pirata* jack;
};
typedef nodo* disco;

class Videojuego{
	private:
	//	struct videojuego{
			char Nombre[100],Genero[100],Estatus[20];
			int Codigo,copias=5,prestado=0,vendido=0;
			float Renta,Venta;
		//	disco genesis;
			typedef class Videojuego* Juego;
			
	//	};
	public:
		//Juego siguiente,anterior;
		Videojuego();
		void Registrar();
		void Mostrar(disco &inicio,disco &fin,disco &lista);
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
//void Renta_Venta();
Videojuego video;
main()
{
	//Juego video=NULL,ini=NULL,final=NULL;
	disco inicio=NULL,fin=NULL,lista;
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
						video.Registrar();
						break;
					case'2':
						video.Mostrar(inicio,fin,lista);
						break;
					case'3':
						video.modificar();
						break;
					case'4':
						video.Reporte_r();
						break;
					case'5':
						video.Reporte_v();
						break;
					case'6':
						video.Reporte_d();
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
				//Renta_Venta();
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
Videojuego::Videojuego()
{
	copias=5;
	prestado=0;
	vendido=0;
}

void Videojuego::Registrar()
{
	//int i,j,reg;
	//Juego q;
	//q=video;
	//q->anterior=NULL;
	ofstream entrada;
	entrada.open("videojuegos.dat",ios::out|ios::app|ios::binary);
	if(entrada.fail())
	{
		cout<<endl<<"error al generar archivo"<<endl;
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
		entrada.write((char *)&video,sizeof(Videojuego));
		//q->siguiente=video
		entrada.close();
	}
}

void Videojuego::Mostrar(disco &inicio,disco &fin,disco &lista) 
{
	int reg,i;
	ifstream salida;
	disco q,t=NULL;
	salida.open("videojuegos.dat",ios::in|ios::binary);
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
		cout<<endl<<reg<<endl;
		for(i=0;i<reg/*botin->sig!=NULL*/;i++)
		{
			salida.read((char *)&video,sizeof(Videojuego));
		
			q=new(struct nodo);
			//pirata copia;
			strcpy(q->Nombre,Nombre);
			strcpy(q->Genero,Genero);
			strcpy(q->Estatus,Estatus);
			q->Codigo=Codigo;
			q->Venta=Venta;
			q->Renta=Renta;
			q->copias=copias;
			
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
	//	while(botin->sig!=NULL)
		{
			cout<<endl<<"nombre del juego: "<<q->Nombre;
			cout<<endl<<"genero: "<<q->Genero;
			cout<<endl<<"codigo: "<<q->Codigo;
			cout<<endl<<"costo de renta: "<<q->Renta;
			cout<<endl<<"costo de venta: "<<q->Venta;
			cout<<endl;
			q=q->sig;
			getch();
			//botin=botin->sig;
			
		}
	}
}

void Videojuego::modificar()
{
	char busco[100];
	int reg,i;
	ifstream salida;
	ofstream entrada;
	cout<<endl<<"introduce el nombre del videojuego que quieres modificar "<<endl;
	fflush(stdin);
	gets(busco);
	entrada.open("exodo.dat",ios::out|ios::app|ios::binary);
	salida.open("videojuegos.dat",ios::in|ios::binary);
	if(salida.fail()||entrada.fail())
	{
		cout<<endl<<"error al generar el archivo..."<<endl;
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
			if(strcmp(busco,video.Nombre)==0)
			{
				cout<<endl<<"archivo encontrado... "<<endl;
				getch();
				cout<<endl<<"introduce el nuevo nombre del archivo "<<endl;
				fflush(stdin);
				gets(Nombre);
				cout<<endl<<"introdusca el nuevo genero"<<endl;
				fflush(stdin);
				gets(Genero);
				cout<<endl<<"estatus \nV)vendido\nD)disponible\nR)rentado\n"<<endl;
				fflush(stdin);
				cin>>Estatus;
				cout<<endl<<"introduce el nuevo codigo"<<endl;
				fflush(stdin);
				cin>>Codigo;
				cout<<endl<<"introduce el nuevo valor de renta"<<endl;
				cin>>Renta;
				cout<<endl<<"introduce el nuevo valor de venta"<<endl;
				cin>>Venta;
			}
			entrada.write((char *)&video,sizeof(Videojuego));
		}
		salida.close();
		entrada.close();
		remove("videojuegos.dat");
		rename("exodo.dat","videojuegos.dat");
		getch();
	}
}

void Videojuego::Reporte_r()
{
	int i,reg;
	char busco[50];
	ifstream salida;
	salida.open("videojuegos.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error al genera el archivo..."<<endl;
		getch();
		
	}
	else
	{
		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Videojuego);
		salida.seekg(0);
		for(i=0;i<reg;i++)
		{
			fflush(stdin);
			salida.read((char *)&video,sizeof(Videojuego));
			cout<<endl<<"videojuego: "<<Nombre<<endl;
			cout<<endl<<"copias rentadas: "<<prestado;
			cout<<endl;
		}
		salida.close();
		getch();
	}
	
}
void Videojuego::Reporte_v()
{
	int i,reg;
	char busco[50];
	ifstream salida;
	salida.open("videojuegos.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error al genera el archivo..."<<endl;
		getch();
		
	}
	else
	{
		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Videojuego);
		salida.seekg(0);
		for(i=0;i<reg;i++)
		{
			fflush(stdin);
			salida.read((char *)&video,sizeof(Videojuego));
			cout<<endl<<"videojuego: "<<Nombre<<endl;
			cout<<endl<<"copias vendidas: "<<vendido;
			cout<<endl;
		}
		salida.close();
		getch();
	}
}

void Videojuego::Reporte_d()
{
	int i,reg;
	char busco[50];
	ifstream salida;
	salida.open("videojuegos.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error al genera el archivo..."<<endl;
		getch();
		
	}
	else
	{
		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Videojuego);
		salida.seekg(0);
		for(i=0;i<reg;i++)
		{
			fflush(stdin);
			salida.read((char *)&video,sizeof(Videojuego));
			cout<<endl<<"videojuego: "<<Nombre<<endl;
			cout<<endl<<"copias disponibles: "<<copias;
			cout<<endl;
		}
		salida.close();
		getch();
	}
}


	
