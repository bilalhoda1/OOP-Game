#ifndef BUTTON_H
#define BUTTON_H
#include<SDL.h>
#include<SDL_image.h>

#include"Ltexture.h"
#include"Word.h"
#include<iostream>
using namespace std;
class button
{
    public:
        button(SDL_Rect*,string S,LTexture*fonts,int myx, int myy,int wordsize);
        bool checkbounds(int,int);
        void Render(SDL_Renderer* gRenderer);
        ~button();


    protected:

    private:
        int x;
        int y;
        SDL_Rect* button_rect;
        Word* button_word;

};

#endif // BUTTON_H
