#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	// Create render window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Main Window)");
	while (window.isOpen()) {
		sf::Event event;

		// If we get a close event, close the window.
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		// Clear entire screen to black.
		window.clear(sf::Color::Black);

		// Purple Circle
		sf::CircleShape circle(50);
		circle.setFillColor(sf::Color(150, 50, 250));
		window.draw(circle);

		// Red Rectangle
		sf::RectangleShape rectangle(sf::Vector2f(200, 200));
		rectangle.setFillColor(sf::Color(255, 55, 55));
		rectangle.setPosition(sf::Vector2f(200, 200));
		window.draw(rectangle);

		// Blue Triangle
		sf::CircleShape triangle(80, 3);
		triangle.setFillColor(sf::Color(55, 55, 255));
		triangle.setPosition(sf::Vector2f(0, 200));
		window.draw(triangle);

		// Display window
		window.display();
	}
}