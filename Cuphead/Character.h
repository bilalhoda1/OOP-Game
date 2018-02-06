#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"
using namespace std;
class Character
{
private:
    Point position;
    int character_value;
    int width;
    int height;
    SDL_Rect spriteClips;
    LTexture* spriteSheetTexture;
public:
    Character();
    Character(LTexture* image, float x, float y,char);
    ~Character();
    void Render(SDL_Renderer* gRenderer, bool debug);
    void SetPosition(Point&);
    void SetPosition(int, int);
    int GetFrameWidth();
    int GetFrameHeight();
};

