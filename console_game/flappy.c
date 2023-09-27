#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>

void printSnake(int, int);


int main(){
    
    int alive = 1;
    int xpos = 3;
    int ypos = 3;

    int direction = 1;
    char in;
    while(alive){

        if(kbhit()){
            in = getch();

            if(in =='w')
                direction = 2;
            else if(in =='a')
                direction = -1;
            else if(in =='s')
                direction = -2;
            else if(in =='d')
                direction = 1;
            else
                direction = 1; 
        }

        if(direction == 1){
            xpos++;
        }

        else if(direction == -1){
            xpos--;
        }
        else if(direction == 2){
            ypos--;
        }
        else if(direction == -2){
            ypos++;
        }
        
        printSnake(xpos,ypos);
        sleep(0.8);
        
    }
    printf("DIED");
}
void printSnake(int x, int y){
    
    for(int z=1; z<=y; z++)
        printf("\n");
    for(int z=1; z<=x; z++)
        printf(" ");
    
    printf("O\n\n\n\n\n\n");
    
}
