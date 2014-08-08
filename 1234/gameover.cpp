#include "gameover.h"
#include "myinputs.h"


void gameover::init() 
{

	
	position.set(0, 0);

	image.LoadBitmapA("gameover.bmp");


	source.top = 0;
	source.left = 0;
	source.right = 1100;
	source.bottom = 900;

}

void gameover::update()
{

	
	
	Vector2D temp(0, 0);

	
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
void gameover::Draw()
{

	dest.top = 0;
	dest.left = 0;
	dest.right = 1100;
	dest.bottom = 900;

	MyDrawEngine::GetInstance()->Blit(dest, source, &image);
}


void gameover::Terminate()
{
	//image.Release();
}