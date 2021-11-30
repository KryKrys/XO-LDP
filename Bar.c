#include<mouse.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<GRAPHICS.h>
#include<time.h>
#include<button.h>

#define duration 33

int driver=DETECT, mode, color,modo,mposx,mposy,fill,past_color;
struct tm *outtime;
    time_t hora;
    int i,x,y;
    button boton1, boton2, boton3;
void reloj(void);
void ajustes(void);
void pantalla_princip(void);
void screen(void);
void Windows(void);
void salir(void); 



void main(){
    initgraph(&driver,&mode," ");
	Windows();
    screen();
    reloj();
    pantalla_princip();
    salir();
    ajustes();
    mver();

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
				setcolor(RED);
				outtextxy(250,250,"LESBIAN OS");
				mver();
                
			}else if(limit(mposx,mposy,30,450,60,480)){
				mocultar();
				setcolor(RED);
				outtextxy(250,250,">Insertar presentacion aqui<");
				mver();

            }else if(limit(mposx,mposy,80,450,100,480)){
                mocultar();
				mver();
                pantalla_princip();
                
                
			}
		}
        
        
		effect3d(boton1.x1,boton1.y1,boton1.x2,boton1.y2,1,ELEVATE);
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
            clrscr();
            ajustes();
        }

        if(limit(x,y,215,255,425,325)){
            mocultar();
            clrscr();   
            salir();
            }

    }while(1);
    
}void ajustes(){
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
				delay(5 * duration);
            else
				delay(3 * duration);
			
        }
}

void salir(){
    getch();
    clrscr();
    screen();

}