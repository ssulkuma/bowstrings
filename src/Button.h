//
//  Button.h
//  Bowstrings
//
//  Created by Sarita Sulkumäki on 13.11.2023.
//  Copyright © 2023 Sarita Sulkumäki. All rights reserved.
//

#pragma once

#include "Game.h"

enum buttonState
{
    IDLE,
    HOVER,
    CLICKED
};

class Button
{
public:
    // Constructor and destructor
    Button();
    ~Button();

    sf::RectangleShape  button_rect;
    sf::Sprite          button;
    int                 state;

    // Button initilization functions
    void    setButtonState(sf::RenderWindow &window);
    bool    setButtonText(sf::String text);

    // Button rendering functions
    void    drawButton(sf::RenderWindow &window);
    
    // Button texture functions
    bool                loadButtonTexture();

private:
    sf::FloatRect       button_bounds;
    sf::Texture         button_tex;

    // Button texts
    sf::Font            font;
    sf::Text            button_text;

    // Mouse
    sf::Vector2i        mouse_position;
};
