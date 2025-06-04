#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

/*
This program is a template for an SFML project using CMake and Vcpkg.
You can duplicate the folder containing this project to easily set up a new
SFML program.
Just delete the "out" folder in the new project , or else you might get CMake errors.
*/

void drawPixel(sf::RenderWindow& window, sf::Vector2i position, sf::Color color) {
	float pX{ static_cast<float>(position.x) };
	float pY{ static_cast<float>(position.y) };
	
	std::array<sf::Vertex, 1> pixel {
		sf::Vertex{
			sf::Vector2f{pX, pY},
			color
		}
	};
	window.draw(pixel.data(), 1, sf::PrimitiveType::Points);
}

int main() {
	sf::RenderWindow window{
		sf::VideoMode::getFullscreenModes().at(0),
		"SFML Demo"
	};
	sf::Clock c;
	auto last{ c.getElapsedTime() };

	while (window.isOpen()) {
		while (const std::optional event{ window.pollEvent() }) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}
		window.clear();

		auto now{ c.getElapsedTime() };
		auto diff{ now - last };
		last = now;
		std::cout << 1 / diff.asSeconds() << " FPS " << std::endl;

		/*
		* DRAWING GOES HERE.
		*/
		for (int32_t x{ 0 }; x < 500; ++x) {
			int32_t y{ static_cast<int32_t>(2.0 / 3.0 * x + 40) };
			drawPixel(window, sf::Vector2i{ x, y }, sf::Color::White);
		}


		window.display();
	}

	return 0;
}


