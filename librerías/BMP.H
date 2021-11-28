#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<graphics.h>
#include<mouse.h>
#include<dos.h>


FILE * BMP;

/*Declaración de variables*/
 long BIT_PIXEL, PIXEL_BIT,CUERPO, PALETA, PALETA_TAM, TAM_X, TAM_Y;
 typedef struct	 /*Estructura para el color*/
  {
   unsigned char b, g, r, a;
  } Color;

 int getcol (void);
 int ShowBMP (char *fname, int x, int y);
 int huge detect(void);

 int ShowBMP (char *fname,int x, int y)
 /*Función que abre el archivo y despliega la imagen en el monitor*/
  {
   int color;
   int k, ypos, xpos;
   Color col;
   BMP = fopen (fname, "rb");
   if (BMP == NULL)
   return 1;
   fseek (BMP, 10, SEEK_SET);	/*Lectura de la cabecera*/
   fread (&CUERPO, sizeof (CUERPO), 1, BMP);
   fseek (BMP, 18, SEEK_SET);
   fread (&TAM_X, sizeof (TAM_X), 1, BMP);
   fseek (BMP, 22, SEEK_SET);
   fread (&TAM_Y, sizeof (TAM_Y), 1, BMP);
   fseek (BMP, 28, SEEK_SET);
   fread (&BIT_PIXEL, sizeof (BIT_PIXEL), 1, BMP);
   PIXEL_BIT = 8 / BIT_PIXEL;
   PALETA_TAM = 1 << BIT_PIXEL;
   PALETA = CUERPO - 4 * PALETA_TAM;
   fseek (BMP, PALETA, SEEK_SET);
   for (k = 0; k < PALETA_TAM; k++)
   /*Cargando la paleta de colores*/
	{
	 fread (&col, sizeof (col), 1, BMP);
	 setrgbpalette (k, (col.r) >> 2, (col.g) >> 2, (col.b) >> 2);
	}
   ypos=y;
   xpos=x;
   for (y = ypos+TAM_Y - 1; y >= ypos; y--)
   /*Despliega la imagen en el*/
   for (x = xpos; x < xpos+TAM_X; x++)
   /*monitor*/
   putpixel (x, y, getcol ());
   return 0;
  }

  int getcol (void)
  /*Función que regresa el color*/
   {
	/*del pixel de acuerdo a sus componentes RGB*/
	static int x = 0;
	static int n = 0;
	static long int col[4];
	unsigned char b;
	if (x >= TAM_X)
	 {
	  x = 0;
	  while (n % 4)
	   {
		fread (&b, sizeof (b), 1, BMP);
		n++;
	   }
	  n = 0;
	 }
	if (x % PIXEL_BIT == 0)
	 {
	  int k = PIXEL_BIT;
	  int mask = (1 << BIT_PIXEL) - 1;
	  fread (&b, sizeof (b), 1, BMP);
	  n++;
	  while (k--)
	   {
		col[k] = b & mask;
		b >>= BIT_PIXEL;
	   }
	 }
return col[x++ % PIXEL_BIT];
}

 int huge detect()
  {
   return 2;
  }