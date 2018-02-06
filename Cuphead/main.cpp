#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iomanip>
#include "LTexture.h"
#include "GameObject.h"
#include "Hero.h"
#include "Platform.h"
#include "Boss.h"
#include "Bullet.h"
#include "level.h"
#include "Minion.h"
#include"Splashscreen.h"
#include"Gamescreen.h"
#include"button.h"
#include <SDL_mixer.h>
#include"Character.h"
#include "Vector2.h"
#include"Splashscreen.h"
#include"Gamescreen.h"
#include"mainmenu.h"
#include"levelScreen.h"
#include"Pausemenu.h"
#include <fstream>
//Pre defined screen width and height
const int SCREEN_WIDTH = 980;
const int SCREEN_HEIGHT = 640;

//extern bool projectilejump;
//extern bool jump;
//extern bool jumped;

bool init();

bool loadMedia();

void close();
void LoadGame (Level*lvnum, Hero* player, Vector2 * vectors)
{


    string characters="";
    ifstream readfile;
    readfile.open("save.txt");
    getline(readfile, characters);
    //lvnum->SetLevel(atoi(characters.c_str()));
    //getline(readfile, characters);
    player->Setx(atof(characters.c_str()));
    getline(readfile, characters);
    player->Sety(atof(characters.c_str()));
    getline(readfile, characters);
    player->SetLives(atoi(characters.c_str()));


    readfile.close();

}

void SaveGame (Level * lvnum, Hero * player, Vector2 * vectors )
{
    ofstream readfile;   //ofstream is used to write to the file
    readfile.open("save.txt");
    //readfile<<lvnum->GetLevel();
    readfile<<player->Getx()<<endl;
    readfile<<player->Gety()<<endl;
    readfile<<player->GetLives();
    for(int i=0;i<vectors->o.size();i++)
    {
        if (vectors->o[i]->GetType()==1)
        {
            readfile<<vectors->o[i]->Getx()<<endl;
            readfile<<vectors->o[i]->Gety()<<endl;
            readfile<<vectors->o[i]->GetLives()<<endl;

        }

    }

}

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture gSpriteSheetTexture;
LTexture gBGTexture;
LTexture gSplashTexture;
LTexture gFontsTexture;
LTexture gMENUBG;
LTexture gPauseMenuTexture;


bool init();
bool loadMedia();
void close();
Mix_Music *gMusic = NULL;
//The sound effects that will be used
Mix_Chunk *gMedium = NULL;
Mix_Chunk *gLaser = NULL;
Mix_Chunk *gDamage=NULL;
Mix_Chunk *gDemon=NULL;

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
            Mix_PlayMusic( gMusic, -1 );

			bool quit = false;                      //Main loop flag

			SDL_Event e;                           //Event handler

            int gun=0; //the type of gun hero is firing
            int &bullet=gun;
			long int frame = 0; //handling the hero frame
			long int bframe=0;  //handling enemy frMW
			//Current animation frame
            int direction=0;
             /**MENU controls**/
            string button_selected;
            bool mainmenuControl=true;
            bool pausemenuControl=false;
            bool Action=true;
            int scrollingOffset = 0;
            int x,y;
           	/* initialize random seed: */
            srand (time(NULL));

            /* generate secret number between 1 and 10: */
            int random = 0;

             Vector2 obj;
            Vector2 obj1;
            Splashscreen S;
            S.Render(gRenderer,&gSplashTexture);
            Hero* chr = new Hero(&gSpriteSheetTexture, float(400), float(600), SCREEN_WIDTH, SCREEN_HEIGHT);
            mainmenu GameMenuSc(&gMENUBG,&gFontsTexture);
            Gamescreen GamePlaySc(&gFontsTexture,&gBGTexture);
            levelScreen level_1("LEVELONE",8,&gFontsTexture);
            Pausemenu GamePauseSc(&gFontsTexture);


           // obj1.o.push_back(chr);
            cout<<"hello2"<<endl;

			Level* l1=new Level(&obj1,1,&gSpriteSheetTexture,SCREEN_WIDTH,SCREEN_HEIGHT);

			//LoadGame(l1, chr, &obj1);
			while( !quit )                          //While application is running
			{   random=rand()%16;
                SDL_GetMouseState(&x,&y);
                while(!Action)
                {
                    cout<<"NO ACTION"<<endl;
                    if(pausemenuControl==true)
                    {
                        if(GamePauseSc.pause_button_select(x,y)!="")
                        {
                             Action=true;
                           cout<<"ACTION"<<endl;
                          break;
                        }
                        break;

                    }
                }

				while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
				{

                    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
                      if(currentKeyStates[ SDL_SCANCODE_1])
                    {

                        gun=0;
                    }

                     if(currentKeyStates[ SDL_SCANCODE_2])
                    {
                        gun=1;
                    }

					//User requests quit
					if( e.type == SDL_QUIT )
					{
					    cout<<"quit"<<endl;
						quit = true;
					}
					 if (e.type==SDL_MOUSEBUTTONDOWN)
                    {

                        /**ALL MENU EVENTS CONTROLLED HERE**/
                        if(e.button.button==SDL_BUTTON_LEFT)
                        {

                            if ((mainmenuControl==true)&&(pausemenuControl==false)&&(GameMenuSc.menu_button_select(x,y)!=""))
                            {
                                button_selected=GameMenuSc.menu_button_select(x,y);
                                cout<<button_selected<<endl;
                            }

                            else if((pausemenuControl==true)&&(mainmenuControl==false)&&(GamePauseSc.pause_button_select(x,y)!=""))
                            {
                                button_selected=GamePauseSc.pause_button_select(x,y);
                                cout<<button_selected<<endl;
                            }

                            else if ((pausemenuControl==false)&&(mainmenuControl==false)&&(GamePlaySc.game_button_select(x,y)!=""))
                            {
                                button_selected=GamePlaySc.game_button_select(x,y);
                                cout<<button_selected<<endl;

                            }
                        }
                    }



					if(e.type == SDL_KEYDOWN) //checks to see if the event is a keyboard key being pressed down
                        {
                            switch (e.key.keysym.sym)  //makes a switch case as to what happens when different keys are called and mode is updated
                            {

							     case SDLK_0:
                                   //  If the music is paused
                                    if( Mix_PausedMusic() == 1 )
                                    {
                                        //Resume the music
                                        Mix_ResumeMusic();

                                    }
                                  //  If the music is playing
                                    else
                                    {
                                        //Pause the music
                                        Mix_PauseMusic();

                                    }
                                    break;


                            case SDLK_LEFT:
                                {

                                    frame=frame%3;
                                    chr->Move(LEFT);
                                    frame++;
                                    direction=1;
                                     break;
                                }
                            case SDLK_RIGHT:
                                {
                                    frame=frame%3;
                                    chr->Move(RIGHT);
                                    frame++;
                                    direction=0;



                                    break;
                                }
                            case SDLK_UP:
                                {

                                    frame=8;
                                    direction=2;
                                    break;
                                }
                                case SDLK_b:
                                {
                                    if (direction==1)
                                    {
                                      chr->Jump();
                                      frame=12;
                                    }
                                     else
                                    {
                                        direction=0;
                                        frame=12;


                                    }
                                    chr->Jump();

                                    break;
                                }
                                case SDLK_DOWN:
                                {
                                    frame=12;

                                    chr->Loop();

                                    break;
                                }
                            case SDLK_SPACE:
                                {
                                    if(bullet==0)
                                    {
                                        Bullet* bullet=new Bullet(&gSpriteSheetTexture, chr->Getx(), chr->Gety(),direction);
                                        obj.o.push_back(bullet);
                                        bullet->SetFrame(0);
                                        Mix_PlayChannel( -1, gMedium, 0 );
                                    }

                                    if(bullet==1)
                                    {
                                        Bullet* bullet=new Bullet(&gSpriteSheetTexture, chr->Getx(), chr->Gety(),direction);
                                        obj.o.push_back(bullet);
                                        bullet->SetFrame(1);
                                        Mix_PlayChannel( -1, gLaser, 0 );

                                    }

                                }

                            }
                        }
                        if(e.type == SDL_KEYUP) //checks to see if the event is a keyboard key being pressed down
                        {
                            switch (e.key.keysym.sym)  //makes a switch case as to what happens when different keys are called and mode is updated
                            {
                            case SDLK_UP:
                                {
                                    direction=0;
                                    frame=0;
                                    break;
                                }
                                case SDLK_LEFT:
                                {
                                    frame=0;
                                    break;
                                }
                                case SDLK_RIGHT:
                                {
                                    frame=0;
                                    break;
                                }
                                case SDLK_DOWN:
                                {
                                    frame=0;

                                   break;

                                }
                                case SDLK_b:
                                {
                                    frame=0;
                                }

                            }

                        }

                    if(currentKeyStates[SDL_SCANCODE_RIGHT]&& currentKeyStates[ SDL_SCANCODE_SPACE] )
                    {
                        frame=(frame+3)%7;
                        frame++;
                        if(bullet==0)
                                    {
                                        Bullet* bullet=new Bullet(&gSpriteSheetTexture, chr->Getx(), chr->Gety(),direction);
                                       obj.o.push_back(bullet);
                                       bullet->SetFrame(0);
                                        Mix_PlayChannel( -1, gMedium, 0 );
                                    }

                                    if(bullet==1)
                                    {
                                        Bullet* bullet=new Bullet(&gSpriteSheetTexture, chr->Getx(), chr->Gety(),direction);
                                        obj.o.push_back(bullet);
                                        bullet->SetFrame(1);
                                        Mix_PlayChannel( -1, gLaser, 0 );

                                    }

                    }

                    if(currentKeyStates[SDL_SCANCODE_LEFT]&& currentKeyStates[ SDL_SCANCODE_SPACE] )
                    {
                        frame=(frame+3)%7;
                        frame++;
                        if(bullet==0)
                                    {
                                        Bullet* bullet=new Bullet(&gSpriteSheetTexture, chr->Getx(), chr->Gety(),direction);
                                       obj.o.push_back(bullet);
                                       bullet->SetFrame(0);
                                        Mix_PlayChannel( -1, gMedium, 0 );
                                    }

                                    if(bullet==1)
                                    {
                                        Bullet* bullet=new Bullet(&gSpriteSheetTexture, chr->Getx(), chr->Gety(),direction);
                                        obj.o.push_back(bullet);
                                        bullet->SetFrame(1);
                                        Mix_PlayChannel( -1, gLaser, 0 );

                                    }

                    }

				}
				if ((mainmenuControl)&&(Action==true))
                   {
                        GameMenuSc.Render(gRenderer);
                        if (button_selected=="play")
                        {
                            level_1.Render(gRenderer);
                            //the reason why level is here is coz it
                            //it will appear only at play and not again when user presses RESUME
                            mainmenuControl = false;
                            pausemenuControl = false;

                        }
                        else if (button_selected=="exit")//exit the application
                        {
                            quit=true;
                        }
                        else if(button_selected=="load")//load operation performed
                        {
                            LoadGame(l1, chr, &obj1);
                            cout<<"LOAD sel"<<endl;//load will take to game but from the same instance
                            mainmenuControl=false;pausemenuControl=false;
                        }
                   }
                if((pausemenuControl==false)&&(mainmenuControl==false))
                {

                        --scrollingOffset;
                        if( scrollingOffset < -gBGTexture.GetWidth() )
                        {
                            scrollingOffset = 0;
                        }
                        GamePlaySc.Render_horizontal(gRenderer,scrollingOffset);


                        --scrollingOffset;
                        if( scrollingOffset < -gBGTexture.GetWidth() )
                        {
                            scrollingOffset = 0;
                        }

                        for(int i=0;i<obj1.o.size();i++)
                        {
                            if(obj1.o[i]->GetType()==1)
                                obj1.o[i]->Shooting(&obj);
                        }
                        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen
                        SDL_RenderClear( gRenderer );
                        gBGTexture.Render( scrollingOffset, 0,NULL,0.0,NULL,SDL_FLIP_NONE, gRenderer );
                        gBGTexture.Render( scrollingOffset + gBGTexture.GetWidth(), 0,NULL,0.0,NULL,SDL_FLIP_NONE,gRenderer );

                        bframe=bframe%3;
                        obj1.Move();
                        if(random==0)
                        {
                          for(int i=0;i<obj1.o.size();i++)
                            {
                                if (obj1.o[i]->GetType()==1)
                                {
                                    obj1.o[i]->SetFrame(bframe);
                                    bframe++;
                                }
                            }

                        }




                        chr->SetFrame(frame);


                        for(int i=0; i<obj1.o.size();i++)
                         if( obj1.Collision2(&(chr->cRectangle), &(obj1.o[i]->cRectangle) ) )
                        {
                            if(  obj1.o[i]->GetType()==2
                                 &&   chr->cRectangle.y+26>=obj1.o[i]->cRectangle.y

                                 &&   (chr->cRectangle.y - obj1.o[i]->cRectangle.y > 0)
                               )
                            {


                              chr->cRectangle.y=obj1.o[i]->cRectangle.y - chr->cRectangle.h - 5;
                              chr->Sety(chr->cRectangle.y+chr->cRectangle.w/2);


                              chr->jump=false;
                              chr->projectilejump=false;
                              chr->jumped = false;
                            }

                        }
                        chr->Render(gRenderer,direction);
                        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
                        obj1.Render(gRenderer,0);

//                        for(int i=0;i<obj1.o.size();i++)
//                        {
//                            SDL_RenderDrawRect( gRenderer, &(obj1.o[i]->cRectangle) );
//                        }
//                        for(int i=0;i<obj.o.size();i++)
//                        {
//                            SDL_RenderDrawRect( gRenderer, &(obj.o[i]->cRectangle) );
//                        }
//
//                        SDL_RenderDrawRect( gRenderer, &(chr->cRectangle) );
                        obj.Render(gRenderer,direction);
                        obj.Move();


                    //Monster & bullet collision
                     for(int i=0;i<obj.o.size();i++)
                    {
                        for(int j=0;j<obj1.o.size();j++)
                        {
                            if(obj.o[i]->GetType()!=obj1.o[j]->GetType())
                            {
                                if(obj.Collision2(&(obj.o[i]->cRectangle),&(obj1.o[j]->cRectangle)))
                                {   cout<<obj1.o[j]->GetType()<<endl;
                                    obj.o.erase(obj.o.begin()+i);

                                    /*killing the boss*/
                                    if(obj1.o[j]->GetType()==1)
                                    {   Mix_PlayChannel( -1, gDemon, 0 );
                                        cout<<"boss hit"<<endl;
                                        obj1.o[j]->SetLives((obj1.o[j]->GetLives())-1);
        //                                cout<<obj1.o[j]->GetLives()<<endl;


                                    }
                                    if(obj1.o[j]->GetLives()==0)
                                    {
                                        obj1.o.erase(obj1.o.begin()+j);
                                        break;
                                    }

                                    break;
                                }

                            }
                        }
                    }
                    //Player bullet Collision
                    for(int i=0;i<obj.o.size();i++)
                    {
                        if(obj.o[i]->GetType()!=chr->GetType())
                        {
                            if(obj.Collision2(&(obj.o[i]->cRectangle),&(chr->cRectangle)))
                            {
                                obj.o.erase(obj.o.begin()+i);
                                cout<<"player hit"<<endl;
                                chr->SetLives((chr->GetLives())-1);
                                Mix_PlayChannel( -1, gDamage, 0 );
        //                        cout<<chr->GetLives()<<endl;
                                if(chr->GetLives()==0)
                                {
                                    return 0;
                                }
                                break;
                            }
                        }
                    }
                }

            if(pausemenuControl==false &&Action)
                   {
                       if (button_selected=="pause")
                            {
                                GamePauseSc.Render(gRenderer,&gPauseMenuTexture);
                                Action=false;pausemenuControl=true;
                            }
                   }
            if(pausemenuControl&&Action)
                    {

                                if(button_selected=="exit_pause")//exit the application
                                {
                                    quit=true;
                                }
                                else if(button_selected=="resume")//will resume back to the game
                                {
                                    cout<<"RESUME sel"<<endl;
                                    Action=true;mainmenuControl=false;pausemenuControl=false;
                                }
                                else if(button_selected=="save")//will perform save operation
                                {
                                    SaveGame(l1, chr, &obj1);
                                    Action=true;mainmenuControl=true;pausemenuControl=false;//takes back to main menu
                                    cout<<"SAVE sel"<<endl;
                                }
                                else if(button_selected=="return")
                                {
                                    mainmenuControl=true;Action=true;pausemenuControl=false;
                                }



                   }
                   if (button_selected=="exit_pause")
                   {
                       quit=true;
                   }
            obj.Deallocate(SCREEN_HEIGHT,SCREEN_WIDTH);
            //Update screen
            SDL_RenderPresent( gRenderer );

			}

			delete chr;
			delete l1;
			chr=NULL;
			l1=NULL;




		}

	}



	//Free resources and close SDL
	close();

	return 0;
}


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if(!gBGTexture.LoadFromFile( "media/bg1.png",gRenderer)||( !gSpriteSheetTexture.LoadFromFile( "media/sprite2.png", gRenderer) )|| (!gSplashTexture.LoadFromFile("media/splash.png", gRenderer)))
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if(!gFontsTexture.LoadFromFile("media/fontSprite.png",gRenderer))
    {
        printf("Failed to load font sprites\n");
        success=false;
    }
    if(!gMENUBG.LoadFromFile("media/menuscreen.png",gRenderer))
    {
        printf("Failed to load mainmenu texture\n");
        success=false;
    }
    if(!gPauseMenuTexture.LoadFromFile("media/pausescreen.png",gRenderer))
    {
        printf("Failed to load pausemenu texture\n");
        success=false;
    }

	gMusic = Mix_LoadMUS( "media/random silly chip song.wav" );
	if( gMusic == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	//Load sound effects

	gLaser = Mix_LoadWAV( "media/laserfire01.wav" );
	if( gLaser == NULL )
	{
		printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
	gMedium = Mix_LoadWAV( "media/medium.wav" );
	if( gMedium == NULL )
	{
		printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
	gDamage = Mix_LoadWAV( "media/damage.wav" );
	if( gDamage == NULL )
	{
		printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}
	gDemon = Mix_LoadWAV( "media/demon.wav" );
	if( gDemon == NULL )
	{
		printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

//
	return success;
}

void close()
{
    //Free the sound effects
	Mix_FreeChunk( gMedium );
	Mix_FreeChunk( gLaser );
	Mix_FreeChunk(gDamage);
	Mix_FreeChunk(gDemon);
	gLaser = NULL;
	gMedium = NULL;
    gDamage=NULL;
    gDemon=NULL;
	//Free loaded images
	gSpriteSheetTexture.Free();
	gBGTexture.Free();
	gSplashTexture.Free();
	gFontsTexture.Free();
	gMENUBG.Free();
	gPauseMenuTexture.Free();



	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;


	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
