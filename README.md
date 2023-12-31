# bowstrings
This is a small game made for the Supercell intern coding challenge (November 2023).  It’s written in C++ and uses the SFML library.

Gameplay</br>
The game is a platformer and the idea of the game is to reach the level end while shooting the targets on the way.

Move left and right – A / D</br>
Jump – Space</br>
Shoot – Hold down left mouse click to charge the bow, shoot on release (incomplete currently)</br>

## How to generate project files

### Visual Studio 2022
One you have the project cloned to your PC.  Open a command prompt and from the source code directory run:
`cmake -B./build -G"Visual Studio 17 2022"`

Open `platformer_test.sln` from `/build`

### Visual Studio 2019
One you have the project cloned to your PC.  Open a command prompt and from the source code directory run:
`cmake -B./build -G"Visual Studio 16 2019"`

Open `platformer_test.sln` from `/build`

### XCode
One you have the project cloned to your MAC.  Open a terminal and from the source code directory run:
`cmake -B./build -GXcode`

Open `platformer_test.xcodeproj` from `/build`
You'll also have to select `Platformer` from the project selection dropdown menu in XCsode.

❏ Assets</br>
	&emsp;&emsp;✓ Menu background</br>
  &emsp;&emsp;✓ Menu buttons idle</br>
  &emsp;&emsp;❏ Menu buttons hover</br>
  &emsp;&emsp;✓ Game background</br>
  &emsp;&emsp;❏ Game over background</br>
	&emsp;&emsp;✓ Player idle</br>
  &emsp;&emsp;✓ Player walking</br>
  &emsp;&emsp;✓ Player shooting</br>
	&emsp;&emsp;❏ Platform</br>
	&emsp;&emsp;✓ Target</br>
	&emsp;&emsp;❏ Target hit</br>
	&emsp;&emsp;✓ Arrow</br>
	&emsp;&emsp;❏ Arrow hit</br>
	&emsp;&emsp;✓ Level end</br>
❏ Add game states</br>
	&emsp;&emsp;✓ Menu</br>
	&emsp;&emsp;✓ Gameplay</br>
	&emsp;&emsp;❏ Pause</br>
	&emsp;&emsp;❏ Game Over</br>
✓ Menu buttons and background</br>
	&emsp;&emsp;✓ Add background</br>
	&emsp;&emsp;✓ Add buttons</br>
	&emsp;&emsp;✓ Hover effect on buttons</br>
✓ Game</br>
	&emsp;&emsp;✓ Add background</br>
	&emsp;&emsp;✓ Move screen with player</br>
❏ Audio</br>
	&emsp;&emsp;✓ Background music</br>
	&emsp;&emsp;❏ Menu buttons hover sound</br>
	&emsp;&emsp;❏ Weapon shooting sound</br>
	&emsp;&emsp;❏ Target hit sound</br>
	&emsp;&emsp;❏ Finish level sound</br>
❏ Platforms</br>
	&emsp;&emsp;❏ Idle platforms</br>
	&emsp;&emsp;❏ Moving platforms</br>
❏ Level exit/completion</br>
	&emsp;&emsp;❏ Move to next level</br>
❏ Player</br>
	&emsp;&emsp;✓ Movement</br>
	&emsp;&emsp;✓ Walk animation</br>
	&emsp;&emsp;✓ Shooting animation</br>
	&emsp;&emsp;❏ Death</br>
❏ Weapon</br>
	&emsp;&emsp;❏ Correct arrow movement</br>
	&emsp;&emsp;❏ Hit</br>
	&emsp;&emsp;❏ Charge indicator</br>
❏ Targets</br>
	&emsp;&emsp;❏ Add targets</br>
	&emsp;&emsp;❏ Target break animation</br>
❏ Points</br>
	&emsp;&emsp;❏ Add point calculator</br>
❏ Game over</br>
	&emsp;&emsp;❏ Add game over background</br>
	&emsp;&emsp;❏ Add try again button</br>
❏ Pause</br>
❏ Enemies</br>
	&emsp;&emsp;❏ Enemy assets</br>
	&emsp;&emsp;❏ Add enemies</br>
	&emsp;&emsp;❏ Enemy AI</br>
	&emsp;&emsp;❏ Enemy kill</br>
❏ Fix bugs</br>

Credits</br>
Audio // https://pixabay.com/users/sergequadrado-24990007/</br>
Font // https://www.fontspace.com/a-adulsa-script-font-f53443
