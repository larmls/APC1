/*
 * Resposta curta:
 * O operador ternario ?: e mais vantajoso quando a decisao so serve
 * para colocar um de dois valores a uma variavel,pois deixa o codigo curto 
 * e direto em uma unica linha. 
 * 
 * Ja o if aninhado foi indispensavel no desconto
 * base, porque a regra da media depende antes da faixa social: cada
 * faixa tem seu proprio limite de media e seus proprios percentuais.
 */

#include <stdio.h>
#include <string.h> // O código mede o tamanho do texto com strlen e troca o \n final por \0

int main(void)
{
    int idade;
    float renda_mensal;
    float media_academica;
    char nome_do_aluno[100];
    char status;
    char faixa;
    float desconto_base = 0.0f;
    float bonus;
    float desconto_total;
    size_t tam;

    
    printf("Digite o nome do aluno: ");
    fgets(nome_do_aluno, 100, stdin);
    tam = strlen(nome_do_aluno);
    if (tam > 0 && nome_do_aluno[tam - 1] == '\n') {
        nome_do_aluno[tam - 1] = '\0';
    }

    printf("Digite a idade do aluno: ");
    scanf("%d", &idade);

    printf("Digite a renda familiar mensal: ");
    scanf("%f", &renda_mensal);

    printf("Digite a media academica (0.0 a 10.0): ");
    scanf("%f", &media_academica);

    printf("Pontualidade no pagamento (S/N): ");
    scanf(" %c", &status);

    
    if (idade < 16 || renda_mensal <= 0) {
        printf("Erro: idade minima 16 anos e renda maior que zero.\n");
        return 1;
    }
    if (media_academica < 0.0f || media_academica > 10.0f) {
        printf("Erro: a media deve estar entre 0.0 e 10.0.\n");
        return 1;
    }

    
    if (renda_mensal <= 2000.0f) {
        faixa = 'A';
    } else if (renda_mensal <= 5000.0f) {
        faixa = 'B';
    } else {
        faixa = 'C';
    }

    
    if (faixa == 'A') {
        if (media_academica >= 8.5f) {
            desconto_base = 50.0f;
        } else {
            desconto_base = 30.0f;
        }
    } else if (faixa == 'B') {
        if (media_academica >= 9.0f) {
            desconto_base = 25.0f;
        } else {
            desconto_base = 10.0f;
        }
    } else {
        if (media_academica >= 9.5f) {
            desconto_base = 10.0f;
        } else {
            desconto_base = 0.0f;
        }
    }

    /* Bonus*/
    bonus = (status == 'S' || status == 's') ? 5.0f : 0.0f;
    desconto_total = desconto_base + bonus;

    
    printf("\n========================================\n");
    printf("    SISTEMA DE AVALIACAO DE DESCONTO\n");
    printf("========================================\n");
    printf("Aluno         : %s\n", nome_do_aluno);
    printf("Faixa Social  : Faixa %c\n", faixa);
    printf("Media         : %.2f\n", media_academica);
    printf("Desconto Base : %.1f%%\n", desconto_base);
    printf("Bonus Pontual : %.1f%%\n", bonus);
    printf("----------------------------------------\n");
    printf("Desconto Total: %.1f%%\n", desconto_total);
    printf("Status        : %s\n",
           desconto_total > 0 ? "APROVADO PARA BOLSA" : "SEM DESCONTO");
    printf("========================================\n");

    return 0;
}