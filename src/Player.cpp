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
    body.setPosition(sf::Vector2f(300.f, 400.f));
    velocity.x = 0.f;
    velocity.y = 0.f;
    state = STAND;
    current_frame.left = 0.f;
    current_frame.top = 0.f;
    current_frame.width = PLAYER_WIDTH;
    current_frame.height = PLAYER_HEIGHT;
    setTextures();
    switch_frame = 0.1f;
    animation_time = 0.0f;
    ready = false;
}

// Destrcutor
Player::~Player()
{
    
}

// Load different player textures.
bool    Player::setTextures()
{
    std::string assetsPath;
    
    assetsPath = Resources::getAssetPath();
    if (!walk_tex.loadFromFile(assetsPath + "/graphics/player_walk.png") ||
        !shoot_tex.loadFromFile(assetsPath + "/graphics/player_shoot.png") ||
        !arrow_tex.loadFromFile(assetsPath + "/graphics/arrow.png"))
        return (false);
    return (true);
}

// Updates player position when moved.
void    Player::movePlayer(int key, sf::Time &deltatime)
{
    sf::Vector2f    previous_position;

    previous_position = body.getPosition();
    std::cout << 1.f / deltatime.asSeconds() << " deltatime\n";
    if (key == sf::Keyboard::D)
    {
        state = WALK_RIGHT;
        velocity.x += ACCELERATION * deltatime.asSeconds();
    }
    else if (key == sf::Keyboard::A)
    {
        state = WALK_LEFT;
        velocity.x -= ACCELERATION * deltatime.asSeconds();
    }
    if (key == sf::Keyboard::Space && state != JUMP)
    {
        state = JUMP;
        velocity.y = -40.f;
    }
}

// Updates the correct frame to player animations
void    Player::updatePlayerAnimation(sf::Time &deltatime)
{
    animation_time += deltatime.asSeconds();
    
    if (animation_time >= switch_frame)
    {
        if (state == WALK_RIGHT)
        {
            body.setTexture(&walk_tex);
            body.setScale(1.0f, 1.0f);
            current_frame.left += PLAYER_WIDTH;
            if (current_frame.left >= PLAYER_WIDTH * 4)
                current_frame.left = 0;
                
        }
        else if (state == WALK_LEFT)
        {
            body.setTexture(&walk_tex);
            body.setScale(-1.0f, 1.0f);
            current_frame.left += PLAYER_WIDTH;
            if (current_frame.left >= PLAYER_WIDTH * 4)
                current_frame.left = 0;
        }
        else if (state == SHOOT_RIGHT)
        {
            body.setTexture(&shoot_tex);
            body.setScale(1.0f, 1.0f);
            if (current_frame.left <= body.getLocalBounds().width)
                current_frame.left += (PLAYER_WIDTH - 9.0f);
        }
        else if (state == SHOOT_LEFT)
        {
            body.setTexture(&shoot_tex);
            body.setScale(-1.0f, 1.0f);
            if (current_frame.left <= body.getLocalBounds().width)
                current_frame.left += (PLAYER_WIDTH - 9.0f);
        }
        else
        {
            body.setTexture(&walk_tex);
            body.setScale(1.0f, 1.0f);
            current_frame.left = 0;
        }
        animation_time = 0.0f;
    }
    body.setTextureRect(current_frame);
}

// Adds gravity to player and updates player's position with each frame.
void    Player::updatePlayer(sf::Time &deltatime)
{
    sf::Vector2f    current_position;

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
    updatePlayerAnimation(deltatime);
}


// Animation for the shot weapon
void    Player::shootWeapon(sf::Time &deltatime)
{
    sf::Vector2f    player_position;
    sf::Vector2f    arrow_position;

    arrow.setTexture(arrow_tex);
    if (ready)
    {
        arrow_position.x += 1.0f * deltatime.asSeconds();
        
        player_position = body.getPosition();
        arrow.setPosition(player_position.x, player_position.y);
    }
}

// Draws player on the window.
void    Player::drawPlayer(sf::RenderWindow &window)
{
    window.draw(body);
//    window.draw(arrow);
}
