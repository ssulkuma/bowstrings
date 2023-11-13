//
//  Main.cpp
//  Bowstrings
//
//  Created by Sarita Sulkumäki on 13.11.2023.
//  Copyright © 2023 Sarita Sulkumäki. All rights reserved.
//

#include "Game.h"

// Start of the game. Initial game loop.
int main()
{
    Game    game;

    // Check that background music starts playing.
    if (!game.audio.playMusic())
    {
        std::cerr << "Error // Failed to open music file.\n";
        return (EXIT_FAILURE);
    }
    // Run the program as long as the window is open.
    while (game.window.isOpen())
    {
        // Get deltatime
        game.deltatime = game.clock.restart();
        // Check for new events in the window and handle them.
        sf::Event event;
        while (game.window.pollEvent(event))
            game.handleEvents(event);
        // Render the content to the window.
        game.render();
    }
    return (EXIT_SUCCESS);
}
