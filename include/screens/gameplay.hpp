#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "models/game-settings.hpp"
#include "models/lights.hpp"
#include "models/player.hpp"
#include "helpers/get-center.hpp"
#include "defaults/fonts.hpp"
#include "defaults/data-paths.hpp"
#include "dialog/gameplay.hpp"
#include "defaults/screen-types.hpp"

class GameplayScreen {
public:
  GameplayScreen(){
    followLight = new TopDownLights(200.00f, YELLOW, 10, 1000);
    player = new Player({(float)GetScreenWidth() /2, (float)GetScreenHeight() / 2});
    RecreateBackgroundTexture();
  }

  void RecreateBackgroundTexture() {
    // Unload existing texture if it exists
    if (backgroundTexture.id > 0) {
      UnloadRenderTexture(backgroundTexture);
    }
    
    // Create new render texture with current screen size
    backgroundTexture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
    BeginTextureMode(backgroundTexture);
      ClearBackground(DARKGRAY);
    EndTextureMode();

    // Recreate light textures
    followLight->HandleScreenResize();

    // Update player position to center
    player->UpdatePosition({
      (float)GetScreenWidth() / 2, 
      (float)GetScreenHeight() / 2
    });
  }
  
  void GameLoop(){
    // Check for window resize
    if (IsWindowResized()) {
      RecreateBackgroundTexture();
    }

    Vector2 mousePos = GetMousePosition();
    mousePos.y = GetScreenHeight() - mousePos.y;
    followLight->UpdateLightPosition(mousePos);
    followLight->PrepareLightMask();
    
    BeginDrawing();
    ClearBackground(BLACK);
    followLight->DrawLightEffect(backgroundTexture.texture);
    player->Draw();
    ShowCursor();
    EndDrawing(); 
  } 

  void HandleKeyPress(int key){
    Vector2 playerPos = player->GetPosition();
    if(key == KEY_W){
      playerPos.y -= 1;
    }
    if(key == KEY_A){
      playerPos.x -= 1;
    }
    if(key == KEY_S){
      playerPos.y += 1;
    }
    if(key == KEY_D){
      playerPos.x += 1;
    }

    player->UpdatePosition(playerPos);
  }
  
private:
  TopDownLights* followLight;
  Player* player;
  RenderTexture2D backgroundTexture;
};

#endif
