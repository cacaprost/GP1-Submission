#ifndef __splash__
#define __splash__
#include "vector2D.h"
#include "mydrawengine.h"

class splash //adapted

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