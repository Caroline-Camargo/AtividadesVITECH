/*  
    NOME: Caroline Souza Camargo
    CURSO: Ciências da Computação

    EXERCÍCIO 4.5
*/


//Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Protótipos funções
void mostrando_matriz(float mat[6][6]);


//Função Main
int main()
{
    //Arquivos que serão lidos
    FILE *arquivoleitura_0, *arquivoleitura_1, *arquivoleitura_2, *arquivoleitura_3, *arquivoleitura_4, *arquivoescrita;
    int i=0, j=0;

    //Matrizes que armazenará temporariamente os dados dos arquivos
    float mat_0[6][6], mat_1[6][6], mat_2[6][6], mat_3[6][6], mat_4[6][6], mat_media[6][6];

    //Nomes arquivos
    char nomearquivo_0[]= "55-43 Video rush_hour_1080p25_60f(numeros).csv", 
    nomearquivo_1[]= "55-43 Video Netflix_Crosswalk_1920x1080_60fps_8bit_420_60f(numeros).csv", 
    nomearquivo_2[]= "55-43 Video Netflix_TunnelFlag_1920x1080_60fps_8bit_420_60f(numeros).csv", 
    nomearquivo_3[]= "55-43 Video rush_field_cuts_1080p_60f(numeros).csv", 
    nomearquivo_4[]= "55-43 Video touchdown_pass_1080p_60f(numeros).csv",
    nomearquivo_escrita[]= "55-43 Dados medios(numeros).csv";

   
    // Abrindo arquivo CSVs Leitura
    arquivoleitura_0 = fopen(nomearquivo_0, "r");
    if (arquivoleitura_0 == NULL) {
        printf("\nErro ao abrir o arquivo 0.\n");
        return 1;
    } 
    arquivoleitura_1 = fopen(nomearquivo_1, "r");
    if (arquivoleitura_1 == NULL) {
        printf("\nErro ao abrir o arquivo 1.\n");
        return 1;
    }
    arquivoleitura_2 = fopen(nomearquivo_2, "r");
    if (arquivoleitura_2 == NULL) {
        printf("\nErro ao abrir o arquivo 2.\n");
        return 1;
    }
    arquivoleitura_3 = fopen(nomearquivo_3, "r");
    if (arquivoleitura_3 == NULL) {
        printf("\nErro ao abrir o arquivo 3.\n");
        return 1;
    }
    arquivoleitura_4 = fopen(nomearquivo_4, "r");
    if (arquivoleitura_4 == NULL) {
        printf("\nErro ao abrir o arquivo 4.\n");
        return 1;
    }

    // Abrindo arquivo CSV Escrita
    arquivoescrita = fopen(nomearquivo_escrita, "w");
    if (arquivoescrita == NULL) {
        printf("\nErro ao abrir o arquivo escrita.\n");
        return 1;
    }

    //Lendo arquivos
    float a, b, c, d, e, f; 
    i=0;
    while (fscanf(arquivoleitura_0, "%f,%f,%f,%f,%f,%f,", &a, &b, &c, &d, &e, &f) != EOF) {
            printf("%f\t%f\t%f\t%f\t%f\t%f\n", a, b, c, d, e, f);
            mat_0[i][0]=a;
            mat_0[i][1]=b;
            mat_0[i][2]=c;
            mat_0[i][3]=d;
            mat_0[i][4]=e;
            mat_0[i][5]=f;
            i++;
    }
    
    printf("\n");
    i=0;
    while (fscanf(arquivoleitura_1, "%f,%f,%f,%f,%f,%f,", &a, &b, &c, &d, &e, &f) != EOF) {
           printf("%f\t%f\t%f\t%f\t%f\t%f\n", a, b, c, d, e, f);
           mat_1[i][0] = a;
           mat_1[i][1] = b;
           mat_1[i][2] = c;
           mat_1[i][3] = d;
           mat_1[i][4] = e;
           mat_1[i][5] = f;
           i++;
    }

    printf("\n");
    i=0;
    while (fscanf(arquivoleitura_2, "%f,%f,%f,%f,%f,%f,", &a, &b, &c, &d, &e, &f) != EOF) {
           printf("%f\t%f\t%f\t%f\t%f\t%f\n", a, b, c, d, e, f);
           mat_2[i][0] = a;
           mat_2[i][1] = b;
           mat_2[i][2] = c;
           mat_2[i][3] = d;
           mat_2[i][4] = e;
           mat_2[i][5] = f;
           i++;
    }

    printf("\n");
    i=0;
    while (fscanf(arquivoleitura_3, "%f,%f,%f,%f,%f,%f,", &a, &b, &c, &d, &e, &f) != EOF) {
           printf("%f\t%f\t%f\t%f\t%f\t%f\n", a, b, c, d, e, f);
           mat_3[i][0] = a;
           mat_3[i][1] = b;
           mat_3[i][2] = c;
           mat_3[i][3] = d;
           mat_3[i][4] = e;
           mat_3[i][5] = f;
           i++;
    }

    printf("\n");
    i=0;
    while (fscanf(arquivoleitura_4, "%f,%f,%f,%f,%f,%f,", &a, &b, &c, &d, &e, &f) != EOF) {
           printf("%f\t%f\t%f\t%f\t%f\t%f\n", a, b, c, d, e, f);
           mat_4[i][0] = a;
           mat_4[i][1] = b;
           mat_4[i][2] = c;
           mat_4[i][3] = d;
           mat_4[i][4] = e;
           mat_4[i][5] = f;
           i++;
    }

    for (i=0; i<6; i++) {
        for (j=0; j<6; j++){
            mat_media[i][j]=((mat_0[i][j] + mat_1[i][j] + mat_2[i][j] + mat_3[i][j] + mat_4[i][j])/5);
        }
    }
    
    mostrando_matriz(mat_media);

    fprintf(arquivoescrita, "%s\n", nomearquivo_escrita);
    //Preenchendo arquivo escrita
    for (i=0; i<6; i++) {
        for (j=0; j<6; j++) {
            fprintf(arquivoescrita, "%f,", mat_media[i][j]);
        }
        fprintf(arquivoescrita, "\n");
    }

    fclose(arquivoleitura_0);
    fclose(arquivoleitura_1);
    fclose(arquivoleitura_2);
    fclose(arquivoleitura_3);
    fclose(arquivoleitura_4);
    fclose(arquivoescrita);
}


//Função que mostra matriz
void mostrando_matriz(float mat[6][6]){
    printf("\n\nmostrando matriz\n");
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            printf("%f\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}