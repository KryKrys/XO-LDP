#include "recursos.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define BACKSPACE 8
#define ESPACE 255
#define ESC 27
#define S 115
#define N 110

#define PASSLONG 10
#define LONGITUD 12
#define MAX_INTENTOS 3
#define USUARIOS 2

void logo_uni(){
 /*a, b, c Dibujan u*/
 /*d, e, f Dibujan n*/
 /*h, i, j Dibujan i*/
 int ax, bx, cx, dx, ex, fx, hx, ix, jx; /* variables para eje x*/
 int ay, by, cy, dy, ey, fy, hy, iy, jy; /* variables para eje y*/

  /*a, b, c Dibujan u*/
 /*d, e, f Dibujan n*/
 /*h, i, j Dibujan i*/
 int a, b, c, d, e, f, h, i, j;
 int x;
  x=0;

      textcolor(WHITE);

    gotoxy(28,3);
    printf("C a r g a n d o . . .");

	  gotoxy( 39 , 24 );
    textcolor(WHITE);
  	cprintf("%d\n",x);  /* Porcentaje de 0 */
	  gotoxy( 38 , 24);
    cprintf("%");

   /* en cada for, se usa una variable controladora, no se usan fors anidados pues esto hará que se ejecute caracter a caracter y no es optimo */
   for(a=5;a<22;a+=1)
   {
        gotoxy(14 , a);
       delay(0100);
       textcolor(BLUE);
     cprintf("%c", 219, a);
      gotoxy(15 , a);
     cprintf("%c", 219, a);
      gotoxy(16 , a);
     cprintf("%c", 219, a);
     gotoxy(17 , a);
     cprintf("%c", 219, a);
     gotoxy(18 , a);
     cprintf("%c", 219, a);
     gotoxy(19 , a);
     cprintf("%c", 219, a);
	  }


   while(x<10)
    {
    	x+=10;
	    gotoxy( 39 , 24 );
      textcolor(WHITE);
  	  cprintf("%d\n",x); /* Porcentaje de 10 y aumenta de 10 en 10 en cada while siguiente*/
	    gotoxy( 38 , 24);
 	    cprintf("%");
	 }


   for(b=20;b<40;b+=1)
   {
        gotoxy(b , 19);
       delay(0100);
       textcolor(BLUE);
   cprintf("%c", 219, b);
    gotoxy(b , 20);
    cprintf("%c\n", 219, b);
    gotoxy(b , 21);
    cprintf("%c\n", 219, b);
   }

   while(x<20)
    {
    	x+=10;
	    gotoxy( 39 , 24 );
      textcolor(WHITE);
  	  cprintf("%d\n",x);
	    gotoxy( 38 , 24);
 	    cprintf("%");
	 }


   for(c=18;c>8;c-=1)
   {
        gotoxy(34 , c);
       delay(0100);
       textcolor(BLUE);
   cprintf("%c", 219, c);
    gotoxy(35 , c);
    cprintf("%c", 219, c);
    gotoxy(36 , c);
    cprintf("%c", 219, c);
   gotoxy(37 , c);
    cprintf("%c", 219, c);
    gotoxy(38 , c);
    cprintf("%c", 219, c);
    gotoxy(39 , c);
    cprintf("%c", 219, c);
   }

   while(x<30)
    {
    	x+=10;
	    gotoxy( 39 , 24);
      textcolor(WHITE);
  	  cprintf("%d\n",x);
	    gotoxy( 38 , 24);
 	    cprintf("%");
	 }

   for(d=16;d>4;d-=1)
   {
        gotoxy(24 , d);
       delay(0100);
       textcolor(BLUE);
   cprintf("%c", 219, d);
    gotoxy(25 , d);
    cprintf("%c", 219, d);
    gotoxy(26 , d);
    cprintf("%c", 219, d);
   gotoxy(27 , d);
    cprintf("%c", 219, d);
    gotoxy(28 , d);
    cprintf("%c", 219, d);
    gotoxy(29 , d);
    cprintf("%c", 219, d);
   }

    while(x<40)
    {
    	x+=10;
	    gotoxy( 39 , 24 );
      textcolor(WHITE);
  	  cprintf("%d\n",x);
	    gotoxy( 38 , 24);
 	    cprintf("%");
	 }


   for(e=25;e<50;e+=1)
   {
        gotoxy(e , 5);
       delay(0100);
       textcolor(BLUE);
   cprintf("%c", 219, e);
    gotoxy(e , 6);
    cprintf("%c\n", 219, e);
    gotoxy(e , 7);
    cprintf("%c\n", 219, e);
   }

   while(x<50)
    {
    	x+=10;
	    gotoxy( 39 , 24 );
      textcolor(WHITE);
  	  cprintf("%d\n",x);
	    gotoxy( 38 , 24);
 	    cprintf("%");
	 }

   for(f=5;f<22;f+=1)
   {
        gotoxy(44 , f);
       delay(0100);
       textcolor(BLUE);
     cprintf("%c", 219, f);
      gotoxy(45 , f);
     cprintf("%c", 219, f);
      gotoxy(46 , f);
     cprintf("%c", 219, f);
     gotoxy(47 , f);
     cprintf("%c", 219, f);
     gotoxy(48 , f);
     cprintf("%c", 219, f);
     gotoxy(49 , f);
     cprintf("%c", 219, f);
   }

    while(x<60)
    {
    	x+=10;
	    gotoxy( 39 , 24 );
      textcolor(WHITE);
  	  cprintf("%d\n",x);
	    gotoxy( 38 , 24);
 	    cprintf("%");
	 }

   for(h=50;h<61;h+=1)
   {
    gotoxy(h , 19);
    delay(0100);
    textcolor(BLUE);
    cprintf("%c", 219, h);
    gotoxy(h , 20);
    cprintf("%c\n", 219, h);
    gotoxy(h , 21);
    cprintf("%c\n", 219, h);
   }

   while(x<70)
    {
    	x+=10;
	    gotoxy( 39 , 24 );
      textcolor(WHITE);
  	  cprintf("%d\n",x);
	    gotoxy( 38 , 24);
	    cprintf("%");
	 }

   for(j=20;j>9;j-=1)
   {
        gotoxy(55 , j);
       delay(0100);
       textcolor(BLUE);
     cprintf("%c", 219, j);
      gotoxy(56 , j);
     cprintf("%c", 219, j);
      gotoxy(57 , j);
     cprintf("%c", 219, j);
     gotoxy(58 , j);
     cprintf("%c", 219, j);
     gotoxy(59 , j);
     cprintf("%c", 219, j);
     gotoxy(60 , j);
     cprintf("%c", 219, j);
   }


   while(x<80)
    {
    	x+=10;
	    gotoxy( 39 , 24 );
      textcolor(WHITE);
  	  cprintf("%d\n",x);
	    gotoxy( 38 , 24);
 	    cprintf("%");
	 }

   for(i=7;i>4;i-=1)
   {
        gotoxy(55 , i);
       delay(0100);
       textcolor(BLUE);
     cprintf("%c", 219, i);
      gotoxy(56 , i);
     cprintf("%c", 219, i);
      gotoxy(57 , i);
     cprintf("%c", 219, i);
     gotoxy(58 , i);
     cprintf("%c", 219, i);
     gotoxy(59 , i);
     cprintf("%c", 219, i);
     gotoxy(60 , i);
     cprintf("%c", 219, i);
   }

   while(x<91)
    {
    	x+=10;
	    gotoxy( 39 , 24 );
      textcolor(WHITE);
  	  cprintf("%d\n",x);
	    gotoxy( 38 , 24);
 	    cprintf("%");
         delay(0300);
	}
    
  gotoxy( 39 , 24 );
  textcolor(WHITE);
  cprintf("100\n");
	gotoxy( 38 , 24);
 	cprintf("%");

  textcolor(WHITE);
  gotoxy(18,3);
  printf("%c Presione cualquier tecla para continuar %c", 175, 174);
  getch();

  clrscr();

  textcolor(WHITE);
  gotoxy(25,3);
  printf("%c Bienvenido al sistema %c", 175,174);

  /* en cada for, se usan dos variables controladoras, pues son fors anidados. Esto se hace en el logo estático porque solo imprime, no hay delay*/
  for(ay=5;ay<22;ay+=1)
  {
    for (ax=14;ax<20;ax++)
   {
     gotoxy(ax , ay);
       textcolor(BLUE);
       cprintf("%c", 219);
   }
  }

  for(by=19;by<22;by++)
  {
   for(bx=20;bx<40;bx+=1)
   {
      gotoxy(bx,by);
      textcolor(BLUE);
      cprintf("%c", 219);
   }
  }

   for(cy=18;cy>8;cy-=1)
   {
    for(cx=34;cx<40;cx++)
    {
      gotoxy(cx, cy);
      textcolor(BLUE);
      cprintf("%c", 219);
    }
   }

   for(dy=16;dy>4;dy-=1)
   {
    for(dx=24;dx<30;dx++)
    {
      gotoxy(dx,dy);
     textcolor(BLUE);
     cprintf("%c", 219);
    }
   }

   for (ey=5;ey<8;ey++)
   {
    for(ex=25;ex<50;ex+=1)
    {
     gotoxy(ex,ey);
     textcolor(BLUE);
     cprintf("%c", 219);
    }
   }

   for(fy=5;fy<22;fy+=1)
   {
    for(fx=44;fx<50;fx++)
    {
       gotoxy(fx , fy);
       textcolor(BLUE);
       cprintf("%c", 219);
    }
   }

   for(hy=19;hy<22;hy++)
   {
    for(hx=50;hx<61;hx+=1)
    {
      gotoxy(hx , hy);
      textcolor(BLUE);
      cprintf("%c", 219);
    }
   }

   for(jy=20;jy>9;jy-=1)
   {
    for(jx=55;jx<61;jx++)
    {
      gotoxy(jx,jy);
      textcolor(BLUE);
      cprintf("%c", 219);
    }
   }

   for(iy=7;iy>4;iy-=1)
   {
    for(ix=55;ix<61;ix++)
    {
      gotoxy(ix , iy);
      textcolor(BLUE);
     cprintf("%c", 219);
    }
   }

   textcolor(WHITE);
   getch();

}

void presentacion() {				
 clrscr();
	gotoxy(25,2);
	textcolor(GREEN);
	cprintf("UNIVERSIDAD NACIONAL DE INGENERIA"); 
	delay(0100);
	 
  gotoxy(22,4);
  cprintf("FACULTAD DE ELECTROTECNIA Y COMPUTACION");
  delay(0100);
			 
  gotoxy(32,6);
  cprintf("NOMBRE DE LA CARRERA:");
  delay(0100);


	gotoxy(30,8);
	cprintf("INGENERIA EN COMPUTACION");
	delay(0100);
			 
	gotoxy(32,10);
	cprintf("NOMBRE DEL PROYECTO:");
	delay(0100);
			 
	gotoxy(37,11);
	cprintf("PEDRITO");
	delay(0100);
			 
	gotoxy(35,13);
	cprintf("INTEGRANTES:");
	delay(0100);
		 
	gotoxy(16,14);
	cprintf("GUILLERMO ERNESTO CASTILLO. No DE CARNET: 2020-0479U");
	delay(0100);
		 
	gotoxy(11,15);
	cprintf("CHRISTOPHER ALEXANDER HERRERA ORTEGA. No DE CARNET: 2020-0261U");
  delay(0100);
		
	gotoxy(16,16);
	cprintf("KRYSTELL MELISSA GOMEZ CASTILLO. No DE CARNET: 2021-0095U ");
	delay(0100);
			
	gotoxy(38,18);
	cprintf("GRUPO:");
	delay(0100);
			 
	gotoxy(38,20);
	cprintf("1M2-CO");
	delay(0100);
			 
 gotoxy(37,22);
	cprintf("DOCENTE:");
	delay(0100);
			 
	gotoxy(32,24);
  cprintf("ING. NELSON BARRIOS");
  delay(0100);
	getch();
    textcolor(WHITE);
}

void marco_pantalla (){

 int x,y;
  /* ////////barras del marco///////// */

 for (x=2;x<80;x++)
  {
   gotoxy(x,1);
   putchar(205);
   gotoxy(x,24);
   putchar(205);
  }

 for(y=2;y<24;y++)
  {
   gotoxy(1,y);
   putchar(186);
   gotoxy(80,y);
   putchar(186);
  }


 /* ///////esquinas del marco////////// */

  gotoxy(1,1);
  putchar(201);

  gotoxy(1,24);
  putchar(200);

  gotoxy(80,24);
  putchar(188);

  gotoxy(80,1);
  putchar(187);

}

int login() {
	char user[LONGITUD + 1];
	char pass[LONGITUD + 1];
	int intento = 0;
	int ingresa = 0;
	int bool_n;
	char caracter, tecla;
	int i = 0;
    int j = 0;

   /* Declaración e inicialización de arreglos*/
    char users[USUARIOS][LONGITUD + 1] = {"sudo", "user"};
    char password[USUARIOS][LONGITUD + 1] = {"linux", "1234"};


	/*Inicio del ciclo*/
	do {
		textcolor(WHITE);
		i = 0;
		clrscr();
		marco_pantalla();
		cuadro_login();
		gotoxy(33,4);
		printf("INICIO DE SESION");
		gotoxy(33,5);
		printf("---------------");
		gotoxy(25,14);
		textcolor(CYAN);
		cprintf("USER: ");
		gotoxy(45,14);
		while (tecla=getch()) {
			
			
			if (tecla==ENTER) {
				user[i] = '\0';
				break;

			}
			else if (tecla==BACKSPACE) {
				if (i > 0) {
					i--;
					printf("\b \b");
				}

			} else {
				if (i<PASSLONG) {
					printf("%c",tecla);
					user[i] = tecla;
					i++;
				}
			}
		}
		fflush(stdin);
		gotoxy(25,18);
		textcolor(CYAN);
		cprintf("PASSWORD: ");
		gotoxy(45,18);
		i=0;
		/*capturamos caracter*/
		while (caracter=getch()) {
			
			
			/*Si presiona enter se tomara como un intento*/
			if (caracter==ENTER) {
				pass[i] = '\0';
				break;

			} /*Backspace hace que retroceda un caracter*/ 
			else if (caracter==BACKSPACE) {
				if (i > 0) {
					i--;
					printf("\b \b");
				}

			} else {
				/*Mientras no se toque ni enter ni backspace, procede a escribir la pass sustituyendola por un * */
				if (i<PASSLONG) {
					printf("*");
					pass[i] = caracter;
					i++;
				}
			}
		}
        /* El user y pass debe coincidir con los que se encuentran en el array */
        for (j=0;j<USUARIOS;++j) {

			/*Validamos usuario*/
            if (strcmp(user, users[j]) == 0 ) {
                ingresa=1;
            }
          
		/*Validamos el password*/
          if(strcmp(pass, password[j]) == 0){
				 ingresa=ingresa+2;
            }
          
        }
			/*En caso de que password y user sean incorrectos*/
        if (ingresa == 0 ) {
			gotoxy(25,8);
			textcolor(RED);
			cprintf("USUARIO Y CLAVE SON INCORRECTOS");
            intento++;
            getchar();

        }
		/*Si el usuario esta correcto y la pass no*/
		if(ingresa==1){
			gotoxy(30,8);
			textcolor(RED);
			cprintf("PASSWORD INCORRECTO");
			gotoxy(34,9);
            intento++;
			cprintf("INTENTO %d/3",intento);
            getchar();

		}
		/*Si el pass esta correcto y el user no*/
		if(ingresa==2){
			gotoxy(33,8);
			textcolor(RED);
			printf("USUARIO INCORRECTO");
            intento++;
			gotoxy(34,9);
			cprintf("INTENTO %d/3",intento);
            getchar();

		}
	} /*El ciclo finaliza hasta alcanzar el maximo de intentos*/
	while (intento < MAX_INTENTOS && ingresa!=3);

	if (ingresa == 3) {
		gotoxy(30,8);
		textcolor(GREEN);
		cprintf("BIENVENIDO AL SISTEMA");
		getch();
		bool_n=1;
		return bool_n;

	} else {
		gotoxy(18,11);
		textcolor(RED);
		cprintf("FUERA DE INTENTOS, PROCEDEMOS A CERRAR EL SISTEMA :(!\n");
		getch();
		bool_n=0;
		textcolor(WHITE);
		return bool_n;
	}
}

void cuadro_login(){
	int x,y;
	clrscr();
	marco_pantalla(); 
	for (x=21;x<60;x++) /*/for para la barra horizontal/*/
  {
   gotoxy(x,12);
   putchar(205);
   gotoxy(x,20);
   putchar(205);
  }		
	 for (x=20;x<60;x++)  /*//linea  vertical de en medio xd// */
  {
   gotoxy(x,16);
   putchar(205);
  }
 for(y=13;y<20;y++)/*/for para las barras verticales/*/
  {
   gotoxy(20,y);
   putchar(186);
   gotoxy(60,y);
   putchar(186);
  }
 for(y=13;y<20;y++)/*/linea  horizontal de en medio xd/*/
  {
   gotoxy(38,y);
   putchar(186);
  }
	/*/esquinas/*/
	gotoxy(20,12);
	putchar(201);

	gotoxy(60,12);
    putchar(187);
	
	gotoxy(20,20);
    putchar(200);
	 
	gotoxy(60,20);
    putchar(188);	
}