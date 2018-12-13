#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;

void getplayercoordinateforview(float x, float y) {
	float tempX = x; float tempY = y;

	if (x < 320) tempX = 320;
	if (y < 240) tempY = 240;
	if (y > 554) tempY = 554;	

	view.setCenter(tempX, tempY); //слідкуємо за зіркою
	

}


void viewmap(float time) { 


	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move(0.1*time, 0);//скролим карту вправо
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, 0.1*time);//скролим карту вниз 
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move(-0.1*time, 0);//скролим карту вліво
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, -0.1*time);//скролим карту вправо 
	}

}
