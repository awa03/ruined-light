#ifndef GET_CENTER_HPP
#define GET_CENTER_HPP
#include <iostream>
#include "models/game-settings.hpp"

const std::pair<int, int> getCenterScreen(const char* text, int fontSize){
  Vector2 textSize = MeasureTextEx(GetFontDefault(), text, fontSize, 1);
  return { (GetScreenWidth() - textSize.x) / 2, (GetScreenHeight() - textSize.y) / 2 };
}

#endif
