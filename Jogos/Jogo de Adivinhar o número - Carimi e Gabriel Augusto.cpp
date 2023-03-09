#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
main() 
{ 
setlocale (LC_ALL,"Portuguese");
	int num_ale, num_dig, qtd_dig=1, vet[100], i, num_pc, inicio, meio, fim, achou, qtd_pc=1, user_resp;
	// Gerar n�mero aleat�rio
	srand (time(NULL));
	num_ale = rand() % 100;
	if (num_ale == 0)
		num_ale = 1;
	// Iniciar o Jogo
	printf("-------------------------------------------------------------------\n");
	printf("JOGO DO ADIVINHA\n");
	printf("-------------------------------------------------------------------\n");
	printf("Tente adivinhar o n�mero entre 1 e 100:");
	scanf("%d", &num_dig);
	//Comparar os n�meros
	while (num_ale != num_dig)
		{
		if(num_dig > num_ale)
			printf("\nO n�mero � menor! Tente novamente.\n");
		else if (num_dig < num_ale)
	    	printf("\nO n�mero � maior! Tente novamente.\n");
		printf("\nDigite novamente um n�mero: ");
		scanf("%d", &num_dig);
		qtd_dig++;
		}
  	printf("\nISSO! Voc� acertou o n�mero aleat�rio %d com %d jogada(s)!\n", num_ale, qtd_dig);
  	//Limpar tela
	printf("\n\nAgora ~EU~ adivinho!");
	printf("\n\Pense em um n�mero de 1 a 100 e pressione uma tecla para eu adivinhar!");
	getch();
	system("cls");
	// PC adivinhar
	printf("\nMe d� uma dica sobre n�mero pensado:");
	printf("\nDigite 1 se Igual\n");
	printf("Digite 2 se Menor\n");
	printf("Digite 3 se Maior\n\n");
	// Gerar vetor de 100 posi��es
	for (i=0;i<100;i++)
		vet[i] = i+1;
	//Busca Bin�ria
	achou = 0;
	inicio = 1;
	fim = 100;
	meio = (inicio+fim)/2;
	while ((!achou) && (inicio<=fim))
 	{
	printf("Ei, voc� pensou no n�mero %d?\n",meio);
 	printf("Resposta: ");
 	scanf("%d",&user_resp);
 	if (user_resp==1) {
 		achou=1;
 		printf("\nAcertei o n�mero pensado com %d jogada(s)!\n", qtd_pc);
 		}
		else if (user_resp==2){
 		fim=meio-1;
 		meio=(fim+inicio)/2;
 		qtd_pc++;
 		}
 		else if (user_resp==3){
 		inicio=meio+1;
 		meio=(inicio+fim)/2;
 		qtd_pc++;
 		}
 	}
 	//Limpar
	printf ("\n\nPRESSIONE UMA TECLA PARA VERIFICAR O PLACAR!");
	getch();
	system("cls");
	// Placar
	printf("\n ______________________________");
	printf("\n| JOGADOR: | VOC� | COMPUTADOR |");
	printf("\n| JOGADAS: |  %d   |       %d    |", qtd_dig, qtd_pc);
	printf("\n ______________________________");
	if (qtd_dig > qtd_pc) printf("\n\nSOU O CAMPE�O! UHUU!");
		else if (qtd_dig < qtd_pc) {
		printf("\n\nVOC� � O CAMPE�O! PARAB�NS!\n");
		}
	else printf("\n\nEMPATAMOS!\n");
}	
