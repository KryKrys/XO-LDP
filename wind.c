#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	void main(){
		int xo[3][3]={
        1,1,1,
        1,1,1
        ,1,1,1};
		int i, j, x,win=0;
        clrscr();

		printf("Horizontales perronas");
		for(x=0;x<3;x++){
			for(i=0;i<3;i++){
				if(xo[x][i]==1){
					win+=1;
					if (win==3) {
						printf("\n\tGanaste c:\n");
						i=3;
						x=3;
					}
					continue;
				}else{
					win=0;
					break;
				}
			}
		}
		
		win=0;

		printf("\nVerticales perronas");
		for(x=0;x<3;x++){
			for(i=0;i<3;i++){
				if(xo[i][x]==1){
					win+=1;
					if (win==3) {
						printf("\n\tGanaste c:\n");
						i=3;
						x=3;
					}
					continue;
				}else{
					win=0;
					break;
				}
			}
		}	

		win=0;

		printf("\nGana en diagonal");
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(j==i){
					if(xo[j][i]==1){
						win+=1;
						if (win==3) {
							printf("\n\tGanaste c:\n");
							i=3;
							x=3;
						}
						continue;
					}else{
						j=3;
						i=3;
					}
				}
			}
		}

		win=0;

		printf("\nGana en diagonal invert");
		for(i=0;i<3;i++){
			if (xo[i][(3-1)-i]==1){
				win+=1;
				if (win==3) {
					printf("\n\tGanaste c:\n");
					i=3;
					x=3;
				}
				continue;
			}else{
				j=3;
				i=3;
			}
		}

        getch();
    }