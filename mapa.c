/*
José é o proprietário de um açougue em sua cidade, 
o estabelecimento possui um grande fluxo de pessoas.
José não está conseguindo controlar a fila de clientes
que está se formando para o atendimento, muitos dos 
clientes estão reclamando que não está sendo respeitado a
ordem de chegada para serem atendidos. Sendo assim José 
solicitou a você um software que resolva o problema.

Depois de uma análise foi definido que o software deverá 
ter duas funcionalidades:
- Retirar uma senha para o atendimento.
- Chamada da próxima senha no painel para atendimento.

Com base nestas informações, você deverá desenvolver
um programa em linguagem C que atenda as funcionalidades: 
- Retirada de nova senha pelo cliente.
- Atendente chamar o próximo número da fila.
- Sair

Funcionalidade e restrições do programa:
- A cada nova iteração deve-se apresentar na tela a composição da fila.
- Ao ser chamado um número para atendimento, 
no painel deve-se apresentar a senha anterior, atual e a próxima.
- A funcionalidade Sair, só poderá ser 
executada se a todas as senhas de atendimento já foram chamadas.
- A fila deve ter no máximo 10 pessoas,
caso a fila esteja completa apresentar uma mensagem que
“A fila já está completa, tente novamente mais tarde.”

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//////////////////////////////////////////////////////////////////////
//                      constants                                   //
//////////////////////////////////////////////////////////////////////
#define fila_max 10

//////////////////////////////////////////////////////////////////////
//                       structs                                    //
//////////////////////////////////////////////////////////////////////
struct queue {
	int data[fila_max];
	int first_position;
	int last_position;
};

//////////////////////////////////////////////////////////////////////
//                       globals                                    //
//////////////////////////////////////////////////////////////////////
struct queue fila;
int atendimento = 0;
int senha = 0;

//////////////////////////////////////////////////////////////////////
//                      prototypes                                 //
//////////////////////////////////////////////////////////////////////
void view_queue();
void queue_in(int senha);
void queue_out();
void menu();
void bye();
void retira_senha();
void logo();
void pause();
void painel();
int exit_program();
int validar();

//////////////////////////////////////////////////////////////////////
//                         MAIN                                     //
//////////////////////////////////////////////////////////////////////
int main(){
	fila.first_position = 0;
	fila.last_position = 0;
	int loop = 1;
	char input;
	int input_int;

	LOOP:
	do {
		menu();
		scanf(" %c", &input);
		input_int = (int) input;

		switch (input_int) {
			case 49: //1
				retira_senha();
				pause();
				break;
			case 50: //2
				view_queue();
				pause();
				break;
			case 51: //3
				queue_out();
				pause();
				break;
			case 52: //4
				loop = exit_program();
				break;
			default:
				printf("Entrada incorreta\n");
				break;
		}

	}while(loop);

	bye();
	return 0;
}


//////////////////////////////////////////////////////////////////////
//                       functions                                  //
//////////////////////////////////////////////////////////////////////

void queue_in(int senha){
	/* Funçao para adicionar elemento na fila. */
	if (fila.last_position == fila_max) {
		printf("Fila cheia, impossível entrar na fila neste momento\n");
		printf("Por favor tente novamente mais tarde\n");
	}
	else {
		fila.data[fila.last_position] = senha;
		fila.last_position++;
	}
}

void queue_out(){
	/* Função para remover elemento da fila */
	if (fila.first_position == fila.last_position) {
		printf("--------------------------------------\n");
		printf("Fila vazia\n");
		printf("--------------------------------------\n");
	}
	else {
		for (int i=0; i<fila_max; i++) {
			fila.data[i] = fila.data[i+1];
		}
		fila.data[fila.last_position] = 0;
		fila.last_position--;
		atendimento++;
		painel();
	}
}

void view_queue() {
	/* Função para visualizar a fila */
	printf("--------------------------------------\n");
	painel();
	printf("Fila: ");
	for (int i=0; i<fila_max; i++){
		printf("%d, ", fila.data[i]);
	}
	printf("\n\nAtendimento: %d \n\n", atendimento);
	printf("--------------------------------------\n");
}

void menu(){
	/*Mostra o menu*/
	printf("--------------------------------------\n");
	logo();
	printf("--------------------------------------\n");
	printf("Ultimo atendimento: %d\n", atendimento);
	printf("");
	printf("[1] Retirar Senha\n");
	printf("[2] Ver fila\n");
	printf("[3] Atendimento\n");
	printf("[4] Sair\n");
	printf("--------------------------------------\n\n");
}

void bye(){
	/* Mensagem de até logo ao sair */
	printf("--------------------------------------\n");
	printf("╔══╦╗            \n");
	printf("║╔╗║╚╦═╗╔╗╔═╦═╦═╗ \n");
	printf("║╠╣║╔╣╩╣║╚╣╬║╬║╬║ \n");
	printf("╚╝╚╩═╩═╝╚═╩═╬╗╠═╝ \n");
	printf("────────────╚═╝  \n");
	printf("--------------------------------------\n");
}

void retira_senha(){
	/* Retirar senha e entrar na fila*/
	int sua_senha;
	if (validar() == 1) {
		sua_senha = senha + 1;
		printf("--------------------------------------\n");
		printf("┏━┓╋╋╋╋┏┓\n");
		printf("┃━╋━┳━┳┫┗┳━┓\n");
		printf("┣━┃┻┫┃┃┃┃┃╋┗┓\n");
		printf("┗━┻━┻┻━┻┻┻━━┛\n");

		printf("--------------------------------------\n");
		printf("Sua senha: %d\n", sua_senha);
		printf("--------------------------------------\n");
		senha++;
		queue_in(sua_senha);
	} else {
		printf("--------------------------------------\n");
		printf("Fila cheia\nImpossível entrar na fila neste momento\n");
		printf("Por favor tente novamente mais tarde\n");
		printf("--------------------------------------\n");
	}

}

int validar(){
	/* Validação que verifica se a fila esta cheia*/
	if (fila.last_position == fila_max) {
		return -1;
	}
	else {
		return 1;
	}
}

void logo(){
	/* Logotipo do açougue do seu zé */
	printf("╭━━━╮\n");
	printf("┃╭━╮┃\n");
	printf("┃┃╱┃┣━━┳━━┳╮╭┳━━┳╮╭┳━━╮    <`--'\\>______ \n");
	printf("┃╰━╯┃╭━┫╭╮┃┃┃┃╭╮┃┃┃┃┃━┫    /. .  `'     \\ \n");
	printf("┃╭━╮┃╰━┫╰╯┃╰╯┃╰╯┃╰╯┃┃━┫    (`')  ,        @ \n");
	printf("╰╯╱╰┻━━┻━━┻━━┻━╮┣━━┻━━╯     `-._,        / \n");
	printf("╱╱╱╱╱╱╱╱╱╱╱╱╱╭━╯┃              )-)_/--( >  \n");
	printf("╱╱╱╱╱╱╱╱╱╱╱╱╱╰━━╯             ''''  ''''\n");
	printf("╭━━━╮╱╱╱╱╱╱╱╱╭╮\n");
	printf("┃╭━╮┃╱╱╱╱╱╱╱╱┃┃\n");
	printf("┃╰━━┳━━┳╮╭╮╱╱┃┣━━┳━━┳━━╮\n");
	printf("╰━━╮┃┃━┫┃┃┃╭╮┃┃╭╮┃━━┫┃━┫\n");
	printf("┃╰━╯┃┃━┫╰╯┃┃╰╯┃╰╯┣━━┃┃━┫\n");
	printf("╰━━━┻━━┻━━╯╰━━┻━━┻━━┻━━╯\n");
}

void pause(void){
	/* Mcgyver para pausar o sistema 
	O codigo foi implementado em sistema Unix e a função
	system("pause") nao funciona nestes sistemas*/
	printf("++++++++++++++++++++++++++++++++++++++\n");
	printf("+   Pressione enter para continuar   +\n");
	printf("++++++++++++++++++++++++++++++++++++++\n");
	//gambiarra pra pausar o sistema
	getchar();
	getchar();
	//fim gambiarra
}

void painel(){
	/* Exibe o painel possuindo informações de:
	senha anterior
	senha atual
	proxima senha a ser atendida*/

	printf("--------------------------------------\n");
	printf("╱╱╱╱╱╭╮\n");
	printf("╭━┳━╮┣╋━┳┳━┳╮\n");
	printf("┃╋┃╋╰┫┃┃┃┃┻┫╰╮\n");
	printf("┃╭┻━━┻┻┻━┻━┻━╯\n");
	printf("╰╯\n");
	printf("--------------------------------------\n");

	if (atendimento - 1 < 0){
		printf("SENHA ANTERIOR: 0\n");
	}
	else {
		printf("SENHA ANTERIOR: %d\n", atendimento -1);
	}

	printf("SENHA: %d \n", atendimento);
	printf("PROXIMO ATENDIMENTO: %d\n",  atendimento + 1);
	printf("--------------------------------------\n");
}

int exit_program(){
	/* Realiza uma validação para verificar se ainda há
	pessoas na fila, caso ainda haja clientes para serem
	atendidos o programa nao deve ser encerrado. */
	if (fila.data[fila.first_position] != 0){
		printf("--------------------------------------\n");
		printf("Impossível encerrar sistema\n");
		printf("Ainda há pessoas na fila!\n");
		printf("--------------------------------------\n");
		pause();
		return 1;
	}
	else{
		return 0;
	}
}

/*
REFERENCIAS:
Pig text Art: http://ascii.co.uk/art/pig
*/
