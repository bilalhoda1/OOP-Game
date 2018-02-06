#ifndef LEVELSCREEN_H_INCLUDED
#define LEVELSCREEN_H_INCLUDED

#include<SDL.h>
#include"Word.h"
#include<iostream>
using namespace std;
class levelScreen
{
    public:
        levelScreen(string levelname,int wordlength,LTexture*f);
        ~levelScreen();
        void Render(SDL_Renderer*);


    protected:

    private:
        LTexture*font;
        SDL_Rect screensize={0,0,980,650};
        string name_of_level;
        Word* displaylevel;

};

#endif // LEVELSCREEN_H_INCLUDED
