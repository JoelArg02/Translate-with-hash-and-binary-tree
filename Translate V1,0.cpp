//Joel Arguello - Prueba estructura de datos - Traductor :D
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>

using namespace std;

struct Translator{
	string spanish;
    string kichwa;
    string french;
    string italian;
};

struct NODO{
	int dato;
	NODO *der,*izq;
};

Translator *dictionary[99]={0};
Translator *createNode(string a, string b, string c, string d);
NODO *tree = NULL;

void menu();
int hash(string s);
void addbase();
void translate();
void show_tree(NODO *tree, int cont);
bool search(NODO *tree, int n);
void insert(NODO *&tree, int n);
void comp();
void er(int n);


main(){
	comp();
	setlocale(LC_CTYPE, "Spanish");
	menu();
}

void menu(){
	int op, cont=0;
	
	do{		
		system("cls");
		cout<<"\t\t\t\t\t ___________________________"<<endl;
		cout<<"\t\t\t\t\t|       Bienvenido :)       |"<<endl;
		cout<<"\t\t\t\t\t|  	  Traductor         |"<<endl;
		cout<<"\t\t\t\t\t|     Español - Kichwa      |"<<endl;
		cout<<"\t\t\t\t\t|     Frances - Italino     |"<<endl;
		cout<<"\t\t\t\t\t|___________________________|"<<endl;
		cout<<"\t\t\t\t\t    ____________________"<<endl;
		cout<<"\t\t\t\t\t   |    1. Traducir     |"<<endl;
		cout<<"\t\t\t\t\t   |     2. Salir       |"<<endl;
		cout<<"\t\t\t\t\t   |____________________|"<<endl;
		cout<<"¿Qué opcion desea usar?"<<endl;
		cout<<"--> ";
		cin>>op;
		switch(op){
			case 1:
				translate();
				break;
			case 2:
				exit(1);
				break;
			case 3:
				cont=0;
				show_tree(tree, cont);	
				system("pause");	
				break;
			default:
				er(1);
				break;
		}
	}while(op!=4);
}

Translator *createNode (string a, string b, string c, string d){
    Translator *new_node = new Translator;

    if(new_node != NULL){
    	new_node->spanish = a;
        new_node->kichwa  = b;
        new_node->french  = c;
        new_node->italian = d;
    }else{
        cout << "Memoria llena | Error";
    }
    return new_node;
}

void addbase(){
    string a, b, c, d, s;
    int hashVal;
    ifstream f("database.dat");
	
	while(!f.eof()){
		getline(f, s);
    	stringstream input_stringstream(s);
    	getline(input_stringstream, a, '-');
	    getline(input_stringstream, b, '-');
    	getline(input_stringstream, c, '-');
	    getline(input_stringstream, d, '-');
    	
		Translator * new_node = createNode(a,b,c,d);
    	hashVal = hash(a);
		insert(tree,hashVal);
		dictionary[hashVal] = new_node;
	}
}

void translate(){
    string a, word;

	int op=0,i;
	
    int hashVal;
    do{
    	system("cls");
    	cout<<"\t\t\t\t\t ___________________________"<<endl;
		cout<<"\t\t\t\t\t|  	  Traductor         |"<<endl;
		cout<<"\t\t\t\t\t|  1. Español - Kichwa      |"<<endl;
		cout<<"\t\t\t\t\t|  2. Español - Frances     |"<<endl;
		cout<<"\t\t\t\t\t|  3. Frances - Italino     |"<<endl;
		cout<<"\t\t\t\t\t|___________________________|"<<endl;
		cout<<endl<<"\t\t\t\t\t ____________________________________"<<endl;
		cout<<"\t\t\t\t\t|  	       Traductor             |"<<endl;
		cout<<"\t\t\t\t\t|    ¿Qué traducción necesitas?      |"<<endl;
		cout<<"\t\t\t\t\t|____________________________________|"<<endl;
		cout<<"\t\t\t---> ";
		cin>>op;
		switch(op){
			case 1:
				{
					system("cls");
    				cout<<"\t\t\t\t\t ___________________________"<<endl;
					cout<<"\t\t\t\t\t|  	  Traductor         |"<<endl;
					cout<<"\t\t\t\t\t|     Español - Kichwa      |"<<endl;
					cout<<"\t\t\t\t\t|___________________________|"<<endl;
					cout<<"\t\t\tIngresar palabra a buscar: ";
					fflush(stdin);
					getline(cin,a);
					stringstream input_stringstream(a);
					for(i=0; i<a.size(); i++){
						if(a[i+1] == ' ' || a[i+1] == '\0'){
							getline(input_stringstream, word, ' ');
							hashVal=hash(word);
							if(search(tree,hashVal)==true && dictionary[hashVal] && dictionary[hashVal]->spanish == word){
								cout<<dictionary[hashVal]->kichwa;
							}else{
								cout<<" *"<<word<<"* ";
							}	
						
						}
					}
				cout<<endl;
				system("pause");
				}	
				break;
			case 2:{
				system("cls");
				cout<<"\t\t\t\t\t ___________________________"<<endl;
				cout<<"\t\t\t\t\t|  	  Traductor         |"<<endl;
				cout<<"\t\t\t\t\t|     Español - Frances     |"<<endl;
				cout<<"\t\t\t\t\t|___________________________|"<<endl;
				cout<<"Ingresar palabra a buscar: ";
    			fflush(stdin);
				getline(cin,a);
				stringstream input_stringstream(a);
					for(i=0; i<a.size(); i++){
						if(a[i+1] == ' ' || a[i+1] == '\0'){
							getline(input_stringstream, word, ' ');
							hashVal=hash(word);
							if(search(tree,hashVal)==true && dictionary[hashVal] && dictionary[hashVal]->spanish == word){
								cout<<dictionary[hashVal]->french;
							}else{
								cout<<" *"<<word<<"* ";
							}	
						
						}
					}
				cout<<endl;
				system("pause");
				}
				break;
			case 3:{
				system("cls");
				cout<<"\t\t\t\t\t ___________________________"<<endl;
				cout<<"\t\t\t\t\t|  	  Traductor         |"<<endl;
				cout<<"\t\t\t\t\t|     Español - Italiano    |"<<endl;
				cout<<"\t\t\t\t\t|___________________________|"<<endl;
				cout<<"Ingresar palabra a buscar: ";
    			fflush(stdin);
				getline(cin,a);
				stringstream input_stringstream(a);
					for(i=0; i<a.size(); i++){
						if(a[i+1] == ' ' || a[i+1] == '\0'){
							getline(input_stringstream, word, ' ');
							hashVal=hash(word);
							if(search(tree,hashVal)==true && dictionary[hashVal] && dictionary[hashVal]->spanish == word){
								cout<<dictionary[hashVal]->italian;
							}else{
								cout<<" *"<<word<<"* ";
							}	
						
						}
					}
				cout<<endl;
				system("pause");
				}
				break;
			default:{
				er(3);
				return;
				}break;
		}
	}while(op!=5);
}



void show_tree(NODO *tree, int cont){
	
	if(tree==NULL){
		return;
	}else{
		show_tree(tree->der, cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
	cout<<tree->dato<<endl;
	show_tree(tree->izq, cont+1);
	}
}

int hash(string s){
    int total = 0;

    for(int j=0; j<s.size(); j++){
		total=total+(int)s[j];
	}
	return total%99;
}

void comp(){
	string s;
	ifstream f("database.dat");
	if(f.is_open()){
		addbase();		
	}else{
		er(2);
	}
}

NODO *createNODO(int n){
	NODO *new_nodo = new NODO();
	new_nodo->dato = n;
	new_nodo->der = NULL;
	new_nodo->izq = NULL;
	
	return new_nodo;
}

void insert(NODO *&tree, int n){
	if (tree == NULL){
		NODO *new_nodo = createNODO(n);
		tree = new_nodo;
	}else{
		int firstDate = tree->dato;
		if(n<firstDate){
			insert(tree->izq,n);
		}else{
			insert(tree->der,n);
		}
	}
}

bool search(NODO *tree, int n){
	if(tree==NULL){
		return false;
	}else if(tree->dato == n){
		return true;
	}else if(n<tree->dato){
		return search(tree->izq,n);
	}else{
		return search(tree->der,n);
	}
}

void er(int n){
	if(n==1){
		cout<<"Seleccione una opcion valida"<<endl;
		exit(1);
	}else if(n==2){
		cout<<"Error al abrir base de datos!"<<endl;
		cout<<"Cerrado programa"<<endl;
		exit(1);
	}else if(n==3){
		cout<<"Ingrese una opcion valida";
		exit(1);
	}
}
