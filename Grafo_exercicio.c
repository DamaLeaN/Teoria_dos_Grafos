#include <stdio.h>
#include <locale.h>
#define linha_V 6 // tamanho do vetor
#define coluna_V 6
#define percorre 100


int Matriz [linha_V][coluna_V]; // neste exercicio será usado a matriz para representar o grafo
int trajetoria[percorre];// vetor criado realizar a varredura
int trajeto =0;
// instanciando as funções que serão usadas no progroma
void imprimir();
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
	
	printf("\nGPS dos vertices: \n");
	printf("\nInforme o vertice de Origem: \n");
	scanf("%d",&origem);
	printf("\nInforme o vertice de Destino: \n");
	scanf("%d",&destino);
	
	Gps(origem,destino,trajetoria);

	return 0;

}
void popular(){
	
	// informando a posição de contato dos vertices
 //vertíce 1	
 Matriz[0][1] = 2;
 Matriz[0][3] = 4;
 //vertíce 2
 Matriz[1][0] = 1;
 Matriz[1][2] = 3;
 //vertíce 3
 Matriz[2][1] = 2;
 //vertíce 4
 Matriz[3][0] = 1;
 Matriz[3][4] = 5;
 //vertíce 5
 Matriz[4][3] = 4;
 Matriz[4][5] = 6;
 //vertíce 6
 Matriz[5][4] = 5;
	
}
void imprimir(){
	// Função irá realizar a impressão das posições declaradas na FUNÇÃO POPULAR.
	
	int i, j;
	printf("===================MATRIZ===================\n");
	for(i=0;i<linha_V;i++){	
		for(j=0;j<coluna_V;j++){
			printf("%d\t",Matriz[i][j]);
		}
		printf("\n");
	}
	printf("============================================\n");
}
void Vizinhos(){
	//Função para identificar os vertices vizinhos.	
	int  i, j, v_usu, posicao;
	printf("Vizinho dos Vertices");
	printf("\n\nInforme o vertice: \n");
	scanf("%d",&v_usu);// declarei a variavel V_USU para receber o valor digitado.
	
	posicao = v_usu - 1; // Aqui foi realizado a conversão para o valor que é lido pelo computador.
	
	for(i = 0; i < linha_V; i ++){ // laço para repetir a quantidade de linhas da matriz
		if(Matriz[posicao][i] != 0){// condição que irá comparar os valores da matriz diferentes de ZERO.
		printf("O Vertice vizinho é: %d\n",i + 1);	// Se os valores que forem diferentes de ZERO, serão printados e convertidos para exibição ao usuário
		}
	}
	printf("============================================\n");
}
void RollBack(){
 int voltar;
	for(voltar = 0; voltar < percorre;voltar++){
		if(trajetoria[voltar] == 0){
	 	trajetoria[voltar-1] = 0;
	 	}
	}
}
void Caminho(int trajetoria[]){//função para identificar a posição dos vertices encontrados
 int posicao =0;
	if(trajetoria[posicao] == 0){
		printf("Não há caminho a ser mostrado.");
		}// irá validar a primeira posição do vetor
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
	 if(destino_V != origem_V){} // laço para iniciar o loop para localizar a posição dos vertices.
 
	 destino_V --;
	 origem_V --;
	 int validaCaminho = 0;
	 int i,moto,corrida,carro;
 
 //Adiciona o numero origem ao final da lista ciminho
 	for(carro = 0;carro<percorre;carro++){
		if(trajetoria[carro] == 0){
			trajetoria[carro] = origem_V+1;
		if(destino_V != origem_V){}
	 		break;
	 	}
 	}
 // Confere se o numero atualmente sendo analisado é o desejado
 	for(moto = 0; moto<percorre; moto++){
	 if(destino_V+1 == trajetoria[moto]){
		printf("\nO caminho é:"); 	
		Caminho(trajetoria);
	 	trajeto = 1;
		return 1;
	 	}
 	}
 // Valida se o vertice pesquisado está no trajeto
 	if(trajeto == 0){
	 	for(i = 0; i < linha_V; i++){
		validaCaminho = 0;
			for(corrida = 0; corrida < coluna_V;corrida++){
				if(Matriz[origem_V][i] == trajetoria[corrida]){
		 		validaCaminho = 1;
 			}	
 		}
	 		if(Matriz[origem_V][i] != 0 && validaCaminho == 0){
				if(Gps(Matriz[origem_V][i],destino_V+1,trajetoria) == 1){
	 				return 1;
	 		}
	 		else{
	 			RollBack();
				}
			}
	 	}
 	return 0;
 	}
}


