//
//  Audio.cpp
//  Bowstrings
//
//  Created by Sarita Sulkumäki on 13.11.2023.
//  Copyright © 2023 Sarita Sulkumäki. All rights reserved.
//

#include "Game.h"

// Constructor
Audio::Audio()
{
    background_music.setLoop(true);
    background_music.setVolume(50.f);
    background_music.setPitch(1.f);
    background_music.setRelativeToListener(false);
    background_music.setMinDistance(5.f);
    background_music.setAttenuation(1.f);
    background_music.setPlayingOffset(sf::seconds(10.f));
}

// Destructor
Audio::~Audio()
{

}

// Stops the background music.
void    Audio::stopMusic()
{
    background_music.stop();
}

// Plays the background music in a loop.
bool    Audio::playMusic()
{
    std::string assetPath;
    
    assetPath = Resources::getAssetPath();
    if (!background_music.openFromFile(assetPath + "/audio/bg_music.ogg"))
        return (false);
    background_music.play();
    return (true);
}
