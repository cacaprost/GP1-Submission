#ifndef __background__
#define __background__
#include "vector2D.h"
#include "mydrawengine.h"

class background //adapted

{

private:
	Vector2D position;
	RECT source, dest;

	MyPicture image;
public:

	void init();

	void update();

	void Draw();

	void Terminate();

};

#endif