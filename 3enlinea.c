#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
#include <time.h>
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
char rep;
int e=0,e1=0,e2=0, val=0;

int comprueba(void);
void mostrar(void);
void jugador1(void);
void jugador2(void);
void juegaPC(void);
void historial(void);
void rachas(void);

struct jugador{
	char name[LONG];
	char marca;
};

struct jugador player1;
struct jugador player2;

struct tm *outtime;
time_t hora;

char marca_comp;

void main(){
    /*FILE *archivo = fopen("C:/TC20/FICHEROS/registro.txt","a+b");*/
    int i,j,final=0;
	int opc;
	int cont=1;
	
	/*Abre archivo de registro*/
	FILE *archivo = fopen("C:/TC20/FICHEROS/registro.txt","w+b");
    
	time(&hora);
    outtime = localtime(&hora);

    


    do{

		clrscr();
		printf("Elija el modo de juego: \n");
		printf("1. P1 vs P2\n2. P1 vs PC\n");
		scanf("%d",&opc);

		final=0;
		i=0;
		j=0;
       	switch(opc){
		
			case 1: 
				clrscr();
				printf("Ingrese un username para player1: ");
				scanf("%s",&player1.name);
			
				printf("Ingrese un username para player2: ");
				scanf("%s",&player2.name);
				clrscr();

				printf("Elija que llevara, %s:   x       o \n", player1.name);
				do
					player1.marca=getch();
				while(tolower(player1.marca)!=X && tolower(player1.marca)!=O);

				if (player1.marca==X) {
					player2.marca=O;
				}else{
					player2.marca=X;
				}

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
						val=1;
						final=1;
						rachas();
						freopen("C:/TC20/FICHEROS/registro.txt","a+b",archivo);
						fprintf(archivo,"%.19s\n", asctime(outtime));
						fprintf(archivo,"%d. Ganador player 1:  %s [%d]\n",cont,player1.name,e);
						rewind(archivo);
						break;
					}
					
					getch();

					jugador2();
					mostrar();
					if (comprueba()==0){
						val=2;
						final=1;
						rachas();
						freopen("C:/TC20/FICHEROS/registro.txt","a+b",archivo);
						fprintf(archivo,"%.19s\n", asctime(outtime));
						fprintf(archivo,"%d.Ganador player 2:  %s [%d]\n",cont,player2.name,e);
						rewind(archivo);
						break;
					}
					getch();
				}

			break;

			case 2:
				clrscr();
				printf("Ingrese un username para player: ");
				scanf("%s",&player1.name);

				printf("Elija que llevara, %s:   x       o \n", player1.name);
				do
					player1.marca=getch();
				while(tolower(player1.marca)!=X && tolower(player1.marca)!=O);

				if (player1.marca==X) {
					marca_comp=O;
				}else{
					marca_comp=X;
				}

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
						val=1;
						rachas();
						freopen("C:/TC20/FICHEROS/registro.txt","a+b",archivo);
						fprintf(archivo,"%.19s\n", asctime(outtime));
						fprintf(archivo,"%d. Ganador player 1:  %s [%d]\n",cont,player1.name,e);
						rewind(archivo);
						final=1;
						break;
					}

					getch();
					
					juegaPC();
					mostrar();
					if (comprueba()==0){
						val=3;
						rachas();
						freopen("C:/TC20/FICHEROS/registro.txt","a+b",archivo);
						fprintf(archivo,"%.19s\n", asctime(outtime));
						fprintf(archivo,"%d. Ganador PC [%d]\n",cont,e);
						rewind(archivo);
						final=1;
						break;
					}
					getch();
				}


			break;
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

		cont++;
		clrscr();

    }while(tolower(rep)!=N);
	fclose(archivo);

}

void jugador1(){ /*marca 1*/
	int posx,posy,repetir=0;
	clrscr();
            /*x=1 o=2*/
		while(repetir==0){
			clrscr();
			printf("%s: %c",player1.name,player1.marca);
			printf("\nPosicion donde marcar %s: ",  player1.name);
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
		printf("%s: %c",player2.name,player2.marca);
		printf("\nPosicion donde marcar %s: ", player2.name);
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

void juegaPC(){
	int posx,posy,repetir=0;
	srand ((unsigned) time (NULL));
	clrscr();
            /*x=1 o=2*/
		printf("PC esta pensando. . .");
		delay(10);
		while(repetir==0){
			clrscr();

			posx = rand() % 3;
            posy = rand() % 3;
			
            if (marca_comp==X && xo[posx][posy]==0){
                xo[posx][posy]=1;
				repetir=1;
            }else if (marca_comp==O && xo[posx][posy]==0){
                xo[posx][posy]=2;
				repetir=1;
            }else{
				repetir=0;
            }
		}
}

int comprueba(){
	int i, j, x;
	int lleno=0;
	int win=0, lose=0;

	
	/*Recorre verticales en busca de semejantes*/
    for(x=0;x<3;x++){
		for(i=0;i<3;i++){
			if(xo[x][i]==1){
				win+=1;
				if (win==3) {
					printf("\n\tGana el jugador H 1 c:\n");
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
				win=0;
				lose=0;
				break;
			}

		}
	}
	lose=0;		
	win=0;
    /*Recorre horizontales en busca de semejantes*/
	for(x=0;x<3;x++){
		for(i=0;i<3;i++){
			if(xo[i][x]==1){
				win++;
				if (win==3) {
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
			}else{
				win=0;
				lose=0;
				break;
			}
		}
	}
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
void rachas(){

	if(val==1){
		e+=1;
		e1=0;
		e2=0;
	 }else if(val==2){
		e1+=1;
		e=0;
		e2=0;
	}else if(val==3){
		 e2+=1;
		 e=0;
		 e1=0;
	 }
}