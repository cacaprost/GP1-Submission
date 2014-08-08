#include "obstacle.h"
#include "myinputs.h"
#include "player.h"

void obstacle::init(int type, int location) //my code
{
	typec = type;
	locationc = location;
								
	switch (type)						
	{
		case 0:
			image.LoadBitmapA("obstacle1.bmp");
			break;
		case 1:
			image.LoadBitmapA("obstacle2.bmp");
			break;
		case 2:
			image.LoadBitmapA("obstacle3.bmp");
			break;
		case 3:
		default:
			image.LoadBitmapA("obstacle4.bmp");
			break;
	}

	source.top = 0;
	source.left = 0;
	source.right = 100;
	source.bottom = 100;

	terminate = false;
}

void obstacle::update()			//my code
{
	
	MyInputs::GetInstance()->SampleKeyboard();
	Vector2D temp(10, 0);

	position = position - temp;

	dest.left =  1020 + position.XValue;
	dest.right = 1120 + position.XValue;

	if (dest.right < 0)
	{

		Terminate();
	}

}


void obstacle::Draw() //my code
{ 
	
	switch (typec)
	{
	case 0:
		if (locationc)
			dest.bottom = 310;
		else
		{
			dest.bottom = 770;
			dest.top = 670;
		}
		break;
	case 1:
		if (locationc)
		dest.bottom = 100;
		else{
			dest.bottom = 800;
			dest.top = 400;
		}
		break;
	case 2:
		if (locationc)
		dest.bottom = 310;
		else{
			dest.bottom = 800;
			dest.top = 500;
		}
		break;

	case 3:
	default:
		if (locationc)
		dest.bottom = 310;
		else
		{
			dest.bottom = 800;
			dest.top = 400;

		}
		break;
	}

	if (locationc == 1)
		dest.top = 0;


	if (dest.left == 0) {
		dest.left = 1020;
		dest.right = 1120;
	}
	//adapted
	MyDrawEngine::GetInstance()->Blit(dest, source, &image); 
}
void obstacle::Terminate()			
{

	terminate = true;
	image.Release();
}