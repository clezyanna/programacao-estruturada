#include <stdio.h>

int main(){
	
	char nome[20];

	scanf("%5[A-Z ^\n]", nome);

	printf("%s", nome);
}