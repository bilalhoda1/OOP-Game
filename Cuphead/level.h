#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "GameObject.h"
#include "Hero.h"
#include "Platform.h"
#include "Boss.h"
#include "LTexture.h"
#include "Bullet.h"
#include "Minion.h"
#include "Vector2.h"

class Level
{
    public:
   Platform* block;
   Boss* ghost;
    Minion * Minions;
    Minion *Minions1;
    Minion * Minions2;
    Minion *Minions3;
    Minion * Minions4;
    Level();
    ~Level();
    int level_num;
    int GetLevel();
    void SetLevel(int);
    Level(Vector2 *vectors ,int, LTexture* image,int w,int h);

};

