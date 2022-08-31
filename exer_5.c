/*  
    NOME: Caroline Souza Camargo
    CURSO: Ciências da Computação

    EXERCÍCIO 5
    Implementando código para reaproveitamento de informações sobre os particionamentos no AOM (software de referência do AV1)
*/


//Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Variáveis globais
long int **mat_1, contador[6][6];

//Protótipos Funções
void lendoarquivo(int maxAltura, int maxLargura, int b, int c, int d);

//Função Main
int main()
{
    FILE *arquivoLeitura, *arquivoescrita;
    int coluna_1, linha_1;
    char nomearquivo_1[40], nome_csv[100]="55-43 Video touchdown_pass_1080p_60f(numeros).csv";
    coluna_1 = 1920/4;
    linha_1 = 1080/4;
    
    strcpy(nomearquivo_1, "csvs - tamanho de bloco/touchdown_pass_1080p_60f/av1_55.csv");    //cq maior
    
    //Zera contador
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            contador[i][j]=0;
        }
    }

    // Aloca um vetor de LIN ponteiros para linhas
    mat_1 = malloc(linha_1 * sizeof (int*));

    // Aloca cada uma das linhas (vetores de COL inteiros)
    for (int i=0; i<linha_1; i++) {
        mat_1[i] = malloc(coluna_1 * sizeof (int*));
    }
    
    // Percorre a matriz e preenche com noves
    for (int i=0; i<linha_1; i++) {
        for (int j=0; j<coluna_1; j++) {
            mat_1[i][j]=9;              //Coloquei nove para saber quando não é um número do csv          
        }
    }

    // Abrindo arquivo CSV
    arquivoLeitura= fopen(nomearquivo_1, "r");
    if (arquivoLeitura == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return 1;
    }
    
    // Percorrendo linhas do arquivo CSV 
    char cabecalho_1[100];
    int a_1, b_1, c_1, d_1, e_1;
    int index=0;
    fscanf(arquivoLeitura, "%s", cabecalho_1);

    // a:num_quadro     b:pos_coluna     c:pos_linha      d:tam_bloco     e:lixo
    while (fscanf(arquivoLeitura, "%d,%d,%d,%d,%d", &a_1, &b_1, &c_1, &d_1, &e_1) != EOF) {
        lendoarquivo(linha_1, coluna_1, b_1, c_1, d_1);
        index=a_1;
    }
    
    //Calculando Percentual
    double contador_percentual[6][6];
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            double aa, bb, cc, dd, ee, ff;
            aa=contador[i][0];
            bb=contador[i][1];
            cc=contador[i][2];
            dd=contador[i][3];
            ee=contador[i][4];
            ff=contador[i][5];
            contador_percentual[i][j] = 100 * (contador[i][j] / (aa + bb + cc + dd + ee + ff));
            if ((aa + bb + cc + dd + ee + ff) == 0){
                contador_percentual[i][j]=0;
            }
        }
    }

    arquivoescrita = fopen(nome_csv, "w");
    if (arquivoescrita == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return 1;
    }

    //Mostrando resultados
    printf("\n\nRelacao Numerica de profundidade entre o CQ maior e o CQ menor\n");
    printf("\n\t0\t1\t2\t3\t4\t5\n\n");
    for (int i=0; i<6; i++) {
        printf("%d\t",i);
        for (int j=0; j<6; j++) {
            printf("%d\t",contador[i][j]);
            fprintf(arquivoescrita, "%d,", contador[i][j]);
        }
        printf("\n");
        fprintf(arquivoescrita, "\n");
    }
 

    printf("\nRelacao percentual\n");
    printf("\n\t0\t\t1\t\t2\t\t3\t\t4\t\t5\n\n");
    for (int i=0; i<6; i++) {
        printf("%d\t",i);
        for (int j=0; j<6; j++) {
            printf("%f\t",contador_percentual[i][j]);
            //fprintf(arquivoescrita, "%f,", contador_percentual[i][j]);
        }
        printf("\n");
        //fprintf(arquivoescrita, "\n");
    }

    fclose(arquivoescrita);
    fclose(arquivoLeitura);

    // libera a memória da matriz
    for (int i=0; i<linha_1; i++) {
        free(mat_1[i]);
    }
    free(mat_1);

    printf("\nFim do programa\n");
}

void lendoarquivo(int maxAltura, int maxLargura, int b, int c, int d)
{
    /*  (a) número do quadro 
		(b) posição da coluna (largura) 
		(c) posição da linha (altura)
		(d) código do tamanho do bloco */

    // Testando Código do tamanho do bloco  
    int largura, altura, profundidade;
    if(d == 0){
        largura = 4;
        altura = 4;
        profundidade = 5;
    } else if (d == 1) {
        largura = 4;
        altura = 8;
        profundidade = 4;
    } else if (d == 2) {
        largura = 8;
        altura = 4;
        profundidade = 4;
    } else if (d == 3) {
        largura = 8;
        altura = 8;
        profundidade = 4;
    } else if (d == 4) {
        largura = 8;
        altura = 16;
        profundidade = 3;
    } else if (d == 5) {
        largura = 16;
        altura = 8;
        profundidade = 3;
    } else if (d == 6) {
        largura = 16;
        altura = 16;
        profundidade = 3;
    } else if (d == 7) {
        largura = 16;
        altura = 32;
        profundidade = 2;
    } else if (d == 8) {
        largura = 32;
        altura = 16;
        profundidade = 2;
    } else if (d == 9) {
        largura = 32;
        altura = 32;
        profundidade = 2;
    } else if (d == 10) {
        largura = 32;
        altura = 64;
        profundidade = 1;
    } else if (d == 11) {
        largura = 64;
        altura = 32;
        profundidade = 1;
    } else if (d == 12) {
        largura = 64;
        altura = 64;
        profundidade = 1;
    } else if (d == 13) {
        largura = 64;
        altura = 128;
        profundidade = 0;
    } else if (d == 14) {
        largura = 128;
        altura = 64;
        profundidade = 0;
    } else if (d == 15) {
        largura = 128;
        altura = 128;
        profundidade = 0;
    } else if (d == 16) {
        largura = 4;
        altura = 16;
        profundidade = 3;
    } else if (d == 17) {
        largura = 16;
        altura = 4;
        profundidade = 3;
    } else if (d == 18) {
        largura = 8;
        altura = 32;
        profundidade = 2;
    } else if (d == 19) {
        largura = 32;
        altura = 8;
        profundidade = 2;
    } else if (d == 20) {
        largura = 16;
        altura = 64;
        profundidade = 1;
    } else if (d == 21) {
        largura = 64;
        altura = 16;
        profundidade = 1;
    } else{
        printf("Erro! não foi possível encontrar o código");
    }
    
    //(b) posição da coluna (largura);
    //(c) posição da linha (altura);
    for (int i=c; i < (c + altura); i++) {
        for (int j=b; j < (b + largura); j++) {
            if (i < maxAltura && j < maxLargura) {
                mat_1[i][j] = profundidade;
            }
        }
    }
}
