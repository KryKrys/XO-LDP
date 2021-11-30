#include<mouse.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<GRAPHICS.h>
#include<time.h>
#include<button.h>

void main(){
    int driver=DETECT, mode;
    initgraph(&driver,&mode," ");
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

    
    getch();


}