#include <stdio.h>


int main() {


   

    char nome[31];
    int idade;
    
    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite uma idade: ");
    scanf("%d", idade);
    
    
    printf("%s",nome, "%s",idade);

return 0; 

}


    //Leia o nome completo (espaços) e idade; imprima formatado, use fgets + scanf 
//com limpeza de buffer. 