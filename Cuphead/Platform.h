

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "GameObject.h"


using namespace std;



class Platform:public GameObject
{
    private:
        enum ANIMATION_FRAME {BLOCK = 5};
        SDL_Rect spriteClips[ BLOCK ];
        LTexture* spriteSheetTexture2;

    public:
        Platform(LTexture* image, float x, float y);
        Platform();
        ~Platform();
        void Render(SDL_Renderer* gRenderer,int dir);
        void SetType(int);
        void SetFrame(int frame);
        int GetType();
        float Getx();
        float Gety();

};

