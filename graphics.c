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
    bar(20,70,340,420);
    setfillstyle(SOLID_FILL,CYAN);
    bar(40,90,320,400);
    setcolor(DARKGRAY);
    settextstyle(0,0,4);
    outtextxy(200,20,"Modalidad");
    /*regresar*/
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(20,10,100,40);
    setcolor(LIGHTGRAY);
    line(34,25,90,25);
    line(34,25,53,35);
    line(34,25,53,15);
    
    /*jugar*/
    setfillstyle(LINE_FILL,WHITE);
    bar(390,180,590,320);
    setfillstyle(SOLID_FILL,CYAN);
    bar(410,200,570,300);

    settextstyle(0,0,3);
    outtextxy(60,150,"P1 vs PC");
    outtextxy(60,300,"P1 vs P2");
    outtextxy(420,235,"Jugar!");
    newButton(&vspc,280,160," ON  ",LIGHTGRAY,GREEN);
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
            newButton(&vspc,280,160," ON  ",LIGHTGRAY,GREEN);
            effect3d(vspc.x1,vspc.y1,vspc.x2,vspc.y2,1,DEPRESSED);
            effect3d(p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2,1,ELEVATE);
        } else if (limit(x,y,p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2)){
            newButton(&vspc,280,160," OFF ",LIGHTGRAY,RED);
            newButton(&p1p2,280,310," ON  ",LIGHTGRAY,GREEN);
            effect3d(vspc.x1,vspc.y1,vspc.x2,vspc.y2,1,ELEVATE);
            effect3d(p1p2.x1,p1p2.y1,p1p2.x2,p1p2.y2,1,DEPRESSED);
        }else if (limit(x,y,405,195,575,305)){
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
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(0,0,640,480);

    /*cuadricula*/
    setcolor(WHITE);
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

    do{
		while(mclick()!=1){
			x=mxpos(1);
			y=mypos(1);
		}
        setcolor(WHITE);
		if(limit(x,y,5,5,95,45)){
            mocultar();
            pantalla_princip();
        }else if(limit(x,y,170,90,270,190)){
            outtextxy(180,100,"0,0");
        }else if (limit(x,y,270,90,370,190)){
            outtextxy(280,100,"0,1");
        }else if (limit(x,y,370,90,470,190)){
            outtextxy(380,100,"0,2");
        }else if (limit(x,y,170,190,270,290)){
            outtextxy(180,200,"1,0");
        }else if(limit(x,y,270,190,370,290)){
            outtextxy(280,200,"1,1");
        }else if(limit(x,y,370,190,470,290)){
            outtextxy(380,200,"1,2");
        }else if(limit(x,y,170,290,270,390)){
            outtextxy(180,300,"2,0");
        }else if(limit(x,y,270,290,370,390)){
            outtextxy(280,300,"2,1");
        }else if(limit(x,y,370,290,470,390)){
            outtextxy(380,300,"2,2");
        }

	}while(1);
}

    