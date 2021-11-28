#include<mouse.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<button.h>

void main(){
    int driver=DETECT,modo=VGAHI,x,y;
    /*button boton1;*/
    initgraph(&driver,&modo,"");
    /*fondo*/
    setbkcolor(LIGHTGRAY);
    setcolor(WHITE);

    /*letras*/
    setcolor(BLUE);
    settextstyle(DEFAULT_FONT,0,5);
    outtextxy(100,20,"Tic");
    setcolor(LIGHTBLUE);
    outtextxy(250,20,"Tac");
    setcolor(CYAN);
    outtextxy(400,20,"Toe");
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
    bar(200,100,310,400);

    getch();



    /*rectangle(170,90,470,390);
    /*verticales*
    line(270,90,270,390);
    line(375,90,375,390);
    /*horizontales*
    line(170,190,470,190);
    line(170,290,470,290);
    
    newButton(&boton1,100,100,"Ajustes");
    mver();

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
				outtextxy(100,120,"Hola B(");
				mver();
			}
		}
		effect3d(boton1.x1,boton1.y1,boton1.x2,boton1.y2,1,ELEVATE);
	}while(mclick()!=2);*/
    closegraph();
}