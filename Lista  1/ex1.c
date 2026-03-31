#include <stdio.h>

int i;
float n[3] = {0, 0, 0}, med = 0;

int main() {
	
	for(i=0;i<3;i++) {
		printf("Digite a %i* nota: ", i+1);
		scanf("%f", &n[i]);
		med+=n[i];
	}
	
	med = med / 3;
	printf("Media: %.2f \n", med);
	
	if(med >= 7) {
		printf("Situacao: APROVADO!");
	} else if(med < 7 && med >= 5)  {
		printf("Situacao: RECUPERACAO!");
	} else if(med < 5) {
		printf("Situacao: REPROVADO!");
	}
	
	return 0;
}
