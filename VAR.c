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
    setbkcolor(BLACK);
    setcolor(WHITE);
	rectangle(0, 450, 800, 480);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill(5,450+10, WHITE);
	newButton(&boton1,2,455," XO ");
    
    
    while(i<1){
        time(&hora);
        outtime = localtime(&hora);
        setcolor(BLACK);
        outtextxy(500, 460, ("%.19s\n",asctime(outtime)));
        delay(1000);
        bar(500,450,650,480);
        setfillstyle(SOLID_FILL,LIGHTGRAY);
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