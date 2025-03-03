#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include "models/game-settings.hpp"
#include "screens/intro.hpp"

class RuinedLight {
public:
  static RuinedLight* StartGame(){
    RuinedLight* game = new RuinedLight;

    while(!WindowShouldClose()){
      BeginDrawing();

        IntroScreen(&game->settings);

      EndDrawing(); 
    }

    return game;
  }

private: 
  RuinedLight(){
    InitWindow(settings.getWindowWidth(), settings.getWindowHeight(), "Ruined Light");
  } 
  ~RuinedLight(){
    CloseWindow();
  }

  GameSettings settings;
};

#endif
