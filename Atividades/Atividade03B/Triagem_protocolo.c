/* “Em qual trecho o fall- through consciente foi mais vantajoso do que repetir o mesmo bloco em cases separados? Por que o switch
não substitui o if-else-if da atividade anterior na classificação por faixas de renda?” */


#include <stdio.h>

int main(void) { 
    int codigo_servico;
    int dia_semana = 7;
    char categoria[100];
    char prazo;
    char status;
    char servico[100];
    char prioridade;
    char guiche;
    char expediente;
    float acrescimo;
    float taxa_base;
    float taxa_final;
    

    
    printf("Digite o Serviço: ");
    fgets(codigo_servico, 100, stdin);










    switch (codigo_servico)
    {
    case 1: codigo_servico = "Historico Escolar:";
        /* fall - through */

    case 2: codigo_servico = "Declaração de Matrícula";
    case 3: codigo_servico = "Declaração de Vínculo";
    
    prazo = 2;
    taxa_base = 15.00;
    

        break;

    case 4: codigo_servico = "";


    
    default:
        break;
    }


    switch(dia_semana) {
   case 1: printf("Domingo\n"); break;
   case 2: printf("Segunda\n"); break;
   case 3: printf("Terça\n"); break;
   case 4: printf("Quarta\n"); break;
   case 5: printf("Quinta\n"); break;
   case 6: printf("Sexta\n"); break;
   case 7: printf("Sábado\n"); break;
   default: printf("Dia da semana inválido\n");
}









    printf("\n========================================\n");
    printf("    TRIAGEM DE PROTOCOLO ACADEMICO \n");
    printf("========================================\n");
    printf("Serviço        : %s\n ", codigo_servico);
    printf("Categoria  : ", categoria);
    printf("Prazo         : ", prazo);
    printf("Taxa Base : %.1f%%\n", taxa_base);
    printf("Prioridade         : ", prioridade);
    printf("Guichê         : ", guiche);
    printf("Acrescimo  : %.1f%%\n", acrescimo);
    printf("Dia da semana         : ", dia_semana);
    printf("Expediente         : ", expediente);
    printf("----------------------------------------------------------\n");
    printf("Taxa Final   : %.1f%%\n", taxa_final);
    printf("Status do serviço       : %s\n", status ? "ACEITO" : "NÃO ACEITO");
    printf("========================================\n");



    return 0;

}