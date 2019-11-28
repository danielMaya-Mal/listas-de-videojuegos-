#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<string.h>
#include"videojuego.h"
#include"clientes.h"
#include"empleado.h"
using namespace std;
 
 

void Renta_Venta();

main()
{
	//Juego video=NULL,ini=NULL,final=NULL;
	disco inicio=NULL,fin=NULL,lista;
	obrero ini=NULL,final=NULL;
	Comprador c_inicio=NULL,c_fin=NULL,c_lista;
//	Empleado *esclavo=NULL;
	Cliente *bato=NULL;
	int I=0;
	char opc,opc_e,opc_c,opc_v,contrasenia[50],entrada[50]="contrasenia",buscador[100];
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
						Adoran.Registrar();
						break;
					case'2':
						Adoran.Consultar_Nom(c_inicio,c_fin,c_lista);
						break;
					case'3': 
					    Adoran.Consultar_Cod(c_inicio,c_fin,c_lista);
						break;
					case'4':
						Adoran.Modificar(c_inicio,c_fin,c_lista);
						getch();
						break;
					case'5':
						Adoran.Mostrar(c_inicio,c_fin,c_lista);
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
						esclavo.consulta();
						break;
					case'3':
						esclavo.consultar_Cod();
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
	char desicion,voluntad,busco_v[100],busco_r[100],busco_c[100];
	int r=0,v=0;
	float costo;
//	cout<<endl<<"has entrado "<<endl;
	getch();
	do
	{
	cout<<endl<<"usted quiere comprar o rentar? \nV)compra\nR)renta"<<endl;
	fflush(stdin);
	cin>>desicion;
	switch(desicion)
	{
		case'V':
			cout<<endl<<"introdusca el codigo de cliente"<<endl;
			fflush(stdin);
		    gets(busco_c);
			if(Adoran.Permiso(busco_c)==1)
			{
				cout<<endl<<"introdusca el codigo del videojuego"<<endl;
				fflush(stdin);
				gets(busco_v);
				video.Ventas_Renta(busco_v);
				costo=video.getVenta(busco_v);
				cout<<endl<<"introdusca el codigo de empleado"<<endl;
			//	getch(busc);
				cout<<endl<<"introdusca el codigo de empleado"<<endl;
						//getch();
				gets(busco_v);
				esclavo.asignar_c(busco_v,costo);
				cout<<endl<<"costo acumulado: "<<costo;
			}
			else
			{
				Adoran.Registrar();
				cout<<"\nRegistrado";
			}
			break;
		case'R':
					cout<<endl<<"introdusca el codigo de cliente"<<endl;
					fflush(stdin);
					gets(busco_c);
					if(Adoran.Permiso(busco_c)<3)
					{
					cout<<endl<<"introdusca el codigo del videojuego"<<endl;
					fflush(stdin);
					gets(busco_r);
					video.Ventas_Rentas(busco_r);
					costo=video.getRenta(busco_r);
					cout<<endl<<costo;
					cout<<endl<<"introdusca el codigo de empleado"<<endl;
					//getch();
					gets(busco_r);
					esclavo.asignar_c(busco_r,costo);
					//	cout<<endl<<"costo acumulado: "<<costo;
					r++;
				}
				else 
				{
					cout<<endl<<"a alcanzado su limite de rentas... compa... le recordamos que los juegos no devueltos presntan cargos de 50000...."<<endl;
					getch();
					cout<<endl<<"el respeto al derecho ajeno es la paz..."<<endl;
				}
			break;
		default:
			cout<<endl<<"valor fuera de rango"<<endl;
			break;
	}
	cout<<endl<<"quiere rentar o comprar otro videojuego? "<<endl;
	fflush(stdin);
	cin>>voluntad;
	}
	while(voluntad!='n');
	
}


