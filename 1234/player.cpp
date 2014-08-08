#include "player.h"
#include "myinputs.h"
#include "gamecode.h"

	

	void player::init()  //adapted
	{
		position.set(150, 344);
		image.LoadBitmapA("nyan.bmp");

	source.top = 0;
	source.left = 0;
	source.right = 100;
	source.bottom = 100;

	alive = true;
	

	}


	void player::update() 
	{
		
		MyInputs::GetInstance()->SampleKeyboard(); 
		Vector2D temp(0, 7); 
		


		if (MyInputs::GetInstance()->KeyPressed(DIK_W))   //my code
		{ 
			if (position.YValue >= 0) 
			{ 
				position -= temp; 
				
			}
		}
		else if (MyInputs::GetInstance()->KeyPressed(DIK_S))  //my code
		{ 
			if (position.YValue <= SCREENHEIGHT - source.bottom) 
			{ 

				position += temp;  
			} 
		} 
		else 
		if (position.YValue < SCREENHEIGHT - source.bottom)  //my code
		{ 
			Vector2D cazi_in_pula_mea(0, 4); 
			position = position + cazi_in_pula_mea; 
		} 
		else if(position.YValue >= SCREENHEIGHT - source.bottom)  //my code
		{ 
			alive = false; 
		} 

	}
	


	void player::Draw() //adapted
	{
	
		dest.top = 0 + position.YValue;
		dest.left = 0 + position.XValue;
		dest.right = 100 + position.XValue;
		dest.bottom = 100 + position.YValue;

		MyDrawEngine::GetInstance()->Blit(dest, source, &image);
	
	}


	void player::Terminate()
	{
		image.Release();
	}

	