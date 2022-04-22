#include <stdio.h>
#include <locale.h>
#define  MAX 7

void inicializar();
void imprimir1();
void ponte();
void vizin();

struct listaAresta{
	int vOrigem;
	int vDestino;
	float grau;
} aresta[MAX];

void main(void){
	inicializar();
	imprimir1();
	vizin();
	ponte();
	
}

void inicializar(){
	setlocale(LC_ALL, "Portuguese");
	//Tentei usar como base o grau de conectividade, que com base no grafo passado, o menor grau seria a ponte a ser localizada.
	
	aresta[0].vOrigem = 1;
	aresta[0].vDestino = 2;
	aresta[0].grau = 2; // 
	
	aresta[1].vOrigem = 1;
	aresta[1].vDestino = 3;
	aresta[1].grau = 2;
	
	aresta[2].vOrigem = 1;
	aresta[2].vDestino = 4;
	aresta[2].grau = 1;
	
	aresta[3].vOrigem = 2;
	aresta[3].vDestino = 3;
	aresta[3].grau = 2;
	
	aresta[4].vOrigem = 3;
	aresta[4].vDestino = 5;
	aresta[4].grau = 2;
	
	aresta[5].vOrigem = 3;
	aresta[5].vDestino = 6;
	aresta[5].grau = 2;
	
	aresta[6].vOrigem = 5;
	aresta[6].vDestino = 6;
	aresta[6].grau = 2;
}

void imprimir1(){
	printf("\n------------------Lista Aresta-------------------\n");
	printf("nº Aresta\tVertice Origem\tVertice Destino\n");
	int i;
	for(i = 0; i < MAX; i++){
		printf("\n\t%d\t|\t%d\t|\t%d", i,aresta[i].vOrigem,aresta[i].vDestino);
	}
	printf("\n-------------------------------------------------\n");
}

void ponte(){
	int i, menor = 1, destino, origem;
	
	printf("--------------->>>BUSCA PONTE<<<----------------\n");
	printf("INFORME O VERTICE ORIGEM: ");
	scanf("%d",&origem);
	printf("INFORME O VERTICE DESTINO: ");
	scanf("%d",&destino);
	
	printf("\nINICIANDO BUSCA\n");
	for(i = 0; i < MAX; i ++){
 		if((aresta[i].vOrigem == origem) && (aresta[i].vDestino == destino)){
 			printf("\nEncontrou o caminho informado -> %d <==> %d\n",aresta[i].vOrigem,aresta[i].vDestino);
			if((aresta[i].grau <= menor)){// Validando a ponte através do tamanho do grau das arestas
					printf("\nPonte Localizada %d <==> %d\n",aresta[i].vOrigem,aresta[i].vDestino);
	 			break;
 			}
 			else{
 				printf("\n\nCaminho Validado, porém não é PONTE %d <==> %d\n",aresta[i].vOrigem,aresta[i].vDestino);
				break;	
			}
		 }
		 else{
			printf("\nO Caminho %d <==> %d não é ponte\n",aresta[i].vOrigem,aresta[i].vDestino); 	
		}	
	}
}

void vizin(int posicao){	
	int  i, cont = 0 ;
	printf("--------------->>>BUSCA VIZINHO<<<----------------\n");
	printf("\nInforme o vertice: \n");
	scanf("%d",&posicao);
	for(i = 0; i < MAX; i ++){ // laço para repetir a quantidade de linhas da matriz
		if(aresta[i].vOrigem == posicao){// Vai validar o vertice de ORIGEM com o valor solicitado, se for igual irá imprimir cada numero repetido
		printf("O Aresta vizinha é: %d\n", i);	// irá imprimir o INDICE DA LISTA
		cont = cont + 1;		
		}
			else if(aresta[i].vDestino == posicao){
			cont = cont + 1;
			printf("O Aresta vizinha é: %d\n",i );	
		}		
	}
	printf("\nGrau: %d\n",cont ) ;// grau de conectividade do vertice.
}

