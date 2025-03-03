#ifndef GAME_SETTINGS_HPP
#define GAME_SETTINGS_HPP
#include "defaults/settings.hpp"

class GameSettings {
public: 

  GameSettings(){
    //LoadSettings();  
    
    SetDefaults();
  }

  void SetDefaults() {
    window_height = WINDOW_HEIGHT;
    window_width = WINDOW_WIDTH;
    target_fps = TARGET_FPS;
  }

  const int getWindowHeight(){
    return window_height;
  }

  const int getWindowWidth(){
    return window_width;
  }


private:
  int window_height, window_width;
  int target_fps;
};

#endif
