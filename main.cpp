#include <SFML/Graphics.hpp>
#include "Game.h"
#include <time.h>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(600, 600), "Game 15");
	window.setFramerateLimit(90);

	Font font;
	font.loadFromFile("calibri.ttf");

	Text text("New Game - F2, Exit - Esc", font, 20);
	text.setFillColor(Color::Cyan);
	text.setPosition(4.f, 4.f);

	Game game;
	game.setPosition(50.f, 50.f);

	Event event;
	int move_counter = 0;	

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
			if (event.type == Event::KeyPressed)
			{
				
				if (event.key.code == Keyboard::Escape) 
					window.close();
				if (event.key.code == Keyboard::Left) 
					game.Move(Direction::Right);
				if (event.key.code == Keyboard::Right) 
					game.Move(Direction::Left);
				if (event.key.code == Keyboard::Up) 
					game.Move(Direction::Down);
				if (event.key.code == Keyboard::Down) 
					game.Move(Direction::Up); 
				if (event.key.code == Keyboard::F2)
				{
					game.Init();
					move_counter = 100;
				}
			}
		}
	
		if (move_counter -- > 0) 
			game.Move((Direction)(rand() % 4));

		window.clear();
		window.draw(game);
		window.draw(text);
		window.display();
	}

	return 0;
}