#ifndef __gameover__
#define __gameover__
#include "vector2D.h"
#include "mydrawengine.h"

class gameover

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