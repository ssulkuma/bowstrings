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
    WALK_LEFT,
    WALK_RIGHT,
    SHOOT_LEFT,
    SHOOT_RIGHT,
    JUMP,
    FALL
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
    
    bool                ready;

    // Player movement and update functions
    void    movePlayer(int key, sf::Time &deltatime);
    void    updatePlayer(sf::Time &deltatime);
    void    updatePlayerAnimation(sf::Time &deltatime);
    void    shootWeapon(sf::Time &deltatime);

    // Player rendering functions
    void    drawPlayer(sf::RenderWindow &window);
private:
    // Player texture
    sf::Texture         walk_tex;
    sf::Texture         shoot_tex;
    sf::Sprite          arrow;
    sf::Texture         arrow_tex;
    sf::Vector2f        velocity;
    
    // Animation
    float               animation_time;
    float               switch_frame;

    bool    setTextures();

};
