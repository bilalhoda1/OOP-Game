#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include<SDL.h>

#include"LTexture.h"
#include<iostream>
#include"button.h"
using namespace std;
class Pausemenu
{
    public:
        Pausemenu(LTexture*);
        void Render(SDL_Renderer*,LTexture*);
        ~Pausemenu();
        string pause_button_select(int,int);
    protected:

    private:
        LTexture*font;
        SDL_Rect resumerect={10,200,268,47};
        SDL_Rect exitPauserect={790,200,200,45};
        SDL_Rect returnrect={10,300,260,45};
        SDL_Rect saverect={790,300,168,50};
        button*resume;
        button*exit_pause;
        button*save;
        button*return_menu;

};

#endif // PAUSEMENU_H
