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
	/*vertical*/
	 bar(160,150,100,390);
	 /*horizontal*/
	 bar(160,330,340,390);
	 /*fin colita u*/
	 bar(280,236,340,390);
	 
	 /*inicio n*/
	 bar(250,150,185,310);
	  /*horizontal*/
	 bar(190,150,400,210);
	 /*vertical*/
	 bar(370,150,430,390);
	 
	 /*horizontal inicio i*/
	 bar(400,330,530,390);
	 /*vertical*/
	 bar(460,250,530,390);
	 /*punto i*/
	 bar(460,150,530,220);

	   getch();
	 closegraph();
	
}