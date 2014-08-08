#include "background.h"



void background::init() //adapted
{
	position.set(0, 0);

	image.LoadBitmapA("background.bmp");


	source.top = 0;
	source.left = 0;
	source.right = 1100;
	source.bottom = 900;

}
void background::update()//my code
{

	
	
	Vector2D temp(30, 0);

	
	position = position + temp;

	source.left = 0 + position.XValue;
	source.right = 1100 + position.XValue;

	

	if (source.right >= 1600) 
	{
		source.right = 1100;
		source.left = 0;

		position.set(0, 0);
	}

}


void background::Draw()//my code
{

	dest.top = 0;
	dest.left = 0;
	dest.right = 1100;
	dest.bottom = 900;
	//adapted
	MyDrawEngine::GetInstance()->Blit(dest, source, &image);
}

 
void background::Terminate()
{
	image.Release();
}