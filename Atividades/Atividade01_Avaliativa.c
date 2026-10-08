#include <stdio.h>


#define Ticket 12.50;
#define Cafe 4.00;



int main() {
   int qntd_ticket;
   int qntd_cafe;
   float disponivel_cartao;

printf("Quantidade de ticket semanais é: ");
scanf ("%d", &qntd_ticket);

printf("Quantidade de café semanais é: ");
scanf ("%d", &qntd_cafe);

printf("Valor disponivel no cartão: ");
scanf ("%f", &disponivel_cartao);


float gasto_ticket = qntd_ticket * Ticket;
float gasto_cafe = qntd_cafe * Cafe;
float gasto_total = gasto_ticket + gasto_cafe;
float saldo_restante = gasto_total - disponivel_cartao;
  
printf("Gasto tickets: $ %.2f\n", gasto_ticket);
printf("Gasto café: $ %.2f\n", gasto_cafe);
printf("Gasto total: $ %.2f\n", gasto_total);
printf("Salto disponivel no cartão: $ %.2f\n", saldo_restante);




return 0;

}