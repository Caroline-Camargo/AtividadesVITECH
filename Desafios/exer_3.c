/*  
    NOME: Caroline Souza Camargo
    CURSO: Ciências da Computação

    EXERCÍCIO 3

    Este código converte um arquivo CSV de vídeo em várias imagens PGM.

    Deverá ser passado por linha de comando os seguintes argumentos: largura  altura  nomeArquivoCSV

    OBS.: Cada linha do CSV contêm seis informações: 
        (a) número do quadro 
		(b) posição da coluna (largura); 
		(c) posição da linha (altura); 
		(d) largura do bloco a ser desenhado; 
		(e) altura do bloco a ser desenhado; e 
		(f) valor da posição.

    O código irá preencher com o valor (f) todas as posições entre [(b), (c)] até [(b) + (d), (c) + (e)]. 
    Eventualmente pode ocorrer que (b) + (d) ou (c) + (e) seja igual ou maior que largura ou altura. 
    Neste caso, há um condicional para evitar problemas de acesso inválido à posições da imagem.
   
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *arquivoleitura, *arquivoescrita;
int i, j;
int **mat;


void lendoarquivo(int maxAltura, int maxLargura, int b, int c, int d, int e, int f)
{
    /*  (a) número do quadro 
		(b) posição da coluna (largura); 
		(c) posição da linha (altura); 
		(d) largura do bloco a ser desenhado; 
		(e) altura do bloco a ser desenhado; e 
		(f) valor da posição.                       */
    
    for (i=b; i < (b + d); i++) {
        for (j = c; j < ((c + e)); j++) {
            if (i < maxLargura && j < maxAltura) {
                mat[j][i] = f;
            }
        }
    }
}


int exportandoImagem(int Altura, int Largura, int nome)
{
    int temp=0;
    char nomefinal[30];

    //convertendo inteiro para string
    sprintf(nomefinal, "quadro_%d.pgm", nome);

    arquivoescrita = fopen(nomefinal, "wb");
    if (arquivoescrita == NULL) {
        printf("\nErro ao abrir o arquivo (imagem).\n");
        return 1;
    }

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
}


int main(int argc, char *arv[])
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

    // percorre a matriz e preenche com zeros
    for (i=0; i<linha; i++) {
        for (j=0; j<coluna; j++) {
            mat[i][j]=0;            
        }
    }

    // abrindo arquivo CSV
    arquivoleitura = fopen(nomearquivo, "r");
    if (arquivoleitura == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return 1;
    }
    
    // percorrendo linhas do arquivo CSV 
    char cabecalho[100];
    int a, b, c, d, e, f;
    int index=0;
    fscanf(arquivoleitura, "%s", cabecalho);
    while (fscanf(arquivoleitura, "%d,%d,%d,%d,%d,%d", &a, &b, &c, &d, &e, &f) != EOF) {
        if (a!=index){
            exportandoImagem(linha, coluna, index);
            printf("\nImagem %d gerada com sucesso", index);
        }
        lendoarquivo(linha, coluna, b, c, d, e, f);
        index=a;
    }
    exportandoImagem(linha, coluna, index);
    printf("\nImagem %d gerada com sucesso\n", index);
    
    fclose(arquivoleitura);

    // libera a memória da matriz
    for (i=0; i<linha; i++) {
        free(mat[i]);
    }
    free(mat);

    printf("\nFim do programa\n");
}
