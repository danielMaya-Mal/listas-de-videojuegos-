#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;
 
 /*struct pirata{
	char Nombre[100],Genero[100],Estatus[20];
	int Codigo,copias=5;
	float Renta,Venta;
	struct pirata* sig;
	struct pirata* ant;
	//Juego sig,ant;
	//typedef pirata* jack;
};
typedef pirata* jack;
*/
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
		void Mostrar();
		void modificar();
		void Reporte_r();
		void Reporte_v();
		void Reporte_d();
		
};
typedef class Videojuego* Juego;

main()
{
	Juego video=NULL,inicio=NULL,final=NULL;
	int I=0,i=1;
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
							Juego q=NULL,t=NULL;
							if(I==0)
							{
								q=new Videojuego;
								q->anterior=NULL;
								q->siguiente=NULL;
								q->Registrar(video);
								inicio=q;
								final=q;
								//q->siguiente=video;
								inicio=q;
								t=q;
							}
							else
							{
								q=new Videojuego;
								q->anterior=NULL;
								q->Registrar(video);
								q->siguiente=t;
								t->anterior=q;
								inicio=q;
								t=q;
							}
						//	Construccion(video,inicio,fin,I);
							
						}
						break;
					case'2':
						Juego q;
						q=inicio;
						for(i=1;i<I;i++)
						{
							q->Mostrar();
							q=q->siguiente;
						}
					//	q->Mostrar(video,inicio,fin,destripador);
					//	Consulta(inicio);
						break;
}

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
		cout<<endl<<"error al generar archivo"<<endl;
		getch();
	}
	else
	{
		cout<<endl<<"introdusca el nombre"<<endl;
		fflush(stdin);
		gets(Nombre);
		cout<<endl<<Nombre;
		cout<<endl<<"introdusca el genero"<<endl;
		fflush(stdin);
		gets(Genero);
		cout<<endl<<Genero;
		cout<<endl<<"estatus \nV)vendido\nD)disponible\nR)rentado\n"<<endl;
		fflush(stdin);
		cin>>Estatus;
		cout<<endl<<Estatus;
		cout<<endl<<"introduce el codigo"<<endl;
		fflush(stdin);
		cin>>Codigo;
		cout<<endl<<Codigo;
		cout<<endl<<"introduce el valor de renta"<<endl;
		cin>>Renta;
		cout<<endl<<Renta;
		cout<<endl<<"introduce el valor de venta"<<endl;
		cin>>Venta;
		cout<<endl<<Venta;
		//q->siguiente=video
		entrada.write((char *)&video,sizeof(Videojuego));
		entrada.close();
		
	}
}
void Videojuego::Mostrar()
{
	cout<<endl<<"nombre del juego: "<<Nombre;
	cout<<endl<<"genero: "<<Genero;
	cout<<endl<<"codigo: "<<Codigo;
	cout<<endl<<"costo de renta: "<<Renta;
	cout<<endl<<"costo de venta: "<<Venta;
	cout<<endl;
}	
