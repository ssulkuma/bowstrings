//
//  Player.cpp
//  Bowstrings
//
//  Created by Sarita Sulkumäki on 13.11.2023.
//  Copyright © 2023 Sarita Sulkumäki. All rights reserved.
//

#include "Game.h"

// Constructor
Player::Player()
{
    body.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
    body.setFillColor(sf::Color::Cyan);
    body.setPosition(sf::Vector2f(300.f, 400.f));
    velocity.x = 0.f;
    velocity.y = 0.f;
    state = STAND;
}

// Destrcutor
Player::~Player()
{
    
}

// Updates player position when moved.
void    Player::movePlayer(int key, sf::Time &deltatime)
{
    sf::Vector2f    previous_position;

    previous_position = body.getPosition();
    std::cout << 1.f / deltatime.asSeconds() << " deltatime\n";
    if (key == sf::Keyboard::D)
        velocity.x += ACCELERATION * deltatime.asSeconds();
    else if (key == sf::Keyboard::A)
        velocity.x -= ACCELERATION * deltatime.asSeconds();
    if (key == sf::Keyboard::Space && state != JUMP)
    {
        state = JUMP;
        velocity.y = -40.f;
    }
}

// Adds gravity to player and updates player's position with each frame.
void    Player::updatePlayer(sf::Time &deltatime)
{
    sf::Vector2f    current_position;

    std::cout << "velocity x " << velocity.x << " velocity y " << velocity.y << "\n";
    body.move(velocity.x * 5.f * deltatime.asSeconds(), velocity.y * deltatime.asSeconds());
    velocity.y += GRAVITY * deltatime.asSeconds();
    if (velocity.x > 0.f)
    {
        velocity.x -= FRICTION * deltatime.asSeconds();
        velocity.x = std::max(velocity.x, 0.f);
    }
    else if (velocity.x < 0.f)
    {
        velocity.x += FRICTION * deltatime.asSeconds();
        velocity.x = std::min(velocity.x, 0.f);
    }
    velocity.x = std::clamp(velocity.x, -MAX_SPEED, MAX_SPEED);
    current_position = body.getPosition();
    if (current_position.y > (WINDOW_HEIGHT - PLAYER_HEIGHT))
    {
        velocity.y = 0.f;
        if (state == JUMP)
            state = STAND;
    }
}

// Draws player on the window.
void    Player::drawPlayer(sf::RenderWindow &window)
{
    window.draw(body);
}
