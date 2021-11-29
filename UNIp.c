#include<mouse.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<button.h>



 /*far _Cdecl bar(int left, int top, int right, int bottom);*/

void main(){
int driver=DETECT,modo=VGAHI,x,y;
	button boton1;
	
    initgraph(&driver,&modo,"");

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

	getch();
	closegraph();
	
}