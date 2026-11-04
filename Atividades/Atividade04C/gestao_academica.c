/*
 * Por que char nome[50] guarda no maximo 49 caracteres uteis?

 * Em C, toda string termina com o caractere nulo '\0', que marca o fim do
 * texto. Esse terminador ocupa uma posicao do vetor, sobrando 49 para letras.
 * 
 * 
 * Em int M[3][4], o primeiro indice e a linha (0 a 2) e o segundo e a coluna
 * (0 a 3). C guarda a matriz na memoria de forma contigua, linha por linha
 * (row-major): M[0][0..3], depois M[1][0..3], depois M[2][0..3], sem lacunas
 * entre os elementos.
 */

 
#include <stdio.h>
#include <string.h>

#define NUM_ALUNOS 5
#define TAM_NOME 50
#define LINHAS 3
#define COLUNAS 4

static void limpar_buffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
        /* tira o que sobrou na linha */
    }
}

/* Le cinco notas em um vetor */
static void ler_notas(float notas[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
    limpar_buffer();
}

int main(void)
{
    int opcao;

    do {
        printf("===== SISTEMA DE GESTAO ACADEMICA =====\n");
        printf("1 - Cadastrar Lista de Alunos (Vetor de Strings)\n");
        printf("2 - Estatisticas de Desempenho (Vetor de Float)\n");
        printf("3 - Matriz de Notas da Turma (Matriz Bidimensional)\n");
        printf("4 - Consultar Aluno em Destaque (Pesquisa em Matriz/Vetor)\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        if (scanf("%d", &opcao) != 1) {
            break; /* entrada encerrada ou invalida */
        }
        limpar_buffer();

        switch (opcao) {
        case 1: {
            char alunos[NUM_ALUNOS][TAM_NOME];
            int i;

            for (i = 0; i < NUM_ALUNOS; i++) {
                printf("Nome do aluno %d: ", i + 1);
                if (fgets(alunos[i], sizeof(alunos[i]), stdin) == NULL) {
                    alunos[i][0] = '\0';
                }
                alunos[i][strcspn(alunos[i], "\n")] = '\0';
            }
            printf("\nLista de alunos:\n");
            for (i = 0; i < NUM_ALUNOS; i++) {
                printf("%d - %s\n", i + 1, alunos[i]);
            }
            break;
        }
        case 2: {
            float notas_finais[NUM_ALUNOS];
            float soma = 0.0f, media;
            int i, acima = 0;

            ler_notas(notas_finais, NUM_ALUNOS); /* primeiro preenche tudo */
            for (i = 0; i < NUM_ALUNOS; i++) {   /* depois processa */
                soma += notas_finais[i];
            }
            media = soma / NUM_ALUNOS;
            for (i = 0; i < NUM_ALUNOS; i++) {
                if (notas_finais[i] >= media) {
                    acima++;
                }
            }
            printf("Media geral da turma: %.2f\n", media);
            printf("Alunos com nota >= media: %d\n", acima);
            break;
        }
        case 3: {
            float boletim[LINHAS][COLUNAS];
            int i, j;

            for (i = 0; i < LINHAS; i++) {
                for (j = 0; j < COLUNAS; j++) {
                    printf("Aluno %d, bimestre %d: ", i + 1, j + 1);
                    scanf("%f", &boletim[i][j]);
                }
            }
            limpar_buffer();

            printf("\n          Bim1   Bim2   Bim3   Bim4   Media\n");
            for (i = 0; i < LINHAS; i++) {
                float soma = 0.0f;

                printf("Aluno %d ", i + 1);
                for (j = 0; j < COLUNAS; j++) {
                    printf("%6.2f ", boletim[i][j]);
                    soma += boletim[i][j];
                }
                printf("%6.2f\n", soma / COLUNAS);
            }
            break;
        }
        case 4: {
            float notas[NUM_ALUNOS];
            float maior;
            int i, indice = 0;

            ler_notas(notas, NUM_ALUNOS);
            maior = notas[0];
            for (i = 1; i < NUM_ALUNOS; i++) {
                if (notas[i] > maior) {
                    maior = notas[i];
                    indice = i;
                }
            }
            printf("Maior nota: %.2f\n", maior);
            printf("Indice no vetor: %d (aluno %d)\n", indice, indice + 1);
            break;
        }
        case 0:
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 0);

    printf("Sistema encerrado.\n");
    return 0;
}