#include "Platform.h"



Platform::Platform()
{
    typeId=2;
    this->x=0;
    this->y=0;
    width=0;
    height=0;

}

Platform::Platform(LTexture* image, float x, float y)
{
    spriteSheetTexture2 = image;
    typeId=2;
    currentFrame=0;

   //Frame 0 Blue Platform
    spriteClips[ 0 ].x =376;
    spriteClips[ 0 ].y =277;
    spriteClips[ 0 ].w =30;
    spriteClips[ 0 ].h =30;

    //Frame 1 Grey platform
    spriteClips[ 1 ].x =345;
    spriteClips[ 1 ].y =277;
    spriteClips[ 1 ].w =30;
    spriteClips[ 1 ].h =30;

    //frame 2
     spriteClips[ 2 ].x =310;
    spriteClips[ 2 ].y =199;
    spriteClips[ 2 ].w =30;
    spriteClips[ 2 ].h =24;

    //Frame3
    spriteClips[ 3 ].x =536;
    spriteClips[ 3 ].y =199;
    spriteClips[ 3 ].w =30;
    spriteClips[ 3 ].h =24;

    //Frame4
    spriteClips[ 4 ].x =443;
    spriteClips[ 4 ].y =278;
    spriteClips[ 4 ].w =30;
    spriteClips[ 4 ].h =30;

    this->x = x;
    this->y = y;
    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
    cRectangle.x=x-width/2;
    cRectangle.y=y-width/2;
    cRectangle.w=width;
    cRectangle.h=height;
}


Platform::~Platform()
{
    spriteSheetTexture2 = NULL;
}

void Platform::SetType(int e)
{
    typeId=e;
}

int Platform::GetType()
{
    return typeId;
}

void Platform::SetFrame(int frame)
{
    currentFrame=frame;
}
void Platform::Render(SDL_Renderer* gRenderer,int dir)
{
    spriteSheetTexture2->Render( x - width/2, y - height/2, &spriteClips[currentFrame], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

float Platform::Getx()
{
    return x;
}
float Platform::Gety()
{
    return y;
}
