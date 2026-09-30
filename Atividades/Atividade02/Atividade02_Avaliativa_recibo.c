/*- Qual problema o scanf("%s") causa com nomes compostos
e como seu programa evita isso? ELE INTERROMPE A LEITURA 
NO PRIMEIRO ESPAÇO EM BRANCO, EX. SERIA SE EU COLOCASSE MEU NOME 
"LARA MELISSA" ELE IRIA LER APENAS ATÉ LARA E CORROMPER O BUFFER 
DE ENTRADA E DOS PROXIMOS PROGRAMAS DE ENTRADA. */



#include <stdio.h>

int main(){
    int codigo_produto;
    float preco_unitario;
    int quantidade;
    char nome_do_cliente[100];
    char nome_do_produto[100];
    char categoria; 


printf("Digite seu nome: ");
fgets (nome_do_cliente, 100, stdin);    
      
printf("Digite o código do produto: ");
scanf ("%d", &codigo_produto);

printf("Digite o nome do produto: ");
scanf ("%s", nome_do_produto);

printf("Categoria disponíveus \n");
printf("A - Papelaria\n");
printf("B - Farmácia\n");
printf("C - Alimentação\n");
printf("Digite a categoria do produto: ");
scanf (" %c", &categoria);

printf("Digite a quantidade de produto: ");
scanf ("%d", &quantidade);

printf("Digite o preço do produto: ");
scanf ("%f", &preco_unitario);




float total = preco_unitario * quantidade;

printf("\n");
printf("====================================\n");
printf("          RECIBO DE COMPRA\n");
printf("====================================\n");
printf("Nome do cliente: %s\n", nome_do_cliente);
printf("Código do produto: %d\n", codigo_produto);
printf("Nome do produto: %s\n", nome_do_produto);
printf("Categoria: %c\n", categoria);
printf("Quantidade: %d\n", quantidade);
printf("Preço Unitário: %.2f\n", preco_unitario);
printf("Total da compra: %.2f\n", total);
printf("====================================");

return 0;

}


