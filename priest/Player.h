#include <SFML/Graphics.hpp>

#ifndef PLAYER_H
#define PLAYER_H

enum stats {
  STR,
  INT,
  WIS,
  DEX,
  CON,
  CHA,
  HP_MAX,
  HP_CUR
};

enum facing {
  FRONT,
  BACK,
  LEFT,
  RIGHT
};

class Player {
public:
  sf::Sprite pSprite;
  int stats[8];
  int facing;
};



#endif // !PLAYER_H
