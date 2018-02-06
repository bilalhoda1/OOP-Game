#include"Minion.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <windows.h>




Minion::Minion()
{

}

Minion::~Minion()
{
    spriteSheetTexture=NULL;
}

Minion::Minion(LTexture* image, float x, float y,int w,int h)
{
    spriteSheetTexture = image;
    //Minion 1 standing
//    spriteClips[ 0 ].x =620;
//    spriteClips[ 0 ].y =1;
//    spriteClips[ 0 ].w =19;
//    spriteClips[ 0 ].h =19;
//
////Minion 1 moving
//    spriteClips[ 1 ].x =643;
//    spriteClips[ 1 ].y =1;
//    spriteClips[ 1 ].w =19;
//    spriteClips[ 1 ].h =19;
//
////Minion 1 last moving
//    spriteClips[ 2 ].x =661;
//    spriteClips[ 2 ].y =1;
//    spriteClips[ 2 ].w =19;
//    spriteClips[ 2 ].h =19;
//
////Minion 1 dead
//spriteClips[ 3 ].x =620;
//    spriteClips[ 3 ].y =53;
//    spriteClips[ 3 ].w =21;
//    spriteClips[ 3 ].h =21;


// Minion 2 standing
    spriteClips[ 0 ].x =620;
    spriteClips[ 0 ].y =100;
    spriteClips[ 0 ].w =18;
    spriteClips[ 0 ].h =19;

//Minion 2 moving
    spriteClips[ 1 ].x =637;
    spriteClips[ 1 ].y =100;
    spriteClips[ 1 ].w =19;
    spriteClips[ 1 ].h =19;

//Minion Minion 2 dead
    spriteClips[ 2 ].x =620;
    spriteClips[ 2 ].y =165;
    spriteClips[ 2 ].w =21;
    spriteClips[ 2 ].h =16;
    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
    typeId=1;
    lives=5;
    speedx = 0;
    speedy = 0;
    cRectangle.x=x-width/2;
    cRectangle.y=y-width/2;
    cRectangle.w=width;
    cRectangle.h=height;
    //alive  = true;
    currentFrame=0;
    ScreenWidth=w;
    ScreenHeight=h;



}



void Minion::Move()
{
    //inmotion=true;
    //MinionFrame=MinionFrame%3;
    static int direction = 0;
    static int num_moves = 0;
    int x1=x-10;
    int x2=x+10;
    if(num_moves++%5==0)
        direction= (rand() % 8);


    if(direction==0 && this->x>10 && this->x>x1)//left
    {
        speedx = -5;
        x+=speedx;

//        currentFrame=currentFrame%2;
//        currentFrame++;
        cRectangle.x=x-width/2;
    }

    if(direction==1 && this->x<950 && this->x<x2 ) //right
    {
        speedx = 5;
        x+=speedx;
//        currentFrame=currentFrame%2;
//        currentFrame++;
        cRectangle.x=x-width/2;
    }
    currentFrame=0;



}
void Minion::SetFrame(int frame)
{
    currentFrame=frame;
}

void Minion::Render(SDL_Renderer* gRenderer, int dir)
{
    if(dir==0)
    {
        spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ currentFrame % MINION_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    else if (dir==1)
    {
      spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ currentFrame % MINION_FRAMES ], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );

    }
}
void Minion::SetType(int type)
{
    typeId=type;
}
int Minion::GetType()
{
    return typeId;
}
float Minion::Getx()
{
    return x;
}
float Minion::Gety()
{
    return y;
}
void Minion::SetLives(int l)
{
    lives=l;
}
int Minion::GetLives()
{
    return lives;
}
