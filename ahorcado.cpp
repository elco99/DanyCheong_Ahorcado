#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int menu();
void Agregar();
void Life(int);
void Jugar();
void RealPlay(char*,int);

int main(int argc, char* argv[]){
	srand(time(0));
	int opcion;
	while ( (opcion = menu()) != 3){
		if (opcion == 1){
			Agregar();
		}else if (opcion == 2){
			Jugar();
		}else{
			cout << "Gracias por jugar =D"<<endl;
		}
	}
	return 0;
}

int menu(){
	int opcion;
	cout <<"Menu:"<<endl;
	cout << "1)Agregar Palabras"<<endl;
	cout << "2)Jugar"<<endl;
	cout << "3)Salir"<<endl;
	do{
		cin >> opcion;
		if (opcion != 1 && opcion != 2 && opcion != 3){
			cerr << "Introduzca un valor correcto" << endl;
		}
	}while(opcion != 1 && opcion != 2 && opcion != 3);
	return opcion;
}

void Agregar(){
	int opcion;
	cout <<"Dificultad:"<<endl;
	cout << "1)Facil"<<endl;
	cout << "2)Medio"<<endl;
	cout << "3)Dificil"<<endl;
	do{
		cin >> opcion;
		if (opcion != 1 && opcion != 2 && opcion != 3){
			cerr << "Introduzca un valor correcto" << endl;
		}
	}while(opcion != 1 && opcion != 2 && opcion != 3);

	if(opcion == 1){
		ofstream file;
		char cadena[80];
		file.open("facil.txt",ios_base::app);
		cout << "Introduzca la palabra: ";
		cin>>cadena;
		file << cadena << "\n";
		file.close();
	}else if(opcion == 2){
		ofstream file;
		char cadena[80];
		file.open("medio.txt",ios_base::app);
		cout << "Introduzca la palabra: ";
		cin>>cadena;
		file << cadena << "\n";
		file.close();
	}else if(opcion == 3){
		ofstream file;
		char cadena[80];
		file.open("dificil.txt",ios_base::app);
		cout << "Introduzca la palabra: ";
		cin>>cadena;
		file << cadena << "\n";
		file.close();
	}
}

void Life(int vida){
	switch(vida){
		case 0:
			cout<<endl<<endl
	   		<<"     +-------+"<<endl
		   	<<"             |"<<endl
	  		<<"             | "<<endl
	   		<<"             | "<<endl
		  	<<"             | "<<endl
	 		<<"    	     | "<<endl
	  	 	<<"  ============="<<endl<<endl; 
	  	 break;
		case 1:
			cout<<endl<<endl
	   		<<"     +-------+"<<endl
		   	<<"     |       |"<<endl
	  		<<"             | "<<endl
	   		<<"             | "<<endl
		  	<<"             | "<<endl
	 		<<"    	     | "<<endl
	  	 	<<"  ============="<<endl<<endl; 
		break;
		case 2:
			cout<<endl<<endl
	   		<<"     +-------+"<<endl
		   	<<"     |       |"<<endl
	  		<<"     O       | "<<endl
	   		<<"             | "<<endl
		  	<<"             | "<<endl
	 		<<"    	     | "<<endl
	  	 	<<"  ============="<<endl<<endl; 
		break;
		case 3:
			cout<<endl<<endl
	   		<<"     +-------+"<<endl
		   	<<"     |       |"<<endl
	  		<<"     O       | "<<endl
	   		<<"     |       | "<<endl
		  	<<"             | "<<endl
	 		<<"    	     | "<<endl
	  	 	<<"  ============="<<endl<<endl; 
		break;
		case 4:
			cout<<endl<<endl
	   		<<"     +-------+"<<endl
		   	<<"     |       |"<<endl
	  		<<"     O       | "<<endl
	   		<<"    /|       | "<<endl
		  	<<"             | "<<endl
	 		<<"    	     | "<<endl
	  	 	<<"  ============="<<endl<<endl; 
		break;
		case 5:
			cout<<endl<<endl
	   		<<"     +-------+"<<endl
		   	<<"     |       |"<<endl
	  		<<"     O       | "<<endl
	   		<<"    /|\\      | "<<endl
		  	<<"             | "<<endl
	 		<<"    	     | "<<endl
	  	 	<<"  ============="<<endl<<endl; 
		break;
		case 6:
			cout<<endl<<endl
	   		<<"     +-------+"<<endl
		   	<<"     |       |"<<endl
	  		<<"     O       | "<<endl
	   		<<"    /|\\      | "<<endl
		  	<<"    /        | "<<endl
	 		<<"    	     | "<<endl
	  	 	<<"  ============="<<endl<<endl; 
		break;
		case 7:
			cout<<endl<<endl
	   		<<"     +-------+"<<endl
		   	<<"     |       |"<<endl
	  		<<"     O       | "<<endl
	   		<<"    /|\\      | "<<endl
		  	<<"    / \\      | "<<endl
	 		<<"    	     | "<<endl
	  	 	<<"  ============="<<endl<<endl; 
		break;
		case 8:
			cout<<endl<<endl
	   		<<"     +-------+"<<endl
		   	<<"     |       |"<<endl
	  		<<"     X       | "<<endl
	   		<<"    /|\\      | "<<endl
		  	<<"    / \\      | "<<endl
	 		<<"  GAME OVER  | "<<endl
	  	 	<<" =============="<<endl<<endl;
		break;
	}
}

void Jugar(){
	int opcion;
	cout <<"Dificultad:"<<endl;
	cout << "1)Facil"<<endl;
	cout << "2)Medio"<<endl;
	cout << "3)Dificil"<<endl;
	do{
		cin >> opcion;
		if (opcion != 1 && opcion != 2 && opcion != 3){
			cerr << "Introduzca un valor correcto" << endl;
		}
	}while(opcion != 1 && opcion != 2 && opcion != 3);

	switch(opcion){
		case 1:{
			ifstream file;
			file.open("facil.txt");
			char** lista = new char*[100];
			char temp[80];
			int cont =0;
			while(!file.eof()){
				file.getline(temp,sizeof(file));
				lista[cont] = new char(strlen(temp)+1);
				strcpy(lista[cont],temp);
				cont++;
			}
			file.close();

			int random = rand() % (cont-1);
			char* guess;
			guess = lista[random];
			RealPlay(guess,strlen(guess)+1);
			
			for(int i = 0; i < cont;i++){
				delete[] lista[i];
			}
			delete[] lista;
		break;}
		case 2:{
			ifstream file;
			file.open("medio.txt");
			char** lista = new char*[100];
			char temp[80];
			int cont =0;
			while(!file.eof()){
				file.getline(temp,sizeof(file));
				lista[cont] = new char(strlen(temp)+1);
				strcpy(lista[cont],temp);
				cont++;
			}
			file.close();

			int random = rand() % (cont-1);
			char* guess;
			guess = lista[random];
			RealPlay(guess,strlen(guess)+1);
			
			for(int i = 0; i < cont;i++){
				delete[] lista[i];
			}
			delete[] lista;
		break;}
		case 3:{
			ifstream file;
			file.open("dificil.txt");
			char** lista = new char*[100];
			char temp[80];
			int cont =0;
			while(!file.eof()){
				file.getline(temp,sizeof(file));
				lista[cont] = new char(strlen(temp)+1);
				strcpy(lista[cont],temp);
				cont++;
			}
			file.close();

			int random = rand() % (cont-1);
			char* guess;
			guess = lista[random];
			RealPlay(guess,strlen(guess)+1);
			
			for(int i = 0; i < cont;i++){
				delete[] lista[i];
			}
			delete[] lista;
		break;}
	}
}

void RealPlay(char* lista,int cont){
	int vida=0,contador=0,winner=0,decision;
	bool pierde = false,gano = false;
	bool usado = false,continua = true;
	char user[100];
	char* guess = new char[cont-1];
	char usados[26] ={' '};
	for(int i=0;i<(cont-1);i++){
		guess[i] = '_';
	}

	do{
		if(winner == cont-1){
			gano = true;
			break;
		}
		continua = true;
		do{
			if(strlen(user) > 1){
				cout << "Guess: ";
				cin >> user;
				break;
			}else{
				usado = false;
				cout << "Guess: ";
				cin >> user;
				for(int i=0;i < contador;i++){
					if(user[0] == usados[i]){
						usado = true;
						cout << "Ya uso esta letra, ingrese otro."<<endl;
						break;
					}
				}
				usados[contador] = user[0];
				contador++;
			}
		}while(usado ==true);

		if(strlen(user)>1){
			cout << "Si ingresa una palabra, y esta incorrecta, perdera el juego, pero si esta correcto ganara. Quiere Seguir? [1-Si/2-No]"<<endl;
			cin >> decision;
			if(decision == 1){
				if(strcmp(lista,user) == 0){
					gano = true;
					break;
				}else{
					break;
				}
			}else{
				continua = false;
				continue;
			}
		}

		if(continua == true){
			pierde = false;
			for(int i=0;i < cont-1;i++){
				if(user[0] == lista[i]){
					pierde = false;
					break;
				}else{
					pierde = true;
				}
			}

			if(pierde == true){
				vida++;
			}else{
				for(int i=0;i < cont-1;i++){
					if(user[0] == lista[i]){
						guess[i] = user[0];
						winner++;
					}
				}
			}

			Life(vida);
			cout << setw(7) << " ";
			for(int i=0;i<(cont-1);i++){
				cout<<guess[i];
			}
			cout<<endl<<endl;

			cout << "Usados: "; 
			for(int i=0;i < contador;i++){
				cout << usados[i] << ",";
			}
			cout << endl;
		}
		

		

	}while(vida<8 || winner==cont);

	if(gano==true){
		cout << "Usted es un ganador!"<<endl;
	}else{
		cout << "Usted es un perdedor, la palabra correcta era: "<<lista<<endl;
	}
	delete[] guess;
}