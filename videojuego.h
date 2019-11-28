#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;
struct nodo{
	char Nombre[100],Genero[100],Estatus[20],Codigo[100];
	//int Codigo;
	int unidades;
	int prestado;
	int vendido;
	float Renta,Venta;
	struct nodo* sig;
	struct nodo* ant;
	//Juego sig,ant;
	//typedef pirata* jack;
};
typedef nodo* disco;


typedef class Videojuego* Juego;
class Videojuego{
	private:
	//	struct videojuego{
			char Nombre[100],Genero[100],Estatus[20],Codigo[100];
			int unidades,prestado,vendido;
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
		void Reporte_r(disco &inicio,disco &fin,disco &lista);
		void Reporte_v();
		void Reporte_d(disco &inicio,disco &fin,disco &lista);
		float Ventas_Renta(char *barbaciega);
		float Ventas_Rentas(char *barbaciega);
		float getRenta(char *barbaciega);
		float getVenta(char *barbaciega);
		
};

Videojuego video;

Videojuego::Videojuego()
{
	unidades=5;
	prestado=0;
	vendido=0;
}
float Videojuego::getRenta(char *barbaciega)
{
	int reg,i;
		ifstream salida;
		//cout<<endl<<"introduce el nombre del videojuego que quieres modificar "<<endl;
		//fflush(stdin);
		//gets(busco);
		salida.open("videojuegos.dat",ios::in|ios::binary);
		if(salida.fail())
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
				if(strcmp(barbaciega,video.Codigo)==0)
				{
					return Renta;
				}
			}
			salida.close();
}
}
float Videojuego::getVenta(char *barbaciega)
{
		int reg,i;
		ifstream salida;
		//cout<<endl<<"introduce el nombre del videojuego que quieres modificar "<<endl;
		//fflush(stdin);
		//gets(busco);
		salida.open("videojuegos.dat",ios::in|ios::binary);
		if(salida.fail())
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
				if(strcmp(barbaciega,video.Codigo)==0)
				{
					return Venta;
				}
			}
			salida.close();
		}
}

float Videojuego::Ventas_Rentas(char *barbaciega)
{
	if(unidades!=1)
	{
		int reg,i;
		ifstream salida;
		ofstream entrada;
		//cout<<endl<<"introduce el nombre del videojuego que quieres modificar "<<endl;
		//fflush(stdin);
		//gets(busco);
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
				if(strcmp(barbaciega,video.Codigo)==0)
				{
					unidades=unidades-1;
					prestado++;
				}
				entrada.write((char *)&video,sizeof(Videojuego));
			}
			salida.close();
			entrada.close();
			remove("videojuegos.dat");
			rename("exodo.dat","videojuegos.dat");
			cout<<endl<<"Renta asignada..."<<endl;
			getch();
		}
	}
	else
	{
		cout<<endl<<"los sentimos no hay copias disponibles en este momento..."<<endl;
		getch();
	}
	
}
float Videojuego::Ventas_Renta(char *barbaciega)
{
	if(unidades!=1)
	{
		int reg,i;
		char busco_v[100];
		ifstream salida;
		ofstream entrada;
		//cout<<endl<<"introduce el nombre del videojuego que quieres modificar "<<endl;
		//fflush(stdin);
		//gets(busco);
		entrada.open("exodo.dat",ios::out|ios::app|ios::binary);
		salida.open("videojuegos.dat",ios::in|ios::binary);
		if(salida.fail()||entrada.fail())
		{
			cout<<endl<<"error al generar el archivo..."<<endl;
			getch();
			
		}
		else
		{
			//cout<<endl<<"introdusca el codigo del videojuego"<<endl;
			//fflush(stdin);
			//gets(busco_v);
			salida.seekg(0,ios::end);
			reg=salida.tellg()/sizeof(Videojuego);
			salida.seekg(0);
			for(i=0;i<reg;i++)
			{
				salida.read((char *)&video,sizeof(Videojuego));
				if(strcmp(barbaciega,video.Codigo)==0)
				{
					unidades=unidades-1;
					//prestado++;
					vendido++;
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
	else
	{
		cout<<endl<<"los sentimos no hay copias disponibles en este momento..."<<endl;
		getch();
	}
	
}
void Videojuego::Registrar()
{
	//int i,j,reg;
	//Juego q;
	//q=video;
	//q->anterior=NULL;
	unidades=5;
	Renta=0;
	Venta=0;
	prestado=0;
	vendido=0;
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
		gets(Codigo);
		//cin>>Codigo;
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
			strcpy(q->Codigo,Codigo);
		//	q->Codigo=Codigo;
			q->Venta=Venta;
			q->Renta=Renta;
			q->unidades=unidades;
			
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
		delete(q);
		salida.close();
			
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
				gets(Codigo);
				//cin>>Codigo;
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

void Videojuego::Reporte_r(disco &inicio,disco &fin,disco &lista)
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
		//	cout<<endl<<"copias rentadas: "<<prestado;
		//	cout<<endl;
			q=new(struct nodo);
			//pirata copia;
			strcpy(q->Nombre,Nombre);
			strcpy(q->Genero,Genero);
			strcpy(q->Estatus,Estatus);
			strcpy(q->Codigo,Codigo);
			//q->Codigo=Codigo;
			q->Venta=Venta;
			q->Renta=Renta;
			q->unidades=unidades;
			q->prestado=prestado;
			q->vendido=vendido;
			
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
	}
	for(i=0;i<reg;i++)
	{
		cout<<endl<<"videojuego: "<<q->Nombre;
		cout<<endl<<"unidades rentadas: "<<q->prestado;
		cout<<endl;
		getch();
		q=q->sig;
	}
	salida.close();
	delete(q);
	
}

void Videojuego::Reporte_d(disco &inicio,disco &fin,disco &lista)
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
			//cout<<endl<<"copias rentadas: "<<unidades;
			//cout<<endl;
			q=new(struct nodo);
			//pirata copia;
			strcpy(q->Nombre,Nombre);
			strcpy(q->Genero,Genero);
			strcpy(q->Estatus,Estatus);
			strcpy(q->Codigo,Codigo);
			//q->Codigo=Codigo;
			q->Venta=Venta;
			q->Renta=Renta;
			q->unidades=unidades;
			q->prestado=prestado;
			q->vendido=vendido;
			
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
	}
	for(i=0;i<reg;i++)
	{
		cout<<endl<<"videojuego: "<<q->Nombre;
		cout<<endl<<"unidades disponibles: "<<q->unidades;
		cout<<endl;
		getch();
		q=q->sig;
	}
	salida.close();
	delete(q);
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
			cout<<endl<<"videojuego: "<<Nombre;
			cout<<endl<<"copias vendidas: "<<vendido;
			cout<<endl;
		}
		salida.close();
		getch();
	}
}

