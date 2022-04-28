#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

#define MAX 17
#define VERTICE 7
#define VERFT 7
#define MAXFT 26

int mAdj[VERTICE][VERTICE];

int mFT[VERFT][VERFT];

void representar();
void imprimirMatriz();
void tranformarEmAresta();
void imprimirArestas();
void fechoTrans();

struct listaAresta{
	int verticeOrigem;
	int verticeDestino;
	float peso;	
} aresta[MAX];

void main(void){
	setlocale(LC_ALL, "Portuguese");
    representar();
    imprimirMatriz();
    tranformarEmAresta();
    imprimirArestas();
	fechoTrans();
}

//a)Representar a matriz computacionalmente    (peso = 0,125)
void representar(){
   
    
    mAdj[0][2] = 1;
	mAdj[0][4] = 1;
	mAdj[0][6] = 1;
	mAdj[1][3] = 1;
	mAdj[1][6] = 1;
	mAdj[2][4] = 1;
	mAdj[3][0] = 1;
	mAdj[3][1] = 1;
	mAdj[4][0] = 1;
	mAdj[4][1] = 1;
	mAdj[4][5] = 1;
	mAdj[5][1] = 1;	
    mAdj[5][3] = 1;
	mAdj[5][6] = 1;
	mAdj[6][1] = 1;
	mAdj[6][2] = 1;
	mAdj[6][5] = 1;
    
}

//b)Imprimir a matriz. (peso = 0,125)
void imprimirMatriz(){

	printf("Matriz \n");
	printf("\n");
	int i,j;
	for(i=0;i<VERTICE;i++){
		for(j=0;j < VERTICE;j++){
			printf("%d  ",mAdj[i][j]);
		}
		printf("\n");
	}

}

//c)Transformar a matriz em lista de aresta. (peso = 0,25)
void tranformarEmAresta(){

	aresta[0].verticeOrigem = 0;
	aresta[0].verticeDestino = 2;

	aresta[1].verticeOrigem = 0;
	aresta[1].verticeDestino = 4;
	
	aresta[2].verticeOrigem = 0;
	aresta[2].verticeDestino = 6;

	aresta[3].verticeOrigem = 1;
	aresta[3].verticeDestino = 3;
	
	aresta[4].verticeOrigem = 1;
	aresta[4].verticeDestino = 6;
	
	aresta[5].verticeOrigem = 2;
	aresta[5].verticeDestino = 4;
	
	aresta[6].verticeOrigem = 3;
	aresta[6].verticeDestino = 0;
	
	aresta[7].verticeOrigem = 3;
	aresta[7].verticeDestino = 1;
	
	aresta[8].verticeOrigem = 4;
	aresta[8].verticeDestino = 0;
	
	aresta[9].verticeOrigem = 4;
	aresta[9].verticeDestino = 1;
	
	aresta[10].verticeOrigem = 4;
	aresta[10].verticeDestino = 5;

	aresta[11].verticeOrigem = 5;
	aresta[11].verticeDestino = 1;

	aresta[12].verticeOrigem = 5;
	aresta[12].verticeDestino = 3;
	
	aresta[13].verticeOrigem = 5;
	aresta[13].verticeDestino = 6;
	
	aresta[14].verticeOrigem = 6;
	aresta[14].verticeDestino = 1;
	
	aresta[15].verticeOrigem = 6;
	aresta[15].verticeDestino = 2;
	
	aresta[16].verticeOrigem = 6;
	aresta[16].verticeDestino = 5;
	
	
	
	
	
	aresta[17].verticeOrigem = 0;
	aresta[17].verticeDestino = 3;

	aresta[18].verticeOrigem = 1;
	aresta[18].verticeDestino = 4;
	
	aresta[19].verticeOrigem = 1;
	aresta[19].verticeDestino = 5;

	aresta[20].verticeOrigem = 2;
	aresta[20].verticeDestino = 0;
	
	aresta[21].verticeOrigem = 2;
	aresta[21].verticeDestino = 6;
	
	aresta[22].verticeOrigem = 3;
	aresta[22].verticeDestino = 5;
	
	aresta[23].verticeOrigem = 4;
	aresta[23].verticeDestino = 2;
	
	aresta[24].verticeOrigem = 5;
	aresta[24].verticeDestino = 4;
	
	aresta[25].verticeOrigem = 6;
	aresta[25].verticeDestino = 2;	
	

}


//d)Imprimir a lista de arestas.(peso = 0,25)
void imprimirArestas(){

	printf("\n Lista de Aresta \n");	
	int i;
	for(i = 0; i < MAX;i++)
		printf("%d <=> %d\n",aresta[i].verticeOrigem, aresta[i].verticeDestino);

}

//e)Criar o fecho transitivo para o grafo dos municípios e imprimir a matriz e a lista de aresta com as novas características.    (peso = 1,25)
void fechoTrans(){

    mFT[0][2] = 1;
	mFT[0][4] = 1;
	mFT[0][6] = 1;
	mFT[1][3] = 1;
	mFT[1][6] = 1;
	mFT[2][4] = 1;
	mFT[3][0] = 1;
	mFT[3][1] = 1;
	mFT[4][0] = 1;
	mFT[4][1] = 1;
	mFT[4][5] = 1;
	mFT[5][1] = 1;	
    mFT[5][3] = 1;
	mFT[5][6] = 1;
	mFT[6][1] = 1;
	mFT[6][2] = 1;
	mFT[6][5] = 1;

//Fecho Transitivo
	mFT[0][3] = 1;
	mFT[1][4] = 1;
	mFT[1][5] = 1;
	mFT[2][0] = 1;
	mFT[2][6] = 1;
	mFT[3][5] = 1;
	mFT[4][2] = 1;	
    mFT[5][4] = 1;
    mFT[6][0] = 1;
	mFT[6][2] = 1;

	printf("\n");
	int k,l;
	
	printf(" Fecho Transitivo \n");

	for(k=0;k<VERFT;k++){
		for(l=0;l < VERFT;l++){
			printf("%d  ",mFT[k][l]);
		}
		printf("\n");
	}


	printf("\n Lista de Aresta Fecho Transitivo \n");	
	int i;
	for(i = 0; i < MAXFT;i++)
		printf("%d <=> %d\n",aresta[i].verticeOrigem, aresta[i].verticeDestino);


}
