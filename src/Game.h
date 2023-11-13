//
//  Game.h
//  Bowstrings
//
//  Created by Sarita Sulkumäki on 13.11.2023.
//  Copyright © 2023 Sarita Sulkumäki. All rights reserved.
//

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

//#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/Drawable.hpp>
//#include <SFML/Graphics/Transformable.hpp>
//#include <SFML/Graphics/Font.hpp>
//#include <SFML/System.hpp>
//#include <SFML/System/Clock.hpp>
//#include <SFML/System/Time.hpp>
//#include <SFML/Window/Keyboard.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

#include "Constants.h"
#include "Player.h"
#include "Audio.h"
#include "Button.h"
#include "resources/Resources.h"
#include "resources/ResourcePath.h"

enum gameState
{
    GAMESTATE_MENU,
    GAMESTATE_INSTRUCTIONS,
    GAMESTATE_PLAY,
    GAMESTATE_PAUSE,
    GAMESTATE_GAMEOVER
};

class Game
{
public:
    // Game window and state
    sf::RenderWindow    window;
    sf::View            view;
    sf::View            player_view;
    int                 game_state;
    std::string         assetPath;

    // Deltatime
    sf::Time            deltatime;
    sf::Clock           clock;

    Player              player;
    Audio               audio;
    

    // Constructor and destructor
    Game();
    ~Game();

    // Game loop functions
    void    handleEvents(sf::Event &event);
    void    render();

    // Exit functions
    void    exitGameSuccess();
    void    exitGameFailure();

private:
    // Game title and backgrounds
    sf::Sprite          title;
    sf::Texture         title_tex;
    sf::Sprite          cupid;
    sf::Texture         cupid_tex;
    sf::Sprite          background;
    sf::Texture         background_tex;

    // Menu buttons
    Button              new_game;
    Button              instructions;
    Button              quit_game;
    Button              back;

    // Event handling functions
    void    handleMouseClickEvents();
    void    handleMouseHoverEvents();
    void    handleMousePressEvents();
    void    handleKeyEvents(sf::Event::KeyEvent key);

    // Rendering functions
    bool    renderMenu();
    void    renderGameplay();
    void    renderPause();
    void    renderLevelSelection();
    void    renderInstructions();
    void    renderGameover();
};
