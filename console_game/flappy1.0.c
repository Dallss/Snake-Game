#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>

typedef struct{
        int size = 4;
        int alive = 1;
        int xpos = 3;
        int ypos = 3;
        int direction = 1;
    }snake;

void printSnake(snake);


int main(){
    
    snake nemo;
    nemo.alive = 1;
    
    char in;
    while(nemo.alive){

        if(kbhit()){
            in = getch();

            if(in =='w')
                nemo.direction = 2;
            else if(in =='a')
                nemo.direction = -1;
            else if(in =='s')
                nemo.direction = -2;
            else if(in =='d')
                nemo.direction = 1;
            else
                nemo.direction = 1;
            
            
        }

        if(nemo.direction == 1){
            nemo.xpos++;
        }

        else if(nemo.direction == -1){
            nemo.xpos--;
        }
        else if(nemo.direction == 2){
           nemo.ypos--;
        }
        else if(nemo.direction == -2){
           nemo.ypos++;
        }
        
        printSnake(nemo);
        sleep(0.95);
        system("cls");

        // if(nemo.xpos >21||nemo.xpos<1||ypos>21||ypos<1)
        //     nemo.alive = 0;

        
    }
    printf("DIED");
}
void printSnake(nemo){
    
    for(int z=1; z<=nemo.ypos; z++)
        printf("\n");
    for(int z=1; z<=nemo.xpos; z++)
        printf(" ");
    printf("O");
    
}
