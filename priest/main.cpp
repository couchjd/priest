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
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      window.close();
    }
    
    window.clear(sf::Color::Magenta);
    window.draw(player);
    window.display();
  }
  return 0;
}