/*  
    NOME: Caroline Souza Camargo
    CURSO: Ciências da Computação
    
    EXERCÍCIO 1
    
    Este código lê três valores inteiros digitados por linha de comando:
        - Largura, Altura e PrimeiroElemento 
    
    Em uma função à parte é criado uma matriz de tamanho Largura x Altura, definidas pelos dois primeiros valores informados pelo usuário. 
    
    Em uma segunda função à parte, é preenchido a primeira posição dessa matriz com o terceiro valor informado pelo usuário (PrimeiroElemento). 
    
    Para as demais posições: 
        Na primeira linha, cada nova posição será o múltiplo de 3 da posição anterior. 
        Para todas as linhas abaixo da primeira, serão preenchidos com o dobro da anterior. 

*/

#include <stdio.h>
#include <string.h>

int i, j;

int preenchendomatriz(int l, int a, int p, int m[a][l])
{
    /*  Função para prencher a matriz.   Onde:  l = largura da matriz
                                                a = altura da matriz
                                                p = primeiro elemento da matriz
                                                m = matriz                              
    */

    int temp=p;
    for (i=0; i<a; i++){
        for (j=0; j<l; j++) {
            if (i==0 && j==0){
                m[i][j] = p;
            } else if(i==0 && j>0){
                temp = temp*3;
                m[i][j]=temp;
            } else{
                temp = m[i-1][j]*2;
                m[i][j]=temp;
            }
        }
    }
    leitura(l,a,m);
}

/* Função para ler a matriz */
int leitura(int l, int a, int m[a][l]){    

    for (i=0; i<a; i++){
        for (j=0; j<l; j++) {
            printf ("    %d", m[i][j]);
        }
        printf("\n");
    }
}


int main(int argc, char *argv[ ]){    
    int linha, coluna, primeiro;
    coluna = atoi(argv[1]);
    linha = atoi(argv[2]);
    primeiro = atoi(argv[3]);

    int matriz[linha][coluna];
    for (i=0; i<linha; i++){
        for (j=0; j<coluna; j++) {
            matriz[i][j] = 0;
        }
    }

    printf ("\n\nMatriz gerada com zeros\n\n");
    leitura(coluna,linha,matriz); 

    printf ("\n\nMatriz preenchida com os devidos elementos\n\n");  
    preenchendomatriz(coluna,linha,primeiro,matriz);
}

 
