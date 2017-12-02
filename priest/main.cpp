#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define TITLE "priest"

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), TITLE);

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();

    window.display();
  }
  return 0;
}