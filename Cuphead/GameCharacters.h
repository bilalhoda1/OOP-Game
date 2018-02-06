#pragma once
#include"SDL.h"
#include "LTexture.h"
#include "Point.h"
#include "GameObject.h"

class GameCharacters:public GameObject
{
    protected:
        float speedx,speedy,friction;


    public:
	    GameCharacters();
	    virtual void Move(int direction);
	    virtual void Move();
	    virtual void Render(SDL_Renderer* gRenderer, int dir);

};
