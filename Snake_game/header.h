#ifndef MYHEADER_H
#define MYHEADER_H


class node{
    public:
        int x,y;
        node* back;
        node* front;
};

struct object{
    public:
        int x;
        int y;
};

class snake{
    public:
        node* head;
        node* tail;
        char direction;
        int size;
        bool alive;
};

void move(node*,node*,char);

void init_snake(node**, node**);

void draw_snake(node*,sf::RenderWindow& window);

void setDirection(snake*);

void grow(snake*);

bool isbitingSelf(snake*);

int appleError(object apol, node* sel);

int gameEngine(sf::RenderWindow& window, int);



#endif