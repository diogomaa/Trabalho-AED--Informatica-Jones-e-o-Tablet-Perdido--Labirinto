
/*ECGM 
Frederico Correia-17464
César Lage-17460

*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

 
/*Cria o mapa de jogo do computador mas vazio*/
void mapaJogo2(int board2[][20], int board[][20]){
    int i, j;
     
    for(i=0; i<20; i++){
        printf("\n");
        for(j=0; j<20; j++){
            board2 [i][j]=0;
        }
    }
    for(i=0; i<20; i++){
        printf("\n");
        for(j=0; j<20; j++){
            board [i][j]=0;
        }
    }
}
//Cria as posições dos barcos
// Submarino
void submarino(int board2[][20]){
    int i;
    int x, y;
    time_t t;
                
    //Inicia o gerador de numeros
    srand((unsigned) time(&t));
    for (i=0;i<4;i++){
        x = (rand()%19)+1;
        y = (rand()%19)+1;
        if (board2[x][y] != 1){ 
            board2[x][y] = 1;
        }else{
            x = (rand()%19)+1;// +1 pois se acontecer de ter o rand() igual a 0, como nos nao temos a posição 0 pomos a ser 1
            y = (rand()%19)+1;
            board2[x][y] = 1;
        }
    }
}

//Cruzadores
void cruzadores(int board2[][20]){
    int i;
    int x, y, p;
    time_t t;
                
    //Inicia o gerador de numeros
    srand((unsigned) time(&t));
    
    p = rand()%1; 
    
    for (i=0;i<3;i++){
        x = (rand()%18)+1;
        y = (rand()%18)+1;
        if (board2[x][y] != 2){ 
            if(p==1){
                board2[x][y] = 2;
                board2[x][y+1] = 2;
            }else{
                board2[x][y] = 2;
                board2[x+1][y] = 2;
            }
        }else{
            x = (rand()%18)+1;// +1 pois se acontecer de ter o rand() igual a 0, como nos nao temos a posição 0 pomos a ser 1
            y = (rand()%18)+1;
            if(p==1){
                board2[x][y] = 2;
                board2[x][y+1] = 2;
            }else{
                board2[x][y] = 2;
                board2[x+1][y] = 2;
            }
        }
    }
}
//Contratorpedeiros
void contratorpedeiros(int board2[][20]){
    int i;
    int x, y, p;
    time_t t;
                
    //Inicia o gerador de numeros
    srand((unsigned) time(&t));
    p = rand()%1;
    for (i=0;i<3;i++){
        x = (rand()%17)+1;
        y = (rand()%17)+1;
        if (board2[x][y] != 3){    
            if(p==1){
                board2[x][y] = 3;
                board2[x][y+1] = 3;
                board2[x][y+2] = 3;
            }else{
                board2[x][y] = 3;
                board2[x+1][y] = 3;
                board2[x+2][y] = 3;
            }
        }else{
            x = (rand()%17)+1;// +1 pois se acontecer de ter o rand() igual a 0, como nos nao temos a posição 0 pomos a ser 1
            y = (rand()%17)+1;    
            if(p==1){
                board2[x][y] = 3;
                board2[x][y+1] = 3;
                board2[x][y+2] = 3;
            }else{
                board2[x][y] = 3;
                board2[x+1][y] = 3;
                board2[x+2][y] = 3;
            }
        }
    }
}
//Porta-aviões
void portaAvioes(int board2[][20]){
    int i;
    int x, y, p;
    time_t t;
                
    //Inicia o gerador de numeros
    srand((unsigned) time(&t));
    
    x = (rand()%16)+1;// +1 pois se acontecer de ter o rand() igual a 0, como nos nao temos a posição 0 pomos a ser 1
    y = (rand()%16)+1;
    
    p = rand()%3;
    for (i=0;i<2;i++){
        if (board2[x][y] != 3){
            if(p==0){
                board2[x][y] = 4;
                board2[x][y+1] = 4;
                board2[x+1][y+1] = 4;
                board2[x][y+2] = 4;
            }else if (p==1){
                board2[x][y] = 4;
                board2[x+1][y] = 4;
                board2[x+1][y+1] = 4;
                board2[x+2][y] = 4;
            }else if (p==2){
                board2[x][y] = 4;
                board2[x+1][y] = 4;
                board2[x+1][y-1] = 4;
                board2[x+2][y] = 4;
            }else if (p==3){
                board2[x][y] = 4;
                board2[x][y+1] = 4;
                board2[x-1][y+1] = 4;
                board2[x][y+2] = 4;
            }
        }else{
            x = (rand()%17)+1;// +1 pois se acontecer de ter o rand() igual a 0, como nos nao temos a posição 0 pomos a ser 1
            y = (rand()%17)+1;
            if(p==0){
                board2[x][y] = 4;
                board2[x][y+1] = 4;
                board2[x+1][y+1] = 4;
                board2[x][y+2] = 4;
            }else if (p==1){
                board2[x][y] = 4;
                board2[x+1][y] = 4;
                board2[x+1][y+1] = 4;
                board2[x+2][y] = 4;
            }else if (p==2){
                board2[x][y] = 4;
                board2[x+1][y] = 4;
                board2[x+1][y-1] = 4;
                board2[x+2][y] = 4;
            }else if (p==3){
                board2[x][y] = 4;
                board2[x][y+1] = 4;
                board2[x-1][y+1] = 4;
                board2[x][y+2] = 4;
            }
        }
    }
}
/*Cria o mapa grafico do jogo*/
void mapaJogo(int board[][20], int board2[][20])
{
    int i, j;
     
    printf("       1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20 ");

	
	for(i=0; i<20; i++)
    {
        printf("\n  %d ", i+1);
        for(j=0; j<20; j++)
        { 
            if(board[i][j]==0){
                printf("  |O|");
            }
            else if(board[i][j]==1)
            {
                printf("  |S|");
            }else if(board[i][j]==2)
            {
                
                printf("  |C|");
            }else if(board[i][j]==3)
            {
                printf("  |T|");
            }else if(board[i][j]==4)
            {
                printf("  |P|");
            }else if(board[i][j]==5){//se nao acertar
                printf("  |X|");
            }
        }
        
        printf("\n");
    }
}
 
 
 
 
/*funcao para cada tiro que se da. se acerta ou nao e faz a pontuacao jogada a jogada*/
void tiroDado(int board[20][20],int board2[20][20],int *pts,int *jogada){
    int x,y;
    char xletra;
    printf("\nInsira coordenada linha \n");
    scanf("%i",&x);
    printf("Insira coordenada coluna \n");
    scanf("%i",&y);
    x-=1;//coloca os valores compativeis com as coordenadas do array
    y-=1;



    if(board2[x][y]==1){
        printf("\nAcertou num Submarino! \n");
        *pts=*pts+1;
        board[x][y]=1;//marca o acerto no mapa;
    }else if(board2[x][y]==2){
        printf("\nAcertou num Cruzador! \n");
        *pts=*pts+1;
        board[x][y]=2;
    }else if(board2[x][y]==3){
        printf("\nAcertou num Contratorpedeiro! \n");
        *pts=*pts+1;
        board[x][y]=3;
    }else if(board2[x][y]==4){
        printf("\nAcertou num Porta-Avioes! \n");
        *pts=*pts+1;
        board[x][y]=4;
    }else if(board2[x][y]==0){//se falhar marca um X no mapa
    	board[x][y]=5;
        printf("\nFalhou tenta outra vez\n");
    }
    *jogada=*jogada-1;
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("A sua pontuacao e: %d \n",*pts);
    printf("Tem %d jogadas \n",*jogada);
     
}
     
void menu(){
    printf("  ______________________________________ \n");
    printf(" |            BATALHA NAVAL             |\n");
    printf(" |           1 - Jogar                  |\n");
    printf(" |           2 - Como jogar             |\n");
    printf(" |           3 - Sair                   |\n");
    printf(" |--------------------------------------|\n");
    printf(" |   Criado por:                        |\n");
    printf(" |      Frederico Correia               |\n");    
    printf(" |      Cesar Lage                      |\n");    
    printf(" |______________________________________|\n\n");

}
 
 
int main() {
    int escolha, pts, jogada, i, j, saida;
    int op;
    int board2[20][20];
    int board[20][20];
    int *appts,*apjogada;
    appts=&pts;
    apjogada=&jogada;
    jogada=50;
    pts=0;
    saida = 0;
    
    for(i=0;i<19;i++){
        for(j=0;j<19;j++){
            board[i][j]= 0;
        }
    }
    do{
        // Aparece o menu
        menu();
        scanf("%i", &escolha);
        system("cls");
        
        switch(escolha){
            case 1:
                do{
                    mapaJogo2(board2,board);
                    
                    //Submarino
                        submarino(board2);
                    //Cruzadores
                        cruzadores(board2);
                    //Contratorpedeiros
                        contratorpedeiros(board2);
                    //Porta-aviões
                        portaAvioes(board2);
                    
                    for (i=0;i<50;i++){
                        mapaJogo(board,board2);
                        tiroDado(board,board2,appts,apjogada);
                    }
                    
                }while(jogada!=0 || pts != 40);
                printf("A sua pontuacao final e de: %i \n\n", pts);
                printf("Voltar atras?? sim-1    nao-2\n");
                scanf("%i", &op);
                if(op == 1){
                    system("cls");
                    break;// regressa ao passo anterior/para o switch
                }
                break;
            case 2:
                printf("\n                        O Objectivo do jogo e tentar afundar todos os barcos militares.\n\n");
                printf(" Existem 4 tipos de barcos militares, num total de 20 ( 8 submarinos, 2 porta-avioess, 4 contratorpedeiros e 6 cruzadores)\n\n");
                printf("                              Apenas tem que colocar as coordenadas do seu tiro!\n\n");
                printf("                             Tem 50 tentativas para completar os seus objectivos\n\n");
                printf("                                            Voltar a tras??\n\n");
                printf("                                                  1-Sim\n");
                printf("                                                  2-Nao\n");
             	scanf("%i", &op);
                if(op == 1){
                    system("cls");
                    break;// regressa ao passo anterior/para o switch
                }
            case 3:
                printf("Obrigado por jogar :D");
                saida = 1;
            default:
                break;
        }
    }while(saida != 1);
}

