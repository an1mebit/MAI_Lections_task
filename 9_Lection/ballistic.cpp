#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace sf;
using namespace std;

#define PI 3.14;

class object
{
	Texture tex;
	Sprite sprite;
public:
	float x, y, w, h, alfa;

	object(float X, float Y, float W, float H)
	{
		tex.loadFromFile("sphere.png");

		x = X;	y = Y;	w = W;	h = H;
		alfa = 0;
		sprite.setTexture(tex);
		sprite.setPosition(x, y);
		sprite.setOrigin(w / 2, h / 2);
	}

	void alfaMove(float& time, float Alfa, float v0)
	{
		alfa = Alfa * PI;
		alfa = alfa / 180;

		if (y <= 600)
		{
			x = x + v0 * time * cos(alfa);
			y = y + v0 * time * sin(alfa) + ((10 * time * time) / 2);
		}
	}

	void draw(RenderWindow& window)
	{
		alfa = alfa * 180;
		alfa = alfa / PI;
		sprite.setRotation(alfa);

		sprite.setPosition(x, y);
		window.draw(sprite);
	}
};

int main()
{
	RenderWindow window(VideoMode(1200, 600), "Sphere");

	object spher(100, 100, 10, 600);

	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

		}

		if (spher.x > 1200) spher.x = 0;
		if (spher.x < 0) spher.x = 1200;
		if (spher.y < 0) spher.y = 0;

		spher.draw(window);

		spher.alfaMove(time, -45, 6);

		window.display();
	}

	return 0;
}
