#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "header.h"

int main(){

    using namespace sf;
    using namespace std;    

    int hs=0;    

    // Create a window
    RenderWindow window(VideoMode(1200, 800), "SNEK");

    window.setFramerateLimit(60);
    
    // Load assets
    Music music;
    if (!music.openFromFile("power.wav")){
        return -1;
    } 
    Font CommodorePixeled;
    if (!CommodorePixeled.loadFromFile("pixel.ttf")) {
        return 1;
    }

    Font Arial;
    if (!Arial.loadFromFile("calibri-regular.ttf")) {
        return 1;
    }
    
    Texture texture2;
    if (!texture2.loadFromFile("1.png"))
    {
        // Failed to load texture
        return -1;
    }

    // Texture texture;
    // if (!texture.loadFromFile("title.png"))
    // {
    //     // Failed to load texture
    //     return -1;
    // }

    

    //bgMusic
    music.setLoop(true);
    music.play();

    //loop
    while(window.isOpen()){
        
        Sprite bg;
        bg.setTexture(texture2);
        bg.setScale(1,1);
        
        //title
        // Sprite title;
        // title.setTexture(texture);
        // title.setScale(1,1);
        // FloatRect titleBounds = title.getLocalBounds();
        // title.setPosition(window.getSize().x / 2 - titleBounds.width / 2, 25);

        //setup easy
        Text easy("Easy", CommodorePixeled, 40);
        easy.setFillColor(Color::White);
        easy.setStyle(Text::Bold);
        FloatRect easyBounds = easy.getLocalBounds();
        easy.setPosition(window.getSize().x / 2 - easyBounds.width / 2, window.getSize().y / 2 +110);

        //Medium
        Text medium("Medium", CommodorePixeled, 40);
        medium.setFillColor(Color::White);
        medium.setStyle(Text::Bold);
        FloatRect mediumBounds = medium.getLocalBounds();
        medium.setPosition(window.getSize().x / 2 - mediumBounds.width / 2, window.getSize().y / 2 +180);

        //Hard
        Text hard("Hard", CommodorePixeled, 40);
        hard.setFillColor(Color::White);
        hard.setStyle(Text::Bold);
        FloatRect hardBounds = hard.getLocalBounds();
        hard.setPosition(window.getSize().x / 2 - hardBounds.width / 2, window.getSize().y / 2 +250);

        //Instructions
        Text ins("Instructions: Play like the classic Snake Game!", Arial, 20);
        ins.setFillColor(Color::White);
        ins.setStyle(Text::Bold);
        FloatRect insBounds = ins.getLocalBounds();
        ins.setPosition(window.getSize().x / 2 - insBounds.width / 2, window.getSize().y / 2 +80);

        //High-Score
        Text high("High-Score: "+to_string(hs), Arial, 20);
        high.setFillColor(Color::Black);
        high.setStyle(Text::Bold);
        FloatRect highBounds = high.getLocalBounds();
        high.setPosition(1000, 50);
        
        //Event handler
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //on-hover event
        if (event.type == Event::MouseMoved) {
            
            Vector2i mousePos = Mouse::getPosition(window);
                
            // Check if the mouse position is within the bounds of a shape
            if (easy.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                easy.setFillColor(Color::Yellow);                
            }
            else {
                easy.setFillColor(Color::White);
            
            }

            if (medium.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                medium.setFillColor(Color::Yellow);                
            }
            else {
                medium.setFillColor(Color::White);
              
            }
            if (hard.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                hard.setFillColor(Color::Yellow);                
            }
            else {
                hard.setFillColor(Color::White);
                
            }
        }
        //on click event
        else if (event.type == Event::MouseButtonPressed) {
            Vector2i mousePos = Mouse::getPosition(window);

            int score; 
            if (easy.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                music.stop();
                score = gameEngine(window,20);//<--game gyod
                if(score>hs)
                    hs = score;
                
            }

            if (medium.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                music.stop();
                score = gameEngine(window,10);//<--game gyod
                if(score>hs)
                    hs = score;
    
            }
            if (hard.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                music.stop();
                score = gameEngine(window,0);//<--game gyod
                if(score>hs)
                    hs = score;
            }
            
            //gameover    
        }


        // render home screen
        window.clear();

        window.draw(bg);
        //window.draw(title);
        window.draw(easy);
        window.draw(medium);
        window.draw(hard);
        //window.draw(ins);
        window.draw(high);

        window.display();

    }
}


