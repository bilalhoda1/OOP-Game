
#pragma once
#include "GameObject.h"
#include "Point.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "GameCharacters.h"
#include <cstdlib>
#include "Bullet.h"
#include "Vector2.h"


class Boss:public GameCharacters
{
private:

        enum ANIMATION_FRAMES {BOSS_FRAMES = 12};
        SDL_Rect spriteClips[ BOSS_FRAMES ];
        LTexture* spriteSheetTexture;

public:

    Boss();
    ~Boss();
    Boss(LTexture* image, float x, float y, int, int );

    void Move();
    void Render(SDL_Renderer* gRenderer, int dir);
    void SetFrame(int frame);
    float Getx();
    float Gety();
    void SetType(int);
    int GetType();
    int GetLives();
    void SetLives(int);
    void Shooting(Vector2*);
};
