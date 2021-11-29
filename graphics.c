#include<mouse.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<button.h>

void ajustes(void);
void pantalla_princip(void);
void pantalla_juego(void);

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

    setfillstyle(LINE_FILL,WHITE);
    bar(20,280,220,420);
    setfillstyle(SOLID_FILL,CYAN);
    bar(40,300,200,400);

    settextstyle(0,0,3);
    outtextxy(290,110,"P1 vs PC");
    outtextxy(290,190,"P1 vs P2");
    outtextxy(55,335,"Jugar!");
    newButton(&vspc,510,110," On  ",LIGHTGRAY,GREEN);
    newButton(&p1p2,510,190," Off ",LIGHTGRAY,RED);
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
            newButton(&p1p2,510,190," OFF ",LIGHTGRAY,RED);
            newButton(&vspc,510,110," ON  ",LIGHTGRAY,GREEN);
            effect3d(vspc.x1,vspc.y1,vspc.x2,vspc.y2,1,DEPRESSED);
            effect3d(p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2,1,ELEVATE);
        } else if (limit(x,y,p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2)){
            newButton(&vspc,510,110," OFF ",LIGHTGRAY,RED);
            newButton(&p1p2,510,190," ON  ",LIGHTGRAY,GREEN);
            effect3d(vspc.x1,vspc.y1,vspc.x2,vspc.y2,1,ELEVATE);
            effect3d(p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2,1,DEPRESSED);
        }else if (limit(x,y,35,295,205,405)){
            mocultar();
            pantalla_juego();
        }


    }while(1);

}

void pantalla_juego(){
    int x,y;
    button boton1;
    clrscr();
    setbkcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,0,640,480);

    setcolor(WHITE);
    rectangle(170,90,470,390);
    line(270,90,270,390);
    line(375,90,375,390);
    line(170,190,470,190);
    line(170,290,470,290);

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(10,10,90,40);
    setcolor(DARKGRAY);
    line(24,25,80,25);
    line(24,25,43,35);
    line(24,25,43,15);
    
    /*newButton(&boton1,100,100,"Ajustes",LIGHTGRAY,WHITE);*/
    mver();

    do{
		while(mclick()!=1){
			x=mxpos(1);
			y=mypos(1);
		}
	
		if(limit(x,y,5,5,95,45)){
            mocultar();
            pantalla_princip();
        }

	}while(1);
}

    