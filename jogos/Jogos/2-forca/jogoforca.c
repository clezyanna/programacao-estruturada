
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#define TAMANHO_PALAVRA 20

int totalDeErroas = 6;
	
char palavrasecreta[TAMANHO_PALAVRA];
int Erros_Permitidos;
char chutes[26];
char nome[40];
int tentativas = 0;
int pontuacao=0;



int acertou(){// vai acertar todas as letras da palavra
	for(int i = 0; i < strlen(palavrasecreta);i++){
		if(!jachutou(palavrasecreta[i]))// se for zero
			return 0;

		}
		return 1;
}
void abertura() {
	printf("/****************/\n");
	printf("/ Jogo da Forca */\n");
	printf("/****************/\n\n");
}

int verificaChute(char chute){
	return chute < 65 || chute > 90;
}

void escolheNivel(){
	int nivel;
	do{
		printf("*****Digite o nivel de dificuldade*****\n  *****Nivel 1*****\n  *****Nivel 2*****\n  *****Nivel 3*****\n ");
	    printf("Escolha:" );
		scanf("%d", &nivel);

		if(nivel == 1){
			Erros_Permitidos = 10;
		}else if(nivel == 2){
			Erros_Permitidos = 6;
		}else if(nivel == 3){
			Erros_Permitidos = 3;
		}else{
			printf("Numero invalido!\n");
		}
	}while(nivel<1 || nivel >3);

}

void chuta() {
	char chute;
	while(verificaChute(chute)){
	printf("Qual letra? ");
	scanf(" %c", &chute);
    }
    if(verificaChute(chute)){
    	printf("Só Letras de A-Z Maiusculas\n");
    }

	chutes[tentativas] = chute;
	tentativas++;//com parentese estou dizendo  quero ver o tem dentro da memória.
}

int jachutou(char letra){// Assinatura da função
	int achou = 0;
	for(int j = 0; j < tentativas; j++) {
				if(chutes[j] == letra) {
					achou = 1;
					break;
				
			    }
	
	}
	return achou;

}

int ganhou(){

	for(int i = 0; i < strlen(palavrasecreta); i++){
		if(!jachutou(palavrasecreta[i])){
			return 0;
		}
	}
	return 1;
}

void pontuac(){

	if(Erros_Permitidos == 10){
		pontuacao++;
	}else if(Erros_Permitidos == 7){
		pontuacao+=2;
	}else{
		pontuacao+=3;
	}
}

void ranking(){
	FILE *f;
	int tamanhoRank;

	f = fopen("ranking.txt", "a");

	printf("Digite o nome do vencedor: \n");
	scanf("%s", nome);
	printf("\nNome:%s\nPontos: %d\n",nome, pontuacao);
	fprintf(f, "%s %d \n", nome, pontuacao);

	fclose(f);

	f = fopen("totalRanking.txt", "r");
	fscanf(f, "%d", &tamanhoRank);
	fclose(f);

	tamanhoRank++;

	f = fopen("totalRanking.txt", "w");
	fprintf(f, "%04d\n", tamanhoRank);
	fclose(f);
}
void desenhaforca(){
	int erros = numChutesErrados();
	if(Erros_Permitidos == 7){
	   printf("  _______         \n");
	   printf(" |/      |        \n");
	   printf(" |      %c%c%c    \n", (erros>0 ? '(' : ' '), (erros>0 ? '_' : ' '),(erros>0 ? ')'  : ' '));
	   printf(" |      %c%c%c    \n", (erros>2 ? '/' : ' '), (erros>1 ? '|' : ' '),(erros >3 ? '\\' : ' '));                                                                );
	   printf(" |        %c      \n", (erros>1 ? '|' : ' '));
	   printf(" |      %c  %c    \n", (erros>4 ? '/' : ' '), (erros>1 ? '/' : ' '));
	   printf(" |                \n");
	   printf("_|__              \n");
	   printf("\n\n");
} else if (Erros_Permitidos == 0 ){

	    printf("  ___________       \n");
		printf(" |/          |      \n");
		printf(" |          %c%c%c  \n", (erros>0 ? '(' : ' '), (erros>1 ? '_' : ' '),(erros>2 ? ')' : ' '));
		printf(" |          %c%c%c  \n", (erros>4 ? '/' : ' '),(erros>5 ? '|' : ' '), (erros>6 ? '\\' : ' '));
		printf(" |           %c     \n", (erros>7 ? '|' : ' '));
		printf(" |          %c %c   \n", (erros>8 ? '/' : ' '),(erros>9 ? '\\' : ' '));
		printf(" |                  \n");
		printf("_|____              \n");	
	}else{
		printf("  ___________       \n");
		printf(" |/          |      \n");
		printf(" |          %c%c%c  \n", (erros>0 ? '(' : ' '), (erros>0 ? '_' : ' '),(erros>0 ? ')' : ' '));
		printf(" |          %c%c%c  \n", (erros>1 ? '/' : ' '),(erros>1 ? '|' : ' '), (erros>1 ? '\\' : ' '));
		printf(" |           %c     \n", (erros>1 ? '|' : ' '));
		printf(" |          %c %c   \n", (erros>2 ? '/' : ' '),(erros>2 ? '\\' : ' '));
		printf(" |                  \n");
		printf("_|____              \n");
	}

	printf("\n\n");



		for(int i = 0; i < strlen(palavrasecreta); i++) {
			char letra = palavrasecreta[i];
			if(jachutou(letra)) {
				printf("%c ", palavrasecreta[i]);
			} else {
				printf("_ ");
			}
		}
		printf("\n");
		

}

void escolhePalavra(){
	FILE* f;

	f = fopen("dicionario.txt","r");

	if(f == 0){
		printf("ERRO! Problema no arquivo!\n ");
		exit(1);
	}

	int quantidadeDePalavras;
	
	fscanf(f, "%d", &quantidadeDePalavras);// fscanf ler a linha do arquivo
	fclose(f);
	srand(time(0));
	f = fopen("palavras.txt", "r");
	if(f==0){
		printf("ERRO! Problema no arquivo!!\n\n");
		exit(1);

	}
 
	int numeroSorteado = rand() % quantidadeDePalavras;

	for(int i = 0 ; i <= numeroSorteado; i++){
		fscanf(f, "%s",  palavrasecreta);
	}

	fclose(f);
}

int contemPalavra(char* palavraNova){
	FILE* f;
	int totalDePalavras;

	f = fopen("palavras.txt", "r");
	fscanf(f, "%d", &totalDePalavras);

	fclose(f);
	f = fopen("palavras.txt", "r");

	for(int i = 0; i < totalDePalavras; i++){
		char palavraNoDicionario[40];
		fscanf(f,"%s", &palavraNoDicionario);

		if(strcmp(palavraNova,palavraNoDicionario) == 0){
			return 1;
		}
	}

    return 0;

}

void colocarPalavra(){

char palavraNova[40];
int novaNuPalavra;

printf("Por favor %s\nDigite uma nova palavra\npara o nosso banco de dados: \n", nome);

	scanf("%s", palavraNova);
	if(contemPalavra(palavraNova)){
		printf("\nDesculpe %s\nEssa palavra ja existe em nosso banco de dados\n\n", nome);
		system("pause");
		system("cls");
	}else{
		for(int i = 0; palavraNova[i]; i++){
		   if(palavraNova[i] < 65 || palavraNova[i] > 90){

              while(palavraNova[i] < 65 || palavraNova[i] > 90){
					printf("Nome invalido, por favor so use letras maiusculas\n");
					scanf("%s", palavraNova);

					if(contemPalavra(palavraNova)){
					printf("\nDesculpe %s\nEssa palavra ja existe em nosso banco de dados\n\n", nome);
					system("pause");
					system("cls");
					return;
		   


               }
             }
          }
       }

       FILE* f;

		f = fopen("palavras.txt","a");
		fprintf(f, "%s\n", palavraNova);

		fclose(f);

		f = fopen("quantidadeDePalavras.txt", "r");
	    fscanf(f, "%d", &novaNuPalavra);
	    fclose(f);

	    novaNuPalavra++;
	    f = fopen("quantidadeDePalavras.txt", "w");
	    fprintf(f, "%04d\n", novaNuPalavra);
	    fclose(f);
   }
}

int enforcou(){
	
   return numChutesErrados() >= Erros_Permitidos;

}

void regrasDoJogo(){
	printf(" **seja bem vindo ao Jogo da Forca**!!!\n\n");
	printf(" Como voce ja deve ter jogado, o jogo da forca trata de voce\n");
	printf(" Chutar letras para tentar achar nossa palavra secreta\n");
	printf(" Mas nosso jogo tem algumas coisas a mais\n");
	printf(" Voce podera escolher o nivel de dificuldade, sendo eles:\n\n");
	printf(" Facil(11 chances e 1 ponto)\n Medio(7 chances e 2 pontos)\n Dificil(4 chances e pontos)\n\n");
	printf(" Caso consiga ganhar, voce podera colocar seu nome em nosso glorioso ranking\n");
	printf(" Tambem, pode nos ajudar e formular novas palavras para nosso banco de dados\n");
	printf(" ATENCAO: em todo o jogo so sao aceitas letras maiusculas, entao, ative o CAPS LOCK E...\n");
	printf(" DIVIRTA-SE!!!\n\n");
	system("pause");
	system("cls");

}
void verificarRankin(){
	char nomeRank[40];
    int pontuacaoRank;
    int tamanhoRank;

	FILE* f;
	f = fopen("totalRanking.txt", "rb");
	fscanf(f,"%d",&tamanhoRank);
	fclose(f);
    if(tamanhoRank == 0){
       printf("Lista vazia\n\n");
    }else{
		f = fopen("ranking.txt", "rb");
		printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
		printf("\xBA       RANKING      \xBA\n");
		printf("\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9\n");
		printf("\xBA NOME      \xBA PONTOS \xBA\n");
		printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");

       	for(int i = 0; i < tamanhoRank; i++){
        	fscanf(f, "%s %d", nomeRank, &pontuacaoRank);
        	printf(" %s -------> %d\n", nomeRank, pontuacaoRank);
        }

        printf("\n");
        fclose(f);
   }

   system("pause");
   system("cls");

}
int letraExiste(char letra){
	for(int j = 0; j < strlen(palavrasecreta);j++){
		if(palavrasecreta[j]== letra){
			return 1;
		}
	 }
	 return 0;

}

int numChutesErrados(){//vai contar quantos chutes errados foram dados.
	int erros = 0;
	for(int i=0; i < tentativas; i++){
		int acertou = 0;

		
	   for (int j = 0; j < strlen(palavrasecreta); j++){
			if(chutes[i] == palavrasecreta[j]){
				acertou = 1;
				break;
			}
		}

		if(acertou == 0){
			erros++;
		}		
	}

       return erros;

}

void finalDoJogo(){
	if(ganhou()){
		printf("******Parabens******\n");
		printf("****Voce venceu!****\n");
		pontuac();
	}else{
		printf("Ah nao foi dessa vez! Voce perdeu\n");
		printf("A palavra era: %s\n", palavrasecreta);
	}
}

void sairDoJogo(){
	for (int i = 0; i < strlen(chutes); ++i){
			chutes[i] = ' ';
	}
	        tentativas = 0;
	system("cls");
}


void adicionapalavra(){
	char escolha;

	printf("voce dejesa adicinar alguma palavra ao nosso Dicionario? (S/N) \n");
	scanf(" %c", &escolha);

	if (escolha == 'S'){
		char novapalavra[TAMANHO_PALAVRA];

		printf("Digite a palavra a ser inserida:\n");
		scanf("%s", novapalavra);

		FILE* f = fopen("dicionario.txt", "r+");

		if(f == 0){
			printf("ERRO! Problema no arquivo!\n ");
			exit(1);

		}

		int quantidadeDePalavras;

		fscanf(f, "%d",&quantidadeDePalavras);
		quantidadeDePalavras++;

		//SEEK_END, SEEK_SET, SEEK_END;
		fseek(f, 0, SEEK_SET);          //vai procurar aonde o ponteiro está.()END,
		fprintf(f, "%d",quantidadeDePalavras); // aonde você vai imprimir?,vai imprimir aonde o ponteiro esta apontando.

		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s",novapalavra);

		fclose(f);//fechar

		                               
	}
}


int main() {

	char again;
	int menu;
	do{
		abertura();
		printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
		printf("\xBA MENU \xBA\n");
		printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
		printf("1) Jogo\n");
		printf("2) Regras\n");
		printf("3) Ranking\n");
		printf("4) Exit\n");

		scanf("%d", &menu);
		system("cls");
		if(menu == 1){
			do{
				escolheNivel();
	            
	            escolhePalavra();
	            abertura();

				do {
		           desenhaforca();
		           chuta();//passando o endereço da memoria
		
	               } while (!acertou() && !enforcou());
	                 finalDoJogo();
	                 printf("\n*********************************\n");
				     printf("**Deseja jogar novamente? <s/n>**\n");
				     printf("*********************************\n");
				     scanf(" %c", &again);
				     sairDoJogo();

				     }while(again == 's' || again == 'S');

			            if(pontuacao > 0){
				             char quest;

				             ranking();
		    	             printf("Deseja digitar um nova palavra? <s/n>\n");
		    	             scanf(" %c", &quest);
		    	             if(quest == 's' || quest == 'S'){
		    		            colocarPalavra();
		    	             }
			            }
			          
			        }else if(menu == 2){
			                  regrasDoJogo();
		            }else if(menu == 3){
			                verificarRankin();
		            }

		                    pontuacao = 0;
	        }while(menu != 4);	




	
		

    
	

	
	

}