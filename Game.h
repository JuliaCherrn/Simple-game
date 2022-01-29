#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

const int SIZE = 4;					
const int ARRAY_SIZE = SIZE * SIZE;	
const int FIELD_SIZE = 500;				
const int CELL_SIZE = 120;				

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

class Game : public Drawable, public Transformable
{
protected:
	int elements[ARRAY_SIZE];
	int empty_index;
	bool solved;
	Font font;
public:
	Game();
	void Init();
	bool Check();
	void Move(Direction direction);
public:
	virtual void draw(RenderTarget& target, RenderStates states) const;
};
