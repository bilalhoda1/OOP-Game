
#include "Hero.h"



Hero::Hero()
{
    this->x=0;
    this->y=0;
    speedx = 0;
    speedy = 0;
    this->lives=0;
    projectilejump = false;
    jump = false;
    jumped = false;
    jumplimit = 0;


}

Hero::Hero(LTexture* image, float x, float y, int SWidth, int SHeight)
{

   spriteSheetTexture = image;
   typeId=0;

   //Frame 0-Standing
    spriteClips[ 0 ].x =0;
    spriteClips[ 0 ].y =0;
    spriteClips[ 0 ].w =25;
    spriteClips[ 0 ].h =26;

    //Frame 1-Start Moving
    spriteClips[ 1 ].x =0;
    spriteClips[ 1 ].y =34;
    spriteClips[ 1 ].w =25;
    spriteClips[ 1 ].h =26;

    //Frame 2-Transition to move
    spriteClips[ 2 ].x =28;
    spriteClips[ 2 ].y =34;
    spriteClips[ 2 ].w =24;
    spriteClips[ 2 ].h =24;

    //Frame 3-Last Moving
    spriteClips[ 3 ].x = 52;
    spriteClips[ 3 ].y = 35;
    spriteClips[ 3 ].w = 25;
    spriteClips[ 3 ].h = 24;

    //Frame 4-Standing with shooting straight
    spriteClips[ 4 ].x = 0;
    spriteClips[ 4 ].y = 60;
    spriteClips[ 4 ].w = 25;
    spriteClips[ 4 ].h = 26;

    //Frame 5- Moving while shooting straight
    spriteClips[ 5 ].x = 35;
    spriteClips[ 5 ].y = 60;
    spriteClips[ 5 ].w = 25;
    spriteClips[ 5 ].h = 26;


    //Frame 6-Transition While shooting straight
    spriteClips[ 6 ].x = 70;
    spriteClips[ 6 ].y = 60;
    spriteClips[ 6 ].w = 25;
    spriteClips[ 6 ].h = 26;

    //Frame 7-Last Moving while Shooting straight
    spriteClips[ 7 ].x = 100;
    spriteClips[ 7 ].y = 60;
    spriteClips[ 7 ].w = 25;
    spriteClips[ 7 ].h = 26;

    //Frame 8- Standing while Shooting upwards
    spriteClips[ 8 ].x = 100;
    spriteClips[ 8 ].y = 88;
    spriteClips[ 8 ].w = 25;
    spriteClips[ 8 ].h = 28;

    //Frame 9- Moving while Shooting straight
    spriteClips[ 9 ].x = 125;
    spriteClips[ 9 ].y = 88;
    spriteClips[ 9 ].w = 25;
    spriteClips[ 9 ].h = 28;

    //Frame 10-Transition Moving while Shooting straight
    spriteClips[ 10 ].x = 150;
    spriteClips[ 10 ].y = 88;
    spriteClips[ 10 ].w = 25;
    spriteClips[ 10 ].h = 28;

     //Frame 11-Transition Moving while Shooting straight
    spriteClips[ 11 ].x = 175;
    spriteClips[ 11 ].y = 88;
    spriteClips[ 11 ].w = 25;
    spriteClips[ 11 ].h = 28;

    //Frame12-Jumping
    spriteClips[ 12 ].x = 25;
    spriteClips[ 12 ].y = 142;
    spriteClips[ 12 ].w = 25;
    spriteClips[ 12 ].h = 24;

    //Frame13-Dead
    spriteClips[ 13 ].x = 109;
    spriteClips[ 13 ].y = 142;
    spriteClips[ 13 ].w = 25;
    spriteClips[ 13 ].h = 28;

    currentFrame=0;
    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
    cRectangle.x=x-width/2;
    cRectangle.y=y-width/2;
    cRectangle.w=spriteClips[ 0 ].w;
    cRectangle.h=spriteClips[ 0 ].h;
    friction = 0.8f;
    speedx = 0;
    speedy = 0;
    this->lives=3;
    ScreenHeight=SHeight;
    ScreenWidth=SWidth;
    projectilejump = false;
    jump = false;
    jumped = false;
    jumplimit = 500;

}
Hero::~Hero()
{
    spriteSheetTexture = NULL;
}


void Hero::Move(int direction)
{
    //inmotion=true;

    if(direction==LEFT && this->x>10)
    {
        speedx = -5;
        x+=speedx;
        cRectangle.x=x-12;

    }

    if(direction==RIGHT && this->x<ScreenWidth)
    {
        speedx = 5;
        x+=speedx;
        cRectangle.x=x-12;

    }

}

void Hero::Move()
{
     speedx = speedx * friction;
     speedy = speedy * friction;

     x = x + speedx;
     y = y + speedy;
}

void Hero::SetFrame(int frame)
{
    currentFrame=frame;
}

void Hero:: Loop()
{

    jump = true;
}

void Hero::Jump()
{
    projectilejump = true;
    jump=true;
    jumplimit = y-100;

}

void Hero::Render(SDL_Renderer* gRenderer, int dir)
{
 if(this->lives>0)
 {
    if(jump == true)
    {

		if ( y >=jumplimit&& jumped == false && y>200)
        {

			if (projectilejump == false )
			{
				y = y - 4;
				cRectangle.y=y-width/2;
			}
			else
			{
				y =y - 4;
				cRectangle.y=y;
				if (x<950 &&dir == 0)
				{

					x = x + 2;
					cRectangle.x=x;

				}


				if (x > 0 && dir==1)
				{
					x = x-2;
					cRectangle.x=x;
				}
				else if (dir == 1)
				{
					x = 0;
					cRectangle.x=x;

				}
			}


		}
		else
		{

			jumped = true;

		}



		if (y < 598 && jumped == true)
		{

			if (projectilejump == false)
			{
			    y = y + 4;
			    cRectangle.y=y;

			}
			else
			{
                y = y + 4;
                cRectangle.y=y;
				if (x<950 && dir == 0 && projectilejump == true)
				{
				    x = x + 2;
				    cRectangle.x=x;
				}
				if (x > 0 && dir == 1 && projectilejump == true)
				{
				    x = x - 2;
				    cRectangle.x=x;
				}

			}
		}

		else if (y >= 598 && jumped == true)
		{
            cRectangle.x=x-width/2;
            cRectangle.y=y-width/2;
			jumped = false;
			projectilejump = false;
			jump = false;

		}

		if (dir == 0)
		{

        spriteSheetTexture->Render(x, y, &spriteClips[ currentFrame ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

		}
		else
		{

        spriteSheetTexture->Render( x, y, &spriteClips[ currentFrame ], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
		}

	}

    else if(dir==0 || dir==2)
    {
        spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ currentFrame % HERO_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    else if (dir==1)
    {
      spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ currentFrame % HERO_FRAMES ], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
    }
 }


}

float Hero::Getx()
{
    return x;
}
float Hero::Gety()
{
    return y;
}

void Hero::Sety(int y1)
{
    y=y1;
}
void Hero::Setx(int x1)
{
    x=x1;
}

void Hero:: Update()
{
    y = y - 10;
    cRectangle.y=y;

}
void Hero::SetType(int e)
{
    typeId=e;
}
int Hero::GetType()
{
    return typeId;
}
void Hero::SetLives(int life)
{
    this->lives=life;
}
int Hero::GetLives()
{
    return this->lives;
}

