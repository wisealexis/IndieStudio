![Banner](https://uploads-ssl.webflow.com/5e17cf86ba9f9e6b1dea17b8/5e17d32acf33862f656fe704_Indie_Logos%209.png)
*Indie Studio - Bomberman game written in CPP, powered by [Raylib](https://github.com/raysan5/raylib)*  


# Features
- Local multiplayer up to 4 players
- Fullscreen support
- Custom map support
- Volume adjustment settings
- Cross-compatible between Linux and Windows

# Installation

**LINUX**
- Clone the repository
- `cmake . && cmake --build .`
- `./bomberman`

**WINDOWS**
- Clone the repository
- `cd build`
- `cmake .. -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Release`
- `cmake --build . --config Release`
- `mv Release/bomberman.exe ../`
- `./bomberman.exe`

# Configs

Default keybindings:
- ESC for pause / back
- ZQSD / Space for P1
- Arrows / Enter for P2
- TFGH / Y for P3
- IJKL / U for P4
- P to pause music
- Tab to toggle in-game HUD
- Mouse controls menus

# Custom maps
You can edit the game's map by editing `map.txt`.
It should be in the same folder as the binary.

The map should be at least 6\*6 in size.
There needs to be at least 2 players alive to load the map.

Missing boundaries will be added automatically.

**To use your custom map, press `load game`.**
Pressing "New game" will generate a new map with the default settings, with the players spawning in the corners of the map.

Characters to be used for the map:

- `#`: Unbreakable walls
- `B`: Breakable walls
- ` `: Empty walkable spaces
- `a` to `z`: Ticking bombs (a being a new bomb and z being the closest to detonation)
- `{`,`|`,`}`: Ongoing explosions
- `1` to `4`: Players

# Thanks

Thanks to [raysan](https://github.com/raysan5) for his work on Raylib and all the members of the Raylib discord for their help.
