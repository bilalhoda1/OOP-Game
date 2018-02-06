#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include<SDL.h>
#include<iostream>
#include"LTexture.h"
#include"button.h"

using namespace std;
class Gamescreen
{
    public:
        Gamescreen(LTexture*f,LTexture*bg);
        void Render_horizontal(SDL_Renderer*,int);
        void Render_vertical(SDL_Renderer*,LTexture*,int);
        ~Gamescreen();
        string game_button_select(int,int);



    protected:

    private:
        SDL_Rect pauserect={750,585,250,48};
        button*pause;
         LTexture*font;
         LTexture*background;

};

#endif // GAMESCREEN_H
