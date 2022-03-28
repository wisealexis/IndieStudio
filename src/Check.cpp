/*
** EPITECH PROJECT, 2021
** B-YEP-400-LIL-4-1-indiestudio-hugo.mondou
** File description:
** Check
*/

#include "main.hpp"

int check_files()
{
    std::string sources[51] = {"assets/texture/master_volume.png",
    "assets/texture/game_volume.png",
    "assets/texture/menu_volume.png",
    "assets/texture/map_density.png",
    "assets/texture/two_players_button.png",
    "assets/texture/four_players_button.png",
    "assets/texture/nb_bombs_button.png",
    "assets/texture/back_button.png",
    "assets/texture/one.png",
    "assets/texture/infinity.png",
    "assets/music/bomberman-menu.mp3",
    "assets/texture/Bomberman.png",
    "assets/texture/Super_Bomberman_Logo.png",
    "assets/texture/new_game_button.png",
    "assets/texture/load_game_button.png",
    "assets/texture/settings_button.png",
    "assets/texture/credits_button.png",
    "assets/texture/exit_button.png",
    "assets/texture/Metal.png",
    "assets/texture/break.png",
    "assets/texture/map.png",
    "assets/models/tnt/textures/palette_blanche.png",
    "assets/models/tnt/scene.gltf",
    "assets/models/tnt/textures/palette_baseColor.png",
    "assets/models/bomberman_fire/textures/Fire_baseColor.png",
    "assets/models/bomberman_fire/scene.gltf",
    "assets/music/grass.mp3",
    "assets/music/bomb-sound.mp3",
    "assets/music/bomberman-game.mp3",
    "assets/texture/quit_button.png",
    "assets/texture/save_and_quit_button.png",
    "assets/models/steve/textures/02_-_Default_baseColor.png",
    "assets/models/steve/scene.gltf",
    "assets/texture/steve_head.png",
    "assets/models/Skeleton/textures/02_-_Default_baseColor.png",
    "assets/models/Skeleton/scene.gltf",
    "assets/texture/skeletton_head.png",
    "assets/models/Creeper/textures/02_-_Default_baseColor.png",
    "assets/models/Creeper/scene.gltf",
    "assets/texture/creeper_head.png",
    "assets/models/Zombie/textures/02_-_Default_baseColor.png",
    "assets/models/Zombie/scene.gltf",
    "assets/texture/zombie_head.png",
    "assets/texture/cross_dead.png",
    "assets/texture/minus_button.png",
    "assets/texture/percent.png",
    "assets/texture/plus_button.png",
    "assets/texture/sound_volume.png",
    "assets/texture/hitmarker.png",
    "assets/music/hitmarker.mp3",
    "assets/texture/credits.png"};

    CheckFiles *checkfiles = new CheckFiles();
    return (checkfiles->Check(sources, 51));
}