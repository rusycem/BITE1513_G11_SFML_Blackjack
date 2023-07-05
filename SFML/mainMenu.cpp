#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "game.h"

using namespace sf;

int mainMenu()
{
    RenderWindow window(VideoMode(1300, 900), "Blackjack made by Group 11 (Irfan, Amir, Hmam, Aisyah)", Style::Titlebar | Style::Close);
    Font font;
    font.loadFromFile("fonts/Akhenaton-LYLD.ttf");
    Texture t1;
    t1.loadFromFile("images/BlackJack_Title_Screen.jpg");
    Sprite background1(t1);

    Color titlecolor(218, 165, 32);
    Text title;
    title.setFont(font);
    title.setString("Blackjack");
    title.setCharacterSize(400);
    title.setOutlineColor(titlecolor);
    title.setOutlineThickness(10);
    title.setFillColor(Color::Black);
    title.setPosition(270, -50);


    // Play button
    Text playText;
    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(200);
    playText.setStyle(Text::Style::Bold);
    playText.setOutlineColor(Color::Black);
    playText.setOutlineThickness(10);
    playText.setFillColor(Color::Red);
    playText.setPosition(550, 350);

    // Exit button
    Text exitText;
    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(200);
    exitText.setOutlineColor(Color::White);
    exitText.setOutlineThickness(10);
    exitText.setFillColor(sf::Color::Black);
    exitText.setPosition(550, 500);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed)
            {
                // Check if play button is clicked
                if (event.mouseButton.button == Mouse::Left && playText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    window.close();
                    runGame();
                }
                // Check if exit button is clicked
                else if (event.mouseButton.button == Mouse::Left &&
                    exitText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    // Handle exit button click event
                    window.close();
                }
            }
        }
        window.clear();

        window.draw(background1);
        window.draw(title);
        window.draw(playText);
        window.draw(exitText);

        window.display();
    }

    return 0;
}

