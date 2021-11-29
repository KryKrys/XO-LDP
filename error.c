#include<mouse.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<GRAPHICS.h>
#include<time.h>
#include<button.h>


int driver=DETECT, mode, color,modo,mposx,mposy,fill,past_color;
struct tm *outtime;
    time_t hora;
    int i=0;
    button boton1, boton2, boton3;
void reloj(void);
void ajustes(void);
void pantalla_princip(void);
void screen(void);

void main(){
    initgraph(&driver,&mode," ");
    screen();
    reloj();
    pantalla_princip();
    ajustes();
    mver();

}

     void screen(){
        initgraph(&driver,&mode," ");
        setbkcolor(BLACK);
         setcolor(LIGHTGRAY);
	    rectangle(0, 450, 800, 480);
         setfillstyle(SOLID_FILL,LIGHTGRAY);
        floodfill(5,450+10, WHITE);
	    newButton(&boton1,10,456," LESBIAN ", BLUE, WHITE);
        newButton(&boton2,75,456," PPX ", BLUE, WHITE);
        newButton(&boton3,115,456," XO ", BLUE, WHITE);
        mver();
    do{
		while(mclick()!=1){
			mposx=mxpos(1);
			mposy=mypos(1);
                /*reloj();*/
            
            
		}
		while(mclick()==1){
            
			if(limit(mposx,mposy,boton1.x1,boton1.y1,boton1.x2,boton1.y2)){
				mocultar();
				effect3d(boton1.x1,boton1.y1,boton1.x2,boton1.y2,1,DEPRESSED);
				setcolor(RED);
				outtextxy(250,250,"LESBIAN OS");
				mver();
                
			}else if(limit(mposx,mposy,boton2.x1,boton2.y1,boton2.x2,boton2.y2)){
				mocultar();
				effect3d(boton2.x1,boton2.y1,boton2.x2,boton2.y2,1,DEPRESSED);
				setcolor(RED);
				outtextxy(250,250,">Insertar presentacion aqui<");
				mver();

            }else if(limit(mposx,mposy,boton3.x1,boton3.y1,boton3.x2,boton3.y2)){
                mocultar();
				effect3d(boton3.x1,boton3.y1,boton3.x2,boton3.y2,1,DEPRESSED);
				mver();
                pantalla_princip();
                
			}
		}
        /*do{
            reloj();
        }while(getch()==' ');*/
		effect3d(boton1.x1,boton1.y1,boton1.x2,boton1.y2,1,ELEVATE);
	}while(1);
    getch();
    }


void reloj(){
    
        time(&hora);
        outtime = localtime(&hora);
        setcolor(BLACK);
        outtextxy(500, 460, ("%.19s\n",asctime(outtime)));
        delay(1000);
        bar(500,450,650,480);
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
    line(550,20,590,60);
    line(590,20,550,60);
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
            clrscr();   
            screen();
            }

    }while(1);
    
}

void ajustes(){
    int x,y;
    char on[3]="On",off[4]="Off";

    button vspc, p1p2;
    clrscr();
    setbkcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(0,0,640,480);

    /*menu*/
    setfillstyle(LINE_FILL,WHITE);
    bar(250,70,570,420);
    setfillstyle(SOLID_FILL,CYAN);
    bar(270,90,550,400);
    setcolor(DARKGRAY);
    settextstyle(0,0,4);
    outtextxy(250,20,"Modalidad");
    /*regresar*/
    setfillstyle(SOLID_FILL,CYAN);
    bar(10,10,90,40);
    setcolor(DARKGRAY);
    line(24,25,80,25);
    line(24,25,43,35);
    line(24,25,43,15);

    settextstyle(0,0,3);
    outtextxy(290,110,"P1 vs PC");
    outtextxy(290,190,"P1 vs P2");
    newButton(&vspc,510,110," On  ",LIGHTGRAY,DARKGRAY);
    newButton(&p1p2,510,190," Off ",LIGHTGRAY,DARKGRAY);
    mver();
    do{
        while(mclick()!=1){
            x = mxpos(1);
            y = mypos(1);
        }

        if(limit(x,y,5,5,95,45)){
            mocultar();
            pantalla_princip();
        }

        if(limit(x,y,vspc.x1,vspc.y1,vspc.x2,vspc.y2)){
            newButton(&p1p2,510,190," OFF ",LIGHTGRAY,RED);
            newButton(&vspc,510,110," ON  ",LIGHTGRAY,GREEN);
            /*effect3d(vspc.x1,vspc.y1,vspc.x2,vspc.y2,1,DEPRESSED);
            effect3d(p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2,1,ELEVATE);*/
        }

        if (limit(x,y,p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2)){
            newButton(&vspc,510,110," OFF ",LIGHTGRAY,RED);
            newButton(&p1p2,510,190," ON  ",LIGHTGRAY,GREEN);
            /*effect3d(vspc.x1,vspc.y1,vspc.x2,vspc.y2,1,ELEVATE);
            effect3d(p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2,1,DEPRESSED);*/
        }

    }while(1);

}
