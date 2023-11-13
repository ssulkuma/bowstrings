//
//  Game.cpp
//  Bowstrings
//
//  Created by Sarita Sulkumäki on 13.11.2023.
//  Copyright © 2023 Sarita Sulkumäki. All rights reserved.
//

#include "Game.h"

// Constructor
Game::Game()
{
    assetPath = Resources::getAssetPath();
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bowstrings", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(FRAMERATE);
    view.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    game_state = GAMESTATE_MENU;
}

// Destructor
Game::~Game()
{

}

// Closes the window and exits the game successfully.
void    Game::exitGameSuccess()
{
    window.close();
    exit(EXIT_SUCCESS);
}

// Closes the window and exits the game in case of error.
void    Game::exitGameFailure()
{
    window.close();
    exit(EXIT_FAILURE);
}

// Handles keypress events.
void    Game::handleKeyEvents(sf::Event::KeyEvent key)
{
    if (key.code == sf::Keyboard::Escape)
        exitGameSuccess();
    if (game_state == GAMESTATE_PLAY)
        player.movePlayer(key.code, deltatime);
}

// Handles mouse click events.
void    Game::handleMouseClickEvents()
{
    // If in menu, check button states to define if click is within bounds of the button.
    if (game_state == GAMESTATE_MENU)
    {
        if (new_game.state == HOVER)
            game_state = GAMESTATE_PLAY;
        if (instructions.state == HOVER)
            game_state = GAMESTATE_INSTRUCTIONS;
        if (quit_game.state == HOVER)
            exitGameSuccess();
    }
    if (game_state == GAMESTATE_INSTRUCTIONS)
        if (back.state == HOVER)
            game_state = GAMESTATE_MENU;
    if (game_state == GAMESTATE_PLAY)
    {

    }
}

// Hadles mouse hover events.
void    Game::handleMouseHoverEvents()
{
    new_game.setButtonState(window);
    instructions.setButtonState(window);
    quit_game.setButtonState(window);
    back.setButtonState(window);
}

// Handles the game events based on event type.
void    Game::handleEvents(sf::Event &event)
{
    switch (event.type)
    {
        case sf::Event::Closed:
            exitGameSuccess();
            break;
        case sf::Event::KeyPressed:
            handleKeyEvents(event.key);
            break;
        case sf::Event::MouseMoved:
            handleMouseHoverEvents();
            break;
        case sf::Event::MouseButtonReleased:
            handleMouseClickEvents();
            break;
        default:
            break;
        }
}

// Renders the game menu.
bool    Game::renderMenu()
{
    // Check that assets are loaded correctly
    if (!title_tex.loadFromFile(assetPath + "/graphics/title.png") ||
        !background_tex.loadFromFile(assetPath + "/graphics/background.png") ||
        !cupid_tex.loadFromFile(assetPath + "/graphics/cupid.png"))
        {
            std::cerr << "Error // Failed to load menu background files.\n";
            return (false);
        }
    // Set title
    title.setTexture(title_tex);
    title.setPosition(sf::Vector2f(250.0f, 10.0f));
    title.setScale(0.6f, 0.6f);
    // Set cupid
    cupid.setTexture(cupid_tex);
    cupid.setPosition(sf::Vector2f(800.0f, 50.0f));
    // Set background
    background.setTexture(background_tex);
    // Sets Button positions.
    if (!new_game.loadButtonTexture() ||
        !instructions.loadButtonTexture() ||
        !quit_game.loadButtonTexture())
    {
        std::cerr << "Error // Failed to load button textures.\n";
        return (false);
    }
    new_game.button_rect.setPosition(350.0f, 350.0f);
    instructions.button_rect.setPosition(350.0f, 450.0f);
    quit_game.button_rect.setPosition(350.0f, 550.0f);
    
    // Sets Button texts.
    new_game.setButtonText("Play");
    instructions.setButtonText("Instructions");
    quit_game.setButtonText("Exit");

    // Draw everything on window
    window.draw(background);
    window.draw(title);
    window.draw(cupid);
    new_game.drawButton(window);
    instructions.drawButton(window);
    quit_game.drawButton(window);
    return (true);
}

// Renders the actual game.
void    Game::renderGameplay()
{
    player.updatePlayer(deltatime);
    std::cout << "X " << player.body.getPosition().x << " Y " << player.body.getPosition().y << "\n";
    player.drawPlayer(window);
}

// Renders the paused game.
void    Game::renderPause()
{

}

// Renders the menu instructions screen.
void    Game::renderInstructions()
{
    // Check that assets are loaded correctly
    if (!title_tex.loadFromFile(assetPath + "/graphics/title.png") ||
        !background_tex.loadFromFile(assetPath + "/graphics/background.png") ||
        !cupid_tex.loadFromFile(assetPath + "/graphics/cupid.png"))
        {
            std::cerr << "Error // Failed to load menu background files.\n";
            exitGameFailure();
        }
    // Set title
    title.setTexture(title_tex);
    title.setPosition(sf::Vector2f(250.0f, 10.0f));
    title.setScale(0.6f, 0.6f);
    // Set cupid
    cupid.setTexture(cupid_tex);
    cupid.setPosition(sf::Vector2f(800.0f, 50.0f));
    // Set background
    background.setTexture(background_tex);
    //Rectangle
    sf::RectangleShape rectangle(sf::Vector2f(400.0f, 200.0f));
    rectangle.setPosition(380.0f, 400.0f);
    rectangle.setFillColor(sf::Color(237, 69, 106));
    //Instruction texts
    sf::Font font;
    sf::Text text;
    
    if (!font.loadFromFile(assetPath + "/fonts/AdulsaScript.ttf"))
    {
        std::cerr << "Error // Failed to load font.\n";
        exitGameFailure();
    }
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(rectangle.getPosition().x + 20.0f, rectangle.getPosition().y + 10.0f);
    text.setString("Move - A / D \nJump - Space \nShoot - Hold down left mouse click \nto charge bow, shoot on release \nExit - esc");
    // Button
    if (!back.loadButtonTexture())
    {
        std::cerr << "Error // Failed to load button texture.\n";
        exitGameFailure();
    }
    back.button_rect.setPosition(350.0f, 600.0f);
    back.setButtonText("Back");
    //Draw everything on the window
    window.draw(background);
    window.draw(title);
    window.draw(cupid);
    window.draw(rectangle);
    window.draw(text);
    back.drawButton(window);
}

// Renders the gameover screen.
void    Game::renderGameover()
{

}

// Clears window with each frame and renders updated game on it.
void    Game::render()
{
    // Clear window
    window.clear();
    // Renders correct things based on the game state
    switch (game_state)
    {
        case GAMESTATE_MENU:
            renderMenu();
            break;
        case GAMESTATE_PLAY:
            // Set the window view to follow the player
            view.setCenter(sf::Vector2f(player.body.getPosition().x, WINDOW_HEIGHT / 2));
            window.setView(view);
            renderGameplay();
            break;
        case GAMESTATE_PAUSE:
            break;
        case GAMESTATE_INSTRUCTIONS:
            renderInstructions();
            break;
        case GAMESTATE_GAMEOVER:
            renderGameover();
            break;
    }
    // Display everything on the window
    window.display();
}
