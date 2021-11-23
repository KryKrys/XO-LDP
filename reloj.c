#include<time.h>
#include<conio.h>
#include<stdlib.h>

void main(){
struct tm *outtime;
time_t hora;
clrscr();
while(!kbhit()){
        time(&hora);
        outtime = localtime(&hora);
        printf("%.19s\n", asctime(outtime));
        delay(1000);
        clrscr(); 
        }
        getch();
}