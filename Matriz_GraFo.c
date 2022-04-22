#include <stdio.h>
#include <locale.h>
#define linha_V 6 // tamanho do vetor
#define coluna_V 6
#define percorre 100


int Matriz [linha_V][coluna_V]; // neste exercicio ser� usado a matriz para representar o grafo
int trajetoria[percorre];
int trajeto =0;
void imprimir();	// instanciando a fun��o que ser� usada no progroma
void popular();
void Vizinhos();
void Caminho();
void RollBack();
int Gps (int origem_V, int destino_V, int trajetoria[]);



int main (void){
	
	int origem, destino;
	setlocale(LC_ALL,"Portuguese");
	
	popular();
	imprimir();
	Vizinhos();
	
	printf("\nInforme o vertice de Origem: \n");
	scanf("%d",&origem);
	printf("\nInforme o vertice de Destino: \n");
	scanf("%d",&destino);
	
	Gps(origem,destino,trajetoria);
	//printf("\n\n");
	//imprimir();
	return 0;

}

void popular(){
	
	// informando a posi��o de contato dos vertices
	
	Matriz[0][1] = 2; 
	Matriz[0][2] = 3;
	Matriz[0][3] = 4;
	
	//V2
	Matriz[1][0] = 1;
	Matriz[1][2] = 3;
	
	//V3
	Matriz[2][0] = 1;
	Matriz[2][1] = 2;
	Matriz[2][4] = 5;
	Matriz[2][5] = 6;
		
	//V4
	Matriz[3][0] = 1;
	
	//V5
	Matriz[4][2] = 3;
	Matriz[4][5] = 6;
	
	//V6
	Matriz[5][2] = 3;
	Matriz[5][4] = 5;
	
}


void imprimir(){
	// Fun��o ir� realizar a impress�o das posi��es declaradas na FUN��O POPULAR.
	
	int i, j;
	printf("===================MATRIZ===================\n");
	for(i=0;i<linha_V;i++){	
		for(j=0;j<coluna_V;j++){
			printf("%d\t",Matriz[i][j]);
		}
		printf("\n");
	}
	
}


void Vizinhos(){
	//Fun��o para identificar os vertices vizinhos.	
	int  i, j, v_usu, posicao;
	
	printf("\n\nInforme o vertice: \n");
	scanf("%d",&v_usu);// declarei a variavel V_USU para receber o valor digitado.
	
	posicao = v_usu - 1; // Aqui foi realizado a convers�o para o valor que � lido pelo computador.
	
	for(i = 0; i < linha_V; i ++){ // la�o para repetir a quantidade de linhas da matriz
		if(Matriz[posicao][i] != 0){// condi��o aonde ir� validar a posi��o informada pelo usu�rio e vai comparar com o contador "i".
		printf("O Vertice vizinho �: %d\n",i + 1);	// se ambos os valores forem iguais, ser� impresso a posi��o do vertice vizinho, somando + 1, para mostrar o valor ao usu�rio.
		}
	}
}

void RollBack(){
 int voltar;
	for(voltar = 0; voltar < percorre;voltar++){
		if(trajetoria[voltar] == 0){
	 	trajetoria[voltar-1] = 0;
	 	}
	}
}

void Caminho(int trajetoria[]){//fun��o para identificar a posi��o dos vertices encontrados
 int posicao =0;
	if(trajetoria[posicao] == 0){
		printf("N�o h� caminho a ser mostrado.");
		}// ir� validar a primeira posi��o do vetor
	else{
		printf(" %d",trajetoria[posicao]);
		posicao ++;
		if(trajetoria[posicao] == 0){}
		else{
			do{
			printf(" -> %d",trajetoria[posicao]);
			posicao = posicao+1;
			}while(trajetoria[posicao] != 0);
		}
	}
}
int Gps(int origem_V, int destino_V, int trajetoria[]){
	 //
	 //printf("\nCaminho do v�rtice %d no vertice %d", destino_V, origem_V);
	 if(destino_V != origem_V){
	 	
	 }
 
	 destino_V --;
	 origem_V --;
	 int estaNoCaminho = 0;
	 int i,x,c,ca;
 
 //Adiciona o numero origem ao final da lista ciminho
 	for(ca = 0;ca<percorre;ca++){
		if(trajetoria[ca] == 0){
			trajetoria[ca] = origem_V+1;
		if(destino_V != origem_V){
		//	printf("\nCaminho alterado, ");
		//	printf("%d foi adicionado ao caminho que agora � ", origem_V+1);
		//	Caminho(trajetoria);
			}
	 		break;
	 	}
 	}
 // Confere se o numero atualmente sendo analisado � o desejado
 	for(x = 0; x<percorre; x++){
	 if(destino_V+1 == trajetoria[x]){
		printf("\nCaminho encontrado, o caminho �:"); 	
		Caminho(trajetoria);
	 	trajeto = 1;
		return 1;
	 	}
 	}
 	
 // Define se o vertice que esta atualmente em pesquisa ja esta no caminho passado
 	if(trajeto == 0){
 // printf("\n\nMostrar Caminho: %d\n\n", mostrarCaminho);
	 	for(i = 0; i < linha_V; i++){
	 // printf("\nAtualmente analisando %d na coluna de %d ", grafo[origem_V][i],origem_V);
		estaNoCaminho = 0;
			for(c = 0; c < coluna_V;c++){
				if(Matriz[origem_V][i] == trajetoria[c]){
		 		estaNoCaminho = 1;
 			}	
 		}
 
 // Testa a fileira do vertice em ques�o, se n�o � um zero e n�o estiver no caminho passado, toma como alvo
	 		if(Matriz[origem_V][i] != 0 && estaNoCaminho == 0){
 // printf("\nAchou um novo vertice, o %d", grafo[origem_V][i]);
			if(Gps(Matriz[origem_V][i],destino_V+1,trajetoria) == 1){
	 			return 1;
	 		}
	 		else{
	 			RollBack();
	 // printf("\nVoltou um Vertice");
				}
			}
	 	}
 	return 0;
 	}
}
