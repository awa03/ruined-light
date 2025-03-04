#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>

class Player {
public:
  Player(Vector2 position) : playerPosition(position){
  }

  void UpdatePosition(Vector2 newPosition){
    playerPosition = newPosition; 
  }

  Vector2 GetPosition(){
    return playerPosition;
  }

  void Draw(){
    DrawCircleV(playerPosition, 5, RED);
  }

private:
  Vector2 playerPosition;

};

#endif 
