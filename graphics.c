#include<mouse.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<button.h>

#define O 111
#define X 120

void ajustes(void);
void pantalla_princip(void);
void pantalla_juego(void);
void pintar_equis(int x1, int x2, int y1, int y2);
int comprueba(void);
void rachas(void);
void jugador1(void);
void jugador2(void);

int e=0,e1=0,e2=0, val=0;

int xo[3][3]={
    0,0,0,
    0,0,0
    ,0,0,0
};

struct jugador{
	char name[20];
	char marca;
};

struct jugador player1;
struct jugador player2;

void main(){
    int driver=DETECT,modo=VGAHI;
    FILE *archivo = fopen("C:/TC20/FICHEROS/registro.txt","w+b");
    /*button boton1;*/
    initgraph(&driver,&modo,"");
    /*fondo*/
    pantalla_princip();

    closegraph();
}

void pantalla_princip(){
    int x,y;
    clrscr();
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(0,0,640,480);
    setbkcolor(LIGHTGRAY);
    setcolor(WHITE);

    /*letras*/
    setcolor(BLUE);
    settextstyle(DEFAULT_FONT,0,4);
    outtextxy(100,20,"Tres");
    setcolor(LIGHTBLUE);
    outtextxy(260,20,"en");
    setcolor(CYAN);
    outtextxy(375,20,"Linea");
    /*circulo y cruz*/
    setcolor(GREEN);
    setlinestyle(0,1,3);
    circle(50,40,20);
    setcolor(LIGHTMAGENTA);
    setlinestyle(0,1,3);
    pintar_equis(550,590,20,60);
    /*menu*/
    setfillstyle(LINE_FILL,WHITE);
    bar(100,80,530,420);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(120,100,510,400);

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(220,160,420,220);
    bar(220,260,420,320);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT,0,3);
    outtextxy(260,180,"Jugar");
    outtextxy(260,280,"Salir");

    mver();
    do{
        while(mclick()!=1){
            x = mxpos(1);
            y = mypos(1);
        }

        if(limit(x,y,215,155,425,225)){
            mocultar();
            ajustes();
        }

        if(limit(x,y,215,255,425,325)){
            mocultar();
            closegraph();
            exit(0);
        }

    }while(1);
}

void ajustes(){
    int x,y;

    button vspc, p1p2;
    button equis, cero;
    clrscr();
    setbkcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(0,0,640,480);

    /*menu*/
    setfillstyle(LINE_FILL,WHITE);
    bar(20,70,340,420);
    setfillstyle(SOLID_FILL,CYAN);
    bar(40,90,320,400);
    
    /*regresar*/
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(20,10,100,40);
    setcolor(LIGHTGRAY);
    line(34,25,90,25);
    line(34,25,53,35);
    line(34,25,53,15);
    
    /*jugar*/
    setfillstyle(LINE_FILL,WHITE);
    bar(390,330,590,420);
    setfillstyle(SOLID_FILL,CYAN);
    bar(410,350,570,400);

    /*selector*/
    setfillstyle(LINE_FILL,WHITE);
    bar(390,100,590,320);
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(410,120,570,300);
    setlinestyle(0,0,3);
    setcolor(GREEN);
    circle(450,250,20);
    setlinestyle(0,0,3);
    setcolor(LIGHTMAGENTA);
    pintar_equis(430,470,160,200);


    settextstyle(0,0,3);
    setcolor(DARKGRAY);
    outtextxy(70,110,"Modalidad");
    outtextxy(60,200,"P1 vs PC");
    outtextxy(60,300,"P1 vs P2");
    outtextxy(430,360,"Jugar!");
    outtextxy(400,70,"Ficha P1");
    newButton(&equis,500,170,"  .  ",LIGHTGRAY,DARKGRAY);
    newButton(&cero,500,250,"     ",LIGHTGRAY,WHITE);
    effect3d(equis.x1,equis.y1,equis.x2,equis.y2,1,DEPRESSED); 

    newButton(&vspc,280,210," ON  ",LIGHTGRAY,GREEN);
    newButton(&p1p2,280,310," OFF ",LIGHTGRAY,RED);
    effect3d(vspc.x1,vspc.y1,vspc.x2,vspc.y2,1,DEPRESSED); 
    mver();
    do{
        while(mclick()!=1){
            x = mxpos(1);
            y = mypos(1);
        }

        if(limit(x,y,5,5,95,45)){
            mocultar();
            pantalla_princip();
        } else if(limit(x,y,vspc.x1,vspc.y1,vspc.x2,vspc.y2)){

            newButton(&p1p2,280,310," OFF ",LIGHTGRAY,RED);
            newButton(&vspc,280,210," ON  ",LIGHTGRAY,GREEN);
            effect3d(vspc.x1,vspc.y1,vspc.x2,vspc.y2,1,DEPRESSED);
            effect3d(p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2,1,ELEVATE);
        } else if (limit(x,y,p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2)){

            newButton(&vspc,280,210," OFF ",LIGHTGRAY,RED);
            newButton(&p1p2,280,310," ON  ",LIGHTGRAY,GREEN);
            effect3d(vspc.x1,vspc.y1,vspc.x2,vspc.y2,1,ELEVATE);
            effect3d(p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2,1,DEPRESSED);
        }else if (limit(x,y,equis.x1,equis.y1,equis.x2,equis.y2)){
            player1.marca=X;
            player2.marca=O;
            newButton(&equis,500,170,"  .  ",LIGHTGRAY,DARKGRAY);
            newButton(&cero,500,250,"     ",LIGHTGRAY,WHITE);
           effect3d(cero.x1,cero.y1,cero.x2,cero.y2,1,ELEVATE);
            effect3d(equis.x1,equis.y1,equis.x2,equis.y2,1,DEPRESSED);
        }else if(limit(x,y,cero.x1,cero.y1,cero.x2,cero.y2)){

            player1.marca=O;
            player2.marca=X;
            newButton(&equis,500,170,"     ",LIGHTGRAY,WHITE);
            newButton(&cero,500,250,"  .  ",LIGHTGRAY,DARKGRAY);
            effect3d(cero.x1,cero.y1,cero.x2,cero.y2,1,DEPRESSED);
            effect3d(equis.x1,equis.y1,equis.x2,equis.y2,1,ELEVATE);
        }else if (limit(x,y,405,345,575,405)){

            mocultar();
            pantalla_juego();
        }
    }while(1);

}

void pantalla_juego(){
    int i,j,final=0;
	int opc=1;
	int cont=1;

    int x,y;
    button boton1;
    clrscr();
    setbkcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(0,0,640,480);

    /*cuadricula*/
    setcolor(WHITE);
    setlinestyle(0,0,3);
    rectangle(170,90,470,390);
    line(270,90,270,390);
    line(375,90,375,390);
    line(170,190,470,190);
    line(170,290,470,290);

    /*regresar*/
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(10,10,90,40);
    setlinestyle(0,0,3);
    setcolor(LIGHTGRAY);
    line(24,25,80,25);
    line(24,25,43,35);
    line(24,25,43,15);

    /*player*/
    setcolor(DARKGRAY);
    settextstyle(0,0,2);
    outtextxy(30,290,"PLAYER 1");
    outtextxy(500,290,"PLAYER 2");
    
    /*newButton(&boton1,100,100,"Ajustes",LIGHTGRAY,WHITE);*/
    mver();

   switch(opc){
       case 1:
            while(final==0){

                jugador1();
                if (comprueba()==0){
                    val=1;
                    final=1;
                    rachas();
                    freopen("C:/TC20/FICHEROS/registro.txt","a+b",archivo);
                    fprintf(archivo,"%.19s\n", asctime(outtime));
                    if(e>4){
                        fprintf(archivo,"%d. Ganador player 1 [%d]\n",cont,e);
                    }else{
                        fprintf(archivo,"%d. Ganador player 1 \n",cont,e);
                    }
                    rewind(archivo);
                    break;
                }

                juegaPC();
                if (comprueba()==0){
                    val=3;
                    final=1;
                    rachas();
                    freopen("C:/TC20/FICHEROS/registro.txt","a+b",archivo);
                    fprintf(archivo,"%.19s\n", asctime(outtime));
                    if(e>4){
                        fprintf(archivo,"%d. Gana PC [%d]\n",cont,e);
                    }else{
                        fprintf(archivo,"%d. Gana PC \n",cont,e);
                    }
                    rewind(archivo);
                    break;
                }
	        }
        
       break;

        case 2:
            while(final==0){

                jugador1();
                if (comprueba()==0){
                    val=1;
                    final=1;
                    rachas();
                    freopen("C:/TC20/FICHEROS/registro.txt","a+b",archivo);
                    fprintf(archivo,"%.19s\n", asctime(outtime));
                    if(e>4){
                        fprintf(archivo,"%d. Ganador player 1 [%d]\n",cont,e);
                    }else{
                        fprintf(archivo,"%d. Ganador player 1 \n",cont,e);
                    }
                    rewind(archivo);
                    break;
                }

                jugador2();
                if (comprueba()==0){
                    val=2;
                    final=1;
                    rachas();
                    freopen("C:/TC20/FICHEROS/registro.txt","a+b",archivo);
                    fprintf(archivo,"%.19s\n", asctime(outtime));
                    if(e>4){
                        fprintf(archivo,"%d. Ganador player 2 [%d]\n",cont,e);
                    }else{
                        fprintf(archivo,"%d. Ganador player 2 \n",cont,e);
                    }
                    rewind(archivo);
                    break;
                }
	        }

       break;
   }

    
}

void jugador1(){
    int x,y;

    do{
		while(mclick()!=1){
			x=mxpos(1);
			y=mypos(1);
		}
        if(limit(x,y,170,90,270,190)){
             while(repetir==0){
                if (player1.marca==X && xo[0][0]==0){
                    xo[0][0]=1;
                    pintar_equis(190,230,110,170);
                    repetir=1;
                }else if (player1.marca==O && xo[0][0]==0){
                    xo[0][0]=2;
                    circle(200,120,5);
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if (limit(x,y,270,90,370,190)){
             while(repetir==0){
                if (player1.marca==X && xo[0][1]==0){
                    xo[0][1]=1;
                    pintar_equis(290,330,110,170);
                    repetir=1;
                }else if (player1.marca==O && xo[0][1]==0){
                    xo[0][1]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if (limit(x,y,370,90,470,190)){
             while(repetir==0){
                if (player1.marca==X && xo[0][2]==0){
                    xo[0][2]=1;
                    pintar_equis(390,430,110,170);
                    repetir=1;
                }else if (player1.marca==O && xo[0][2]==0){
                    xo[0][2]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if (limit(x,y,170,190,270,290)){
             while(repetir==0){
                if (player1.marca==X && xo[1][0]==0){
                    xo[1][0]=1;
                    pintar_equis(190,330,210,270);
                    repetir=1;
                }else if (player1.marca==O && xo[1][0]==0){
                    xo[1][0]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,270,190,370,290)){
             while(repetir==0){
                if (player1.marca==X && xo[1][1]==0){
                    xo[1][1]=1;
                    pintar_equis(290,330,210,270);
                    repetir=1;
                }else if (player1.marca==O && xo[1][1]==0){
                    xo[1][1]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,370,190,470,290)){
             while(repetir==0){
                if (player1.marca==X && xo[1][2]==0){
                    xo[1][2]=1;
                    pintar_equis(390,430,210,270);
                    repetir=1;
                }else if (player1.marca==O && xo[1][2]==0){
                    xo[1][2]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,170,290,270,390)){
             while(repetir==0){
                if (player1.marca==X && xo[2][0]==0){
                    xo[2][0]=1;
                    pintar_equis(190,430,310,350);
                    repetir=1;
                }else if (player1.marca==O && xo[2][2]==0){
                    xo[2][2]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,270,290,370,390)){
            while(repetir==0){
                if (player1.marca==X && xo[2][1]==0){
                    pintar_equis(290,430,310,350);
                    xo[2][1]=1;
                    repetir=1;
                }else if (player1.marca==O && xo[2][1]==0){
                    xo[2][1]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,370,290,470,390)){
            while(repetir==0){
                if (player1.marca==X && xo[2][2]==0){
                    xo[2][2]=1;
                    pintar_equis(390,430,310,350);
                    repetir=1;
                }else if (player1.marca==O && xo[2][2]==0){
                    xo[2][2]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }
	}while(1);
}

void jugador2(){
    int x,y;

    do{
		while(mclick()!=1){
			x=mxpos(1);
			y=mypos(1);
		}

		if(limit(x,y,170,90,270,190)){
             while(repetir==0){
                if (player2.marca==X && xo[0][0]==0){
                    xo[0][0]=1;
                    pintar_equis(390,430,310,350);
                    repetir=1;
                }else if (player2.marca==O && xo[0][0]==0){
                    xo[0][0]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if (limit(x,y,270,90,370,190)){
             while(repetir==0){
                if (player2.marca==X && xo[0][1]==0){
                    xo[0][1]=1;
                    pintar_equis(390,430,310,350);
                    repetir=1;
                }else if (player2.marca==O && xo[0][1]==0){
                    xo[0][1]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if (limit(x,y,370,90,470,190)){
             while(repetir==0){
                if (player2.marca==X && xo[0][2]==0){
                    xo[0][2]=1;
                    pintar_equis(390,430,310,350);
                    repetir=1;
                }else if (player2.marca==O && xo[0][2]==0){
                    xo[0][2]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if (limit(x,y,170,190,270,290)){
             while(repetir==0){
                if (player2.marca==X && xo[1][0]==0){
                    xo[1][0]=1;
                    pintar_equis(390,430,310,350);
                    repetir=1;
                }else if (player2.marca==O && xo[1][0]==0){
                    xo[1][0]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,270,190,370,290)){
             while(repetir==0){
                if (player2.marca==X && xo[1][1]==0){
                    xo[1][1]=1;
                    pintar_equis(390,430,310,350);
                    repetir=1;
                }else if (player2.marca==O && xo[1][1]==0){
                    xo[1][1]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,370,190,470,290)){
             while(repetir==0){
                if (player2.marca==X && xo[1][2]==0){
                    xo[1][2]=1;
                    pintar_equis(390,430,310,350);
                    repetir=1;
                }else if (player2.marca==O && xo[1][2]==0){
                    xo[1][2]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,170,290,270,390)){
             while(repetir==0){
                if (player2.marca==X && xo[2][0]==0){
                    xo[2][0]=1;
                    pintar_equis(390,430,310,350);
                    repetir=1;
                }else if (player2.marca==O && xo[2][2]==0){
                    xo[2][2]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,270,290,370,390)){
            while(repetir==0){
                if (player2.marca==X && xo[2][1]==0){
                    xo[2][1]=1;
                    pintar_equis(390,430,310,350);
                    repetir=1;
                }else if (player2.marca==O && xo[2][1]==0){
                    xo[2][1]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,370,290,470,390)){
            while(repetir==0){
                if (player2.marca==X && xo[2][2]==0){
                    xo[2][2]=1;
                    pintar_equis(390,430,310,350);
                    repetir=1;
                }else if (player2.marca==O && xo[2][2]==0){
                    xo[2][2]=2;
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }

	}while(1);
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

void pintar_equis(int x1, int x2, int y1, int y2){
    setcolor(LIGHTMAGENTA);
    line(x1,y1,x2,y2);
    line(x2,y1,x1,y2);
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
    