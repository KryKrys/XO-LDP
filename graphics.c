#include<mouse.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<button.h>

void ajustes(void);
void pantalla_princip(void);

void main(){
    int driver=DETECT,modo=VGAHI;
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
            closegraph();
            exit(0);
        }

    }while(1);
}

void ajustes(){
    int x,y;
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
    newbutton(&vspc,530,110,"v",LIGHTGRAY,BLACK);
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

        if(limit())

    }while(1);

}

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