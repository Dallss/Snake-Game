#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "header.h"

using namespace std;
using namespace sf;

void move(node* head, node* tail, char direction){
    
    node* sel = tail;

    if(direction == 'w')
        head->y-=10;
    else if(direction == 'a')
        head->x-=10;
    else if(direction == 's')
        head->y+=10;
    else if(direction == 'd')
        head->x+=10;

    do{
        sel->x = sel->front->x;
        sel->y = sel->front->y;

        sel = sel->front;
    }while(sel->front != nullptr);

}

void init_snake(node** hed, node** tel){

    node* head = new(node);
    head->front = nullptr;

    node* sel = head;

    for(int i=0; i<10; i++){
        sel->back = new(node);
        sel->back->front = sel;
        sel = sel->back;

        sel->x = 50;
        sel->y = 50;
    }

    sel -> back = nullptr;

    head->x = 60;
    head->y = 50;

    *hed = head;
    *tel = sel;
}

void draw_snake( node* sel, sf::RenderWindow& window ){

    using namespace std;
    using namespace sf;
    window.setFramerateLimit(60);
    
    //for rendering snake
    Texture snek;
    if (!snek.loadFromFile("scales.png"))
    {
        // Failed to load texture
        return;
    }

    RectangleShape squares(Vector2f(20,20));
    squares.setFillColor(Color::Green);
    squares.setPosition(600,400);
    squares.setTexture(&snek);

    while(sel != nullptr){
    
        squares.setPosition(sel->x, sel->y);
        window.draw(squares);

        sel = sel->back;
    } 

}

void setDirection(snake* snek){
    using namespace std;
    using namespace sf;
    if (Keyboard::isKeyPressed(Keyboard::W)|| Keyboard::isKeyPressed(Keyboard::Up)){
            if(snek->direction != 's')
                snek->direction = 'w';
        }
        if (Keyboard::isKeyPressed(Keyboard::A)|| Keyboard::isKeyPressed(Keyboard::Left)){
            if(snek->direction != 'd')
                snek->direction = 'a';
        }
        if (Keyboard::isKeyPressed(Keyboard::S)|| Keyboard::isKeyPressed(Keyboard::Down)){
            if(snek->direction != 'w')
                snek->direction = 's';
        }
        if (Keyboard::isKeyPressed(Keyboard::D)|| Keyboard::isKeyPressed(Keyboard::Right)){
            if(snek->direction != 'a')
                snek->direction = 'd';
        }
}

void grow(snake* snek){

    for(int i=0; i<5; i++){
        node* nyo = new(node);
        snek->tail->back = nyo;
        snek->tail->back->front = snek->tail;
        snek->tail->back->back = nullptr;

        snek->tail = nyo;
        snek->tail->x = snek->tail->front->x;
        snek->tail->y = snek->tail->front->y;
    }
 
}

bool isbitingSelf(snake* snek){

    RectangleShape haed(Vector2f(20,20));
    RectangleShape body(Vector2f(20,20));

    haed.setPosition(snek->head->x, snek->head->y);

    node* sel = snek->head->back->back->back->back;
    while(sel != nullptr){
        
        body.setPosition(sel->x, sel->y);

        if(haed.getGlobalBounds().intersects(body.getGlobalBounds())){
            return true;
        }
        sel = sel->back;
    }    
    return false;
}

int appleError(object apol, node* sel){
    
    RectangleShape apple(Vector2f(apol.x, apol.y));

    while(sel->back != nullptr){

        RectangleShape head (Vector2f(sel->x,sel->y));

        if(head.getGlobalBounds().intersects(apple.getGlobalBounds())){
            return 1;
        }
        sel = sel->back;
    }

    return 0;
}

int gameEngine(sf::RenderWindow& window, int speed){

    using namespace std;
    using namespace sf;

    int sc = 0;

    snake wemby;
    wemby.alive = true;
    wemby.direction = 'd';

    object apple;
    apple.x = rand()%860;
    apple.y = rand()%720;





    Texture texture;
    if (!texture.loadFromFile("desert.png"))
    {
        // Failed to load texture
        return -1;
    }





    // Load the music from a file
    Music music;
    if (!music.openFromFile("apple.wav")){
        return -1;
    }
    Music deadsound;
    if (!deadsound.openFromFile("over.wav")){
        return -1;
    }
    Font Arial;
    if (!Arial.loadFromFile("calibri-regular.ttf")) {
        return 1;
    }


    Sprite title;
    title.setTexture(texture);
    title.setScale(1,1);
    FloatRect titleBounds = title.getLocalBounds();
    //title.setPosition(window.getSize().x / 2 - titleBounds.width / 2, 25);





    //Score
    Text score("Score: "+to_string(sc), Arial, 20);
    score.setFillColor(Color::White);
    score.setStyle(Text::Bold);
    FloatRect scoreBounds = score.getLocalBounds();
    score.setPosition(1050, 50);

    //for rendering apple
    RectangleShape squares(Vector2f(35,35));
    squares.setFillColor(Color::Red);
    squares.setPosition(apple.x,apple.y);

    Texture appl;
    if (!appl.loadFromFile("apolreal.png"))
    {
        // Failed to load texture
        return -1;
    }
    squares.setTexture(&appl);


    
    //setup snake(wemby)
    init_snake(&wemby.head, &wemby.tail);

    while(wemby.alive){

        //
        setDirection(&wemby);
        
        move(wemby.head, wemby.tail, wemby.direction);
        squares.setPosition(apple.x, apple.y);

        //check ifeatsapple
        RectangleShape haed(Vector2f(20,20));
        haed.setPosition(wemby.head->x, wemby.head->y);
        if (haed.getGlobalBounds().intersects(squares.getGlobalBounds())) {

            music.stop();
            music.play();
            grow(&wemby);

            do{
                apple.x = rand()%860;
                apple.y = rand()%720;
            }while(appleError(apple,wemby.head));

            sc++;
            score.setString("Score: "+to_string(sc));
        }

        //check if dead
        Vector2f head_pos = haed.getPosition();
        Vector2f head_size = haed.getSize();
        Vector2u window_size = window.getSize();

        bool isEdged =  (head_pos.x <= 0) ||
                        (head_pos.x + head_size.x >= window_size.x) ||
                        (head_pos.y <= 0) ||
                        (head_pos.y + head_size.y >= window_size.y);

        if(isEdged || isbitingSelf(&wemby)){
            wemby.alive = false;
        }

        //render
        window.clear();
        

        window.draw(title);

        draw_snake( wemby.head, window );
        window.draw(squares);
        window.draw(score);
        Sleep(speed);
        
        window.display();

    }

    deadsound.stop();
    deadsound.play();
    return sc;
}

