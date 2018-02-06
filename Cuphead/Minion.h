#pragma once
#include "GameObject.h"
#include "Point.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "GameCharacters.h"

class Minion:public GameCharacters
{
    enum ANIMATION_FRAMES {MINION_FRAMES = 7};
        SDL_Rect spriteClips[ MINION_FRAMES ];
        LTexture* spriteSheetTexture;
        int ScreenWidth;
        int ScreenHeight;
public:


    Minion();
    ~Minion();
    bool onground;
    Minion(LTexture* image, float x, float y,int w,int h);
    //void shoot();
    float Getx();
    float Gety();
    void Move();
    void Render( SDL_Renderer* gRenderer, int dir);
    void SetFrame(int);
    void SetType(int);   //Sets the type of object
    int GetType();
    int GetLives();
    void SetLives(int);
};
