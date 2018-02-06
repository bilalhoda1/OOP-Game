#ifndef VECTOR2_H
#define VECTOR2_H
#include "LTexture.h"
#include <SDL.h>
#include <vector>
#include <iostream>
#include "GameObject.h"
using namespace std;

class Vector2
{
    public:
        Vector2();
        ~Vector2();
        vector<GameObject*> o;
//        void Render(SDL_Renderer* gRenderer);
        void Render(SDL_Renderer* gRenderer,int dir);
        void Deallocate(int h,int w);
        void Move();
        bool Collision2(const SDL_Rect* a,const SDL_Rect *b);
    protected:

    private:
};

#endif // VECTOR2_H
