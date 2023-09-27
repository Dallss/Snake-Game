#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>

void printSnake(int, int, int, int);

int main(){
    
    int size = 4;
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
        
        printSnake(xpos,ypos,size,direction);
        sleep(0.95);
        system("cls");

        // if(xpos >21||xpos<1||ypos>21||ypos<1)
        //     alive = 0;

        
    }
    printf("DIED");
}
void printSnake(int x, int y,int s, int d){
    
    if(d==-1){
        for(int z=1; z<=y; z++)
            printf("\n");
        for(int z=1; z<=x; z++)
            printf(" ");
        for(int z=0; z<=s; z++)
            printf("O");
    }
    else if(d == 1){
        for(int z=1; z<=y; z++)
            printf("\n");
        for(int z=1; z<=x-s; z++)
            printf(" ");
        for(int z=0; z<=s; z++)
            printf("O");
    }
    else if(d==2){
        for(int z=1; z<=y; z++)
            printf("\n");
        for(int z=1; z<=x; z++)
            printf(" ");
        printf("0");
        for(int z=0; z<=s; z++){
            printf("\n");
            for(int z=1; z<=x; z++)
                printf(" ");
            printf("O");
        }
    }
    else if(d==-2){
        for(int z=1; z<=y-s; z++)
            printf("\n");
        for(int z=1; z<=x; z++)
            printf(" ");
        for(int z=0; z<=s; z++){
            printf("O");
            printf("\n");
            for(int z=1; z<=x; z++)
                printf(" ");
        }
        printf("0");
    }
}
