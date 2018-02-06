#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include<SDL.h>

#include"LTexture.h"
#include<iostream>
using namespace std;
class Splashscreen
{
    public:
        Splashscreen();
        void Render(SDL_Renderer*,LTexture*);
        ~Splashscreen();


    private:
};

#endif // SPLASHSCREEN_H
