#include <stdio.h>
#include <stdlib.h>
char labirinto[12][13];
int comecoL;
int colunaC;
int Linhafim;
int colunafim;

void lerLabirinto(){//ler o labirinto
	printf("#### SEJA BEM VINDO AO LABIRINTO ####\n\n");
	FILE* f;
	f = fopen("lab.txt","r");


	for(int i = 0; i <12; ++i){
		fscanf(f, "%s",labirinto[i]);
	}

	fclose(f);

}

void aparecerLabirinto(){//aparecer o labirinto;
	for(int i = 0; i < 12; ++i){
		printf("%s\n", labirinto[i]);
	}

}

void acharInicio(){//vai achar o Inicio;
	for(int i = 0; i < 12; ++i){
		if(labirinto[i][0] == '.'){
			comecoL = i;
			colunaC = 0;
			labirinto[i][0] = 'X';


		}

	}
	
}

void acharFim(){//Está função vai achar o fim;
    for(int i=0; i<12; ++i){
    	if(labirinto[i][11]== '.'){
    		Linhafim = i;
    		colunafim = 11;
    	}

    }
}

int finaldolabirinto(){//Está função é para comparar o começo com e fim e retornar 1 se verdadeiro e 0 para falso;
	if(Linhafim == comecoL && colunaC == colunafim){

		return 1;

	}
	return 0;
}

void travessiaDeLabirinto(){//Está função é pra a travessia do labirinto 
	if(labirinto[comecoL][colunaC+1]=='.'){
		labirinto[comecoL][colunaC+1]='X';
	 	colunaC++;
	}
	else if(labirinto[comecoL-1][colunaC]=='.'){
		labirinto[comecoL-1][colunaC]= 'X';
		comecoL--;
	}
	else if(labirinto[comecoL][colunaC-1]=='.'){
		labirinto[comecoL][colunaC-1]='X';
		colunaC--;
	}
	else if(labirinto[comecoL+1][colunaC]=='.'){
		labirinto[comecoL+1][colunaC]='X';
	 	comecoL++;
	}
}


int  main(){
	
	lerLabirinto();
	acharInicio();
	acharFim();
	while(!finaldolabirinto()){
		aparecerLabirinto();
		travessiaDeLabirinto();
		
		system("pause");
		system("cls");
	}
  }
