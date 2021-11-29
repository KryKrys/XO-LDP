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
button boton1, boton2, boton3;

void main(){
    
    int driver=DETECT, mode, color,modo,mposx,mposy,fill,past_color;
    
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
                reloj();
            
            
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
				setcolor(RED);
				outtextxy(250,250,"HOLA VAMO A JUGAR?");
				mver();
                
			}
		}
        do{
            reloj();
        }while(!kbhit());
		effect3d(boton1.x1,boton1.y1,boton1.x2,boton1.y2,1,ELEVATE);
	}while(getch()==' ');
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