#include<iostream>
#include<stdlib.h>
#include<iomanip>
/*
	Criado por Beatriz Almeida
	25/09/2019
	beatrizdealmeida1997@gmail.com
*/
using namespace std;

int main(){
	
	struct Aluno { // Estrutura aluno com suas propriedades
		string nome; // Nome 
		int numeroMatricula; // Numero da Matricula do aluno
		float nota[3]; // Vetor para as três notas do aluno
		float media; // Media com as notas do aluno
	};
	
	const int numeroNotas = 3; //Constante que determina o numero de notas do aluno
	
	int numeroAlunos; //Variavel para guardar a quantia de alunos
	cout << "Insira o numero de alunos: "; 
	cin >> numeroAlunos; //Salvando o nome do aluno
	Aluno alunos[numeroAlunos]; //Vetor utilizando a struct Aluno, de tamanho definido pela variavel numeroAlunos
	
	for(int i = 0; i < numeroAlunos; i ++){ //Loop para popular as informacoes de cada aluno
		cout << endl << "Insira o nome do aluno " << i+1 << ":"<< endl;
		cin >> alunos[i].nome; //Salvando o nome do aluno da posicao i do vetor de alunos
		cout << endl << "Insira o numero de matricula:" << endl;
		cin >> alunos[i].numeroMatricula; //Salvando o numero de matricula do aluno da posicao i do vetor de alunos
		float somNotas = 0; //Variavel para guardar o somatorio das notas do aluno para futuro calculo de media
		
		for(int j = 0; j < numeroNotas; j++){ //Loop para popular as notas do aluno i, que estao em um vetor nota.
			cout << endl << "Insira a nota " << j+1 << " :" << endl;
			cin >> alunos[i].nota[j]; //Salvando a nota do aluno i na posicao j do vetor notas
			somNotas += alunos[i].nota[j]; //Somando a nota com o conteudo da variavel somNotas para obter ao final o somatorio
		}
		
		alunos[i].media = somNotas/numeroNotas; //Utilizando o somatorio de notas para obter a media do aluno i
	}
	
	for(int i = 0; i < numeroAlunos; i++){ //Loop para mostrar as informacoes inseridas de cada um dos alunos
		cout << endl << "Aluno: " << alunos[i].nome << endl <<"Matricula: " << alunos[i].numeroMatricula << endl << "Media: " << fixed << setprecision(2) << alunos[i].media << endl;
	}
	
	system("pause"); // finaliza o programa
	return 0;
}
