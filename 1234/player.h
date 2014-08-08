#ifndef __playerNyan__
#define __playerNyan__
#include "vector2D.h"
#include "mydrawengine.h"

class player //adapted

{

private:
	Vector2D position;


	MyPicture image;

	
public:
		RECT source, dest;
	bool alive; //my code

	void init();

	void update();

	void Draw();

	void Terminate();

};
 
#endif