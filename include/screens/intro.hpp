#ifndef INTRO_HPP
#define INTRO_HPP

#include <raylib.h>
#include <iostream>
#include "models/game-settings.hpp"
#include "helpers/get-center.hpp"
#include "defaults/fonts.hpp"
#include "defaults/data-paths.hpp"
#include "dialog/intro.hpp"
#include "defaults/screen-types.hpp"

class IntroScreen {
public:
  IntroScreen() {
    LoadTextures();
    MaximizeWindow();
  }
  ~IntroScreen(){
    UnloadTextures();
  }

  void GameLoop(){
    BeginDrawing();
    auto screenDimensions = getScreenDimensions();

    // offset dimensions
    screenDimensions.first += 75;
    screenDimensions.second -= 300;

    auto screenCenterTitle = getCenterScreen(TITLE, HEADER_1);
    auto screenCenterSubTitle = getCenterScreen(SUB_TITLE, HEADER_3);

    // offset y
    screenCenterTitle.second += 200;

    // offset the subtitle
    screenCenterSubTitle.second += 400;

    ClearBackground(BLACK);

    ShowCursor();

    DrawText(TITLE, screenCenterTitle.first, screenCenterTitle.second, HEADER_1, LIGHTGRAY);
    DrawText(SUB_TITLE, screenCenterSubTitle.first, screenCenterSubTitle.second, HEADER_3, LIGHTGRAY);

    DrawTexture(logoTexture, screenDimensions.first / 2 - logoTexture.width / 2, 
            (screenDimensions.second / 2) - (logoTexture.height / 2), WHITE);

    EndDrawing(); 
  }

private:
  Texture2D logoTexture;

  void LoadTextures(){
    logoTexture = LoadTexture("../resources/game_logo.png");
  }
  void UnloadTextures(){
    UnloadTexture(logoTexture);
  }
};

#endif
