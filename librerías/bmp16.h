char colpix(char c)
{

char op;
op=c;

switch(c)
{
case 1: op=4;break; /*BLUE --><-- RED*/
case 3: op=6;break; /*CYAN --><-- BROWN*/
case 4: op=1;break; /*RED --><-- BLUE*/
case 6: op=3;break; /*BROWN --><-- CYAN*/
case 7: op=8;break; /*LGRAY --><-- DGRAY*/
case 8: op=7;break; /*DGRAY --><-- LGRAY*/
case 9: op=12;break; /*LBLUE --><-- LRED*/
case 11: op=14;break; /*LCYAN --><-- YELLOW*/
case 12: op=9;break; /*RED --><-- LBLUE*/
case 14: op=11;break; /*YELLOW --><-- LCYAN*/
}
return op;
}

int bmp16(int x1,int y1,char *imagen,int col)
{
int cont=-1,tamx,tamy,c1,c2,x,y;
FILE *fp;
if((fp=fopen(imagen,"rb"))==NULL) return 0;

while(cont++<=117)
{
if(cont==18)
{
tamx=fgetc(fp)|fgetc(fp)<<8;
cont++;
}
else
{
if(cont==22)
{
tamy=fgetc(fp)|fgetc(fp)<<8;
cont++;
}
else
{fgetc(fp);}
}
}

for(y=tamy+y1-1;y>=y1;y--)
{
x=x1;
while(x<tamx+x1)
{ cont=0;
while(cont++<4)
{ c1=c2=fgetc(fp);
c1>>=4;c2=c2&15;
if(x++<tamx+x1) putpixel(x-1,y,(c1=colpix(c1))==col?getpixel(x,y):c1);
if(x++<tamx+x1) putpixel(x-1,y,(c2=colpix(c2))==col?getpixel(x,y):c2);
}
}
} fclose(fp);
return 1;
}