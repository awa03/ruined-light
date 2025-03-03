#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include "models/game-settings.hpp"

class RuinedLight {
public:
  static RuinedLight* StartGame(){
    RuinedLight* game = new RuinedLight;
    return game;
  }

private: 
  RuinedLight(){
  } 

  GameSettings settings;
};

#endif
