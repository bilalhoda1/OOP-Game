#pragma once
#include "GameObject.h"
#include "Point.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "GameCharacters.h"

enum MOTION {RIGHT, LEFT, UP, DOWN};
class Hero:public GameCharacters
{
private:


        enum ANIMATION_FRAMES {HERO_FRAMES = 14};
        SDL_Rect spriteClips[ HERO_FRAMES ];
        LTexture* spriteSheetTexture;
public:
    float gravity = 0.5f;
    Hero();
    ~Hero();
    Hero(LTexture* image, float x, float y, int, int );
    float Getx();
    float Gety();
    void Setx(int);
    void Sety(int);
    void Move(int direction);
    void Move();
    void Update();
    void Render(SDL_Renderer* gRenderer, int dir);
    void Loop();
    void Jump();
    void SetType(int e);
    int GetType();
    void SetFrame(int);
    bool projectilejump ;
    bool jump;
    bool jumped ;
    int  jumplimit;
    int GetLives();
    void SetLives(int);


};
