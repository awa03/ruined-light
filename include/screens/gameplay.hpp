#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include <raylib.h>
#include <iostream>
#include "models/game-settings.hpp"
#include "helpers/get-center.hpp"
#include "defaults/fonts.hpp"
#include "defaults/data-paths.hpp"
#include "dialog/gameplay.hpp"
#include "defaults/screen-types.hpp"

class GameplayScreen {
public:
  GameplayScreen(){

  }
  void GameLoop(){
    BeginDrawing();
    ClearBackground(WHITE);
    ShowCursor();
    EndDrawing(); 
  } 
  
private:
};

#endif
