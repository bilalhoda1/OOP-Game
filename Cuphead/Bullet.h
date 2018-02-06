#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>

class Bullet:public GameObject
{
    LTexture* spriteSheetTexture;
    int direction; //used for determining direction of bullet
    float width,height,speedx,speedy;
    enum ANIMATION_FRAMES {FLYING_FRAMES = 7};
    SDL_Rect spriteClips[ FLYING_FRAMES ];

public:

    Bullet();
    Bullet(LTexture* image, float x1, float y1, int dir);
    ~Bullet();
    void Move();
    void Render(SDL_Renderer* gRenderer,int dir);
    void SetFrame(int frame);
    float Getx();
    float Gety();
    void SetType(int);
    int GetType();
};
