#include<mouse.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<GRAPHICS.h>
#include<time.h>
#include<button.h>

#define duration 20
#define O 111
#define X 120

int driver=DETECT, mode, color,modo,mposx,mposy,fill,past_color;
struct tm *outtime;
    time_t hora;
    int i,x,y;
    button boton1, boton2, boton3;
    int e=0,e1=0,e2=0, val=0, bool1=0;
    int opc=1;
    int lleno=0;
    int win=0, lose=0;
    char marca_comp;

void reloj(void);
void ajustes(void);
void pantalla_princip(void);
void pantalla_juego(void);
void screen(void);
void Windows(void);
void salir(void);
void flag(void);
void pintar_equis(int x1, int x2, int y1, int y2);
void rachas(void);
int comprueba(void);
void jugador1(void);
void jugador2(void);
void juegaPC(void);
void present(void);
void pantalla_win(void);

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
    initgraph(&driver,&mode," ");
	Windows();
    screen();
    reloj();
    pantalla_princip();
    salir();
    ajustes();
    mver();
    flag();
    present();
    pantalla_win();
}

     void screen(){
        initgraph(&driver,&mode," ");
    setlinestyle(0,0,3);
	rectangle(110,140,170,360);
	rectangle(110,320,350,380);
	rectangle(290,213,350,320);
	rectangle(195,140,260,300);
	rectangle(200,140,390,200);
	rectangle(380,140,440,380);
	rectangle(380,320,540,380);
	rectangle(470,220,540,380);
	rectangle(470,140,540,210);
	/*rectangle();*/
	setcolor(BLACK);
	line(340,320,348,320);
	line(251,200,258,200);
	line(260,191,260,198);
	line(531,320,538,320);
	line(440,371,440,378);
	line(470,371,470,378);
	/*vertical*/
	bar(160,130,100,370);
	/*horizontal*/
	bar(160,310,340,370);
	/*fin colita u*/
	bar(280,220,340,370);
	 
	/*inicio n*/
	bar(250,130,185,290);
	/*horizontal*/
	bar(190,130,400,190);
	/*vertical*/
	bar(370,130,430,370);
	 
	/*horizontal inicio i*/
	bar(400,310,530,370);
	/*vertical*/
	bar(460,230,530,370);
	/*punto i*/
	bar(460,130,530,200);

        setfillstyle(SOLID_FILL,LIGHTGRAY);
        bar(0,450,640,480);
        setcolor(RED);
        setlinestyle(0,0,3);
        circle(20,465,8);
         setlinestyle(0,0,3);
	    line(20,455,20,465);
        setcolor(BLUE);
        line(70,460,80,470);
        line(80,460,70,470);
        circle(90,465,6);
        setfillstyle(SOLID_FILL,WHITE);
        bar(40,455,60,475);
        setcolor(DARKGRAY);
        setlinestyle(0,0,1);
        line(42,460,58,460);
        line(42,465,58,465);
        line(42,470,58,470);
        mver();
        
    do{
      
        
		while(mclick()!=1){
			mposx=mxpos(1);
			mposy=mypos(1);
            reloj();
		}
		while(mclick()==1){
            
			if(limit(mposx,mposy,0,450,30,480)){
				mocultar();
                clrscr();   
                flag();
				mver();
                
			}else if(limit(mposx,mposy,30,450,60,480)){
				mocultar();
				present();
                screen();
				mver();

            }else if(limit(mposx,mposy,80,450,100,480)){
                mocultar();
                pantalla_princip();
                mver();
                
                
			}
		}
        
        
	}while(1);
    }


void reloj(){
    
        time(&hora);
        outtime = localtime(&hora);
        setcolor(BLUE);
        outtextxy(445, 460, ("%.19s\n",asctime(outtime)));
        delay(1000);
        bar(450,450,650,480);
        setfillstyle(SOLID_FILL,LIGHTGRAY);
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
    player1.marca=X;

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
            mocultar();
            opc=1;
            newButton(&p1p2,280,310," OFF ",LIGHTGRAY,RED);
            newButton(&vspc,280,210," ON  ",LIGHTGRAY,GREEN);
            effect3d(vspc.x1,vspc.y1,vspc.x2,vspc.y2,1,DEPRESSED);
            effect3d(p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2,1,ELEVATE);
            mver();
        } else if (limit(x,y,p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2)){
            opc=2;
            mocultar();
            newButton(&vspc,280,210," OFF ",LIGHTGRAY,RED);
            newButton(&p1p2,280,310," ON  ",LIGHTGRAY,GREEN);
            effect3d(vspc.x1,vspc.y1,vspc.x2,vspc.y2,1,ELEVATE);
            effect3d(p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2,1,DEPRESSED);
            mver();
        }else if (limit(x,y,equis.x1,equis.y1,equis.x2,equis.y2)){
            mocultar();
            player1.marca=X;
            player2.marca=O;
            newButton(&equis,500,170,"  .  ",LIGHTGRAY,DARKGRAY);
            newButton(&cero,500,250,"     ",LIGHTGRAY,WHITE);
           effect3d(cero.x1,cero.y1,cero.x2,cero.y2,1,ELEVATE);
            effect3d(equis.x1,equis.y1,equis.x2,equis.y2,1,DEPRESSED);
            mver();
        }else if(limit(x,y,cero.x1,cero.y1,cero.x2,cero.y2)){
            mocultar();
            player1.marca=O;
            player2.marca=X;
            newButton(&equis,500,170,"     ",LIGHTGRAY,WHITE);
            newButton(&cero,500,250,"  .  ",LIGHTGRAY,DARKGRAY);
            effect3d(cero.x1,cero.y1,cero.x2,cero.y2,1,DEPRESSED);
            effect3d(equis.x1,equis.y1,equis.x2,equis.y2,1,ELEVATE);
            mver();
        }else if (limit(x,y,405,345,575,405)){

            mocultar();
            pantalla_juego();
        }
    }while(1);

}

void pantalla_juego(){
    FILE *archivo = fopen("C:/TC20/FICHEROS/registro.txt","a+");

    int i,j,final=0;
	
	int cont=1;
    
    time(&hora);
    outtime = localtime(&hora);

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

     if (player1.marca==X){
        pintar_equis(50,110,320,380);
        setcolor(GREEN);
        circle(560,350,30);
     }else if (player2.marca==X){
        pintar_equis(530,590,320,380);
        setcolor(GREEN);
        circle(80,350,30);
     }

    
    /*newButton(&boton1,100,100,"Ajustes",LIGHTGRAY,WHITE);*/
    mver();

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

   switch(opc){
       cont=1;
       final=0;
       bool1=0;
       case 1:
            for (j=0;j<3;j++){
		        for(i=0;i<3;i++){
			        xo[i][j]=0;
	            }
	        }
            while(final==0){

                jugador1();
                if (comprueba()==0){
                    val=1;
                    final=1;
                    bool1=1;
                    rachas();
                    freopen("C:/TC20/FICHEROS/registro.txt","a+",archivo);
                    
                    fprintf(archivo,"%.19s\n", asctime(outtime));
                    if(e>4){
                        fprintf(archivo,"%d. Ganador player 1 [%d]\n",cont,e);
                    }else{
                        fprintf(archivo,"%d. Ganador player 1 \n",cont,e);
                    }
                    rewind(archivo);
                    pantalla_win();
                    break;
                }

                juegaPC();
                if (comprueba()==0){
                    val=3;
                    final=1;
                    bool1=2;
                    rachas();
                    freopen("C:/TC20/FICHEROS/registro.txt","a+",archivo);
                    time(&hora);
                    outtime = localtime(&hora);
                    fprintf(archivo,"%.19s\n", asctime(outtime));
                    if(e>4){
                        fprintf(archivo,"%d. Gana PC [%d]\n",cont,e);
                    }else{
                        fprintf(archivo,"%d. Gana PC \n",cont,e);
                    }
                    rewind(archivo);
                    pantalla_win();
                    break;
                }

                cont++;
	        }
       break;

        case 2:
            cont=1;

            for (j=0;j<3;j++){
		        for(i=0;i<3;i++){
			        xo[i][j]=0;
	            }
	        }

            while(final==0){

                jugador1();
                if (comprueba()==0){
                    val=1;
                    final=1;
                    bool1=1;
                    rachas();
                    freopen("C:/TC20/FICHEROS/registro.txt","a+",archivo);
                    fprintf(archivo,"%.19s\n", asctime(outtime));
                    if(e>4){
                        fprintf(archivo,"%d. Ganador player 1 [%d]\n",cont,e);
                    }else{
                        fprintf(archivo,"%d. Ganador player 1 \n",cont,e);
                    }
                   
                    rewind(archivo);
                    pantalla_win();
                    break;
                }

                jugador2();
                if (comprueba()==0){
                    val=2;
                    final=1;
                    bool1=3;
                    rachas();
                    freopen("C:/TC20/FICHEROS/registro.txt","a+",archivo);
                    fprintf(archivo,"%.19s\n", asctime(outtime));
                    if(e>4){
                        fprintf(archivo,"%d. Ganador player 2 [%d]\n",cont,e);
                    }else{
                        fprintf(archivo,"%d. Ganador player 2 \n",cont,e);
                    }
                    rewind(archivo);
                    pantalla_win();
                    break;
                }

                cont++;
	        }
       break;
   }
}

void juegaPC(){
    int posx,posy,repetir=0;
    
	srand ((unsigned) time (NULL));
            /*x=1 o=2*/
        setlinestyle(0,0,3);
        if (player1.marca==X) {
			marca_comp=O;
		}else{
			marca_comp=X;
		}

		while(repetir==0){

			posx = rand() % 3;
            posy = rand() % 3;

			
            if (marca_comp==X && posx==0 && posy==0 && xo[posx][posy]==0){
                xo[posx][posy]=1;
                mocultar();
                pintar_equis(190,230,110,170);
                mver();
				repetir=1;
            }else if (marca_comp==O && posx==0 && posy==0 && xo[posx][posy]==0){
                xo[posx][posy]=2;
                mocultar();
                setcolor(GREEN);
                circle(220,140,32);
                mver();
				repetir=1;
            }else if (marca_comp==X && posx==0 && posy==1 && xo[posx][posy]==0){
                xo[posx][posy]=1;
                 mocultar();
                pintar_equis(290,330,110,170);
                mver();
				repetir=1;
            }else if (marca_comp==O && posx==0 && posy==1 && xo[posx][posy]==0){
                xo[posx][posy]=2;
                mocultar();
                setcolor(GREEN);
                circle(320,140,32);
                mver();
				repetir=1;
            }else if (marca_comp==X && posx==0 && posy==2 && xo[posx][posy]==0){
                xo[posx][posy]=1;
                mocultar();
                pintar_equis(390,430,110,170);
                mver();
                repetir=1;
            }else if (marca_comp==O && posx==0 && posy==2 && xo[posx][posy]==0){
                xo[posx][posy]=2;
                mocultar();
                setcolor(GREEN);
                circle(420,140,32);
                mver();
                repetir=1;
            }else if (marca_comp==X && posx==1 && posy==0 && xo[posx][posy]==0){
                xo[posx][posy]=1;
                mocultar();
                pintar_equis(190,230,210,270);
                mver();
                repetir=1;
            }else if (marca_comp==O && posx==1 && posy==0 && xo[posx][posy]==0){
                xo[posx][posy]=2;
                mocultar();
                setcolor(GREEN);
                circle(220,240,32);
                mver();
                repetir=1;
            }else if (marca_comp==X && posx==1 && posy==1 && xo[posx][posy]==0){
                xo[posx][posy]=1;
                mocultar();
                pintar_equis(290,330,210,270);
                mver();
                repetir=1;
            }else if (marca_comp==O && posx==1 && posy==1 && xo[posx][posy]==0){
                xo[posx][posy]=2;
                mocultar();
                setcolor(GREEN);
                circle(320,240,32);
                mver();
                repetir=1;
            }else if (marca_comp==X && posx==1 && posy==2 && xo[posx][posy]==0){
                xo[posx][posy]=1;
                mocultar();
                pintar_equis(390,430,210,270);
                mver();
                repetir=1;
            }else if (marca_comp==O && posx==1 && posy==2 && xo[posx][posy]==0){
                xo[posx][posy]=2;
                mocultar();
                setcolor(GREEN);
                circle(420,240,32);
                mver();
                repetir=1;
            }else if (marca_comp==X && posx==2 && posy==0 && xo[posx][posy]==0){
                xo[posx][posy]=1;
                mocultar();
                pintar_equis(190,230,310,370);
                mver();
                repetir=1;
            }else if (marca_comp==O && posx==2 && posy==0 && xo[posx][posy]==0){
                xo[posx][posy]=2;
                mocultar();
                setcolor(GREEN);
                circle(220,340,32);
                mver();
                repetir=1;
            }else if (marca_comp==X && posx==2 && posy==1 && xo[posx][posy]==0){
                mocultar();
                pintar_equis(290,330,310,370);
                mver();
                xo[posx][posy]=1;
                repetir=1;
            }else if (marca_comp==O && posx==2 && posy==1 && xo[posx][posy]==0){
                xo[posx][posy]=2;
                mocultar();
                setcolor(GREEN);
                circle(320,340,32);
                mver();
                repetir=1;
            }else if (marca_comp==X && posx==2 && posy==2 && xo[posx][posy]==0){
                xo[posx][posy]=1;
                mocultar();
                pintar_equis(390,430,310,370);
                mver();
                repetir=1;
            }else if (marca_comp==O && posx==2 && posy==2 && xo[posx][posy]==0){
                xo[posx][posy]=2;
                mocultar();
                setcolor(GREEN);
                circle(420,340,32);
                mver();
                repetir=1;
            }else{
                repetir=0;
            }

            posx=NULL;
            posy=NULL;
		}
}

void jugador1(){
    int x,y,repetir=0;

    do{
		while(mclick()!=1){
			x=mxpos(1);
			y=mypos(1);
		}
        setlinestyle(0,0,3);

        if(limit(x,y,170,90,270,190)){
             while(repetir==0){
                if (player1.marca==X && xo[0][0]==0){
                    xo[0][0]=1;
                    mocultar();
                    pintar_equis(190,230,110,170);
                    mver();
                    repetir=1;
                }else if (player1.marca==O && xo[0][0]==0){
                    xo[0][0]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(220,140,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if (limit(x,y,270,90,370,190)){
             while(repetir==0){
                if (player1.marca==X && xo[0][1]==0){
                    xo[0][1]=1;
                    mocultar();
                    pintar_equis(290,330,110,170);
                    mver();
                    repetir=1;
                }else if (player1.marca==O && xo[0][1]==0){
                    xo[0][1]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(320,140,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if (limit(x,y,370,90,470,190)){
             while(repetir==0){
                if (player1.marca==X && xo[0][2]==0){
                    xo[0][2]=1;
                    mocultar();
                    pintar_equis(390,430,110,170);
                    mver();
                    repetir=1;
                }else if (player1.marca==O && xo[0][2]==0){
                    xo[0][2]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(420,140,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if (limit(x,y,170,190,270,290)){
             while(repetir==0){
                if (player1.marca==X && xo[1][0]==0){
                    xo[1][0]=1;
                    mocultar();
                    pintar_equis(190,230,210,270);
                    mver();
                    repetir=1;
                }else if (player1.marca==O && xo[1][0]==0){
                    xo[1][0]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(220,240,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,270,190,370,290)){
             while(repetir==0){
                if (player1.marca==X && xo[1][1]==0){
                    xo[1][1]=1;
                    mocultar();
                    pintar_equis(290,330,210,270);
                    mver();
                    repetir=1;
                }else if (player1.marca==O && xo[1][1]==0){
                    xo[1][1]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(320,240,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,370,190,470,290)){
             while(repetir==0){
                if (player1.marca==X && xo[1][2]==0){
                    xo[1][2]=1;
                    mocultar();
                    pintar_equis(390,430,210,270);
                    mver();
                    repetir=1;
                }else if (player1.marca==O && xo[1][2]==0){
                    xo[1][2]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(420,240,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,170,290,270,390)){
             while(repetir==0){
                if (player1.marca==X && xo[2][0]==0){
                    xo[2][0]=1;
                    mocultar();
                    pintar_equis(190,230,310,370);
                    mver();
                    repetir=1;
                }else if (player1.marca==O && xo[2][0]==0){
                    xo[2][0]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(220,340,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,270,290,370,390)){
            while(repetir==0){
                if (player1.marca==X && xo[2][1]==0){
                    xo[2][1]=1;
                    mocultar();
                    pintar_equis(290,330,310,370);
                    mver();
                    repetir=1;
                }else if (player1.marca==O && xo[2][1]==0){
                    xo[2][1]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(320,340,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,370,290,470,390)){
            while(repetir==0){
                if (player1.marca==X && xo[2][2]==0){
                    xo[2][2]=1;
                    mocultar();
                    pintar_equis(390,430,310,370);
                    mver();
                    repetir=1;
                }else if (player1.marca==O && xo[2][2]==0){
                    xo[2][2]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(420,340,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }
	}while(repetir==0);
}

void jugador2(){
    int x,y,repetir=0;

     do{
		while(mclick()!=1){
			x=mxpos(1);
			y=mypos(1);
		}
        setlinestyle(0,0,3);
        if(limit(x,y,170,90,270,190)){
             while(repetir==0){
                if (player2.marca==X && xo[0][0]==0){
                    xo[0][0]=1;
                    mocultar();
                    pintar_equis(190,230,110,170);
                    mver();
                    repetir=1;
                }else if (player2.marca==O && xo[0][0]==0){
                    xo[0][0]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(220,140,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if (limit(x,y,270,90,370,190)){
             while(repetir==0){
                if (player2.marca==X && xo[0][1]==0){
                    xo[0][1]=1;
                    mocultar();
                    pintar_equis(290,330,110,170);
                    mver();
                    repetir=1;
                }else if (player2.marca==O && xo[0][1]==0){
                    xo[0][1]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(320,140,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if (limit(x,y,370,90,470,190)){
             while(repetir==0){
                if (player2.marca==X && xo[0][2]==0){
                    xo[0][2]=1;
                    mocultar();
                    pintar_equis(390,430,110,170);
                    mver();
                    repetir=1;
                }else if (player2.marca==O && xo[0][2]==0){
                    xo[0][2]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(420,140,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if (limit(x,y,170,190,270,290)){
             while(repetir==0){
                if (player2.marca==X && xo[1][0]==0){
                    xo[1][0]=1;
                    mocultar();
                    pintar_equis(190,230,210,270);
                    mver();
                    repetir=1;
                }else if (player2.marca==O && xo[1][0]==0){
                    xo[1][0]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(220,240,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,270,190,370,290)){
             while(repetir==0){
                if (player2.marca==X && xo[1][1]==0){
                    xo[1][1]=1;
                    mocultar();
                    pintar_equis(290,330,210,270);
                    mver();
                    repetir=1;
                }else if (player2.marca==O && xo[1][1]==0){
                    xo[1][1]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(320,240,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,370,190,470,290)){
             while(repetir==0){
                if (player2.marca==X && xo[1][2]==0){
                    xo[1][2]=1;
                    mocultar();
                    pintar_equis(390,430,210,270);
                    mver();
                    repetir=1;
                }else if (player2.marca==O && xo[1][2]==0){
                    xo[1][2]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(420,240,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,170,290,270,390)){
             while(repetir==0){
                if (player2.marca==X && xo[2][0]==0){
                    xo[2][0]=1;
                    mocultar();
                    pintar_equis(190,230,310,350);
                    mver();
                    repetir=1;
                }else if (player2.marca==O && xo[2][0]==0){
                    xo[2][0]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(220,340,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,270,290,370,390)){
            while(repetir==0){
                if (player2.marca==X && xo[2][1]==0){
                    mocultar();
                    pintar_equis(290,330,310,350);
                    mver();
                    xo[2][1]=1;
                    repetir=1;
                }else if (player2.marca==O && xo[2][1]==0){
                    xo[2][1]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(320,340,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }else if(limit(x,y,370,290,470,390)){
            while(repetir==0){
                if (player2.marca==X && xo[2][2]==0){
                    xo[2][2]=1;
                    mocultar();
                    pintar_equis(390,430,310,350);
                    mver();
                    repetir=1;
                }else if (player2.marca==O && xo[2][2]==0){
                    xo[2][2]=2;
                    mocultar();
                    setcolor(GREEN);
                    circle(420,340,32);
                    mver();
                    repetir=1;
                }else{
                    repetir=0;
                }
		    }
        }
	}while(repetir==0);
}

int comprueba(){
	int i, j, x;
	
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
    win=0;
    lose=0;
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

void pantalla_win(){
    int x,y;

    mocultar();
    if(win==3){
        setlinestyle(0,0,3);
        setcolor(LIGHTMAGENTA);
        rectangle(130,70,510,410);
        setfillstyle(1,DARKGRAY);
		bar(130,70,510,410);
        if (bool1==2){
            settextstyle(0,0,2);
		    setcolor(LIGHTMAGENTA);
		    outtextxy(240,160,"GANA EL PC");
        }else if(bool1==1){
            settextstyle(0,0,2);
		    setcolor(LIGHTMAGENTA);
		    outtextxy(145,160,"EL GANADOR ES PLAYER 1");
        }
		

		setlinestyle(0,0,3);
        setcolor(LIGHTMAGENTA);
        rectangle(162,340,278,360);
        rectangle(335,340,468,360);
        setfillstyle(1,DARKGRAY);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		bar(162,340,278,360);
        bar(335,340,468,360);
        setcolor(LIGHTMAGENTA);
		outtextxy(165,345,"Jugar de nuevo");
		outtextxy(338,345,"Regresar al menu");

    }else if (lose==3){
        setlinestyle(0,0,3);
        setcolor(GREEN);
        rectangle(130,70,510,410);
        setfillstyle(1,DARKGRAY);
        bar(130,70,510,410);
        if (bool1==2){
            settextstyle(0,0,2);
		    setcolor(GREEN);
		    outtextxy(240,160,"GANA EL PC");
        }else if(bool1==3){
            settextstyle(0,0,2);
		    setcolor(GREEN);
		    outtextxy(145,160,"EL GANADOR ES PLAYER 2");
        }
		

        setlinestyle(0,0,3);
        setcolor(GREEN);
        rectangle(162,340,278,360);
        rectangle(335,340,468,360);
        setfillstyle(1,DARKGRAY);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		bar(162,340,278,360);
        bar(335,340,468,360);
        setcolor(GREEN);
		outtextxy(165,345,"Jugar de nuevo");
		outtextxy(338,345,"Regresar al menu");

    }else{
         setlinestyle(0,0,3);
        setcolor(WHITE);
        rectangle(130,70,510,410);
        setfillstyle(1,DARKGRAY);
        bar(130,70,510,410);
		settextstyle(0,0,3);
		setcolor(WHITE);
		outtextxy(270,160,"EMPATE");

        setlinestyle(0,0,3);
        setcolor(WHITE);
        rectangle(162,340,278,360);
        rectangle(335,340,468,360);
        setfillstyle(1,DARKGRAY);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		bar(162,340,278,360);
        bar(335,340,468,360);
        setcolor(WHITE);
		outtextxy(165,345,"Jugar de nuevo");
		outtextxy(338,345,"Regresar al menu");
    }
    mver();
    do{
        while(mclick()!=1){
			x=mxpos(1);
			y=mypos(1);
		}

        if(limit(x,y,160,335,280,365)){
            mocultar();
            ajustes();
        }else if(limit(x,y,330,335,470,365)){
            mocultar();
            pantalla_princip();
        }
    }while(1);
  
	  
  }
void Windows(void)
{
	int i, j, x, y;
	
	
    int logo[4][10] =  {{288,159,   318,155,    318,182,    287,182,    288,159},   
	{321,155,   359,149,    359,182,    321,182,    321,155},   
	{288,185,   318,185,    318,212,    287,208,    288,185},  
	{321,185,   359,185,    359,217,    321,212, 321,185}};
	
	int charger[2][50] = {  {320,321,323,325,326,327,327,327,327,326,324,322,321,319,317,315,313,312,312,312,312,313,314,316,317,   320,321,323,325,326,327,327,327,327,326,324,322,321,319,317,315,313,312,312,312,312,313,314,316,317},
                            {368,368,369,370,371,373,375,377,379,381,382,383,384,384,383,382,381,379,377,375,373,371,370,369,368,   368,368,369,370,371,373,375,377,379,381,382,383,384,384,383,382,381,379,377,375,373,371,370,369,368}};



    settextstyle(SMALL_FONT,HORIZ_DIR,5);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,LIGHTCYAN);

    for(i=0;i<4;i++)
        fillpoly(5,logo[i]);

    for(j=0;j<4;j++)
        for (i=0;i<25;i++)
        {
            putpixel(charger[0][i+1],charger[1][i+1],WHITE);
            putpixel(charger[0][i+3],charger[1][i+3],WHITE);
            putpixel(charger[0][i+6],charger[1][i+6],WHITE);
            putpixel(charger[0][i+9],charger[1][i+9],WHITE);


            putpixel(charger[0][i],charger[1][i],BLACK);
            putpixel(charger[0][i+2],charger[1][i+2],BLACK);
            putpixel(charger[0][i+5],charger[1][i+5],BLACK);
            putpixel(charger[0][i+8],charger[1][i+8],BLACK);

            if(i>10||i<1)
				delay(1 * duration);
            else
				delay(1 * duration);
			
        }
}
void salir(){
     initgraph(&driver,&mode," ");
    screen();

}
void flag(){
    initgraph(&driver,&mode," ");
    setcolor(LIGHTGRAY);
	outtextxy(200,250,">Instalando actulizaciones...<");
    Windows();
    closegraph();
}
void present(void)
{
    initgraph(&driver,&mode," ");
	
	setcolor(LIGHTMAGENTA);
	outtextxy(260, 50, "Presentacion");
	outtextxy(214, 88, "Ingenieria en Computacion");
	outtextxy(276, 123, "Juego XO");
	setcolor(LIGHTCYAN);
	outtextxy(260, 161, "Integrantes:");
	outtextxy(157, 197, "Krystell Melissa Gomez Casstillo 2021-0095U");
	outtextxy(185, 234, "Guillermo Ernesto Castillo 2020-0379U");
	outtextxy(151, 269, "Francisco Ernesto Castillo Duarte 2020-0399U");
	outtextxy(144, 305, "Christopher Alexander Herrera Ortega 2020-0261");
	setcolor(YELLOW);
	outtextxy(258, 341, "Grupo: 1M2-CO");
	outtextxy(230, 376, "30 de Noviembre 2021");
    getch();
    closegraph();
    
}