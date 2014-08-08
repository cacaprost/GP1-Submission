#ifndef __obstacol__
#define __obstacol__
#include "vector2D.h"
#include "mydrawengine.h"

class obstacle //adapted

{

private:
	Vector2D position;

	int typec;//my code
	int locationc;//my code
	MyPicture image;

public:
	bool terminate;

	void init(int type, int position);//my code

	RECT source, dest;

	void update();

	void Draw();

	void Terminate();

};

#endif