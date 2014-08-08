// GameCode.cpp		Version 11			5/3/08	
// These three functions form the basis of a game loop in the window created in the
// wincode.cpp file

#include "gamecode.h"
#include "mydrawengine.h"
#include "mypicture.h"
#include "mysoundengine.h"
#include "mysound.h"
#include "myinputs.h"
#include <time.h>
#include "gametimer.h"
#include "errorlogger.h"
#include <math.h>
#include <cstdlib>


#include "player.h"
#include "background.h"
#include "splash.h"
#include "obstacle.h"
MyDrawEngine* pTheDrawEngine;	// A pointer to the drawing engine
MySoundEngine* pTheSoundEngine;	// A pointer to the sound engine
MyInputs* pTheInputs;

extern HWND gHwnd;				// A handle to the main window application (created and declared in wincode.cpp).
extern HINSTANCE g_hinstance;	// A handle to the program instance

// Your global objects ***********************************************************************
player* NYAN;
background* back;
splash* firstscreen;
obstacle* obstacol[4];//my code
int random_number ;//my code
time_t new_time, prev_time, prev_time2;//my code

int k =0;//my code
int x = 0;//my code


bool draw_screen = true;//my code
// Your global functions *********************************************************************
MySound* pSoundObject;


// The game !!! *********************************************************************************

ErrorType GameInit(bool bFullScreen)
// Called once before entering game loop. 
// Use this function to set up the program
// gHwnd is the handle to the window and is required by the constructors for the engines
{
	// Create the engines - this should be done before creating other DDraw objects
	pTheDrawEngine = MyDrawEngine::Start(SCREENWIDTH, SCREENHEIGHT, COLOURDEPTH, gHwnd, bFullScreen);
	pTheSoundEngine = MySoundEngine::Start(gHwnd);
	pTheInputs = MyInputs::Start(g_hinstance, gHwnd);
  
	//adapted
    pSoundObject = new MySound();
    pSoundObject->LoadWave("cat.wav");
    pSoundObject->Play(0);


    NYAN = new player();
	NYAN->init();
	back = new background();
	back->init();
	firstscreen = new splash();
	firstscreen->init();

	for (int i = 0; i < 4; i++)	//my code
		obstacol[i] = new obstacle();

	prev_time = time(NULL);
    return (SUCCESS);

		
// ******************************************************************
}

ErrorType GameMain()
// Called repeatedly - the game loop
{
	//  validation routine - should be able to alt-tab out of program
	// (Done in game main just to show that it needs to be done - better to do in MyDrawEngine. really)
	if(pTheDrawEngine->Validate()==FAILURE) return FAILURE;

	int i;//mycode



    //CODE GOES HERE
	
	firstscreen->Draw(); //Drag the splashscreen into the scene.
	
	MyInputs::GetInstance()->SampleKeyboard();//my code
	

	//Instante the Obstacles //my code
	if(!draw_screen && NYAN -> alive)
	{
			new_time = time(NULL);
			k++;
	
		if (rand() % 30 == 0 && difftime(new_time, prev_time) > 0.5)
		{
			prev_time = new_time;

			for (i = 0; i < 4; i++)
				if (obstacol[i]->terminate)
				{
					obstacol[i] = new obstacle();
					obstacol[i] -> init(rand() % 4, rand() % 2);
					break;
				}
		}


	 
		//Drag the background into the scene.
		back->update();
		back->Draw();
		//Drag the cat into the scene.
		NYAN->update();
		NYAN->Draw();
		
		//Collision detection, adapted from baloons project.
				for (i = 0; i < 4; i++)
	if (!obstacol[i]->terminate)
	{
		obstacol[i]->update();
		obstacol[i]->Draw();

		if ((NYAN->dest.left >= obstacol[i] -> dest.left) &&
				(NYAN->dest.left <= obstacol[i] -> dest.right) &&
				(NYAN->dest.top >= obstacol[i] -> dest.top ) &&
				(NYAN->dest.top <= obstacol[i] -> dest.bottom))
			{
				NYAN -> alive = false;
			}

		if ((NYAN->dest.left >= obstacol[i] -> dest.left) &&
				(NYAN->dest.left <= obstacol[i] -> dest.right) &&
				(NYAN->dest.bottom - 30 >= obstacol[i] -> dest.top ) &&
				(NYAN->dest.bottom + 30 <= obstacol[i] -> dest.bottom))
			{
				NYAN -> alive = false;
			}
	}
	}
	
	//After the player dies, the obstacle loop is restarted, the score is set back to 0.  //my code
	if(!NYAN -> alive)
	{
			for (i = 0; i < 4; i++)
				obstacol[i] -> Terminate();

		NYAN -> init();
		firstscreen->init();
		draw_screen = true;
		k = 0;
	}
	

	//Play the game when P is pressed, after the first screen appears.  //my code
	if (MyInputs::GetInstance()->KeyPressed(DIK_P))  
	{
		firstscreen -> Terminate(); 
		draw_screen = false; 
	}	

	//Quit the game when key Q is pressed.  //my code
	if(MyInputs::GetInstance()->KeyPressed(DIK_Q))
	{
		PostMessage(gHwnd,WM_CLOSE,0,0);		
	}
		
	



	// Scoring system  //my code
	if(!draw_screen && NYAN -> alive)  
	{
		int kappa = k;
		int power = 0;
		while(kappa != 0)
		{
			kappa = kappa / 10;
			power++;
		}
		x = 1000 - (27 * power);
		MyDrawEngine::GetInstance()->WriteInt(k, x, 0);
	}




    //Flip and clear the back buffer
	pTheDrawEngine->Flip();
	pTheDrawEngine->ClearBackBuffer();

	return SUCCESS;


}

// ***********************************************************

void GameShutdown()
// called after the game loop is finished
{	
	firstscreen->Terminate();
	delete firstscreen;
	NYAN->Terminate();
	delete NYAN;
	back->Terminate();
	delete back;
	// (engines must be terminated last)
	pTheDrawEngine->Terminate();
	pTheSoundEngine->Terminate();
	pTheInputs->Terminate();   
		
}



