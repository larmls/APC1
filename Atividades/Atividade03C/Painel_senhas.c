/*
 * Por que o menu precisa de do-while, e nao de while?
 * 
 * O menu precisa aparecer pelo menos uma vez antes de qualquer decisao. No
 * do-while a condicao e testada no fim, entao o menu e exibido e a opcao e
 * lida antes de saber se o programa continua. Com while seria preciso ler a
 * opcao antes do laco ou forcar um valor inicial artificial.
 * 
 * 
 * Em qual trecho o continue evita contar uma senha inválida, e o que ocorreria
 * na busca prioritária se o break fosse omitido?”
 * 
 * No lote (opcao 1), o continue evita contar uma senha invalida: quando a
 * senha e negativa, somo em ignoradas e o continue salta para a proxima leitura.
 * Na busca prioritaria, sem o break o laco infinito nunca terminaria: o
 * programa ficaria preso pedindo senhas e nao voltaria ao menu.
 */
#include <stdio.h>
 
int main(void)
{
    int opcao;
 
    do {
        printf("===== PAINEL DE SENHAS =====\n");
        printf("1 - Registrar lote\n");
        printf("2 - Simular chamadas\n");
        printf("3 - Grade de guiches\n");
        printf("4 - Buscar senha prioritaria\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
 
        switch (opcao) {
        case 1: {
            int senha, atendidas = 0, ignoradas = 0, pares = 0;
 
            printf("Senha: ");
            scanf("%d", &senha);
            while (senha != 0) {
                if (senha < 0) {
                    ignoradas++;
                    printf("Senha: ");
                    scanf("%d", &senha); /* le a proxima antes do continue */
                    continue;
                }
                atendidas++;
                if (senha % 2 == 0) {
                    pares++;
                }
                printf("Senha: ");
                scanf("%d", &senha);
            }
            printf("Atendidas : %d\n", atendidas);
            printf("Ignoradas : %d\n", ignoradas);
            printf("Pares : %d\n", pares);
            break;
        }
        case 2: {
            int inicio, fim, passo, i, executou = 0;
 
            printf("Inicio: ");
            scanf("%d", &inicio);
            printf("Fim: ");
            scanf("%d", &fim);
            printf("Passo: ");
            scanf("%d", &passo);
 
            if (passo == 0) {
                printf("Passo invalido\n");
            } else if (passo > 0) {
                for (i = inicio; i <= fim; i += passo) {
                    if (!executou) {
                        printf("Chamadas:");
                        executou = 1;
                    }
                    printf(" %d", i);
                }
            } else {
                for (i = inicio; i >= fim; i += passo) {
                    if (!executou) {
                        printf("Chamadas:");
                        executou = 1;
                    }
                    printf(" %d", i);
                }
            }
            if (passo != 0) {
                if (executou) {
                    printf("\n");
                } else {
                    printf("Nenhuma chamada\n");
                }
            }
            break;
        }
        case 3: {
            int g, s, i, j;
 
            printf("Guiches (1 a 4): ");
            scanf("%d", &g);
            printf("Senhas por guiche (1 a 5): ");
            scanf("%d", &s);
 
            if (g < 1 || g > 4 || s < 1 || s > 5) {
                printf("Grade invalida\n");
            } else {
                for (i = 1; i <= g; i++) {
                    printf("Guiche %d:", i);
                    for (j = 1; j <= s; j++) {
                        printf(" %d", j);
                    }
                    printf("\n");
                }
            }
            break;
        }
        case 4: {
            int senha, lidas = 0;
 
            for (;;) {
                printf("Senha: ");
                scanf("%d", &senha);
                if (senha == 0) { /* zero testado antes do multiplo de 10 */
                    printf("Nao encontrada\n");
                    printf("Lidas : %d\n", lidas);
                    break;
                }
                if (senha > 0 && senha % 10 == 0) {
                    printf("Prioritaria : %d\n", senha);
                    printf("Lidas antes : %d\n", lidas);
                    break;
                }
                lidas++;
            }
            break;
        }
        case 0:
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 0);
 
    printf("Painel encerrado.\n");
    return 0;
}