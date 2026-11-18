#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TURMA 30
#define TAM_NOME 41

enum StatusAluno { REPROVADO = 0, RECUPERACAO = 1, APROVADO = 2 };

struct Aluno {
    int matricula;
    char nome[TAM_NOME];
    float a1;
    float a2;
    enum StatusAluno status;
};

/* calcular a média */

static float calcular_media(float a1, float a2)
{
    return 0.4f * a1 + 0.6f * a2;
}

static enum StatusAluno calcular_status(float media)
{
    if (media >= 5.0f) return APROVADO;
    if (media >= 3.0f) return RECUPERACAO;
    return REPROVADO;
}

static const char *texto_status(enum StatusAluno s)
{
    switch (s) {
        case APROVADO:    return "APROVADO";
        case RECUPERACAO: return "RECUPERACAO";
        default:          return "REPROVADO";
    }
}

static void imprimir_aluno(const struct Aluno *a)
{
    printf("%d | %s | %.1f | %.1f | %.2f | %s\n",
           a->matricula, a->nome, a->a1, a->a2,
           calcular_media(a->a1, a->a2), texto_status(a->status));
}

/* Le uma linha com fgets e remove o '\n'. Retorna 0 em EOF. */
static int ler_linha(char *buf, int tam)
{
    size_t n;
    if (fgets(buf, tam, stdin) == NULL) return 0;
    n = strlen(buf);
    if (n > 0 && buf[n - 1] == '\n') {
        buf[n - 1] = '\0';
    } else {
        int c; /* linha maior que o buffer: descarta o resto */
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
    return 1;
}

static int ler_inteiro(const char *msg, int *valor)
{
    char linha[64];
    for (;;) {
        printf("%s", msg);
        if (!ler_linha(linha, sizeof linha)) return 0;
        if (sscanf(linha, "%d", valor) == 1) return 1;
        printf("Valor invalido. Tente de novo.\n");
    }
}

static int ler_nota(const char *msg, float *valor)
{
    char linha[64];
    for (;;) {
        printf("%s", msg);
        if (!ler_linha(linha, sizeof linha)) return 0;
        if (sscanf(linha, "%f", valor) == 1 && *valor >= 0.0f && *valor <= 10.0f)
            return 1;
        printf("Nota invalida (use um valor entre 0 e 10).\n");
    }
}

/* Copia em minusculas para busca sem diferenciar maiusculas/minusculas */
static void para_minusculas(const char *origem, char *destino)
{
    int i;
    for (i = 0; origem[i] != '\0'; i++)
        destino[i] = (char)tolower((unsigned char)origem[i]);
    destino[i] = '\0';
}

/* ---------- Programa principal ---------- */

int main(void)
{
    struct Aluno turma[TURMA];
    int total = 0;
    int opcao = 0;
    int i;

    do {
        printf("\n===== CADASTRO DE TURMA =====\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Buscar matricula\n");
        printf("4. Buscar trecho do nome\n");
        printf("5. Estatisticas\n");
        printf("6. Sair\n");
        if (!ler_inteiro("Opcao: ", &opcao)) break;

        switch (opcao) {

        case 1: { /* Cadastrar */
            struct Aluno novo;
            int duplicada = 0;

            if (total >= MAX) {
                printf("Turma cheia (maximo de %d alunos).\n", MAX);
                break;
            }
            if (!ler_inteiro("Matricula: ", &novo.matricula)) break;

            for (i = 0; i < total; i++) {
                if (turma[i].matricula == novo.matricula) duplicada = 1;
            }
            if (duplicada) {
                printf("Matricula ja cadastrada.\n");
                break;
            }

            printf("Nome: ");
            if (!ler_linha(novo.nome, TAM_NOME)) break;
            if (!ler_nota("A1: ", &novo.a1)) break;
            if (!ler_nota("A2: ", &novo.a2)) break;

            novo.status = calcular_status(calcular_media(novo.a1, novo.a2));
            turma[total] = novo;
            total++;
            printf("Aluno cadastrado. Status: %s\n", texto_status(novo.status));
            break;
        }

        case 2: /* Listar */
            if (total == 0) {
                printf("Nenhum aluno cadastrado.\n");
                break;
            }
            printf("matricula | Nome | A1 | A2 | Media | Status\n");
            for (i = 0; i < total; i++) imprimir_aluno(&turma[i]);
            break;

        case 3: { /* Buscar por matricula */
            int mat, achou = 0;
            if (!ler_inteiro("Matricula a buscar: ", &mat)) break;
            for (i = 0; i < total && !achou; i++) {
                if (turma[i].matricula == mat) {
                    printf("matricula | Nome | A1 | A2 | Media | Status\n");
                    imprimir_aluno(&turma[i]);
                    achou = 1;
                }
            }
            if (!achou) printf("nao encontrado\n");
            break;
        }

        case 4: { /* Buscar por trecho do nome */
            char trecho[TAM_NOME], trecho_min[TAM_NOME], nome_min[TAM_NOME];
            int achados = 0;
            printf("Trecho do nome: ");
            if (!ler_linha(trecho, TAM_NOME)) break;
            para_minusculas(trecho, trecho_min);
            for (i = 0; i < total; i++) {
                para_minusculas(turma[i].nome, nome_min);
                if (strstr(nome_min, trecho_min) != NULL) {
                    if (achados == 0)
                        printf("matricula | Nome | A1 | A2 | Media | Status\n");
                    imprimir_aluno(&turma[i]);
                    achados++;
                }
            }
            if (achados == 0) printf("nao encontrado\n");
            break;
        }

        case 5: { /* Estatisticas */
            int qtd[3] = {0, 0, 0};
            float soma = 0.0f;
            if (total == 0) {
                printf("Nenhum aluno cadastrado.\n");
                break;
            }
            for (i = 0; i < total; i++) {
                qtd[turma[i].status]++;
                soma += calcular_media(turma[i].a1, turma[i].a2);
            }
            printf("Aprovados:    %d\n", qtd[APROVADO]);
            printf("Recuperacao:  %d\n", qtd[RECUPERACAO]);
            printf("Reprovados:   %d\n", qtd[REPROVADO]);
            printf("Media geral da turma: %.2f\n", soma / total);
            break;
        }

        case 6:
            printf("Encerrando.\n");
            break;

        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 6);

    return 0;
}