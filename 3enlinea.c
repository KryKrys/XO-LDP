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
#define LONG 20

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
void historial(void);

struct jugador{
	char nombre[20];
	char marca;
}


void main(){
    /*FILE *archivo = fopen("C:/TC20/FICHEROS/registro.txt","a+b");*/
    int i,j,final=0;
	/*Abre archivo de registro*/
	FILE *archivo = fopen("C:\TC20\FICHEROSregistro.txt","a+b");
    
	struct jugador player1;
	struct jugador player2;

	
    clrscr();

	printf("Ingrese un username para player1: %s",)
	
    
    printf("Elija que llevara el jugador 1:   x       o \n");
        do
            player1.marca=getch();
        while(tolower(player1.marca)!=X && tolower(player1.marca)!=O);

        if (player1.marca==X) {
            player2.marca=O;
        }else{
            player2.marca=X;
        }

    do{
        
        for (j=0;j<3;j++){
            for(i=0;i<3;i++){
                xo[i][j]=0;
            }
        }

       	while(final==0){
            clrscr();

			jugador1();
			mostrar();
			if (comprueba()==0){
				final=1;
				freopen("C:/TC20/FICHEROS/registro.txt","a+b",archivo);
				fprintf(archivo,"Ganador:  %c",player1.marca);
				break;
			}
            
			getch();

			jugador2();
			mostrar();
			if (comprueba()==0){
				final=1;
				freopen("C:/TC20/FICHEROS/registro.txt","a+b",archivo);
				fprintf(archivo,"Ganador:  %c",player2.marca);
			}
			getch();
        }

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
	fclose(archivo);
}

void jugador1(){ /*marca 1*/
	int posx,posy,repetir=0;
	clrscr();
            /*x=1 o=2*/
		while(repetir==0){
			clrscr();
			printf("Jugador 1: %c",player1.marca);
			printf("\nPosicion donde marcar jugador 1: ");
            printf("COLUMNA: ");
            scanf("%d",&posx);
            printf("FILA: ");
            scanf("%d",&posy);
            if (player1.marca==X && xo[posx][posy]==0){
                xo[posx][posy]=1;
				repetir=1;
            }else if (player1.marca==O && xo[posx][posy]==0){
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
		printf("Jugador 2: %c",player2.marca);
		printf("\nPosicion donde marcar jugdor 2: ");
    	printf("COLUMNA: ");
    	scanf("%d",&posx);
    	printf("FILA: ");
   		scanf("%d",&posy);
           /*x=1 o=2*/
		if (player2.marca==X && xo[posx][posy]==0){
			xo[posx][posy]=1;
			repetir=1;
		}else if (player2.marca==O && xo[posx][posy]==0){
			xo[posx][posy]=2;
			repetir=1;
		}else{
			printf("Esa coordenada ya esta ocupada");
			repetir=0;
		}
	}
}

int comprueba(){
	int i, j, x;
	int lleno=0;
	int win=0, lose=0;

	
	/*Recorre horizontales en busca de semejantes*/
    for(x=0;x<3;x++){
		for(i=0;i<3;i++){
			if(xo[x][i]==1){
				win++;
				if (win==3) {
<<<<<<< HEAD
					printf("\n\tGana el jugador H 1 c:\n");
=======
					printf("\n\tGanaste X c: H 	\n");
>>>>>>> e909ca81e00cb658596b56a09ab72726952df51e
					i=3;
					x=3;
                    return 0;
					break;
					}else{
						win=0;
						lose=0;
					}
				}
<<<<<<< HEAD
				continue;	
			}else{
				win=0;
				lose=0;
				break;
			}
		}
	}
	lose=0;		
	win=0;
	for(x=0;x<3;x++){
		for(i=0;i<3;i++){
			if(xo[x][i]==2){
				lose+=1;
				if (lose==3) {
					printf("\n\tGana el jugador H 2 c:\n");
					i=3;
					x=3;
                    return 0;
				}
				continue;
			}else{
=======
				}
			}
			for(x=0;x<3;x++){
				for(i=0;i<3;i++){
			if (xo[x][i]==2){
				lose++;
				if(lose==3){
					printf("\n\tGanaste O c: H\n");
					i=3;
					x=3;
                   	return 0;
					break;
				}else{
>>>>>>> e909ca81e00cb658596b56a09ab72726952df51e
				win=0;
				lose=0;
				break;
				}

			}
		}
	}
<<<<<<< HEAD
	lose=0;		
	win=0;
=======
	
	lose=NULL;		
	win=NULL;

>>>>>>> e909ca81e00cb658596b56a09ab72726952df51e
    /*Recorre verticales en busca de semejantes*/
	for(x=0;x<3;x++){
		for(i=0;i<3;i++){
			if(xo[i][x]==1){
				win++;
				if (win==3) {
<<<<<<< HEAD
					printf("\n\tGana el jugador 1 V c:\n");
					i=3;
					x=3;
                    return 0;
				}
				continue;
			}else{
				lose=0;
				win=0;
				break;
			}
		}
	}	
	lose=0;		
	win=0;
	for(x=0;x<3;x++){
		for(i=0;i<3;i++){
			if(xo[i][x]==2){
				lose+=1;
				if (lose==3) {
					printf("\n\tGana el jugador V 2 c:\n");
					i=3;
					x=3;
                    return 0;
				}
				continue;
=======
					printf("\n\tGanaste X c: V\n");
					i=3;
					x=3;
                    return 0;
					break;
				}else{
					win=0;
					lose=0;
					break;
				}	
			}
		}
	}
	
	for(x=0;x<3;x++){
			for(i=0;i<3;i++){
			if (xo[i][x]==2){
				lose++;
				if(lose==3){
					printf("\n\tGanaste O c: V\n");
					i=3;
					x=3;
                   	return 0;
					break;
>>>>>>> e909ca81e00cb658596b56a09ab72726952df51e
			}else{
				win=0;
				lose=0;
				break;
			}
<<<<<<< HEAD
		}
	}
=======

		}
			
	}
		}
	lose=NULL;		
	win=NULL;
>>>>>>> e909ca81e00cb658596b56a09ab72726952df51e
    /*Recorre diagonal principal en busca de semejantes*/
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(j==i){
				if(xo[j][i]==1){
					win++;
					if (win==3) {
						printf("\n\tGanaste X c: D\n");
						i=3;
						x=3;
                        return 0;
					}
					continue;
<<<<<<< HEAD
				}else{
					win=0;
					lose=0;
					break;
				}
			}
		}
	}
	lose=0;		
	win=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(j==i){
				if(xo[j][i]==2){
					lose+=1;
					if (lose==3) {
						printf("\n\tGanaste c:\n");
=======
				}else if(xo[j][i]==2){
					lose++;
					if(lose==3){
						printf("\n\tGanaste O c: D\n");
>>>>>>> e909ca81e00cb658596b56a09ab72726952df51e
						i=3;
						x=3;
                        return 0;
					}
					continue;
				}else{
					win=0;
					lose=0;
					break;
				}
			}
		}
	}
<<<<<<< HEAD
=======
	
	lose=NULL;		
	win=NULL;
>>>>>>> e909ca81e00cb658596b56a09ab72726952df51e

    /*Recorre diagonal secundaria en busca de semejantes*/
for(i=0;i<3;i++){
		if (xo[i][(3-1)-i]==1){
			win++;
			if (win==3) {
				printf("\n\tGanaste X c:DI\n");
				i=3;
				x=3;
                return 0;
			}
			continue;
<<<<<<< HEAD
		}else{
			win=0;
			lose=0;
			break;
		}
	}
	lose=0;		
	win=0;
	for(i=0;i<3;i++){
		if (xo[i][(3-1)-i]==2){
			lose+=1;
			if (lose==3) {
				printf("\n\tGanaste c:\n");
=======
		}else if (xo[i][(3-1)-i]==2){
			lose++;
			if(lose==3){
				printf("\n\tGanaste O c: DI\n");
>>>>>>> e909ca81e00cb658596b56a09ab72726952df51e
				i=3;
				x=3;
                return 0;
			}
			continue;
		}else{
			win=0;
			lose=0;
			break;
		}
		
	}
<<<<<<< HEAD

=======
	lose=NULL;		
	win=NULL;
>>>>>>> e909ca81e00cb658596b56a09ab72726952df51e

	for (j=0;j<3;j++){
        for(i=0;i<3;i++){
            if(xo[i][j]!=0){
				lleno++;
				if (lleno==9){
					printf("\n\t Empatacion");
					i=3;
					j=3;
					return 0;
				}
				continue;
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