//
//  Player.h
//  Bowstrings
//
//  Created by Sarita Sulkumäki on 13.11.2023.
//  Copyright © 2023 Sarita Sulkumäki. All rights reserved.
//

#pragma once

enum playerState
{
    STAND,
    WALK,
    JUMP
};

class Player
{
public:
    sf::RectangleShape  body;
    sf::Sprite          player_body;
    sf::IntRect         current_frame;
    int                 state;

    // Constructor and destructor
    Player();
    ~Player();

    // Player movement and update functions
    void    movePlayer(int key, sf::Time &deltatime);
    void    updatePlayer(sf::Time &deltatime);

    // Player rendering functions
    void    drawPlayer(sf::RenderWindow &window);
private:
    // Player texture
    sf::Texture         player_texture_sheet;
    sf::Vector2f        velocity;
};
