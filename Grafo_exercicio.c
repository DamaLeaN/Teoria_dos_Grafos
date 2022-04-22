#include <stdio.h>
#include <locale.h>
#define linha_V 6 // tamanho do vetor
#define coluna_V 6
#define percorre 100


int Matriz [linha_V][coluna_V]; // neste exercicio ser� usado a matriz para representar o grafo
int trajetoria[percorre];// vetor criado realizar a varredura
int trajeto =0;
// instanciando as fun��es que ser�o usadas no progroma
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
	
	// informando a posi��o de contato dos vertices
 //vert�ce 1	
 Matriz[0][1] = 2;
 Matriz[0][3] = 4;
 //vert�ce 2
 Matriz[1][0] = 1;
 Matriz[1][2] = 3;
 //vert�ce 3
 Matriz[2][1] = 2;
 //vert�ce 4
 Matriz[3][0] = 1;
 Matriz[3][4] = 5;
 //vert�ce 5
 Matriz[4][3] = 4;
 Matriz[4][5] = 6;
 //vert�ce 6
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
	printf("============================================\n");
}
void Vizinhos(){
	//Fun��o para identificar os vertices vizinhos.	
	int  i, j, v_usu, posicao;
	printf("Vizinho dos Vertices");
	printf("\n\nInforme o vertice: \n");
	scanf("%d",&v_usu);// declarei a variavel V_USU para receber o valor digitado.
	
	posicao = v_usu - 1; // Aqui foi realizado a convers�o para o valor que � lido pelo computador.
	
	for(i = 0; i < linha_V; i ++){ // la�o para repetir a quantidade de linhas da matriz
		if(Matriz[posicao][i] != 0){// condi��o que ir� comparar os valores da matriz diferentes de ZERO.
		printf("O Vertice vizinho �: %d\n",i + 1);	// Se os valores que forem diferentes de ZERO, ser�o printados e convertidos para exibi��o ao usu�rio
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
	 if(destino_V != origem_V){} // la�o para iniciar o loop para localizar a posi��o dos vertices.
 
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
 // Confere se o numero atualmente sendo analisado � o desejado
 	for(moto = 0; moto<percorre; moto++){
	 if(destino_V+1 == trajetoria[moto]){
		printf("\nO caminho �:"); 	
		Caminho(trajetoria);
	 	trajeto = 1;
		return 1;
	 	}
 	}
 // Valida se o vertice pesquisado est� no trajeto
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


