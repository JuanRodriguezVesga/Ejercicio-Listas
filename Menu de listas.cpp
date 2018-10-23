#include<stdio.h>
#include<stdlib.h>

struct Nodo{
	int dato;
	Nodo *siguiente;
};


 

void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarlista(Nodo *, int);
void eliminarNodo(Nodo *&, int);
void borrarTodo(Nodo *&, int &);
void menu();



int main(){
	system("color 8f");
	menu();

	Nodo *lista=NULL;
	int dato, dato3;
	
	printf("Digite un dato \n");
	scanf("%d",&dato);
	insertarLista(lista,dato);
	
	printf("Digite un dato \n");
	scanf("%d",&dato);
	insertarLista(lista,dato);
	
	printf("Digite un dato \n");
	scanf("%d",&dato);
	insertarLista(lista,dato);
	
	mostrarLista(lista);
	printf("Digite dato a eliminar \n");
	scanf("%d",&dato3);
	eliminarNodo(lista,dato3);
	mostrarLista(lista);
	buscarlista(lista,dato);
	system("pause");

	
	return 0;
	
}

void menu(){
   	Nodo *lista = NULL;
	int dato, opcion;
	do{
	printf("Menu Lista Enlazadas\n");
	printf("1. Insertar\n");		
	printf("2. mostrar\n"); 
	printf("3. Buscar\n"); 		
    printf("4. Borrar Nodoo\n");
    printf("5. Borrar Todo\n");		   
    printf("6. Salir\n");	   
	scanf("%d",&opcion);
	switch(opcion){
		
		case 1: 
	       system("cls");
		   printf("Digite Un Numero\n");
		   scanf("%d",&dato);
		   insertarLista(lista,dato);
		   system("pause");
		   system("cls");
		   break;
	
	case 2: 
		system("cls");
		if(lista==NULL){
			printf("La Lista Esta Vacias\n\n");
		}else{
			printf("Mostrando lista\n\n");
			mostrarLista(lista);
		}
		system("pause");
		system("cls");
		break;
		
	case 3: 
		system("cls");
		printf("Digite un numero a Buscar\n");
		scanf("%d",&dato);
		buscarlista(lista,dato);
		system("pause");
		system("cls");
		break;
		
	
	case 4: 
		system("cls");
		eliminarNodo(lista,dato);
		system("pause");
		system("cls");
		break;	
		
	case 5:
		system("cls");
		while(lista != NULL){
			borrarTodo(lista,dato);
			printf("Borando Los Elementos\n");
		}
		system("pause");
		system("cls");
	    break;
	
	case 6:
		   exit(0);
		   break;
		
	default: printf("\tOpcion Invalida...\n");
	
	    }		   
     } while(opcion!=6);

}

void insertarLista(Nodo *&lista, int n){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=n;
	Nodo *aux1=lista;
	Nodo *aux2;
	while((aux1 != NULL)&&(aux1->dato <n)){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(lista==aux1){
		lista=nuevo_nodo;
	}else{
		aux2->siguiente=nuevo_nodo;
	}
	nuevo_nodo->siguiente=aux1;
	printf("dato %d insertado con exito\n",n);
}

void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	while(actual != NULL){
		printf("%d\n",actual->dato);
		actual=actual->siguiente;
	}
}

void buscarlista(Nodo *lista, int n){
	bool band = false;
	Nodo *actual = new Nodo();
	actual = lista;
	
	while((actual !=NULL)&&(actual->dato<=n)){
		if(actual->dato == n){
			band = true;
		}
		actual =actual->siguiente;	
	} 
	if(band == true){
		printf("Elemento a sido Encontrado En La Lista\n");
		
	}else{
		printf("Elemento No A Sido Encontrado\n");
	}
}

void eliminarNodo(Nodo *&lista, int n){
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		aux_borrar = lista;
		
		while((aux_borrar != NULL) && (aux_borrar ->dato !=n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		if(aux_borrar==NULL){
			printf("El elemento no existe\n");
		}else if(anterior == NULL){
			lista=lista->siguiente;
			printf("Elemento %d eliminado \n",n);
			delete aux_borrar;
		}else{
			anterior->siguiente=aux_borrar->siguiente;
			printf("Elemento %d elimnado \n",n);
			delete aux_borrar;
		}
	}
}





void borrarTodo(Nodo *&lista, int &n){
	Nodo *aux = lista;
	n = aux->dato;
	lista = aux->siguiente;
	delete aux;
}
