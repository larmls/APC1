/*
 * O fall-through consciente foi mais vantajoso no switch do expediente (dias
 * 2, 3, 4 e 5 -> "Pleno" e dias 1 e 7 -> "Fechado") e no switch do serviço
 * (códigos 1-3 e 4-5): vários valores compartilham exatamente a mesma ação,
 * então um único bloco evita repetir código e reduz o risco de inconsistência
 * se a regra mudar. Já o switch não substitui o if-else-if da atividade
 * anterior na classificação por faixas de renda porque o switch só compara
 * igualdade com constantes inteiras ou char, enquanto faixas exigem
 * comparações relacionais (>=, <) sobre valores reais (float/double).
 */

#include <stdio.h> 

int main(void) {
    int codigo;
    char prioridade;
    int dia;

    const char *servico;
    const char *categoria;
    const char *prazo;
    const char *status;
    double taxa_base;

    const char *prioridade_nome;
    int guiche;
    double acrescimo;

    const char *nome_dia;
    const char *expediente;

    double taxa_final;

    /* Nomes usados dentro dos grupos de fall-through. O índice é seguro
       porque, dentro do bloco do grupo, o código só pode estar no grupo. */
    const char *nomes_documentos[] = {
        "Historico escolar",
        "Declaracao de matricula",
        "Declaracao de vinculo"
    };
    const char *nomes_interrupcao[] = {
        "Trancamento",
        "Cancelamento"
    };

    printf("Codigo do servico (1 a 6): ");
    scanf("%d", &codigo);
    printf("Prioridade (U/N/B): ");
    scanf(" %c", &prioridade); /* espaço antes de %c ignora o Enter do buffer */
    printf("Dia da semana (1 = domingo ... 7 = sabado): ");
    scanf("%d", &dia);

    /* 1. Serviço: switch de int com fall-through de agrupamento */
    switch (codigo) {
        case 1:
            /* fall-through */
        case 2:
            /* fall-through */
        case 3:
            servico = nomes_documentos[codigo - 1];
            categoria = "Documento simples";
            prazo = "2 dias uteis";
            taxa_base = 15.00;
            status = "ACEITO";
            break;
        case 4:
            /* fall-through */
        case 5:
            servico = nomes_interrupcao[codigo - 4];
            categoria = "Interrupcao de vinculo";
            prazo = "10 dias uteis";
            taxa_base = 0.00;
            status = "ACEITO";
            break;
        case 6:
            servico = "Colacao de grau";
            categoria = "Ato solene";
            prazo = "15 dias uteis";
            taxa_base = 80.00;
            status = "ACEITO";
            break;
        default:
            servico = "Codigo invalido";
            categoria = "-";
            prazo = "0";
            taxa_base = 0.00;
            status = "RECUSADO";
            break;
    }

    /* 2. Prioridade: switch de char, maiúscula e minúscula agrupadas */
    switch (prioridade) {
        case 'U':
            /* fall-through */
        case 'u':
            prioridade_nome = "Urgente";
            guiche = 1;
            acrescimo = 10.00;
            break;
        case 'N':
            /* fall-through */
        case 'n':
            prioridade_nome = "Normal";
            guiche = 2;
            acrescimo = 0.00;
            break;
        case 'B':
            /* fall-through */
        case 'b':
            prioridade_nome = "Balcao";
            guiche = 3;
            acrescimo = 0.00;
            break;
        default:
            prioridade_nome = "Invalida";
            guiche = 0;
            acrescimo = 0.00;
            break;
    }

    /* 3. Nome do dia: break em todo case (fall-through proibido) */
    switch (dia) {
        case 1:
            nome_dia = "Domingo";
            break;
        case 2:
            nome_dia = "Segunda-feira";
            break;
        case 3:
            nome_dia = "Terca-feira";
            break;
        case 4:
            nome_dia = "Quarta-feira";
            break;
        case 5:
            nome_dia = "Quinta-feira";
            break;
        case 6:
            nome_dia = "Sexta-feira";
            break;
        case 7:
            nome_dia = "Sabado";
            break;
        default:
            nome_dia = "Dia invalido";
            break;
    }

    /* 4. Expediente: switch de int com fall-through de agrupamento */
    switch (dia) {
        case 2:
            /* fall-through */
        case 3:
            /* fall-through */
        case 4:
            /* fall-through */
        case 5:
            expediente = "Pleno";
            break;
        case 6:
            expediente = "Reduzido";
            break;
        case 1:
            /* fall-through */
        case 7:
            expediente = "Fechado";
            break;
        default:
            expediente = "Dia invalido";
            break;
    }

    /* Cálculo final, sem condição */
    taxa_final = taxa_base + acrescimo;

    printf("\n========================================\n");
    printf(" TRIAGEM DE PROTOCOLO ACADEMICO\n");
    printf("========================================\n");
    printf("Servico    : %s\n", servico);
    printf("Categoria  : %s\n", categoria);
    printf("Prazo      : %s\n", prazo);
    printf("Taxa base  : R$ %.2f\n", taxa_base);
    printf("Prioridade : %s\n", prioridade_nome);
    printf("Guiche     : %d\n", guiche);
    printf("Acrescimo  : R$ %.2f\n", acrescimo);
    printf("Dia        : %s\n", nome_dia);
    printf("Expediente : %s\n", expediente);
    printf("-----------------------------------------------------------------------\n");
    printf("Taxa final : R$ %.2f\n", taxa_final);
    printf("Status do servico : %s\n", status);
    printf("========================================\n");

    return 0;
}