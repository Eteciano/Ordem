#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
main()
{
	char nome[255]="abelha a";										//Variavel p ler a entrada (coloquei qlq coisa pq o programa tava me enchendo o saco...
	int N;															//Var N padrão p saber quantas linhas
	static const char v[] = "0123456789";							//String p fazer uma verificação la em baixo
	scanf("%d", &N);												//Le N
	int ordem[N];													//Lista de numeros de tamanho N
	int verif = 1;													//Variavel de controle do loop do while la em baixo
	char num[50];													//string p obter o valor do numero(ainda em caractere)
	int ordenar[N];													//Lista de numeros para ordenar a chama de nomes pq eu n consegui fazer buble sort com string kk
	int achou = 0;													//Variavel de controle p ver se achou o numero na string nome(na separação do while)
	int b;															//Variavel auxiliar para escrever na variavel num(MANO STRING É MUITO CHATO Q ISSO QUANTA FRESCURA)
	int ni;															//De novo o negocio de cima, serve p saber até onde vai o nome
	char nomef[N][255];												//Lista de nomes
	int aux, aux2;													//Variaveis auxiliares para -aux=> bubble sort; aux2=> falar que ja achou o numero e parar de incrementar a variavel ni
	aux2=0;															//inicia ela
	for(int g = 0; g<N;g++)											//for pra ler N nomes
	{
		scanf(" %[^\n]s", &nome);									//scanf forçado até \n(enter) pra ler tudo, pq NÃO TEM COMO SABER QUANTOS NOMES O CARA TEM MANO
		while(verif)												//Loop pra achar ate onde vai o final do nome da pessoa e separar o numero
		{
			for(int cont = 0;cont<strlen(nome);cont++)				//for do tamanho da string nome(com o numero da chamada)
			{
				for(int i = 0;i<10;i++)								//for do tamanho da variavel v pra verificar se o caracter verificado é um numero
				{
					if(nome[cont]==v[i])							//se o caracter verificado for um numero
					{
						if(aux2==0)									//se nenhum caractere anterior foi um numero
						{
							ni=cont-1;								//var ni recebe cont-1 pra saber o tamanho do nome(-1 pq ta no numero, era p colocar -2 por causa do espaço mas por algum motivo aleatorio buga... string ne)
							aux2=1;									//fala q ja foi achado um numero
						}

						char a[] = {v[i]};							//quem criou essa sintaxe tinha ***** na cabeça, coloca o valor de v[i], ou seja, o numero que achou na variavel a
						if(achou)									//se o primeiro numero ja tiver sido achado
						{
							num[b]=a[0];							//a variavel num escreve a variavel a na posicao b, eu queria muito pular a linha 38  MAS É COM STRING Q ESTOU TRABALHANDO KKK OQ EU QUERO É O QUE MENOS IMPORTA AQUI
							b++;									//incrementa b
						}	
						
						else										//se não sabe oq é se mata :)
						{
							achou = 1;								//fala que o primeiro numero foi achado
							num[0] = a[0];							//o primeiro termo de num recebe a
							b =1;									//b é iniciado em 1, pq o 0 ja foi escrito
						}
					}
				}
			}
			verif =0;												//depois q separou tudo, fecha o loop, sla se pa esse loop é totalmente inutil kkk mas eu comecei usando essa logica e deu mo preguiça de mudar
		}
		for(int l =0; l<ni;l++)										//for p colocar o nome numa variavel só com o nome(ni é o ultimo caractere antes do numero)
		{
			nomef[g][l]=nome[l];									//coloca o nome numa matriz pq assim eu posso chamar o nome q eu quiser, sim a matriz é invertida...pq? PQ STRING NÃO FAZ SENTIDO
		}
		ordem[g]=atoi(num);											//pega a varivel q eu isolei o numero, transforma ela em inteiro e coloca ela numa lista
		ordenar[g]=ordem[g];										//copia a lista, mas essa é p eu chamar os nomes pq eu n consegui fazer o bubble sort com string
		achou = 0;													//reseta as variaveis
		b=1;
		verif=1;
		aux2=0;
		for(int c = 0; c<50; c++)									//ja falei man, ta resetando a variavel
			num[c]='\0';
	}
	for(int l = 0; l<N-1; l++)										//BUBBLE SORT
	{
		for (int k = 1; k<N; k++)
		{
			if(ordem[l]>ordem[k])
			{
				aux = ordem[l];
				ordem[l]=ordem[k];
				ordem[k]=aux;
			}
		}
	}
	for(int l = 0; l<N; l++)										//printa os nomes na ordem crescente de chamada
	{
		printf("%d ", ordem[l]);
		for(int p = 0; p<N;p++)
		{
			if(ordenar[p]==ordem[l])
				printf("%s\n", nomef[p]);
		}
	}
	
}
