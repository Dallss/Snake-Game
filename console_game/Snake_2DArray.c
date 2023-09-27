#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>

//index value is head
void print(int a[30][50]);
void decrement(int a[30][50]);
int main(){
    int direction = 1,in;
    int size = 6;
    int cords[30][50] = {0};
    int x=5,y=5;
    int alive = 1;

    cords[rand()%22+2][rand()%49] = -1;

    while(alive){

        //scan
        if(kbhit()){

            //scans for a keypress and stores the character in 'in'
            in = getch();

            //if kbhit is triggered direction changes
            if(in =='w'){
                if(direction!=-2)
                    direction = 2;
            }
            else if(in =='a'){
                if(direction!=1)
                    direction = -1;
            }
            else if(in =='s'){
                if(direction!=2)
                    direction = -2;
            }
            else if(in =='d'){
                if(direction!=-1)
                    direction = 1;
            }
            else{
                if(direction!=-1)
                    direction = 1; 
            }
        }
        
        //render (print the current state of the screen);
        system("cls");
        print(cords);

        //update coordinate values (to make snake move forward)
        if(direction == 1){
            x++;

            //nikaon og apol
            if(cords[y][x]==-1){
                cords[y][x] =+ size+1;
                size++;
                cords[rand()%22+2][rand()%49] = -1;
                
            }

            //self bite
            else if(cords[y][x]>0){
                alive = 0;
            }
            
            //moveforwrd
            else{
                cords[y][x] =+ size;
            }
            sleep(0.9);
        }
        else if(direction == -1){
            x--;
            if(cords[y][x]==-1){
                cords[y][x] =+ size+1;
                size++;
                cords[rand()%22+2][rand()%49] = -1;
            }
            else if(cords[y][x]>0){
                //touching self
                alive = 0;
            }
            else{
                cords[y][x] =+ size;
            }
            sleep(0.9);
        }
        else if(direction == 2){
            y--;
            if(cords[y][x]==-1){
                cords[y][x] =+ size+1;
                size++;
                cords[rand()%22+2][rand()%49] = -1;
            }
            else if(cords[y][x]>0){
                //touching self
                alive = 0;
            }
            else{
                cords[y][x] =+ size;
            }
            sleep(0.9999);
        }
        else if(direction == -2){
            y++;
            if(cords[y][x]==-1){
                cords[y][x] =+ size+1;
                size++;
                cords[rand()%22+2][rand()%48+2] = -1;
            }
            else if(cords[y][x]>0){
                //touching slef
                alive = 0;
            }
            else{
                cords[y][x] =+ size;
            }
            sleep(0.9999);
        }

        decrement(cords);

        //condittions to be alive
        if(x>=50||x<1||y>=25||y<1)
            alive = 0;
    }

    //died
    system("cls");
    
    for(int x=0; x<10;x++)
        printf("\n");
    for(int x=0; x<5;x++)
        printf(" ");
    printf("YOU DIED...");
    for(int x=0; x<10;x++)
        printf("\n");

}



//functions
void print(int a[30][50]){

        int x=1, y=1;

    while(y<=25){
        x=1;
        while(x<=50){
            if(y==1||y==25){
                printf("-");
            }
            else if(x==1||x==50){
                printf("|");
            }
            else if(a[y][x]>0){
                printf("o");
            }
            else if(a[y][x]==0){
                printf(" ");
            }
            else{
                printf("A");
            }
            x++;
        }
        printf("\n");
        y++;
    }
}

void decrement(int cords[30][50]){
    int x=1,y=1;
        while(y<25){
            x=1;
            while(x<50){
                if(cords[y][x]>0){
                    cords[y][x]--;
                }
                x++;
            }
            y++;
        }

}
