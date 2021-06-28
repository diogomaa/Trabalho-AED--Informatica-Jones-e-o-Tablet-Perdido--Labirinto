#include <stdio.h>
#include <stdlib.h>

// 1-Parede; 0-caminho; 2-veneno; 3-energia; 4-portal; 5-coordenador; 6-end

int map[18][18] = {  
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,1,1,1,1,0,0,0,0,3,0,0,0,0,1,
		1,6,1,0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,
		1,1,1,1,1,3,0,0,0,1,1,1,1,1,1,1,0,1,
		1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,
		1,3,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,
		1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,
		1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,0,3,1,1,1,1,1,0,1,
		1,2,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,1,
		1,0,1,1,1,1,0,3,1,1,1,1,1,1,1,1,0,1,
		1,0,1,1,1,1,0,0,0,1,1,1,1,1,1,1,2,1,
		1,0,1,1,1,1,1,1,0,1,0,0,0,0,0,1,0,1,
		1,0,1,1,0,0,1,1,0,1,0,1,0,1,0,1,0,1,
		1,0,0,0,0,4,1,1,0,1,0,1,4,1,0,1,0,1,
		1,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,1,
		1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	}; 
		int utX=1;
		int utY=17;
		int energia=100;
		
	void objeto(){
						if(map[utY][utX]==2){
				printf("\n	Foste contaminado\n");
				energia=energia-20;
				printf("\n                                                                           Energia atual: %i\n", energia);
			}
					else	if(map[utY][utX]==3){
				printf("\n	Barra energetica!\n");
				if(energia<=80){
				energia=energia+20;}
				else{
					printf("\n	Nao teve efeito..");
				}
				printf("\n                                                                           Energia atual: %i\n", energia);
			}
					else	if(map[utY][utX]==4){
				printf("\n	Um portal!\n");
				utY=14;
				utX=14;
				printf("\nEle levou-te para uma nova posicao ");
				printf("\n>\n>\n>\n>\n>");
				printf("\nEncontras-te o tablet!\nParabens! Acabaste o jogo!\n");
				printf("\nMaria: Obrigada! Encontraste o meu tablet!");
				exit(0);
			}
					else	if(map[utY][utX]==5){
				printf("\nEncontras-te o Coordenador de curso!\n");
				utY=14;
				utX=14;
				printf("\nEle levou-te para uma nova posicao ");
				printf("\n>\n>\n>\n>\n>");
				printf("\nEncontras-te o tablet!\nParabens! Acabaste o jogo!\n");
				printf("\nMaria: Obrigada! Encontraste o meu tablet!");
				exit(0);
			}
					else	if(map[utY][utX]==6){
				printf("\nEncontras-te o tablet!\nParabens! Acabaste o jogo!\n");
				printf("\nMaria: Obrigada! Encontraste o meu tablet!");
				exit(0);
			}
			else{
				printf("\n	Nao tinha nada por perto..\n");
			}
			
		}

void verMovBaixo(int o){
	int i, parede;
	i=0;
	parede=0;
	for(i=1; i<=o; i++){
		if(map[utY+i][utX] ==1){
			
			
			printf("\n	Impossivel\n");
			parede=1;
		}
	}
	if(parede==0)	{
			utY=utY+o;
				printf("\n	Qual a direcao que escolhes? \n c- cima; \n e- esquerda; \n b- baixo; \n d- direita;\n");
	}
}

void verMovCima(int o){
	int i, parede;
	i=0;
	parede=0;
	        while(utY-o<utY-i){
                 i++;
                         if(map[utY-i][utX]==1){
                             parede=1;
                         }
             }
	if(parede==0){
		utY=utY-o;
			printf("\n	Posicao nova: [%i][%i]", utX, utY);
			printf("\n	Qual a direcao que escolhes? \n c- cima; \n e- esquerda; \n b- baixo; \n d- direita;\n");
	}
	else{
		printf("\n	Impossivel\n");
	}
		
}

void verMovDireita(int o){
	int i,parede;
	i=0;
	parede=0;
			while(utX+o>utX+i){
                 i++;
                         if(map[utY][utX+i]==1){
                             parede=1;
                         }
             }
	if(parede==0){
		utX=utX+o;
		printf("\n	Posicao nova: [%i][%i]", utX, utY);
		printf("\n	Qual a direcao que escolhes? \n c- cima; \n e- esquerda; \n b- baixo; \n d- direita;\n");
	}
	else{
		printf("\n	Impossivel\n");
	}	
}

void verMovEsquerda(int o){
	int i,parede;
	i=0;
	parede=0;
 			while(utX-o<utX-i){
                 i++;
                         if(map[utY][utX-i]==1){
                             parede=1;
                         }
             }
	if(parede==0){
		utX=utX-o;
		printf("\n	Posicao nova: [%i][%i]", utX, utY);
	printf("\n		Qual a direcao que escolhes? \n c- cima; \n e- esquerda; \n b- baixo; \n d- direita;\n");
	}
	else{
		printf("\n	Impossivel\n");
	}	
}
int main (){
int contajogadas=0;
int x, y, o, d;

char op;
for(x=0; x<16; x++){
	for(y=0; y<16; y++){
		map[x][y];
	}
}

	printf("\n\n	Maria: 'Perdi o meu tablet e precisava imenso que me ajudasses a encontra-lo!\n");
	printf("\n			Informatica Jones:Estas pronto para entrar nesta aventura?\n");
	printf("\n					Vamos comecar!\n");
	printf("\n		Posicao atual: [%i][%i]", utX, utY);
	printf("\n\n	Qual a direcao que escolhes? \n c- cima; \n e- esquerda; \n b- baixo; \n d- direita;\n");	
do{ 
	if(contajogadas==6){
		energia=energia-20;
		printf("\n	Retirei-te energia... \n");
		printf("\n                                                                           Energia atual: %i\n", energia);
		contajogadas=0;
	}
	if(energia<=0){
		printf("\n	Ficaste sem energia...");
		exit(0);
	}
	scanf("\n%c", &op);
//if(opcion=='c' || opcion=='e' || op=='b' || op=='d'){
switch(op){
	
	case 'c':
		if(energia<=100){
		contajogadas++;	
		}
		printf("\n	Quantas casas queres mover para cima?                                          Energia atual: %i\n", energia);
		scanf("%i", &o);
		verMovCima(o);
		break;
	case 'e':
		if(energia<=100){
		contajogadas++;	
		}
		printf("\n	Quantas casas queres mover para a esquerda?                                     Energia atual: %i\n", energia);	
		scanf("%i", &o);
		verMovEsquerda(o);
		break;
	case 'b':
		if(energia<=100){
		contajogadas++;	
		}
		printf("\nQuantas casas queres mover baixo?\n                                               Energia atual: %i\n", energia);
		scanf("%i", &o);
		verMovBaixo(o);
		break;
	case 'd':
		if(energia<=100){
		contajogadas++;	
		}
		printf("\n	Quantas queres mover para a direita?                                            Energia atual: %i\n", energia);
		scanf("%i", &o);
		verMovDireita(o);
		break;
	case 'o':
		printf("\n	A procura de um objeto..\n");	
			printf("\n                                                                            Energia atual: %i\n", energia);
		objeto();
		break;
}

/*else if(op=='s' || op=='S'){
	exit(0);
}*/
}while(op!='s' && op!='S');

}





