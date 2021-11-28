#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	int Driver=VGA, Modo=VGAHI;
	initgraph(&Driver, &Modo, "c:\\tc3\\bgi");
	do
	{
	 line(185, 67, 185, 333);
	 line(323, 67, 323, 333);
	 line(74, 162, 436, 162);
	 line(74, 259, 436, 259);
	 getch();
	}while(!kbhit());
	closegraph();
}