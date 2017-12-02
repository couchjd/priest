#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define TITLE "priest"

int main() {
  sf::RenderWindow window(sf::VideoMode().getDesktopMode(), TITLE, sf::Style::Fullscreen);
  
  sf::Image viewPortColor;
  viewPortColor.create(640.f, 640.f, sf::Color::White);

  sf::Texture viewPortBackground;
  viewPortBackground.loadFromImage(viewPortColor);

  sf::Sprite viewPort;
  float border = (window.getSize().y - 640.f) / 2;
  viewPort.setPosition(border, border);
  viewPort.setTexture(viewPortBackground);
  
  sf::RectangleShape player(sf::Vector2f(32.f, 32.f));
  player.setFillColor(sf::Color::Red);
  player.setPosition(sf::Vector2f(viewPort.getPosition().x + 320.f, viewPort.getPosition().y + 320.f));

  sf::Font font;
  font.loadFromFile("./fonts/8-Bit Madness.ttf");

  sf::Text text;
  text.setFont(font);
  text.setString("Strength:\t18\nIntelligence:\t18\nWisdom:\t18");
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::White);
  text.setPosition(((2*border) + 640.f), border);

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed) {
        window.close();
      }

      if(event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Up) {
          player.setPosition(player.getPosition().x, player.getPosition().y - 32.f);
        }
        if(event.key.code == sf::Keyboard::Down) {
          player.setPosition(player.getPosition().x, player.getPosition().y + 32.f);
        }
        if(event.key.code == sf::Keyboard::Left) {
          player.setPosition(player.getPosition().x - 32.f, player.getPosition().y);
        }
        if(event.key.code == sf::Keyboard::Right) {
          player.setPosition(player.getPosition().x + 32.f, player.getPosition().y);
        }
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      window.close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      player.setPosition(player.getPosition().x, player.getPosition().y - 1.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      player.setPosition(player.getPosition().x, player.getPosition().y + 1.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      player.setPosition(player.getPosition().x - 1.f, player.getPosition().y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      player.setPosition(player.getPosition().x + 1.f, player.getPosition().y);
    }

    window.clear(sf::Color::Black);
    window.draw(viewPort);
    window.draw(player);
    window.draw(text);
    window.display();
  }
  return 0;
}