#include<mouse.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<GRAPHICS.h>
#include<time.h>
#include<button.h>

void reloj(void);
struct tm *outtime;
time_t hora;
int i=0;
button boton1;

void main(){
    
    int driver=DETECT, mode, color,modo,mposx,mposy,fill,past_color;
    
    initgraph(&driver,&mode," ");
    setbkcolor(GREEN);
    setcolor(WHITE);
	rectangle(0, 0, 800, 20);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    floodfill(10,10, WHITE);
	newButton(&boton1,2,2," XO ");
    
    
    while(i<1){
        time(&hora);
        outtime = localtime(&hora);
        setcolor(BLACK);
        outtextxy(500, 3, ("%.19s\n",asctime(outtime)));
        delay(1000);
        bar(500,0,650,19);
        setfillstyle(SOLID_FILL,LIGHTBLUE);
        mver();
        }
    
    
    do{
		while(mclick()!=1){
			mposx=mxpos(1);
			mposy=mypos(1);
		}
		while(mclick()==1){
			if(limit(mposx,mposy,boton1.x1,boton1.y1,boton1.x2,boton1.y2)){
				mocultar();
				effect3d(boton1.x1,boton1.y1,boton1.x2,boton1.y2,1,DEPRESSED);
				setcolor(WHITE);
				outtextxy(250,250,"HOLA VAMO A JUGAR?");
				mver();
			}
		}
		effect3d(boton1.x1,boton1.y1,boton1.x2,boton1.y2,1,ELEVATE);
	}while(getch()==' ');
}