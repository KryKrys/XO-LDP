#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define BACKSPACE 8
#define ESPACE 255
#define ESC 27
#define S 115
#define N 110
#define O 111
#define X 120

int xo[3][3]={
    0,0,0,
    0,0,0
    ,0,0,0
};
char marca1,marca2,rep;

int comprueba(void);
void mostrar(void);
void jugador1(void);
void jugador2(void);

void main(){
    
    int i,j;
    
    clrscr();
    
    printf("Elija que llevara el jugador 1:   x       o \n");
        do
            marca1=getch();
        while(tolower(marca1)!=X && tolower(marca1)!=O);

        if (marca1==X) {
            marca2=O;
        }else{
            marca2=X;
        }

    do{
        
        for (j=0;j<3;j++){
            for(i=0;i<3;i++){
                xo[i][j]=0;
            }
        }

        do{
            clrscr();
            mostrar();

            printf("\nJugador 1: %c\n",marca1);
            printf("Jugador 2: %c",marca2);

			jugador1();
			mostrar();
            getch();
			jugador2();

			mostrar();
            getch();

        }while(comprueba()!=0);

        getch();
        clrscr();
		gotoxy(25,10);
		textcolor(MAGENTA);
		cprintf("%cQUIERES PROBARLO DE NUEVO? ;)",168);
		gotoxy(30,12);
		textcolor(WHITE);
		cprintf("[S]I  /  [N]O");

        do{
           	rep=getch();
        }while(tolower(rep)!=N && tolower(rep)!=S);

    }while(tolower(rep)!=N);
}

void jugador1(){ /*marca 1*/
	int posx,posy,repetir=0;
	clrscr();
            /*x=1 o=2*/
		while(repetir==0){
			printf("\nPosicion donde marcar jugador 1: ");
            printf("COLUMNA: ");
            scanf("%d",&posx);
            printf("FILA: ");
            scanf("%d",&posy);
            if (marca1==X && xo[posx][posy]==0){
                xo[posx][posy]=1;
				repetir=1;
            }else if (marca1==O && xo[posx][posy]==0){
                xo[posx][posy]=2;
				repetir=1;
            }else{
                printf("Esa coordenada ya esta ocupada");
				repetir=0;
            }
		}
}

void jugador2(){
	int posx,posy,repetir=0;
	
	while(repetir==0){
		clrscr();
		printf("\nPosicion donde marcar jugdor 2: ");
    	printf("COLUMNA: ");
    	scanf("%d",&posx);
    	printf("FILA: ");
   		scanf("%d",&posy);
           /*x=1 o=2*/
		if (marca2==X && xo[posx][posy]==0){
			xo[posx][posy]=1;
			repetir=1;
		}else if (marca2==O && xo[posx][posy]==0){
			xo[posx][posy]=2;
			repetir=1;
		}else{
			printf("Esa coordenada ya esta ocupada");
			repetir=0;
		}
	}
}

int comprueba(){
	int i, j, x,win=0;
	int lose=0;

	/*Recorre horizontales en busca de semejantes*/
    for(x=0;x<3;x++){
		for(i=0;i<3;i++){
			if(xo[x][i]==1){
				win+=1;
				if (win==3) {
					printf("\n\tGanaste c:\n");
					i=3;
					x=3;
                    return 0;
				}
				continue;
			}else if (xo[x][i]==2){
				lose+=1;
				if(lose==3){
					
						printf("\n\tGana el jugador 2 c:\n");
						i=3;
						x=3;
                   	 return 0;
				}
			}
		}
	}
	lose=0;		
	win=0;

    /*Recorre verticales en busca de semejantes*/
	for(x=0;x<3;x++){
		for(i=0;i<3;i++){
			if(xo[i][x]==1){
				win+=1;
				if (win==3) {
					printf("\n\tGanaste c:\n");
					i=3;
					x=3;
					break;
                    return 0;
				}
				continue;
				
			}else if (xo[x][i]==2){
				lose+=1;
				if(lose==3){
						printf("\n\tGanaste c:\n");
						i=3;
						x=3;
					 break;
                   	 return 0;
				}
				
			}
		}
	}	
	lose=0;
	win=0;

    /*Recorre diagonal principal en busca de semejantes*/
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(j==i){
				if(xo[j][i]==1){
					
					win+=1;
					if (win==3) {
						printf("\n\tGanaste c:\n");
						i=3;
						x=3;
						break;
                        return 0;
					}
					continue;
				}else if(xo[j][i]==2){
					lose+=1;
					if(lose==3){
						printf("\n\tGanaste c:\n");
						i=3;
						x=3;
					 break;
                   	 return 0;
					}
				}
			}
		}
	}
	lose=0;
	win=0;

    /*Recorre diagonal secundaria en busca de semejantes*/
	for(i=0;i<3;i++){
		if (xo[i][(3-1)-i]==1){
			win+=1;
			if (win==3) {
				printf("\n\tGanaste c:\n");
				i=3;
				x=3;
				break;
                return 0;
			}
			continue;
		}else if (xo[i][(3-1)-i]==2){
			lose+=1;
			if(lose==3){
				printf("\n\tGanaste c:\n");
				i=3;
				x=3;
				break;
                return 0;
			}
		}
	}

    return 1;
}

void mostrar(){
    int i,j;
    for (j=0;j<3;j++){
        for(i=0;i<3;i++){
            printf("%d ",xo[i][j]);
        }
        printf("\n");
    }
}