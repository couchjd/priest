#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sstream>

#define TITLE           "priest"
#define VIEWPORT_SIZE   640.f

std::string itos(int input) {
  std::stringstream ss;
  ss << input;
  return ss.str();
}

int main() {
  int viewPortX = 0.f;
  int viewPortY = 0.f;
  
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

  std::string string1 = "Width:\t";
  viewPortBackground.getSize().x;
  std::string string2 = string1 + itos(viewPortBackground.getSize().x) + "\n";
  string2 += "Height:\t" + itos(viewPortBackground.getSize().y);

  sf::Text text;
  text.setFont(font);
  text.setString(string2);
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::White);
  text.setPosition(((2*border) + VIEWPORT_SIZE), border);

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
          if(viewPortY < viewPortBackground.getSize().y) {
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
          if(viewPortX < viewPortBackground.getSize().x) {
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
    window.draw(text);
    window.display();
  }
  return 0;
}