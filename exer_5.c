/*  
    NOME: Caroline Souza Camargo
    CURSO: Ciências da Computação

    EXERCÍCIO 5
    Implementando código para reaproveitamento de informações sobre os particionamentos no AOM (software de referência do AV1)
*/


//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Protótipos Funções
void LendoArquivo(int **matriz, int maxAltura, int maxLargura, int a, int b, int c, int d, int quadroPesquisar);
int VerificandoProfundidade(int colunaPesquisar, int linhaPesquisar, int quadroPesquisar);

//Função Main Para Testes
int main()
{
    int colunaPesquisar = 72, linhaPesquisar = 0, quadroPesquisar = 0;
	int profundidadeCQMaior = VerificandoProfundidade(colunaPesquisar, linhaPesquisar, quadroPesquisar);
    printf("Profundidade: %d", profundidadeCQMaior);
    printf("\nFim do programa\n");
}

/* NO LIBAOM:   mi_col: coluna
                mi_row: linha
                cm->current_frame.order_hint: quadro codificado */      
int VerificandoProfundidade(int colunaPesquisar, int linhaPesquisar, int quadroPesquisar) {
	FILE *arquivoLeitura;
	char nomeArquivo[] = "teste.csv";    							//Nome do arquivo gerado pelo CQ maior
    int colunaMatriz = 1920/4, linhaMatriz = 1080/4;				//Resolução do vídeo 1920x1080 (FullHD)
	int **matriz;

    // Aloca um vetor de ponteiros para as linhas e depois aloca espaço para as colunas 
    matriz = malloc(linhaMatriz * sizeof (int*));
    for (int i = 0; i < linhaMatriz; i++) {
        matriz[i] = malloc(colunaMatriz * sizeof (int*));
    }
    
    // Percorre a matriz de ponteiros e preenche com noves
    for (int i = 0; i < linhaMatriz; i++) {
        for (int j = 0; j < colunaMatriz; j++) {
            matriz[i][j] = 9;              						    //Coloquei nove para saber quando não é um número do csv          
        }
    }

    // Abrindo arquivo CSV para leitura
    arquivoLeitura = fopen(nomeArquivo, "r");
    if (arquivoLeitura == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
    }
    
    // Percorrendo linhas do arquivo CSV 
    char cabecalho[45];
    int a, b, c, d, e, profundidade;
    fscanf(arquivoLeitura, "%s", cabecalho);

    // a:num_quadro     b:pos_coluna     c:pos_linha      d:tam_bloco     e:lixo
    while (fscanf(arquivoLeitura, "%d,%d,%d,%d,%d", &a, &b, &c, &d, &e) != EOF) {
        LendoArquivo(matriz, linhaMatriz, colunaMatriz, a, b, c, d, quadroPesquisar);
    }

	// Verificando profundidade do CQ Maior na regiao especificada
	for (int i = 0; i < linhaMatriz; i++) {
        for (int j = 0; j < colunaMatriz; j++) {
			if (i == linhaPesquisar && j == colunaPesquisar) {
				profundidade = matriz[i][j];
			}
        }
    }
    
    // fecha arquivo e libera a memória da matriz
    fclose(arquivoLeitura);
    for (int i = 0; i < linhaMatriz; i++) {
        free(matriz[i]);
    }
    free(matriz);

    //retorna a profundidade encontrada (essa função vai estar no inicio do codigo)
    return profundidade;
}

void LendoArquivo(int **matriz, int maxAltura, int maxLargura, int a, int b, int c, int d, int quadroPesquisar)
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
    for (int i = c; i < (c + altura); i++) {
        for (int j = b; j < (b + largura); j++) {
			if (quadroPesquisar == a) {
				if (i < maxAltura && j < maxLargura) {
                	matriz[i][j] = profundidade;
            	}
			}
        }
    }
}

void AplicandoProfundidade(int profundidadeAtual, int profundidadeCQMaior) {
    // Verificando técnica que será implementada
	if (profundidadeCQMaior >=0 && profundidadeCQMaior <= 3) {          //REGRA 1: Mesmo nível de profundidade ou um nível a mais
		if (profundidadeAtual == profundidadeCQMaior || profundidadeAtual == (profundidadeCQMaior + 1)) {
            /* particiona */
            /*
            part_search_state.do_square_split              = true;
            part_search_state.partition_none_allowed       = false;
            part_search_state.do_rectangular_split         = false;
            part_search_state.partition_rect_allowed[HORZ] = false;
            part_search_state.partition_rect_allowed[VERT] = false;
            part_search_state.found_best_partition         = false;
            part_search_state.terminate_partition_search   = false;
            */
        } else {
            /* não particiona */
            /* 
            part_search_state.do_square_split               = false;
            part_search_state.partition_none_allowed        = true;
            part_search_state.do_rectangular_split         &= true;
            part_search_state.partition_rect_allowed[HORZ] &= true;
            part_search_state.partition_rect_allowed[VERT] &= true;
            part_search_state.found_best_partition          = true;
            part_search_state.terminate_partition_search    = true; 
            */
        }
	} else if (profundidadeCQMaior > 3 && profundidadeCQMaior <=5 ) {  //REGRA 2: Evita-se níveis de profundidade menores que 3
		if (profundidadeAtual >= 3) {
            /* particiona */
            /*
            part_search_state.do_square_split              = true;
            part_search_state.partition_none_allowed       = false;
            part_search_state.do_rectangular_split         = false;
            part_search_state.partition_rect_allowed[HORZ] = false;
            part_search_state.partition_rect_allowed[VERT] = false;
            part_search_state.found_best_partition         = false;
            part_search_state.terminate_partition_search   = false;
            */
        } else {
            /* não particiona */
            /* 
            part_search_state.do_square_split               = false;
            part_search_state.partition_none_allowed        = true;
            part_search_state.do_rectangular_split         &= true;
            part_search_state.partition_rect_allowed[HORZ] &= true;
            part_search_state.partition_rect_allowed[VERT] &= true;
            part_search_state.found_best_partition          = true;
            part_search_state.terminate_partition_search    = true; 
            */
        }
	} else {
        printf("\nERRO! (Essa profundidade nao deveria existir)");
    }
}

						
