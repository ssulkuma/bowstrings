//
//  Button.cpp
//  Bowstrings
//
//  Created by Sarita Sulkumäki on 13.11.2023.
//  Copyright © 2023 Sarita Sulkumäki. All rights reserved.
//

#include "Game.h"

// Constructor
Button::Button()
{
    button_rect.setSize(sf::Vector2f(600.f, 120.f));
    state = IDLE;
}

// Destructor
Button::~Button()
{
    
}

// Loads the button texture to a sprite.
bool    Button::loadButtonTexture()
{
    std::string assetPath;

    assetPath = Resources::getAssetPath();
    if (!button_tex.loadFromFile(assetPath + "/graphics/button.png"))
        return (false);
    button_rect.setTexture(&button_tex);
    button_rect.setScale(0.8f, 0.8f);
    return (true);
}

// Sets the button's state based on mouse position.
void    Button::setButtonState(sf::RenderWindow &window)
{
    mouse_position = sf::Mouse::getPosition(window);
    button_bounds = button_rect.getGlobalBounds();
    if (button_bounds.contains(mouse_position.x, mouse_position.y))
        state = HOVER;
    else
        state = IDLE;
}

// Sets button's text.
bool    Button::setButtonText(sf::String text)
{
    sf::Vector2f    text_offset;
    std::string     assetPath;
    sf::FloatRect   text_bounds;
    
    assetPath = Resources::getAssetPath();
    if (!font.loadFromFile(assetPath + "/fonts/AdulsaScript.ttf"))
        return (false);
    button_text.setFont(font);
    button_text.setCharacterSize(60);
    button_text.setFillColor(sf::Color::White);
    button_text.setString(text);
    text_bounds = button_text.getLocalBounds();
    text_offset.x = button_rect.getPosition().x + (button_rect.getSize().x * 0.8f - text_bounds.width) / 2.0f;
    text_offset.y = button_rect.getPosition().y + (button_rect.getSize().y * 0.8f - text_bounds.height) / 2.0f - 25.0f;
    button_text.setPosition(sf::Vector2f(text_offset));
    return (true);
}

// Draws the button.
void    Button::drawButton(sf::RenderWindow &window)
{
    // Set font color based on the state of the button
    switch (state)
    {
    case HOVER:
        button_text.setFillColor(sf::Color::Black);
        break;
    case CLICKED:
        button_text.setFillColor(sf::Color::White);
        break;
    default:
        button_text.setFillColor(sf::Color::White);
        break;
    }
    window.draw(button_rect);
    window.draw(button_text);
}
