
//Biblioteca de cliente
#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std; 


class Persona2{
	protected:
		char Nombre[100],Codigo[100];
		int Edad;
		struct Direccion{
			char Calle[100], Colonia[100]; 
			int Numero,CP;
	     	}Dir;
	public:
		
		void Registrar();
		void Consultar_Nom();
		void Consultar_Cod();
		void Modificar();
		void ListaClientes();
		void consulta();
		void consultar_Cod();
};
typedef class Persona2* Sujeto;

 struct nodo_c{
	char Nombre[100];
	char Codigo[100];
    struct Direccion{
				char Calle[100], Colonia[100]; 
	     		int Numero,CP;
	     	}Dir;
	struct nodo_c* sig;
	struct nodo_c* ant;

};
typedef nodo_c* Comprador; 

class Cliente : public Persona2{
	
	private:
		char Correo[100];
		int telefono, rentas;
		Cliente *siguiente,*anterior;
		
	public:
			Cliente();
			void Registrar();
			void Mostrar(Comprador &inicio,Comprador &fin,Comprador &lista);
			void Consultar_Nom(Comprador &inicio,Comprador &fin,Comprador &lista);
	       	void Consultar_Cod(Comprador &inicio,Comprador &fin,Comprador &lista);
	       	void Modificar(Comprador &inicio,Comprador &fin,Comprador &lista);
	       	int Permiso(char *acceso);
};



Cliente Adoran; 

Cliente::Cliente()
{
	rentas=0;
}

void Cliente::Registrar()
{
	rentas=0;
	ofstream entrada; 
	entrada.open("clientes.dat",ios::out|ios::app|ios::binary);
    if(entrada.fail())
    {
    	cout<<"\nERROR AL GENERAR ARCHIVO \n"; 
    	getch(); 
	} 
	else
	{
		cout<<"\nIntroduzca el nombre: "; 
		fflush(stdin); 
		gets (Nombre);
		cout<<"\nIntroduzca registro: "; 
		fflush(stdin); 
		cin>>Codigo; 
		cout<<"\nInserte domicilio: "; 
		cout<<"\nCalle: "; 
		fflush(stdin); 
		gets(Dir.Calle); 
		 cout<<"\nColonia: "; 
		fflush(stdin); 
		gets(Dir.Colonia);
		cout<<"\nCodigo postal: "; 
		cin>>Dir.CP; 
		entrada.write((char *)&Adoran,sizeof(Cliente)); 
		
		entrada.close();
		
	}
} 
void Cliente::Consultar_Nom(Comprador &inicio,Comprador &fin,Comprador &lista)  
{
		 
	int reg,i;
	char Compara[100];
	ifstream salida;
	Comprador q,t=NULL;
	salida.open("clientes.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error "<<endl;
		getch();
	}
	else
	{

		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Cliente);
		salida.seekg(0);
		cout<<endl<<reg<<endl;
		for(i=0;i<reg;i++)
		{
			salida.read((char *)&Adoran,sizeof(Cliente));
			getch();
		
		
			q=new(struct nodo_c);
	
		
			strcpy(q->Nombre,Nombre);
			cout<<endl<<q->Nombre<<endl;
			strcpy(q->Dir.Calle,Dir.Calle); 
			strcpy(q->Dir.Colonia,Dir.Colonia);
			strcpy(q->Codigo,Codigo);
		
			q->Dir.CP=Dir.CP;
		
			
			if(i==0)
			{
		
				t=q;
				q->ant=NULL;
				q->sig=inicio;
				inicio=q;
				fin=q;
			}
			else
			{
		
				q->ant=NULL;
				q->sig=inicio;
				t->ant=q;
				inicio=q;
			}
		} 
		
		cout<<"Inserta el nombre del cliente: ";
		fflush(stdin);
		gets (Compara);
	
		for(i=0;i<reg;i++)

		{
			if(strcmp(Compara,q->Nombre)==0)
			{
			
			cout<<endl<<"nombre: "<<q->Nombre;
			cout<<endl<<"codigo: "<<q->Codigo;
			cout<<endl<<"Direccion: ";
			cout<<"\nCalle: "<<q->Dir.Calle; 
			cout<<"\nColonia: "<<q->Dir.Colonia;
			cout<<"\nCodigo Postal: "<<q->Dir.CP;
		    }
			
			cout<<endl;
			q=q->sig;
		
		
			
		}
		
       getch();
	}
	
} 

int Cliente::Permiso(char *acceso)
{
	int reg,i;
	char Compara[100];
	ifstream salida;
	Comprador q,t=NULL;
	salida.open("clientes.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error "<<endl;
		getch();
	}
	else
	{

		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Cliente);
		salida.seekg(0);
		cout<<endl<<reg<<endl;
		for(i=0;i<reg;i++)
		{
			salida.read((char *)&Adoran,sizeof(Cliente));
			if(strcmp(acceso,Adoran.Codigo)==0)
			{
				cout<<endl<<"cliente encontrado "<<endl;
				return rentas;
			}
			
		}
		salida.close();
		return 0;
	}
}

void Cliente::Consultar_Cod(Comprador &inicio,Comprador &fin,Comprador &lista)  
{
		 
	int reg,i;
	char Compara[100];
	ifstream salida;
	Comprador q,t=NULL;
	salida.open("clientes.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error "<<endl;
		getch();
	}
	else
	{

		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Cliente);
		salida.seekg(0);
		cout<<endl<<reg<<endl;
		for(i=0;i<reg;i++)
		{
			salida.read((char *)&Adoran,sizeof(Cliente));
			getch();
		
		
			q=new(struct nodo_c);
	
		
			strcpy(q->Nombre,Nombre);
			cout<<endl<<q->Nombre<<endl;
			strcpy(q->Dir.Calle,Dir.Calle); 
			strcpy(q->Dir.Colonia,Dir.Colonia);
			strcpy(q->Codigo,Codigo);
			cout<<endl<<q->Codigo<<endl;
		
			q->Dir.CP=Dir.CP;
		
			
			if(i==0)
			{
		
				t=q;
				q->ant=NULL;
				q->sig=inicio;
				inicio=q;
				fin=q;
			}
			else
			{
		
				q->ant=NULL;
				q->sig=inicio;
				t->ant=q;
				inicio=q;
			}
		} 
		
		cout<<"Inserta el codigo del cliente: ";
		fflush(stdin);
		gets (Compara);
	
		for(i=0;i<reg;i++)

		{
			if(strcmp(Compara,q->Codigo)==0)
			{
			
			cout<<endl<<"nombre: "<<q->Nombre;
			cout<<endl<<"codigo: "<<q->Codigo;
			cout<<endl<<"Direccion: ";
			cout<<"\nCalle: "<<q->Dir.Calle; 
			cout<<"\nColonia: "<<q->Dir.Colonia;
			cout<<"\nCodigo Postal: "<<q->Dir.CP;
		    }
			
			cout<<endl;
			q=q->sig;
		
		
			
		}
		
       getch();
	}
	
} 
void Cliente::Modificar(Comprador &inicio,Comprador &fin,Comprador &lista)  
{
		 
	int reg,i;
	char Compara[100];
	ifstream salida;
	ofstream entrada;
	//Comprador q,t=NULL;
	entrada.open("Clientela.dat",ios::out|ios::app|ios::binary);
	salida.open("clientes.dat",ios::in|ios::binary);
	if(salida.fail()||entrada.fail())
	{
		cout<<endl<<"error "<<endl;
		getch();
	}
	else
	{

		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Cliente);
		salida.seekg(0);
		cout<<endl<<reg<<endl;
			
		cout<<"Inserta el nombre del cliente a modificar: ";
		fflush(stdin);
		gets (Compara);
		for(i=0;i<reg;i++)
		{
			salida.read((char *)&Adoran,sizeof(Cliente));
		//	getch();
		
		
		/*	q=new(struct nodo_c);
	
		
			strcpy(q->Nombre,Nombre);
			cout<<endl<<q->Nombre<<endl;
			strcpy(q->Dir.Calle,Dir.Calle); 
			strcpy(q->Dir.Colonia,Dir.Colonia);
			strcpy(q->Codigo,Codigo);
		
			q->Dir.CP=Dir.CP;
		
			
			if(i==0)
			{
		
				t=q;
				q->ant=NULL;
				q->sig=inicio;
				inicio=q;
				fin=q;
			}
			else
			{
		
				q->ant=NULL;
				q->sig=inicio;
				t->ant=q;
				inicio=q; */
		//	}
		//} 
	
	
		//for(i=0;i<reg;i++)

		//{   salida.read((char *)&Adoran,sizeof(Cliente));
			if(strcmp(Compara,/*q->*/Nombre)==0)
			{
			cout<<endl<<"Informacion actual: \n";
			cout<<endl<<"nombre: "<</*q->*/Nombre;
			cout<<endl<<"codigo: "<</*q->*/Codigo;
			cout<<endl<<"Direccion: ";
			cout<<"\nCalle: "<<Dir.Calle; 
			cout<<"\nColonia: "<<Dir.Colonia;
			cout<<"\nCodigo Postal: "<<Dir.CP;
			getch(); 
			cout<<endl<<"Nuevo Nombre: "; 
			fflush(stdin); 
			gets(Nombre);
			cout<<endl<<"Nuevo Codigo: "; 
			fflush(stdin); 
			gets(Codigo);
			cout<<endl<<"Nueva direccion:\n "; 
			cout<<endl<<"Calle: "; 
			fflush(stdin); 
			gets(Dir.Calle);
			cout<<endl<<"\nColonia: "; 
			fflush(stdin); 
			gets(Dir.Colonia);
			cout<<endl<<"\nCodigo Postal: "; 
			cin>>Dir.CP;
		    } 
		   	entrada.write((char *)&Adoran,sizeof(Cliente)); 
			cout<<endl;
			//q=q->sig;
			
		}
		salida.close();
		entrada.close();
		remove("clientes.dat");
		rename("Clientela.dat","clientes.dat");
		getch();

     
	}
	
} 


void Cliente::Mostrar(Comprador &inicio,Comprador &fin,Comprador &lista) 
{
	int reg,i;
	
	ifstream salida;
	Comprador q,t=NULL;
	salida.open("clientes.dat",ios::in|ios::binary);
	if(salida.fail())
	{
		cout<<endl<<"error "<<endl;
		getch();
	}
	else
	{

		salida.seekg(0,ios::end);
		reg=salida.tellg()/sizeof(Cliente);
		salida.seekg(0);
		cout<<endl<<reg<<endl;
		for(i=0;i<reg;i++)
		{
			salida.read((char *)&Adoran,sizeof(Cliente));
			getch();
		
		
			q=new(struct nodo_c);
	
		
			strcpy(q->Nombre,Nombre);
			cout<<endl<<q->Nombre<<endl;
			strcpy(q->Dir.Calle,Dir.Calle); 
			strcpy(q->Dir.Colonia,Dir.Colonia);
			strcpy(q->Codigo,Codigo);
		
			q->Dir.CP=Dir.CP;
		
			
			if(i==0)
			{
		
				t=q;
				q->ant=NULL;
				q->sig=inicio;
				inicio=q;
				fin=q;
			}
			else
			{
		
				q->ant=NULL;
				q->sig=inicio;
				t->ant=q;
				inicio=q;
			}
		}
		for(i=0;i<reg;i++)

		{
			cout<<endl<<"nombre: "<<q->Nombre;
			cout<<endl<<"codigo: "<<q->Codigo;
			cout<<endl<<"Direccion: ";
			cout<<"\nCalle: "<<q->Dir.Calle; 
			cout<<"\nColonia: "<<q->Dir.Colonia;
			cout<<"\nCodigo Postal: "<<q->Dir.CP;
		
			
			cout<<endl;
			q=q->sig;
			getch();
		
			
		}
		

	}
}

