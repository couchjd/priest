#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sstream>

#define TITLE           "priest"
#define VIEWPORT_SIZE   640.f

struct stats {
  int str;
  int intel;
  int wis;
  int dex;
  int con;
  int cha;
  int hpMax;
  int hpCurr;
};

std::string itos(int input) {
  std::stringstream ss;
  ss << input;
  return ss.str();
}

std::string statString(struct stats& stats) {
  return  itos(stats.str) + "\n" + itos(stats.intel) + "\n" + itos(stats.wis) + "\n" + itos(stats.dex) + "\n" +
          itos(stats.con) + "\n" + itos(stats.cha) + "\n\n" + itos(stats.hpCurr) + "\\" + itos(stats.hpMax);
}

int main() {
  int viewPortX = 0.f;
  int viewPortY = 0.f;

  struct stats stats;
  stats.str     = 18;
  stats.intel   = 16;
  stats.wis     = 14;
  stats.dex     = 17;
  stats.con     = 18;
  stats.cha     = 13;
  stats.hpCurr  = 55;
  stats.hpMax   = 63;

  sf::RenderWindow window(sf::VideoMode().getDesktopMode(), TITLE, sf::Style::Fullscreen);

  sf::Texture viewPortBackground;
  viewPortBackground.loadFromFile("test.bmp");

  sf::Sprite viewPort;
  float border = (window.getSize().y - VIEWPORT_SIZE) / 2;
  viewPort.setPosition(border, border);
  viewPort.setTexture(viewPortBackground);
  viewPort.setTextureRect(sf::IntRect(viewPortX, viewPortY, VIEWPORT_SIZE, VIEWPORT_SIZE));

  sf::RectangleShape player(sf::Vector2f(32.f, 32.f));
  player.setFillColor(sf::Color::Red);
  player.setPosition(sf::Vector2f(viewPort.getPosition().x + VIEWPORT_SIZE / 2, viewPort.getPosition().y + VIEWPORT_SIZE / 2));

  sf::Font font;
  font.loadFromFile("./fonts/8-Bit Madness.ttf");

  std::string statLabelsString = "Strength:\nIntelligence : \nWisdom : \nDexterity : \nConstitution : \nCharisma : \n\nHP:";
  std::string statValuesString = statString(stats);
  
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
          player.setPosition(player.getPosition().x, player.getPosition().y - 32.f);
          if(viewPortY - 32.f > 0.f) {
            viewPortY -= 32.f;
          }
          viewPort.setTextureRect(sf::IntRect(viewPortX, viewPortY, VIEWPORT_SIZE, VIEWPORT_SIZE));
        }
        if(event.key.code == sf::Keyboard::Down) {
          player.setPosition(player.getPosition().x, player.getPosition().y + 32.f);
          if(viewPortY < 520.f) {
            viewPortY += 32.f;
          }
          viewPort.setTextureRect(sf::IntRect(viewPortX, viewPortY, VIEWPORT_SIZE, VIEWPORT_SIZE));
        }
        if(event.key.code == sf::Keyboard::Left) {
          player.setPosition(player.getPosition().x - 32.f, player.getPosition().y);
          if(viewPortX - 32.f > 0.f) {
            viewPortX -= 32.f;
          }
          viewPort.setTextureRect(sf::IntRect(viewPortX, viewPortY, VIEWPORT_SIZE, VIEWPORT_SIZE));
        }
        if(event.key.code == sf::Keyboard::Right) {
          player.setPosition(player.getPosition().x + 32.f, player.getPosition().y);
          if(viewPortX < /*viewPortBackground.getSize().x*/520.f) {
            viewPortX += 32.f;
          }
          viewPort.setTextureRect(sf::IntRect(viewPortX, viewPortY, VIEWPORT_SIZE, VIEWPORT_SIZE));
        }
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      window.close();
    }

    window.clear(sf::Color::Black);
    window.draw(viewPort);
    //window.draw(player);
    window.draw(labels);
    window.draw(values);
    window.display();
  }
  return 0;
}