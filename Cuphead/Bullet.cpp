#include "Bullet.h"


Bullet::Bullet()
{
//    typeId=0;
//    this->x=0;
//    this->y=0;
//    speedx = 0;
//    speedy = 0;
//    currentFrame=0;

}


Bullet::Bullet(LTexture* image, float x1, float y1,int dir)
{
    spriteSheetTexture=image;
    typeId=0;


    // Hero Bullet 1-Green Star
    spriteClips[ 0 ].x = 74;
    spriteClips[ 0 ].y = 379;
    spriteClips[ 0 ].w = 22;
    spriteClips[ 0 ].h = 28;

    // Hero Bullet 2-Blue Orb
    spriteClips[ 1 ].x = 17;
    spriteClips[ 1 ].y = 441;
    spriteClips[ 1 ].w = 22;
    spriteClips[ 1 ].h = 25;

    // Boss 1 Bullet-Orange Orb
    spriteClips[ 2 ].x = 150;
    spriteClips[ 2 ].y = 296;
    spriteClips[ 2 ].w = 30;
    spriteClips[ 2 ].h = 30;

    // Boss1 Bullet 2- Star Disc
    spriteClips[ 3 ].x = 258;
    spriteClips[ 3 ].y = 101;
    spriteClips[ 3 ].w = 20;
    spriteClips[ 3 ].h = 15;

    // Boss2 Bullet 1-Red Kamehameha DOWN
    spriteClips[ 4 ].x = 210;
    spriteClips[ 4 ].y = 430;
    spriteClips[ 4 ].w = 23;
    spriteClips[ 4 ].h = 32;

    // Boss2 Bullet 2-Red Orb
    spriteClips[ 5 ].x = 238;
    spriteClips[ 5 ].y = 305;
    spriteClips[ 5 ].w = 21;
    spriteClips[ 5 ].h = 21;

    // Boss3 Bullet 1-Laser
    spriteClips[ 6 ].x = 130;
    spriteClips[ 6 ].y = 415;
    spriteClips[ 6 ].w = 19;
    spriteClips[ 6 ].h = 47;

    // Boss3 Bullet 2-Orange Star
    spriteClips[ 6 ].x = 31;
    spriteClips[ 6 ].y = 380;
    spriteClips[ 6 ].w = 23;
    spriteClips[ 6 ].h = 19;
    this->x = x1;
    this->y = y1;
    currentFrame=0;
    direction=dir;
    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
    cRectangle.x=x-width/2;
    cRectangle.y=y-width/2;
    cRectangle.w=spriteClips[0].w;
    cRectangle.h=spriteClips[0].h-20;

if(dir==0)  //Right Direction
   {
     x=x1+22;
     y=y1+10;
     cRectangle.x=x-width/2;
     cRectangle.y=y-width/2;
   }
   if(dir==1) //Left Direction
   {
     x=x1-22;
     y=y1+10;
    cRectangle.x=x-width/2;
    cRectangle.y=y-width/2;
   }
   if(dir==2)  //Up direction
   {
     x=x1;
     y=y1-10;
     cRectangle.x=x-width/2;
     cRectangle.y=y-width/2;
   }
   if(dir==3)  //Down direction
   {
     x=x1;
     y=y1+10;
     cRectangle.x=x-width/2;
     cRectangle.y=y-width/2;
   }
   if(dir==4)  //Right Diagnol
   {
     x=x1+10;
     y=y1+10;
     cRectangle.x=x-width/2;
     cRectangle.y=y-width/2;
   }
    if(dir==5)  //Left Diagnol
   {
     x=x1-10;
     y=y1+10;
     cRectangle.x=x-width/2;
     cRectangle.y=y-width/2;
   }


}

Bullet::~Bullet()
{
    spriteSheetTexture=NULL;
    cout<<"Bullet Deallocated"<<endl;
}

void Bullet::Move()
{

    if(direction==0) // Right direction
    {
       speedx =15;  //bullet speed
       x+=speedx;// with - sign, bullet goes left
       cRectangle.x=x;
    }

    if(direction==1)  //Left Direction
    {
       speedx =15;  //bullet speed
       x-=speedx;
       cRectangle.x=x-spriteClips[0].w/2; // with - sign, bullet goes left
    }
    if(direction==2)   //Up Direction
    {
        speedy=15;
        y-=speedy;
        cRectangle.y=y-spriteClips[0].w/2;
    }
    if(direction==3)  //Down Direction
    {
        speedy=15;
        y+=speedy;
        cRectangle.y=y-spriteClips[0].w/2;
    }
    if(direction==4)  //Right Diagnol
    {
        speedy=15;
        y+=speedy;
        speedx =2 ;  //bullet speed
        x+=speedx;
        cRectangle.x=x-spriteClips[0].w/2;
        cRectangle.y=y-spriteClips[0].w/2;
    }
 if(direction==5)   //Left Diagnol
    {
        speedy=15;
        y+=speedy;
        speedx =2 ;  //bullet speed
        x-=speedx;
        cRectangle.x=x-spriteClips[0].w/2;
        cRectangle.y=y-spriteClips[0].w/2;
    }

}

float Bullet::Getx()
{
    return x;
}
float Bullet::Gety()
{
    return y;
}
void Bullet::SetType(int e)
{
    typeId=e;
}
int Bullet::GetType()
{
    return typeId;
}
void Bullet::SetFrame(int frame)
{
    currentFrame=frame;
}
void Bullet::Render(SDL_Renderer* gRenderer,int dir)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ currentFrame ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}


