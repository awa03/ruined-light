#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include "models/game-settings.hpp"
#include "screens/intro.hpp"
#include "screens/gameplay.hpp"
#include "defaults/screen-types.hpp"

class RuinedLight {
public:
  static RuinedLight* StartGame(){
    RuinedLight* game = new RuinedLight;  
    return game;
  }

private: 
  RuinedLight(){
    InitWindow(settings.getWindowWidth(), settings.getWindowHeight(), "Ruined Light");
    screen = 0;


    IntroScreen intro;
    GameplayScreen gameplay;

    while(!WindowShouldClose()){
      if(screen == INTRO){
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
          screen = GAMEPLAY;
        }
        else intro.GameLoop();
      }
      else if(screen == GAMEPLAY){
        gameplay.GameLoop();
      }
      else {
        break; // exit condition
      }
    }
  } 
  ~RuinedLight(){
    CloseWindow();
  }

  void handleIntro(IntroScreen* intro){
    intro->GameLoop(); 
  }

  GameSettings settings;
  int screen;
};

#endif
