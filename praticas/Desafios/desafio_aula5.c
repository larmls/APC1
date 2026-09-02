#include <stdio.h>


int main() {


   

    char nome[31];
    int idade;
    
    printf("Digite seu nome: ");
    printf("Digite uma idade: ");

    fgets(nome, sizeof(nome), stdin);
    fgets(idade, sizeof(idade), stdin);
    printf("%s",nome, idade);

return 0; 

}


    //Leia o nome completo (espaços) e idade; imprima formatado, use fgets + scanf 
//com limpeza de buffer. 