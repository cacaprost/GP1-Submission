#include "splash.h"
#include "myinputs.h"


void splash::init() //adapted
{

	
	position.set(0, 0);

	image.LoadBitmapA("splash.bmp");


	source.top = 0;
	source.left = 0;
	source.right = 1100;
	source.bottom = 900;

}

void splash::update()  //adapted
{

	
	
	Vector2D temp(0, 0);

	
	position = position + temp;

	source.left = 0 + position.XValue;
	source.right = 1100 + position.XValue;


}
void splash::Draw()
{

	dest.top = 0;
	dest.left = 0;
	dest.right = 1100;
	dest.bottom = 900;
	//adapted
	MyDrawEngine::GetInstance()->Blit(dest, source, &image);
}


void splash::Terminate()
{
}