#include<iostream>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <locale.h>
void gotoxy(int x,int y)
{     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1}); }
//Desenhando forca
void forca(int status)
	{if(status==0){
		printf("-----------");
		printf("\n|         |");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n-");
	}else if(status==1){
		printf("-----------");
		printf("\n|         |");
		printf("\n|         0");
		printf("\n|");
		printf("\n|");
		printf("\n|");
		printf("\n-");
	}else if(status==2){
		printf("-----------");
		printf("\n|         |");
		printf("\n|         0");
		printf("\n|         |");
		printf("\n|");
		printf("\n|");
		printf("\n-");	
	}else if(status==3){
		printf("-----------");
		printf("\n|         |");
		printf("\n|         0");
		printf("\n|        -|");
		printf("\n|");
		printf("\n|");
		printf("\n-");	
    }else if(status==4){
		printf("-----------");
		printf("\n|         |");
		printf("\n|         0");
		printf("\n|        -|-");
		printf("\n|");
		printf("\n|");
		printf("\n-");	
	}else if(status==5){
		printf("-----------");
		printf("\n|         |");
		printf("\n|         0");
		printf("\n|        -|-");
		printf("\n|        /");
		printf("\n|");
		printf("\n-");	
	}else if(status==6){
		printf("-----------");
		printf("\n|         |");
		printf("\n|         0");
		printf("\n|        -|-");
		printf("\n|        / \\");
		printf("\n|");
		printf("\n-");	
	}
}
 main(){
 	setlocale (LC_ALL,"Portuguese");
 	fflush(stdin);
 	char palavra_secreta[20];
 	int i;
 	gotoxy(20,3);
 	printf("** JOGO DA FORCA **");
 	printf("\n");
 	gotoxy(20,4);
 	printf("Jogador 1");
 	gotoxy(20,5);
 	printf("Informe a palavra secreta: ");
    gets(palavra_secreta);
    gotoxy(20,6);
    printf("ATEN��O: A palavra tem %lu letras!",strlen(palavra_secreta));
    printf("\n");
    
    //Limpa tela
	system("cls");

	printf("\nJogador 2, adivinhe a palavra!\n\n");
	int erro=0;
	char palavra_tela[20],letra, vet[10];	
	strcpy(palavra_tela,palavra_secreta);
	
	//Troca letras por underlines
	for(int i=0;i<strlen(palavra_tela);i++){
		palavra_tela[i]='_';
	}
	while(1){

	//Imprime a forca
	forca(erro);
	printf("\nPalavra: ");
	
	//Um underline por letra da palavra secreta
	for(i=0;i<strlen(palavra_tela);i++){
		printf("%c ",palavra_tela[i]);
		}

	//Recebe a letra
	printf("\nLetra: ");
	scanf(" %c",&letra);
	system("cls");
	printf("\nJogador 2, adivinhe a palavra!\n\n");
	
	//Verifica se a letra est� correta
	int verifica_erro=1;//1=sim;0=n�o
	for(i=0;i<strlen(palavra_tela);i++){
		if(letra==palavra_secreta[i]){
			palavra_tela[i]=letra;
			verifica_erro=0;
			}
		}
	//Se letra n�o correta, incrementa erro
	if(verifica_erro==1)
		erro++;
	
	//Verifica perda (se jogo acabou)
	if(erro==6){
		//Perdeu
		system("cls");
		printf("-----------");
		printf("\n|         |");
		printf("\n|         0");
		printf("\n|        -|-");
		printf("\n|        / \\");
		printf("\n|");
		printf("\n-");	
		printf("\n\nVoc� perdeu e foi enforcado!!!");
		printf("\nA palavra era: %s.", palavra_secreta);
		break;
	}
	//Verifica vit�ria (palavra secreta = palavra da tela
	system("cls");
	if(strcmp(palavra_tela,palavra_secreta)==0){
		//Vit�ria! Desenha trof�u.
		printf("\t\t       ___________      \n");
		printf("\t\t      '._==_==_=_.'     \n");
		printf("\t\t      .-\\:      /-.    \n");
		printf("\t\t     | (|:.     |) |    \n");
		printf("\t\t      '-|:.     |-'     \n");
		printf("\t\t        \\::.    /      \n");
		printf("\t\t         '::. .'        \n");
		printf("\t\t           ) (          \n");
		printf("\t\t         _.' '._        \n");
		printf("\t\t        '-------'       \n\n");
		printf("Parab�ns, voc� venceu o jogo e est� livre da forca!!!");
		break;
		}
	}
}
