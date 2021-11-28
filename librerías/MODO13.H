
//////////////////////////////////////////////////////////////////
//                                                              //
//                  Libreria para el modo 13h                   //
//                   320 x 200 x 256 colores                    //
//                         Creada por:                          //
//                Leonardo Fabio Castillo Garcia                //
//                           LEFFAK                             //
//              Planeta Rica - Cordoba - Colombia               //
//               Funciona bien en Turbo C++ 3.0                 //
//                 Email: leffak@terra.com.co                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef MODO13_H
#define MODO13_H

#ifndef unstype
#define unstype
typedef unsigned char BYTE;
typedef unsigned int  WORD;
typedef unsigned long DWORD;
#endif

//  direccion de la pantalla de video, es la misma para cualquier modo de video
#define            pvideo   (BYTE far *)0xA0000000
BYTE far *pdefecto=pvideo;
BYTE cdefecto=15;
WORD xlimitemin=0,ylimitemin=0,xlimitemax=319,ylimitemax=199;
class nodorellenar
{
  friend void rellenar(int,int,BYTE,BYTE far*);
  short i,j;
  BYTE y;
  int x;
  nodorellenar *sig,*ant;
};
#ifndef VABS
#define VABS
template <class T> inline T vabs(T val){return (val<0)?-val:val;}
#endif
void setmode(unsigned short mode)
{
  asm mov ax,[mode]
  asm int 10h
}
BYTE getmode()
{
  asm mov ah,0fh
  asm int 10h
  return _AL;
}
inline void modog()
{
  setmode(0x13);
}
inline void modot()
{
  setmode(0x3);
}
void setareag(WORD x1,WORD y1,WORD x2,WORD y2)
{
  if(x1>=x2||y1>=y2||x2>=320||y2>=200)
    return;
  xlimitemin=x1;
  ylimitemin=y1;
  xlimitemax=x2;
  ylimitemax=y2;
}
inline void putpixel(unsigned x,unsigned y,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  if(x>=xlimitemin&&y>=ylimitemin&&x<=xlimitemax&&y<=ylimitemax)
    donde[y*320+x]=color;
}
inline BYTE getpixel(unsigned x,unsigned y,BYTE far *donde=pdefecto)
{
  return donde[y*320+x];
}
//  esta funcion es muy lenta y no se si funciona con pantallas virtuales
//  pero la dejo porsiacaso
void limpiar(BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  unsigned segmento,desplazamiento;
  segmento=((unsigned)(void _seg *)(void far *)(donde));
  desplazamiento=((unsigned)(donde));
  asm mov es,segmento
  asm mov di,desplazamiento
  asm mov al,[color]
  asm mov ah,al
  asm mov dx,ax
  asm db 66h
  asm shl ax,16
  asm mov cx,16000
  asm mov ax,dx
  asm db 0F3h,66h,0ABh
}
//  esta cambia las propiedades de un color
void setVGAreg(int reg_no,char rojo,char verde,char azul)
{
  asm mov ax,1010h
  asm mov bx,reg_no
  asm mov ch,verde
  asm mov cl,azul
  asm mov dh,rojo
  asm int 10h
}
//  este es el famoso retraso vertical
void retrasovert()
{
  asm mov dx,3dah
  atras1:
  asm in al,dx
  asm test al,8h
  asm jnz atras1
  atras2:
  asm in al,dx
  asm test al,8h
  asm jz atras2
}
void linea(float x1,float y1,float x2,float y2,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  if(y1>=200&&y2>=200)return;
  if(x1>=320&&x2>=320)return;
  putpixel(x1,y1,color,donde);
  putpixel(x2,y2,color,donde);
  if(vabs(x2-x1)<1.0&&vabs(y2-y1)<1.0)return;
  linea(x1,y1,(x1+x2)/2.0,(y1+y2)/2.0,color,donde);
  linea(x2,y2,(x1+x2)/2.0,(y1+y2)/2.0,color,donde);
}
void cuadro(int x1,int y1,int x2,int y2,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  int i;
  for(i=x1;i<=x2;i++)
    putpixel(i,y1,color,donde);
  for(i=x1;i<=x2;i++)
    putpixel(i,y2,color,donde);
  for(i=y1;i<=y2;i++)
    putpixel(x1,i,color,donde);
  for(i=y1;i<=y2;i++)
    putpixel(x2,i,color,donde);
}
void barra(int x1,int y1,int x2,int y2,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  int i,j;
  for(i=x1;i<=x2;i++)
    for(j=y1;j<=y2;j++)
      putpixel(i,j,color,donde);
}
void aro(int x,int y,int rmayor,int rmenor,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  int i,j;
  if(rmayor<rmenor||rmayor<=0||rmenor<0)return;
  for(i=-rmayor;i<=0;i++)
  {
    for(j=-rmayor;j<=0;j++)
    {
      if((float)i*(float)i+(float)j*(float)j<=(float)rmayor*(float)rmayor&&(float)i*(float)i+(float)j*(float)j>=(float)rmenor*(float)rmenor)
      {
        putpixel(x+i,y+j,color,donde);
        putpixel(x-i,y-j,color,donde);
        putpixel(x+i,y-j,color,donde);
        putpixel(x-i,y+j,color,donde);
      }
    }
  }
}
inline void circunferencia(int x,int y,int r,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  aro(x,y,r,r-1,color,donde);
}
inline void circulo(int x,int y,int r,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  aro(x,y,r,0,color,donde);
}
void aromayor(int x,int y,int rmayor,int rmenor,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  int i,j;
  if(rmayor<rmenor||rmayor<=0||rmenor<0)return;
  for(i=-rmayor;i<=0;i++)
  {
    for(j=-rmayor;j<=0;j++)
    {
      if((float)i*(float)i+(float)j*(float)j<=(float)rmayor*(float)rmayor&&(float)i*(float)i+(float)j*(float)j>=(float)rmenor*(float)rmenor)
      {
        if(getpixel(x+i,y+j,donde)<color)
          putpixel(x+i,y+j,color,donde);
        if(getpixel(x-i,y-j,donde)<color)
          putpixel(x-i,y-j,color,donde);
        if(getpixel(x+i,y-j,donde)<color)
          putpixel(x+i,y-j,color,donde);
        if(getpixel(x-i,y+j,donde)<color)
          putpixel(x-i,y+j,color,donde);
      }
    }
  }
}
inline void circunferenciamayor(int x,int y,int r,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  aromayor(x,y,r,r-1,color,donde);
}
inline void circulomayor(int x,int y,int r,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  aromayor(x,y,r,0,color,donde);
}
void aromenor(int x,int y,int rmayor,int rmenor,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  int i,j;
  if(rmayor<rmenor||rmayor<=0||rmenor<0)return;
  for(i=-rmayor;i<=0;i++)
  {
    for(j=-rmayor;j<=0;j++)
    {
      if((float)i*(float)i+(float)j*(float)j<=(float)rmayor*(float)rmayor&&(float)i*(float)i+(float)j*(float)j>=(float)rmenor*(float)rmenor)
      {
        if(getpixel(x+i,y+j,donde)>color)
          putpixel(x+i,y+j,color,donde);
        if(getpixel(x-i,y-j,donde)>color)
          putpixel(x-i,y-j,color,donde);
        if(getpixel(x+i,y-j,donde)>color)
          putpixel(x+i,y-j,color,donde);
        if(getpixel(x-i,y+j,donde)>color)
          putpixel(x-i,y+j,color,donde);
      }
    }
  }
}
inline void circunferenciamenor(int x,int y,int r,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  aromenor(x,y,r,r-1,color,donde);
}
inline void circulomenor(int x,int y,int r,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  aromenor(x,y,r,0,color,donde);
}
void putimg(int x,int y,BYTE far *img,BYTE dir,int ign=0,BYTE far *donde=pdefecto)
{
  int xl,yl,i,j,dx,dy,xpos,ypos;
  xl=(int)img[0];
  yl=(int)img[1];
  for(i=0;i<xl;i++)
  {
    for(j=0;j<yl;j++)
    {
      dx=((dir&1)?(xl-(i+1)):(i));
      dy=((dir&2)?(yl-(j+1)):(j));
      if(dir&4)
      {
        xpos=x+dy;
        ypos=y+dx;
      }
      else
      {
        xpos=x+dx;
        ypos=y+dy;
      }
      if((int)img[i+j*xl+2]!=ign)
      {
          putpixel(xpos,ypos,img[i+j*xl+2],donde);
      }
    }
  }
}
void getimg(unsigned x1,unsigned y1,unsigned x2,unsigned y2,BYTE far *img,BYTE far *donde=pdefecto)
{
  unsigned i,j;
  if(x1>=x2||y1>=y2||x2-x1>255||y2-y1>255)
    return;
  img[0]=1+x2-x1;
  img[1]=1+y2-y1;
  for(i=0;i<img[0];i++)
  {
    for(j=0;j<img[1];j++)
    {
      if(i+x1<320&&j+y1<200)
        img[i+j*img[0]+2]=getpixel(i+x1,j+y1,donde);
      else
        img[i+j*img[0]+2]=0;
    }
  }
}
//  esta no funciona bien en areas abiertas porque se queda sin memoria
void rellenar(int x,int y,BYTE color=cdefecto,BYTE far *donde=pdefecto)
{
  BYTE c;
  nodorellenar *pr=0;
  c=getpixel(x,y,donde);
  if(c==color)
    return;
  pr=new nodorellenar;
  if(!pr)return;
  putpixel(x,y,color,donde);
  pr->x=x;
  pr->y=y;
  pr->i=-1;
  pr->j=-1;
  pr->sig=0;
  pr->ant=0;
  while(1)
  {
    for(;pr->i<2;pr->i++)
    {
      for(pr->j=-1;pr->j<2;pr->j++)
      {
        if(pr->x+pr->i>=xlimitemin&&pr->y+pr->j>=ylimitemin&&pr->x+pr->i<=xlimitemax&&pr->y+pr->j<=ylimitemax&&(pr->j!=0||pr->i!=0)&&(pr->j==0||pr->i==0))
        {
          if(getpixel(pr->x+pr->i,pr->y+pr->j,donde)==c)
          {
            putpixel(pr->x+pr->i,pr->y+pr->j,color,donde);
            pr->sig=new nodorellenar;
            if(pr->sig)
            {
              pr->sig->ant=pr;
              pr=pr->sig;
              pr->x=pr->ant->x+pr->ant->i;
              pr->y=pr->ant->y+pr->ant->j;
              pr->i=-2;
              break;
            }
          }
        }
      }
    }
    if(pr->ant)
    {
      pr=pr->ant;
      delete pr->sig;
      pr->i++;
    }
    else
    {
      delete pr;
      return;
    }
  }
}
#endif