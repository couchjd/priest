#include <SFML/Graphics.hpp>
#include "Sprites.h"

namespace TESTING {
  sf::Sprite* sprites[5];

  void initSprites(sf::Sprite** sprites, const sf::Texture &characterSheet) {
    sprites[0] = new sf::Sprite();
    sprites[0]->setTexture(characterSheet);
    sprites[0]->setTextureRect(sf::IntRect(PRIEST_FRONT_LEFT));
    sprites[0]->setPosition(200.f, 200.f);
    sprites[0]->setScale(4, 4);

    sprites[1] = new sf::Sprite();
    sprites[1]->setTexture(characterSheet);
    sprites[1]->setTextureRect(sf::IntRect(PRIEST_FRONT_RIGHT));
    sprites[1]->setPosition(300.f, 200.f);
    sprites[1]->setScale(4, 4);

    sprites[2] = new sf::Sprite();
    sprites[2]->setTexture(characterSheet);
    sprites[2]->setTextureRect(sf::IntRect(PRIEST_BACK_LEFT));
    sprites[2]->setPosition(400.f, 200.f);
    sprites[2]->setScale(4, 4);

    sprites[3] = new sf::Sprite();
    sprites[3]->setTexture(characterSheet);
    sprites[3]->setTextureRect(sf::IntRect(PRIEST_BACK_RIGHT));
    sprites[3]->setPosition(500.f, 200.f);
    sprites[3]->setScale(4, 4);

    sprites[4] = new sf::Sprite();
    sprites[4]->setTexture(characterSheet);
    sprites[4]->setTextureRect(sf::IntRect(PRIEST_LEFT_STOP));
    sprites[4]->setPosition(600.f, 200.f);
    sprites[4]->setScale(4, 4);
  }
}