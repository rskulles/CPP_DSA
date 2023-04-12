#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Title",
                          sf::Style::Fullscreen);

  while (window.isOpen()) {
    sf::Event e;
    while (window.pollEvent(e)) {
      switch (e.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::KeyReleased:
        if (e.key.code == sf::Keyboard::Escape) {
          window.close();
        }
        break;
      default:
        break;
      }
    }

    window.clear(sf::Color::Cyan);
    window.display();
  }
  return 0;
}
