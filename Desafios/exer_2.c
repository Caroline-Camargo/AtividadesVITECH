/*  
    NOME: Caroline Souza Camargo
    CURSO: Ciências da Computação

    EXERCÍCIO 2

    Este código converte um arquivo CSV em uma imagem PGM.

    Deverá ser passado por linha de comando os seguintes argumentos: largura  altura  nomeArquivoCSV

    OBS.: Cada linha do CSV contêm quatro informações: 
        (a) posição da coluna (largura); 
        (b) posição da linha (altura); 
        (c) tamanho quadrático do bloco a ser desenhado; 
        (d) valor da posição.

    O código irá preencher com o valor (d) todas as posições entre [(a), (b)] até [(a) + (c), (b) + (c)]. 
    Eventualmente pode ocorrer que (a) + (c) ou (b) + (c) seja igual ou maior que largura ou altura. 
    Neste caso, há um condicional para evitar problemas de acesso inválido à posições da imagem.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *arquivoleitura, *arquivoescrita;
int i, j;
int **mat;


void lendoarquivo(int maxAltura, int maxLargura)
{
    /*  a = Posição da coluna (largura);
        b = Posição da linha (altura);
        c = Tamanho quadrático do bloco a ser desenhado;
        d = Valor da posição.   */
    
    char cabecalho[100];
    int a, b, c, d;
    fscanf(arquivoleitura, "%s", cabecalho);
    while (fscanf(arquivoleitura, "%d,%d,%d,%d", &a, &b, &c, &d) != EOF) {
        for (i=a; i < (a + c); i++) {
            for (j = b; j < (b + c); j++) {
                if (i < maxLargura && j < maxAltura) {
                    mat[j][i] = d;
                }
            }
        }
    }
    printf("\nLeitura e gravação dos dados na matriz foi realizada com sucesso\n");
}

int exportandoImagem(int Altura, int Largura)
{
    int temp=0;
    arquivoescrita = fopen("imagemfinal.pgm", "wb");
    if (arquivoescrita == NULL) {
        printf("\nErro ao abrir o arquivo (imagem).\n");
        return 1;
    }
    printf("\nO arquivo (imagem) foi criado com sucesso.\n");
    
    fprintf(arquivoescrita, "P2\n"); 

    fprintf(arquivoescrita, "%d %d\n", Largura, Altura);

    fprintf(arquivoescrita, "255\n");
    
    for (i=0; i<Altura; i++) {
		for (j=0; j<Largura; j++) {
			temp = mat[i][j];
			// Escrevendo os valores de cinza no array 2D no arquivo
			fprintf(arquivoescrita, "%d ", temp);
		}
		fprintf(arquivoescrita, "\n");
	}
	fclose(arquivoescrita);

    printf("\nA imagem foi gerada com sucesso.\n");
}

int main(int argc, char *argv[])
{
    int coluna, linha;
    char nomearquivo[40];

    coluna = atoi(argv[1]);
    linha = atoi(argv[2]);
    strcpy(nomearquivo, argv[3]);

    // aloca um vetor de LIN ponteiros para linhas
    mat = malloc(linha * sizeof (int*));

    // aloca cada uma das linhas (vetores de COL inteiros)
    for (i=0; i<linha; i++) {
        mat[i] = malloc(coluna * sizeof (int*));
    }

    // percorre a matriz
    for (i=0; i<linha; i++) {
        for (j=0; j<coluna; j++) {
            mat[i][j]=0;            
        }
    }

    arquivoleitura = fopen(nomearquivo, "r");
    if (arquivoleitura == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return 1;
    }
    
    lendoarquivo(linha,coluna);
    exportandoImagem(linha,coluna);

    fclose(arquivoleitura);

    // libera a memória da matriz
    for (i=0; i<linha; i++) {
        free(mat[i]);
    }
    free(mat);

    printf("\nFim do programa\n");
}
