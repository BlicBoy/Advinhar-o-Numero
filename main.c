#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
Autor: Gonçalo Oliveira
*/


//Inicializar
int random();

int main() 
{

    //Limpar consola
    system("cls");

    //Variaveis
    int numeroCerto = 0, tentativas = 0, numeroInserido = 0, tentativasDificuldade = 0, numeroDificuldade = 0;
    char opcao, flag = 1;

    //Escolher nivel de dificuldade
    printf("====== Advinhar Numero - Dificuldade ======");
    printf("\n\t 1- Iniciante \t 2- Medio \t 3- Experiente");

    printf("\nOpcao: ");
    scanf("%c", &opcao);


    //Nivel de dificuldade
    switch (opcao)
    {
        case '1': 
            numeroCerto = random(10);
            numeroDificuldade = 10;
            tentativasDificuldade = 3;
            break;
        case '2':
            numeroCerto = random(30);
            numeroDificuldade = 30;
            tentativasDificuldade = 10;
            break;
        case '3':
            numeroCerto = random(50);
            numeroDificuldade = 50;
            tentativasDificuldade = 15;
            break;
        default:
            main();
            break;
    }

    //Apresentar Numero de tentativas
    printf("\nTem %d tentativas para advinhar o numero de 1 a %d", tentativasDificuldade, numeroDificuldade);

    //pedir primeiro numero
    printf("\nQual e o numero? ");
    scanf("%d", &numeroInserido);

    //Primeira tentativa
    tentativas++;

    //pedir numeros ate esgotar as tentativas ou ate acertar
    while (numeroInserido != numeroCerto && tentativas < tentativasDificuldade )
    {
        //Errou na primeira tentativa
        flag = 0;
        //Dicas
        if(numeroInserido > numeroCerto)
            printf("O numero certo e menor");
        else
            printf("O numero certo e maior!");
   
        //pedir primeiro numero
        printf("\nQual e o numero? ");
        scanf("%d", &numeroInserido);
        
        //se tiver certo ele passa a flag a 1 
        if(numeroInserido == numeroCerto)
            flag = 1;

        //Avisar da ultima tentativa
        if(tentativas == tentativasDificuldade - 2)
            printf("\tULTIMA TENTATIVA!!!\n");
        //+ 1 tentativa    
        tentativas++;     
    }
    


    //Verifica se ganhou ou perdeu
    if(flag == 1)
    {
        printf("\nGanhou!!");
        printf("\nNumero Certo: %d", numeroCerto);
        printf("\nNumero de Tentativas: %d", tentativas);
    }else{
        printf("\nPerdeu!");
        printf("\nO numero certo era: %d", numeroCerto);
    }


    //fim
    getchar();

}


//Escolher numero random
int random(int numeros)
{
    srand( (unsigned)time(NULL) );

    return (1 + rand()%numeros);
}