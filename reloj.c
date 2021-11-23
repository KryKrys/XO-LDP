#include<time.h>
#include<conio.h>
#include<stdlib.h>

void main(){
struct tm *outtime;
time_t hora;
int i;
i=0;
clrscr();
while(i<1){
        time(&hora);
        outtime = localtime(&hora);
        printf("%.19s\n", asctime(outtime));
        delay(1000);
        clrscr(); 
        }
        getch();
}