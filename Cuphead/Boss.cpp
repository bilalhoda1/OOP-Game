
#include "Boss.h"
#include <cstdlib>



//bool jump=false;

Boss::Boss()
{
    typeId=1;
    this->x=0;
    this->y=0;
    this->lives=0;
    speedx = 0;
    speedy = 0;
    currentFrame=0;
    ScreenWidth=0;
    ScreenHeight=0;
    this->lives=0;



}

Boss::Boss(LTexture* image, float x, float y, int Swidth, int SHeight)
{

    spriteSheetTexture = image;
   typeId=1;

   //Boss1-Eye Open
    spriteClips[ 0 ].x =307;
    spriteClips[ 0 ].y =13;
    spriteClips[ 0 ].w =99;
    spriteClips[ 0 ].h =90;

    //Boss1-Eye Half Open
    spriteClips[ 1 ].x =406;
    spriteClips[ 1 ].y =13;
    spriteClips[ 1 ].w =95;
    spriteClips[ 1 ].h =90;

    //Boss1-dead
    spriteClips[ 2 ].x =502;
    spriteClips[ 2 ].y =13;
    spriteClips[ 2 ].w =100;
    spriteClips[ 2 ].h =90;

     //Boss2-Standing
    spriteClips[ 3 ].x =1037;
    spriteClips[ 3 ].y =13;
    spriteClips[ 3 ].w =139;
    spriteClips[ 3 ].h =85;

     //Boss2-Transition
    spriteClips[ 4 ].x =1180;
    spriteClips[ 4 ].y =13;
    spriteClips[ 4 ].w =135;
    spriteClips[ 4 ].h =85;

     //Boss2-Final Movement
    spriteClips[ 5 ].x =1338;
    spriteClips[ 5 ].y =13;
    spriteClips[ 5 ].w =116;
    spriteClips[ 5 ].h =85;

     //Boss2-Shooting
    spriteClips[ 6 ].x =1025;
    spriteClips[ 6 ].y =108;
    spriteClips[ 6 ].w =134;
    spriteClips[ 6 ].h =85;

    //Boss2-Dead
    spriteClips[ 7 ].x =1436;
    spriteClips[ 7 ].y =145;
    spriteClips[ 7 ].w =119;
    spriteClips[ 7 ].h =65;

    //Boss3-Standing
    spriteClips[ 8 ].x =598;
    spriteClips[ 8 ].y =340;
    spriteClips[ 8 ].w =135;
    spriteClips[ 8 ].h =104;

    //Boss3- Hands Moving
    spriteClips[ 9 ].x =451;
    spriteClips[ 9 ].y =339;
    spriteClips[ 9 ].w =134;
    spriteClips[ 9 ].h =128;

    //Boss3-Shooting
    spriteClips[ 10 ].x =305;
    spriteClips[ 10 ].y =128;
    spriteClips[ 10 ].w =136;
    spriteClips[ 10 ].h =135;

     //Boss3-Dead
    spriteClips[ 10 ].x =761;
    spriteClips[ 10 ].y =341;
    spriteClips[ 10 ].w =126;
    spriteClips[ 10 ].h =112;





    currentFrame=0;
    this->x = x;
    this->y = y;
    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h-10;
    this->lives=20;
    cRectangle.x=x-width/2;
    cRectangle.y=y-width/2;
    cRectangle.w=spriteClips[ 0 ].w;
    cRectangle.h=spriteClips[ 0 ].h;
    speedx = 0;
    speedy = 0;
    ScreenHeight=SHeight;
    ScreenWidth=Swidth;

}
Boss::~Boss()
{
    spriteSheetTexture = NULL;
}


void Boss::Move()
{
     static int direction=0;
    static int num_moves=0;
    if(num_moves++%20==0)
        direction= (rand() % 4);

    //left

    if(direction==0 && this->x>50)
    {
        speedx = -5;
        x+=speedx;
       cRectangle.x=x-55;
    }
    //right
    if(direction==1 && this->x<ScreenWidth)
    {
        speedx = 5;
        x+=speedx;
       cRectangle.x=x-55;
    }
    //up
    if(direction==2 && this->y>50)
    {
        speedy = -5;
        y+=speedy;
       cRectangle.y=y-50;
    }
   //down
    if(direction==3 && this->y<ScreenHeight)
    {
        speedy = 5;
        y+=speedy;
       cRectangle.y=y-50;
    }

}

void Boss::SetFrame(int frame)
{
    currentFrame=frame;
}

void Boss::Render(SDL_Renderer* gRenderer, int dir)
{
    if(dir==0 && this->lives>0)
    {
        spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ currentFrame % BOSS_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    else if (dir==1 && this->lives>0)
    {
      spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ currentFrame % BOSS_FRAMES ], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
    }
}

float Boss::Getx()
{
    return x;
}
float Boss::Gety()
{
    return y;
}
void Boss::SetType(int e)
{
   typeId=e;
}
int Boss::GetType()
{
    return typeId;
}
void Boss::SetLives(int life)
{
    this->lives=life;
}
int Boss::GetLives()
{
    return this->lives;
}
void Boss::Shooting(Vector2* vectors)
{   int random=0;
    random=rand()%10;
    int  d=0;
    if(random==0)
               {
                 d=rand()%6;
                 Bullet* ebullet=new Bullet(spriteSheetTexture, x, y,d);
                 ebullet->SetFrame(2);
                 ebullet->SetType(1);
                 vectors->o.push_back(ebullet);

               }
}
