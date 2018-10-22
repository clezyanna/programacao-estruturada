
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_TENTATIVAS 5

int main(){
	// imprime o cabecalho do nosso jogo
	printf("******************************************\n");
	printf("* Bem vindo ao nosso jogo de adivinhacao *\n");	
	printf("******************************************\n");

    int totaldetentativas;
    int nivel;
	int segundos = time (NULL);
    srand(segundos);//sementes do srand,a semente vai mudando direto
	int numerosecreto = rand()%101;
	int pontos = 1000;
	int acertou = 0;

	int chute;
	int tentativas = 1;
	printf("*****Digite o nivel de dificuldade*****\n  *****Nivel 1*****\n  *****Nivel 2*****\n  *****Nivel 3*****\n ");
	printf("Escolha:" );
	scanf("%d",&nivel);
	switch (nivel){
	case 1:
	 totaldetentativas = 20;
	 break;

	 case 2:
	 totaldetentativas = 15;
	 break;

	 default:
	 totaldetentativas = 6;
	 break;
	 
	}

	do{
		printf("Tentativa %d\n", tentativas);
		printf("Qual e o seu chute?");

		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);

		acertou = chute == numerosecreto;
		pontos -=abs((numerosecreto - chute)/2);
	
		if(acertou){
				
				printf("\nacerto !\n");
				
				break;
		}else{
			
			printf("\nErrooo!!!\n");
				
			if(chute > numerosecreto){
				printf("Numero digitado eh maior que o numero secreto!\n\n");
			}else{
				printf("Numero digitado eh menor que o numero secreto!\n\n");
			}
		}
		tentativas++;
	}while(tentativas<totaldetentativas);
	if(acertou){
		printf("Voce terminou com %i pontos\n",pontos);
		printf("Fim de jogo!\n");
	}else{
		printf("Voce perdeu!!! \n");
		printf("Fim de jogo!\n");
	}
	
	return 0;
}