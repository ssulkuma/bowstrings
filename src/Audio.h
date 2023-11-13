//
//  Audio.h
//  Bowstrings
//
//  Created by Sarita Sulkumäki on 13.11.2023.
//  Copyright © 2023 Sarita Sulkumäki. All rights reserved.
//

#pragma once

class Audio
{
public:
    // Constructor and destructor
    Audio();
    ~Audio();

    // Background music functions
    bool        playMusic();
    void        stopMusic();

private:
    // Music 
    sf::Music   background_music;

    // Sound effects
};