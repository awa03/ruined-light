#ifndef INTRO_HPP
#define INTRO_HPP

#include <raylib.h>
#include "models/game-settings.hpp"
#include "helpers/get-center.hpp"
#include "defaults/fonts.hpp"
#include "dialog/intro.hpp"

inline void IntroScreen(GameSettings* settings){
  auto screenCenterTitle = getCenterScreen(TITLE, HEADER_1);
  auto screenCenterSubTitle = getCenterScreen(SUB_TITLE, HEADER_3);

  // offset the subtitle
  screenCenterSubTitle.second += 300;

  ClearBackground(BLACK);

  DrawText(TITLE, screenCenterTitle.first, screenCenterTitle.second, HEADER_1, LIGHTGRAY);
  DrawText(SUB_TITLE, screenCenterSubTitle.first, screenCenterSubTitle.second, HEADER_3, LIGHTGRAY);

}

#endif
