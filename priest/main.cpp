#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Sprites.h"
#include "Utility.h"
#include "testing.h"

#define TITLE           "priest"
#define VIEWPORT_SIZE   640.f

Player player;

int main() {
  srand(time(NULL));

  sf::Texture characterSheet;
  characterSheet.loadFromFile("Characters.png");

  TESTING::initSprites(TESTING::sprites, characterSheet);

  sf::Sprite playerSprite;
  playerSprite.setTexture(characterSheet);
  playerSprite.setTextureRect(sf::IntRect(PRIEST_FRONT_LEFT));
  player.pSprite = playerSprite;
  player.pSprite.setPosition(100.f, 100.f);
  player.pSprite.setScale(4, 4);

  int viewPortX = 0.f;
  int viewPortY = 0.f;

  sf::RenderWindow window(sf::VideoMode().getDesktopMode(), TITLE /*, sf::Style::Fullscreen*/);

  sf::Texture viewPortBackground;
  if(!viewPortBackground.loadFromFile("background1.bmp")) {
    printf("Failed to load sprite sheet.\n");
  }
  
  sf::Sprite viewPort;
  float border = (window.getSize().y - VIEWPORT_SIZE) / 2;
  viewPort.setPosition(border, border);
  viewPort.setTexture(viewPortBackground);
  viewPort.setTextureRect(sf::IntRect(viewPortX, viewPortY, VIEWPORT_SIZE, VIEWPORT_SIZE));

  sf::Font font;
  font.loadFromFile("./fonts/8-Bit Madness.ttf");

  std::string statLabelsString = "Strength:\nIntelligence : \nWisdom : \nDexterity : \nConstitution : \nCharisma : \n\nHP:";
  std::string statValuesString = statString(player.stats);
  
  sf::Text labels;
  labels.setFont(font);
  labels.setString(statLabelsString);
  labels.setCharacterSize(24);
  labels.setFillColor(sf::Color::White);
  labels.setPosition(((2 * border) + VIEWPORT_SIZE), border);

  sf::Text values;
  values.setFont(font);
  values.setString(statValuesString);
  values.setCharacterSize(24);
  values.setFillColor(sf::Color::White);
  values.setPosition(labels.getPosition().x + 200, border);

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed) {
        window.close();
      }

      if(event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Up) {
          if(!(player.facing == BACK)) {
            player.facing = BACK;
            player.pSprite.setTextureRect(sf::IntRect(PRIEST_BACK_LEFT));
          }  
        }
        if(event.key.code == sf::Keyboard::Down) {
          if(!(player.facing == FRONT)) {
            player.facing = FRONT;
            player.pSprite.setTextureRect(sf::IntRect(PRIEST_FRONT_LEFT));
          }
        }
        if(event.key.code == sf::Keyboard::Left) {
          if(!(player.facing == LEFT)) {
            player.facing = LEFT;
            player.pSprite.setTextureRect(sf::IntRect(PRIEST_LEFT_STOP));
          }
        }
        if(event.key.code == sf::Keyboard::Right) {
          if(!(player.facing == RIGHT)) {
            player.facing = RIGHT;
            player.pSprite.setTextureRect(sf::IntRect(PRIEST_RIGHT_STOP));
          }
        }
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      window.close();
    }

    window.clear(sf::Color::Black);
    window.draw(viewPort);
    window.draw(labels);
    window.draw(values);

    for(int x = 0; x < 5; x++)
      window.draw(*TESTING::sprites[x]);

    window.draw(player.pSprite);
    window.display();
  }
  return 0;
}