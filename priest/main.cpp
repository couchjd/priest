#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include "Player.h"
#include "Sprites.h"

#define TITLE           "priest"
#define VIEWPORT_SIZE   640.f

std::string itos(int input) {
  std::stringstream ss;
  ss << input;
  return ss.str();
}

std::string statString(int* stats) {
  return  itos(stats[STR]) + "\n" + itos(stats[INT]) + "\n" + itos(stats[WIS]) + "\n" + itos(stats[DEX]) + "\n" +
          itos(stats[CON]) + "\n" + itos(stats[CHA]) + "\n\n" + itos(stats[HP_CUR]) + "\\" + itos(stats[HP_MAX]);
}

int main() {
  Player player;
  sf::Texture playerSheet;
  playerSheet.loadFromFile("Characters.png");

  sf::Sprite playerSprite;
  playerSprite.setTexture(playerSheet);
  playerSprite.setTextureRect(sf::IntRect(PRIEST_FRONT_LEFT));
  player.pSprite = playerSprite;
  player.pSprite.setPosition(100.f, 100.f);
  player.pSprite.setScale(3, 3);

  int viewPortX = 0.f;
  int viewPortY = 0.f;

  player.stats[STR] = 18;
  player.stats[INT] = 16;
  player.stats[WIS] = 14;
  player.stats[DEX] = 17;
  player.stats[CON] = 18;
  player.stats[CHA] = 13;
  player.stats[HP_CUR] = 55;
  player.stats[HP_MAX] = 63;

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
  labels.setPosition(((2*border) + VIEWPORT_SIZE), border);

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
    window.draw(player.pSprite);
    window.display();
  }
  return 0;
}