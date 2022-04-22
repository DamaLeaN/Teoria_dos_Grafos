#include<stdio.h>
#include<locale.h>
#define MAX 13
#define LINHA 7
#define COLUNA 7

struct aresta{
	int vOrigem;
	int vDestino;
}aresta[MAX];

int mAdj[LINHA][COLUNA];
int cor[LINHA];

void inicializar();
void imprimir();
void transformarEmMatriz();
void imprimirMatriz();
void colorir(int n);

int main(void){
	inicializar();
	imprimir();
	transformarEmMatriz();
	imprimirMatriz();
	colorir(1);
	imprimirMatriz();
	
	
}

void inicializar(){
	setlocale(LC_ALL,"Portuguese");
	
	aresta[0].vOrigem  = 1;
	aresta[0].vDestino = 4;
	
	aresta[1].vOrigem  = 4;
	aresta[1].vDestino = 6;
	
	aresta[2].vOrigem  = 6;
	aresta[2].vDestino = 2;
	
	aresta[3].vOrigem  = 4;
	aresta[3].vDestino = 7;
	
	aresta[4].vOrigem  = 2;
	aresta[4].vDestino = 7;
	
	aresta[5].vOrigem  = 7;
	aresta[5].vDestino = 5;
	
	aresta[6].vOrigem  = 2;
	aresta[6].vDestino = 5;

	aresta[7].vOrigem  = 5;
	aresta[7].vDestino = 3;
	
	aresta[8].vOrigem  = 2;
	aresta[8].vDestino = 4;
	
	aresta[9].vOrigem  = 4;
	aresta[9].vDestino = 5;
	
	aresta[10].vOrigem  = 6;
	aresta[10].vDestino = 7;
	
	aresta[11].vOrigem  = 7;
	aresta[11].vDestino = 3;
	
	int i;
	
	for (i = 0; i < MAX; i++){
		cor[i] = 60+i;	
	}
	
	
}

void imprimir(){
	int i;
	
	printf("---------->>>> Lista Aresta <<<<------------\n");
	printf("Aresta\t\t |Origem \t |Destino\n");
	for (i = 0; i < MAX; i++){
		printf("%d -> \t\t |%d  \t\t |%d \n",i, aresta[i].vOrigem, aresta[i].vDestino);		
	}
	
}

void transformarEmMatriz(){
	
	int i;
	
	for(i = 0; i < MAX; i++){
	
		mAdj[(aresta[i].vOrigem - 1)][(aresta[i].vDestino - 1)] = 1;
		mAdj[(aresta[i].vDestino - 1)][(aresta[i].vOrigem - 1)] = 1;
	
	}
	
}


void imprimirMatriz(){
	int i, j;
	
	printf("----------------------->>>MATRIZ<<<------------------------\n");
	
	for(i = 0; i < LINHA; i++){
		for(j = 0; j < COLUNA; j++){
			printf("   %d\t",mAdj[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------------------------------------\n");
}

void colorir(int n){
	
	n = n - 1;
	int i, j = 1, proximo, next;
	
	printf("---------------->>>COLORA��O DE ARESTAS<<<-----------------\n ");
	
	for (i = 0; i < LINHA; i ++){ // La�o que ir� iniciar a varredura no vertice 1, localizando o valor informar ir� realizar sua coloro��o
		if(mAdj[n][i] != 0){ mAdj[i][n] = cor[0];} // vermelho
		}
		printf("COLORINDO A COLUNA %d \n\n", n+1);
		printf("Vizinho = ");
		for (i = 0; i < LINHA; i ++){ // La�o para identificar o vizinho do vertice
			if(mAdj[n][i] != 0){ 
				printf("%d ", (i+1));
				if(mAdj[n][i] == 1){ proximo = i;}		
			}
		}	printf("\nPROXIMO = %d\n", proximo+1); // ir� exibir vizinho, que ser� iniciado na pr�xima varredura.
			next = proximo ;
	
	for (i = 0; i < LINHA; i++){ // La�o 2: ir� pegar o Vizinho que foi encontrado, far� a varredura e ir� colorir as arestas localizadas.
		
		if((mAdj[i][next]  >= 1 )){ // Valida se o valor de NEXT � igual ou maior que um, caso sim, ir� realizar a colora��o.
			mAdj[i][next] = cor[1];	//azul
			}else if(mAdj[next][i] != 0 )
			mAdj[i][next] = cor[0]; //TERMINO DO LA�O 2
		}	
			printf("\nCOLORINDO A COLUNA %d \n", next + 1);
			printf("Vizinho = ");
			for (i = 0; i < LINHA; i ++){ // La�o para identificar o vizinho do vertice
				if(mAdj[next][i] != 0){ 			
				printf("%d, ", (i+1));
				if(mAdj[next][i] == 1){ proximo = i;}		
				}
			}	printf("\nPROXIMO = %d\n", proximo+1);
				next = proximo;
	
	for (i = 0; i < LINHA; i++){ // La�o 3: ir� pegar o Vizinho que foi encontrado, far� a varredura e ir� colorir as arestas localizadas.
		
		if(mAdj[i][next]  > 1 ){ // Valida se o valor de NEXT � igual ou maior que um, caso sim, ir� realizar a colora��o.
			mAdj[i][next] = cor[2];		
			}else if(mAdj[next][i] != 0 )
			mAdj[i][next] = cor[0];
	}	
		printf("\nCOLORINDO A COLUNA %d \n", next + 1);
		printf("Vizinho = ");
		for (i = 0; i < LINHA; i ++){ // La�o para identificar o vizinho do vertice
			if(mAdj[next][i] != 0){ 	
				printf("%d, ", (i+1));
				if(mAdj[next][i] == 1){ proximo = i;}		
			}
		}	printf("\nPROXIMO = %d\n", proximo+1);
			next = proximo;
		
	for (i = 0; i < LINHA; i++){ // La�o 4: ir� pegar o Vizinho que foi encontrado, far� a varredura e ir� colorir as arestas localizadas.
		
		if((mAdj[i][next]  == 1 ) ){ // Valida se o valor de NEXT � igual ou maior que um, caso sim, ir� realizar a colora��o.
			mAdj[i][next] = cor[2];		
			}else if(mAdj[next][i] != 0 )
			mAdj[i][next] = cor[0];
	}
		printf("\nCOLORINDO A COLUNA %d \n", next + 1);
		printf("Vizinho = ");
		for (i = 0; i < LINHA; i ++){ // La�o para identificar o vizinho do vertice
			if(mAdj[next][i] != 0){ 			
			printf("%d, ", (i+1));
			if(mAdj[next][i] == 1){ proximo = i;}		
			}
		}	printf("\nPROXIMO = %d\n", proximo+1);
			next = proximo;
	
	for (i = 0; i < LINHA; i++){ // La�o 3: ir� pegar o Vizinho que foi encontrado, far� a varredura e ir� colorir as arestas localizadas.
		if(mAdj[next][i]  >= 1 ){ // Valida se o valor de NEXT � igual ou maior que um, caso sim, ir� realizar a colora��o.
			mAdj[i][next] = cor[3];		
			}else if(mAdj[next][i] != 0 )
			mAdj[i][next] = cor[0];
	}
		printf("\nCOLORINDO A COLUNA %d \n", next + 1);
		printf("Vizinho = ");
		for (i = 0; i < LINHA; i ++){ // La�o para identificar o vizinho do vertice
			if(mAdj[next][i] != 0){ 			
				printf("%d, ", (i+1));
				if(mAdj[next][i] == 1){ proximo = i;}		
			}
		}	printf("\nPROXIMO = %d\n", proximo+1);
			next = proximo;
	
	for (i = 0; i < LINHA; i++){ // La�o 3: ir� pegar o Vizinho que foi encontrado, far� a varredura e ir� colorir as arestas localizadas.
		if(mAdj[i][next]  > 1  ){ // Valida se o valor de NEXT � igual ou maior que um, caso sim, ir� realizar a colora��o.
			mAdj[i][next] = cor[4];		
			}else if(mAdj[next][i] != 0 )
			mAdj[i][next] = cor[0];
	}
		printf("\nCOLORINDO A COLUNA %d \n", next + 1);
		printf("Vizinho = ");
		for (i = 0; i < LINHA; i ++){ // La�o para identificar o vizinho do vertice
		if(mAdj[next][i] != 0){ 		
			printf("%d, ", (i+1));
			if(mAdj[next][i] == 1){ proximo = i;}		
		}
	}		printf("\nPROXIMO = %d\n", proximo+1);
			next = proximo;
	
	for (i = 0; i < LINHA; i++){ // La�o 3: ir� pegar o Vizinho que foi encontrado, far� a varredura e ir� colorir as arestas localizadas.	
		if(mAdj[next][i]  > 1 ){ // Valida se o valor de NEXT � igual ou maior que um, caso sim, ir� realizar a colora��o.
		mAdj[i][next] = cor[1];		
		}else if(mAdj[next][i] != 0 )
		mAdj[i][next] = cor[0];
	}
	printf("\nTERMINA NA COLUNA %d \n", next + 1);
}




/*
	60 - VERMELHO
	61 - AZUL
	62 - LARANJA
	63 - VERDE

*/


