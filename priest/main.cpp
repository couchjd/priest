#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define TITLE "priest"

int main() {
  sf::RenderWindow window(sf::VideoMode().getDesktopMode(), TITLE, sf::Style::Fullscreen);
  sf::RectangleShape player(sf::Vector2f(20.f, 20.f));
  
  player.setFillColor(sf::Color::Black);
  player.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
  
  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed) {
        window.close();
      }

      if(event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Up) {
          player.setPosition(player.getPosition().x, player.getPosition().y - 20.f);
        }
        if(event.key.code == sf::Keyboard::Down) {
          player.setPosition(player.getPosition().x, player.getPosition().y + 20.f);
        }
        if(event.key.code == sf::Keyboard::Left) {
          player.setPosition(player.getPosition().x - 20.f, player.getPosition().y);
        }
        if(event.key.code == sf::Keyboard::Right) {
          player.setPosition(player.getPosition().x + 20.f, player.getPosition().y);
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

    window.clear(sf::Color::Cyan);
    window.draw(player);
    window.display();
  }
  return 0;
}