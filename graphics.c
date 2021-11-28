#include<mouse.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<button.h>

void main(){
    int driver=DETECT,modo,x,y;
    button boton1;
    initgraph(&driver,&modo,"");
    newButton(&boton1,100,100,"Ajustes");
    setbkcolor(DARKGRAY);
    rectangle(170,90,470,390);
    /*verticales*/
    line(270,90,270,390);
    line(375,90,375,390);
    /*horizontales*/
    line(170,190,470,190);
    line(170,290,470,290);
    

    do{
		while(mclick()!=1){
			x=mxpos(1);
			y=mypos(1);
		}
		while(mclick()==1){
			if(limit(x,y,boton1.x1,boton1.y1,boton1.x2,boton1.y2)){
				mocultar();
				effect3d(boton1.x1,boton1.y1,boton1.x2,boton1.y2,1,DEPRESSED);
				setcolor(WHITE);
				outtextxy(300,300,"Hola B(");
				mver();
			}
		}
		effect3d(boton1.x1,boton1.y1,boton1.x2,boton1.y2,1,ELEVATE);
	}while(getch()==' ');
    getch();
    closegraph();
}