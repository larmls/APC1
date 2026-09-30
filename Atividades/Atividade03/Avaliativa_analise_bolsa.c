/* “Em qual situação do seu código o uso do operador ternário ?: é mais vantajoso que o if-else tradicional e em qual situação o if aninhado tornou-se indispensável?” 

Resposta: */


#include <stdio.h>

int main(){
    int idade;
    float renda_mensal;
    float media_academica;
    char nome_do_aluno[100];
    char nome_do_produto[100];
    char status; 


printf("Digite o nome do aluno: \n");
fgets (nome_do_aluno, 100, stdin);    


if (idade < 16 || renda_mensal <= 0)      
printf("Digite a idade do aluno: \n");
scanf ("%d", idade);

printf("Digite a renda familiar mensal: \n");
scanf ("%f", &renda_mensal);


if (media_academica > 0 || media_academica <= 10)
printf("Digite a média acadêmica: \n");
scanf ("%d", &media_academica);

printf("Status de pontualidade de pagamento? \n");
scanf (" %c", &status);











printf("\n");
printf("====================================\n");
printf("            SISTEMA DE AVALIAÇÃO DE DESCONTO \n");
printf("====================================\n");
printf("Nome do Aluno: %s\n", nome_do_aluno);
printf("Faixa Social:");
printf("Média Acadêmica: %s\n", media_academica);
printf("Desconto base: \n");
printf("Bônus Pontual: \n");
printf("====================================");
printf("Desconto total: \n");
printf("Status: %.2f\n", status);


return 0;

}

